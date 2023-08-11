#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define maxsize 4
struct  student{
    char  name[8];
    int  score;
}R[maxsize];/*定义结构体*/
int main()
{
	int i,j;
	int mingci=1;
    char a[maxsize];
    printf("请输入学生的姓名与分数：\n");
    for(i=0;i<maxsize;i++)/*依次输入姓名成绩*/
    {
        printf("姓名：");
        scanf("%s",R[i].name);
        printf("成绩：");
        scanf("%4d",&R[i].score);
    }
        for(i=1;i<maxsize;i++)
		{
            int tmp=R[i].score;
            for(j=i-1;j>=0;j--)
			{
                if(R[j].score>tmp)
				{
                    R[j+1].score=R[j].score;
                }
				else
				{
                    break;
                }
			   strcpy(a,R[j].name);
             strcpy(R[j].name,R[j+1].name);
             strcpy(R[j+1].name,a);
            }
            R[j+1].score=tmp;

        }
	for(i=0;i<maxsize;i++)
	{
		if(R[i].score!=R[i-1].score)
			mingci=i+1;
		else
			mingci=mingci;
		printf("成绩%d 姓名%s 名次%d\n",R[maxsize-1-i].score,R[maxsize-1-i].name,mingci);
	}
	return 0;
}
