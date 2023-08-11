
/*int main()
{
  float litres[] = { 11.5, 11.21, 12.7, 12.6, 12.4 } ;
  float miles[] = { 471.5, 358.72, 495.3, 453.6, 421.6 } ;
  int mpl[5] ;
  int *p;
  float *pl,*pm;
  pl=litres;
  pm=miles;
  for(p=mpl;p<mpl+(sizeof(mpl)/sizeof(int));p++)
  {
      *p=(int)(*pm / *pl);
      printf("%d\t",*p);
      pl++;
      pm++;
  }
return 0;
}
*/
/*int main()
{
    char c;
    printf("Enter a charactor:");
    c=getchar();
    if (c<0x20)
    printf("\nThe charactor is a control charactor.\n");
    else if(c>'0'&&c<'9')
        printf("\nThe charactor is a digit charactor.\n");
    else if(c>'A'&&c<'Z')
        printf("\nThe charactor is a capital charactor.\n");
    else if(c>'a'&&c<'z')
        printf("\nThe charactor is a lower charactor.\n");
    else
        printf("\nThe charactor is a other charactor.\n");
    return 0;
}
*/
/*
#include<stdalign.h>
#include<math.h>
int main()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        printf("%7d",i);
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%d",i);
        for(j=0;j<10;j++)
        {
            printf("%7.3f",sqrt(10*i+j));
        }
        printf("\n");
    }

    return 0;
}
*/
/*
#include<stdio.h>
int Gcd(int a, int b);
int main()
{
    int a,b,m;
    printf("Input a,b:\n");
    scanf("%d,%d",&a,&b);
    if(a<=0||b<=0)
        printf("Input error!\n");
    else
    {
        m=Gcd(a,b);
        printf("Gcd=%d\n",m);
    }
    return 0;
}
int Gcd(int a, int b)
{
    int m,d;
    if(a<b)
    {
    d=a;
    a=b;
    b=d;
    }
    do
    {
        m=a%b;
        a=b;
        b=m;
    }while(m!=0);
    return a;
}
*/
/*
#include<stdio.h>
M(int a);
int main()
{
    int m;
    printf("Enter number:");
    scanf("%d",&m);
    M(m);
    printf("\n");
    return 0;
}
M(int a)
{
    if(a>=0&&a<=9)
    {
        printf("%d",a);
    }
    else
    {
        printf("%d",a%10);
        M(a/10);
    }
}*/
/*
#include<stdio.h>
int main()
{
    int i=-1,j;
    int score[40];
    int Max;
    do
    {
        i++;
        printf("Input score:");
        scanf("%d",&score[i]);
    }while(score[i]>=0&&i<40);
    printf("Total students are %d\n",i);
    Max=score[0];
    for(j=0;j<i;j++)
    {

        if(Max<score[j])
        {
            Max=score[j];
        }

    }
    printf("The highest score is %d\n",Max);
    return 0;
}
*/
//写函数方法：
/*
#include<stdio.h>
#define N 40
int Readscore(int score[N]);
int Max(int score[N],int Max);
main()
{
    int score[N];
    int n,max;
    n=Readscore(score);
    printf("Total students are %d\n",n);
    max=Max(score,n);
    printf("The highest score is %d\n",max);
}
int Readscore(int score[N])
{
    int i=-1;
    do
    {
        i++;
        printf("Input score:");
        scanf("%d",&score[i]);
    }while(score[i]>0);
    return i;
}
int Max(int score[N],int n)
{
    int i=0,Max;
    Max=score[0];
    for(i;i<n;i++)
    {
        if(Max<score[i])
            Max=score[i];
    }
    return Max;
}
*/
/*
#include<stdio.h>
#include<string.h>
#define D 40
void Switch(char a[],char b[]);
int main()
{
    char a[D],b[D];
    printf("请输入一个字符串：");
    gets(a);
    Switch(a,b);
    printf("该字符串逆反后为%s！\n",b);
    return 0;
}
void Switch(char a[],char b[])
{
    int len,i,j;
    len = strlen(a);
    for(i=0,j=len-1;a[i]!='\0';i++,j--)
    {
        b[j]=a[i];
    }
    b[i]='\0';
}
*/
