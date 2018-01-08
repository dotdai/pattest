#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500
#define INFINITY 0x7fffffff
int Route[MAXSIZE][MAXSIZE];	// 邻接矩阵存储图 
int dist[MAXSIZE];				// 从起始点到其他结点的距离，用于寻找最短路径 
int counts[MAXSIZE];			// 从起始点到其他结点能够收集的人数 
int team[MAXSIZE];				// 每个节点的人数 
int numroads[MAXSIZE];			// 从起点到其他结点的最短路径的条数 
int N_Node, N_Vertex, Start, End;	// 节点数,边数,起始点,终点 

// 根据输入初始化图 
void InitRoute() {
	scanf("%d %d %d %d", &N_Node, &N_Vertex, &Start, &End);
	for (int i = 0; i < N_Node; i++) {
		for (int j = 0; j < N_Node; j++) {
			Route[i][j] = INFINITY;
			if (i==j) Route[i][j] = 0;
		}
	}
	for (int i = 0; i < N_Node; i++) {
		scanf("%d", team+i);
	}
	int s, e, w;
	for (int i = 0; i < N_Vertex; i++) {
		scanf("%d %d %d", &s, &e, &w);
		Route[s][e] = w;
		Route[e][s] = w;
	}
} 

// 寻找距已收集的结点的路径最短者 
int FindMinDist(bool collected[]) {
	int MinV;
    int MinDist = INFINITY;
 
    for (int i=0; i < N_Node; i++) {
        if (collected[i]==false && dist[i]<MinDist) {
            MinDist = dist[i];
            MinV = i;
        }
    }
    if (MinDist < INFINITY)
        return MinV;
    else return -1;		// 这样的结点不存在，则返回-1 
}

// 主算法 dijkstra 
void Emergency() {
	bool collected[MAXSIZE];	// 某节点是否访问过 
 	
 	// 初始化数组信息 
    for ( int i = 0; i < N_Node; i++ ) {
        collected[i] = false;
        dist[i] = INFINITY;
        counts[i] = 0; 
    }
    
    counts[Start] = team[Start];	// 从S结点到S结点能收集的人数为S结点的人数 
    dist[Start] = 0;				// 从S结点到S结点的距离为0 
    numroads[Start] = 1;			// 从S结点到S结点的路径数为1 
    
    while (1) {
        int v = FindMinDist(collected);		// 找到据已收集的结点最近的结点 
        if (v < 0)							// 这样的结点不存在，则退出循环 
            break;
        collected[v] = true;				// 标记访问 
        
        for(int i = 0; i < N_Node; i++){	// 对v结点的每一个邻接点进行操作 
        	if (collected[i]) continue;		// 排除访问过的结点 
        	if (Route[v][i] == INFINITY) continue;	// 排除非邻接点 
            if (dist[v] + Route[v][i] < dist[i]) {	// 如果使距离缩短 
                dist[i] = dist[v] + Route[v][i];	// 修改距离 
                counts[i] = counts[v] + team[i];	// 修改收集的人数 
                numroads[i] = numroads[v];			// 修改路径条数 
            } else if (dist[v] + Route[v][i] == dist[i]) {	// 如果距离不变 
            	if (counts[i] < counts[v] + team[i]) {		// 如果收集的人数增加，则修改 
            		counts[i] = counts[v] + team[i];
				}
				numroads[i] += numroads[v];					// 修改路径条数 
			}
		}
    }
    
    printf("%d %d", numroads[End], counts[End]);
}

int main() {
	InitRoute();
	Emergency();
} 
