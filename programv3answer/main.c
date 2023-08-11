#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#define   MAX_LEN  10           /* �ַ�����󳤶� */
#define   STU_NUM 30         /* ����ѧ������ */
int   Menu(void);
void  ReadScore(long num[], char name[][MAX_LEN], float score[], int n);
void  AverSumofScore(float score[], int n);
void  SortbyScore(long num[], char name[][MAX_LEN], float score[], int n,
                  int (*compare)(float a, float b));
int   Ascending(float a, float b);
int   Descending(float a, float b);
void  SwapFloat(float *x, float *y);
void  SwapLong(long *x, long *y);
void  SwapChar(char x[], char y[]);
void  AsSortbyNum(long num[], char name[][MAX_LEN], float score[], int n);
void  SortbyName(long num[], char name[][MAX_LEN], float score[], int n);
void  SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n);
void  SearchbyName(long num[], char name[][MAX_LEN], float score[], int n);
void  StatisticAnalysis(float score[], int n);
void  PrintScore(long num[], char name[][MAX_LEN], float score[], int n) ;
int main()
{
    char  ch;
    int   n = 0;
    float score[STU_NUM];
    long num[STU_NUM];
    char name[STU_NUM][MAX_LEN];
    printf("Input student number(n<30):\n");
    scanf("%d", &n);
    while (1)
    {
        ch = Menu();            /* ��ʾ�˵�������ȡ�û����� */
        switch (ch)
        {
        case 1:
            ReadScore(num, name, score, n);
            break;
        case 2:
            AverSumofScore(score, n);
            break;
        case 3:
            SortbyScore(num, name, score, n, Descending);
            printf("Sort in descending order by score:\n");
            PrintScore(num, name, score, n);
            break;
        case 4:
            SortbyScore(num, name, score, n, Ascending);
            printf("Sort in ascending order by score:\n");
            PrintScore(num, name, score, n);
            break;
        case 5:
            AsSortbyNum(num, name, score, n);
            printf("Sort in ascending order by number:\n");
            PrintScore(num, name, score, n);
            break;
        case 6:
            SortbyName(num, name, score, n);
            printf("Sort in dictionary order by name:\n");
            PrintScore(num, name, score, n);
            break;
        case 7:
            SearchbyNum(num, name, score, n);
            break;
        case 8:
            SearchbyName(num, name, score, n);
            break;
        case 9:
            StatisticAnalysis(score, n);
            break;
        case 10:
            PrintScore(num, name, score, n);
            break;
        case 0:
            printf("End of program!");
            exit(0);
        default:
            printf("Input error!\n");
        }
    }
    return 0;
}
/*  �������ܣ���ʾ�˵�������û����������ѡ�� */
int Menu(void)
{
    int itemSelected;
    printf("Management for Students' scores\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    printf("Please Input your choice:\n");
    scanf("%d", &itemSelected);     /* �����û����� */
    return itemSelected;
}
/* �������ܣ�����n��ѧ����ĳ�ſγɼ� */
void ReadScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    int i;
    printf("Input student's ID, name and score:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%ld%s%f", &num[i], name[i], &score[i]);
    }
}
/* �������ܣ�����ȫ���ֺܷ�ƽ���� */
void AverSumofScore(float score[], int n)
{
    int    i;
    float  sum = 0;
    for (i = 0; i < n; i++)
    {
        sum = sum + score[i];
    }
    printf("sum=%.0f,aver=%.2f\n", sum, n > 0 ? sum / n : 0);
}
/* �������ܣ���ѡ�񷨽�����score��Ԫ��ֵ���� */
void SortbyScore(long num[], char name[][MAX_LEN], float score[], int n,
                 int (*compare)(float a, float b))
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j], score[k])) k = j;
        }
        if (k != i)
        {
            SwapFloat(&score[k], &score[i]); /* �����ɼ� */
            SwapLong(&num[k], &num[i]);       /* ����ѧ�� */
            SwapChar(name[k], name[i]);       /* �������� */
        }
    }
}
/* ʹ���ݰ��������� */
int Ascending(float a, float b)
{
    return a < b;     /* �����ȽϾ����˰������������a<b���򽻻� */
}
/* ʹ���ݰ��������� */
int Descending(float a, float b)
{
    return a > b;    /* �����ȽϾ����˰������������a>b���򽻻� */
}
/* �������������ȸ��������� */
void  SwapFloat(float *x, float *y)
{
    float  temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* ������������������ */
void  SwapLong(long *x, long *y)
{
    long   temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/* ���������ַ��� */
void  SwapChar(char x[], char y[])
{
    char temp[MAX_LEN];
    strcpy(temp, x);
    strcpy(x, y);
    strcpy(y, temp);
}
/* �������ܣ���ѡ�񷨽�����num��Ԫ��ֵ���ӵ͵������� */
void AsSortbyNum(long num[], char name[][MAX_LEN], float score[], int n)
{
    int     i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[k])  k = j;
        }
        if (k != i)
        {
            SwapFloat(&score[k], &score[i]); /* �����ɼ� */
            SwapLong(&num[k], &num[i]);       /* ����ѧ�� */
            SwapChar(name[k], name[i]);       /* �������� */
        }
    }
}
/* �������ܣ�������ʵ���ַ������ֵ�˳������ */
void SortbyName(long num[], char name[][MAX_LEN], float score[], int n)
{
    int    i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[j], name[i]) < 0)
            {
                SwapFloat(&score[i], &score[j]); /* �����ɼ� */
                SwapLong(&num[i], &num[j]);       /* ����ѧ�� */
                SwapChar(name[i], name[j]);       /* �������� */
            }
        }
    }
}
/* �������ܣ���ѧ�Ų���ѧ���ɼ�����ʾ���ҽ�� */
void SearchbyNum(long num[], char name[][MAX_LEN], float score[], int n)
{
    long number;
    int   i;
    printf("Input the number you want to search:\n");
    scanf("%ld", &number);
    for (i = 0; i < n; i++)
    {
        if (num[i] == number)
        {
            printf("%ld\t%s\t%.0f\n", num[i], name[i], score[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/* �������ܣ����������ֵ�˳���ų��ɼ��� */
void SearchbyName(long num[], char name[][MAX_LEN], float score[], int n)
{
    char x[MAX_LEN];
    int  i;
    printf("Input the name you want to search:\n");
    scanf("%s", x);
    for (i = 0; i < n; i++)
    {
        if (strcmp(name[i], x) == 0)
        {
            printf("%ld\t%s\t%.0f\n", num[i], name[i], score[i]);
            return;
        }
    }
    printf("Not found!\n");
}
/* �������ܣ�ͳ�Ƹ������ε�ѧ����������ռ�İٷֱ� */
void StatisticAnalysis(float score[], int n)
{
    int  i, total, t[6] = {0, 0, 0, 0, 0, 0};
    for (i = 0; i < n; i++)
    {
        if (score[i] >= 0 && score[i] < 60)t[0]++;
        else if (score[i] < 70)            t[1]++;
        else if (score[i] < 80)            t[2]++;
        else if (score[i] < 90)            t[3]++;
        else if (score[i] < 100)           t[4]++;
        else if (score[i] == 100)        t[5]++;
    }
    for (total = 0, i = 0; i <= 5; i++)
    {
        total = total + t[i];
    }
    for (i = 0; i <= 5; i++)
    {
        if (i == 0) printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
        else if (i == 5) printf("%d\t%d\t%.2f%%\n",
                                    (i + 5) * 10, t[i], (float)t[i] / n * 100);
        else    printf("%d-%d\t%d\t%.2f%%\n",
                           (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
    }
}
/* �������ܣ� ��ӡѧ���ɼ� */
void PrintScore(long num[], char name[][MAX_LEN], float score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t%.0f\n", num[i], name[i], score[i]);
    }
}
