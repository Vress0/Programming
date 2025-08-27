#include <iostream>
#include <cmath>
using namespace std;

double calculateStandardDeviation(int *array, int len){
    int sum = 0;
    for (int i = 0; i < len; i++){
        sum += array[i];
    }
    double avg = (double)sum / len;
    double SD = 0;
    for (int i = 0; i < len; i++){
        SD += pow(array[i] - avg, 2);
    }
    SD = sqrt(SD / len);
    return SD;
}

int main(){
    int currentSize = 10, len = 0, x;
    int *array;
    array = new int[currentSize];
    while(true){
        cin >> x;
        if(x == 0){
            break;
        }
        if(currentSize == len){
            int newSize = currentSize * 2;
            int *newArray = new int[newSize];
            for (int i = 0; i < currentSize; i++){
                newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;
            currentSize = newSize;
        }
        array[len] = x;
        len++;
    }
    double stdDev = calculateStandardDeviation(array, len);
    cout << stdDev << endl;
    delete[] array;
    return 0;
}