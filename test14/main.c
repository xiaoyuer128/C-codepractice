/*#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int Lcm(int a, int b);*/
/*void main()
{
    int year=2018,month=3,days=0;
    switch(month)
    {
    case 3:
        days+=31;
        break;
    case 2:
        days+=((year%4==0&&year%100!=0||year%400==0)?29:28);
        break;
    case 1:
        days+=31;
        break;
    default:
        break;

    }
    printf("%d\n",days);
}
*/
/*int main()
{
    int n,k=0;
    scanf("%d",&n);
    while(n!=0)
    {
        k++;
        n/=10;
    }
    printf("%d\n",k);

    return 0;
}
*//*
void main()
{
    int a,b,c;
    for(a=1;a<=4;a++)
    {
        for(b=3;b>=a-1;b--)
            printf(" ");
        for(c=1;c<=2*a-1;c++)
            printf("*");
        printf("\n");

    }
    for(a=3;a>=1;a--)
    {
        for(b=a-1;b<=3;b++)
        {
            printf(" ");

        }
        for(c=2*a-1;c>=1;c--)
        {
            printf("*");
        }
        printf("\n");

    }

}
*/
/*void main()
{
    int n,i,k=2;
    printf("imput a number:");
    scanf("%d",&n);
    if(n==2)
        printf("%d=2",n);
    else{
            printf("%d=",n);
        do
    {
        if(n%k==0)
        {
            printf("%d*",k);
            n=n/k;
        }
        else
        {
            k=k+1;
        }
    }while(n!=2);

    }
}
*//*
#include <stdio.h>
int main(){
	int i,n;
	scanf("%d",&n);
	printf("%d=",n);
	for(i=2;i<=n;i++){
			while(n!=i){
				if(n%i==0){
					printf("%d*",i);
					n=n/i;
				}else{
					break;
				}
			}
	}
	printf("%d",n);
	return 0;
}

*/
/*
int main()//主函数
{
   int m, n, num1, num2, temp;//定义整型变量
   printf("请输入两个数：");//提示语句
   scanf("%d %d", &num1, &num2);//键盘输入两个数
   m=num1; //赋值
   n=num2; //赋值
   while(num2!=0) // 余数不为0，继续相除，直到余数为0
   {
       temp=num1%num2;
       num1=num2;
       num2=temp;
   }
   printf("最大公约数是：%d\n", num1);//输出最大公约数
   printf("最小公倍数是：%d\n", m*n/num1);//输出最小公倍数
}


*/
/*
int main()
{
int n,i,k;
printf("Input n:\n");
scanf("%d",&n);
for(i=1;i<=n;i++){
    printf("%4d",i);
}
printf("\n");
for(i=1;i<=n;i++){
    printf("   -");
}
printf("\n");
for(i=1;i<=n;i++){
    for(k=i;k<=n;k++)
    {
        printf("%4d",i*k);
    }
    printf("\n");
}
return 0;
}
*/
/*
int main()
{
    int i,n,sum=1;
    printf("Input days:\n");
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
    {
    sum=(sum+1)*2;
    }
    printf("x=%d\n",sum);
    return 0;
}
*/

/*
int main()
{
    int a,b,c;
    printf("Input a,b:");
    scanf("%d,%d",&a,&b);
    c=Lcm(a,b);
    if(c==-1)
    printf("Input error!\n");
    else
    printf("Least Common Multiple of %d and %d is %d\n" ,a,b,c);
    return 0;
}
int Lcm(int a, int b)
{
    int temp,x,y,c;
    if(a<=0||b<=0)
    return -1;
    else{
        x=a>b?a:b;
        y=a+b-x;
        while(x!=0)
        {
            temp=y%x;
            y=x;
            x=temp;
        }
        c=a*b/y;
        return c;
    }
}


*//*
void reverse(char s[])
{
    int len;
    len = strlen(s);
    if (len == 1)
    {
        printf("%c", s[0]);
    }
    else
    {
        reverse(s + 1);
        printf("%c", s[0]);
    }
}

int main()
{
    char s[100];
    printf("input your string:\n");
    scanf("%s", s);
    reverse(s);
}
*/
/*
#include<stdio.h>
#define N 128
int GetAboveAver(int score[], int n);
int main()
{
    int i,n,count=0,score[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&score[i]);
        if(score[i]<0)
        count++;
    }
    n=GetAboveAver(score[count],count);
    printf("Students of above average is %d\n",n);
    return 0;
}
int GetAboveAver(int score[], int n)
{
    int i,sum=0,aver,count=0;
    for(i=0;i<n;i++)
    {
        sum=sum+score[i];
    }
    aver=sum/n;
    for(i=0;i<n;i++)
    {
        if(score[i]<aver)
        count++;
    }
    return count;
}
*/
/*
#include <stdio.h>
#define N 40
int Average(int score[], int n);
int ReadScore(int score[]);
int GetAboveAver(int score[], int n);
main() {
    int score[N], m, n;
    n = ReadScore(score);//1
    printf("Total students are %d\n", n);//1
    m = GetAboveAver(score, n);//1
    printf("Students of above average is %d\n", m);//1
}
int Average(int score[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++)//1
    {
        sum += score[i];//1
    }
    return sum / n;//1
}
int ReadScore(int score[]) {
    int i = -1;
    do {
        i++;
        scanf("%d", &score[i]);//1
    } while (score[i] >= 0);//e2
    return i;//1
}
int GetAboveAver(int score[], int n) {
    int i, count = 0, aver;
    aver = Average(score, n);//1
    printf("Average score is %d\n", aver);//1
    for (i = 0; i < n; i++)//1
    {
        if (score[i] >= aver) //1
            count++;//1
    }
    return count;//1
}
*/

/*
#include<stdio.h>
#define N 10
int Search(int a[], int n, int x);
void main()
{
    int i,x,m,arr[N];
    printf("Input 10 numbers:\n");
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Input x:\n");
    scanf("%d",&x);
    m=Search(arr,N,x);
    if(m==-1)
    printf("Not found!\n");
    else
    printf("Subscript of x is %d\n",m);

}

int Search(int a[], int n, int x)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==x)
        {
           return i;
        }
    } return -1;
}
*/

#include<stdio.h>
#define N 10
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];

    return 0;
}
