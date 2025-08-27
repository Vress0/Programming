#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	double x = sqrt(n);
	int i = 2;
	while(i <= x){
		if(n % i == 0){
			break;
		}
		i++;
	}
	if(i > x){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}
