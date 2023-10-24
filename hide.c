#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
    // Проверяем, что передано достаточно аргументов
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Получаем имя файла из аргументов командной строки
    char *filename = argv[1];

    // Создаем скрытый каталог
    struct stat st = {0};
    if (stat("./hidden_folder", &st) == -1) {
        mkdir("./hidden_folder", 0333);
    }

    // Получаем текущий путь (рабочую директорию)
    char *currentPath = getcwd(NULL, 1024);

    // Создаем команду для переноса файла в скрытый каталог
    char command[100];
    sprintf(command, "mv %s/%s %s/hidden_folder/", currentPath, filename, currentPath);

    // Переносим файл в скрытый каталог
    system(command);

    printf("File %s hidden successfully\n", filename);

    return 0;
}
