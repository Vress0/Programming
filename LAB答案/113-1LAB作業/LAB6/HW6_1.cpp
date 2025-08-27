#include<iostream>
#include<stdlib.h>
using namespace std;

int main () {
	int s, x;
	cin >> s >> x;
	srand(s);
	for(int i = 0 ; i < x; i++){
		int color = rand() % 4 + 1;
		int number = rand() % 13 + 1;
		switch (color) {
			case 1:
				cout << "S";
				break;
			case 2:
				cout << "H";
				break;
			case 3:
				cout << "D";
				break;
			case 4:
				cout << "C";
				break;
		}
		switch (number) {
			case 1:
				cout << "A";
				break;
			case 11:
				cout << "J";
				break;
			case 12:
				cout << "Q";
				break;
			case 13:
				cout << "K";
				break;
			default: 
				cout << number;
				break;
		}
		cout << endl;
	}
	return 0;
}
