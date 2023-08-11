#include <stdlib.h>
#include <stdio.h>
#define NULL 0
#define M 100
typedef char DataType;
typedef struct Node
{
DataType data;/*������*/
struct Node *leftChild;/*������ָ��*/
struct Node *rightChild;/*������ָ��*/
}BiTreeNode;/*���Ľṹ�嶨��*/
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

t = curr->leftChild;/*����ԭcurr��ָ����������ָ��*/
a = (BiTreeNode *)malloc(sizeof(BiTreeNode));
a->data = x;
a->leftChild = t;/*�²������������Ϊԭcurr��������*/
a->rightChild = NULL;

curr->leftChild = a;/*�½���Ϊcurr��������*/
return curr->leftChild;/*�����²������ָ��*/
}

/*����ǰ���curr�ǿգ���curr������������Ԫ��ֵΪx���½��*/
/*ԭcurr��ָ������������Ϊ�²������������*/
/*������ɹ������²������ָ�룬���򷵻ؿ�ָ��*/
BiTreeNode *InsertRightNode(BiTreeNode *curr, DataType x)
{
BiTreeNode *a, *t;

if(curr == NULL) return NULL;

t = curr->rightChild;/*����ԭcurr��ָ����������ָ��*/
a = (BiTreeNode *)malloc(sizeof(BiTreeNode));
a->data = x;
a->rightChild = t;/*�²������������Ϊԭcurr��������*/
a->leftChild = NULL;

curr->rightChild = a;/*�½���Ϊcurr��������*/
return curr->rightChild;/*�����²������ָ��*/
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
void inorder(BiTreeNode *t)//��������ķǵݹ��㷨
{
	BiTreeNode *temp = t;
	while(temp != NULL||s.top != 0)
	{
		while(temp != NULL)//�Ȱ�������ջ������������ջ����
		{
			push(temp);
			temp = temp->leftChild;
		}
		if(s.top != 0)//������ջ������ȡջ�������ջ��Ԫ�أ������Һ���
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
    printf("ǰ�����\n");
    PreOrder(root->leftChild);
	printf("�������:\n");
	inorder(root);
    return 0;
