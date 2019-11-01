#pragma once
#ifndef UI_H
#define UI_H
#include"LifeGame.h"


class ui 
{
private:
	int ui_width, ui_height;  //窗口的宽和高的像素
public:
	ui(int width = 640, int height = 480);
	RECT SetPressBotton(int left, int top, int right, int bottom);  // 设置按钮方框
	void SetText(RECT r,LPCTSTR str);	//设置文字
	void SetSeedLand(int left, int top, int right, int bottom,int SeedCondition);		//设置种子地方格

};

#endif // UI_H