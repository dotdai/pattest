#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
	����˼·��
	* ʹ�����飨����ʹ����vector�����洢���ڵ㣬��Ϊ�������Ŀ����Ҫ���������������Ĵ洢���ǲ���洢��
		������������ȫ����������˿ռ�ʹ��������� 
	* ���Ƚ��ռ��õĽ���������
	* Ȼ�������ȫ�����������������������������
		* �ҵ����ĸ��ڵ㣺����������Ľ������������ʼ�ڵ㣬��Ϊ���ڵ�
		* �����ڵ���ں��ʵ�λ�ã��ɵ����߸����������ݹ�����������Ϊǰ����2��λ�ã���Ϊ����������Ϊ2����1
		* �ݹ��������� 
*/

vector<int> nodes;
vector<int> result;

int left_tree_num(int n) {
	int height = log(n) / log(2);
	int offset = n - pow(2, height)+1;
	offset = offset > pow(2, height-1) ? pow(2, height-1): offset;
	return pow(2, height-1)-1 + offset;
}

void rebuild_tree(int start, int end, int pos) {
	if (start > end) {
		return;
	}
	int head = left_tree_num(end-start+1) + start;
	result[pos] = nodes[head];
	int lpos = 2*pos+1;
	int rpos = lpos+1;
	rebuild_tree(start, head-1, lpos);
	rebuild_tree(head+1, end, rpos);
} 

int main1064() {
	int n, data;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> data;
		nodes.push_back(data);
	}
	sort(nodes.begin(), nodes.end());
	result.resize(n);
	rebuild_tree(0, n-1, 0);
	for (int i = 0; i < n-1; ++i) {
		cout << result[i] << " ";
	}
	cout << result.back();
	return 0;
} 
