#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	double seg, chain;
	vector<double> segls;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seg;
		segls.push_back(seg);
	}
	sort(segls.begin(), segls.end());
	
	vector<double>::iterator it = segls.begin();
	if (it != segls.end()) {
		chain = *it++;
		while (it != segls.end()) {
			chain = floor(chain/2 + *it/2);
			it++;
		}
	}
	cout << chain << endl;
	return 0;
}