#include  <stdio.h>
#include  <math.h>
main()
{
    float data1, data2;                 //��������������
    char op;                            //���������
    char reply;                         //�û�����Ļش�
    do
    {
        printf("Please enter the expression:\n");
        scanf("%f %c%f", &data1, &op, &data2);      //%cǰ��һ�ո�
        switch (op)                     //��������������ȷ��Ҫִ�е�����
        {
        case '+':
            printf("%f + %f = %f\n", data1, data2, data1 + data2);
            break;
        case '-':
            printf("%f - %f = %f \n", data1, data2, data1 - data2);
            break;
        case '*':
            printf("%f * %f = %f \n", data1, data2, data1 * data2);
            break;
        case '/':
            if (fabs(data2) <= 1e-7)
            {
                printf("Division by zero!\n");
            }
            else
            {
                printf("%f / %f = %f \n", data1, data2, data1 / data2);
            }
            break;
        default:
            printf("Unknown operator!\n");
        }
        printf("Do you want to continue(Y/N or y/n)?");
        scanf(" %c", &reply);               //%cǰ��һ�ո�
    }
    while (reply == 'Y' || reply == 'y');
    printf("Program is over!\n");
}


