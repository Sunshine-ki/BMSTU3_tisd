#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "binary_search_tree.h"

bin_search_s *get_bin_search(char word[MAX_LEN_WORD], bin_search_s *parent)
{
    bin_search_s *temp = (bin_search_s *)malloc(sizeof(bin_search_s));
    temp->left = temp->right = NULL;
    strcpy(temp->value, word);
    temp->parent = parent;
    return temp;
}

// Меньше 0	str1 меньше, чем str2
// 0	str1 равна str2
// Больше 0	str1 больше, чем str2
void insert_bin_search(bin_search_s **head, char word[MAX_LEN_WORD])
{
    bin_search_s *temp = NULL;
    bin_search_s *ins = NULL;

    if (*head == NULL)
    {
        *head = get_bin_search(word, NULL);
        return;
    }

    temp = *head;

    while (temp)
    {
        if (strcmp(word, temp->value) > 0)
        {
            if (temp->right)
            {
                temp = temp->right;
                continue;
            }
            else
            {
                temp->right = get_bin_search(word, temp);
                return;
            }
        }
        else if (strcmp(word, temp->value) < 0)
        {
            if (temp->left)
            {
                temp = temp->left;
                continue;
            }
            else
            {
                temp->left = get_bin_search(word, temp);
                return;
            }
        }
        else
        {
            return;
        }
    }
}

bin_search_s *find_bin_search(bin_search_s *parent, char word[MAX_LEN_WORD])
{
    bin_search_s *head = parent;

    while (head)
    {
        if (strcmp(word, head->value) > 0)
        {
            head = head->right;
            continue;
        }
        else if (strcmp(word, head->value) < 0)
        {
            head = head->left;
            continue;
        }
        else
        {
            return head;
        }
    }
    return NULL;
}

void remove_node_bin_search(bin_search_s *target)
{

    if (target->left && target->right) //Оба наследника есть
    {
        printf("я тут l + r\n");

        bin_search_s *local_max = find_max_node(target->left);
        printf("local_max = %s\n", local_max->value);
        strcpy(target->value, local_max->value);
        remove_node_bin_search(local_max);
        return;
    }
    else if (target->left) //Есть только левый наследник
    {
        printf("я тут l\n");

        if (target->parent == NULL)
        {
            printf("я тут ...\n");

            // target = target->left;
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
        printf("я тут r\n");

        if (target->parent == NULL)
        {
            printf("я тут ..\n");

            // target = target->left;
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
        printf("я тут\n");
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

    if (target)
        free(target);
}

void delete_bin_search(bin_search_s *root, char word[MAX_LEN_WORD])
{
    bin_search_s *target = find_bin_search(root, word);
    // printf("Target: %s\n", target->value);
    remove_node_bin_search(target);
}

bin_search_s *find_min_node(bin_search_s *root)
{
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

bin_search_s *find_max_node(bin_search_s *root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}

void print_bin_search(bin_search_s *root, const char *dir, int level)
{
    if (root)
    {
        printf("lvl %d %s = %s\n", level, dir, root->value);
        print_bin_search(root->left, "left", level + 1);
        print_bin_search(root->right, "right", level + 1);
    }
}