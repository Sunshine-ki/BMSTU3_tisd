<h1>Отчёт:</h1> 

**Задача:**

Смоделировать операцию умножения действительного числа на действительное число в форме +/- m.n E +/- K, где суммарная длина мантиссы (m+n) - до 30 значащих цифр, а величина порядка K - до 5 цифр. Результат выдать в форме +/-0.m1 E +/- K1, где m1 - до 30 значащих цифр, а K2 - до 5 цифр.

**Введение:**

Наименование программы: lab_01.c

Краткие характеристики: Программа служит для перемножения двух действительных чисел.

Ввод может осуществляться как в экспоненциальном формате, так и в вещественном. Пользователь сам решает, когда завершиться программа. Обработка ошибок присутствует.

Срок сдачи: 16.09.19  

**Основания для разработки:**

Заказчик: Александра Васильевна Силантьева

Исполнитель: Сукочева Элис

**Требования к программе:**

1. Задача решается на языке программирования "с". 

2. При некорректном вводе пользователя выводится сообщение об ошибке и просьба ввести заново.

3. При суммарной длине мантиссы больше 30 цифр происходит округление. (Допустимые потери данных)

4. При порядке длинной более 5 цифр выдаётся сообщение об ошибке. (Слишком большое число)


**Требования к функциональным характеристикам:**

1. Постановка задачи: 
Задача заключается в том, чтобы обработать, введённые пользователем числа, на ошибки и корректность записи.
Далее проверить, суммарную длину мантиссы и порядок и выдать результат умножения. Также позволить пользователю прочесть инструкцию. Следить за регистром (ответ не зависит от регистра).

2. Типы входных и выходных данных:

| Входные данные | Результат работы программы | 
|------------|----------| 
|Верный ввод двух чисел| Верный результат их перемножения | 
|Неверный ввод|Сообщение о некорректном вводе и просьба ввести заново|

*Неверный ввод подразумевает под собой:

1. Некорректные символы в числе (отличные от цифр, точки и символа "e")

2. На вопрос о желании узнать информацию корректный ответ только: yes/no (ответ не зависит от регистра).

3. Программа завершается как только пользователь введёт "exit". (ответ не зависит от регистра)

4. Программа выдаёт результат каждый раз, когда пользователь вводит два корректных числа, удовлетворяющих инструкции.

**Тестовые данные**

Функциональные тесты:

Тепличные:

| Входные данные | Выходные данные | Проверяется |  
|------------|----------|----------|
|2.0 6.0|0.12е2|Корректность умножения|
|-2.0 -6.0|0.12е2|Корректность умножения знаков - на -|
|2.0 -6.0|-0.12е2|Корректность умножения знаков + на -|
|-2.0 6.0|-0.12е2|Корректность умножения знаков - на +|
|1.2e2 1.2e2|0.144e5|Корректность умножения экспонециальных чисел| 
|1.2e2 120|0.144e5|Корректность умножения экспон. на веществен.|
|123.123 123.123|0.12159273129е5|Умножения больших чисел|
|exit|Завершение программы.|Корректность завершения программы|
|EXIT|Завершение программы.|Завершение программы с учётом регистра|

Граничные:

| Входные данные | Выходные данные | Проверяется |  
|------------|----------|----------|
|0.00000 0.00000|0.0е0|Нулевое значение в вещественном формате|
|0.0e1000 0.0e1000|0.0е|Нулевое значение в эксп. формате|
|0.1e99999 1.0e-99999|0.1e0|Порядок первого + порядок второго = 0|
|Отсутствие данных|Просьба ввести данные|

Запредельные:

| Входные данные | Выходные данные | 
|------------|----------| 
|1231ewe21|Некорректные символы!|
|123e.21|'e' идёт после '.'|
|+123.1221|Пишите без знака "+"|
|12.12e+122|Пишите без знака "+"|
|-1221.e-12-12|Слишком много знаков '-'|
|dfdwe|Некорректные символы!|
|1221331|'.' встретилась 0 раз!|
|123123e10|'.' встретилась 0 раз!|
|12312.e2121|Недопустимый формат!|
|1212.12e000021|После "e" не должно быть нулей!|
|0.1e123456|Слишком большой порядок|
|0.1e-123456|Слишком большой порядок|
|0.999999999999998000000000000001e123456|Слишком большой порядок|
|0.0.0.0|"." встретилась более 1 раза!|
|0.2e33e3|"E" встретилась более 1 раза!|


**СД**

Структурой данных является структура, содержащая:

1. Массив чисел (мантисса) (int)

2. Знак числа (int)

3. Порядок (е) (int)

5. Позицию точки. (int)

```

// Структура, содержащая характеристики числа
typedef struct 
{
	int sign_number; // Знак числа (0:+ 1:-) 
	int mantissa[LEN]; // Мантисса числа
	int power; // Позицию точки
	int exp; // Порядок числа  
} number_attributes;

```

**Описание алгоритмов:**

**1. float_to_number**

int float_to_number(char str_number[LEN], number_attributes *number)

Предназначение: 

Переводит строку чисел, записанных в вещественной форме в массив чисел

Входные данные:

1. Строка, содержащая число.

2. Структура, содержащая характеристики числа

Выходные данные:

длина числа (кол-во цифр)

Подпрограмма итерируется по строке, пока не встретит конец (символ '\0')
проверяет, является ли символ числом и если является, то записывает в массив чисел. Так же проверяет, встретилась ли точка ('.'), как только встретилась, в характеристики записывается индекс (number->power = i). Далее, как только встречается символ 'e' (Не зависит от регистра) подпрограмма считает порядок (всё что после 'e') и записывает в характеристики числа (number->exp )

**2. exp_to_number**

int exp_to_number(char str_number[LEN], number_attributes *number)

Предназначение: 

Переводит строку чисел, записанных в экспоненциальной форме в массив чисел

Входные данные:

1. Строка, содержащая число.

2. Структура, содержащая характеристики числа

Выходные данные:

длина числа (кол-во цифр)

Подпрограмма итерируется по строке, пока не встретит конец (символ '\0')
проверяет, является ли символ числом и если является, то записывает в массив чисел. Как только встретилась '.' в характеристики записывается индекс (number->power = i).

**3. multiplication**

void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2, int arr_result[LEN])

Предназначение: 

Функция перемножения чисел.

Входные данные:

1. Первое и второе число в виде массива чисел.

2. Их длина 

3. Массив, в который будет записан результат.

Выходные данные:

Отсутствуют.

Запускается цикл по первому массиву с конца (Так же создаётся итерирующая переменная для конечного массива (результирующего), значение будет складываться из длинны первого числа + длина второго числа)
В цикле запускается второй цикл, который идёт по второму массиву (также с конца)
Каждые элементы массивов перемножаются и, если их длина больше 9 (делается якобы запоминание), то мы к следующему элементу (результирующего массива) прибавляем то, что больше 9, а текущему элементу (результирующего массива) всё что меньше 9.
По завершению цикла  итерирующая переменная для результирующего массива передвигается на следующую позицию (куда будет записываться результат следующего цикла.). Итерируемые переменные уменьшаются на единицу.
 

<h1>Программа</h1> 

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

#define OK 0
#define LEN 70
#define NO 0
#define YES 1
#define TRUE 1
#define FALSE 0
#define ERROR_INPUT -1
#define EXIT 2
#define MAX_LEN_POW 99999
#define MAX_LEN_MANTISSA 30

#define STRUCT_INIT {0, {0}, 0, 0}

// Структура, содержащая характеристики числа
typedef struct 
{
	int sign_number; // Знак числа (0:+ 1:-) 
	int mantissa[LEN]; // Мантисса числа
	int power; // Позицию точки
	int exp; // Порядок числа  
} number_attributes;

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
			// if (number[i + 1] == '0')
			// {	
			// 	printf("После \"e\" не должно быть нулей!");
			// 	return ERROR_INPUT;
			// }
			// if (number[i - 1] == '.')
			// {	
			// 	printf("Недопустимый формат!(12.3 либо 12.3e3)");
			// 	return ERROR_INPUT;
			// }
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

// Вывод результата
void print_result(number_attributes number, int len)
{
	int i = 0;

	if (number.mantissa[i] == 0)
	{
		number.exp--;
		i++;
	} 
	// printf("EXP DO: %d\n", number.exp);
	// printf("!!!!!!%d %d!!!!!\n", number.power, len);
	while (number.mantissa[len - 1] == 0)
	{
		// number.exp++;
		len--;
	}

	// printf("EXP POSLE: %d\n", number.exp);

	if (number.sign_number)
		printf("-");

	// while ((number.mantissa[i] == 0) && (number.power + 1 < len))
		// i++;
	printf("0.");

	while (i < len)
	{	
		// if (number.power == len - i)
			// printf(".");
		if (number.mantissa[i] == '.')
		{
			i++;
		}
		printf("%d", number.mantissa[i]);
		i++;
	}
	printf("e%d", number.exp);
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

// Переводит строку чисел, записанных в 
// Экспоненциальной форме в мссив чисел
int exp_to_number(char str_number[LEN], number_attributes *number)
{
	int len_num = 0;
	int power_exp = 0;
	int temp = 1;
	int sign = FALSE;
	char exp_num[MAX_LEN_POW] = { '0' };
	int k = 0;

	number->sign_number = sign_of_number(str_number[0]);
	// while (str[i] == '0' && str[i + 1] != '.')
		// i++;
	// if (str_number[i] == '0' && str_number[i + 1] == '.')
	// 	i++;

	for (int i = 0; str_number[i]; i++)
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
			// number->power -= i - 1;
			i++;
			// if (str_number[i] == '-')
			// {
			// 	i++;
			// 	sign = TRUE;
			// }
			while (str_number[i])
			{
				// power_exp += char_to_int(str_number[i]) * temp;
				// temp *= 10;
				exp_num[k] = str_number[i];
				i++;
				k++;
			}
			break;
			// reverse(&power_exp);
		}
	}
	power_exp = atoi(exp_num);
	// if (sign)
	// 	power_exp *= -1;
	number->exp = atoi(exp_num) + number->power;
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
	// if ((str_number[0] == '0') || (sign_of_number(str_number[0]) && str_number[1] == '0'))
	// {
	// 	i++;
	// }

	for (; str_number[i]; i++)
	{
		if (str_number[i] >= '0' && str_number[i] <= '9')
		{
			number->mantissa[len_num] = char_to_int(str_number[i]);
			len_num++;
		}
		if (str_number[i] == '.')
		{
			// number->power = strlen(str_number) - 1 - i;
			number->power = i;
			number->exp = i;
		}
	}

	// while (number->mantissa[len_num] == 0)
	// {
	// 	len_num--;
	// }
	// if (number->power == 0)
		
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
		if (abs(result_number.exp) > MAX_LEN_POW)
		{
			printf("Аварийная ситуация!\
				\nРезультат имеет запредельный порядок числа");
			printf(" %d\n", result_number.exp);
			printf("%d %d\n", first_number.exp, second_number.exp);
			continue;
		}

		// print_struct(result_number, len1 + len2);
		// printf("EXP:%d\n", first_number.exp);

		puts("\nУмножение чисел:");
		print_result(first_number, len1);
		printf(" * ");
		print_result(second_number, len2);
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
```

