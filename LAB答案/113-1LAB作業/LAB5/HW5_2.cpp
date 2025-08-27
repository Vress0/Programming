#include<iostream>
using namespace std;

int main(){
	int n, sum;
	cin >> n;
	for(int i = 1; i <= n; i++){
		if(i % 11 == 0 && i % 23 == 0){
			sum +=i;
		}
	}
	
	cout << sum << endl;
	return 0;
}
