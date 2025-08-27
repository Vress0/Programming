#include <iostream>
#include <cmath>
using namespace std;

class myPrime{
    public:
        myPrime();
        myPrime(int x);
        void setNumber(int x);
        int getPrime();
        bool isPrime(int y);
        void next();

    private:
        int primeNumber;
};

myPrime::myPrime(){
    primeNumber = 2;
}

myPrime::myPrime(int x){
    setNumber(x);
}

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

void myPrime::next(){
    int tmp = primeNumber + 1;
    while(true){
        if(isPrime(tmp)){
            primeNumber = tmp;
            break;
        }
        tmp++;
    }
}

int main(){
    int n;
    cin >> n;
    if(n > 1){
        myPrime mp(n);
        int x;
        while(true){
            cin >> x;
            if(x > 1){
                for (int i = 0; i < x; i++){
                    mp.next();
                }
            }
            else if(x == 1){
                cout << mp.getPrime() << endl;
            }
            else{
                break;
            }
        }
    }
    else{
        myPrime mp;
        int x;
        while(true){
            cin >> x;
            if(x > 1){
                for (int i = 0; i < x; i++){
                    mp.next();
                }
            }
            else if(x == 1){
                cout << mp.getPrime() << endl;
            }
            else{
                break;
            }
        }
    }
    return 0;
}