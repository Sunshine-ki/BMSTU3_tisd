#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define OK 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define MAX_COUNT_COLLISIONS 10
#define LEN_HASH_TABLE 10

#define MODE_HASH_TABLE 1
#define MODE_BST 2 // BINARY SEARCH TREE.
#define MODE_BALANCED_TREE 3

#define FILE_OPEN_HASH "text/text_bin_search.txt" // "text/text.txt"

#define OK 0

int main(void)
{
    char word[MAX_LEN_WORD];
    int answer = -1;

    FILE *f = fopen(FILE_OPEN_HASH, "r");

    int count_hash = 1;

    hash_s **hash_table = create_hash_table(f, &count_hash); // Хеш-таблица
    value_s data = {0};
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

            add_element_hash_table(stdin, hash_table, word);

            insert_bin_search(&root, word);

            break;
        case 4:
            green();
            printf("Введите слово, которое хотели бы удалить: ");
            white();

            scanf("%s", word);

            if (root)
            {
                yellow();
                delete_bin_search(&root, word);
                white();
            }
            else
            {
                red();
                printf("Пусто!(Для дерева)\n");
                white();
            }

            if (!is_empty_hash_table(hash_table, count_hash))
            {
                del_element_hash_table(hash_table, word);
            }
            else
            {
                red();
                printf("Пусто!(Для хеш-таблицы)\n");
                white();
            }

            break;
        case 5:
            green();
            printf("Введите слово, которое нужно найти: ");
            white();

            scanf("%s", word);

            data = find_hash(hash_table, word);
            if (!strcmp(data.name, ""))
            {
                red();
                printf("\nНет данного элемента.(Для хеш-таблицы)\n");
                white();
            }
            else
            {
                green();
                printf("\nНайдено: (Для хеш-таблицы)  %s.\n", data.name);
                white();
            }

            if (root)
            {
                find_root = find_bin_search(root, word);

                if (find_root)
                {
                    green();
                    printf("\nНайдено:(Для дерева)  %s\n", find_root->data);
                    white();
                }
                else
                {
                    red();
                    printf("\nНет данного элемента.(Для дерева)\n");
                    white();
                }
            }

            break;
        case 6:
            f = fopen(FILE_OPEN_HASH, "r");

            green();
            printf("\nДобавлено %d элементов!(Для хеш-таблицы)\n", input_hash_table(f, hash_table));
            white();
            fseek(f, 0, 0);
            green();
            printf("Добавлено %d элементов!(Для дерева)\n", input_bin_search(f, &root));
            white();

            fclose(f);
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
