#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "binary_search_tree.h"
#include "struct.h"
#include "colors.h"

#define OK 0

#define CMP_EQ(a, b) (strcmp(a, b) == 0)
#define CMP_LT(a, b) (strcmp(a, b) < 0)
#define CMP_GT(a, b) (strcmp(a, b) > 0)

bin_search_s *create_bin_search(char value[MAX_LEN_WORD], bin_search_s *parent)
{
    bin_search_s *tmp = (bin_search_s *)malloc(sizeof(bin_search_s));
    tmp->left = tmp->right = NULL;
    strcpy(tmp->data, value);
    tmp->parent = parent;
    return tmp;
}

int input_bin_search(FILE *f, bin_search_s **root)
{
    char word[MAX_LEN_WORD]; // Слово.
    int count = 0;           // Кол-во слов.

    // Итерируемся, пока не конец файла и записываем слово в word.
    while (!feof(f) && fscanf(f, "%s", word))
    {
        insert_bin_search(root, word); // Добавляем элемент
        count++;                       // Считаем кол-во слов.
    }

    return count; // Возвращаем кол-во слов.
}

void insert_bin_search(bin_search_s **head, char value[MAX_LEN_WORD])
{
    bin_search_s *tmp = NULL;
    bin_search_s *ins = NULL;
    if (*head == NULL)
    {
        *head = create_bin_search(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (CMP_GT(value, tmp->data))
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = create_bin_search(value, tmp);
                return;
            }
        }
        else if (CMP_LT(value, tmp->data))
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = create_bin_search(value, tmp);
                return;
            }
        }
        else
        {
            return;
        }
    }
}

bin_search_s *find_min_bin_search(bin_search_s *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

bin_search_s *find_max_bin_search(bin_search_s *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

bin_search_s *find_bin_search(bin_search_s *root, char value[MAX_LEN_WORD])
{
    while (root)
    {
        if (CMP_GT(root->data, value))
        {
            root = root->left;
            continue;
        }
        else if (CMP_LT(root->data, value))
        {
            root = root->right;
            continue;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

void remove_bin_search(bin_search_s *target)
{
    if (target->left && target->right) //Оба наследника есть
    {
        bin_search_s *localMax = find_max_bin_search(target->left);
        strcpy(target->data, localMax->data);
        remove_bin_search(localMax);
        return;
    }
    else if (target->left) //Есть только левый наследник
    {
        if (target->parent == NULL)
        {
            bin_search_s *temp = find_max_bin_search(target->left);
            strcpy(target->data, find_max_bin_search(target->left)->data);
            remove_bin_search(temp);
            return;
        }
        if (target == target->parent->left)
        {
            target->parent->left = target->left;
        }
        else
        {
            target->parent->right = target->left;
        }
    }
    else if (target->right) //Есть только правый наследник
    {
        if (target->parent == NULL)
        {
            bin_search_s *temp = find_min_bin_search(target->right);
            strcpy(target->data, find_min_bin_search(target->right)->data);
            remove_bin_search(temp);
            return;
        }
        if (target == target->parent->right)
        {
            target->parent->right = target->right;
        }
        else
        {
            target->parent->left = target->right;
        }
    }
    else //Нет наследников
    {
        // Если нет наследников, то нужно узнать,
        // Каким поддеревом относительно родителя является узел.
        if (target == target->parent->left)
        {
            target->parent->left = NULL;
        }
        else
        {
            target->parent->right = NULL;
        }
    }
    free(target);
}

void delete_bin_search(bin_search_s **root, char value[MAX_LEN_WORD])
{
    bin_search_s *target = find_bin_search(*root, value);
    if (target == NULL)
    {
        printf("Нет данного узла.\n");
        return;
    }
    // if (target->parent == NULL && (target->left == NULL || target->right == NULL))
    // {
    //     printf("Вы хотите удалить корень.\n");
    //     return;
    // }
    remove_bin_search(target);
}

void print_bin_search(bin_search_s *root, const char *dir, int level)
{
    if (root)
    {
        printf("lvl %d %s = %s\n", level, dir, root->data);
        print_bin_search(root->left, "left", level + 1);
        print_bin_search(root->right, "right", level + 1);
    }
}

// bin_search_s *get_bin_search(char word[MAX_LEN_WORD], bin_search_s *parent)
// {
//     bin_search_s *temp = (bin_search_s *)malloc(sizeof(bin_search_s));
//     temp->left = temp->right = NULL;
//     strcpy(temp->value, word);
//     temp->parent = parent;
//     return temp;
// }

// // Меньше 0	str1 меньше, чем str2
// // 0	str1 равна str2
// // Больше 0	str1 больше, чем str2
// void insert_bin_search(bin_search_s **head, char word[MAX_LEN_WORD])
// {
//     bin_search_s *temp = NULL;
//     bin_search_s *ins = NULL;

//     if (*head == NULL)
//     {
//         *head = get_bin_search(word, NULL);
//         return;
//     }

//     temp = *head;

//     while (temp)
//     {
//         if (strcmp(word, temp->value) > 0)
//         {
//             if (temp->right)
//             {
//                 temp = temp->right;
//                 continue;
//             }
//             else
//             {
//                 temp->right = get_bin_search(word, temp);
//                 return;
//             }
//         }
//         else if (strcmp(word, temp->value) < 0)
//         {
//             if (temp->left)
//             {
//                 temp = temp->left;
//                 continue;
//             }
//             else
//             {
//                 temp->left = get_bin_search(word, temp);
//                 return;
//             }
//         }
//         else
//         {
//             return;
//         }
//     }
// }

// bin_search_s *find_bin_search(bin_search_s *parent, char word[MAX_LEN_WORD])
// {
//     bin_search_s *head = parent;

//     while (head)
//     {
//         if (strcmp(word, head->value) > 0)
//         {
//             head = head->right;
//             continue;
//         }
//         else if (strcmp(word, head->value) < 0)
//         {
//             head = head->left;
//             continue;
//         }
//         else
//         {
//             return head;
//         }
//     }
//     return NULL;
// }

// void remove_node_bin_search(bin_search_s **target1)
// {
//     bin_search_s *target = *target1;

//     if (target->left && target->right) //Оба наследника есть
//     {
//         printf("я тут l + r\n");

//         bin_search_s *local_max = find_max_node(target->left);
//         printf("local_max = %s\n", local_max->value);
//         strcpy(target->value, local_max->value);
//         remove_node_bin_search(&local_max);
//         return;
//     }
//     else if (target->left) //Есть только левый наследник
//     {
//         printf("я тут l\n");

//         if (target->parent == NULL)
//         {
//             printf("я тут ...\n");
//             // bin_search_s *out = target;
//             target = target->left;
//             // target = target->left;
//             return;
//         }

//         if (target == target->parent->left)
//         {
//             target->parent->left = target->left;
//         }
//         else
//         {
//             target->parent->right = target->left;
//         }
//     }
//     else if (target->right) //Есть только правый наследник
//     {
//         printf("я тут r\n");

//         if (target->parent == NULL)
//         {
//             printf("я тут ..\n");

//             // target = target->left;
//             return;
//         }

//         if (target == target->parent->right)
//         {
//             target->parent->right = target->right;
//         }
//         else
//         {
//             target->parent->left = target->right;
//         }
//     }
//     else //Нет наследников
//     {
//         printf("я тут\n");
//         // Если нет наследников, то нужно узнать,
//         // Каким поддеревом относительно родителя является узел.
//         if (target == target->parent->left)
//         {
//             target->parent->left = NULL;
//         }
//         else
//         {
//             target->parent->right = NULL;
//         }
//     }

//     if (target)
//         free(target);
// }

// void delete_bin_search(bin_search_s **root, char word[MAX_LEN_WORD])
// {
//     bin_search_s *target = find_bin_search(*root, word);
//     // printf("Target: %s\n", target->value);
//     remove_node_bin_search(&target);
// }

// bin_search_s *find_min_node(bin_search_s *root)
// {
//     while (root->left)
//     {
//         root = root->left;
//     }
//     return root;
// }

// bin_search_s *find_max_node(bin_search_s *root)
// {
//     while (root->right)
//     {
//         root = root->right;
//     }
//     return root;
// }

// void print_bin_search(bin_search_s *root, const char *dir, int level)
// {
//     if (root)
//     {
//         printf("lvl %d %s = %s\n", level, dir, root->value);
//         print_bin_search(root->left, "left", level + 1);
//         print_bin_search(root->right, "right", level + 1);
//     }
// }
