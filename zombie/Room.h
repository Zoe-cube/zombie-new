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
	int npcs[npcNum];//ÿ��npc��Ӧһ����ţ��� 
	int exits[npcNum];
	int goods[goodsNum];
	int enterScript;
	int leaveScript;  //������뿪����ʱ�Ľű�
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
	// ��ȡNPC����Ʒ�����ڶ�Ӧ��ţ�����ʲôNPC����Ʒ������ 
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
