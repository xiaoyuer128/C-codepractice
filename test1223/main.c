#include <stdio.h>
#include <stdlib.h>

int main()
{
    float arr[5]={10,9,8.000,7,56};
    int i;
    arr[3]+=10;
   for(i=0;i<10;i++)
   {
       printf("%f\n",arr[i]);
   }
   printf("数组占的大小：%d\n",sizeof(arr[2]));
    return 0;
}
