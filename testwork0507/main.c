//#include <stdio.h>
//#include <stdlib.h>
//int Gcd(int a,int b);
//int main()
//{
//    int a,b,m;
//    printf("Input a,b:");
//    scanf("%d,%d",&a,&b);
//    m=Gcd(a,b);
//    if(m==-1)
//    {
//        printf("Input number should be positive!\n");
//    }
//    else
//    {
//        printf("Greatest Common Divisor of %d and %d is %d\n",a,b,m);
//    }
//    return 0;
//}
//int Gcd(int a,int b)
//{
//    int m;
//    if(a<b)
//    {
//        m=a;
//        a=b;
//        b=m;
//    }
//    if(a<=0||b<=0)
//    {
//        return -1;
//    }
//    else if(a==b)
//    {
//        return a;
//    }
//    else
//    {
//        Gcd(a-b,b);
//    }
//
//}

//
//#include<stdio.h>
//#define N 10
//int main()
//{
//    int a[N], i;
//    int max, min, m, n;
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//    max = a[0];
//    min = a[0];
//    for (i = 0; i < N; i++)
//    {
//        if (max <= a[i])
//        {
//            max = a[i];
//            m = i;
//        }
//
//    }
//    for (i = 0; i < N; i++)
//    {
//        if (min >= a[i])
//        {
//            min = a[i];
//            n = i;
//        }
//
//    }
//    printf("max=%d, pos=%d\n", max, m);
//    printf("min=%d, pos=%d\n", min, n);
//    return 0;
//}

//#include  <stdio.h>
//#define N 10
//void ReadData(int a[], int n);
//void PrintData(int a[], int n);
//void Swap(int *x, int *y);
//int main()
//{
//    int  a[N], b[N], i, n;
//    printf("Input array size(n<=10):");
//    scanf("%d", &n);
//    printf("Input array a:");
//    ReadData(a, n);
//    printf("Input array b:");
//    ReadData(b, n);
//    for(i=0;i<n;i++)
//    {
//        Swap(&a[i],&b[i]);
//    }
//    printf("Output array a:");
//    PrintData(a, n);
//    printf("Output array b:");
//    PrintData(b, n);
//    return 0;
//}
//void ReadData(int a[], int n)
//{
//    int i;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &a[i]);
//    }
//}
//void PrintData(int a[], int n)
//{
//    int i;
//    for (i = 0; i < n; i++)
//    {
//        printf("%5d", a[i]);
//    }
//    printf("\n");
//}
///* 函数功能：两整数值互换 */
//void  Swap(int *x, int *y)
//{
//    int  temp;
//    temp=*x;
//    *x=*y;
//    *y=temp;
//}
//#include <stdio.h>
//#include <string.h>
//#define WEEKDAYS 7
//#define MAX_STR_LEN 10
//int main()
//{
//    int i, pos;
//    int findFlag = 0;
//    char x[MAX_STR_LEN];
//    char weekDay[][MAX_STR_LEN] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//
//    printf("Please enter a string:\n");
//    scanf("%s", x);
//
//    for (i = 0; i < WEEKDAYS && !findFlag; i++)
//    {
//        if (strcmp(x, weekDay[i]) == 0)
//        {
//            pos = i;
//            findFlag = 1;
//        }
//    }
//
//    if (findFlag)
//    {
//        printf("%s is %d\n", x, pos);
//    }
//    else
//    {
//        printf("Not found!\n");
//    }
//    return 0;
//}
/*
#include<stdio.h>
#define N 50
void MyStrcat(char *desStr,char *srcStr);
int main()
{
    char a[N],b[N];
    printf("Input a string:");
    gets(a);
    printf("Input another string:");
    gets(b);
    MyStrcat(a,b);
    printf("Concatenate results:%s\n",a);
    return 0;
}
void MyStrcat(char *desStr,char *srcStr)
{
    while(*desStr!='\0')
    {
        desStr++;
    }
    while(*srcStr!='\0')
    {
        *desStr=*srcStr;
        srcStr++;
        desStr++;
    }
    *desStr='\0';
}
*/
/*
#include<stdio.h>
#define N 50
void Transpose(int (*a)[N], int n);
void Swap(int *x, int *y);
void InputMatrix(int (*a)[N], int n);
void PrintMatrix(int (*a)[N], int n);
main()
{
    int n,a[N][N];
    printf("Input n:");
    scanf("%d",&n);
    InputMatrix(a,n);
    Transpose(a,n);
    printf("The transposed matrix is:\n");
    PrintMatrix(a,n);

}
void Transpose(int (*a)[N], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            Swap(*(a+i)+j,*(a+j)+i);

        }
    }
}
void  Swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void InputMatrix(int (*a)[N], int n)
{
    int i,j;
    printf("Input %d*%d matrix:\n",n,n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
}
void PrintMatrix(int (*a)[N], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t",*(*(a+i)+j));

        }
        printf("\n");
    }
}*/
/*
#include<stdio.h>
#include<string.h>
#define N 150
#define MAX_len 10
void ReadCountries(char str[N][MAX_len];int n);
void Sorted(char str[N];int n);
void Print(char str[N];int n);
int main()
{
    int n,a[N][MAX_len];
    printf("How many countries?");
    scanf("%d",&n);
    getchar();
    ReadCountries(a,n);
    Sorted(a,n);
    printf("Sorted results:\n");
    Print(a,n);
    return 0;
}
void ReadCountries(char str[N];int n)
{
    int i;
    printf("Input their names:\n");
    for(i=0;i<n;i++)
    {
        gets(str[i]);
    }
}
void Sorted(char str[N];int n)
{
    int i,j;
    char temp[10];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(str[i],str[j])>0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }

    }
}
void Print(char str[N];int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%s\n",str[i]);
    }
}
*/
