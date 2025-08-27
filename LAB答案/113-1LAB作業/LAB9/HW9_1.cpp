#include<iostream>
using namespace std;

class basicTime{
    public:
        basicTime();
        void input();
        void output();
        void outputSecond();
    private:
        int hour;
        int minute;
        int second;
};
basicTime::basicTime(){
    hour = 0;
    minute = 0;
    second = 0;
}
void basicTime::input(){
    int h, m, s;
    cin >> h >> m >> s;
    if(h <= 23 && h >= 0){
        hour = h;
    }
    else{
        hour = 0;
    }
    if(m <= 59 && m >= 0){
        minute = m;
    }
    else{
        minute = 0;
    }
    if(s <= 59 && s >= 0){
        second = s;
    }
    else{
        second = 0;
    }
}
void basicTime::output(){
    if(hour < 10){
        cout << "0";
    }
    cout << hour << ":";
    if(minute < 10){
        cout << "0";
    }
    cout << minute << ":";
    if(second < 10){
        cout << "0";
    }
    cout << second << "\n";
}
void basicTime::outputSecond(){
    int totalSecond = 0;
    totalSecond += second;
    totalSecond += minute * 60;
    totalSecond += hour * 60 * 60;
    if(totalSecond < 10000){
        cout << "0";
    }
    cout << totalSecond << "\n";
}
int main(){
    int situation;
    basicTime bt;
    bool inLoop = true;
    while(inLoop){
        cin >> situation;
        switch (situation){
            case 1:
                bt.input();
                break;
            case 2:
                bt.output();
                break;
            case 3:
                bt.outputSecond();
                break;
            default:
                inLoop = false;
                break;
        }
    }
    return 0;
}