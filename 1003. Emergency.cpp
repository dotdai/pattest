#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500
#define INFINITY 0x7fffffff
int Route[MAXSIZE][MAXSIZE];	// �ڽӾ���洢ͼ 
int dist[MAXSIZE];				// ����ʼ�㵽�������ľ��룬����Ѱ�����·�� 
int counts[MAXSIZE];			// ����ʼ�㵽��������ܹ��ռ������� 
int team[MAXSIZE];				// ÿ���ڵ������ 
int numroads[MAXSIZE];			// ����㵽�����������·�������� 
int N_Node, N_Vertex, Start, End;	// �ڵ���,����,��ʼ��,�յ� 

// ���������ʼ��ͼ 
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

// Ѱ�Ҿ����ռ��Ľ���·������� 
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
    else return -1;		// �����Ľ�㲻���ڣ��򷵻�-1 
}

// ���㷨 dijkstra 
void Emergency() {
	bool collected[MAXSIZE];	// ĳ�ڵ��Ƿ���ʹ� 
 	
 	// ��ʼ��������Ϣ 
    for ( int i = 0; i < N_Node; i++ ) {
        collected[i] = false;
        dist[i] = INFINITY;
        counts[i] = 0; 
    }
    
    counts[Start] = team[Start];	// ��S��㵽S������ռ�������ΪS�������� 
    dist[Start] = 0;				// ��S��㵽S���ľ���Ϊ0 
    numroads[Start] = 1;			// ��S��㵽S����·����Ϊ1 
    
    while (1) {
        int v = FindMinDist(collected);		// �ҵ������ռ��Ľ������Ľ�� 
        if (v < 0)							// �����Ľ�㲻���ڣ����˳�ѭ�� 
            break;
        collected[v] = true;				// ��Ƿ��� 
        
        for(int i = 0; i < N_Node; i++){	// ��v����ÿһ���ڽӵ���в��� 
        	if (collected[i]) continue;		// �ų����ʹ��Ľ�� 
        	if (Route[v][i] == INFINITY) continue;	// �ų����ڽӵ� 
            if (dist[v] + Route[v][i] < dist[i]) {	// ���ʹ�������� 
                dist[i] = dist[v] + Route[v][i];	// �޸ľ��� 
                counts[i] = counts[v] + team[i];	// �޸��ռ������� 
                numroads[i] = numroads[v];			// �޸�·������ 
            } else if (dist[v] + Route[v][i] == dist[i]) {	// ������벻�� 
            	if (counts[i] < counts[v] + team[i]) {		// ����ռ����������ӣ����޸� 
            		counts[i] = counts[v] + team[i];
				}
				numroads[i] += numroads[v];					// �޸�·������ 
			}
		}
    }
    
    printf("%d %d", numroads[End], counts[End]);
}

int main() {
	InitRoute();
	Emergency();
} 
