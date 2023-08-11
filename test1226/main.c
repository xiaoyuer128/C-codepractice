#include<stdio.h>
#include<math.h>
#define EPS 1e-1
/*int main()
{
    int a,b,c;
    long sum=0;
    for(a=1,b=2,c=3;c<=101;a=a+2,b=b+2,c=c+2)
    {
        sum=sum+a*b*c;

    }
    printf("sum = %ld\n",sum);
    return 0;
}

int main()
{
    char a,b;
    int c;
    scanf("%c%*c%c%*c%d",&a,&b,&c);
    printf("%c,%c,%d\n",a,b,c);

    return 0;
}

int main()
{
    char c;
    scanf("%c",&c);
    c=c-32;
    printf("%c,%d",c,c);
    return 0;
}
*/
/*int main(){
float a,b,c;
scanf("%f,%f,%f",&a,&b,&c);
if(a+b>c&&b+c>a&&c+a>b)
{
    if(fabs(a*a+b*b-c*c)<=EPS||fabs(b*b+c*c-a*a)<=EPS||fabs(a*a+c*c-b*b)<=EPS)
    {
       if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
        {
            printf("等腰直角三角形");
        }
        else
        {
            printf("直角三角形");
        }
    }
    else if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
    {
        if(fabs(a-b)<=EPS&&fabs(a-c)<=EPS&&fabs(b-c)<=EPS)
        {
             printf("等边三角形");
        }

        else
        {
            printf("等腰三角形");

        }

    }
    else{
        printf("一般三角形");
    }

}
else{
    printf("不是三角形！");
}


return 0;}
*/
/*int main()
{
    float a,b,c;
    int flag=1;
    scanf("%f,%f,%f",&a,&b,&c);
    if(a+b>c&&b+c>a&&c+a>b)
    {
        if(fabs(a*a+b*b-c*c)<=EPS||fabs(b*b+c*c-a*a)<=EPS||fabs(a*a+c*c-b*b)<=EPS)
        {
            flag=0;
            printf("直角");
        }
        if(fabs(a-b)<=EPS||fabs(a-c)<=EPS||fabs(b-c)<=EPS)
       {
           flag=0;
           printf("等腰");
        }
        if(fabs(a-b)<=EPS&&fabs(a-c)<=EPS&&fabs(b-c)<=EPS)
        {
            flag=0;
            printf("等边");
        }
        if(flag)
        {
            printf("一般");
        }
        printf("三角形");
    }
    else
    {
        printf("不是三角形");

    }
    return 0;
}*/

int main()
{
	float w,z;
	int r;
	printf("输入收入\n");
	scanf("%f",&z);
	if(z<=800)
	{
	w=0;
	printf("交税为%f\n",w);
    }
	else
	{
		r=z/100;
		switch(r)
	  {
	  	case 8:
	  	case 9:
		case 10:
		case 11:
            w=1.0*(z-800)*0.05;
            break;
        case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
		    w=1.0*400*0.05+(z-1200)*0.08;
		    break;
		default:
		    w=1.0*400*0.05+800*0.08+(z-2000)*0.2;
		    break;
	  }
	  printf("交税为%f",w);
	}
    return 0;
}
