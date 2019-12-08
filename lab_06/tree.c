#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define OK 0

// for avl
int main(void)
{
    char word[MAX_LEN_WORD];

    FILE *f = fopen("text/text_bin_search.txt", "r");

    node_t *tree = NULL;

    input_tree(f, &tree);

    print_avl(tree, "root", 0);

    printf("______\n");

    tree = remove_tree(tree, "a");
    tree = remove_tree(tree, "b");
    tree = remove_tree(tree, "c");

    print_avl(tree, "root", 0);

    fclose(f);

    return OK;
}

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
