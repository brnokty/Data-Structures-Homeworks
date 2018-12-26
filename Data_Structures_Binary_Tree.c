#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
	int value;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} tree;

tree *search(tree *parent, int value);
tree *min(tree *parent);
tree *max(tree *parent);

void traverse(tree *parent);
void insert(tree **root, int value, tree *parent);
void Sil(tree **root, int value);

void flush_stdin(void);

int main(int argc, char *argv[]) {
	int cmd = 0, value = 0;
	tree *root = NULL;
	tree *temp = NULL;

	do {
		printf("Mevcut komutlar\n\n"
			"1 - Ekle\n"
			"2 - Ara\n"
			"3 - Sil\n"
			"4 - Minimum\n"
			"5 - Maximum\n"
			"0 - Cikis\n\nSecim..");
		scanf("%d", &cmd);

		switch (cmd) {
		case 1:
			printf("eklenecek deger..");
			scanf("%d", &value);
			insert(&root, value, NULL);
			break;
		case 2:
			printf("bulunacak deger..");
			scanf("%d", &value);
			if (search(root, value) == NULL) {
				printf("%d agacta bulunamadi!\n", value);
			}
			else {
				printf("%d agacta bulunur!\n", value);
			}
			break;
		case 3:
			printf("silinecek deger..");
			scanf("%d", &value);
			Sil(&root, value);
			break;
		case 4:
			temp = min(root);
			printf("\nMinimum deger : %d", temp->value);
			break;
		case 5:
			temp = max(root);
			printf("\nMaximum deger : %d", temp->value);
			break;
		}

		printf("\n");
		for (int i = 0; i < 120; i++, printf("-"));
		printf("\n");

		traverse(root);

		printf("\n\n");
		for (int i = 0; i < 120; i++, printf("-"));
		printf("\n\n");

	} while (cmd != 0);

	return 0;
}


tree *search(tree *parent, int value) {
	if (parent == NULL) {
		return NULL;
	}

	if (value == parent->value) {
		return parent;
	}

	if (value < parent->value) {
		return search(parent->left, value);
	}
	else {
		return search(parent->right, value);
	}
}


tree *min(tree *parent) {
	if (parent == NULL) {
		return NULL;
	}

	tree *min = parent;
	while (min->left != NULL) {
		min = min->left;
	}

	return min;
}

tree *max(tree *parent) {
	if (parent == NULL) {
		return NULL;
	}

	tree *max = parent;
	while (max->right != NULL) {
		max = max->right;
	}

	return max;
}

void traverse(tree *parent) {
	if (parent != NULL) {
		traverse(parent->left);
		printf("(%d)->", parent->value);
		traverse(parent->right);
	}
}

void insert(tree **root, int value, tree *parent) {
	tree *p = NULL;

	if (*root == NULL) {
		p = (tree*)malloc(sizeof(tree));

		p->value = value;
		p->left = NULL;
		p->right = NULL;
		p->parent = parent;

		*root = p;

		return;
	}

	if (value < (*root)->value) {
		insert(&((*root)->left), value, *root);
	}
	else {
		insert(&((*root)->right), value, *root);
	}
}

void Sil(tree **root, int value) {
	if (*root == NULL) {
		return;
	}

	tree *parent = *root,
		*current = *root;

	while (current != NULL) {
		if (value == current->value) {

			if (current->left == NULL && current->right == NULL) {
				if (current == *root) {
					free(*root);
					*root = NULL;
				}
				else {
					if (current->value < parent->value) {
						parent->left = NULL;
					}
					else {
						parent->right = NULL;
					}
					free(current);
				}
			}

			else if (current->left == NULL || current->right == NULL) {
				if (current->value < parent->value) {
					if (current->left == NULL) {
						parent->left = current->right;
						current->right->parent = parent;
					}
					else {
						parent->left = current->left;
						current->left->parent = parent;
					}
				}
				else {
					if (current->left == NULL) {
						parent->right = current->right;
						current->right->parent = parent;
					}
					else {
						parent->right = current->left;
						current->left->parent = parent;
					}
				}
				free(current);
			}

			else {
				if (current == *root) {
					printf("Maalesef, hem sol hem de sag alt ogeye sahip olan kök dügümünü silemiyorum!\n");
				}
				else {
					tree *submin = min(current->right);

					tree *clone = (tree*)malloc(sizeof(tree));

					clone->value = submin->value;
					clone->parent = parent;
					clone->left = current->left;

					if (submin == current->right) {
						clone->right = NULL;
					}
					else {
						clone->right = current->right;
					}

					if (current->value < parent->value) {
						parent->left = clone;
					}
					else {
						parent->right = clone;
					}

					if (submin->value < submin->parent->value) {
						submin->parent->left = NULL;
					}
					else {
						submin->parent->right = NULL;
					}

					free(current);
					free(submin);
				}
			}

			return;

		}
		else {
			parent = current;
			if (value < current->value) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
	}

	printf("%d agacta bulunamadi\n", value);

}

void flush_stdin(void) {
	while (getc(stdin) != '\n');
}
