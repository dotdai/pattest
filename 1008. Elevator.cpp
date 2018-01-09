#include <stdio.h> 

int abs(int a) {
	return a>0?a:-a;
}

int main() {
	int N, sum, prev, diff, next;
	scanf("%d", &N);
	sum = 0;
	prev = 0;
	while (N--) {
		scanf("%d", &next);
		diff = next - prev;
		if (diff > 0) {
			sum += abs(diff) * 6 + 5;
		} else {
			sum += abs(diff) * 4 + 5;
		}
		prev = next;
	}
	
	printf("%d", sum);
}
