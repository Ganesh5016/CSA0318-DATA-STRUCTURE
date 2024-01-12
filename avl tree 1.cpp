#include <stdio.h>
#include <stdlib.h>
struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};
int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}
int max(int a, int b) {
  return (a > b) ? a : b;
}
struct Node *newNode(int key) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}
struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}
struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}
struct Node *insertNode(struct Node *node, int key) {
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;
  node->height = 1 + max(height(node->left),height(node->right));
  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);
  if (balance < -1 && key > node->right->key)
    return leftRotate(node);
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}
struct Node *minValueNode(struct Node *node) {
  struct Node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}
struct Node *deleteNode(struct Node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  if (root == NULL)
    return root;
  root->height = 1 + max(height(root->left),height(root->right));
  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);
  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
  return root;
}
void preorder(struct Node *root) 
{
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}
void inorder(struct Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}
void postorder(struct Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->key);
	}
}
struct Node* searchAVL(struct Node* root, int element) 
{
  if (root == NULL || root->key == element) {
    return root;
  }
  else if (element < root->key) {
    return searchAVL(root->left, element);
  }
  else {
    return searchAVL(root->right, element);
  }
}
int main()
{
	struct Node *root=NULL;
	struct Node *result=NULL;
	int val,ch;
	while(1)
	{
		printf("\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.delete\n6.search\n7.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter the element:");
				scanf("%d",&val);
				root=insertNode(root,val);
				break;
			case 2:
				printf("\ninorder element:");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("\npreorder element:");
				preorder(root);
				printf("\n");
				break;
			case 4:
				printf("\npostorder element:");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("\nenter the element:");
				scanf("%d",&val);
				root=deleteNode(root,val);
				break;
			case 6:
				printf("\nenter the element");
				scanf("%d",&val);
				result = searchAVL(root, val);
                if (result == NULL)
                {
                    printf("\nNode not found!\n");
                }
                else
                {
                    printf("\n Node found\n");
                }
                break;
			case 7:
				exit(1);
			default:
				printf("\ninvalid");	
		}
	}
}
