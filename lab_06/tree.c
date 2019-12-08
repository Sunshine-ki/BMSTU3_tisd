#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "instructions.h"
#include "struct.h"
#include "hash.h"
#include "bin_tree.h"
#include "binary_search_tree.h"

#define OK 0

int main()
{
    bin_search_s *root = NULL;

    insert_bin_search(&root, "g");
    insert_bin_search(&root, "b");
    insert_bin_search(&root, "c");
    insert_bin_search(&root, "d");
    insert_bin_search(&root, "e");
    insert_bin_search(&root, "f");
    insert_bin_search(&root, "a");

    print_bin_search(root, "root", 0);

    printf("max = %s\n", find_max_node(root)->value);
    printf("min = %s\n", find_min_node(root)->value);

    // delete_bin_search(root, "4");
    // printf("parent of 7 is %s\n", find_bin_search(root, "7")->parent->value);

    // print_bin_search(root, "root", 0);
    // delete_bin_search(root, "8");
    // print_bin_search(root, "root", 0);

    printf("------------------\n");
    // if (root->left && root->right)
    // printf("я тут\n");

    delete_bin_search(root, "g");
    print_bin_search(root, "root", 0);

    return OK;
}

// for bin_tree
// int main(void)
// {
//     char word[MAX_LEN_WORD];

//     FILE *f = fopen("text/text2.txt", "r");

//     node_t *tree = create_node("1");

//     input_tree(f, &tree);
//     // printf("%d\n", height(tree));

//     apply_pre(tree, stdout);

//     fclose(f);

//     return OK;
// }
