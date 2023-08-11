/*#include <stdio.h>
#include <string.h>
void MyStrCat(char *dest, char *source);
main()
{
    char    first[80];
    char    second[80];

    printf("Input the first string:");
    gets(first);
    printf("Input the second string:");
    gets(second);
    MyStrCat(first, second);
    printf("The result is : %s\n", first);
}

void MyStrCat(char *dest, char *source)
{
    int i = 0, j = 0;

    while (*(dest+i)!='\0')
    {
        i++;
    }
    while (*(source+j)!='\0')
    {
        *(dest+i) = *(source+j);
        i++;
        j++;
    }
    *(dest+i) = '\0';
}


#include <stdio.h>
#include <string.h>
void MyStrCat(char *dest, char *source);
main()
{
    char    first[80];
    char    second[80];
    printf("Input the first string:");
    gets(first);
    printf("Input the second string:");
    gets(second);
    MyStrCat(first, second);
    printf("The result is : %s\n", first);
}

void MyStrCat(char *dest, char *source)
{
    int i = 0, j = 0;

    while (*(dest+i)!='\0')
    {
        i++;
    }
    for (; *(source+j)!='\0'; i++,j++)
    {
        *(dest+i) = *(source+j);

    }
    *(dest+i) = '\0';
}
*/
/*
#include<stdio.h>
int Gcd(int a,int b);
main()
{
    int a,b,n;
    printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    n=Gcd(a,b);
    if(n==-1)
        printf("Input error!\n");
    else
        printf("Gcd=%d\n",n);
}
int Gcd(int a,int b)
{
    int c;
    if(a<b)
        {c=b;
        b=a;
        a=c;
        }
    if(a<=0||b<=0)
        return -1;
    else
    {
        if(a==b)
            return a;
        else
        {
            a=a-b;
            Gcd(a,b);
        }
    }
}
*/
/*
#include<stdio.h>
int main()
{
    int a,b;
    char c;
    printf("Please enter an expression:");
    scanf("%d%c%d",&a,&c,&b);
    switch(c)
    {
    case '+':
        printf("%d + %d = %d \n",a,b,a+b);
        break;
    case '-':
        printf("%d - %d = %d \n",a,b,a-b);
        break;
    case '*':
        printf("%d * %d = %d \n",a,b,a*b);
        break;
    case '/':
    {
        if(b==0)
        {
            printf("Division by zero!\n");
            break;
        }

        else
        {
            printf("%d / %d = %d \n",a,b,a/b);
            break;
        }

    }
    default:
    {
        printf("Invalid operator! \n");
        break;
    }

    }
    return 0;
}
*/

//#include<stdio.h>
//int main()
//{
//    int num;
//    int sum=0;
//    while(num!=0)
//    {
//        printf("Input num:");
//        scanf("%d",&num);
//        sum=sum+num;
//        printf("sum = %d\n",sum);
//    }
//
//    return 0;
//}
/*
#include <stdio.h>
unsigned long  Fact(unsigned int  n);
int main()
{
    int m, k;
    double p;
    do
    {
        printf("Input m,k (m>=k>0):");
        scanf("%d,%d", &m, &k);
    }
    while (m < k || m < 0 || k < 0);
    p = (double)Fact(m) / (Fact(k) * Fact(m - k));
    printf("p = %.0f\n", p);
    return 0;
}
unsigned long  Fact(unsigned int  n)
{
    unsigned int  i;
    unsigned long result = 1;
    for (i = 2; i <= n; i++)
        result *= i;
    return result;
}


*/
