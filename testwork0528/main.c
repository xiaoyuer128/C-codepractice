/*#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct date
{
    int year;
    int month;
    int day;
}DATE;//结构体年月日的定义。
typedef struct student
{
    long studentID;
    char name[10];
    char sex;
    DATE birthday;
    int score[4];
}STUDENT;
//结构体学生的定义。
void Input(int n,STUDENT stu[]);
int main()
{
    int i,j,n,sum[N];
    STUDENT stu[N];
    printf("please input student number:\n");
    scanf("%d",&n);
    Input(n,stu);
    Output(n,stu);
    return 0;
}

void Input(int n,STUDENT stu[])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("---------please input student%d's record:---------\n",i);
        printf("please input ID:");
        scanf("%ld",&stu[i].studentID);
        printf("please input name:");
        scanf("%s",&stu[i].name);
        printf("please input sex:");
        scanf(" %c",&stu[i].sex);
        printf("please input birthday(****,*,*):");
        scanf("%d,%d,%d",&stu[i].birthday.year,&stu[i].birthday.month,&stu[i].birthday.day);
        printf("please input score:");
        for(j=0;j<4;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}
void Output(int n,STUDENT stu[])
{
    int i,j,sum[N];
    for(i=0;i<n;i++)
    {
        sum[i]=0;
        for(j=0;j<4;j++)
        {
            sum[i]=sum[i]+stu[i].score[j];
        }
        printf("%10d%8s%3c%6d/%02d/%02d%4d%4d%4d%4d%6.1f\n",
               stu[i].studentID,
               stu[i].name,
               stu[i].sex,
               stu[i].birthday.year,
               stu[i].birthday.month,
               stu[i].birthday.day,
               stu[i].score[0],
               stu[i].score[1],
               stu[i].score[2],
               stu[i].score[3],
               sum[i]/4.0
               );
    }
}
*/


/*
#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char title[10];
    char author[20];
    struct Book *next;
};
void getInput(struct Book *book)
{
    printf("输入书名：");
    scanf("%s",book->title);
    printf("输入作者：");
    scanf("%s",book->author);

}
void addBook(struct Book **library)
{
    struct Book *book,*temp;
    book = (struct Book*)malloc(sizeof(struct Book));
    if(book==NULL)
    {
        printf("内存分配失败！");
        exit(1);
    }
    getInput(book);
    if(*library != NULL)
    {
        temp = *library;
        *library = book;
        book->next = temp;

    }
    else
    {
        *library = book;
        book->next = NULL;
    }
}
void Print(struct Book *library)
{
    struct Book *book;
    int count = 1;
    book = library;
    while(book != NULL)
    {
    printf("------Book%d------\n",count);
    printf("书名:%s\n",book->title);
    printf("作者:%s\n：",book->author);
    book = book->next;
    count++;
    }
}
void release(struct Book **library)
{
    struct Book *temp;
    while(*library != NULL)
    {
        temp = *library;
        *library = library.next;
        free(temp);

    }
}
int main(void)
{
    struct Book *library = NULL;
    int ch;
    while(1)
    {
        printf("请问是否需要录入书籍信息(Y/N)");
        do
        {
            ch = getchar();
        }while(ch !='Y'&&ch!='N');
        if(ch=='Y')
        {
            addBook(&library);
        }
        else
        {
            break;
        }
    }
    printf("请问是否需要打印图书信息(Y/N):");
    do
        {
            ch = getchar();
        }while(ch !='Y'&&ch!='N');
        if(ch=='Y')
        {
            Print(library);
        }
        release(&library);
    return 0;
}*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}Link;
Link *Appendnode(Link *head);
void Displaynode(Link *head);
void release(Link *head);
int main(void)
{
    int i=0;
    char c;
    Link *head = NULL;
    printf("Do you want to append a new node?(Y/N):");
    scanf("%c",&c);
    while(c=='Y'||c=='y')
    {
        head = Appendnode(head);
        Displaynode(head);
        printf("Do you want to append a new node?(Y/N):");
        scanf(" %c",&c);
        i++;
    }
    printf("%d new node have been appended.",i);
    release(head);

    return 0;
}

Link *Appendnode(Link *head)
{
    Link *p=NULL,*pr = head;
    int data;
    p = (Link *)malloc(sizeof(Link));
    if(p == NULL)
    {
        printf("no enough memory\n");
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
    printf("input node data:");
    scanf("%d",&data);
    p->data = data;
    p->next = NULL;
    return head;
}
void Displaynode(Link *head)
{
    Link *p = head;
    int j = 1;
    while(p != NULL)
    {
        printf("%5d%10d\n",j,p->data);
        p=p->next;
        j++;
    }
}
void release(Link *head)
{
    Link *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p=p->next;
        free(pr);
    }
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
typedef struct stu
{
	char ID[12];//学号
	char name[20];//姓名
	int c1;//语文成绩
	int c2;//数学成绩
	int c3;//英语成绩
	struct stu * next;
}STU;
STU *Append(STU *head);
void DisLink(STU *head);
void release(STU *head);
int main(void)
{
    int i,n;
    printf("1  增加数据\n");
    printf("2  退出\n");
    scanf("%d",&n);
    if(n==1)
    {

    }
    if(n==2)
    {

    }
    return 0;
}

STU *Append(STU *head)
{
    STU *p = NULL,*pr = head;
    p = (STU *)malloc(sizeof(STU));
    if(p == NULL)
    {
        printf("error!\n");
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
    printf("请输入学号：");
    scanf("%s",p->ID);
    printf("请输入名字：");
    scanf("%s",p->name);
    printf("请依次输入语文，数学，外语成绩：");
    scanf("%d%d%d",p->c1,p->c2,p->c3);
    p->next = NULL;
    return head;
}
void DisLink(STU *head)
{
    STU *p = head;

    while(p != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n",p->ID,p->name,p->c1,p->c2,p->c3,(p->c1+p->c2+p->c3));
        p=p->next;

    }
}
void release(STU *head)
{
    STU *p = head,*pr = NULL;
    while(p != NULL)
    {
        pr = p;
        p = p->next;
        free(pr);
    }
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

struct stu
{
    char ID[12];
    char name[20];
    int c1;
    int c2;
    int c3;
    struct stu * next;
}		  	   ;

struct stu * Append(struct stu *);//增加
struct stu * Start();//初始赋值
void DisLink(struct stu *);//显示
void Sort(struct stu *);//排序
void DeleteMemory(struct stu *);//释放



struct stu * Start( )
{
    struct stu * head = NULL;
    int flag = 1, a;

    while (flag)
    {
        printf("1  增加数据\n");//1
        printf("2  退出\n");//1
        printf("选择：");
        scanf(" %d", &a);//1
        switch (a)
        {
        case 1:
            head = Append(head);//1
            break;
        case 2:
            flag = 0;
            break;
        default:
            printf("请输入有效选择！\n");//1
        }
    }
    return head;
}
void DisLink( struct stu * head )
{
    struct stu * p = head;
    int j = 1;
    printf("序号\t学号\t名字 \t语文\t数学\t外语\t总分\n");
    while (p != NULL)//1
    {
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\n", j, p->ID, p->name, p->c1, p->c2, p->c3, p->c1 + p->c2 + p->c3);//1
        p = p->next;//1
        j++;
    }
}

struct stu * Append (struct stu * head)
{
    struct stu *p = NULL;
    struct stu *pr = head;
    p = (struct stu *)malloc(sizeof(struct stu));//1
    if (p == NULL)//1
    {
        printf("No enough memory to alloc");
        exit(0);
    }
    if (head == NULL)//1
    {
        head = p;//1
    }
    else
    {
        while (pr->next != NULL)//1
        {
            pr = pr->next;//1
        }
        pr->next = p;//1
    }
    pr = p;
    printf("请输入学号：");
    scanf(" %s", &pr->ID);//1
    printf("请输入名字：");
    scanf(" %s", &pr->name);//1
    printf("请依次输入语文，数学，外语成绩：");
    scanf(" %d%d%d", &pr->c1, &pr->c2, &pr->c3);//1
    pr->next = NULL;
    return head;
}

void Sort(struct stu * head)
{
    struct stu *pr = head, *p = head, temp1;
    int i = 1, j, k;
    while (p->next != NULL)//1
    {
        p = p->next;//1
        i++;
    }
    p = head;
    for (j = 1; j<i; j++)//1
    {
        p = p->next;//1
        for (k = 0; k<(i - j); k++)//1
        {
            if ((pr->c1 + pr->c2 + pr->c3) <(p->c1 + p->c2 + p->c3) )//1
            {
                temp1 = *pr;//1
                temp1.next = p->next;//1
                *pr = *p;//1
                *p = temp1;//1
                pr->next = p;//1
            }
            p = p->next;
            pr = pr->next;
        }
        p = head;
        pr = head;
    }
}

void DeleteMemory(struct stu * head)
{
    struct stu *p = head, *pr = NULL;
    while (p != NULL)//1
    {
        pr = p;//1
        p = p->next;//1
        free(pr);//1
    }
}

int main()
{
    struct stu * head = NULL;//1
    head = Start();
    DisLink(head);

    printf("排序后：\n");
    Sort(head);
    DisLink(head);

    DeleteMemory(head);

    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#define N 100
struct student{
    int ID;          //学生学号
    char name[20];     //学生姓名
    float score;          //考试成绩
    struct student * pNextNode;
};

int main(void)
{
    int i,n;
    struct student Stu[N];
    printf("请输入学生人数：\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个学生的ID、姓名和成绩:",i+1);
        scanf("%d %s %f",&Stu[i].ID,&Stu[i].name,&Stu[i].score);
    }
    printf("所有学生的成绩：\n");
    for(i=0;i<n;i++)
    {
        printf(" %-5d  %-8s  %-4.2f\n",Stu[i].ID,Stu[i].name,Stu[i].score);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++
        {
         if(Stu[i].score>Stu[j].score)

        }

    }

    return 0;
}
*/

//
//#include <stdio.h>
//#include <stdlib.h>
//#define N 6
//struct LNode
//{
//    int data;
//    struct LNode *next;
//}                        ;
//
//struct LNode* create_rear(int a[], int n);
//void output(struct LNode *h);
//
//int main(int argc, char *argv[])
//{
//    int a[N], i;
//    struct LNode* head;
//    /*②输入数组元素的值*/
//    printf("输入数组%d个元素的值。\n", N);
//    for (i = 0; i < N; i++)
//        scanf("%d", &a[i]);
//
//    /*③创建链表head,其结点的值依次为数组a元素的值*/
//    head = create_rear(a, N);
//    /*④输出链表head*/
//    printf("此链表各个结点的数据域为：");
//    output(head);
//
//    return 0;
//}
//
//struct LNode* create_rear(int a[], int n)
//{
//    /*新建一个链表h，每个结点依次插入到链尾，将链表的头指针返回 */
//    struct LNode *h = NULL;
//    struct LNode *s, *r; /*用s指向要插入结点，r指向链表的尾结点*/
//    int i;
//
//    for (i = 0; i < n; i++)
//    {
//        s = (struct LNode *)malloc(sizeof(struct LNode));
//        s->data = a[i];
//        s->next = NULL;
//        if (h == NULL)
//            h = s;       /*如果链表为空，则头指针h指向s */
//        else
//            r->next = s; /*否则将s链接到尾结点r之后     */
//        r = s;           /*将r指向尾结点               */
//    }
//    return h;  /*返回链表的头指针*/
//}
//
//void output(struct LNode *h)
//{
//    /*将链表h的各个结点的数据域依次输出，即遍历该链表*/
//    struct LNode *p = h;/*从第一个结点开始，用p依次指向各个结点*/
//    while (p)
//    {
//        /*只要p是一个非空结点，则输出其数据域，然后将p后移*/
//        printf("%d ", p->data);
//        p = p->next;  //将p后移
//    }
//
//
//}
