#include <iostream>
#include <vector>
using namespace std;

/*
	ȷ��һ�����������Ƿ����Ϊ��ջ˳��
	����˼·��
	�����д�1~n��������Ҫ������ջ����start������һ������ջ��Ԫ��
	��ʱջ�д��ڴ�1~top��Щ����
	����ȡ��һ������input
	 *�����Ҫ��ջ��������ݣ���input��start����
	 1.���������ݵĸ�������ջ�������������ݴ�start��input������ջ����󵯳�input
	 2.�������ջ���������ж������в������ջ˳��
	 *�������Ҫ��ջ��������ݣ�˵�������Ѿ���ջ�У���input��ջ��Ԫ��top���Ƚ�
	 1.�����ջ��Ԫ����ȣ����ջ��Ԫ��
	 2.�����ջ��Ԫ�ز��ȣ����ж������в������ջ˳��
	 
*/
int main() {
	int m, n, k;			// �ֱ�Ϊջ�ռ�/���ָ���/���и���
	vector<int> stack;		
	int start;				// ��ǰջ�洢�����������
	int input, top;			// �������ֺ�ջ��Ԫ��
	bool flag;				// ��ǰ�����Ƿ������ջ˳��
	cin >> m >> n >> k;		
	for (int i = 0; i < k; i++) {
		start = 0;				// ��ʼ������
		stack.clear();
		flag = true;
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (!flag) {
				continue;
			}
			int increment = input - start;		// �ж��Ƿ�Ҫ��ջ���������
			int capacity = m - stack.size();	// ����ջ�Ŀ��ÿռ�
			if (increment > 0) {
				if (increment <= capacity) {
					for (int l = start; l < input; l++) {
						stack.push_back(l + 1);
					}
					start = input;
					stack.pop_back();
				}
				else {
					flag = false;
					continue;
				}
			}
			else if (stack.back() == input) {
				stack.pop_back();
			} 
			else {
				flag = false;
				continue;
			}
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
