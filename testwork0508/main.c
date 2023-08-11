//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#define N 150
//#define Max_length 10
//void Sorted(char str[N][Max_length],int n);
//int main()
//{
//    int n,i;
//    char a[N][Max_length];
//    printf("How many countries?");
//    scanf("%d",&n);
//    getchar();
//    printf("Input their names:\n");
//    for(i=0;i<n;i++)
//    {
//        gets(a[i]);
//    }
//    Sorted(a,n);
//    printf("Sorted results:\n");
//    for(i=0;i<n;i++)
//    {
//        puts(a[i]);
//    }
//    return 0;
//}
//void Sorted(char str[N][Max_length],int n)
//    {
//        int i,j;
//        char temp[Max_length];
//        for(i=0;i<n-1;i++)
//        {
//         for(j=i;j<n;j++)
//         {
//             if(strcmp(str[i],str[j])>0)
//             {
//                 strcpy(temp,str[i]);
//                 strcpy(str[i],str[j]);
//                 strcpy(str[j],temp);
//             }
//         }
//        }
//    }

//#include <stdio.h>
//#include <string.h>
//#define ARR_SIZE 80
//int main()
//{
//    char str[ARR_SIZE];
//    int  len,i;
//    int  letter=0,digit=0,space=0,other=0;
//
//    printf("请输入一个字符串:");
//    gets(str);
//    len = strlen(str);
//    for (i=0; i<len; i++)
//    {
//        if (('a'<=str[i]&&str[i]<='z')||('A'<=str[i]&&str[i]<='Z'))
//        {
//            letter ++;
//        }
//        else if ('0'<=str[i]&&str[i]<='9')
//        {
//            digit ++;
//        }
//        else if (str[i]==' ')
//        {
//            space ++;
//        }
//        else
//            other ++;
//    }
//
//    printf("英文字符数:%d\n", letter);
//    printf("数字字符数:%d\n", digit);
//    printf("空格数:%d\n", space);
//    printf("其他字符数:%d\n", other);
//    return 0;
//}


//#include<stdio.h>
//#define N 100
//void SentenceEncoding(char *soure,char *code);
//char CharEncoding(char ch);
//int main()
//{
//    char strs[N],strc[N];
//    printf("Input source sentence:");
//    gets(strs);
//    SentenceEncoding(strs,strc);
//    printf("Encoded sentence:");
//    puts(strc);
//    return 0;
//}
//
//char CharEncoding(char ch)
//{
//    char encode  = 0;
//    if(ch>='A' && ch<='Z')
//    {
//        encode  = ('A'+'Z')- ch;
//    }
//    else if(ch>='a' && ch<= 'z' )
//    {
//        encode  = 'a'+'z'-ch;
//    }
//    else
//    {
//        switch(ch)
//        {
//        case ' ':
//            encode = '@';
//            break;
//        case '.':
//            encode = '#';
//            break;
//        default:
//            encode = '.';
//            break;
//        }
//    }
//    return encode;
//}
//void SentenceEncoding(char *soure,char *code)
//{
//    while(*soure!='\0')
//    {
//        *code=CharEncoding(*(soure));
//        soure++;
//        code++;
//    }
//    *code='\0';
//
//}
/*
#include<stdio.h>
#define N 100
void Delete(char *str, char *str1, char c);
int main()
{
    char Str[N];
    char Str1[N];
    char n;
    printf("Input a string:");
    gets(Str);
    printf("Input a character:");
    scanf("%c", &n);
    Delete(Str, Str1, n);
    printf("Results:\n");
    puts(Str1);
    return 0;
}
void Delete(char *str, char *str1, char c)
{
    while (*str != '\0')
    {
        if (*str != c)
        {
            *str1 = *str;
            str++;
            str1++;
        }
        else
        {
            str++;
        }
    }
    *str1 = '\0';
}
*/
#include<stdio.h>
int main()
{
    int n;
    printf("****TIME****\n");
    printf("1.morning\n");
    printf("2.afternoon\n");
    printf("3.night\n");
    printf("Enter your choice");
    scanf("%d",&n);
    if(n==1)
    printf("Good morning");
    else if(n==2)
    printf("Good afternoon");
    else if("n==3")
    printf("Good night");
    else
    printf("Selection wrong");

    return 0;
}
