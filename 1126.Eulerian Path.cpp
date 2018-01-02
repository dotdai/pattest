#include <iostream>
#include <vector>
#define MAXVE 501

using namespace std;

int graph[MAXVE][MAXVE];
int visited[MAXVE] = {0};
int cnt = 0;
int n_ve, n_ed;

void dfs(int);

int main1126() {
	vector<int> degreels;
	int end1, end2;
	int num_of_odd;
	cin >> n_ve >> n_ed;
	for (int i = 0; i < n_ve; i++) {
		for (int j = 0; j < n_ve; j++) {
			graph[i][j] = 0;
		}
	}

	for (int i = 0; i < n_ed; i++) {
		cin >> end1 >> end2;
		graph[end1][end2] = 1;
		graph[end2][end1] = 1;
	}
	int degree;
	num_of_odd = 0;
	for (int i = 1; i <= n_ve; i++) {
		degree = 0;
		for (int j = 1; j <= n_ve; j++) {
			if (graph[i][j] == 1) {
				degree++;
			}
		}
		cout << degree;
		if (i != n_ve) {
			cout << ' ';
		}
		else {
			cout << endl;
		}
		if (degree % 2 == 1) {
			num_of_odd++;
		}
	}

	dfs(1);
	if (cnt != n_ve) {
		num_of_odd = 1;
	}

	switch (num_of_odd)
	{
	case 0: cout << "Eulerian" << endl; break;
	case 2: cout << "Semi-Eulerian" << endl; break;
	default:
		cout << "Non-Eulerian" << endl; break;
		break;
	}
	return 0;
}

void dfs(int start)//µÝ¹é±éÀúÁ¬Í¨Í¼
{
	visited[start] = 1;
	cnt++;
	for (int i = 1; i <= n_ve; i++)
	{
		if (graph[start][i] == 1 && visited[i] == 0)
			dfs(i);
	}

	return;
}