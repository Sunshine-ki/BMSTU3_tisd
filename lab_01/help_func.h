#ifndef PRINT_H
#define PRINT_H

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

void print_arr(int arr[LEN], int len);
void reverse(int *num);
int len_int_number(int num);
void print_struct(number_attributes num, int len);
int char_to_int(char symbol);
void lower(char *str);
int my_strchr(char *str, char symbol);
void reset_to_zero(number_attributes *number);
int count_symbol(char *str, char symbol);
int format_numer(char number[LEN]);
void swap(char *a, char *b);
int sign_of_number(char symbol);
void convenient_input();
void information();

#endif