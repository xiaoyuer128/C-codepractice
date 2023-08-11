#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

int main()
{
    mciSendString("open D:\\TestMusics\\µ¾Ïã.mp3",NULL,0,NULL);
    mciSendString("play D:\\TestMusics\\µ¾Ïã.mp3",NULL,0,NULL);
    getchar();
    return 0;
}
