#include <iostream>
using namespace std;

int main(){
    int x, y, cnt = 0;
    cin >> x;
    int *array;
    array = new int[x];
    for (int i = 0; i < x; i++){
        cin >> array[i];
    }
    cin >> y;
    for (int i = 0; i < x; i++){
        if(array[i] == y){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}