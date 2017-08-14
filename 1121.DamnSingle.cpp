#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
using namespace std;

/* �ҳ����ɶԵ�Ԫ�� */
int main() {

	//freopen("in.txt", "r", stdin);
	int n, m;
	int p1, p2, p0;
	map<int, int> couples, attendence;		// ע�������

	cin >> n;
	int i;
	for (i = 0; i < n; ++i) {	// ��ע�������ע�ᵽmap�У��ɶ�ע��
		cin >> p1 >> p2;
		couples[p1] = p2;
		couples[p2] = p1;
	}

	cin >> m;
	map<int, int>::iterator set_p2;
	map<int, int>::iterator map_it;
	for (i = 0; i < m; ++i) {
		cin >> p0;
		map_it = couples.find(p0);						// ÿ�μ�һ����Ա���������²���
		if (map_it == couples.end()) {					// ���û��ע�����£�ֱ�Ӳ��뵽������
			attendence[p0] = -1;
		}
		else {											// ����Ѿ�ע�����
			int flag = attendence[map_it->second];		// �鿴�Է��Ƿ��Ѿ�����
			if (flag != -1) {							// ����Է�û����
				attendence[p0] = -1;					// ���뵽������
			}
			else{										// ����Ѿ�����
				attendence[p0] = 1;						// ��ɾ��
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