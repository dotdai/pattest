#include <stdio.h>
#include <stdlib.h> 

typedef struct Node {
	int exp;
	double coef;
} PolyNode, *Poly;

Poly ReadPoly(int len) {
	int i = 0;
	Poly p = (Poly)malloc(len*sizeof(PolyNode));
	for (i = 0; i < len; i++) {
		scanf("%d", &(p[i].exp));
		scanf("%lf", &(p[i].coef));
	}
	return p;
}

Poly Add(Poly p1, Poly p2, int len1, int len2, int &len) {
	int i = 0, j = 0;
	len = 0;
	Poly p3 = (Poly)malloc((len1+len2)*sizeof(PolyNode));
	while (i < len1 && j < len2) {
		if (p1[i].exp > p2[j].exp) {
			p3[len].exp = p1[i].exp;
			p3[len].coef = p1[i].coef;
			i++;
			len++;
		} else if(p1[i].exp < p2[j].exp) {
			p3[len].exp = p2[j].exp;
			p3[len].coef = p2[j].coef;
			j++;
			len++;
		} else {
			if (p1[i].coef + p2[j].coef == 0) {
				i++; j++;
				continue;
			}
			p3[len].exp = p1[i].exp;
			p3[len].coef = p1[i].coef + p2[j].coef;
			i++; j++;
			len++;
		}
	}
	while (i < len1) {
		p3[len].exp = p1[i].exp;
		p3[len].coef = p1[i].coef;
		i++;
		len++;
	}
	while (j < len2) {
		p3[len].exp = p2[j].exp;
		p3[len].coef = p2[j].coef;
		j++;
		len++;
	}
	return p3;
}

void Print(Poly p, int len) {
	printf("%d", len);
	for (int i = 0; i < len; i++) {
		printf(" %d %.1lf", p[i].exp, p[i].coef);
	}
	printf("\n");
}

int main() {
	int len1 = 0, len2 = 0, len3 = 0;
	scanf("%d", &len1);
	Poly p1 = ReadPoly(len1);
	scanf("%d", &len2);
	Poly p2 = ReadPoly(len2);
	Poly p3 = Add(p1, p2, len1, len2, len3);
	Print(p3, len3);
}
