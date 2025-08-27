#include<iostream>
using namespace std;

class intList{
    public:
        intList();
        void insert(int value);
        bool remove(int pos);
        int getValue(int pos);
        bool setValue(int pos, int value);
        int getSize();
    protected:
        bool swapValue(int pos1, int pos2);
    private:
        int *data;
        int totalSize;
        int sizeUsed;
        void expandSize();
};

intList::intList(){
    totalSize = 1;
    data = new int[totalSize];
    sizeUsed = 0;
}

void intList::insert(int value){
    if(totalSize == sizeUsed){
        expandSize();
    }
    data[sizeUsed] = value;
    sizeUsed++;
}

bool intList::remove(int pos){
    if(pos > sizeUsed || pos < 1){
        return false;
    }
    int pose = data[pos - 1];
    cout << pose << endl;
    swapValue(pos, sizeUsed);
    sizeUsed--;
    return true;
}

int intList::getValue(int pos){
    return data[pos - 1];
}

bool intList::setValue(int pos, int value){
    if(pos > sizeUsed || pos < 1){
        return false;
    }
    data[pos - 1] = value;
    return true;
}

int intList::getSize(){
    return sizeUsed;
}

bool intList::swapValue(int pos1, int pos2){
    if(pos1 > sizeUsed || pos1 < 1 || pos2 > sizeUsed || pos2 < 1){
        return false;
    }
    int tmp = data[pos1 - 1];
    data[pos1 - 1] = data[pos2 - 1];
    data[pos2 - 1] = tmp;
    return true;
}

void intList::expandSize(){
    int *x;
    x = new int[2 * totalSize];
    for(int i = 0; i < totalSize;i++){
        x[i] = data[i];
    }
    for(int i = totalSize; i < 2 * totalSize;i++){
        x[i] = NULL;
    }
    delete[] data;
    totalSize *= 2;
    data = new int[totalSize];
    for (int i = 0; i < totalSize;i++){
        data[i] = x[i];
    }
    delete[] x;
}

int main(){
    int x;
    intList list;
    while(true){
        cin >> x;
        if(x == 0){
            break;
        }
        else if(x > 0){
            list.insert(x);
        }
        else{
            if(!list.remove(-x)){
                cout << "no" << endl;
            }
        }
    }
    return 0;
}