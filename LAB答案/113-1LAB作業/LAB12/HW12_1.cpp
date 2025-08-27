#include<iostream>
using namespace std;

class BankAcc{
    private:
        double NTD;
        double USD;
        double EUD;
    public:
        BankAcc();
        BankAcc(double ntd, double usd, double eud);
        double valueInNTD();
        double valueInUSD();
        double valueInEUD();
        void output();
};

BankAcc::BankAcc(){
    NTD = 0;
    USD = 0;
    EUD = 0;
}

BankAcc::BankAcc(double ntd, double usd, double eud){
    NTD = ntd;
    USD = usd;
    EUD = eud;
}

double BankAcc::valueInNTD(){
    double sum = NTD;
    sum += USD * 30;
    sum += EUD * 40;
    return sum;
}

double BankAcc::valueInUSD(){
    double sum = USD;
    sum += NTD / 30;
    sum += EUD * 40 / 30;
    return sum;
}

double BankAcc::valueInEUD(){
    double sum = EUD;
    sum += USD * 30 / 40;
    sum += NTD / 40;
    return sum;
}

void BankAcc::output(){
    cout << NTD << " " << USD << " " << EUD << endl;
}

int main(){
    double NTD, USD, EUD;
    cin >> NTD >> USD >> EUD;
    BankAcc BA(NTD, USD, EUD);
    cout << BA.valueInNTD() << " " << BA.valueInUSD() << " " << BA.valueInEUD() << endl;
    return 0;
}