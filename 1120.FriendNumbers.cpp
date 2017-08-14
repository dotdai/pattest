#include "stdio.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

/* 求友数
   所谓的友数就是每位相加结果相同的数
   A习题集 T1120
*/
int main() {
	int n;				// 输入数据个数				
	int val;			// 输入数据
	int sum;			// 每次求和的结果
	set<int> sum_set;	// 保存友数的结果

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		sum = 0;
		while (val) {			// 将数据每位相加
			sum += val % 10;
			val = val / 10;
		}
		sum_set.insert(sum);	// 保存到集合中
	}
	
	set<int>::iterator set_it = sum_set.begin();	// 遍历集合输出结果
	cout << sum_set.size() << endl;
	if (set_it != sum_set.end()) {
		cout << *set_it;
		while (++set_it != sum_set.end()) {
			cout << " " << *set_it;
		}
	}
//	getchar();
//	getchar();
	return 0;
}
