#include <iostream>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sys/wait.h>
#include <sstream>
#include <cstdio>
// Функция для обработки команды от клиента


void handleClient(int clientSocket) {
    // Буфер для чтения команды от клиента
    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        std::cerr << "Ошибка при получении данных" << std::endl;
        close(clientSocket);
        return;
    }

    // Преобразование полученных данных в строку
    std::string command(buffer, bytesRead);
    if (!command.empty() && command.back() == '\r') {
        command.pop_back();
    }

    // Открытие канала с командой с использованием popen()
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Ошибка при выполнении команды" << std::endl;
        close(clientSocket);
        return;
    }

    // Чтение и сборка вывода команды
    char readBuffer[1024];
    std::stringstream commandOutput;
    while (fgets(readBuffer, sizeof(readBuffer), pipe) != nullptr) {
        commandOutput << readBuffer;
    }

    // Закрытие канала и получение статуса завершения команды
    int status = pclose(pipe);
    if (status == -1) {
        std::cerr << "Ошибка при закрытии канала" << std::endl;
    }

    // Формирование и отправка ответа клиенту
    std::string response = "Код завершения: " + std::to_string(WEXITSTATUS(status)) + "\n" + commandOutput.str();
    send(clientSocket, response.c_str(), response.size(), 0);

    // Закрытие сокета клиента
    close(clientSocket);
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int port = std::atoi(argv[1]);
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Не удалось создать сокет" << std::endl;
        return 1;
    }

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        std::cerr << "Ошибка привязки сокета" << std::endl;
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == -1) {
        std::cerr << "Ошибка при переходе в режим прослушивания" << std::endl;
        return 1;
    }

    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket == -1) {
            std::cerr << "Ошибка при подключении клиента" << std::endl;
            continue;
        }

        // Создание отдельного потока для обработки запроса клиента
        std::thread clientThread(handleClient, clientSocket);
        clientThread.detach();
    }

    close(serverSocket);
    return 0;
}
