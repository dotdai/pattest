#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
	解题思路：
	* 使用数组（这里使用了vector）来存储树节点，因为在这道题目中需要层序遍历，而数组的存储就是层序存储。
		另外由于是完全二叉树，因此空间使用情况良好 
	* 首先将收集好的结点进行排序
	* 然后根据完全二叉树的性质在数组中重组二叉树
		* 找到树的根节点：计算出左树的结点数，加上起始节点，即为根节点
		* 将根节点放在合适的位置：由调用者给出，即若递归左子树，则为前结点的2倍位置，若为右子树，则为2倍加1
		* 递归左右子树 
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
