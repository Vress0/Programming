#include<iostream>
#include<cmath>
using namespace std;

class BankAcc{
    private:
        double NTD;
        double USD;
        double EUD;
    public:
        BankAcc();
        BankAcc(double ntd, double usd, double eud);
        double getNTD();
        double getUSD();
        double getEUD();
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

const BankAcc operator +(BankAcc& Acc1, BankAcc& Acc2){
    double newNTD = Acc1.getNTD() + Acc2.getNTD();
    double newUSD = Acc1.getUSD() + Acc2.getUSD();
    double newEUD = Acc1.getEUD() + Acc2.getEUD();
    return BankAcc(newNTD, newUSD, newEUD);
}

const BankAcc operator -(BankAcc& Acc1, BankAcc& Acc2){
    double newNTD = Acc1.getNTD() - Acc2.getNTD();
    double newUSD = Acc1.getUSD() - Acc2.getUSD();
    double newEUD = Acc1.getEUD() - Acc2.getEUD();
    return BankAcc(newNTD, newUSD, newEUD);
}

const BankAcc operator %(BankAcc& Acc1, BankAcc& Acc2){
    double newNTD = abs(Acc1.getNTD() - Acc2.getNTD());
    double newUSD = abs(Acc1.getUSD() - Acc2.getUSD());
    double newEUD = abs(Acc1.getEUD() - Acc2.getEUD());
    return BankAcc(newNTD, newUSD, newEUD);
}

const BankAcc operator *(BankAcc& Acc1, BankAcc& Acc2){
    double newNTD = Acc1.getNTD() + Acc2.getNTD() * 0.99;
    double newUSD = Acc1.getUSD() + Acc2.getUSD() * 0.99;
    double newEUD = Acc1.getEUD() + Acc2.getEUD() * 0.99;
    return BankAcc(newNTD, newUSD, newEUD);
}

const BankAcc operator /(BankAcc& Acc1, BankAcc& Acc2){
    double newNTD = Acc1.getNTD() - Acc2.getNTD() * 1.01;
    double newUSD = Acc1.getUSD() - Acc2.getUSD() * 1.01;
    double newEUD = Acc1.getEUD() - Acc2.getEUD() * 1.01;
    return BankAcc(newNTD, newUSD, newEUD);
}

double BankAcc::getNTD(){
    return NTD;
}

double BankAcc::getUSD(){
    return USD;
}

double BankAcc::getEUD(){
    return EUD;
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
    double NTD1, USD1, EUD1;
    double NTD2, USD2, EUD2;
    cin >> NTD1 >> USD1 >> EUD1 >> NTD2 >> USD2 >> EUD2;
    BankAcc BA1(NTD1, USD1, EUD1);
    BankAcc BA2(NTD2, USD2, EUD2);
    BankAcc BA;
    BA = BA1 + BA2;
    BA.output();
    BA = BA1 - BA2;
    BA.output();
    BA = BA1 % BA2;
    BA.output();
    BA = BA1 * BA2;
    BA.output();
    BA = BA1 / BA2;
    BA.output();
    return 0;
}