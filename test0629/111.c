#define INF 32767            //INF表示无穷

#define MAXV 10

#include "stdio.h"



//以下是输出最短路径的算法dispath，其中ppath（）函数在path中递归输出从顶点vi到vj的最短路径。

void ppath(int path[][MAXV],int i,int j)

{ int k;

  k=path[i][j];

  if(k==i)  //path[i][j]=i时,顶点vi和vj之间无中间顶点,也就是说找到了始节点

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

                 printf("从顶点v%d到v%d没有路径:\n",i,j);

               }//if

          else

          {

               printf("从顶点v%d到v%d的路径为:",i,j);

               printf("v%d,",i);

               ppath(path,i,j);

               printf("v%d,",j);

               printf("路径长度为: %d ^-^\n",A[i][j]);

          }//else

        }

}



void floyd(int cost[MAXV][MAXV],int n)

{

int A[MAXV][MAXV],path[MAXV][MAXV];

int i,j,k;

for(i=0;i<n;i++)         //赋值A0[i][j]和path0[i][j]

        for(j=0;j<n;j++)

  {

          A[i][j]=cost[i][j];

          if(cost[i][j]<INF)

                path[i][j]=i; //初始化路径矩阵，原来有路

          else

                path[i][j]=-1; //原来没有路

       }//for



  for(k=0;k<n;k++)        //向vi与vj之间中n次加入中间顶点vk

        for(i=0;i<n;i++)

          for(j=0;j<n;j++) //求min{Ak[i][j]，Ak+1[i][k]+Ak+1[k][j]}

               if(A[i][j]>(A[i][k]+A[k][j]))

                {

                     A[i][j]=A[i][k]+A[k][j];

                     path[i][j]=k;//表示从i节点到j节点,要经过k节点。

                }//if,for

  dispath(A,path,n);      //输出最短路径

}//floyd



int inputM(int cost[][MAXV])

{

int n,e,w,h,z;

/*

printf("Please input 顶点数和边数\n");

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

printf("please int the 邻接矩阵的值(起点(数字) 终点(数字) 权值(数字))：\n");

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

n=inputM(cost); //返回顶点数

floyd(cost,n);

}

