#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int str_count = errors_count();
    int time_window=atoi(argv[1]);
    printf("%d\n",time_window);
    max_time_window_request(time_window, str_count);
    return 0;
}