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
	int cnt = 1;//��ʼ1��������0.��Ϊ��һ������һ���Ǵ���1�ġ�
	for (int i = 0; i < n; i++)
	{
		if (inputs[i] > cnt)
			cnt++;
		else
		{
			break;
		}
	}
	cout << --cnt << endl;//��ʱ��cnt�Ƕ���1��Ҫ��ȥ

	return 0;
}