#include <stdio.h>
#include <string.h>

struct uint1024_t mult_op(struct uint1024_t x, struct uint1024_t y) {
    struct uint1024_t ans;
    int len_x, len_y;
    int tmp_ans[128];
    for (int i = 0; i < 128; i++) tmp_ans[i] = 0;
    int i = 127;
    while (x.digit[i] == 0) i--;
    len_x = i + 1;
    i = 127;
    while (y.digit[i] == 0) i--;
    len_y = i + 1;
    int len_ans = len_x + len_y + 1;
    for (int ix = 0; ix < len_x; ix++) {
        for (int iy = 0; iy < len_y; iy++) {
            tmp_ans[ix + iy] += x.digit[ix] * y.digit[iy];
        }
    }
    for (int i = 0; i < len_ans; i++) {
        tmp_ans[i + 1] += tmp_ans[i] / 256;
        tmp_ans[i] = tmp_ans[i] % 256;
    }
    for (int i = 0; i < 128; i++) {
        ans.digit[i] = tmp_ans[i];
    }
    return ans;
}

struct uint1024_t from_uint(unsigned int x) {
    struct uint1024_t rez;
    for (int i = 0; i < 128; i++) rez.digit[i] = 0;
    int i = 0;
    while (x > 0) {
        rez.digit[i++] = x % 256;
        x = x / 256;
    }
    return rez;
}

int main() {
    struct uint1024_t A, B;
    scanf_value(&A);
    printf_value(A);
    printf("\n");
    scanf_value(&B);
    printf_value(B);
    char operation[20];
    char output[] = "Input operation: A+B A-B B-A A*B generation_from_uint\n";
    char output_gen[] = "Input operation: A+B GEN+A GEN+B A-B B-A GEN-A A-GEN GEN-B B-GEN A*B A*GEN B*GEN\n";
    int flag = 0;
    printf("\n%s", output);
    struct uint1024_t uint_number;
    while (scanf("%s", operation)) {
        if (!(strcmp(operation, "A+B"))) {
            struct uint1024_t C = add_op(A, B);
            printf_value(C);
        }
        else if (!(strcmp(operation, "GEN+A"))) {
            struct uint1024_t C = add_op(uint_number, A);
            printf_value(C);
        }
        else if (!(strcmp(operation, "GEN+B"))) {
            struct uint1024_t C = add_op(uint_number, B);
            printf_value(C);
        }
        else if (!(strcmp(operation, "A-B"))) {
            struct uint1024_t C = subtr_op(A, B);
            printf_value(C);
        }
        else if (!(strcmp(operation, "B-A"))) {
            struct uint1024_t C = subtr_op(B, A);
            printf_value(C);
        }
        else if (!(strcmp(operation, "GEN-A"))) {
            struct uint1024_t C = subtr_op(uint_number, A);
            printf_value(C);
        }
        else if (!(strcmp(operation, "A-GEN"))) {
            struct uint1024_t C = subtr_op(A, uint_number);
            printf_value(C);
        }
        else if (!(strcmp(operation, "GEN-B"))) {
            struct uint1024_t C = subtr_op(uint_number, B);
            printf_value(C);
        }
        else if (!(strcmp(operation, "B-GEN"))) {
            struct uint1024_t C = subtr_op(B, uint_number);
            printf_value(C);
        }
        else if (!(strcmp(operation, "A*B"))) {
            struct uint1024_t C = mult_op(A, B);
            printf_value(C);
        }
        else if (!(strcmp(operation, "A*GEN"))) {
            struct uint1024_t C = mult_op(A, uint_number);
            printf_value(C);
        }
        else if (!(strcmp(operation, "B*GEN"))) {
            struct uint1024_t C = mult_op(B, uint_number);
            printf_value(C);
        }
        else if (!(strcmp(operation, "generation_from_uint"))) {
            flag = 1;
            printf("Input uint number:");
            unsigned int a;
            scanf("%u", &a);
            uint_number = from_uint(a);
            printf_value(uint_number);
        }
        if (!flag)printf("\n%s", output);
        else printf("\n%s", output_gen);
    }
    return 0;
}