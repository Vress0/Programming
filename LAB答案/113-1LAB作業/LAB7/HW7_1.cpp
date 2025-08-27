#include <iostream>
using namespace std;

int main(){
    int array[25];
    for (int i = 0; i < 25; i++){
        cin >> array[i];
    }
    for (int i = 24; i >= 0; i--){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}