#include <iostream>
using namespace std;

int main(){
    int s, max_cnt = 0, min_cnt = 100000, max, min;
    cin >> s;
    srand(s);
    int array[51];
    for (int i = 1; i <= 51;i++){
        array[i] = 0;
    }
    for (int i = 0; i < 100000;i++){
        int tmp = rand() % 50 + 1;
        array[tmp]++;
    }
    for (int i = 1; i <= 50;i++){
        if(array[i] > max_cnt){
            max = i;
            max_cnt = array[i];
        }
        else if(array[i] < min_cnt){
            min = i;
            min_cnt = array[i];
        }
    }
    cout << max << " " << max_cnt << endl;
    cout << min << " " << min_cnt << endl;
    return 0;
}