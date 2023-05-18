#include <iostream>
using namespace std;

class Array {
private:
    int *arr;
    int length;
public:
    Array(int capacity) {
        arr = new int[capacity];
        length = capacity;
    }
    Array(){
        arr = new int[1];
        length = 1;
    }

    void init() {
        cout<<"Length of array - "<<length<<endl;
        for (int i = 0; i < length; ++i) {
            cout<<"Enter the element "<<i+1<<": ";
            cin >> arr[i];
        }
    }

    void print() {
        for (int i = 0; i < length; ++i)
            cout << "Number of element "<<i + 1 << " - " << arr[i] << endl;
    }
};

void test() {
    int length;
    cout<<"Enter length of array - ";
    cin>>length;
    Array array = *new Array(length);
    array.init();
    array.print();
}


int main() {
    test();
    return 0;
}
