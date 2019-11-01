#ifndef LIFEGAME_H
#define LIFEGAME_H

//定义一个种子生命状况结构体
typedef struct _SSeed
{
    int Condition;		//用1表示存活，0表示死亡
}SSeed;

class LifeGame
{
private:
    int map_height;
    int map_width;
    SSeed* m_map1;		// 缓冲地图1
    SSeed* m_map2;		// 缓冲地图2
    SSeed* Current_Map; // 现在的地图
    SSeed* New_Map;		// 下一代地图
    void ChangeMap();						//地图换到下一代
    void Set_CurSeed(int x, int y, int condition);	//改变当前地图上种子状态的函数
    void Set_NewSeed(int x, int y, int condition);	//改变新地图上种子状态的函数
    int IsPosValid(int x, int y);					//判断输入的坐标位置是否有效，返回0无效1有效
    SSeed* GetSeed(SSeed* map, int x, int y)		//得到指定种子的位置指针
    {
        return map + (x-1) * map_width + (y-1);		//在一块连续内存里按行填充存储种子
    }
    int GetAroundSeed(int x, int y);				//返回周围生存种子的个数

public:
    LifeGame(int width = 5, int height = 5);
    ~LifeGame();
    void initall();									//把所有种子都重新变成死亡状态，初始化
    int GetSeedCondition(int x, int y);				//获得种子生存或是死亡状态,生存返回1，死亡返回0
    int SetSeedCondition(int x, int y, int condition);		//设置种子生存状态
    void NextGeneration();							//进入下一代
    void RandomInit();							//随机初始化
	int GetWidth() { return map_width; }		//返回种子地宽度
	int GetHeight() { return map_height; }		//返回种子地高度


};
#endif // LIFEGAME_H
