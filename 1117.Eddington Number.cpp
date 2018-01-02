#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int n, max;
	cin >> n;
	vector<int> inputs(n);
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}
	sort(inputs.begin(), inputs.end(), greater<int>());
	int cnt = 1;//初始1，不能是0.因为第一天是有一天是大于1的。
	for (int i = 0; i < n; i++)
	{
		if (inputs[i] > cnt)
			cnt++;
		else
		{
			break;
		}
	}
	cout << --cnt << endl;//此时的cnt是多了1，要减去

	return 0;
}