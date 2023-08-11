#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
//开户信息
typedef struct _Person
{
	char name[20];
	char account[20];
	char password[7];
	float money;
}Person;
//用户结点
typedef struct _Node
{
	Person P;	//客户
	struct _Node* next;
}Node;
Node* HeadNode = NULL;//链表头

/*----------------函数--------------------*/
void Login();
void Menu();
void Register();
void LoginMenu(Node* pNode);
void FindAccount(Node* pNode);
void DrawMoney(Node* pNode);
void Deposit(Node* pNode);
void Transfer(Node* pNode);
void LoginMenu(Node* pNode);

//主菜单
void Menu()
{
	printf("hello\n");
	printf("1.注册\n");
	printf("2.登录\n");
	printf("3.系统帮助\n");
	printf("4.查询账号\n");
	printf("5.推出\n");
}

void Register()
{
    int i;
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->next = NULL;
	NewNode->P.money = 0;

	printf("请输入您的名字:");
	scanf("%s", NewNode->P.name);
	printf("请输入您的密码:");
	scanf("%s", NewNode->P.password);

	char Password[7];
	printf("请再次输入您的密码:");
	scanf("%s", Password);

	for (i = 1; i < 4; i++)
	{
		if (strcmp(NewNode->P.password, Password) != 0)
		{
			printf("您输入的密码有误，还有%d次机会.\n", 3 - i);
			printf("请再次输入您的密码:");
			scanf("%s", Password);
		}
		else
		{
			srand((unsigned int)time(NULL));
			sprintf(NewNode->P.account, "%d%d%d%d%d", rand() % 9000 + 1000, rand() % 9000 + 1000,
				rand() % 9000 + 1000, rand() % 9000 + 1000, rand() % 900 + 100);
			//头插法
			if (HeadNode == NULL)
			{
				HeadNode = NewNode;
			}
			else
			{
				NewNode->next = HeadNode;
				HeadNode = NewNode;
			}
			printf("\n\n\n\n\t\t\t\t恭喜你已经成功注册账户，以下是您的账户信息.\n");
			printf("\t\t\t\t姓名:%s\n", NewNode->P.name);
			printf("\t\t\t\t账户:%s\n", NewNode->P.account);
			printf("\t\t\t\t余额:%.2f\n", NewNode->P.money);
			getch();
			return 1;
		}

	}
	printf("您的账号已被锁定，请稍后再试.");
	return 1;
}
//取款
void DrawMoney(Node* pNode)
{
	Node* mNode = pNode;
	float Money = 0;
	printf("欢迎进入ATM银行管理系统\n");
	printf("请选择你取款金额\n");
	printf("100\t\t2000\n");
	printf("500\t\t5000\n");
	printf("10000\t\t其他金额\n");
	scanf("%f", &Money);
	mNode->P.money = mNode->P.money - Money;
	return mNode;
}
//存款
void Deposit(Node* pNode)
{
	Node* mNode = pNode;
	float Money = 0;
	printf("请存取您的金额:");
	scanf("%f", &Money);
	mNode->P.money = mNode->P.money + Money;
	return mNode;
}
//转账
void Transfer(Node* pNode)
{
	Node* TNode = HeadNode;
	char Account[20] = "";
	printf("请输入转账的号码:");
	scanf("%s", Account);
	while (TNode != NULL)
	{
		if (strcmp(TNode->P.account, Account) != 0)
		{
			TNode = TNode->next;
			continue;
		}
		else
		{
			float Money = 0;
			printf("请输入您要转账的金额:");
			printf("100\t\t2000\n");
			printf("500\t\t5000\n");
			printf("10000\t\t其他金额\n");
			scanf("%f", &Money);
			TNode->P.money = TNode->P.money + Money;
			pNode->P.money = pNode->P.money - Money;
			return 1;
		}
	}
	return 1;
}
//修改账户密码
void ChangePassword(Node* pNode)
{
    int i;
	Node* CNode = HeadNode;
	char password[7] = "";
	printf("请输入您的旧密码:");
	while (CNode != NULL)
	{
		for (i = 1; i < 4; i++)
		{
			scanf("%s", password);
			if (strcmp(password, pNode->P.password) != 0)
			{
				printf("您输入的密码有误，请重新输入，还有%d次机会.\n", 3 - i);
				continue;
			}
			else
			{
				printf("请输入您的新密码:");
				scanf("%s", pNode->P.password);
				printf("您的密码已修改完成.");
				return 1;
			}
		}
		printf("您错误的次数过多，请稍后重试.\n");
		return 1;
	}
}
//登录菜单
void LoginMenu(Node* pNode)
{

	while (1)
	{
		printf("欢迎进入ATM银行管理系统\n");
		printf("请选择以下服务:\n");
		printf("1.取款\t\t2.查询\n");
		printf("3.存款\t\t4.转账\n");
		printf("5.修改密码\t6.退出\n");

		char ch = getch();
		switch (ch)
		{
		case '1':
			DrawMoney(pNode);//取款
			break;
		case '2':
			printf("您的账户余额为:%.2f", pNode->P.money);
			getch();
			break;
		case '3':
			Deposit(pNode);//存款
			break;
		case '4':
			Transfer(pNode);//转账
			break;
		case '5':
			ChangePassword(pNode);//修改密码
			break;
		case '6'://退出
			return 0;
			break;
		default:
			break;
		}
		system("cls");
	}


}
//登录
void Login()
{
	system("cls");
	Node* pNode = HeadNode;

	char P_account[20];
	char P_password[7];
	int i;
	printf("请输入您的卡号:");
	scanf("%s", P_account);

	while (pNode != NULL)
	{
		if (strcmp(P_account, pNode->P.account) != 0)
		{
			pNode = pNode->next;
			continue;
		}
		else
		{
			for (i = 1; i < 4; i++)
			{
				printf("请输入您的密码:");
				scanf("%s", P_password);
				if (strcmp(P_password, pNode->P.password) != 0)
				{
					printf("您输入的密码有误，还有%d次机会.\n", 3 - i);
				}
				else
				{
					system("cls");
					LoginMenu(pNode);
					return 1;
				}
			}
			printf("\n对不起，您输入的密码有误，请重新登录.\n");
			system("pause");
			return 1;

		}

	}
	return 1;
}
//系统帮助信息
void Help()
{
	system("cls");
	printf("\n\n\n\n\t——————————-----—---——ATM系统帮助----------------------------------------\n"
		"\t1、初始界面：客户插卡前或者退卡后ATM显示的界面，提示客户插卡操作及银行广告.\n"

		"\t2、身份认证：需要客户插入银行卡后输入密码来验证所有权.\n"

		"\t3、吞卡：客服若连续输入密码3次错误后，则将卡吞入ATM内.\n"

		"\t4、账户：账户由银行卡的卡号、密码、银行系统用户信息组成.\n"

		"\t5、业务操作：由查询余额、取款、存款、转账、取卡等事项组成.\n"

		"\t6、查询余额：显示该账户中剩余金额.\n"

		"\t7、取款：根据客户输入的金额从账户中扣除相应的金额，客户可以提取相应数额的现金.\n"

		"\t8、存款：客户存入现金，账户根据现金数额增加剩余金额.\n"

		"\t9、转账：客户输入另外一个账户号码和金额，从本账户的余额中减去该金额，增加到那个账号中.\n"

		"\t10、打印凭条：凭条由日期，银行卡的卡号，交易流水号组成.\n"

		"\t11、取卡：客户取回银行卡.\n"
		"\t————————————————-------------------------------------------------------\n"
	);
	getch();
	return 1;
}
//查询账号
void FindAccount(Node* pNode)
{
	Node* FNode = pNode;
	char AccountName[7];
	printf("请输入账号姓名:");
	scanf("%s", AccountName);

	while (FNode != NULL)
	{
		if (strcmp(AccountName, FNode->P.name) != 0)
		{
			FNode = FNode->next;
			continue;
		}
		else
		{
			printf("该姓名的账户为:%s", FNode->P.account);
			return 1;
		}
	}
	printf("抱歉!该姓名未注册账号.");
	return 1;
}
int main()
{
	system("color b0");//背景颜色

	while (1)
	{
		system("cls");
		Menu();
		char ch = _getch();
		switch (ch)
		{
		case '1':
			Register();//注册
			break;
		case '2':
			Login();//登录
			break;
		case '3':
			Help();//系统帮助
			break;
		case '4':
			FindAccount(HeadNode);//查询账号
			getch();
			break;
		case '5'://退出程序
			exit(0);
		default:
			break;
		}
	}
	return 0;
}
