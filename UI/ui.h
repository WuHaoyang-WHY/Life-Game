#pragma once
#ifndef UI_H
#define UI_H
#include"LifeGame.h"


class ui 
{
private:
	int ui_width, ui_height;  //���ڵĿ�͸ߵ�����
public:
	ui(int width = 640, int height = 480);
	RECT SetPressBotton(int left, int top, int right, int bottom);  // ���ð�ť����
	void SetText(RECT r,LPCTSTR str);	//��������
	void SetSeedLand(int left, int top, int right, int bottom,int SeedCondition);		//�������ӵط���

};

#endif // UI_H