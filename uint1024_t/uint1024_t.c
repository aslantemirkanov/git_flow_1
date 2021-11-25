#include <stdio.h>
#include <string.h>

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