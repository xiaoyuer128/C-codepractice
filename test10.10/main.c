#include <stdlib.h>
#include <stdio.h>
#define NULL 0
#define M 100
typedef char DataType;
typedef struct Node
{
DataType data;/*数据域*/
struct Node *leftChild;/*左子树指针*/
struct Node *rightChild;/*右子树指针*/
}BiTreeNode;/*结点的结构体定义*/
typedef struct stack
{
   BiTreeNode *shu[M];
   int top;
}seqstack;//
BiTreeNode *root;
seqstack s;
void setnull()
{
	s.top=0;
}
void Initiate(BiTreeNode **root)
{
*root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
(*root)->leftChild = NULL;
(*root)->rightChild = NULL;
}
BiTreeNode *InsertLeftNode(BiTreeNode *curr, DataType x)
{
BiTreeNode *a, *t;
if(curr == NULL) return NULL;

t = curr->leftChild;/*保存原curr所指结点的左子树指针*/
a = (BiTreeNode *)malloc(sizeof(BiTreeNode));
a->data = x;
a->leftChild = t;/*新插入结点的左子树为原curr的左子树*/
a->rightChild = NULL;

curr->leftChild = a;/*新结点成为curr的左子树*/
return curr->leftChild;/*返回新插入结点的指针*/
}

/*若当前结点curr非空，在curr的右子树插入元素值为x的新结点*/
/*原curr所指结点的右子树成为新插入结点的右子树*/
/*若插入成功返回新插入结点的指针，否则返回空指针*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
BiTreeNode *a, *t;

if(curr == NULL) return NULL;

t = curr->rightChild;/*保存原curr所指结点的右子树指针*/
a = (BiTreeNode *)malloc(sizeof(BiTreeNode));
a->data = x;
a->rightChild = t;/*新插入结点的右子树为原curr的右子树*/
a->leftChild = NULL;

curr->rightChild = a;/*新结点成为curr的右子树*/
return curr->rightChild;/*返回新插入结点的指针*/
}
void push(BiTreeNode *temp)
{
  s.shu[s.top++]=temp;
}
BiTreeNode *pop()
{
   return s.shu[--s.top];
}
int empey()
{
	return s.top ==0;
}
void PreOrder(BiTreeNode *t)
{
   BiTreeNode *temp = t;
   while(temp != NULL || s.top != 0)
   {
	   while(temp != NULL)
	   {
		   printf("%c ",temp->data);
		   push(temp);
		   temp = temp->leftChild;
	   }
	   if(s.top != 0)
	   {
		   temp = pop();
		   temp = temp->rightChild;
	   }
   }
   printf("\n");
}
void inorder(BiTreeNode *t)//中序遍历的非递归算法
{
	BiTreeNode *temp = t;
	while(temp != NULL||s.top != 0)
	{
		while(temp != NULL)//先把左孩子入栈，所有左孩子入栈结束
		{
			push(temp);
			temp = temp->leftChild;
		}
		if(s.top != 0)//左孩子入栈结束，取栈顶，输出栈顶元素，遍历右孩子
		{
			temp = pop();
			printf(" %c",temp->data);
			temp = temp->rightChild;
		}
	}
	printf("\n");
}
int main()
{
	BiTreeNode *root, *p, *pp;
	Initiate(&root);
    p = InsertLeftNode(root, 'A');
    p = InsertLeftNode(p, 'B');
    p = InsertLeftNode(p, 'D');
    p = InsertRightNode(p, 'G');
    p = InsertRightNode(root->leftChild, 'C');
    pp = p;
    InsertLeftNode(p, 'E');
    InsertRightNode(pp, 'F');
    printf("前序遍历\n");
    PreOrder(root->leftChild);
	printf("中序遍历:\n");
	inorder(root);
    return 0;
