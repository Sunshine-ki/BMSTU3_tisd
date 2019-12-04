#include <stdlib.h>
#include <string.h>

#include "struct.h"

// typedef struct node_t
// {
// 	char *value;		 // значение в вершине
// 	unsigned int height; // высота дерева в данной вершине
// 	struct node_t *left;
// 	struct node_t *right;
// 	// конструктор вершины (то есть функция, которая создает вершину
// 	// со значением k)
// 	// node(int k) { key = k; left = right = 0; height = 1; }
// 	// node_t node = {value, height, left, right}
// } node_t;

node_t *create_node(const char *const value)
{
	node_t *node = (node_t *)malloc(sizeof(node_t));
	if (!node)
		return NULL;

	node->height = 1;
	node->left = (node->right = NULL);
	node->value;
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

//
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
	// балансировка не нужна
	return p;
}

node_t *insert(node_t *p, const char *const value) // вставка ключа k в дерево с корнем p
{
	if (!p)
		return create_node(value);

	if (strcmp(p->value, value) < 0)
		p->left = insert(p->left, value);

	else if (strcmp(p->value, value) > 0)
		p->right = insert(p->right, value);

	return balance(p);
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

node_t *remove(node_t *p, const char *const value) // удаление ключа k из дерева p
{
	if (!p)
		return NULL;

	if (strcmp(p->value, value) < 0)
		p->left = remove(p->left, value);

	else if (strcmp(p->value, value) > 0)
		p->right = remove(p->right, value);

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