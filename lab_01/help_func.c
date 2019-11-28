#include "help_func.h"
#include <stdio.h>
#include <string.h>

void print_arr(int arr[LEN], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
}

// Переворачивает число
void reverse(int *num)
{
	int temp = *num;
	*num = 0;

	while(temp)
	{
		*num = *num * 10 + temp % 10;
		temp /= 10;
	}
}

// Узнаёт длину числа (int)
int len_int_number(int num)
{
	int len = 0;
	while (num)
	{
		len++;
		num /= 10;
	}
	return len;
}

// Вывод структуры
void print_struct(number_attributes num, int len)
{
	printf("\nsign_number: %d\npower: %d\nexp: %d\n", num.sign_number, num.power, num.exp);
	for (int i = 0; i < len; i++)
		printf("%d", num.mantissa[i]); 
}

// Преоборазование числа, из типа char в тип int
int char_to_int(char symbol)
{
	return symbol - '0';
}

// Переводит строку в нижний регистр
void lower(char *str)
{
	while (*str)
	{
		if ((*str >= 'A') && (*str <= 'Z'))
			*str += 'a' - 'A';
		str++;
	}
}

// Выдаёт первое вхождение элемента symbol в строку str
// (0 - элемент в строке отсутсвтует) 
int my_strchr(char *str, char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == symbol)
			return i;
	}
	return FALSE;
}

// Обнуляет все поля структуры
void reset_to_zero(number_attributes *number)
{
	number->sign_number = 0;
	number->power = 0;
	number->exp = 0;
	for (int i = 0; i < LEN; i++)
		number->mantissa[i] = 0;
}

// Считает кол-во вхождений символа symbol в строку str
int count_symbol(char *str, char symbol)
{
	int count = 0;
	while (*str)
	{
		if (*str == symbol)
			count++;
		str++;
	}
	return count;
}

// Функция для проверки записи формы числа
// На входе строковый массив, содержаший число
// На выходe 1 - экспоненциальная запись числа
// 0 - вещественное число
int format_numer(char number[LEN])
{
	while (*number)
	{
		if (*number == 'e')
			return TRUE;
		number++;
	}
	return FALSE;

}

// Меняет местами два числа
void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

// Определяет, является symbol + или - (0 / 1)
int sign_of_number(char symbol)
{
	return symbol == '-' ? 1 : 0;
}

// Вывод границ ввода
void convenient_input()
{
	puts("\n0        10        20       \33[31m30\e[0m\
	  \n|--------|---------|---------\33[31m|\e[0m");
}

// Запрос у пользователя желания изучить информацию.
// Информация
void information()
{
	printf("Желаете изучить инструкцию? \33[32m(Yes/No)\e[0m\n");
	char answer[16];
	scanf("%s", answer);
	lower(answer); // Переводим строку к нижнему регистру 
	while (strcmp(answer, "yes") && strcmp(answer, "no"))
	{
		printf("Ваш ответ \"%s\" неверный.\
			\nНапишите \"Yes\" или \"No\"!\n", answer);
		scanf("%s", answer);
		lower(answer);  // Переводим строку к нижнему регистру 
	}
	if (strcmp(answer, "no"))
		printf("\t \33[32mИнструкция:\33[31m\
		\nУмножение вещественного числа на вещественное!\e[0m\
		\nВвод осуществляется без пробелов!\
		\nЗнак \"+\" не нужен.\
		\nМантисса не более 30 значащих цифр\
		\nПорядок не более 5 значащих цифр\
		\nПримеры корректного ввода: \
		\n12.345; 0.345; 2.34e-75; 1234.232e56;\n");
}
