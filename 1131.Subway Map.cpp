#include <cstdio> 
#include <cstdlib>
#include <cstring>
#include <deque>
#include <vector>
#include <memory.h>
using namespace std;
#define MAXSTATION 10000
#define MAXDISTANT 10000

int Line_Size;
int Station_Size;
vector<vector<int> > Lines;
vector<int> Stations[MAXSTATION];
int Query_Size;
int Min_Distant = MAXDISTANT;
int Path[MAXSTATION];
int PathLine[MAXSTATION]; 
int Dist[MAXSTATION];

void InitPath() {
	memset(Path, -1, MAXSTATION*sizeof(int));
}

void InitDist() {
	memset(Dist, -1, MAXSTATION*sizeof(int));
}

void HandleQuery() {
	InitPath();
	InitDist(); 
	int start, end;
	scanf("%d %d", &start, &end);
	deque<int> queue;
	queue.push_back(start);
	Dist[start] = 0;
	while (!queue.empty()) {
		int s = queue.front();
		for (int i = 0; i < Stations[s].size(); i++) {
			int line = Stations[s][i];
			for (int j = 0; j < Lines[line].size(); j++) {
				int st = Lines[line-1][j];
				if (st == end && Dist[s] < Min_Distant) {
					Min_Distant = Dist[s];
					Path[st] = s;
					PathLine[st] = line;
					break;
				}
				if (Dist[st] == -1) {
					Dist[st] = Dist[s] + 1;
					if (Stations[st].size() > 1) {
						Path[st] = s;
						queue.push_back(st);
					}
				}
			}
		}
		queue.pop_front();
	}
	
	int cur = end, mid = start;
	deque<int> pathline;
	while (Path[cur] != -1) {
		queue.push_back(cur);
		pathline.push_back(PathLine[cur]);
		cur = Path[cur];
	}
	
	while (!pathline.empty()) {
		printf("Take Line#%d from %d to %d.\n", pathline.back(), mid, queue.back());
		pathline.pop_back();
		mid = queue.back();
		queue.pop_back();
	}
}

int main() {
	scanf("%d", &Line_Size);
	for (int i = 1; i <= Line_Size; i++) {
		scanf("%d", &Station_Size);
		vector<int> L;
		int station;
		for (int j = 0; j < Station_Size; j++) {
			scanf("%d", &station);
			L.push_back(station);
			Stations[station].push_back(i);
		}
		Lines.push_back(L);
	}
	
	scanf("%d", &Query_Size);
	for (int i = 0; i < Query_Size; i++) {
		HandleQuery();
	}
}
