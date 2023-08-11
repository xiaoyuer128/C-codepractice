/*#include <stdio.h>
#include <stdlib.h>
typedef struct goods
{
    int num;            //��Ʒ���
    char type[20];       //��Ʒ����
    char name[20];       //��Ʒ����
    int  counts;         //��Ʒ����
    struct goods *next;
} GOODS;
GOODS *create(GOODS *head);
void show(GOODS *head);
GOODS *deletenode(GOODS *head,int n);
void release(GOODS *head);
int main()
{
    int m;
    char c;
    struct goods *head = NULL;
    do
    {
        head = create(head);
        printf("�Ƿ��������,��Y���������룬�������ͽ���.\n");
        scanf(" %c",&c);
    }
    while(c=='Y');
    show(head);
    printf("������Ҫɾ������Ʒ��ţ�\n");
    scanf("%d",&m);
    deletenode(head,m);
    release(head);
    return 0;
}
GOODS *create(struct goods *head)
{
    GOODS *p = NULL,*pr = head;
    p =(GOODS *)malloc(sizeof(GOODS));
    if(p == NULL)
    {
        printf("not exit!");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next = p;
    }
    printf("����������ÿ����Ʒ��š����͡����ơ�������\n");
    scanf("%d %s %s %d",&p->num,&p->type,&p->name,&p->counts);
    p->next=NULL;
    return head;
}
void show(GOODS *head)
{
    GOODS *p = head;
    int j = 1;
    printf("���������Ʒ��ϢΪ����� ���� ���� ����:\n");
    while(p != NULL)
    {
        printf("%d %s %s %d\n",p->num,p->type,p->name,p->counts);
        p = p->next;
        j++;
    }
}
GOODS *deletenode(GOODS *head,int n)
{
    GOODS *p = head,*pr = head;
    if(head == NULL)
    {
        printf("empty link");
        return(head);
    }
    while(n != p->num && p->next != NULL)
    {
        pr = p;
        p = p->next;
    }
    if(n == p->num)
    {
        if(p == head)
        {
            head = p->next;
        }
        else
        {
            pr->next = p->next;
        }
        printf("��Ʒɾ���ɹ���\n");
        show(head);
        free(p);
    }
    else
    {
        printf("�����ڣ�");
    }
    return head;
}
void release(GOODS *head)
{
    GOODS *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}*/
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct grade {
	int score;
	char ID[6];
	struct grade *next;
}GREAD;
GREAD *creat(GREAD *head);
void show(GREAD *head);


int main(void)
{
    GREAD *head = NULL;
    int i;
    printf("����ѧ���ɼ���ID��\n");
    while(head->score>0)
    {
        creat(head);
    }
    printf("����������\n");
    show(head);
    printf("������Ҫ������ĳɼ���ID:");


    return 0;
}
GREAD *creat(GREAD *head)
{
    GREAD *p = NULL,*pr = head;
    p=(GREAD *)malloc(sizeof(GREAD));
    if(p == NULL)
    {
        printf("not memory!");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr = pr->next;
        }
        pr->next = p;
    }
    scanf("%d,%s",&p->score,&p->ID);
    p->next = NULL;
    return head;
}
void show(GREAD *head)
{
    GREAD *p = head;
    int j = 1;
    while(p != NULL)
    {
        printf("%d,%s\n",p->score,p->ID);
        p= p->next;
        j++;
    }

}
GREAD *insertnode(GREAD *head,int n)
{
    int j;
    GREAD *p = head,*pr = head,*temp = NULL;
    p=(GREAD*)malloc(sizeof(GREAD));
    if(p == NULL)
    {
        printf("no memory!");
        exit(0);
    }
    p->next = NULL;
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(j<n&&p->next!=NULL)
        {
            temp = pr;
            pr = pr->next;
            j++
        }
        if(p==NULL)
        {
            printf("no insertnode");
            return head;
        }

    }
}
NODE *insert(GREAD *head, GREAD *pnew, int i) //2
{
	NODE *p; //1
	int j;

	p = head;
	for (j = 0; j<i&&p != NULL; j++)//1
		p = p->next;//1

	if (p == NULL)//1
	{
		printf("����Ľڵ㲻���ڣ�");
		return head; //1
	}

	pnew->next = p->next;//1
	p->next = pnew; //1
	return head; //1
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct stu{
    char name[20];
    in num;
    int score;
    struct stu *next;
}STU;



int main(void)
{
    STU *head = NULL;
    int n;
    char c;
    do
    {
        head = create(head);
        printf("�Ƿ��������,��Y���������룬�������ͽ���.\n");
        scanf(" %c",&c);
    }while(c=='Y');
    printf("������Ҫ����ѧ����ѧ�ţ�\n");
    scanf("%d",&n);
    Find(head);
    release(head);
    return 0;
}
STU *create(STU *head)
{
    STU *p = NULL,*pr = head;
    p =(STU *)malloc(sizeof(STU));
    if(p == NULL)
    {
        printf("not exit!");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next = p;
    }
    printf("������ѧ��������ѧ�ţ��ɼ��� \n");
    scanf("%s %d %d",p->name,p->num,p->score);
    p->next=NULL;
    return head;
}
void release(GOODS *head)
{
    GOODS *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
void Find(STU *head,int n)
{
    STU *p=head;
    while(p->num != n)
    {
        p = p->next;
    }
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct goods
{
    int num;           //��Ʒ���
    char type[20];       //��Ʒ����
    char name[20];       //��Ʒ����
    int  counts;         //��Ʒ����
    struct goods *next;
} GOODS;
GOODS *create(GOODS *head);
void show(GOODS *head);
void release(GOODS *head);
GOODS *sel(GOODS *head);
int main(void)
{
    GOODS *head = NULL;
    char c;
    do
    {
        head = create(head);
        printf("�Ƿ��������,��Y���������룬�������ͽ���.\n");
        scanf(" %c",&c);
    }
    while(c=='Y');
    show(head);
    sel(head);
    release(head);
    return 0;
}
GOODS *create(GOODS *head)
{
    GOODS *p = NULL,*pr = head;
    p =(GOODS *)malloc(sizeof(GOODS));
    if(p == NULL)
    {
        printf("not exit!");
        exit(0);
    }
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        while(pr->next!=NULL)
        {
            pr=pr->next;
        }
        pr->next = p;
    }
    printf("����������ÿ����Ʒ��š����͡����ơ�������\n");
    scanf("%d %s %s %d",&p->num,&p->type,&p->name,&p->counts);
    p->next=NULL;
    return head;
}
void show(GOODS *head)
{
    GOODS *p = head;
    int j = 1;
    printf("���������Ʒ��ϢΪ����� ���� ���� ����:\n");
    while(p != NULL)
    {
        printf("%d %s %s %d\n",p->num,p->type,p->name,p->counts);
        p = p->next;
        j++;
    }
}
void release(GOODS *head)
{
    GOODS *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
GOODS *sel(GOODS *head) //2
{
    GOODS *p;//1
    int n;
    int flag = 0;
    p = head->next;
    printf("������Ҫ�޸���Ʒ�ı�ţ�\n");
    scanf("%d",&n);
    while(p)//1
    {
        if(p->num ==n)//1
        {
            flag = 1;//1
            printf("�������������Ʒ������ ��\n");
            scanf("%d",&p->counts);
            break;
        }
        p=p->next;//1
    }
    if(flag)//1
    {
        show(head);
    }
    else//1
    {
        printf("�޸�ʧ��.\n");
        printf("����в����ڸ���Ʒ.\n");
    }
    return head;
}*/
/*
#include <stdio.h>
main()
{
    int fahr;
    float celsius;
    for (fahr = -40; fahr <= 110; fahr = fahr + 10)
    {
        celsius = 5.0 / 9 * (fahr - 32);
        printf("%4d\t%6.1f\n", fahr, celsius);
    }
}
*/
/*
#include <stdio.h>
int Coconut(int n);
int main()
{
    printf("y = %d\n", Coconut(5));
    return 0;
}
int Coconut(int n)
{
    int   i = 1;
    float x = 1, y;
    y = n * x + 1;
    do
    {
        y = y * n / (n - 1) + 1;
        i++;
        if (y != (int)y)
        {
            x = x + 1;
            y = n * x + 1;
            i = 1;
        }
    }
    while (i < n);
    return (int)y;
}
*/

#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main()
{
    int  m, n;
    long sum = 0;
    printf("Input m,k (m>=k>0)");
    scanf("%d,%d", &m,&n);
    while(m<n)
    {
        printf("Input m,k (m>=k>0)");
        scanf("%d,%d", &m,&n);
    }
    sum = Fact(m)/(Fact(n)*Fact(m-n));
    printf("The combination is %ld\n", sum);
    return 0;
}
/* �������ܣ��õ����������޷������ͱ���n�Ľ׳� */
unsigned long  Fact(unsigned int  n)
{
    unsigned int  i;
    unsigned long result = 1;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}
