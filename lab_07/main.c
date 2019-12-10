/*
Вариант 13.
В системе двусторонних дорог за проезд 
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

#include "instructions.h"
#include "struct.h"
#include "colors.h"

#define MAX_LEN_STATION 128

#define OK 0

int main(void)
{
    char in_station[MAX_LEN_STATION];
    char out_station[MAX_LEN_STATION];

    green();
    printf("Откуда: ");
    white();
    scanf("%s", in_station);

    green();
    printf("Куда: ");
    white();
    scanf("%s", out_station);

    green();
    printf("Самый быстрый и бюджетный путь:\n");

    // system("xdg-open graph/graph.png");

    printf("\n");
    return OK;
}

// while (answer)
// {
//     instruction();
//     answer = scanf_answer();

//     switch (answer)
//     {
//     case 0:
//         /* code */
//         break;
//     case 1:
//         /* Найти путь*/
//         break;
//     case 2:
//         /* Вывести граф */
//         break;
//     case 3:
//         /* Вывести граф */
//         break;
//     case 4:
//         system("xdg-open graph.png");
//         /* Вывести граф */
//         break;

//     default:
//         red();
//         printf("\t\t\t\t\t\t\t\t\tНет данного действия!\n");
//         white();
//         break;
//     }
// }
