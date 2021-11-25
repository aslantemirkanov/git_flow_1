#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int conversion_date_to_sec(char *date) {
    long int second = 0;
    second += ((date[0] - 48) * 10 + (date[1] - 48) - 1) * 86400;
    second += ((date[12] - 48) * 10 + (date[13] - 48)) * 3600;
    second += ((date[15] - 48) * 10 + (date[16] - 48)) * 60;
    second += (date[18] - 48) * 10 + date[19] - 48;
    if (date[3] == 'F' && date[4] == 'e' && date[5] == 'b') {
        second += 2678400;
    } else if (date[3] == 'M' && date[4] == 'a' && date[5] == 'r') {
        second += 5097600;
    } else if (date[3] == 'A' && date[4] == 'p' && date[5] == 'r') {
        second += 7776000;
    } else if (date[3] == 'M' && date[4] == 'a' && date[5] == 'y') {
        second += 10368000;
    } else if (date[3] == 'J' && date[4] == 'u' && date[5] == 'n') {
        second += 13046400;
    } else if (date[3] == 'J' && date[4] == 'u' && date[5] == 'l') {
        second += 15638400;
    } else if (date[3] == 'A' && date[4] == 'u' && date[5] == 'g') {
        second += 18316800;
    } else if (date[3] == 'S' && date[4] == 'e' && date[5] == 'p') {
        second += 20995200;
    } else if (date[3] == 'O' && date[4] == 'c' && date[5] == 't') {
        second += 23587200;
    } else if (date[3] == 'N' && date[4] == 'o' && date[5] == 'v') {
        second += 26265600;
    } else if (date[3] == 'D' && date[4] == 'e' && date[5] == 'c') {
        second += 28857600;
    }
    return second;
}

int errors_count() {
    FILE *file_input;
    file_input = fopen("access_log_Jul95.txt", "r");
    FILE *file_output;
    file_output = fopen("errors.txt", "w");
    int str_count = 0;
    char str[500];
    char *str_pointer;
    int error_str_count = 0;
    while (1) {
        str_pointer = fgets(str, sizeof(str), file_input);
        str_count++;
        if (str_pointer == NULL) {
            if (feof(file_input) != 0) {
                fprintf(file_output, "reading has finished\n");
                break;
            }
        }
        int str_len = strlen(str);
        int i = str_len;
        while (str[i] != '"' && i >= 0) {
            i--;
        }
        if (str[i + 2] == '5') {
            error_str_count++;
            fprintf(file_output, "%d - %s", error_str_count, str);
        }
    }
    fprintf(file_output, "%d", error_str_count);
    fclose(file_input);
    fclose(file_output);
    return str_count;
}

int main(int argc, char *argv[]) {
    int str_count = errors_count();
    int time_window=atoi(argv[1]);
    printf("%d\n",time_window);
    max_time_window_request(time_window, str_count);
    return 0;
}