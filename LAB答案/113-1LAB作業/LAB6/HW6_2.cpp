#include <iostream>
#include<cmath>
using namespace std;

bool isPrime (int num) {
	double x = sqrt(num);
	int i = 2;
	while(i <= x){
		if(num % i == 0){
			return false;
		}
		i++;
	}
	return true;
}

int main () {
	int n, maximum;
	cin >> n;
	for(int i = 2; i <= n; i++){
		if(isPrime(i)){
			maximum = i;
		}
	}
	cout << maximum << endl;
	return 0;
}
