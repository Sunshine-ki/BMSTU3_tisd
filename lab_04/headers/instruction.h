#ifndef INSTRUCTION_H

#define INSTRUCTION_H

#include <stdio.h>

#include "colors.h"

void instruction()
{
    yellow();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t1. Добавить слово.\n\
    \t\t\t\t\t\t\t2. Удалить слово.\n\
    \t\t\t\t\t\t\t3. Вывод текущего состояния стека.\n\
    \t\t\t\t\t\t\t4. Вывести массив свободных областей.\n\
    \t\t\t\t\t\t\t5. Распечатать слова в обратном порядке.\n\
    \t\t\t\t\t\t\t6. Очистить список.\n\
    \t\t\t\t\t\t\t7. Очистить массив.\n\
    \t\t\t\t\t\t\t8. Сравнить время.\n\
    \t\t\t\t\t\t\t0. Выход.\n");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие:  "); // упорядоченную по количеству страниц
    white();
}

#endif

/*

void instruction()
{
    yellow();
    printf("\n\t\t\t\t\t\t\t\t\t\tМеню:\n\
    \t\t\t\t\t\t\t1. Добавить слово.\n\
    \t\t\t\t\t\t\t2. Удалить слово.\n\
    \t\t\t\t\t\t\t3. Вывод текущего состояния стека.\n\
    \t\t\t\t\t\t\t4. Вывести массив свободных областей.\n\
    \t\t\t\t\t\t\t5. Сравнить время.\n\
    \t\t\t\t\t\t\t6. Распечатать слова в обратном порядке.\n\
    \t\t\t\t\t\t\t7. Добавить словa из файла (в список)\n\
    \t\t\t\t\t\t\t8. Очистить список.\n\
    \t\t\t\t\t\t\t9. Очистить массив.\n\
    \t\t\t\t\t\t\t10. Добавить словa из файла (в массив)\n\
    \t\t\t\t\t\t\t0. Выход.\n");
    green();
    printf("\t\t\t\t\t\t\t\t\tВыберите действие:  "); // упорядоченную по количеству страниц
    white();
}

*/