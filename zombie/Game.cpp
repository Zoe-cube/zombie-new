#include "Game.h"
#include<iostream>
#include<string>
using namespace std;
Game::Game() {

}//构造函数
Game::~Game() {
}//析构函数
//打印npcs
void Game::printNpcs(int roomIndex) {
	int i = 0;
	for (i = 0; i < rooms[roomIndex].npcNum; i++) {
		cout << i + 1 << ".";
		showNpcName(rooms[roomIndex].npcs[i]);
		cout << endl;
	}
}
//显示角色身上的物品
void Game::printGoodsOfNpc(int npcIndex) {

}
//获取玩家输入
int Game::getUserInput() {

}
//获取正确的玩家输入
int Game::getUserInput(int min, int max) {
	int n = getUserInput();
	while (n<min || n>max)
		n = getUserInput();
	return n;
}
//读取玩家数据
//存储玩家数据
//运行游戏，这个函数必须在文本文件中的数据都已经读入才能被调用
void Game::RunGame() {
	int nInput;
	//首先确定所有文本文件的数据都已经被读入


	//游戏运行
	oGameEnv.eState = system_menu;
	iRunning = true;
	while (iRunning) {
		int i;

		switch (oGameEnv.eState) {
			//显示游戏的标题和系统菜单
		case  system_menu:
			//清屏

			showBuffer(logoBuffer);
			systemOut("1.新的旅程 2.继续远航 3.下次再战");
			nInput = getUserInput(1, 3);
			//如果是新建游戏
			if (nInput = 1 = 1) {
				systemHint("读取玩家数据……");
				/*如果读取失败，停止运行
				if(!loadPlayerData(true)){
				iRunning=false;
				}
				*/
				cout << "你名叫";
				showNpcDetail(0);//第零个npc就是玩家
				systemPause();
				oGameEnv.eState = player_adven;
			}
			//如果是读取存档
			else if (nInput == 2) {

			}
			//如果要离开游戏
			else if (nInput == 4) {
				return;
			}
			break;
			//玩家冒险状态
		case player_adven:
			//清屏
			showRoomDetail(oGameEnv.currentMap);//显示地点的详细信息
			showNpcDetail(0);//显示角色在地点的描述！！！？？？
			systemOut("1、交谈		2、观察		3、攻击		4、拾取		5、赶路		6、状态		7、系统		8、地图")；

				nInput = getUserInput(1, 8);
			//与人交谈
			if (nInput == 1) {

			}
			//观察别人
			else if (nInput == 2) {

			}
			//攻击别人
			else if (nInput == 3) {

			}
			//拾取
			else if (nInput == 4) {

			}
			//赶路
			else if (nInput == 5) {

			}
			//状态
			else if (nInput == 6) {

			}
			//系统
			else if (nInput == 7) {
			}
			//地图
			else if (nInput == 8) {

			}
			break;
			//查看玩家状态
		case player_state:
			systemHint("要察看什么？");
			systemOut("1、属性		2、物品		3、装备		4、取消");
			nInput = getUserInput(1, 6);
			//如果要查看属性
			if (nInput == 1) {

			}
			//查看身上的物品
			else if (nInput == 2) {

			}
			//查看装备
			else if (nInput == 3) {

			}
			//取消
			else if (nInput == 4) {

			}
			//选择移动的目的地
		case show_exit:
			systemHint("要去哪里？");
			//显示可以去的地方
			for (i = 0; i < rooms[oGameEnv.currentMap].exitNum; i++) {
				cout << (i + 1) << ".";
				showRoomName(rooms[oGameEnv.currentMap].exits[i]);
				cout << endl;
			}
			cout << i + 1 << ".取消" << endl << endl;
			nInput = getUserInput(1, i + 1);
			//取消
			if (nInput == i + 1)
				oGameEnv.eState = player_adven;
			//转换到目的地
			else {
				oGameEnv.currentMap = rooms[oGameEnv.currentMap].exits[nInput - 1];
				runScripts(rooms[oGameEnv.currentMap].enterScript);
				oGameEnv.eState = player_adven;
			}
			break;
			//和人交谈
		case talk_with_npc:
			systemHint("要和谁交谈？");
			printNpcs(oGameEnv.currentMap);
			cout << i + 1 << ".取消" << endl << endl;
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npcNum + 1);
			//取消
			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			//与选中的人物对话
			else {
				oGameEnv.currentNpc = rooms[oGameEnv.currentMap].npcs[nInput - 1];
				runScripts(npcs[oGameEnv.currentNpc].talkScript);
				if (oGameEnv.eState == talk_with_npc)
					oGameEnv.eState = player_adven;
			}
			//观察别人
		case watch_npc:
			systemHint("要观察谁？");
			printNpcs(oGameEnv.currentMap);
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npc + 1);
			//取消
			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			//现实对那人的描述
			else {
				showNpcDetail(rooms[oGameEnv.currentMap].npcs[nInput - 1]);
				systemPause();
				oGameEnv.eState = player_adven;
			}
			break;
			//攻击别人
		case attack_npc:
			systemHint("要攻击谁？");
			printNpcs(oGameEnv.currentMap);
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npcNum + 1);

			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			else {
				cout << "你与";
				showNpcName(rooms[oGameEnv.currentMap].npcs[nInput - 1]);
				systemWarning("进行战斗！");
				initFight(rooms[oGameEnv.currentMap].npcs[nInput - 1]);//初始化战斗
			}
			break;

			//战斗过程
		case fighting:
			int actRole;
			actRole = decideWhoAct();
			if (actRole == 0) {
				oGameEnv.eState = player_act;
			}
			else {

			}
			break;
			//玩家在战斗过程中的行动
		case player_act:
			systemHint("轮到你行动了！");
			showNpcDetail(0);
			systemOut("1.攻击 2.物品 3.逃走");
			nInput = getUserInput(1, 3);
			if (nInput == 1)
				Act(0, oGameEnv.currentEnemy);
			else if (nInput == 2) {
				if (npcs[0].goodsNum == 0) {
					systemWarning("你身上没有任何物品！");
				}oGameEnv.eState = list_goods;
			}
			else if (nInput == 4)
				escapeOut(0, oGameEnv.currentEnemy);
			else systemWarning("没有您选的那项，请重新选择！");
			break;
			//游戏过程中调出系统菜单
		case playing_sys_menu:
			systemHint("要做什么？");
			systemOut("1.存储进度\n2.读取进度\n3.返回标题\n4.继续游戏");
			nInput = getUserInput(1, 4);
			if (nInput == 1) {

			}
			else if (nInput == 2) {

			}
			else if (nInput == 3) {
				oGameEnv.eState = player_adven;
			}
			break;
			//查看拥有物品
		case list_goods:
			systemHint("要使用什么物品");
			printGoodsOfNpc(0);
			nInput = getUserInput(1, npcs[0].goodsNum + 1);
			if (nInput == npcs[0].goodsNum + 1) {
				if (oGameEnv.bFighting)
					oGameEnv.eState = player_act;
				else oGameEnv.eState = player_adven;
			}
			else {
				oGameEnv.currentGoods = nInput - 1;
				oGameEnv.eState = use_goods;
			}
			break;
			//使用物品
		case use_goods:
			showGoodsDetail(npcs[0].mygoods[oGameEnv.currentGoods]);
			systemOut("1.使用 2.丢弃 3.返回");
			nInput = getUserInput(1, 3);
			if (nInput == 1) {
				useGoods(0, oGameEnv.currentGoods);
				if (oGameEnv.bFighting)
					oGameEnv.eState = fighting;
				else
					oGameEnv.eState = list_goods;
			}
			else if (nInput == 2) {
				showNpcName(0);
				cout << "扔掉了";
				showGoodsName(npcs[0].myGoods[oGameEnv.currentGoods]);
				cout << "。" << endl;
				systemPause();

				addGoodsToRoom(oGameEnv.currentMap, npcs[0].myGoods[oGameEnv.currentGoods]);
				removeGoods(0, oGameEnv.currentGoods, false);//??????
				oGameEnv.eState = list_goods;
			}
			else
				oGameEnv.eState = list_goods;
			break;
			//列出可以拾取的东西
		case list_free_item:
			systemHint("要捡起什么？");
			for (i = 0; i < rooms[oGameEnv.currentMap].goodsNum; i++) {
				cout << i + 1 << ".";
				showGoodsName(rooms[oGameEnv.currentMap].goods[i]);
				cout << "\t";
			}
			cout << i + 1 << ".取消";
			nInput = getUserInput(1, i + 1);
			if (nInput == i + 1)
				oGameEnv.eState = player_adven;
			else {
				oGameEnv.currentGoods = nInput - 1;
				oGameEnv.eState = pick_item;
			}
			break;
			//拾取
		case pick_item:
			showGoodsDetail(
				rooms[oGameEnv.currentMap].goods[oGameEnv.currentGoods]
			);
			systemOut("1.捡取 2.取消");
			nInput = getUserInput(1, 2);
			if (nInput == 1) {
				pickGoods(0, oGameEnv.currentGoods);
				if (rooms[oGameEnv.currentMap].goodsNum == 0)
					oGameEnv.eState = player_adven;
				else oGameEnv.eState = list_free_item;
			}
			else oGameEnv.eState = list_free_item;
			break;
			//检查装备的情况
			//卸除装备
			//交易
			//购买物品
			//售卖物品


		}



	}
}
//读取场景数据
//显示场景名称
void Game::showRoomName(int roomIndex) {
	cout << "[" << rooms[roomIndex].getName() << "]";
}
//显示场景的详细信息
void Game::showGoodsDetail(int roomIndex) {
	showRoomName(roomIndex);
	int i;
	cout << endl;
	cout << rooms[roomIndex].getScene() << endl;
	if (rooms[roomIndex].getNpcNum()) {
		cout << "这里的人物有：";
		for (i = 0; i < rooms[roomIndex].getNpcNum(); i++) {
			showNpcName(rooms[roomIndex].getNpc(i));
			cout << "\t";
		}
		cout << endl;
	}
	if (rooms[roomIndex].getGoodsNum()) {
		cout << "这里可以捡取的物品有：";
		for (i = 0; i < rooms[roomIndex].getGoodsNum(); i++) {
			showGoodsName(rooms[roomIndex].getGoods(i));
			cout << "\t";
		}
		cout << endl;
	}
	if (rooms[roomIndex].getExitNum()) {
		cout << "这里可以通往";
		for (i = 0; i < rooms[roomIndex].getExitNum(); i++) {

		}
	}
}

//显示物品名称
void Game::showGoodsName(int goodsIndex) {

}

//显示物品的详细信息
void Game::showGoodsDetail(int goodsIndex) {

}
//加载npc数据
//暂停游戏，等用户输入
void Game::systemPause() {

}
//系统信息输出
void Game::systemOut(string outString) {

}
//提示信息输出
void Game::systemHint(string hintString) {

}
//警告信息输出，并赞同
void Game::systemWarning(string warningString) {

}
//显示角色姓名
void Game::showNpcName(int npcIndex) {

}
//显示角色的状态
void Game::showNpcState(int npcIndex) {

}
//显示角色的描述（详细信息）
void Game::showNpcDetail(int npcIndex) {

}
//读取资源文件名
//加载物品数据
//加载脚本数据
