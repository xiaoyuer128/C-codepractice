#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<mmsystem.h>//����ý��ӿڵ�ͷ�ļ�//
#pragma comment (lib,"winmm.lib")//���ö�ý����ļ�//
#define PI 3.1415
#define NUM 10
#define WIDTH 960
#define HEIGHT 640
//�̻����Ľṹ��//
struct Jet
{
	int x, y;//��ʼ���ɵ�λ��//
	int hx, hy;//��ߵ�λ��//
	IMAGE Img[2];//ѭ����ͼ//
	byte n : 1;//λ��
	bool isLaunch;//�̻����Ƿ��ڷ�����//
}Jet[NUM];
struct fire
{
	int x, y;
	int r;//��ǰ���Ű뾶//
	int width, height;
	int cen_x, cen_y;//����Բ������//
	int  max_r;//�������뾶//
	DWORD  pixel[240][240];//**ͼƬ��������//
	bool isShow;//�̻��Ƿ�׼������//
	bool isDraw;//�Ƿ�����̻�//
}fire[NUM];

//��������//
void welcome()
{
	mciSendString(L"open ./res/С����.mp3", 0, 0, 0);//**�ȴ�//ע��Ѱ�ҵ�·��,���Ƿ���DEBUG����//
	mciSendString(L"play ./res/С����.mp3", 0, 0, 0);//**�ٲ���//
	for (int i = 1; i < 40; i++)
	{
		cleardevice();//�����Ļ//
		int x = 150 - 100 * cos(2*PI / 60 * i);
		int y = 150 - 100* sin( 2*PI / 60 * i);
		settextstyle(i,i, L"����");
		setbkmode(TRANSPARENT);
		settextcolor(RGB(0, 202, 0));
		outtextxy(x, y, L"������֣�����������");
		Sleep(40);
		settextstyle(20, 20, L"����");
		outtextxy(400, 600, L"�����������");
	}
	getchar();//�����������//
	cleardevice();
	settextstyle(40, 40, L"����");
	outtextxy(300, 250, L"��������");
	outtextxy(300, 300, L"����������");
	outtextxy(300, 350, L"ף���������");
	outtextxy(300, 400, L"�������̻�����");

}
void InitData(int i)
{
	fire[i].cen_x = 120;
	fire[i].cen_y = 120;
	fire[i].max_r = 120;
	fire[i].r = 0;
	fire[i].width = 240;
	fire[i].height = 240;
	fire[i].isDraw = false;
	fire[i].isShow = false;
}
//��ȡ��Ƭ//
void loadImg()
{
	//��ʼ�����//
	IMAGE fireImg, tfire;
	loadimage(&fireImg, L"./res/flower.jpg", 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		InitData(i);//**��ʼ����𣬿϶�����Ҫ��ʼ�����ݵ�//
		SetWorkingImage(&fireImg);
		getimage(&tfire, i * 240, 0, 240, 240);
		SetWorkingImage(&tfire);
		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].pixel[a][b] = getpixel(a, b);
			}
		}
	}

	//��ʼ���̻���//
	IMAGE Jetimg;
	loadimage(&Jetimg, L"./res/launch.jpg", 200, 50);
	SetWorkingImage(&Jetimg);
	for (int i = 0; i < NUM; i++)
	{
		int n = rand() % 5;//**�������ģ��
		getimage(&Jet[i].Img[0], n * 20, 0, 20, 50);
		getimage(&Jet[i].Img[1], n * 20 + 100, 0, 20, 50);
		Jet[i].isLaunch = false;//**�������ָ�ֵ���ж�����**//
	}
	SetWorkingImage();
}
//�����̻���//**��Ҫ�Խṹ���������е����ݶ�����ֵ//
void createJet()
{
	int i = rand() % NUM;
	if (Jet[i].isLaunch == false)
	{
		Jet[i].x = rand() % (WIDTH - 20);//���ó�ʼ�����λ��//**���������ģ���γ������//
		Jet[i].y = rand() % 100 + HEIGHT;
		Jet[i].hx = Jet[i].x;
		Jet[i].hy = rand() % (HEIGHT / 3 * 2);
		Jet[i].isLaunch = true;
	}
}
//�����̻���//
void launch()
{
	for (int i = 0; i < NUM; i++)
	{
		if (Jet[i].isLaunch)
		{
			putimage(Jet[i].x, Jet[i].y, &Jet[i].Img[Jet[i].n], SRCINVERT);
			if (Jet[i].y > Jet[i].hy)//**�ж�ֹͣ����//
			{
				Jet[i].y -= 5;
				Jet[i].n++;
			}
			putimage(Jet[i].x, Jet[i].y, &Jet[i].Img[Jet[i].n], SRCINVERT);
			if(Jet[i].y <= Jet[i].hy)
			{
				Jet[i].isLaunch = false;//**ֹͣ���ж�����//
				fire[i].x = Jet[i].x;
				fire[i].y = Jet[i].y;
				fire[i].isShow = true;
			}
		}
	}
}

//���ը��//
void bloom(DWORD *pMem)
{
	for (int i = 0; i < NUM; i++)
	{
		if (fire[i].isShow)
		{
			if (fire[i].r < fire[i].max_r)
			{
				fire[i].r++;
				fire[i].isDraw = true;
			}
			if (fire[i].r >= fire[i].max_r)
			{
				InitData(i);
			}
		}
		if (fire[i].isDraw)//�Ƿ���Կ�ʼ����//
		{
			for (double a = 0; a < 2 * PI; a += 0.01)
			{
				int img_x = fire[i].cen_x + fire[i].r*cos(a);
				int img_y = fire[i].cen_y + fire[i].r*sin(a);
				if (img_x>0&&img_x<fire[i].width&&img_y>0&&img_y<fire[i].height)
				{
					int win_x = fire[i].x + fire[i].r*cos(a);
					int win_y = fire[i].y + fire[i].r*sin(a);
					if (win_x > 0 && win_x < WIDTH&&win_y>0 && win_y < HEIGHT)
					{
						pMem[win_y * WIDTH + win_x] = BGR(fire[i].pixel[img_x][img_y]);
					}
				}

			}
		}
	}
}
int main()
{
	initgraph(960, 640);
	srand((unsigned)time(NULL) + clock());
	DWORD *pMem = GetImageBuffer();//**��ȡ�����ڴ�ָ��//
	welcome();
	loadImg();
	while (1)
	{
		for (int  i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//**ע��������������//
				}
			}
		}
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//**ע��������������//
				}
			}
		}
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//**ע��������������//
				}
			}
		}
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//**ע��������������//
				}
			}
		}
		for (int i = 0; i < WIDTH; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				int x = rand() % WIDTH;
				int y = rand() % HEIGHT;
				if (y < HEIGHT)
				{
					pMem[y * WIDTH + x] = BLACK;//**ע��������������//
				}
			}
		}
		createJet();
		launch();
		bloom(pMem);
		Sleep(10);
	}
	closegraph();
	return 0;
}
