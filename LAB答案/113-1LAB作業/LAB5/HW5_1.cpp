#include<iostream>
using namespace std;

int main(){
	int year, month, day;
  	cin >> year >> month >> day;
  	if (month == 1 || month == 2){
  		month += 12;
		year--;	
	}
  	int c = year / 100, y = year % 100;
  	int w = (y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1) % 7;
  	w = (w % 7 + 7 ) % 7;
  	cout << w << endl;
  	return 0;
}
