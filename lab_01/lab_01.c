#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include "help_func.h"

// Проверка на корректность ввода числа
int correctness_number(char number[LEN])
{	
	lower(number);  // Переводим строку к нижнему регистру 
	if (!strcmp(number, "exit"))
	{
		printf ("\33[31m" );
		puts("Завершение программы.");
		printf ("\e[0m" );
		return EXIT;
	}
	else if (count_symbol(number, '.') > 1)
	{
		puts("\".\" встретилась более 1 раза!");
		return ERROR_INPUT;
	}
	else if (!count_symbol(number, '.'))
	{
		puts("Число должно быть записано в вещественном формате! (12.3 либо 12.3e3)");
		return ERROR_INPUT;
	}
	else if (count_symbol(number, 'e') > 1)
	{
		puts("\"E\" встретилась более 1 раза!");
		return ERROR_INPUT;
	}
	else if (count_symbol(number, '-') > 2)
	{
		puts("Слишком много знаков \'-\'");
		return ERROR_INPUT;
	}
	else if (count_symbol(number, '+'))
	{
		puts("Пишите без знака \'+\'");
		return ERROR_INPUT;
	}
	else if (my_strchr(number, 'e') && (my_strchr(number, 'e') < my_strchr(number, '.')))
	{
		puts("Некорректный ввод!\n\'e\' идёт после \'.\'");
		return ERROR_INPUT;
	}

	for (int i = 0; number[i]; i++)
	{
		if ((number[i] < '0' || number[i] > '9') && number[i] != 'e' && number[i] != '.' && number[i] != '-')
		{	
			printf("некорректные символы!");
			return ERROR_INPUT;
		}
	}
	for (int i = 0; number[i]; i++)
	{
		if (number[i] == 'e')
		{
			i += number[i + 1] == '-' ? 7 : 6;
			if (strlen(number) > i)
			{
				puts("Слишком большой порядок");
				return ERROR_INPUT;
			}
			break;
		}
	}


	return OK;
}

// Функция перемножения чисел.
// Аргументы: 
// Первое и второе число в виде массива чисел.
// Их длина и массив, в который будет записан результат.
void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2, int arr_result[LEN])
{
	int multi;

	for (int i = len1 - 1, k = len1 + len2 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--, k--)
		{
			multi = arr1[i] * arr2[j];
			arr_result[k] += arr1[i] * arr2[j];
			if (arr_result[k] > 9)
			{
				arr_result[k - 1] += arr_result[k] / 10;
				arr_result[k] = arr_result[k] % 10;
			}
		}
		k = k + len2 - 1;
	}
}

// Вывод результата
void print_result(number_attributes number, int len)
{
	// print_struct(number, len);
	// print_arr(number.mantissa, len);
	// printf("EXP %d ", number.exp);
	if (len <= 0 )
	{
		puts("0.e1");
		return;
	}
	else 
	{	
		int count = 0;
		for (int t = 0; t < len; t++)
		{
			if (number.mantissa[t] == 0)
				count++;
		}
		if (count == len)
		{
			puts("0.e1");
			return;
		}
	}

	int i = 0;
	while (number.mantissa[i] == 0)
	{
		number.exp--;
		i++;
	}

	while (number.mantissa[len - 1] == 0)
	{
		len--;
	}

	if (abs(number.exp + number.power) > MAX_LEN_POW)
	{
		printf("Аварийная ситуация!\
			\nРезультат имеет запредельный порядок числа");
		return;
	}

	// Вывод
	// printf("%d %d ", number.exp, number.power);
	if (number.sign_number)
		printf("-");
	printf("0.");
	for (; i < len; i++)
	{
		printf("%d", number.mantissa[i]);
	}
	printf("E%d\n", number.exp + number.power);
}

// Переводит строку чисел, записанных в 
// Экспоненциальной форме в мaссив чисел
int exp_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int power_exp = 0;
	int temp = 1;
	int sign = FALSE;
	char exp_num[MAX_LEN_POW] = { '0' };
	int k = 0;
	int i = 0;

	number->sign_number = sign_of_number(str_number[0]);

	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
		}
		if (str_number[i] == '.')
		{
			number->power = i;
		}
		if (str_number[i] == 'e')
		{
			i++;
			while (str_number[i])
			{
				exp_num[k] = str_number[i];
				i++;
				k++;
			}
			break;
		}
	}
	power_exp = atoi(exp_num);
	number->exp = power_exp;
	// printf("POWER_EXP%d\n", power_exp);

	// БЫЛО ДО
	// number->exp = atoi(exp_num) + number->power;

	// number->power *= -1;
	// printf("EXP%d\n", number->exp);
	// printf("POWER%d\n", number->power);
	// printf("ATOI%d\n", atoi(exp_num));

	return len_num;
}

// Переводит строку чисел, записанных 
// В вещественной форме в массив чисел
int float_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int i = 0;

	number->sign_number = sign_of_number(str_number[0]);

	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
		}
		if (str_number[i] == '.')
		{
			number->power = 0;
			number->exp = i;
		}
	}
	while (number->mantissa[len_num - 1] == 0)
		len_num--;
		
	return len_num;
}

int main(void)
{
	setbuf(stdout, NULL);

	information();
	puts("Для выхода напишите \"\33[31mexit\e[0m\"");

	char str_number[LEN];
	int correct = 0;
	int len1, len2;
	// Создаем 3 структуры для хранения информации о числах 
	// И инициализируем все поля нулями.
	number_attributes first_number = STRUCT_INIT;
	number_attributes second_number = STRUCT_INIT;
	number_attributes result_number = STRUCT_INIT;

	// Цикл продолжается, пока что пользователь 
	// Не введёт "exit"
	while (correct != EXIT)
	{
		// Обнуляем все поля структур.
		reset_to_zero(&first_number);
		reset_to_zero(&second_number);
		reset_to_zero(&result_number);

		convenient_input();
		puts("\nВведите первое число: ");
		scanf("%s", str_number);
		correct = correctness_number(str_number);
		while (correct < 0)
		{
			puts("\nВведите корректное число:");
			scanf("%s", str_number);
			correct = correctness_number(str_number);
		}

		if (correct == EXIT)
			return OK;	

		if (format_numer(str_number))
		{
			len1 = exp_to_number(str_number, &first_number);
			// printf("power_exp:%d \n", first_number.exp);
			// printf("%d\n", first_number.power);
			// for (int i = 0; i < len1; i++)
			// 	printf("%d", first_number.mantissa[i]);  
		}
		else
		{
			len1 = float_to_number(str_number, &first_number);
		}
		if (len1 > MAX_LEN_MANTISSA)
		{
			puts("Слишком большая мантисса");
			continue;
		}
		// 2 NUMBER
		puts("Введите второе число: ");
		// convenient_input();
		scanf("%s", str_number);
		correct = correctness_number(str_number);
		while (correct < 0)
		{
			puts("\nВведите корректное число:");
			scanf("%s", str_number);
			correct = correctness_number(str_number);
		}
		if (correct == EXIT)
			return OK;	

		if (format_numer(str_number))
		{
			len2 = exp_to_number(str_number, &second_number);
			// printf("Ожидайте...");
		}
		else
		{
			len2 = float_to_number(str_number, &second_number);
		}
		if (len2 > MAX_LEN_MANTISSA)
		{
			puts("Слишком большая мантисса");
			continue;
		}
		// print_struct(first_number);print_struct(second_number);
		// printf("len1 %d len2 %d\n", len1, len2);
		if (len1 + len2 > MAX_LEN_MANTISSA)
		{
			printf("Аварийная ситуация!\
				\nРезультат имеет запредельную мантиссу");
			continue;
		}
		// Перемножение
		multiplication(first_number.mantissa, second_number.mantissa, len1, \
			len2, result_number.mantissa);
		// Запись информации в соответсвующие поля (результат)
		result_number.sign_number = first_number.sign_number ^ second_number.sign_number;
		result_number.power = first_number.power + second_number.power;
		result_number.exp = first_number.exp + second_number.exp;
		// if (abs(result_number.exp) > MAX_LEN_POW)
		// {
		// 	printf("Аварийная ситуация!\
		// 		\nРезультат имеет запредельный порядок числа");
		// 	printf(" %d\n", result_number.exp);
		// 	printf("%d %d\n", first_number.exp, second_number.exp);
		// 	continue;
		// }

		// print_struct(result_number, len1 + len2);
		// printf("EXP:%d\n", first_number.exp);

		puts("\nУмножение чисел");

		// Меняем цвет текста
		printf ("\33[31m" );
		printf("\nРЕЗУЛЬТАТ:\n");
		printf ("\33[34m" );
		print_result(result_number, len1 + len2);
		// Возвращаем цвет обратно.
		printf ("\n\e[0m" );
	}

	return OK;
}


// Вывод результата для float
// void print_result(number_attributes number, int len)
// {

 	// print_struct(number, len);
	// print_arr(number.mantissa, len);
	// printf("EXP %d ", number.exp);
	// int i = 0;
	// while (number.mantissa[i] == 0)
	// {
	// 	number.exp--;
	// 	i++;
	// }

	// while (number.mantissa[len - 1] == 0)
	// {
	// 	len--;
	// }

	// // Вывод
	// puts("");
	// if (number.sign_number)
	// 	printf("-");
	// printf("0.");
	// for (; i < len; i++)
	// {
	// 	printf("%d", number.mantissa[i]);
	// }
	// printf("E%d\n", number.exp);
// }