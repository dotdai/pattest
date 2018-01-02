#include <iostream>
using namespace std;

typedef struct Node {
	struct Node *left, *right;
	int data;
} Node; 

Node *LL (Node *T) {
	Node *n = T->left;
	T->left = n->right;
	n->right = T;
	return n;
}

Node *RR (Node *T) {
	Node *n = T->right;
	T->right = n->left;
	n->left = T;
	return n;
}

Node *RL (Node *T) {
	T->right = LL(T->right);
	return RR(T);
}

Node *LR(Node *T) {
	T->left = RR(T->left);
	return LL(T);
}

int Max(int a, int b) {
	return a > b ? a : b;
}

int Height(Node *T) {
	if (T == NULL) {
		return 0;
	}
	else {
		return Max(Height(T->left), Height(T->right)) + 1;
	}
}

Node *Insert(Node *T, int val) {
	if (T == NULL) {
		T = new Node;
		T->data = val;
		T->left = T->right = NULL;
	}
	else if (val < T->data)
	{
		T->left = Insert(T->left, val);
		if (Height(T->left) - Height(T->right) == 2)
		{
			if (val < T->left->data)
				T = LL(T);
			else if (val > T->left->data)
				T = LR(T);
		}
	}
	else if (val > T->data)
	{
		T->right = Insert(T->right, val);
		if (Height(T->left) - Height(T->right) == -2)
		{
			if (val > T->right->data)
				T = RR(T);
			else if (val < T->right->data)
				T = RL(T);
		}
	}
	return T;
}

int main() {
	int n, data;
	Node *T = NULL;
	cin >> n;
	for (int i=0; i < n; i++) {
		cin >> data;
		T = Insert(T, data);
	}
	cout << T->data;
	return 0;
}
