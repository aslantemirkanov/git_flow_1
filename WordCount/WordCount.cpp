#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
    FILE *file;
    file = fopen("test.txt", "r");
    fclose(file);
    char fileName[] = "test.txt";    char ln1[] = "--lines";
    char ln2[] = "-l";    char bt1[] = "--bytes";
    char bt2[] = "-c";    char wd1[] = "--words";
    char wd2[] = "-w";    int Flag[3];
    for (int i = 0; i < 3; i++) {
        Flag[i] = 0;
    }
    if (strcmp(argv[argc-1], fileName)!=0) {
        printf("you loser\n");
    } else {
        for (int i = 1; i < argc - 1; i++) {
            if ((!(strcmp(argv[i], ln1))) || (!(strcmp(argv[i], ln2)))) {
                if ((Flag[0] == 0)) {
                    Flag[0] = 1;
                    lnCount();
                }
            } else if (((!(strcmp(argv[i], bt1))) || (!(strcmp(argv[i], bt2))))) {
                if ((Flag[1] == 0)) {
                    Flag[1] = 1;
                    litCount();
                }
            } else if (((!(strcmp(argv[i], wd1))) || (!(strcmp(argv[i], wd2))))) {
                if ((Flag[2] == 0)) {
                    Flag[2] = 1;
                    WdCount();
                }
            } else {
                //printf("you loser\n");
            }
        }
    }
    return 0;
}