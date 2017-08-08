#include <iostream>
#include <vector>
#include <cmath>

#define exp 0.00001
using namespace std;

typedef struct {
	int expon;
	double coef;
}PolyNode;

vector<PolyNode> add(vector<PolyNode> poly1, vector<PolyNode> poly2) {
	int i = 0, j = 0;
	vector<PolyNode> poly3;
	while (i < poly1.size() && j < poly2.size()) {
		if (poly1[i].expon > poly2[j].expon) {
			poly3.push_back(poly1[i]); ++i;
		}
		else if (poly1[i].expon < poly2[j].expon) {
			poly3.push_back(poly2[j]); ++j;
		}
		else {
			PolyNode node;
			node.expon = poly1[i].expon;
			node.coef = poly1[i].coef + poly2[j].coef;
			if (abs(node.coef) < exp) {
				++i;++j;continue;
			}
			poly3.push_back(node);
			++i; ++j;
		}
	}
	while (i < poly1.size()) {
		poly3.push_back(poly1[i]); ++i;
	}
	while (j < poly2.size()) {
		poly3.push_back(poly2[j]); ++j;
	}
	return poly3;
}

vector<PolyNode> multi(PolyNode node, vector<PolyNode> poly) {
	vector<PolyNode> poly3;
	vector<PolyNode>::iterator it = poly.begin();
	for (; it != poly.end(); ++it) {
		PolyNode n;
		n.expon = (*it).expon + node.expon;
		n.coef = (*it).coef * node.coef;
		if (abs(n.coef) < exp) {
			++it;continue;
		}
		poly3.push_back(n);
	}
	return poly3;
}

int main() {
	int n;
	vector<PolyNode> poly1;
	vector<PolyNode> poly2;
	vector<PolyNode> result, temp;
	cin >> n;
	int expon;
	double coef;
	for (int i = 0; i < n; i++) {
		cin >> expon >> coef;
		PolyNode node;
		node.expon = expon;
		node.coef = coef;
		poly1.push_back(node);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> expon >> coef;
		PolyNode node;
		node.expon = expon;
		node.coef = coef;
		poly2.push_back(node);
	}
	if (poly1.size() == 0 || poly2.size() == 0) {
		printf("1 0 0.0");
		return 0;
	}
	for (int i = 0; i < poly1.size(); i++) {
		temp = multi(poly1[i], poly2);
		result = add(temp, result);
	}
	vector<PolyNode>::iterator it = result.begin();
	cout << result.size();
	while (it != result.end()) {
		printf(" %d %.1f", (*it).expon, (*it).coef);
		++it;
	}
	return 0;
} 
