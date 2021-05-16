#include <iostream>
#include "Header.h"
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;

//굳이 내가 왜 이 배열이 있는데 동적할당을 해서 변수에 넣고 출력을 하고있는걸까
char element_name[26][9] = { "수소", "헬륨", "규소", "탄소", "질소", "산소", "나트륨", "칼륨", "마그네슘",
"칼슘", "염소", "금", "은", "구리", "철", "알루미늄", "수은", "납", "인", "황", "아이오딘", "플루오린", "망가니즈", "바륨", "리튬", "스트론튬" };

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
		if (what == 0) { //이름으로 기호맞추기
			int len = strlen(element_name[index]) + 1;
			name = new char[len];
			strcpy(name, element_name[index]);

			len = strlen(element_symbol[index]) + 1;
			symbol = new char[len];
			strcpy(symbol, element_symbol[index]);

			cout << name << ": ";
			cin >> input;
			
			if (!strcmp(input, symbol)) { //sucsess to answer!
				cout << "정답!" << endl;
				j++;
				n_index[g_index] = index;
				g_index++;
				score += 10;
				delete[] name;
				delete[] symbol;
				continue;
			}
			else { //fail to answer......??!?!?!?!
				cout << "오답.. 정답은 " << symbol << "이었습니다!" << endl;
				j++;
				n_index[g_index] = index;
				g_index++;
				delete[] name;
				delete[] symbol;
				continue;
			}
		}
		else if (what == 1) { //기호로 이름맞추기
			int len = strlen(element_name[index]) + 1;
			name = new char[len];
			strcpy(name, element_name[index]);

			len = strlen(element_symbol[index]) + 1;
			symbol = new char[len];
			strcpy(symbol, element_symbol[index]);

			cout << symbol << ": ";
			cin >> input;

			if (!strcmp(input, name)) { //sucsess to answer!
				cout << "정답!" << endl;
				score += 10;
				j++;
				n_index[g_index] = index;
				g_index++;
				delete[] name;
				delete[] symbol;
				continue;
			}
			else { // fail to answer......?!?!?!??!?!
				cout << "오답.. 정답은 " << name << "이었습니다!" << endl;
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
	cout << "끝!! 점수는 " << score << "/100 이었습니다!";
	_sleep(5000);
}

int input::check(int count)
{
	for (int i = 0; i < 9; i++) {
		if (n_index[i] == count) return 0;
	}
	return 1;
}
