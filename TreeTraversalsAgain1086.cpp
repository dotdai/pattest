#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
	解题思路：
	* 栈中存放了树节点，出栈的顺序即为中序遍历
	* 前序遍历是已知的，即入栈的顺序
	* 根据中序和前序，打印出后序遍历 
*/
int num = 0;
vector<int> inorder;
vector<int> preorder;

void post_order(int start, int end) {
	if (start > end) {
		return;
	}
	int val = preorder[num++];
	int index = 0;
	for (int i = start; i <= end; i++) {
		if (inorder[i] == val) {
			index = i;
			break;
		}
	}
	post_order(start, index-1);
	post_order(index+1, end);
	cout << val;
	if (val != preorder[0] ) {
		cout << " ";
	}
}

int main() {
	int n;
	vector<int> input;
	string op;				// 操作 
	int data;				// 数据 
	
	cin >> n;
	for (int i = 0; i < 2*n; i++) {	 
		cin >> op;
		if (op == "Push") {
			cin >> data;
			input.push_back(data);
			preorder.push_back(data);
		} else {
			inorder.push_back(input.back());
			input.pop_back();
		}
	}
	if (inorder.size() > 0) {
		post_order(0, inorder.size()-1);
	}
	return 0;
} 
