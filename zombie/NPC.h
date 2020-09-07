#pragma once
#include<iostream>
#include<string>
#include"Weapon.h"
class NPC {
private:
	string name;
	string description;
	int ID;
	int maxHp;
	int hp;
	int attack;
	int defend;
	int exp;
	int goodsNum;
	Goods myGoods[goodsNum];
	string talkScript;
	string failScript;
public:
	string beWatched();//被观察时调用，弹出脚本
	void setMaxHp();//也许多余，暂时留着
	void setHp();
	void setAttack();//随机数（？）
	void setDefend();
	Goods getMyGoods();
	string getTalkScript();
	string getFailScript();
	void getAttacked();
	int getID() { return ID; }
	void addHp();//物品buff
	void addDef();//物品
	void addExp(); //物品buff或打怪得到 

};

