#include <stdio.h>
#include <stdlib.h>
void check(char name[],char passwork[],int i);
int main()
{
    check();
    return 0;
}
void check(char name[],char passwork[],int i)//�����Ƿ�����˺�
{
    FILE *f;
    char x[20],y[20],ch;
    f=fopen("remember.txt","r");
    if(i==0)//ע��
    {
        do{
          fscanf(f,"%s %s ",x,y);
        }while((strcmp(name,x)!=0)&&(!feof(f)));
        if(strcmp(name,x)!=0)
        {
            char names[35];
            fclose(f);
            f=fopen("remember.txt","a");
            fprintf(f,"%s\n%s\n",name,passwork);
            fclose(f);
            f=fopen(strcat(strcpy(names,name),".txt"),"w");
            for(i=0;i<5;i++)
            {
                fprintf(f,"%ld\n%s\n",0,name);
            }
            fclose(f);
            land(name);
        }
        else
        {
            map();
            Pos(6,10);
            printf("�������!������!");
            Sleep(500);
            Pos(6,12);
            printf("����ע��������Y/y:");
            Pos(25,12);
            ch=getchar();
            if(ch=='y'||ch=='Y')
            {
                getchar();
                newuser();
            }
            else
            {
                user();
            }

        }
    }
    else//��¼
    {
        do{
          fscanf(f,"%s %s ",x,y);
        }while((strcmp(name,x)!=0||strcmp(passwork,y)!=0)&&(!feof(f)));
        if(strcmp(name,x)==0&&strcmp(passwork,y)==0)
        {
            fclose(f);
            land(name);
        }
        else
        {
            fclose(f);
            map();
            Pos(6,10);
            printf("�������!������!");
            Sleep(500);
            Pos(6,12);
            printf("���µ�¼������Y/y:");
            Pos(25,12);
            ch=getchar();
            if(ch=='y'||ch=='Y')
            {
                getchar();
                olduser();
            }
            else
                user();
        }
    }
}
