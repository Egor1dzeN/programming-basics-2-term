#include <iostream>
#include<vector>
#include<typeinfo>
using namespace std;

template<typename T>
class Vector{
private:
    vector<T> pVector;
public:
    Vector(int size = 1){
        pVector.reserve(size);

    }
    Vector(vector<T> v){
        pVector = v;
    }
    Vector operator +=(const T el){
        pVector.push_back(el);
        //cout<<"opa"<<endl;
        return Vector<T>(pVector);
    }
    T operator[](const int id){
        return pVector[id];
    }
    Vector operator -=(const T el){
        erase(pVector,el);
        return Vector<T>(pVector);
    }
    Vector operator *=(const T mnozh){
        for(int i = 0;i<pVector.size();++i){
            pVector[i]*=mnozh;
        }
        return Vector<T>(pVector);
    }



    void print(){
        for(auto el:pVector){
            cout<<el<<endl;
        }
    }
    vector<T> getVector(){
        return pVector;
    }
};
std::istream& operator >> (std::istream& in, Vector<int>& v){
    int el;
    in>>el;
    v+=el;
    return in;
}
std::ostream& operator << (std::ostream& ou, Vector<int>& v){
    for(auto el:v.getVector()){
        ou<<el<<endl;
    }
    return ou;
}

template<typename T>
class Matrix{
private:
    vector<Vector<T>> matrix;
public:
    Matrix(int size = 1){
        matrix.reserve(size);
    }
    Matrix(vector<Vector<T>> matrix1){
        matrix = matrix1;
    }
    void print(){
        for(int i =0;i<matrix.size();++i){
            Vector<T>v = matrix[i];
            cout<<"Vector - "<<i<<endl;
            v.print();
        }
    }
    Matrix operator +=(const Vector<T> v){
        matrix.push_back(v);
        return Matrix<T>(matrix);
    }
};



int main() {
    Vector<int> myVector(12);
    int c = 19;
    cin>>myVector;
    myVector*=2;
    cout<<myVector;
    Matrix<int> myMatrix;
    myMatrix+=myVector;
    myMatrix+=myVector;
    myMatrix.print();
    return 0;
}
