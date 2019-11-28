#ifndef CONST_O

#define CONST_O

#define OK 0
#define TRUE 1
#define FALSE 0
#define READED 1
#define NAME_FILE 1
#define MAX_LEN_ANSWER 32
#define MAX_SURNAME 128
#define MAX_TITLE 128
#define MAX_PUBLISH 128
#define MAX_INDUSTRY 128
#define MAX 128
#define ERROR_INPUT -1
#define LEN_STRUCT 100
#define EMPTY_STRING "\0"

// typedef enum
// {
//     NOVEL,
//     PLAY,
//     POEMS_FICTION
// } type_fiction; // (Роман. Пьеса. Стихи) Художественная.

// typedef enum
// {
//     FAIRY_TALE,
//     POEMS_CHILDRENS
// } type_childrens; // (Сказка, Стихи) Детская.

// typedef enum
// {
//     TECHNICAL,
//     FICTION,
//     CHILDRENS
// } type_literature_t;

typedef struct
{
    int key;
    int count;
} key_struct;

typedef struct
{
    char industry[MAX_INDUSTRY]; // Отрасль.
    int domestic;                // Отечественная.
    int transferable;            // Переводная.
    int year_publication;        // Год издания.

} technical_strust; // Техничсекая.

typedef union {
    technical_strust technical_type; // Техническая.
    int fiction_type;                // (Роман. Пьеса. Стихи)
    int childrens_type;              // (Сказка, Стихи)
} type_literature_struct;            // Вид литературы.

typedef struct
{
    int row;                                // ключ ряда
    char surname[MAX_SURNAME];              // Фамилия автора.
    char title[MAX_TITLE];                  // Название книги.
    char publishing_house[MAX_PUBLISH];     // Издательство.
    int number_pages;                       // Кол-во страниц.
    int type;                               // Вид литературы.
    type_literature_struct type_literature; // Вариантное поле.
} literature;

#endif

// _______________________________________________ //

// typedef struct
// {
//     type_fiction type; // (Роман. Пьеса. Стихи)
// } fiction_struct;      // Художественная.

// typedef struct
// {
//     type_childrens type; // (Сказка, Стихи)
// } childrens_struct;

// typedef union {
//     technical_strust technical; // Техническая.
//     fiction_struct fiction;     // Художественная.
//     childrens_struct childrens; // Детская.
// } type_literature_struct;       // Вид литературы.

// _______________________________________________ //
