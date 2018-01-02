#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n, k;
	vector<int> stack;
	int start;
	int input, top;
	bool flag;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		start = 0;
		stack.clear();
		flag = true;
		for (int j = 0; j < n; j++) {
			cin >> input;
			//if (!flag) {
			//	continue;
			//}
			if (!stack.empty()) {
				top = stack.back();
			}
			int increment = input - start;
			int capacity = m - stack.size();
			if ((increment < 0 &&top != input) || increment > capacity) {
				flag = false;
				continue;
			}
			for (int l = start; l < input; l++) {
				stack.push_back(l + 1);
			}
			start = input > start ? input : start;
			stack.pop_back();
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	system("pause");
	return 0;
}
