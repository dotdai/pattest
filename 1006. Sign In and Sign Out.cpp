#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> records;
int M;

void InputData() {
	scanf("%d", &M);
	records.assign(86400, "");
	int i;
	string id;
	int h1, m1, s1, h2, m2, s2, idx;
	char c;
	for (i = 0; i < M; i++) {
		cin >> id >> h1 >> c >> m1>>c >> s1>> h2 >>c>> m2>>c >> s2;
		idx = h1*3600+m1*60+s1;
		records[idx] = id;
		idx = h2*3600+m2*60+s2;
		records[idx] = id;
	}
}

void OutEarlestAndLast() {
	int i,j;
	string e, l;
	for (i = 0; i < records.size(); i++) {
		if (records[i].size() != 0) {
			e = records[i]; break;
		}
	}
	
	for (j = records.size()-1; j >= 0; j--) {
		if (records[j].size() != 0) {
			l = records[j]; break;
		}
	}
	
	cout << e << ' ' << l;
}

int main() {
	InputData();
	OutEarlestAndLast();
}
