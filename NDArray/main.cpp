// main.cpp
#include "NDArray.h"
#include <iostream>
using namespace std;

int main() {
    vector<int> shape = { 2, 2 };
    NDArray arr1(shape);
    NDArray arr2(shape);

    arr1.set({ 0, 0 }, 1.5f); arr1.set({ 0, 1 }, 2.5);
    arr1.set({ 1, 0 }, 6); arr1.set({ 1, 1 }, 4);

    arr2.set({ 0, 0 }, 5); arr2.set({ 0, 1 }, 6);
    arr2.set({ 1, 0 }, 7); arr2.set({ 1, 1 }, 8);

    cout << "Array 1:" << endl;
    arr1.print();

    cout << "Array 2:" << endl;
    arr2.print();

    NDArray result_add = arr1 + arr2;
    cout << "Result of addition:" << endl;
    result_add.print();

    NDArray result_mul = arr1 * arr2;
    cout << "Result of multiplication:" << endl;
    result_mul.print();

     vector<int> shape1 = { 2, 3 };
     vector<float> initData = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f };
     NDArray arr(shape1, initData);
     arr.print();

    return 0;
}
