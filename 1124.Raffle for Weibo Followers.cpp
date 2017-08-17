#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main() {
	int total, skip, first;
	string user;
	set<string> winners;
	vector<string> winls;

	cin >> total >> skip >> first;
	int count = 0;
	if (first > total) {
		cout << "Keep going...";
		return 0;
	}
	for (int i = 0; i < first - 1; i++) {
		cin >> user;
	}
	count = skip - 1;
	for (int i = 0; i < total - first + 1; i++) {
		cin >> user;
		if (++count == skip) {
			if (winners.find(user) == winners.end()) {
				winners.insert(user);
				winls.push_back(user);
				count = 0;
				continue;
			}
			else {
				--count;
			}
		}
	}

	auto it = winls.begin();
	while (it != winls.end())
	{
		cout << *it++ << endl;
	}

	return 0;
}
