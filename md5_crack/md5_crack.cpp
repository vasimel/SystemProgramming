#include <iostream>
#include <string>
#include <openssl/md5.h>
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <random>


// Глобальная переменная для управления состоянием
volatile sig_atomic_t stopExecution = 0;

// Обработчик сигнала
void signalHandler(int signum) {
    stopExecution = 1;
}

// Функция для вычисления MD5-хэша
std::string calculateMD5(const std::string& input) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char*)input.c_str(), input.length(), (unsigned char*)&digest);

    char mdString[33];
    for (int i = 0; i < 16; i++)
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

    return std::string(mdString);
}



// Функция для перебора паролей
void crackMD5(const std::string& targetHash, int processID, int totalProcesses) {
    std::random_device rd;  // Инициализация генератора случайных чисел
    std::mt19937 gen(rd()); // Генератор случайных чисел
    std::uniform_int_distribution<> dis(0, 9); // Распределение для цифр от 0 до 9
// пусть известно, что пароль вначале содержит слово  admin, после которого
// идет 1 - 10 любых цифр
    for (int i = processID; !stopExecution; i += totalProcesses) {
        std::string testString = "admin";
        int numDigits = i % 10 + 1; // Произвольное количество цифр от 1 до 10

        // Добавление случайных цифр к строке "admin"
        for (int j = 0; j < numDigits; ++j) {
            testString += std::to_string(dis(gen));
        }

        std::string hash = calculateMD5(testString);
        if (hash == targetHash) {
            std::cout << "Найдено совпадение: " << testString << std::endl;
            kill(getppid(), SIGUSR1); // Отправка сигнала родительскому процессу
            break;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <md5-hash>\n";
        return 1;
    }

    std::string targetHash = argv[1];
    int totalProcesses = sysconf(_SC_NPROCESSORS_ONLN); // Получение количества процессоров

    std::vector<pid_t> children;

    signal(SIGUSR1, signalHandler);
    signal(SIGALRM, signalHandler);

    alarm(30);


    for (int i = 0; i < totalProcesses; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            // Дочерний процесс
            crackMD5(targetHash, i, totalProcesses);
            kill(getppid(), SIGUSR1); // Отправка сигнала родительскому процессу
        } else if (pid > 0) {
            // Родительский процесс
            children.push_back(pid);
        } else {
            std::cerr << "Ошибка создания процесса\n";
            return 1;
        }
    }
    while (!stopExecution) {
        pause(); // Ожидание сигнала
    }

    // Отправка сигнала SIGTERM оставшимся дочерним процессам
    for (pid_t child : children) {
        kill(child, SIGTERM);
    }

    for (pid_t child : children) {
        waitpid(child, nullptr, 0); // Ожидание завершения дочерних процессов
    }

    return 0;
}
