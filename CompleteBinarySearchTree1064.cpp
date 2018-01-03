#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int n, data;
	vector<int> nodes;
	int layer;
	int head;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> data;
		nodes.push_back(data);
	}
	layer = 1;
	int num = n;
	while (num > 1) {
		layer++;
		num /= 2;
	}
	head = (n+1)/2-1;
	int offset = n - pow(2, layer-1)+1;
	if (offset > pow(2, layer-2)) {
		offset = pow(2, layer-2);
	}
	head += offset;
	sort(nodes.begin(), nodes.end());
	
	int pre_last = head;
	for (int i = head)
} 
