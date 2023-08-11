#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0
#define OPSETSIZE 8
typedef int Status;
typedef struct StackChar
{
   char c;
   struct StackChar *next;
}StackChar;
typedef struct StackFloat
{
    float f;
    struct StackFloat *next;
}SF;
StackChar *Push(StackChar *s,char c)
{
    StackChar *p=(StackChar*)malloc(sizeof(StackChar));
    p->c=c;
    p->next=s;
    return p;
}
SF *Push(SF *s,float f)
{
    SF *p=(SF*)malloc(sizeof(SF));
    p->f=f;
   p->next=s;
   return p;
}
StackChar *Pop(StackChar *s)
{
   StackChar *q=s;
   s=s->next;
   free(q);
   return s;
}
SF *Pop(SF *s)
{
   SF *q=s;
   s=s->next;
   free(q);
   return s;
}
float Operate(float a,unsigned char theta, float b)      //计算函数Operate
{
    switch(theta)
{
          case '+': return a+b;
          case '-': return a-b;
          case '*': return a*b;
          case '/': return a/b;
          case '^': return pow(a,b);
          default : return 0;
 }
}
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#','^'};
Status In(char Tet,char *TetOp)
{
    int Find=false;
    for (int i=0; i< OPSETSIZE; i++)
 {
            if(Tet == TetOp[i])
            Find= true;
        }
    return Find;
}
Status ReturnOpOrd(char op,char *TetOp)
{
    for(int i=0; i< OPSETSIZE; i++)
      {
          if (op == TetOp[i])
          return i;
       }
}
int getIndex(unsigned char theta)   //获取theta所对应的索引
{
	    int index = 0;
	    switch (theta)
	    {
       case '+':
	        index = 0;
	        break;
	    case '-':
	        index = 1;
	        break;
	    case '*':
	        index = 2;
	        break;
	    case '/':
	        index = 3;
	        break;
	    case '(':
	        index = 4;
	        break;
	    case ')':
	        index = 5;
            break;
	    case '#':
	        index = 6;
	    default:break;
	    }
	    return index;
	}

char precede(char theta1, char theta2)   //获取theta1与theta2之间的优先级
{
	    const char priority[][7] =     //算符间的优先级关系
	    {
	        { '>','>','<','<','<','>','>' },
	        { '>','>','<','<','<','>','>' },
	        { '>','>','>','>','<','>','>' },
			 { '>','>','>','>','<','>','>' },
			 { '<','<','<','<','<','=','0' },
			 { '>','>','>','>','0','>','>' },
			 { '<','<','<','<','<','0','=' },
		 };

        int index1 = getIndex(theta1);
        int index2 = getIndex(theta2);
        return priority[index1][index2];
}
float EvaluateExpression(char* MyExpression)
{
       // 算术表达式求值的算符优先算法
 // 设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合
       StackChar *opter=NULL;       // 运算符栈，字符元素
 SF *opnd=NULL;               // 运算数栈，实数元素
       char TempData[20];
       float Data,a,b;
       char theta,*c,Dr[]={'#','\0'};
       opter=Push(opter,'#');
       c=strcat(MyExpression,Dr);
       strcpy(TempData,"\0");
       while (*c!= '#' || opter->c!='#')
          {
              if (!In(*c, OPSET))
                {
                    Dr[0]=*c;
                    strcat(TempData,Dr);
                    c++;
                    if (In(*c, OPSET))
                       {
                           Data=atof(TempData);
                           opnd=Push(opnd, Data);
                           strcpy(TempData,"\0");
                        }
                 }
               else    // 不是运算符则进栈
                 {
                     switch (precede(opter->c, *c))
                        {
                            case '<': // 栈顶元素优先级低
                            opter=Push(opter, *c);
    c++;
                            break;
    case '=': // 脱括号并接收下一字符
                            opter=Pop(opter);
                            c++;
                            break;
                            case '>': // 退栈并将运算结果入栈
                            theta=opter->c;opter=Pop(opter);
    b=opnd->f;opnd=Pop(opnd);
                            a=opnd->f;opnd=Pop(opnd);
                            opnd=Push(opnd, Operate(a, theta, b));
                            break;
                        } //switch
                   } //else
 } //while
  return opnd->f;
} //EvaluateExpression
int main()//主函数
{
      char s[128];
      printf("输入表达式为:");
      gets(s);
  printf("该表达式的值为:\n");
      printf("%s\b=%g\n",s,EvaluateExpression(s));
      printf("\n");
      return 0;
}
