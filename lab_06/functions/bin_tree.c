#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "struct.h"
#include "bin_tree.h"

int input_tree(FILE *f, node_t **p)
{
	char word[MAX_LEN_WORD]; // Слово.
	int count = 0;			 // Кол-во слов.

	// Итерируемся, пока не конец файла и записываем слово в word.
	while (!feof(f) && fscanf(f, "%s", word))
	{
		*p = insert(*p, word);
		count++; // Считаем кол-во слов.
	}

	return count; // Возвращаем кол-во слов.
}

node_t *balance_tree(bin_search_s *bts, node_t **tree_avl)
{
	if (bts)
	{
		// printf("зашёл\n");
		*tree_avl = insert(*tree_avl, bts->data);
		balance_tree(bts->left, tree_avl);
		balance_tree(bts->right, tree_avl);
	}

	return *tree_avl;
}

void print_avl(node_t *root, const char *dir, int level)
{
	if (root)
	{
		printf("lvl %d %s = %s\n", level, dir, root->value);
		print_avl(root->left, "left", level + 1);
		print_avl(root->right, "right", level + 1);
	}
}

node_t *create_node(char word[MAX_LEN_WORD])
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (!node)
		return NULL;

	node->height = 1;
	node->left = (node->right = NULL);
	strcpy(node->value, word);
	return node;
}

// возвращает высоту, если посалали ненулевой указатель, а
// если нулевой, то высота 0
unsigned int height(node_t *p)
{
	return p ? p->height : 0;
}

// расчет коэффициента балансировки
int balance_factor(node_t *p)
{
	return height(p->right) - height(p->left);
}

void fix_height(node_t *p)
{
	unsigned int hl = height(p->left);
	unsigned int hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

// функция возвращает новую вершину
// поворот направо вокруг p
node_t *rotate_right(node_t *p)
{
	node_t *q = p->left;
	p->left = q->right;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}

// функция возвращает новую вершину
// поворот налево вокруг q
node_t *rotate_left(node_t *q)
{
	node_t *p = q->right;
	q->right = p->left;
	p->left = q;
	fix_height(q);
	fix_height(p);
	return p;
}

// Балансировка
node_t *balance(node_t *p)
{
	fix_height(p);

	if (balance_factor(p) == 2)
	{
		if (balance_factor(p->right) < 0)
			p->right = rotate_right(p->right);
		return rotate_left(p);
	}

	else if (balance_factor(p) == -2)
	{
		if (balance_factor(p->left) > 0)
			p->left = rotate_left(p->left);
		return rotate_right(p);
	}
	// балансировка не нужна.
	return p;
}

node_t *insert(node_t *p, char word[MAX_LEN_WORD]) // вставка ключа k в дерево с корнем p
{
	if (!p)
		return create_node(word);

	if (strcmp(p->value, word) > 0)
		p->left = insert(p->left, word);

	else if (strcmp(p->value, word) < 0)
		p->right = insert(p->right, word);

	// return p;
	// printf(" ");
	return balance(p);
}

node_t *find_avl(node_t *p, char word[MAX_LEN_WORD], count_s *count_all)
{
	node_t *target;

	if (!p)
		return NULL;

	if (strcmp(word, p->value) < 0)
	{
		(count_all->count_avl_find)++;
		target = find_avl(p->left, word, count_all);
	}
	else if (strcmp(word, p->value) > 0)
	{
		(count_all->count_avl_find)++;
		target = find_avl(p->right, word, count_all);
	}
	else
		return p;

	return target;
}

//
node_t *find_min(node_t *p) // поиск узла с минимальным ключом в дереве p
{
	return p->left ? find_min(p->left) : p;
}

node_t *remove_min(node_t *p) // удаление узла с минимальным ключом из дерева p
{
	if (!p->left)
		return p->right;
	p->left = remove_min(p->left);
	return balance(p);
}

node_t *remove_tree(node_t *p, char word[MAX_LEN_WORD]) // удаление ключа k из дерева p
{
	if (!p)
		return NULL;

	if (strcmp(p->value, word) > 0)
		p->left = remove_tree(p->left, word);

	else if (strcmp(p->value, word) < 0)
		p->right = remove_tree(p->right, word);

	else //  k == p->key
	{
		node_t *q = p->left;
		node_t *r = p->right;
		free(p);
		if (!r)
			return q;
		node_t *min = find_min(r);
		min->right = remove_min(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

// --------------------------
// void to_dot(node_t *tree, FILE *f);
// void export_to_dot(FILE *f, const char *tree_name, node_t *tree);
// void apply_pre(node_t *tree, FILE *f);

// // Функция вывода дерева
// void print_tree(node_t *p)
// {
// 	if (p)
// 	{
// 		print_tree(p->left);
// 		printf("%d %s\n", p->height, p->value);
// 		print_tree(p->right);
// 	}
// }

// // .....

// // обход дерева
// void apply_pre(node_t *tree, FILE *f)
// {
// 	if (tree == NULL)
// 	{
// 		return;
// 	}

// 	to_dot(tree, f);
// 	apply_pre(tree->left, f);
// 	apply_pre(tree->right, f);
// }

// void export_to_dot(FILE *f, const char *tree_name, node_t *tree)
// {
// 	fprintf(f, "digraph %s {\n", tree_name);

// 	apply_pre(tree, f);

// 	fprintf(f, "}\n");
// }

// void to_dot(node_t *tree, FILE *f)
// {

// 	if (tree->left)
// 	{
// 		fprintf(f, "\"%s \" -> \"%s \";\n", tree->value, tree->left->value);
// 	}

// 	if (tree->right)
// 	{
// 		fprintf(f, "\"%s \" -> \"%s \";\n", tree->value, tree->right->value);
// 	}
// }
// .....