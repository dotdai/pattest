#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <set>
using namespace std;

/* �ҳ����ɶԵ�Ԫ�� */
int main1121() {

	//freopen("in.txt", "r", stdin);
	int n, m;
	int p1, p2, p0;
	map<int, int> couples;		// ע�������
	set<int> presents;			// ��ϯ����Ա

	cin >> n;
	int i;
	for (i = 0; i < n; ++i) {	// ��ע�������ע�ᵽmap�У��ɶ�ע��
		cin >> p1 >> p2;
		couples[p1] = p2;
		couples[p2] = p1;
	}

	cin >> m;
	set<int>::iterator set_p2;
	map<int, int>::iterator map_it;
	for (i = 0; i < m; ++i) {
		cin >> p0;
		map_it = couples.find(p0);						// ÿ�μ�һ����Ա���������²���
		if (map_it == couples.end()) {					// ���û��ע�����£�ֱ�Ӳ��뵽������
			presents.insert(p0);
		}
		else {											// ����Ѿ�ע�����
			set_p2 = presents.find(map_it->second);		// �鿴�Է��Ƿ��Ѿ�����
			if (set_p2 == presents.end()) {				// ����Է�û����
				presents.insert(p0);					// ���뵽������
			}
			else{										// ����Ѿ�����
				presents.erase(set_p2);					// ��ɾ��
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