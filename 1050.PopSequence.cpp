#include <iostream>
#include <vector>
using namespace std;

/*
	确定一个数字序列是否可以为出栈顺序
	核心思路：
	假设有从1~n个数字需要依次入栈，用start代表下一个将入栈的元素
	此时栈中存在从1~top这些数据
	假设取到一个数字input
	 *如果需要向栈中添加数据，即input比start大，则
	 1.如果添加数据的个数满足栈的容量，将数据从start到input依次入栈，最后弹出input
	 2.如果超出栈的容量，判定该序列不满足出栈顺序
	 *如果不需要向栈中添加数据，说明数据已经在栈中，则input和栈顶元素top做比较
	 1.如果和栈顶元素相等，则出栈该元素
	 2.如果和栈顶元素不等，则判定该序列不满足出栈顺序
	 
*/
int main() {
	int m, n, k;			// 分别为栈空间/数字个数/序列个数
	vector<int> stack;		
	int start;				// 当前栈存储过的最大数字
	int input, top;			// 输入数字和栈顶元素
	bool flag;				// 当前序列是否满足出栈顺序
	cin >> m >> n >> k;		
	for (int i = 0; i < k; i++) {
		start = 0;				// 初始化工作
		stack.clear();
		flag = true;
		for (int j = 0; j < n; j++) {
			cin >> input;
			if (!flag) {
				continue;
			}
			int increment = input - start;		// 判断是否要向栈中添加数据
			int capacity = m - stack.size();	// 计算栈的可用空间
			if (increment > 0) {
				if (increment <= capacity) {
					for (int l = start; l < input; l++) {
						stack.push_back(l + 1);
					}
					start = input;
					stack.pop_back();
				}
				else {
					flag = false;
					continue;
				}
			}
			else if (stack.back() == input) {
				stack.pop_back();
			} 
			else {
				flag = false;
				continue;
			}
		}
		if (flag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
