#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    struct stat s;
    DIR *dir;
    struct dirent *ent;
    dir = opendir("./");

    int reg_files = 0;
    int dirs = 0;
    int symbolic = 0;
    int sockets = 0;
    int chardev = 0;
    int blockdev = 0;
    int fifo = 0;
    int unknown = 0;

    if (dir == NULL) {
        printf("Error: Unable to open directory\n");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            reg_files += 1;
        }
        else if (ent->d_type == DT_DIR) {
            dirs += 1;
        }
        else if (ent->d_type == DT_LNK) {
            symbolic += 1;
        }
        else if (ent->d_type == DT_SOCK) {
            sockets += 1;
        }
        else if (ent->d_type == DT_CHR) {
            chardev += 1;
        }
        else if (ent->d_type == DT_FIFO) {
            fifo += 1;
        }
        else if (ent->d_type == DT_BLK) {
            blockdev += 1;
        }
        else {
            unknown += 1;
        }
    }

    closedir(dir);
    printf("Количество обычных файлов: %d\n", reg_files);
    printf("Количество директорий: %d\n", dirs);
    printf("Количество символьных ссылок: %d\n", symbolic);
    printf("Количество сокетов: %d\n", sockets);
    printf("Количество символьных специальных файлов: %d\n", chardev);
    printf("Количество блочных специальных файлов: %d\n", blockdev);
    printf("Количество FIFO-файлов: %d\n", fifo);
    printf("Количество файлов c неизвестным типом: %d\n", unknown);
    return 0;
}
