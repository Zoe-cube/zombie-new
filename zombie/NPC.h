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
	string beWatched();//���۲�ʱ���ã������ű�
	void setMaxHp();//Ҳ����࣬��ʱ����
	void setHp();
	void setAttack();//�����������
	void setDefend();
	Goods getMyGoods();
	string getTalkScript();
	string getFailScript();
	void getAttacked();
	int getID() { return ID; }
	void addHp();//��Ʒbuff
	void addDef();//��Ʒ
	void addExp(); //��Ʒbuff���ֵõ� 

};

