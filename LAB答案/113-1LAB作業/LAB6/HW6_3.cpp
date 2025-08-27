#include <iostream>
using namespace std;

void spaceStar (int space, int star) {
	for(int i = 0; i < space; i++) {
		cout << " ";	
	}
	for(int i = 0; i < star; i++) {
		cout << "*";
	}
	cout << endl;
	return;
}

int main () {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		spaceStar(n - i, 2 * i - 1);
	}
	return 0;
}
