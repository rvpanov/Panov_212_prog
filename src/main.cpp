#include "DynamicArray.h"
#include <new>
#include<string>

int main(){
    cout << "PART 4" << endl << endl;

    cout << "TEST OPERATOR[]" << endl << endl;

    DynamicArray<int> arrInt(3);
    arrInt[0] = 1;
    arrInt[1] = 2;
    arrInt[2] = 3;

    cout << arrInt << endl;
    cout << arrInt[1] << endl;

    try{
        arrInt[5] = 67;
    }catch(const out_of_range& e){
        cout << e.what() << endl;
    }

    try{
        arrInt[1] = 6767;
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }
    DynamicArray<int> arrInt2(3);
    arrInt2[0] = 1;
    arrInt2[1] = 2;
    arrInt2[2] = 3;

    if(arrInt == arrInt2){
        cout << "true" << endl;
    }else{
        cout << "false";
    }

    arrInt2[2] = 67;
    if(arrInt != arrInt2){
        cout << "true" << endl;
    }else{
        cout << "false";
    }

    arrInt += arrInt2;
    cout << arrInt << endl;

    arrInt -= 67;
    cout << arrInt << endl;

    for(const auto& x : arrInt2){
        cout << x << " ";
    }
    cout << endl;

    for(auto& x : arrInt2){
        x = x*2;
        cout << x << " ";
    }
    cout << endl;

    cout  << "distance: " << arrInt.distance(arrInt2) << endl << endl;

    cout << "STRING" << endl << endl;

    DynamicArray<string> arrStr(2);
    arrStr[0] = "Hello";
    arrStr[1] = "World";
    arrStr += "!!!";
    cout << arrStr << endl;

    DynamicArray<string> arrStr2(2);

    try{
        double d = arrStr.distance(arrStr2);
        cout << d;
    }catch(const bad_typeid& e){
        cout << e.what() << endl;
    }

    DynamicArray<int> arrInt3(2);

    arrInt3.set(0, 1);
    arrInt3.set(1, 2);

    try{
        double d = arrInt.distance(arrInt3);
        cout << d;
    }catch(const invalid_argument& e){
        cout << e.what() << endl;
    }

    return 0;
}
