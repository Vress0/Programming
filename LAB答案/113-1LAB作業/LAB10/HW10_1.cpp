#include <iostream>
#include <cmath>
using namespace std;

class myPrime{
    public:
        void setNumber(int x);
        int getPrime();
        bool isPrime(int y);

    private:
        int primeNumber;
};

void myPrime::setNumber(int x){
    if(isPrime(x)){
        primeNumber = x;
    }
    else{
        int tmp = x + 1;
        while(true){
            if(isPrime(tmp)){
                primeNumber = tmp;
                break;
            }
            tmp++;
        }
    }
}

int myPrime::getPrime(){
    return primeNumber;
}

bool myPrime::isPrime(int y){
    if(y == 1){
        return false;
    }
    for (int i = 2; i <= sqrt(y);i++){
        if(y % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int x;
    myPrime mp;
    while(true){
        cin >> x;
        if(x < 0){
            if(mp.isPrime(-x)){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
        else if(x > 0){
            mp.setNumber(x);
            cout << mp.getPrime() << endl;
        }
        else{
            break;
        }
    }
    return 0;
}