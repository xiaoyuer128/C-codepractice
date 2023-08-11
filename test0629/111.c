#define INF 32767            //INF��ʾ����

#define MAXV 10

#include "stdio.h"



//������������·�����㷨dispath������ppath����������path�еݹ�����Ӷ���vi��vj�����·����

void ppath(int path[][MAXV],int i,int j)

{ int k;

  k=path[i][j];

  if(k==i)  //path[i][j]=iʱ,����vi��vj֮�����м䶥��,Ҳ����˵�ҵ���ʼ�ڵ�

         return;

  ppath(path,i,k);

  printf("v%d,",k);

  ppath(path,k,j);

}



void dispath(int A[][MAXV],intpath[][MAXV],int n)

{ int i,j;

for(i=0;i<n;i++)

        for(j=0;j<n;j++)

        {

              if(A[i][j]==INF)

               {

                 if(i!=j)

                 printf("�Ӷ���v%d��v%dû��·��:\n",i,j);

               }//if

          else

          {

               printf("�Ӷ���v%d��v%d��·��Ϊ:",i,j);

               printf("v%d,",i);

               ppath(path,i,j);

               printf("v%d,",j);

               printf("·������Ϊ: %d ^-^\n",A[i][j]);

          }//else

        }

}



void floyd(int cost[MAXV][MAXV],int n)

{

int A[MAXV][MAXV],path[MAXV][MAXV];

int i,j,k;

for(i=0;i<n;i++)         //��ֵA0[i][j]��path0[i][j]

        for(j=0;j<n;j++)

  {

          A[i][j]=cost[i][j];

          if(cost[i][j]<INF)

                path[i][j]=i; //��ʼ��·������ԭ����·

          else

                path[i][j]=-1; //ԭ��û��·

       }//for



  for(k=0;k<n;k++)        //��vi��vj֮����n�μ����м䶥��vk

        for(i=0;i<n;i++)

          for(j=0;j<n;j++) //��min{Ak[i][j]��Ak+1[i][k]+Ak+1[k][j]}

               if(A[i][j]>(A[i][k]+A[k][j]))

                {

                     A[i][j]=A[i][k]+A[k][j];

                     path[i][j]=k;//��ʾ��i�ڵ㵽j�ڵ�,Ҫ����k�ڵ㡣

                }//if,for

  dispath(A,path,n);      //������·��

}//floyd



int inputM(int cost[][MAXV])

{

int n,e,w,h,z;

/*

printf("Please input �������ͱ���\n");

scanf("%d%d",&n,&e);

*/

n=3;

e=5;

for(int i=0;i<n;i++)

       for(intj=0;j<n;j++)

       {

              if(i==j)cost[i][j]=0;

              elsecost[i][j]=INF;

       }

/*

printf("please int the �ڽӾ����ֵ(���(����) �յ�(����) Ȩֵ(����))��\n");

for(int i=0;i<e;i++)

 {

       scanf("%d%d%d",&h,&z,&w);

       cost[h][z]=w;

 }//for

*/

cost[0][1]=4;

cost[0][2]=11;

cost[1][0]=6;

cost[1][2]=2;

cost[2][0]=3;

return n;

}



int main()

{

int n;

int cost[MAXV][MAXV];

n=inputM(cost); //���ض�����

floyd(cost,n);

}

