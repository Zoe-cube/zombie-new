#pragma once
#include<iostream>
#include<string>
#include"Room.h"
#include"Weapon.h"
#include"Character.h"
using namespace std;
enum GAMESTATE {
	system_menu,//�µĺ��̣�����Զ�����´���ս��
	playing_sys_menu,//�洢���ȣ���ȡ���ȣ��뿪��Ϸ��
	player_adven,//���ð�գ���·����������̸��״̬����Ʒ������
	show_exit,//�����ѡ��ȥ����
	talk_with_npc,//�����ѡ���˭��̸
	attack_npc,//choose to attack which npc
	watch_npc,//choose to watch which npc
	player_state,//player watch state,skills,goods
	list_goods,//�о���ӵ����Ʒ
	list_skills,//list skills
	use_goods,
	use_skill,
	fighting,//ս����
	player_act,//�ֵ�����ж�
	list_free_item,//�г�����ʰȡ����Ʒ
	pick_item,
	check_equipment,
	un_equipment,//ж��װ��
	trading,//����
	buy_goods,//����Ʒ
	sell_goods,//����Ʒ
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
	void systemHint(const string hintString);//��ʾ
	void systemWarning(const string warningString);
	void systemPause();

	void printNpcs(int roomIndex);//��ӡĳ����������npc������
	void printGoodsOfNpc(int npcIndex);//��ʵ��ɫ�������е���Ʒ
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

	int experience(int npcIndex, int goodsIndex, int enemyIndex);//���㾭��
	int Damamge(int npcIndex, int enemyIndex);//�˺�
	void refresh(int npcIndex);//������ȫ��

	bool addNpc(int roomIndex, int nocIndex);
	bool removeNpc(int roomIndex, int npcIndex);
	void addMoney(int npcIndex, int money);
	bool delMoney(int npcIndex, int money);
	bool addGoods(int npcIndex, int gooods, bool visible);//������Ʒ
	bool removeGoods(int npcIndex, int goodsLocation, bool visible);//�Ƴ���Ʒ
	int haveGoods(int npcIndex, int goodsIndex);//�Ƿ�ӵ��ĳ����Ʒ
	int numOfGoods(int npcIndex, int goodsIndex);//ӵ��ĳ����Ʒ������
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
		GAMESTATE eState;//��Ϸ״̬
	}oGameEnv;





};
