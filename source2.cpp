#include <iostream>
#include "Header.h"
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

//���� ���� �� �� �迭�� �ִµ� �����Ҵ��� �ؼ� ������ �ְ� ����� �ϰ��ִ°ɱ�
char element_name[26][9] = { "����", "���", "�Լ�", "ź��", "����", "���", "��Ʈ��", "Į��", "���׳׽�",
"Į��", "����", "��", "��", "����", "ö", "�˷�̴�", "����", "��", "��", "Ȳ", "���̿���", "�÷����", "��������", "�ٷ�", "��Ƭ", "��Ʈ��Ƭ" };

char element_symbol[26][12] = { "H", "He", "Si", "C", "N", "O", "Na", "K", "Mg", "Ca", "Cl", "Au", "Ag", "Cu", "Fe", "Al", "Hg",
"Pb", "P", "S", "I", "F", "Mn", "Ba", "Li", "Sr" };

int n_index[10];
int g_index = 0;
int score;

void input::myinput()
{
	for (int j = 0; j < 10;) {
		srand((unsigned)time(NULL));
		index = rand() % 26;
		if (!check(index)) continue;

		srand((unsigned)time(NULL));
		int what = rand() % 2; //1 or 0
		if (what == 0) { //�̸����� ��ȣ���߱�
			int len = strlen(element_name[index]) + 1;
			name = new char[len];
			strcpy(name, element_name[index]);

			len = strlen(element_symbol[index]) + 1;
			symbol = new char[len];
			strcpy(symbol, element_symbol[index]);

			cout << name << ": ";
			cin >> input;
			
			if (!strcmp(input, symbol)) { //sucsess to answer!
				cout << "����!" << endl;
				j++;
				n_index[g_index] = index;
				g_index++;
				score += 10;
				delete[] name;
				delete[] symbol;
				continue;
			}
			else { //fail to answer......??!?!?!?!
				cout << "����.. ������ " << symbol << "�̾����ϴ�!" << endl;
				j++;
				n_index[g_index] = index;
				g_index++;
				delete[] name;
				delete[] symbol;
				continue;
			}
		}
		else if (what == 1) { //��ȣ�� �̸����߱�
			int len = strlen(element_name[index]) + 1;
			name = new char[len];
			strcpy(name, element_name[index]);

			len = strlen(element_symbol[index]) + 1;
			symbol = new char[len];
			strcpy(symbol, element_symbol[index]);

			cout << symbol << ": ";
			cin >> input;

			if (!strcmp(input, name)) { //sucsess to answer!
				cout << "����!" << endl;
				score += 10;
				j++;
				n_index[g_index] = index;
				g_index++;
				delete[] name;
				delete[] symbol;
				continue;
			}
			else { // fail to answer......?!?!?!??!?!
				cout << "����.. ������ " << name << "�̾����ϴ�!" << endl;
				j++;
				n_index[g_index] = index;
				g_index++;
				delete[] name;
				delete[] symbol;
				continue;
			}
		}
		else {
			cout << "error!..in random calculate..";
			exit(0);
		}
		
	}
	cout << "��!! ������ " << score << "/100 �̾����ϴ�!";
	_sleep(5000);
}

int input::check(int count)
{
	for (int i = 0; i < 9; i++) {
		if (n_index[i] == count) return 0;
	}
	return 1;
}
