// GAME2001A1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "UnderArray.h"// UnderorderedArray.h not the correct file name
#include "SortingArray.h"

using namespace std;

int main() {
    cout << "Testing UnorderedArray:\n";
    UnderArray<int> uArr;
    uArr.Push(5);
    uArr.Push(2);
    uArr.Push(9);
    uArr.Push(1);

    for (int i = 0; i < uArr.GetSize(); i++) {
        cout << uArr[i] << " ";
    }
    cout << "\n";

    cout << "Testing OrderedArray (no duplicates):\n";
    SortingArray<int> oArr(2, false);
    oArr.Push(5);
    oArr.Push(2);
    oArr.Push(9);
    oArr.Push(1);
    oArr.Push(2); // ignored duplicate

    for (int i = 0; i < oArr.GetSize(); i++) {
       cout << oArr[i] << " ";
    }
    cout << "\n";

    return 0;
}