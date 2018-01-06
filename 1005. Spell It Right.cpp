#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// 获取输入 
void ReadData(char *nums) {
	scanf("%s", nums);
}

// 根据数字返回对应的单词 
void GetCharOfNum(int i, char *t) {
	switch (i) {
		case 0: sprintf(t, "zero"); break;
		case 1: sprintf(t, "one"); break;
		case 2: sprintf(t, "two"); break;
		case 3: sprintf(t, "three"); break;
		case 4: sprintf(t, "four"); break;
		case 5: sprintf(t, "five"); break;
		case 6: sprintf(t, "six"); break;
		case 7: sprintf(t, "seven"); break;
		case 8: sprintf(t, "eight"); break;
		case 9: sprintf(t, "nine"); break;
	}
}

void AddAndOutput(char *num) {
	int sum = 0;			// 保存累加和 
	char sumstr[100];		// 和字符串 
	
	// 累加求和 
	int len = strlen(num);
	char sc[2];
	for (int i = 0; i < len; i++) {
		sprintf(sc, "%c", num[i]);
		sum += atoi(sc);
	}
	
	// 输出对应单词 
	sprintf(sumstr, "%d", sum);
	len = strlen(sumstr);
	char t[6];
	for (int i = 0; i < len-1; i++) {
		sprintf(sc, "%c", sumstr[i]);
		GetCharOfNum(atoi(sc), t);
		printf("%s ", t);
	}
	GetCharOfNum(atoi(sumstr+len-1), t);
	printf("%s", t);
}

int main() {
	char nums[100];
	ReadData(nums);
	AddAndOutput(nums);
}
