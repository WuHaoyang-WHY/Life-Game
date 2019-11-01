#include<graphics.h>
#include<conio.h>
#include<iostream>
#include"ui.h"
using namespace std;

ui::ui(int width , int height )
{
	ui_width = width;
	ui_height = height;

}

RECT ui::SetPressBotton(int left, int top, int right, int bottom)  //设置按钮框
{
	setfillcolor(BLACK);	//设置填充样式为黑色
	solidrectangle(left, top, right, bottom);
	RECT r = { left,top,right,bottom };
	return r;
}

void ui::SetText(RECT r , LPCTSTR string)	//设置文本
{
	settextcolor(RED);
	drawtext(string, &r, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
}

void ui::SetSeedLand(int left, int top, int right , int bottom, int SeedCondition)
{
	if (SeedCondition == 1)
		setfillstyle((BYTE*)"\x3e\x41\x80\x80\x80\x80\x80\x41");  //种子活用圆形图案填充
	else
		setfillstyle(BS_HATCHED, HS_DIAGCROSS);		//种子死用交叉填充
	fillrectangle(left, top, right, bottom);
}