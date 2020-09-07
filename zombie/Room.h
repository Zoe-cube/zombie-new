#pragma once
#include<iostream>
#include<string>
using namespace std;
class Room
{
protected:
	string name;
	string scene;
	int npcNum;
	int exitNum;
	int goodsNum;
	int npcs[npcNum];//每个npc对应一个编号？？ 
	int exits[npcNum];
	int goods[goodsNum];
	int enterScript;
	int leaveScript;  //进入或离开房间时的脚本
public:
	Room(string name, string scene, int npcNum, int exitNum, int goodsNum
	);
	string getName() {
		return name;
	}
	string getScene() {
		return scene;
	}
	int getNpcNum() {
		return npcNum;
	}
	int getExitNum() {
		return exitNum;
	}
	int getGoodsNum() {
		return goodsNum;
	}
	// 获取NPC、物品、出口对应编号，即有什么NPC、物品、出口 
	int getNpcs(int iNpc) {
		return npcs[iNpc];
	}

	int getGoods(int iGoods) {
		return goods[iGoods];
	}
	int getExits(int iExit);


	void getEnterScript();
	void getLeaveScript();

};
