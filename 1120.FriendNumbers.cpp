#include "stdio.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

/* ������
   ��ν����������ÿλ��ӽ����ͬ����
   Aϰ�⼯ T1120
*/
int main() {
	int n;				// �������ݸ���				
	int val;			// ��������
	int sum;			// ÿ����͵Ľ��
	set<int> sum_set;	// ���������Ľ��

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> val;
		sum = 0;
		while (val) {			// ������ÿλ���
			sum += val % 10;
			val = val / 10;
		}
		sum_set.insert(sum);	// ���浽������
	}
	
	set<int>::iterator set_it = sum_set.begin();	// ��������������
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
