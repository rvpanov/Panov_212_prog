#include "DynamicArray.h"
#include <utility>
#include<string>


void processArray(DynamicArray<int> arr) {
        cout << "size: " << arr.getSize() << endl;
} 

int main(){
    cout << "PART 5" << endl << endl;

    cout << "TEST OPERATOR=" << endl << endl;

    DynamicArray<int> arrInt(3);
    arrInt[0] = 1;
    arrInt[1] = 2;
    arrInt[2] = 3;
    DynamicArray<int> arrInt2(3);
    arrInt2[0] = 4;
    arrInt2[1] = 4;
    arrInt2[2] = 4;

    arrInt2 = arrInt;
    arrInt = arrInt;

    cout << arrInt2 << endl;
    cout << arrInt << endl;


    DynamicArray<int> arrInt3 = std::move(arrInt);
    cout << arrInt3 << endl;
    cout << "arrInt: "<< arrInt << "(obnulen)" << endl;

  
    DynamicArray<int> arrInt4(2);
    arrInt4[0] = 1;
    arrInt4[1] = 10;

    arrInt4 = std::move(arrInt3);

    cout << arrInt4 << endl;
    cout << "arrInt3: " << arrInt3 << " obnulen" << endl;


    cout << "Size arrInt4 begin: " << arrInt4.getSize() << endl;
    processArray(arrInt4);
    cout << "Size arrInt4 Last: " << arrInt4.getSize() << endl;

    cout << "Move" << endl;
    cout << "Size arrInt4 Begin: " << arrInt4.getSize() << endl;
    processArray(std::move(arrInt4));
    cout << "Size arrInt4 last: " << arrInt4.getSize() << endl;

}
