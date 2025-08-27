#include<iostream>
using namespace std;
class myDateTime{
    public:
        myDateTime();
        bool setTime(const int hour, const int min, const int sec);
        bool setDate(const int year, const int month, const int day);
        int whatDate();
        void output();
        void outputROC();
        int seconds();
        bool isLeap();
    private:
        int Year;
        int Month;
        int Day;
        int Hour;
        int Minute;
        int Second;
};
myDateTime::myDateTime(){
    Year = 1970;
    Month = 1;
    Day = 1;
    Hour = 0;
    Minute = 0;
    Second = 0;
}
bool myDateTime::setTime(const int hour, const int min, const int sec){
    if((hour > 23 || hour < 0) || (min < 0 || min > 59) || (sec < 0 || sec > 59)){
        Hour = 0;
        Minute = 0;
        Second = 0;
        return 0;
    }
    else{
        Hour = hour;
        Minute = min;
        Second = sec;
        return 1;
    }
}
bool myDateTime::setDate(const int year, const int month, const int day){
    if((year < 0) || (month < 1 || month > 12)){
        Year = 1900;
        Month = 1;
        Day = 1;
        return 0;
    }
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if(day < 1 || day > 31){
                Year = 1900;
                Month = 1;
                Day = 1;
                return 0;
            }
            break;
        case 4: case 6: case 9: case 11:
            if(day < 1 || day > 30){
                Year = 1900;
                Month = 1;
                Day = 1;
                return 0;
            }
            break;
        case 2:
            if(day < 1 || day > 29){
                Year = 1900;
                Month = 1;
                Day = 1;
                return 0;
            }
            break;
    }
    Year = year;
    Month = month;
    Day = day;
    return 1;
}
int myDateTime::whatDate(){
    int year = Year;
    int month = Month;
    int day = Day;
    if (month == 1 || month == 2){
  		month += 12;
		year--;	
	}
  	int c = year / 100, y = year % 100;
  	int w = (y + y / 4 + c / 4 - 2 * c + 26 * (month + 1) / 10 + day - 1) % 7;
  	w = (w % 7 + 7 ) % 7;
  	if(w == 0){
        return 7;
    }
    else {
        return w;
    }
}
void myDateTime::output(){
    bool isPM = false;
    int hour = Hour;
    if(Year < 10){
    	cout << "000";
	}
	else if(Year < 100){
		cout << "00";
	}
	else if(Year < 1000){
		cout << "0";
	}
    cout << Year << "-";
    if(Month < 10){
        cout << "0";
    }
    cout << Month << "-";
    if(Day < 10){
        cout << "0";
    }
    cout << Day << " ";
    if(hour >= 12){
        isPM = true;
        if(hour != 12){
        	hour -= 12;
		}
    }
    if(hour < 10){
        cout << "0";
    }
    cout << hour << ":";
    if(Minute < 10){
        cout << "0";
    }
    cout << Minute << ":";
    if(Second < 10){
        cout << "0";
    }
    cout << Second << " ";
    if(isPM){
        cout << "pm\n";
    }
    else{
        cout << "am\n";
    }
}
void myDateTime::outputROC(){
    int ROCyear = Year - 1911;
    int hour = Hour;
    cout << "中華民國";
    if(ROCyear < 10){
        cout << "00";
    }
    else if(ROCyear < 100){
    	cout << "0";
	} 
    cout << ROCyear << "年";
    if(Month < 10){
        cout << "0";
    }
    cout << Month << "月";
    if(Day < 10){
        cout << "0";
    }
    cout << Day << "日";
    if(hour >= 12){
        cout << "下午";
        if(hour != 12){
        	hour -= 12;
		}
    }
    else{
        cout << "上午";
    }
    if(hour < 10){
        cout << "0";
    }
    cout << hour << "時";
    if(Minute < 10){
        cout << "0";
    }
    cout << Minute << "分";
    if(Second < 10){
        cout << "0";
    }
    cout << Second << "秒\n";
}
int myDateTime::seconds(){
    int totalSecond = 0;
    totalSecond += Second;
    totalSecond += Minute * 60;
    totalSecond += Hour * 60 * 60;
    return totalSecond;
}
bool myDateTime::isLeap(){
    if((Year%4==0 && Year%100!=0) || Year%400==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int main(){
    int y, m, d, hr, min, sec;
    myDateTime DT;
    while(true){
        cin >> y >> m >> d >> hr >> min >> sec;
        if(y == 0 && m == 0 && d == 0 && hr == 0 && min == 0 && sec ==0){
            break;
        }
        DT.setDate(y, m, d);
        DT.setTime(hr, min, sec);
        DT.output();
        DT.outputROC();
        if(DT.isLeap()){
            cout << 1;
        }
        else{
            cout << 0;
        }
        switch(DT.whatDate()){
            case 1:
                cout << "Monday\n";
                break;
            case 2:
                cout << "Tuesday\n";
                break;
            case 3:
                cout << "Wednesday\n";
                break;
            case 4:
                cout << "Thursday\n";
                break;
            case 5:
                cout << "Friday\n";
                break;
            case 6:
                cout << "Saturday\n";
                break;
            case 7:
                cout << "Sunday\n";
                break;
        }
        cout << DT.seconds() << "\n";
    }
    return 0;
}

