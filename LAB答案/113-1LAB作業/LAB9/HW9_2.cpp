#include<iostream>
#include<cmath>
using namespace std;
class PrimeChecker{
    public:
        PrimeChecker();
        void setNumber(int n);
        bool isPrime();
    private:
        int number;
};
PrimeChecker::PrimeChecker(){
    number = 1;
}
void PrimeChecker::setNumber(int n){
    number = n;
}
bool PrimeChecker::isPrime(){
    if(number == 1){
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++){
        if(number % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int number = 0;
    PrimeChecker PC;
    while(true){
        cin >> number;
        if(number <= 0){
            break;
        }
        PC.setNumber(number);
        if(PC.isPrime()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}
