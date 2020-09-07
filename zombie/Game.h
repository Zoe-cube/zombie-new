#pragma once
#include<iostream>
#include<string>
#include"Room.h"
#include"Weapon.h"
#include"Character.h"
using namespace std;
enum GAMESTATE {
	system_menu,//新的航程，继续远航，下次再战；
	playing_sys_menu,//存储进度，读取进度，离开游戏；
	player_adven,//玩家冒险：赶路，攻击，交谈，状态，物品，进度
	show_exit,//让玩家选择去哪里
	talk_with_npc,//让玩家选择和谁交谈
	attack_npc,//choose to attack which npc
	watch_npc,//choose to watch which npc
	player_state,//player watch state,skills,goods
	list_goods,//列举所拥有物品
	list_skills,//list skills
	use_goods,
	use_skill,
	fighting,//战斗中
	player_act,//轮到玩家行动
	list_free_item,//列出可以拾取的物品
	pick_item,
	check_equipment,
	un_equipment,//卸除装备
	trading,//交易
	buy_goods,//买物品
	sell_goods,//卖物品
};
class Game
{
public:
	Game();
	~Game();
	void RunGame();
	string getLogoBuffer() { return logoBuffer; }
	string getMapbuffer() { return mapBuffer; }
private:
	void showBuffer(string buffer);
	bool findScripts(int scriptsId);//find scripts whose id is identicial to that given
	void runScripts(int scriptsId);//run scripts

	void systemOut(const string outString);
	void systemHint(const string hintString);//提示
	void systemWarning(const string warningString);
	void systemPause();

	void printNpcs(int roomIndex);//打印某房间内所有npc的名字
	void printGoodsOfNpc(int npcIndex);//现实角色身上所有的物品
	void showNpcName(int npcIndec);
	void showNpcDetail(int npcIndex);
	void showNpcState(int npcIndex);
	void showRoomName(int roomIndex);
	void showRoomDetail(int roomIndex);
	void showGoodsName(int goodsIndex);
	void showGoodsDetail(int goodsIndex);

	void initFight(int npcIndex);
	void endFight(int endFight);
	int decideWhoAct();
	int useWhichGoods(int npcIndex);
	void Act(int npcIndex, int enemyIndex);
	void escapeOut(int npcIndex, int enemyIndex);

	int experience(int npcIndex, int goodsIndex, int enemyIndex);//计算经验
	int Damamge(int npcIndex, int enemyIndex);//伤害
	void refresh(int npcIndex);//生命力全满

	bool addNpc(int roomIndex, int nocIndex);
	bool removeNpc(int roomIndex, int npcIndex);
	void addMoney(int npcIndex, int money);
	bool delMoney(int npcIndex, int money);
	bool addGoods(int npcIndex, int gooods, bool visible);//增加物品
	bool removeGoods(int npcIndex, int goodsLocation, bool visible);//移除物品
	int haveGoods(int npcIndex, int goodsIndex);//是否拥有某种物品
	int numOfGoods(int npcIndex, int goodsIndex);//拥有某种商品的数量
	void eat(int npcIndex, int goodsIndex);
	void useGoods(int npcIndex, int gooodsLocation);
	void pickGoods(int npcIndex, int goodsLocation);
	void removeGoodsFromRoom(int roomIndex, int goodsLocation);
	void addGoodsToRoom(int roomIndex, int gooodsLocation);
	void buyGoods(int npcIndex, int goodsIndex);
	void sellGoods(int npcIndex, int goodsLocation);

	int getAddedAttack(int npcIndex);
	int getAddedDefened(int npcIndex);

	int getUserInput();
	int getUserInput(int min, int max);


private:
	bool iRunning;
	bool iRunningScripts;
	int roomNum;
	int npcNum;
	int skillNum;
	int goodsNum;
	HANDLE ConsoleHandle;

	Character* pCharacters;
	Room* pRooms;
	Weapon* pWeapons;

	string logoBuffer;
	string mapBuffer;

	struct gameEnvironment {
		int currentMap;
		int currentNpc;
		int currentEnemy;
		int currentGoods;
		bool bFighting;
		GAMESTATE eState;//游戏状态
	}oGameEnv;





};
