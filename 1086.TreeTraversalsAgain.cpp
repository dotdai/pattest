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

// 根据前序遍历和中序遍历打印后序遍历
// start和end分别是中序遍历序列中的位置 
void post_order(int start, int end) {
	if (start > end) {
		return;
	}
	int val = preorder[num++];
	int index = 0;		// 寻找前序遍历中val在中序遍历中的位置 
	for (int i = start; i <= end; i++) {
		if (inorder[i] == val) {
			index = i;
			break;
		}
	}
	post_order(start, index-1);		// 遍历左子树 
	post_order(index+1, end);		// 遍历右子树 
	cout << val;					// 打印节点 
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
			preorder.push_back(data);		// 记录前序遍历 
		} else {
			inorder.push_back(input.back());// 记录中序遍历 
			input.pop_back();
		}
	}
	if (inorder.size() > 0) {
		post_order(0, inorder.size()-1);
	}
	return 0;
} 
