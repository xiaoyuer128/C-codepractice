//#include <stdio.h>
/*main()
{
    int n;
    char monthName[][20] = {"Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Input month number:");
    scanf("%d",&n);
    if ((n <= 12) &&(n >= 1))
    {
        printf("month %d is %s\n", n, monthName[n]);

    }
    else
    {
        printf("%s\n", monthName[0]);
    }
}
*//*
#include<stdio.h>
#define N 10
void InputArray(int a[][N], int m, int n);
void CalSumAndMean(int a[][N], int m, int n, int *sum, float *mean);
void InputArray(int a[][N], int m, int n)
{
    int i, j;
    printf("Input elements of %d*%d array:\n", m, n);
    for (i = 0; i < m; i++)
    {
        for (j=0;j<n;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
}

int main()
{
    int m, n, iSum=0;
    float fMean=0;
    int a[N][N];
    float *sum;
    float *mean;
    sum=&iSum;
    mean=&fMean;
    printf("Input size of 2-D array m,n:\n");
    scanf("%d,%d",&m,&n);
    InputArray(a,m,n);
    CalSumAndMean(a,m,n,sum,mean);
    printf("sum=%d, mean=%.2f\n", *sum, *mean);
    return 0;
}


void CalSumAndMean(int a[][N], int m, int n, int *sum, float *mean)
{
    int i, j,count;
    count = 0;
    for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if(a[i][j]>0)
        {
            *sum=*sum+a[i][j];
            count++;
        }
    }
}
    *mean=*sum/(count*1.0);
    return ;
}


#include<stdio.h>
#define N 10
void InputArray(int a[][N], int m, int n);
void CalSumAndMean(int a[][N], int m, int n, int *sum, float *mean);
从键盘输入一个m行n列的二维数组*/
/*void InputArray(int a[][N], int m, int n)
{
    int i, j;
    printf("Input elements of %d*%d array:\n", m, n);
    for (i = 0; i < m; i++)
    {
       for(j=0;j<n;j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
}
int main()
{
    int m, n, iSum=0 ;//iSum用于保存二维数组a中正数的总和
    float fMean=0;   //fMean用于保存二维数组a中正数的均值
    int a[N][N];
    int *sum;
	float *mean;
	sum=&iSum;
	mean=&fMean;
    printf("Input size of 2-D array m,n:\n");
    scanf("%d,%d", &m, &n);
    InputArray( a ,  m,  n);
    CalSumAndMean( a , m,  n,sum, mean);


    printf("sum=%d, mean=%.2f\n",*sum, *mean);
    return 0;
}
void CalSumAndMean(int a[][N], int m, int n, int *sum, float *mean)
{
    int i, j,count;
    count = 0;
    for (i = 0; i < m; i++)
    {
       for(j=0;j<n;j++)
        {
             if( a[i][j] > 0)
             {
             	*sum=*sum+a[i][j];
             	count++;
			 }
        }
    }
    *mean=*sum/(count*1.0);
    return ;
}
*/
/*#include<stdio.h>
int main()
{
    int max=0,row=0,m,n,a[3][3];
    for(m=0;m<3;m++)
    {
        for(n=0;n<3;n++)
        {
            scanf("%d",&a[m][n]);
        }
    }
    max=a[m][m];
    for(m=0;m<3;m++)
    {
     if(max<=a[m][m])
     {
     max=a[m][m];
    row=m;
     }
    }
    printf("max=%d ,row=%d",max,row);
    return 0;
}*/

/*
#include<stdio.h>
int main()
{
    int i,j,max,a[3][4];
    printf("请输入3*4矩阵：\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max=a[0][0];
     for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(max<=a[i][j])
            max=a[i][j];
        }
    }
    printf("max value is %d\n",max);
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int i,j,max=0,a[3][4];
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max=a[0][0];
     for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            if(max<a[i][j])
            max=a[i][j];
        }
    }
    printf("max=%d\n",max);
    return 0;
}
*/
/*
#include<stdio.h>
int main()
{
    int i, j, a[3][3],max, row=0;
    for(i=0;i<3;i++)
     {
         for(j=0;j<3;j++)
         {
             scanf("%d",&a[i][j]);
         }
     }
     max=a[0][0];
      for(i=0;i<3;i++)
     {
             if(max<a[i][i])

             {
                 max=a[i][i];
                row=i;
             }
     }
    printf("max=%d ,row=%d",max,row);
    return 0;
}*/

#include<stdio.h>
int main()
{
    int a[6][6],i,j,tep,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j] = i * n + j + 1;
        }

    }
    printf("The original matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
           printf("%3d",a[i][j]);
        }

    }
    printf("\n");
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           if (i < j)
            {
                tep = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = tep;
            }

        }

    }

    printf("The changed matrix is:\n");
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
           printf("%3d",a[i][j]);
        }

    }
    return 0;
}
