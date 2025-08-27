#include <iostream>
using namespace std;
class Accumulator{
    public:
        Accumulator(int cost);
        double getAverage();
    private:
        static int sumUp;
        static int count;
};

int Accumulator::sumUp = 0;
int Accumulator::count = 0;

Accumulator::Accumulator(int cost){
    count++;
    sumUp += cost;
}

double Accumulator::getAverage(){
    return (double)sumUp / count;
}

int main(){
    Accumulator theOne(0);
    int x;
    while(true){
        cin >> x;
        if(x > 0){
            Accumulator Ac(x);
        }
        else{
            cout << theOne.getAverage() << endl;
            break;
        }
    }
    return 0;
}