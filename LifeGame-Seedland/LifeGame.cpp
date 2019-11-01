#include<ctime>
#include<cstdlib>
#include"LifeGame.h"
using namespace std;

/*---------   Private   ----------*/

void LifeGame::Set_CurSeed(int x, int y, int condition)
{
    if (IsPosValid(x,y) == 0)
        return;
    SSeed* seed = GetSeed(Current_Map, x, y);
    if (seed - Current_Map > x * map_width + y * map_height) // 判断没有超出地图范围
        return;
    seed->Condition = condition;
}

void LifeGame::Set_NewSeed(int x, int y, int condition)
{
    if (IsPosValid(x, y) == 0)
        return;
    SSeed* seed = GetSeed(New_Map, x, y);
    if (seed - New_Map > x * map_width + y * map_height) // 判断没有超出地图范围
        return;
    seed->Condition = condition;
}

int LifeGame::IsPosValid(int x, int y)					//判断输入的坐标位置是否有效，返回0无效,1有效
{
    if (x > map_width || x<0 || y>map_height || y < 0)
        return 0;
    else
        return 1;
}

int LifeGame::GetAroundSeed(int x, int y)						//返回周围生存种子的个数
{
    int count = 0;
    if (IsPosValid(x, y) == 0)
        return -1;					//输入坐标无效
    for(int i = x-1; i<=x+1;i++)
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (i == x && j == y)
                continue;			//遍历到自己则不计数
            if (IsPosValid(i, j) == 1 && GetSeedCondition(i,j) == 1)
                count++;
        }
	return count;
}

void LifeGame::ChangeMap()					//地图换到下一代
{
    SSeed* ptemp = Current_Map;
    Current_Map = New_Map;
    New_Map = ptemp;
}

/*----------- Public --------------*/

LifeGame::LifeGame(int width, int height)
{
    map_width = width;
    map_height = height;
    m_map1 = (SSeed*) new SSeed[map_height * map_width];
    m_map2 = (SSeed*) new SSeed[map_height * map_width];
    Current_Map = m_map1;
    New_Map = m_map2;
    initall();
}

LifeGame::~LifeGame()
{

}

void LifeGame::initall()				//初始化，让所有种子死去
{
    if (Current_Map != NULL && New_Map != NULL)
    {
        for(int i=0;i<map_width;i++)
            for (int j = 0; j < map_height;j++)		//遍历整个地图
            {
                Set_CurSeed(i, j, 0);
                Set_NewSeed(i, j, 0);
            }
    }
}

int LifeGame::GetSeedCondition(int x, int y)		//返回某个种子的生存状况
{
    if (IsPosValid(x, y) == 0)
        return -1;
    SSeed* seed = GetSeed(Current_Map,x, y);
    return seed->Condition;
}

int LifeGame::SetSeedCondition(int x, int y, int condition)				//设置当前地图某个种子生存状况
{																		//返回负值则设置失败，返回0则设置成功
    if (IsPosValid(x, y) == 0)
        return -1;
    if (condition != 1 && condition != 0)
        return -2;
    SSeed* seed = GetSeed(Current_Map, x, y);
    seed->Condition = condition;
    return 0;
}

void LifeGame::RandomInit()							//随机生成种子的操作
{
    initall();
    srand((unsigned)time(NULL));
    for(int i=0;i<map_width;i++)
        for (int j = 0; j < map_height; j++)
        {
            int condition = rand() % 2;
            Set_CurSeed(i, j, condition);
        }
}

void LifeGame::NextGeneration()					//发展到下一代
{
    int NeighborNum = 0;
    for (int i = 0; i < map_width; i++)
        for (int j = 0; j < map_height; j++)
        {
            NeighborNum = GetAroundSeed(i, j);
            if (NeighborNum == 2)
                Set_NewSeed(i, j, GetSeedCondition(i, j));
            else if (NeighborNum == 3)
                Set_NewSeed(i, j, 1);
            else
                Set_NewSeed(i, j, 0);
        }
    ChangeMap();
}

