//  Implement insertion, deletion and
//  display (inorder, preorder and postorder) on binary search tree.

// Name -Sai Prashant Saxena
// Branch-CSE
// Subject-Data Structures
// Roll No-02220902719
#include <stdio.h>
#include <stdlib.h>

struct node *newNode(int);
struct node *insert(struct node *, int);
struct node *minValueNode(struct node *);
struct node *deleteNode(struct node *, int);
void display(struct node *);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

struct node
{
	int key;
	struct node *left, *right;
};

int main()
{
	struct node *root = NULL;
	int again = 1, ch, val;
	while (again)
	{
		printf("Enter 1 to add an element to tree.\n");
		printf("Enter 2 to delete an element from tree.\n");
		printf("Enter 3 to display the tree.\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter data which you want to add to tree: ");
			scanf("%d", &val);
			root = insert(root, val);
			break;
		case 2:
			printf("Enter the data which you want to delete from the tree: ");
			scanf("%d", &val);
			root = deleteNode(root, val);
			break;
		case 3:
			display(root);
			break;
		default:
			printf("Invalid Input.\n");
		}
		printf("\nDo you want to perform more operations? (0, 1): ");
		scanf("%d", &again);
	}
	return 0;
}

struct node *insert(struct node *node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key == node->key)
	{
		printf("Data already exists. Insertion not possible.");
		return node;
	}
	else if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct node *deleteNode(struct node *root, int key)
{
	if (root == NULL)
	{
		printf("Tree Empty\n");
		return root;
	}
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		struct node *temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
struct node *minValueNode(struct node *node)
{
	struct node *current = node;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

void display(struct node *root)
{
	printf("Inorder Traverse is");
	inorder(root);
	printf("\nPreorder Traverse is");
	preorder(root);
	printf("\nPostorder Traverse is");
	postorder(root);
}
void inorder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf(" %d", root->key);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf(" %d", root->key);
	preorder(root->left);
	preorder(root->right);
	return;
}
void postorder(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %d", root->key);
	return;
}
