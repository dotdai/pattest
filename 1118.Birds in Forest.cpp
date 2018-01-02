#include <iostream>
#include <map>

using namespace std;

// 并查集的应用
// 这里采用map作为实现

map<int, int> trees;

int find (int index) {	// 查找根节点
	if (trees[index] < 0) {
		return index;
	}
	else{
		return (trees[index] = find(trees[index]));	// 路径压缩
	}
}

void un(int root1, int root2) {	// 合并并查集
	if (trees[root1] < trees[root2]) { // 小集合并入大集合，按秩归并思想
		trees[root1] += trees[root2];
		trees[root2] = root1;
	}
	else {
		trees[root2] += trees[root1];
		trees[root1] = root2;
	}
}

int main() {
	int n, n_birds, index, first;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n_birds;
		cin >> first;	// 集合第一个元素特殊处理
		if (trees.find(first) == trees.end()) {
			trees.insert({ first, -1 });
		}
		for (int j = 0; j < n_birds-1; j++) {
			cin >> index;
			trees.insert({ index, -1 });
			un(find(first), find(index));
		}
	}

	int n_trees = 0;
	auto it = trees.cbegin();
	while (it != trees.end()) {
		if (it->second < 0) {
			++n_trees;
		}
		++it;
	}
	cout << n_trees << ' ' << trees.size() << endl;

	cin >> n;
	int b1, b2;
	for (int i = 0; i < n; i++) {
		cin >> b1 >> b2;
		if (find(b1) == find(b2)) {
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	return 0;
}