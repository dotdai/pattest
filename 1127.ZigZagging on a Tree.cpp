#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	struct Node *left, *right;
	int data;
}Node;

typedef Node *BiTree;

vector<int> inorder;
vector<int> postorder;
vector<int> levelorder;
BiTree btree;
int cnt;

void create_bitree(Node *&node, int start, int end) {
	if (start > end) {
		node = NULL;
		return;
	}
	int val = postorder[cnt--];
	node = new Node;
	node->data = val;
	int index = 0;
	for (int i = start; i <= end; i++) {
		if (inorder[i] == val) {
			index = i; break;
		}
	}
	create_bitree(node->right, index + 1, end);
	create_bitree(node->left, start, index - 1);
}

void level_travel() {
	vector<Node*> s1;
	vector<Node*> s2;
	s1.push_back(btree);
	while (s1.size() != 0) {
		while (s1.size() != 0) {
			Node *node = s1.back();
			s1.pop_back();
			levelorder.push_back(node->data);
			if (node->right != NULL) s2.push_back(node->right);
			if (node->left != NULL) s2.push_back(node->left);
		}
		while (s2.size() != 0) {
			Node *node = s2.back();
			s2.pop_back();
			levelorder.push_back(node->data);
			if (node->left != NULL) s1.push_back(node->left);
			if (node->right != NULL) s1.push_back(node->right);
		}
	}
}

int main1127() {
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		inorder.push_back(input);
	}
	for (int i = 0; i < n; i++) {
		cin >> input;
		postorder.push_back(input);
	}
	cnt = inorder.size()-1;
	create_bitree(btree, 0, inorder.size()-1);
	level_travel();

	for (int i = 0; i < levelorder.size()-1; i++) {
		cout << levelorder[i] << " ";
	}
	cout << levelorder.back();
	return 0;
}