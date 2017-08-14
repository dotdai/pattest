#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;

/* 找出不成对的元素 */
int main() {

	//freopen("in.txt", "r", stdin);
	int n, m;
	int p1, p2, p0;
	map<int, int> couples, attendence;		// 注册的情侣

	cin >> n;
	int i;
	for (i = 0; i < n; ++i) {	// 把注册的情侣注册到map中，成对注册
		cin >> p1 >> p2;
		couples[p1] = p2;
		couples[p2] = p1;
	}

	cin >> m;
	map<int, int>::iterator set_p2;
	map<int, int>::iterator map_it;
	for (i = 0; i < m; ++i) {
		cin >> p0;
		map_it = couples.find(p0);						// 每参加一个人员，进行如下测试
		if (map_it == couples.end()) {					// 如果没有注册情侣，直接插入到集合中
			attendence[p0] = -1;
		}
		else {											// 如果已经注册过了
			int flag = attendence[map_it->second];		// 查看对方是否已经来过
			if (flag != -1) {							// 如果对方没来过
				attendence[p0] = -1;					// 插入到集合中
			}
			else{										// 如果已经来过
				attendence[p0] = 1;						// 则删除
				attendence[map_it->second] = 1;
			}
		}
	}

	cout << 2*m - attendence.size() << endl;
	map_it = attendence.begin();
	if (map_it != attendence.end()) {
		while (map_it->second != -1) {
			++map_it;
		}
		cout << map_it->first;
		while (++map_it != attendence.end()) {
			if (map_it->second == -1)
			cout << " " << map_it->first;
		}
	}
	getchar();
	getchar();
	return 0;
}