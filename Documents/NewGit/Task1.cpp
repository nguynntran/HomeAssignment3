
#include <string>
#include <iostream>
#include <cmath>
 
template <typename T, size_t H, size_t W>
class matrix {
public:
    // Constructor:

    matrix() :mat(new T* [H])
    {
        for (size_t i = 0; i < H; ++i)
            mat[i] = new T[W];
 
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] = 0;
    }

    matrix(const T& num) :mat(new T* [H])
    {
        for (size_t i = 0; i < H; ++i)
            mat[i] = new T[W];
 
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] = num;
    }

    matrix(const matrix& other) :mat(new T* [H])
    {
        for (size_t i = 0; i < H; ++i)
            mat[i] = new T[W];
 
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] = other.mat[i][j];
    }
    // Getters:

    int getRow(){
        row = H;
        return row;
    }
    int getCol(){
        col = W;
        return col;
    }
    // Operator ():
    T& operator()(const size_t& i, const size_t& j)
    {
        return mat[i][j];
 
    }
    const T& operator()(const size_t& i, const size_t& j) const
    {
        return mat[i][j];
    }
 
    matrix& operator= (const matrix& other)
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] = other.mat[i][j];
        return *this;
    }
 
    // Operator + 

    matrix& operator+= (const matrix& other)
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] += other.mat[i][j];
        return *this;
    }

    matrix operator+ (const matrix& other)
    {
        matrix <T, H, W> result(0);
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
                return result;
    }
 
    // Operator -
    matrix& operator-= (const matrix& other)
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] -= other.mat[i][j];
        return *this;
    }

    matrix operator- (const matrix& other)
    {
        matrix <T, H, W> result(0);
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
        return result;
    }
 
    //Operator * (for scalar k)
    matrix& operator*= (const T& num)
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                mat[i][j] *= num;
        return *this;
    }

    matrix operator* (const T& num)
    {
        return matrix(*this) *= num;
    }
 
    // Operator * (for two matrix)
    template <size_t H2, size_t W2>
    matrix<T, H, W2> operator* (const matrix<T, H2, W2>& second)
    {
        matrix <T, H, W2> result(0);
        if (W == H2)
        {
            int i, j, k;
            for (i = 0; i < H; i++)
                for (j = 0; j < W2; j++)
                    for (k = 0; k < W; k++)
                        result.mat[i][j] += mat[i][k] * second.mat[k][j];
        }
        return result;
    }
    // Operator compare:
    bool operator== (const matrix& other)
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                if (mat[i][j] != other.mat[i][j])
                    return 0;
        return 1;
    }
    bool operator== (const matrix& other) const
    {
        for (size_t i = 0; i < H; i++)
            for (size_t j = 0; j < W; j++)
                if (mat[i][j] != other.mat[i][j])
                    return 0;
        return 1;
    }
    
    // Transposed matrix function: 
    matrix<T,W,H>  transposed() const {
        matrix <T, W, H> trp;
        for (int i = 0; i < H; ++i)
            for (int j = 0; j < W; ++j)
                trp.mat[j][i] = mat[i][j];
        return trp;
    }

    // Function print:
    void print()
    {
        for (size_t i = 0; i < H; i++)
        {
            for (size_t j = 0; j < W; j++)
            {
                std::cout << mat[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor:
    ~matrix()
    {
        for (size_t i = 0; i < H; i++)
            delete[] mat[i];
        delete[] mat;
    }

    // Create two dimensional array:
    T** mat = new T * [H];

private:
    int row,col;
};
// Specialization for matrix (n,1)

template<typename T, size_t N>
class matrix<T, 1, N> {
public:
    // Constructor: 
    matrix() :mat1(new T* [1])
    {
        for (size_t i = 0; i < 1; ++i)
            mat1[i] = new T[N];
 
        for (size_t i = 0; i < 1; i++){
            for (size_t j = 0; j < N; j++){
                mat1[i][j] = 0;
            }
        }
    }

    matrix(const T& num) :mat1(new T* [1])
    {
        for (size_t i = 0; i < 1; ++i)
            mat1[i] = new T[N];
 
        for (size_t i = 0; i < 1; i++){
            for (size_t j = 0; j < N; j++){
                mat1[i][j] = num;;
            }
        }
    }

    matrix(const matrix& other) :mat1(new T* [1])
    {
        for (size_t i = 0; i < 1; ++i)
            mat1[i] = new T[N];
 
        for (size_t i = 0; i < 1; i++){
            for (size_t j = 0; j < N; j++){
                mat1[i][j] = other.mat1[i][j];
            }
        }
    }
    // Operator: 
    T& operator() (const size_t &i, const size_t &j){
        return mat1[i][j];
    }

    matrix& operator= (const matrix& other){
        for (int i = 0; i < N; i++){
            mat1[0][i] = other.mat1[0][i];
        }
        return *this;
    }
    
    matrix operator+ (const matrix& other) {
    matrix<T,1,N> res(0);
    for (size_t i = 0; i < N; i++) {
        res.mat1[0][i] = mat1[0][i] + other.mat1[0][i];
    }
    return res;
    }

    matrix operator- (const matrix& other) {
    matrix<T,1,N> res(0);
    for (size_t i = 0; i < N; i++) {
        res.mat1[0][i] = mat1[0][i] - other.mat1[0][i];
    }
    return res;
    }

    matrix operator* (const T& k) {
    matrix<T,1,N> res(0);
    for (size_t i = 0; i < N; i++) {
        res.mat1[0][i] = mat1[0][i] * k;
    }
    return res;
    }

    // Fuction to calculate L2 Norm: 
    T& Norm(){
        T result = 0;
        for (size_t i = 0; i < N; i++){
            result += pow(mat1[0][i],2);
        }
        return result;
    }

    // Print Function:
    void print(){
        for (size_t i = 0; i < 1; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                std::cout << mat1[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor: 
    ~matrix()
    {
        for (size_t i = 0; i < 1; i++)
            delete[] mat1[i];
        delete[]mat1;
    }
    T** mat1 = new T * [N];
};


int main(){
    // General case:
    int x;
    matrix<int,2,3> mt1;
    std::cout <<"Input of matrix 1" << std::endl;
    for ( int i = 0; i < 2; i++){
        for ( int j = 0; j < 3; j++){
            std::cin>>x;
            mt1(i,j) = x;
        }
    }
    

    std::cout <<"Input of matrix 2" << std::endl;
    matrix<int,3,2> mt2;
    for ( int i = 0; i < 3; i++){
        for ( int j = 0; j < 2; j++){
            std::cin>>x;
            mt2(i,j) = x;
        }
    }

    std::cout <<"Matrix 1 is: "<< std::endl;
    mt1.print();

    std::cout <<"Matrix 2 is: "<< std::endl;
    mt2.print();

    matrix<int,2,2> mt3 = mt1 * mt2;
    std::cout <<"Matrix 1 x Matrix 2 is: " << std::endl;
    mt3.print();
    
    std::cout <<"Transpose matrix 1 x matrix 2 is: " << std::endl;
    matrix<int,2,2> mt = mt3.transposed();
    mt.print();
    
    //Specialization case: 
    matrix<int,1,3> mtx;
    matrix<int,1,3> mty;
    int y;
    std::cout<< "Input matrix X: "<< std::endl;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            std:: cin >> y;
            mtx(i,j) = y;
        }
    }
    
    std::cout<< "Input matrix Y: "<< std::endl;
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            std:: cin >> y;
            mty(i,j) = y;
        }
    }

    matrix<int,1,3> mtz = mtx + mty;
    std::cout << "The matrix (X + Y) is: "<< std::endl;
    mtz.print();
    std::cout << "L2 Norm is equal: "<< std::endl;
    std:: cout << mtz.Norm();
}