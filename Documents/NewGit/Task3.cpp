#include <iostream>
using namespace std;

// Create first meta-function to remove modifiers: 
template <typename T>
struct RemoveMod{
    using type = T;
};

template <typename T>
struct RemoveMod<T *>{
    using type = typename RemoveMod<T>:: type;
};

template <typename T>
struct RemoveMod<const T>{
    using type = typename RemoveMod<T>:: type;
};

template <typename T, int N>
struct RemoveMod<const T[N]>{
    using type = typename RemoveMod<T>:: type;
};

template <typename T>
struct RemoveMod<T &>{
    using type = typename RemoveMod<T>:: type;
};


template <typename T, int N>
struct RemoveMod<T[N]>{
    using type = typename RemoveMod<T>:: type;
};

template <typename T>
struct RemoveMod<T[]>{
    using type = typename RemoveMod<T>:: type;
};
// Second meta - function to return true type
template<typename T>
struct ReturnTrueType{
    using type = typename RemoveMod<T>:: type;
};

int main(){
    using OrType = const int*[];
    using ResultTrueType = ReturnTrueType<OrType>:: type;

    cout << "Original Type: " << typeid(OrType).name() << endl;
    cout << "Remove Type: " << typeid(ResultTrueType).name() << endl;
}