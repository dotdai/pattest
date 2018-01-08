#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

int main() {
	int N;
	char input[33];
	int d1, d2, mid;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", &input);
		mid = strlen(input)/2;
		d2 = atoi(input+mid);
		d1 = atoi(input)/pow(10, mid);
		if (d1*d2) {
			if (atoi(input)%(d1*d2)) {
				printf("No\n");
			} else {
				printf("Yes\n");
			}
		} else {
			printf("No\n");
		}
		
	}
	return 0;
} 
