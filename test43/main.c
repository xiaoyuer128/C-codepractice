#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a[2][3]={1,2,3,4,5,6};
   int *p=&a[0][0];
   printf("%d",p[4]);
}
