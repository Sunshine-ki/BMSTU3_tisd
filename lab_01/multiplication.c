#include <stdio.h>

#define LEN 70


void print_array(int arr[LEN], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);
	puts("");
}

void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2, int arr_result[LEN])
{
	int multi;

	print_array(arr2, len2);
	print_array(arr1, len1);
	puts("");

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



int main(void)
{
	int arr1[] = {9,9,9,9,9,9,9,9,9};
	int arr2[] = {9,9,9,9,9,9,9,9,9};
	int arr_result[LEN] = { 0 };
	int len1 = 9, len2 = 9; 

	multiplication(arr1, arr2, len1, len2, arr_result); // от меньшего к большему

	printf("Результат: \n");
	print_array(arr_result, len1 + len2);
	puts("");
	return 0;
}

// typedef struct 
// {
// 	int sign_number; // Знак числа (0:+ 1:-) 
// 	int mantissa[LEN]; // Мантисса числа
// 	int power; // Порядок числа
// } number_attributes;


// void exp_to_number(char str_number[LEN], number_attributes *number)
// {
	// int len_str = strlen(str_number);
	// int power = char_to_int(str_number[len_str - 1]);
	// int point_position = 0;
	// int k = len_str - 1;
	// int len_num = 0;

	// power *= str_number[len_str - 2] == '-' ? -1 : 1;
	// // Избавляемся от exp
	// while(k > 0)
	// {
	// 	if (str_number[k] == 'e')
	// 	{
	// 		str_number[k] = 0;
	// 		break;
	// 	}
	// 	str_number[k] = 0;
	// 	k--;
	// }

	// // Узнаём длину числа
	// for (int i = 0; str_number[i] != '.'; i++)
	// {
	// 	len_num += (str_number[j] >= '0' && str_number[j] <= '9') ? 1 : 0
	// }
	// len_num += power;

	// printf("DO: %s power: %d\n", str_number, power);
	// for (int j = 0, i = 0; str_number[j]; j++)
	// {
	// 	if (str_number[j] >= '0' && str_number[j] <= '9')
	// 	{	
	// 		number->mantissa[i] = char_to_int(str_number[j]);
	// 		i++;
	// 	}
	// }

	// if (power > 0)
	// {
	// 	point_position =  my_strchr(str_number, '.') + power;
	// }

	// for (int i = 0; i < len_num; i++)
	// {
	// 	printf("%d ", number->mantissa[i]);
	// }
	// puts("");
	// if (power > 0)
	// {
	// 	for (int j = my_strchr(str_number, '.'); power; power--,j++)
	// 	{

	// 		swap(&str_number[j], &str_number[j + 1]);

	// 	}
	// }
	// else if (power < 0)
	// {
	// 	int point_position = my_strchr(str_number, '.');
	// 	power *= -1;
	// 	if (point_position < power)
	// 	{
	// 		// nuli
	// 		printf("Заполнить нулями и  двинуть!\n");
	// 	}
	// 	else
	// 	{
	// 		for (int k = point_position; power; power--, k--)
	// 		{
	// 			swap(&str_number[k], &str_number[k - 1]);
	// 		}
	// 	}
	// }

// }

//_________________________

// void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2)
// {
// 	int temp;
// 	int temp2 = 0;
// 	int arr_res[LEN] = { 0 };
// 	int num_row, num_sum = 0; // number row and number sum row
// 	int number = 0;
// 	for (int i = 0; i < len2; i++)
// 		printf("%d", arr2[i]);
// 	puts("");
// 	for (int i = 0; i < len1; i++)
// 		printf("%d", arr1[i]);
// 	puts("\n|temp2   |temp     |num_row   |number|   \
// arr1[i]|   arr2[j]|  arr_res[k]|");

// 	for (int i = len1 - 1, k = len1 + len2; i >= 0; i--, k + len2 - 1)
// 	{
// 		temp = 0;
// 		for (int j = len2 - 1; j >= 0; j--, k--)
// 		{
// 			num_row = arr1[i] * arr2[j] + temp;
// 			// num_sum = arr_res[k] + num_row % 10;
// 			temp = num_row / 10;
// 			number = num_row % 10;
			
// 			// if (number + arr_res[k] + temp2 > 9)
// 			// {
// 			// 	arr_res[k] = (number + arr_res[k] + temp2) % 10;
// 			// 	temp2 = (number + arr_res[k] + temp2) / 10;
// 			// }
// 			// else
// 			// {
// 			// 	arr_res[k] = number + arr_res[k] + temp2;
// 			// }

// 			printf("\n%9d|%9d|%9d|%9d|%9d|%9d|%13d|", \
// 				temp2, temp, num_row, number, arr1[i],\
// 				 arr2[j], arr_res[k]);
// 		}
// 		puts("\nend\n");
// 		k--;
// 		arr_res[k] += temp;
// 	}
// 	for (int i = 0; i < len1 + len2; i++)
// 		printf("%d ", arr_res[i]);
// }


			// if (num_sum + arr_res[k] <= 9 && temp2 == 0)
			// {
			// 	arr_res[k] = num_sum;
			// }
			// else if (num_sum + arr_res[k] > 9 && temp2 == 0) 
			// {
			// 	arr_res[k] = (arr_res[k] + num_sum + temp2) / 10;
			// 	temp2 = (arr_res[k] + num_sum + temp2) % 10;
			// }
			// else if (num_sum + arr_res[k] > 9 && temp2 != 0 \
			// 	&& num_sum + arr_res[k] + temp2 <= 9)
			// {
			// 	arr_res[k] += num_sum + temp2;
			// }
			// else if (num_sum + arr_res[k] > 9 && temp2 != 0 \
			// 	&& num_sum + arr_res[k] + temp2 > 9)
			// {
			// 	arr_res[k] = (arr_res[k] + num_sum + temp2) % 10;
			// 	temp2 = (arr_res[k] + num_sum + temp2) / 10;
			// }


// void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2)
// {
// 	int temp;
// 	int temp2 = 0;
// 	int arr_res[LEN] = { 0 }; // ОБНУЛИТЬ!!!!!!!!!!!
// 	int num_row, num_sum; // number row and number sum row
// 	for (int i = len1, k = len1 * len2; i > 2; i--, k--)
// 	{
// 		temp = 0;
// 		for (int j = len2; j > 2; j--)
// 		{
// 			num_row = arr1[i] * arr2[j] + temp;
// 			num_sum = arr_res[k] + num_row % 10;
// 			temp = num_row / 10;
// 			if (num_sum <= 9)
// 			{
// 				arr_res[k] = num_sum;
// 			}
// 			else
// 			{
// 				arr_res[k] = (num_sum + temp2) / 10;
// 				temp2 = num_sum / 10;
// 			}
// 		}
// 		k--;
// 		arr_res[k] = temp;
// 	}
// 	for (int i = 0; i < len1 * len2; i++)
// 		printf("%d", arr_res[i]);
// }