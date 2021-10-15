#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

int transform(int y) {
	return 250 - y;
};


int main() {
	initgraph(500, 500);
	int pointsnum = 0;
	int tmppositionX = 0;
	int tmppositionY = 0;
	int counts = 0;
	vector<int> x_row = { 0,100,200,300,400,500 };
	vector<int> realpositions;
	ifstream infile("file1.txt", ios::in);
	infile >> pointsnum;
	while (infile) {
		int tmpposition = 0;
		infile >> tmpposition;
		int realposition = transform(tmpposition);
		if (realpositions.size() == 6) {
			for (int i = 1; i < 6; i++) {
				realpositions[i - 1] = realpositions[i];
			}
			realpositions[5]=realposition;
		}
		else {
			realpositions.push_back(realposition);
		}
		int x0 = 500; int y0 = realposition;
		initgraph(500, 500);
		if (realpositions.size() == 1) {
			line(500, 250, x0, y0);
		}
		else {
			for (int i = 1; i < realpositions.size(); i++) {
				line(x0, y0, x_row[5-i], realpositions[realpositions.size()-i-1]);
				x0 = x_row[5-i];
				y0 = realpositions[realpositions.size()-i-1];
			}
		}

		Sleep(1000);

	}
	system("pause");
	closegraph();
	return 0;
}
