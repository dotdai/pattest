#include <cstdio>
#include <cstdlib>
#include <memory.h>

int N,M,L,K;
int V1[10000],V2[10000],Test[10000];

bool IfCover();
void InitTest();

int main() {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &V1[i], &V2[i]);
	}
	scanf("%d", &L);
	for (i = 0; i < L; i++) {
		scanf("%d", &K);
		if (IfCover()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
} 

bool IfCover() {
	InitTest();
	bool flag = false;
	int input;
	for (int i = 0; i < K; i++) {
		scanf("%d", &input);
		Test[input] = true;
	}
	for (int i = 0; i < M; i++) {
		if (!Test[V1[i]] && !Test[V2[i]]) {
			return false;
		}
	}
	return true;
}

void InitTest() {
//	memset(Test, false, N*sizeof(bool));
	for (int i = 0; i < N; i++) {
		Test[i] = false;
	}
}
