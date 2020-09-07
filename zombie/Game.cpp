#include "Game.h"
#include<iostream>
#include<string>
using namespace std;
Game::Game() {

}//���캯��
Game::~Game() {
}//��������
//��ӡnpcs
void Game::printNpcs(int roomIndex) {
	int i = 0;
	for (i = 0; i < rooms[roomIndex].npcNum; i++) {
		cout << i + 1 << ".";
		showNpcName(rooms[roomIndex].npcs[i]);
		cout << endl;
	}
}
//��ʾ��ɫ���ϵ���Ʒ
void Game::printGoodsOfNpc(int npcIndex) {

}
//��ȡ�������
int Game::getUserInput() {

}
//��ȡ��ȷ���������
int Game::getUserInput(int min, int max) {
	int n = getUserInput();
	while (n<min || n>max)
		n = getUserInput();
	return n;
}
//��ȡ�������
//�洢�������
//������Ϸ����������������ı��ļ��е����ݶ��Ѿ�������ܱ�����
void Game::RunGame() {
	int nInput;
	//����ȷ�������ı��ļ������ݶ��Ѿ�������


	//��Ϸ����
	oGameEnv.eState = system_menu;
	iRunning = true;
	while (iRunning) {
		int i;

		switch (oGameEnv.eState) {
			//��ʾ��Ϸ�ı����ϵͳ�˵�
		case  system_menu:
			//����

			showBuffer(logoBuffer);
			systemOut("1.�µ��ó� 2.����Զ�� 3.�´���ս");
			nInput = getUserInput(1, 3);
			//������½���Ϸ
			if (nInput = 1 = 1) {
				systemHint("��ȡ������ݡ���");
				/*�����ȡʧ�ܣ�ֹͣ����
				if(!loadPlayerData(true)){
				iRunning=false;
				}
				*/
				cout << "������";
				showNpcDetail(0);//�����npc�������
				systemPause();
				oGameEnv.eState = player_adven;
			}
			//����Ƕ�ȡ�浵
			else if (nInput == 2) {

			}
			//���Ҫ�뿪��Ϸ
			else if (nInput == 4) {
				return;
			}
			break;
			//���ð��״̬
		case player_adven:
			//����
			showRoomDetail(oGameEnv.currentMap);//��ʾ�ص����ϸ��Ϣ
			showNpcDetail(0);//��ʾ��ɫ�ڵص������������������
			systemOut("1����̸		2���۲�		3������		4��ʰȡ		5����·		6��״̬		7��ϵͳ		8����ͼ")��

				nInput = getUserInput(1, 8);
			//���˽�̸
			if (nInput == 1) {

			}
			//�۲����
			else if (nInput == 2) {

			}
			//��������
			else if (nInput == 3) {

			}
			//ʰȡ
			else if (nInput == 4) {

			}
			//��·
			else if (nInput == 5) {

			}
			//״̬
			else if (nInput == 6) {

			}
			//ϵͳ
			else if (nInput == 7) {
			}
			//��ͼ
			else if (nInput == 8) {

			}
			break;
			//�鿴���״̬
		case player_state:
			systemHint("Ҫ�쿴ʲô��");
			systemOut("1������		2����Ʒ		3��װ��		4��ȡ��");
			nInput = getUserInput(1, 6);
			//���Ҫ�鿴����
			if (nInput == 1) {

			}
			//�鿴���ϵ���Ʒ
			else if (nInput == 2) {

			}
			//�鿴װ��
			else if (nInput == 3) {

			}
			//ȡ��
			else if (nInput == 4) {

			}
			//ѡ���ƶ���Ŀ�ĵ�
		case show_exit:
			systemHint("Ҫȥ���");
			//��ʾ����ȥ�ĵط�
			for (i = 0; i < rooms[oGameEnv.currentMap].exitNum; i++) {
				cout << (i + 1) << ".";
				showRoomName(rooms[oGameEnv.currentMap].exits[i]);
				cout << endl;
			}
			cout << i + 1 << ".ȡ��" << endl << endl;
			nInput = getUserInput(1, i + 1);
			//ȡ��
			if (nInput == i + 1)
				oGameEnv.eState = player_adven;
			//ת����Ŀ�ĵ�
			else {
				oGameEnv.currentMap = rooms[oGameEnv.currentMap].exits[nInput - 1];
				runScripts(rooms[oGameEnv.currentMap].enterScript);
				oGameEnv.eState = player_adven;
			}
			break;
			//���˽�̸
		case talk_with_npc:
			systemHint("Ҫ��˭��̸��");
			printNpcs(oGameEnv.currentMap);
			cout << i + 1 << ".ȡ��" << endl << endl;
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npcNum + 1);
			//ȡ��
			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			//��ѡ�е�����Ի�
			else {
				oGameEnv.currentNpc = rooms[oGameEnv.currentMap].npcs[nInput - 1];
				runScripts(npcs[oGameEnv.currentNpc].talkScript);
				if (oGameEnv.eState == talk_with_npc)
					oGameEnv.eState = player_adven;
			}
			//�۲����
		case watch_npc:
			systemHint("Ҫ�۲�˭��");
			printNpcs(oGameEnv.currentMap);
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npc + 1);
			//ȡ��
			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			//��ʵ�����˵�����
			else {
				showNpcDetail(rooms[oGameEnv.currentMap].npcs[nInput - 1]);
				systemPause();
				oGameEnv.eState = player_adven;
			}
			break;
			//��������
		case attack_npc:
			systemHint("Ҫ����˭��");
			printNpcs(oGameEnv.currentMap);
			nInput = getUserInput(1, rooms[oGameEnv.currentMap].npcNum + 1);

			if (nInput == rooms[oGameEnv.currentMap].npcNum + 1)
				oGameEnv.eState = player_adven;
			else {
				cout << "����";
				showNpcName(rooms[oGameEnv.currentMap].npcs[nInput - 1]);
				systemWarning("����ս����");
				initFight(rooms[oGameEnv.currentMap].npcs[nInput - 1]);//��ʼ��ս��
			}
			break;

			//ս������
		case fighting:
			int actRole;
			actRole = decideWhoAct();
			if (actRole == 0) {
				oGameEnv.eState = player_act;
			}
			else {

			}
			break;
			//�����ս�������е��ж�
		case player_act:
			systemHint("�ֵ����ж��ˣ�");
			showNpcDetail(0);
			systemOut("1.���� 2.��Ʒ 3.����");
			nInput = getUserInput(1, 3);
			if (nInput == 1)
				Act(0, oGameEnv.currentEnemy);
			else if (nInput == 2) {
				if (npcs[0].goodsNum == 0) {
					systemWarning("������û���κ���Ʒ��");
				}oGameEnv.eState = list_goods;
			}
			else if (nInput == 4)
				escapeOut(0, oGameEnv.currentEnemy);
			else systemWarning("û����ѡ�����������ѡ��");
			break;
			//��Ϸ�����е���ϵͳ�˵�
		case playing_sys_menu:
			systemHint("Ҫ��ʲô��");
			systemOut("1.�洢����\n2.��ȡ����\n3.���ر���\n4.������Ϸ");
			nInput = getUserInput(1, 4);
			if (nInput == 1) {

			}
			else if (nInput == 2) {

			}
			else if (nInput == 3) {
				oGameEnv.eState = player_adven;
			}
			break;
			//�鿴ӵ����Ʒ
		case list_goods:
			systemHint("Ҫʹ��ʲô��Ʒ");
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
			//ʹ����Ʒ
		case use_goods:
			showGoodsDetail(npcs[0].mygoods[oGameEnv.currentGoods]);
			systemOut("1.ʹ�� 2.���� 3.����");
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
				cout << "�ӵ���";
				showGoodsName(npcs[0].myGoods[oGameEnv.currentGoods]);
				cout << "��" << endl;
				systemPause();

				addGoodsToRoom(oGameEnv.currentMap, npcs[0].myGoods[oGameEnv.currentGoods]);
				removeGoods(0, oGameEnv.currentGoods, false);//??????
				oGameEnv.eState = list_goods;
			}
			else
				oGameEnv.eState = list_goods;
			break;
			//�г�����ʰȡ�Ķ���
		case list_free_item:
			systemHint("Ҫ����ʲô��");
			for (i = 0; i < rooms[oGameEnv.currentMap].goodsNum; i++) {
				cout << i + 1 << ".";
				showGoodsName(rooms[oGameEnv.currentMap].goods[i]);
				cout << "\t";
			}
			cout << i + 1 << ".ȡ��";
			nInput = getUserInput(1, i + 1);
			if (nInput == i + 1)
				oGameEnv.eState = player_adven;
			else {
				oGameEnv.currentGoods = nInput - 1;
				oGameEnv.eState = pick_item;
			}
			break;
			//ʰȡ
		case pick_item:
			showGoodsDetail(
				rooms[oGameEnv.currentMap].goods[oGameEnv.currentGoods]
			);
			systemOut("1.��ȡ 2.ȡ��");
			nInput = getUserInput(1, 2);
			if (nInput == 1) {
				pickGoods(0, oGameEnv.currentGoods);
				if (rooms[oGameEnv.currentMap].goodsNum == 0)
					oGameEnv.eState = player_adven;
				else oGameEnv.eState = list_free_item;
			}
			else oGameEnv.eState = list_free_item;
			break;
			//���װ�������
			//ж��װ��
			//����
			//������Ʒ
			//������Ʒ


		}



	}
}
//��ȡ��������
//��ʾ��������
void Game::showRoomName(int roomIndex) {
	cout << "[" << rooms[roomIndex].getName() << "]";
}
//��ʾ��������ϸ��Ϣ
void Game::showGoodsDetail(int roomIndex) {
	showRoomName(roomIndex);
	int i;
	cout << endl;
	cout << rooms[roomIndex].getScene() << endl;
	if (rooms[roomIndex].getNpcNum()) {
		cout << "����������У�";
		for (i = 0; i < rooms[roomIndex].getNpcNum(); i++) {
			showNpcName(rooms[roomIndex].getNpc(i));
			cout << "\t";
		}
		cout << endl;
	}
	if (rooms[roomIndex].getGoodsNum()) {
		cout << "������Լ�ȡ����Ʒ�У�";
		for (i = 0; i < rooms[roomIndex].getGoodsNum(); i++) {
			showGoodsName(rooms[roomIndex].getGoods(i));
			cout << "\t";
		}
		cout << endl;
	}
	if (rooms[roomIndex].getExitNum()) {
		cout << "�������ͨ��";
		for (i = 0; i < rooms[roomIndex].getExitNum(); i++) {

		}
	}
}

//��ʾ��Ʒ����
void Game::showGoodsName(int goodsIndex) {

}

//��ʾ��Ʒ����ϸ��Ϣ
void Game::showGoodsDetail(int goodsIndex) {

}
//����npc����
//��ͣ��Ϸ�����û�����
void Game::systemPause() {

}
//ϵͳ��Ϣ���
void Game::systemOut(string outString) {

}
//��ʾ��Ϣ���
void Game::systemHint(string hintString) {

}
//������Ϣ���������ͬ
void Game::systemWarning(string warningString) {

}
//��ʾ��ɫ����
void Game::showNpcName(int npcIndex) {

}
//��ʾ��ɫ��״̬
void Game::showNpcState(int npcIndex) {

}
//��ʾ��ɫ����������ϸ��Ϣ��
void Game::showNpcDetail(int npcIndex) {

}
//��ȡ��Դ�ļ���
//������Ʒ����
//���ؽű�����
