// LifeGame.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 生命游戏全部完成人：Wuhaoyang 2016301510012	

#include<graphics.h>
#include<conio.h>
#include <iostream>
#include "LifeGame.h"
#include "ui.h"
using namespace std;

RECT SeedArray[5][5];

//设置种子地
void PrintSeed(LifeGame LG,ui window)
{
	
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			int left = i * 96;
			int top = j * 96;
			int right = (i + 1) * 96;
			int bottom = (j + 1) * 96;
			SeedArray[i][j] = { left,top,right,bottom };
			window.SetSeedLand(left, top, right, bottom, LG.GetSeedCondition(i + 1, j + 1));
		}
}
//判断鼠标位置是否在矩形里
int IfMouse(RECT r,MOUSEMSG m)
{
	if (m.x > r.left&&m.x<r.right&&m.y>r.top&&m.y < r.bottom)
		return 1;
	else
		return 0;
}

int main()
{
	LifeGame LG;
	ui window;
	MOUSEMSG m;

	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();

	//设置按钮图像
	RECT p1 = window.SetPressBotton(480, 64, 640, 104);
	window.SetText(p1, _T("初始化"));
	RECT p2 = window.SetPressBotton(480, 168, 640, 208);
	window.SetText(p2, _T("随机生成种子"));
	RECT p3 = window.SetPressBotton(480, 272, 640, 312);
	window.SetText(p3, _T("下一代"));
	RECT p4 = window.SetPressBotton(480, 376, 640, 416);
	window.SetText(p4, _T("退出"));

	//设置裁剪区
	HRGN rgn = CreateRectRgn(0, 0, 480, 480);
	setcliprgn(rgn);
	DeleteObject(rgn);

	while (1)
	{
		m = GetMouseMsg();
		//设置按钮功能
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (IfMouse(p1, m))
			{
				LG.initall();
				clearcliprgn();
				PrintSeed(LG, window);
				break;
			}
			else if (IfMouse(p2, m))
			{
				LG.RandomInit();
				clearcliprgn();
				PrintSeed(LG, window);
				break;
			}
			else if (IfMouse(p3, m))
			{
				LG.NextGeneration();
				clearcliprgn();
				PrintSeed(LG, window);
				break;
			}
			else if (IfMouse(p4, m))
			{
				return 0;
			}
			else
			{
				for (int i = 0; i < 5; i++)
					for (int j = 0; j < 5; j++)
					{
						if (IfMouse(SeedArray[i][j], m))
						{
							if (LG.GetSeedCondition(i + 1, j + 1) == 1)
								LG.SetSeedCondition(i + 1, j + 1, 0);
							else
								LG.SetSeedCondition(i + 1, j + 1, 1);
							clearcliprgn();
							PrintSeed(LG, window);
							break;
						}
					}
				break;
			}
		case WM_RBUTTONDOWN:
			return 0;	// 按鼠标右键退出程序

		}
	}
		// 关闭图形窗口
		closegraph();



	
}
	

	


