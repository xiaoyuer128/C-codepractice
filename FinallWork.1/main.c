#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#define FORMAT "%-10s%-10s%-15s%-25s%-30s%\n"//定义一个格式化输出（使系统输出更简洁）的宏
#define LEN sizeof(struct addritem)//定义LEN为结构体addritem所占用的内存的字节数的宏
#define Data addrinfo[i].name,addrinfo[i].occu,addrinfo[i].tel,addrinfo[i].email,addrinfo[i].address
void input();
void search();
void update();
void del();
void display();
void sort();
void menu();

struct addritem
{
    char name[10];//联系人姓名
    char occu[10];//工作
    char tel[11];//电话
    char email[20];//邮箱
    char address[30];//地址
};
struct addritem addrinfo[100];//定义结构体数组
int main()
{
    int n;

    menu();
    scanf("%d", &n);
    while (n)
    {
        switch (n)
        {
        case 1:
            input();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            sort();
            break;
        case 6:
            display();
            break;
        default:
            break;

        }
        getch();
        menu();
        scanf("%d", &n);
    }
    return 0;
}
void menu()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t||---------------CONTACT----------------||\n");
    printf("\t\t||1.input record                        ||\n");
    printf("\t\t||2.search record                       ||\n");
    printf("\t\t||3.update record                       ||\n");
    printf("\t\t||4.delete record                       ||\n");
    printf("\t\t||5.sort                                ||\n");
    printf("\t\t||6.display                             ||\n");
    printf("\t\t||0.exit                                ||\n");
    printf("\t\t||--------------------------------------||\n");
    printf("请选择0-6：");

}
//菜单
void input()
{
    int i,count = 0;
    char ch[3];
    FILE *fp;
    if((fp=fopen("data.txt","a+"))==NULL)
    {
        printf("can't open\n");
        return;
    }
    while(!feof(fp))
    {
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    }
    fclose(fp);
    if(count==0)
    {
        printf("no contact record!\n");
    }
    else
    {
        system("cls");
        display();

    }
    if((fp=fopen("data.txt","wb")))
    {
        printf("can't open\n");
        return;
    }
    for(i=0; i<count; i++)
    {
        fwrite(&addrinfo[i],LEN,1,fp);
    }
    printf("please input yes or no");
    scanf("%s",ch);
    while(strcmp(ch,"Yes")==0||strcmp(ch,"yes")==0)
    {
        printf("name:");
        scanf("%s",addrinfo[count].name);
        for(i=0; i<count; i++)
        {
            if(strcmp(addrinfo[i].name,addrinfo[count].name)==0)
            {
                printf("姓名已经存在，请按任意一个键继续。");
                getch();
                fclose(fp);
                return;
            }
            printf("occupation:");
            scanf("%s",addrinfo[count].occu);
            printf("telephone:");
            scanf("%s",addrinfo[count].tel);
            printf("email:");
            scanf("%s",addrinfo[count].email);
            printf("address:");
            scanf("%s",addrinfo[count].address);
            if(fwrite(&addrinfo[count],LEN,1,fp)!=1)
            {
                printf("can't save the record!");
                getch();
            }
            else
            {
                printf("%s saved!",addrinfo[count].name);
                count++;
            }
            printf("continue?yes or no:");
            scanf("%s",ch);
        }
    }
    fclose(fp);
    printf("OK!\n");
}

void search()
{
    FILE *fp;
    int i,count = 0;
    char ch[3],name[10];
    if((fp=fopen("data.txt","rb"))==NULL)
    {
        printf("can't open\n");
        return;
    }
    while(!feof(fp))
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    fclose(fp);
    if(count==0)
    {
        printf("no record!");
        return;
    }
    printf("please input the name:");
    scanf("%s",name);
    for(i=0; i<count; i++)
    {
        if(strcmp(name,addrinfo[i].name)==0)
        {
            printf("Find the cantact,display?yes or no");
            scanf("%s",ch);
            if((strcmp(ch,"Yes")==0)||strcmp(ch,"yes")==0)
            {
                printf("name      occupation      email        address");
                printf(FORMAT,Data);
            }
            break;
        }
        if(i==count)
            printf("can't find the cantact!");
    }
}
void update()
{

    FILE *fp;
    int i,j,count = 0;
    char name[10];
    if((fp=fopen("data.txt","r+"))==NULL)
    {
        printf("can't open\n");
        return;
    }
    while(!feof(fp))
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    if(count==0)
    {
        printf("no record!");
        return;
    }
    display();
    printf("update name:");
    scanf("%s",name);
    for(i=0; i<count; i++)
    {
        if(strcmp(name,addrinfo[i].name)==0)
        {
            printf("Find the contact!you can update!\n");
            printf("name:");
            scanf("%s",addrinfo[i].name);
            printf("occupation:");
            scanf("%s",addrinfo[i].occu);
            printf("telephone:");
            scanf("%s",addrinfo[i].tel);
            printf("email:");
            scanf("%s",addrinfo[i].email);
            printf("address:");
            scanf("%s",addrinfo[i].address);
            printf("update successful!\n");
            if((fp=fopen("data.txt","wb"))==NULL)
            {
                printf("can't open\n");
                return;
            }
            for(j=0; j<count; j++)
                if(fread(&addrinfo[j],LEN,1,fp)!=1)
                {
                    printf("can't save!");
                    getch();

                }
            fclose(fp);
            return;
        }
    }
    printf("not found the contact!");
}

void del()
{
    FILE *fp;
    int i,j,count = 0;
    char ch[3];
    char name[10];
    if((fp=fopen("data.txt","r+"))==NULL)
    {
        printf("can't open\n");
        return;
    }
    while(!feof(fp))
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    fclose(fp);
    if(count==0)
    {
        printf("no record!");
        return;
    }
    display();
    printf("please input the name:");
    scanf("%s",name);
    for(i=0; i<count; i++)
    {
        if(strcmp(name,addrinfo[i].name)==0)
        {
            printf("find the contact,delete?yes or no");
            scanf("%s",ch);
            if((strcmp(ch,"Yes")==0)||strcmp(ch,"yes")==0)

                for(j=i; j<count; j++)

                    addrinfo[j]=addrinfo[j+1];

            count--;
            if((fp=fopen("data.txt","wb"))==NULL)
            {
                printf("can't open\n");
                return;
            }

            for(j=0; j<count; j++)
                if(fwrite(&addrinfo[j],LEN,1,fp)!=1)
                {
                    printf("can't save!");
                    getch();
                }
            fclose(fp);
            printf("delete successful!");
            return;
        }
    }
    printf("not find the contact!\n");

}

void sort()
{
    FILE *fp;
    struct addritem t;
    int i=0,j=0,count=0;
    if(fp=fopen("data.txt","r+")==NULL)
    {
        printf("can't open!\n");
        return;
    }
    while(!feof(fp))
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    fclose(fp);
    if(count==0)
    {
        printf("no record!\n");
        return;
    }
    for(i=0; i<count-1; i++)
    {
        for(j=i+1; j<count; j++)
        {
            if(strcmp(addrinfo[i].name,addrinfo[j].name)>0)
            {
                t=addrinfo[i];
                addrinfo[i]=addrinfo[j];
                addrinfo[j]=t;
            }

        }

    }
    if((fp=fopen("data.txt","wb"))==NULL)
    {
        printf("can't open\n");
        return;
    }
    for(i=0; i<count; i++)
        if(fwrite(&addrinfo[i],LEN,1,fp)!=1)
        {
            printf("can't save!\n");
        }
    fclose(fp);
    printf("save successful!\n");
    return;
}
void display()
{
    FILE *fp;
    int i,count=0;
    fp=fopen("data.txt","rb");
    while(!feof(fp))
        if(fread(&addrinfo[count],LEN,1,fp)==1)
            count++;
    fclose(fp);
    printf("name      occupation      email        address\t\n");
    for(i=0; i<count; i++)
        printf(FORMAT,Data);
    return;
}
