#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
	����˼·��
	* ջ�д�������ڵ㣬��ջ��˳��Ϊ�������
	* ǰ���������֪�ģ�����ջ��˳��
	* ���������ǰ�򣬴�ӡ��������� 
*/
int num = 0;
vector<int> inorder;
vector<int> preorder;

// ����ǰ����������������ӡ�������
// start��end�ֱ���������������е�λ�� 
void post_order(int start, int end) {
	if (start > end) {
		return;
	}
	int val = preorder[num++];
	int index = 0;		// Ѱ��ǰ�������val����������е�λ�� 
	for (int i = start; i <= end; i++) {
		if (inorder[i] == val) {
			index = i;
			break;
		}
	}
	post_order(start, index-1);		// ���������� 
	post_order(index+1, end);		// ���������� 
	cout << val;					// ��ӡ�ڵ� 
	if (val != preorder[0] ) {
		cout << " ";
	}
}

int main() {
	int n;
	vector<int> input;
	string op;				// ���� 
	int data;				// ���� 
	
	cin >> n;
	for (int i = 0; i < 2*n; i++) {	 
		cin >> op;
		if (op == "Push") {
			cin >> data;
			input.push_back(data);
			preorder.push_back(data);		// ��¼ǰ����� 
		} else {
			inorder.push_back(input.back());// ��¼������� 
			input.pop_back();
		}
	}
	if (inorder.size() > 0) {
		post_order(0, inorder.size()-1);
	}
	return 0;
} 
