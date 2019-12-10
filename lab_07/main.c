/*
Вариант 13.
В системе двусторонних дорог за проезд 13, 28
каждой дороги взимается некоторая пошлина.
Найти путь из города A в город B с
минимальной величиной S+P, где S - сумма
длин дорог пути, а P - сумма пошлин
проезжаемых дорог
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "colors.h"

#define OK 0

int main(void)
{
    int answer = -1;

    while (answer)
    {
        answer = scanf_answer();
    }

    printf("\n");
    return OK;
}