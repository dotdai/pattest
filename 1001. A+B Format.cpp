#include <stdio.h>
#include <string.h>

int main() {
	int a, b, flag = 0;
	char sum[10];
	scanf("%d %d", &a, &b);
	if (a + b < 0)  {
		printf("-");
		sprintf(sum, "%d", -(a + b));
	} else {
		sprintf(sum, "%d", a + b);
	}
	flag += strlen(sum)%3;
	for (int i = 0; i < strlen(sum); i++) {
		if (i % 3 == flag) {
			if (flag || i != flag) {
				printf(",");
			}
		} 
		printf("%c", sum[i]);
		
	}
	return 0;
} 
