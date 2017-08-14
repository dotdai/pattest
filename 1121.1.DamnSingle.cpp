#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <set>
using namespace std;

/* 找出不成对的元素 */
int main1121() {

	//freopen("in.txt", "r", stdin);
	int n, m;
	int p1, p2, p0;
	map<int, int> couples;		// 注册的情侣
	set<int> presents;			// 出席的人员

	cin >> n;
	int i;
	for (i = 0; i < n; ++i) {	// 把注册的情侣注册到map中，成对注册
		cin >> p1 >> p2;
		couples[p1] = p2;
		couples[p2] = p1;
	}

	cin >> m;
	set<int>::iterator set_p2;
	map<int, int>::iterator map_it;
	for (i = 0; i < m; ++i) {
		cin >> p0;
		map_it = couples.find(p0);						// 每参加一个人员，进行如下测试
		if (map_it == couples.end()) {					// 如果没有注册情侣，直接插入到集合中
			presents.insert(p0);
		}
		else {											// 如果已经注册过了
			set_p2 = presents.find(map_it->second);		// 查看对方是否已经来过
			if (set_p2 == presents.end()) {				// 如果对方没来过
				presents.insert(p0);					// 插入到集合中
			}
			else{										// 如果已经来过
				presents.erase(set_p2);					// 则删除
			}
		}
	}

	set<int>::iterator set_it;
	cout << presents.size() << endl;
	set_it = presents.begin();
	if (set_it != presents.end()) {
		cout << *set_it;
		while (++set_it != presents.end()) {
			cout << " " << *set_it;
		}
	}
	return 0;
}