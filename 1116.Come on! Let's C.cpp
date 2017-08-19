#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> contestants;

bool is_prime_num(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void award(string id) {
	int rank = contestants[id];
	if (rank == -1) {
		cout << id << ": " << "Checked" << endl;
	}
	else if (rank == 1) {
		cout << id << ": " << "Mystery Award" << endl;
	}
	else if (is_prime_num(rank)) {
		cout << id << ": " << "Minion" << endl;
	}
	else {
		cout << id << ": " << "Chocolate" << endl;
	}
}

int main1116(){
	int n;
	string input;
	int rank;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		contestants.insert({ input, i + 1 });
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (contestants.find(input) == contestants.end()) {
			cout << input << ": " << "Are you kidding?" << endl;
		}
		else {
			award(input);
			contestants[input] = -1;
		}
	}
	return 0;
}