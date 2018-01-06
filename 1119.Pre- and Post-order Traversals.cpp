#include <iostream>
#include <vector>

using namespace std;

vector<int> pre_order;
vector<int> post_order;
vector<int> in_order;
bool flag = false;

int find_interval(int start, int end, int rchild_root) {
	for (int i = start; i <= end; i++) {
		if (pre_order[i] == rchild_root) {
			return i;
		}
	}
	return -1;
}

void get_inorder(int pre_l, int pre_r, int post_l, int post_r) {
	if (pre_l > pre_r) {
		flag = true;
		return;
	}
	if (pre_l == pre_r) {
		in_order.push_back(pre_order[pre_l]);
		return;
	}
	int pre_mid = find_interval(pre_l, pre_r, post_order[post_r - 1]);
	if (pre_mid != -1) {
		get_inorder(pre_l + 1, pre_mid - 1, post_l, post_l + pre_mid - pre_l - 2);
		in_order.push_back(pre_order[pre_l]);
		get_inorder(pre_mid, pre_r, post_l + pre_mid - pre_l - 1, post_r-1);
	}
}

int main() {
	int n;
	cin >> n;
	pre_order.resize(n);
	post_order.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> pre_order[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post_order[i];
	}
	get_inorder(0, n-1, 0, n-1);

	if (flag) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	
	for (int i = 0; i < n-1; i++) {
		cout << in_order[i] << " ";
	}
	cout << in_order[n-1] << endl;
	return 0;
}