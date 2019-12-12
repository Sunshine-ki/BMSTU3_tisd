#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "file.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define MAX_COUNT_COLLISIONS 10
#define LEN_HASH_TABLE 10

#define MODE_HASH_TABLE 1
#define MODE_BST 2 // BINARY SEARCH TREE.
#define MODE_BALANCED_TREE 3

#define FILE_OPEN_HASH "text/text.txt" // "text/text_bin_search.txt"

#define OK 0

int count_word(FILE *f)
{
    int count = 0;
    char word[MAX_LEN_WORD];

    while (!feof(f) && fscanf(f, "%s", word))
    {
        count++; // Cчитаем кол-во слов.}
    }
    return count;
}

int main(void)
{
    // double a = clock();
    // value_s dataa = {0};
    // double b = clock();
    // printf("b - a%f\n", b - a);

    char word[MAX_LEN_WORD];
    int answer = -1;
    time_s my_time = {0};
    count_s count_all = {0};

    int collision = 0;

    FILE *f = fopen(FILE_OPEN_HASH, "r");

    int count_hash = 1;

    green();
    printf("Кол-во слов в файле : %d\nВведите размерность Хеш-таблицы : ", count_word(f));
    white();
    fseek(f, 0, 0);
    scanf("%d", &count_hash);

    hash_s **hash_table = (hash_s **)malloc(sizeof(hash_s *) * count_hash);
    // hash_s **hash_table = create_hash_table(f, &count_hash); // Хеш-таблица
    int flag;
    // value_s data = {0};
    int data;
    printf("Слов = %d\n", count_hash);

    bin_search_s *root = NULL; // ДДП
    bin_search_s *find_root = NULL;

    node_t *tree_avl = NULL; // АВЛ
    node_t *find_node_avl = NULL;

    while (answer)
    {
        instruction();

        answer = scanf_answer();

        switch (answer)
        {
        case 0:
            break;
        case 1:
            if (is_empty_hash_table(hash_table, count_hash))
            {
                red();
                printf("Таблица пуста!\n");
                white();
            }
            else
            {
                yellow();
                output_hash_table(stdout, hash_table, count_hash);
                white();
            }
            break;
        case 2:
            if (root)
            {
                yellow();
                print_bin_search(root, "root", 0);
                white();
            }
            else
            {
                red();
                printf("Дерево пусто!\n");
                white();
            }
            break;
        case 3:
            green();
            printf("Введите слово, которое хотели бы добавить: ");
            white();

            scanf("%s", word);

            // if (find_hash(hash_table, word, &count_all))
            // {
            //     // count_all.count_hash_find = 0;
            //     green();
            //     printf("Уже имеется данный элемент!\n");
            //     white();
            //     break;
            // }

            my_time.time_bst_add_start = clock();
            insert_bin_search(&root, word);
            my_time.time_bst_add_end = clock();

            green();
            printf("Добавлено в дерево за :  %f\n", //
                   my_time.time_bst_add_end - my_time.time_bst_add_start);
            white();

            my_time.time_hash_add_start = clock();
            flag = add_element_hash_table(stdin, hash_table, word, &collision, count_hash);
            my_time.time_hash_add_end = clock();

            // if (flag == 1)
            // {
            green();
            printf("Добавлено в хеш-таблицу за :  %f\n", //
                   my_time.time_hash_add_end - my_time.time_hash_add_start);
            white();
            // }
            // else if (flag == 2)
            // {
            //     green();
            //     printf("Уже имеется данный элемент!\n");
            //     white();
            // }

            f = fopen(FILE_OPEN_HASH, "a");
            my_time.time_file_add_start = clock();
            add_element_in_file(f, word);
            my_time.time_file_add_end = clock();
            fclose(f);

            green();
            printf("Добавлено в файл за :  %f\n", //
                   my_time.time_file_add_end - my_time.time_file_add_start);
            white();

            if (tree_avl)
            {
                my_time.time_avl_add_start = clock();
                tree_avl = insert(tree_avl, word);
                my_time.time_avl_add_end = clock();

                green();
                printf("Добавлено в АВЛ дерево за :  %f\n", //
                       my_time.time_avl_add_end - my_time.time_avl_add_start);
                white();
            }

            break;
        // case 4:
        //     green();
        //     printf("Введите слово, которое хотели бы удалить: ");
        //     white();

        //     scanf("%s", word);

        //     if (root)
        //     {
        //         yellow();
        //         delete_bin_search(&root, word);
        //         white();
        //     }
        //     else
        //     {
        //         red();
        //         printf("Пусто!(Для дерева)\n");
        //         white();
        //     }

        //     if (!is_empty_hash_table(hash_table, count_hash))
        //     {
        //         del_element_hash_table(hash_table, word);
        //     }
        //     else
        //     {
        //         red();
        //         printf("Пусто!(Для хеш-таблицы)\n");
        //         white();
        //     }

        //     break;
        case 4:
            green();
            printf("Введите слово, которое нужно найти: ");
            white();

            scanf("%s", word);
            // int h = hash_function(word);

            if (root)
            {
                count_all.count_hash_find = 0;
                count_all.count_avl_find = 0;
                count_all.count_bst_find = 0;

                my_time.time_bst_find_start = clock();
                find_root = find_bin_search(root, word, &count_all);
                my_time.time_bst_find_end = clock();

                if (find_root)
                {
                    green();
                    // printf("\nНайдено в дереве за :  %f\n", //
                    //    my_time.time_bst_find_end - my_time.time_bst_find_start);

                    printf("Кол-во сравнений (ДДП): %d\n", count_all.count_bst_find + 1);
                    white();
                }
                // else
                // {
                //     red();
                //     printf("\nНет данного элемента.(Для дерева)\n");
                //     white();
                // }
            }

            if (tree_avl)
            {
                my_time.time_avl_find_start = clock();
                find_node_avl = find_avl(tree_avl, word, &count_all);
                my_time.time_avl_find_end = clock();

                if (find_node_avl)
                {
                    green();
                    // printf("\nНайдено в АВЛ дереве за :  %f\n", //
                    //    my_time.time_avl_find_end - my_time.time_avl_find_start);
                    printf("Кол-во сравнений (АВЛ): %d\n", count_all.count_avl_find + 1);
                    white();
                }
            }

            my_time.time_hash_find_start = clock();
            data = find_hash(hash_table, word, &count_all, count_hash);
            my_time.time_hash_find_end = clock();

            if (!data)
            {
                red();
                printf("\nНет данного элемента.\n");
                white();
            }
            else
            {
                //  ((double) end - start) / ((double) CLOCKS_PER_SEC));
                green();
                // printf("\nНайдено в хеш-таблце за :  %f\n", //
                //    my_time.time_hash_find_end - my_time.time_hash_find_start);
                printf("Кол-во сравнений (Хеш-таблица): %d\n", count_all.count_hash_find + 1);
                // printf("\nНайдено: (Для хеш-таблицы)  %s.\n", data.name);
                white();
            }

            break;
        case 5:
            f = fopen(FILE_OPEN_HASH, "r");

            input_hash_table(f, hash_table, &collision, count_hash);
            fseek(f, 0, 0);
            input_bin_search(f, &root);

            green();
            printf("\nДобавлено");
            white();

            // green();
            // printf("\nДобавлено %d элементов!(Для хеш-таблицы)\n", input_hash_table(f, hash_table)); // &collision);
            // white();
            // fseek(f, 0, 0);
            // green();
            // printf("Добавлено %d элементов!(Для дерева)\n", input_bin_search(f, &root));
            // white();

            fclose(f);
            break;
        case 6:

            if (root)
            {
                my_time.time_balance_tree_start = clock();
                tree_avl = balance_tree(root, &tree_avl);
                my_time.time_balance_tree_end = clock();

                green();
                printf("Веремя балансировки :  %f\n", //
                       my_time.time_balance_tree_end - my_time.time_balance_tree_start);
            }
            else
            {
                red();
                printf("Заполните дерево, чтобы получить АВЛ дерево!\n");
                white();
            }

            break;
        case 7:
            if (tree_avl)
            {
                green();
                print_avl(tree_avl, "root", 0);
                white();
            }
            else
            {
                red();
                printf("Сбалансируйте дерево, чтобы получить АВЛ дерево!\n");
                white();
            }

            break;
        default:
            printf("\33[31m");
            printf("\t\t\t\t\t\t\t\t\t Нет данного действия.\n");
            printf("\e[0m");
            break;
        }
    }

    green();
    printf("Завершение программы!\n");
    white();

    return OK;
}

// for avl
// int main(void)
// {
//     char word[MAX_LEN_WORD];

//     FILE *f = fopen("text/text_bin_search.txt", "r");

//     node_t *tree = NULL;

//     input_tree(f, &tree);

//     print_avl(tree, "root", 0);

//     printf("______\n");

//     tree = remove_tree(tree, "a");
//     tree = remove_tree(tree, "b");
//     tree = remove_tree(tree, "c");

//     print_avl(tree, "root", 0);

//     fclose(f);

//     return OK;
// }

// for bin_tree (bst)
// int main(void)
// {
//     bin_search_s *root = NULL;

//     insert_bin_search(&root, "d");
//     insert_bin_search(&root, "c");
//     insert_bin_search(&root, "b");
//     insert_bin_search(&root, "a");

//     // insert_bin_search(&root, "g");
//     // insert_bin_search(&root, "b");
//     // insert_bin_search(&root, "c");
//     // insert_bin_search(&root, "d");
//     // insert_bin_search(&root, "e");
//     // insert_bin_search(&root, "f");
//     // insert_bin_search(&root, "a");

//     print_bin_search(root, "root", 0);
//     printf("---------------\n");

//     delete_bin_search(&root, "d");
//     print_bin_search(root, "root", 0);
//     printf("---------------\n");

//     return OK;
// }
