#include <iostream>
using namespace std;

// Create meta - function to calculate sum of sequence: 
template<int n, int k>
struct Power{
    static const int res = n * Power<n, k - 1>:: res;
};

// For case n ^ 0 = 1:
template<int n>
struct Power<n, 0>{
    static const int res = 1;
};

template<int n, int k>
struct SumofSeq{
    static const int value = Power<n, k>:: res + SumofSeq<n, k - 1>:: value;
};

// For case sequence has one element: 
template<int n>
struct SumofSeq<n, 0>{
    static const int value = 1;
};

int main(){
    cout << "Sum of Power sequence: "<< endl;
    cout << SumofSeq<1,8>:: value;
}