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
    if (stat("./hidden_folder", &st) == -1 || !S_ISDIR(st.st_mode)) {
        mkdir("./hidden_folder", 0333);
    }
    else if (st.st_mode != strtol("0333", 0, 8)) {
        chmod("./hidden_folder", strtol("0333", 0, 8));
    }

    // Получаем текущий путь (рабочую директорию)
    char *currentPath = getcwd(NULL, 1024);
    char old_path[100];
    char new_path[100];

    sprintf(old_path, "%s/%s", currentPath, filename);
    sprintf(new_path, "%s/hidden_folder/%s", currentPath, filename);
    if (rename (old_path, new_path) == -1) {
        printf("Unable to hide file %s\n", filename);
    }
    else {
        printf("File %s hidden successfully\n", filename);
    }



    return 0;
}
