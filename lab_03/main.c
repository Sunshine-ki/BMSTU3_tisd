#include <stdio.h>

// #include "headers/define.h"
// #include "headers/matrix_multiplication.h"
#include "headers/cdio.h"

int main(void)
{
    setbuf(stdout, NULL);

    matrix_t struct_matrix;
    construct(&struct_matrix);
    input_matrix(&struct_matrix);

    print_matrix(struct_matrix);
    printf("\nЯ тут!\n");
    return 0;
}