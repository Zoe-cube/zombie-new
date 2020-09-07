#pragma once
#include<iostream>
#include<string>
using namespace std;
class Weapon
{
protected:
	int price;
	int addAtk;
	int addDef;
	int addExp;
	int addHp;
	string name;
	string introduction;
public:
	Weapon(int price, int atk, int def, int exp, string name, string introduction);
	int getPrice() { return price; }
	int getAddAtk() { return addAtk; }
	int getAddDef() { return addDef; }
	int getAddExp() { return addExp; }
	int getAddHp() { return addHp; }
	string getName() { return name; }
	string getIntroduction() { return introduction; }
	/*
	virtual ~(){};
	*/

};
