#include <iostream>
using namespace std;

class solidClass{
    public:
        solidClass();
        solidClass(int x);
        solidClass(int x, int y, int z);
        int getVolume();
        int getSurfaceArea();
    private:
        int length;
        int width;
        int height;
};

solidClass::solidClass(){
    length = 1;
    width = 1;
    height = 1;
}

solidClass:: solidClass(int x){
    length = x;
    width = x;
    height = x;
}

solidClass::solidClass(int x, int y, int z){
    length = x;
    width = y;
    height = z;
}

int solidClass::getVolume(){
    return length * width * height;
}

int solidClass::getSurfaceArea(){
    return length * width * 2 + length * height * 2 + width * height * 2;
}

int main(){
    int x, y, z;
    while(true){
        cin >> x;
        if(x == 0){
            solidClass sc;
            cout << sc.getVolume() << " " << sc.getSurfaceArea() << endl;
        }
        else if(x > 0){
            cin >> y;
            if(y == 0){
                solidClass sc(x);
                cout << sc.getVolume() << " " << sc.getSurfaceArea() << endl;
            }
            else{
                cin >> z;
                solidClass sc(x, y, z);
                cout << sc.getVolume() << " " << sc.getSurfaceArea() << endl;
            }
        }
        else if(x == -1){
            break;
        }
    }
    return 0;
}