#include <stdio.h>
#include <stdlib.h>
typedef struct Link_list
{
    /* data */
    int data;
    struct Link_list *next;
}Data; /* ����һ�������������̽���ַΪnext */

/*��ӡ����*/
void print_list(Data *L)
{
	while (L)
	{
		printf("%d ",L->data);
		L = L -> next;
	}
	printf("\n");
}
/*β�巨��������*/
Data *insert_tail(Data *L, int n)
{
    L = (Data *)malloc(sizeof(Data));
    L->next = NULL;
    Data *r = L;
    int b;
    while(n--)
	{
        scanf("%d",&b);
        Data *p = (Data *)malloc(sizeof(Data));
        p->data = b;
        r->next = p;
        p->next = NULL;
        r = p;
    }
    return L;
}
/*�ϲ���������*/
Data *merge_list(Data *LA, Data *LB)
{
    Data p;
    p.data = 0;
    p.next = NULL;
    Data *result = &p;
    while (LA && LB)
	{
        if (LA->data < LB->data)
		{
            result->next = LA;
            LA = LA->next;
        }
		else if (LA->data > LB->data)
		{
            result->next = LB;
            LB = LB ->next;
        }
		else
		{
            result->next = LB;
            LB = LB ->next;
            LA = LA->next;
		}
        result = result -> next;
    }

    if (LA == NULL)
	{
        result ->next = LB;
    }

    if (LB == NULL)
	{
        result ->next = LA;
    }

    return p.next;
}

int main()
{
    Data *LA;
	Data *LB;
    printf("��һ������ \n");
    //β�巨����һ����ڵ������
    LA = insert_tail(LA,5);
    printf("�ڶ�������\n");
    //β�巨����һ�����ڵ������
    LB = insert_tail(LB,6);

    Data *result = merge_list(LA->next,LB->next);
    printf("�ϲ�������\n");
    print_list(result);
    return 0;
}

