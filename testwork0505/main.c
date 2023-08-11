/*#include <stdio.h>
#include <stdlib.h>
int Length(char *c);
int main()
{
char c[50];
int n;
printf("Enter string:");
scanf("%s",c);
n=Length(c);
printf("string length=%d\n",n);
return 0;
}
int Length(char *c)
{
    int n = 0;
    while(*c != '\0')
    {
        c++;
        n++;
    }
    return n;
}
*/
/*
#include<stdio.h>
 struct S
    {
        int a;
        int b;
    };
int main()
{
    struct S za={3,4},zb={5,6},za1={10,20},zb1={30,40};;
    printf("(%d+%di)*(%d+%di)=",za.a,za.b,zb.a,zb.b);
    printf("(%d+%di)\n",(za.a*zb.a-za.b*zb.b),(za.b*zb.a+za.a*zb.b));
    printf("(%d+%di)*(%d+%di)=",za1.a,za1.b,zb1.a,zb1.b);
    printf("(%d+%di)\n",(za1.a*zb1.a-za1.b*zb1.b),(za1.b*zb1.a+za1.a*zb1.b));
    return 0;
}
*/
/*
#include<stdio.h>
#define N 100
int main()
{
    int n=100;
    int i=0,j=0;
    int g,s,b,Armstrong[N];
    do
    {
        g=n%10;
        b=n/100;
        s=(n-100*b)/10;
        if(n==g*g*g+s*s*s+b*b*b)
        {
             Armstrong[i]=n;
             i++;
             n++;
        }
        else
        {
            n++;
        }

    }while(n<1000);
    printf("There are following Armstrong number smaller than 1000:\n");
    printf(" ");
    for(j;j<i;j++)
    {
        printf("%d\t",Armstrong[j]);
    }
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int a[3][2];
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<2;j++)
        {
            a[i][j]=i+j;
        }
    }
    for(i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
        {
           printf("%4d",a[i][j]);
        }
    }
    return 0;
}
*/
/*
#include<stdio.h>
#define N 100
char Max(char a[]);
int main()
{
    char Str[N];
    char s;
    printf("Input a string:");
    printf("\n");
    gets(Str);
    s=Max(Str);
    printf("The largest character of \"%s\" is \'%c\' ,The ASCII is %d.",Str,s,s);
    return 0;
}
char Max(char a[])
{
    int i=0;
    char m=a[0];
    while(a[i]!='\0')
    {
        if(a[i]>m)
            m=a[i];
        i++;
    }
    return m;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char a[100];
    char *p;
    int i;
    p=a;
    printf("请输入你的姓名：");
    gets(a);
    for(i=strlen(a);i>0;i--)
    {
        *(p+2*i)=*(p+i);
        *(p+2*i-1)=' ';
    }
    puts(a);

}
*//*
#include <stdio.h>

int main()
{
    char name[100];
    char *p = name;

    printf("请输入你的姓名：");
    scanf("%s", name);

    while (*p != '\0')
    {
        putchar(*p);
        putchar(' ');
        p++;
    }

    return 0;
}
*/
