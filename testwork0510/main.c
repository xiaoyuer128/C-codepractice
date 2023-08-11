#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define   MAX_LEN  10
#define   STU_NUM 30
int   Menu(void);
void  ReadScore(long num[], char name[][MAX_LEN], float score[], int n);
void AverSumofScore(float score[], int n);
void  SortbyScore(long num[], char name[][MAX_LEN], float score[], int n,
int (*compare)(float a, float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  SwapFloat(float *x, float *y);
void  SwapLong(long *x, long *y);
void  SwapChar(char x[], char y[]);
void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[], int n);
void  SortbyName(long num[], char name[][MAX_LEN], float score[], int n);
void  SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n);
void  SearchbyName(long num[], char name[][MAX_LEN], float score[], int n);
void  StatisticAnalysis(float score[], int n);
void  PrintScore(long num[], char name[][MAX_LEN], float score[], int n) ;
int main()
{
    int n,m;
    long num[STU_NUM];
    char name[STU_NUM][MAX_LEN];
    float score[STU_NUM];
    printf("Input student number(n<30):");
    scanf("%d",&n);
    while(1)
    {
        m=Menu();
        switch(m)
    {
    case 1:
        printf("Input student's ID, name and score:");
        ReadScore(num,name,score,n);
        break;
    case 2:
        AverSumofScore(score,n);
        break;
    case 3:
        printf("Sort in descending order by score:\n");
        SortbyScore(num,name,score,n,Descending);
        PrintScore(num,name,score,n);
    case 4:
        printf("Sort in descending order by score:\n");
        SortbyScore(num,name,score,n,Ascending);
        PrintScore(num,name,score,n);
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0:
    default:
        break;

    }

    }

    return 0;
}
//菜单
int   Menu(void)
{
    int i;
    printf("Management for Students' scores\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    printf("Please enter your choice:\n");
    scanf("%d",&i);
    return i;
}
//输入数据
void  ReadScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%ld%s%f",&num[i],name[i],&score[i]);
    }
}
//打印数据
void  PrintScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%ld\t%s\t%.0f\n",num[i],name[i],score[i]);
    }

}
//求成绩总数及其平均数
void AverSumofScore(float score[], int n)
{
    float sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        sum=sum+score[i];
    }
    printf("sum=%.0f,aver=%.2f\n",sum,sum/n);

}
//选择法排序数组
void  SortbyScore(long num[], char name[][MAX_LEN], float score[], int n,
int (*compare)(float a, float b))
{
    int i,j,k;
    for(i = 0;i<n-1;i++)
    {
        k = i;
        for(j=i+1;j<n;j++)
        {
            if((*compare)(score[j],score[k]))
            {
                k = j;
            }
        }
        if(k!=i)
        {
            SwapFloat(&score[k], &score[i]); /* 交换成绩 */
            SwapLong(&num[k], &num[i]);       /* 交换学号 */
            SwapChar(name[k], name[i]);       /* 交换姓名 */
        }
    }

}
//按升序排序
int   Ascending(float a, float b)
{
    return a<b;
}
//按降序排序
int   Descending(float a, float b)
{
    return a>b;
}
//交换两个浮点型类型
void  SwapFloat(float *x, float *y)
{
    float temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//交换两个长整型数
void  SwapLong(long *x, long *y)
{
    long temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
//交换两个字符数组
void  SwapChar(char x[], char y[])
{
    char temp[MAX_LEN];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[], int n)
{
    int i,j;
    long num2[STU_NUM];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(name[j], name[i]) < 0)
            {

            }
        }
    }
}
