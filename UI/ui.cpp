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

RECT ui::SetPressBotton(int left, int top, int right, int bottom)  //���ð�ť��
{
	setfillcolor(BLACK);	//���������ʽΪ��ɫ
	solidrectangle(left, top, right, bottom);
	RECT r = { left,top,right,bottom };
	return r;
}

void ui::SetText(RECT r , LPCTSTR string)	//�����ı�
{
	settextcolor(RED);
	drawtext(string, &r, DT_CENTER|DT_SINGLELINE|DT_VCENTER);
}

void ui::SetSeedLand(int left, int top, int right , int bottom, int SeedCondition)
{
	if (SeedCondition == 1)
		setfillstyle((BYTE*)"\x3e\x41\x80\x80\x80\x80\x80\x41");  //���ӻ���Բ��ͼ�����
	else
		setfillstyle(BS_HATCHED, HS_DIAGCROSS);		//�������ý������
	fillrectangle(left, top, right, bottom);
}