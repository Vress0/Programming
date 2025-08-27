#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int s, max = 0, min = 1000, sum = 0;
    cin >> s;
    srand(s);
    int array[100];
    for (int i = 0; i < 100; i++){
        array[i] = rand() % (1000 - 100 + 1) + 100;
        if(array[i] > max){
            max = array[i];
        }
        if(array[i] < min){
            min = array[i];
        }
        sum += array[i];
    }
    cout << max << endl;
    cout << min << endl;
    double avg = sum / 100.0;
    cout << avg << endl;
    double SD = 0;
    for (int i = 0; i < 100; i++){
        SD += pow(array[i] - avg, 2);
    }
    SD = sqrt(SD / 100);
    cout << SD << endl;
    return 0;
}