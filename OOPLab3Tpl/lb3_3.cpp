#include <iostream>


class Matrix{

    int** arr;
    int rows;
    int cols;
    int state;


    public:
    
    Matrix();
    Matrix(int n);
    Matrix(int n, int m, int value);
    Matrix(const Matrix& other);

    Matrix& operator=(const Matrix& other);

    ~Matrix(){
        for (int i = 0; i < rows; ++i){
            delete[] arr[i];
        }
        delete[] arr;
    }


    void setElement(int row, int col, int value = 0);
    int getElement(int row, int col);

    Matrix add(const Matrix& other) const;
    Matrix subtract(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;
    Matrix multiply(short scalar) const;

    void print() const;

    bool isEqual(const Matrix& other) const;
    bool isGreaterThan(const Matrix& other) const;
    bool isLessThan(const Matrix& other) const;

};


Matrix::Matrix() : Matrix(3, 3, 0) {}

Matrix::Matrix(int n) : Matrix(n, n, 0) {}

Matrix::Matrix(int n, int m, int value) : rows(n), cols(m), state(0){
    arr = new int*[rows];
    for (int i = 0; i < rows; ++i){
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            arr[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), state(0){
    arr = new int*[rows];
    for (int i = 0; i < rows; ++i){
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            arr[i][j] = other.arr[i][j];
        }
    }

}

Matrix& Matrix::operator=(const Matrix& other){
    if (this != &other){
        for (int i = 0; i < rows; ++i){
            delete[] arr[i];
        }
        delete[] arr;

        rows = other.rows;
        cols = other.cols;
        arr = new int*[rows];
        for (int i = 0; i < rows; ++i){
            arr[i] = new int[cols];
        }
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                arr[i][j] = other.arr[i][j];
            }
        }
    }
    return *this;
}

void Matrix::setElement(int row, int col, int value){
    if (row >= 0 && row < rows && col >= 0 && col < cols){
        arr[row][col] = value;
    } 
    else{
        state = 2;  
    }
}



int Matrix::getElement(int row, int col){
    if (row >= 0 && row < rows && col >= 0 && col < cols){
        return arr[row][col];
    }
    else{
        state = 2; 
        return 0;
    }
}


Matrix Matrix::add(const Matrix& other) const{
    Matrix result(*this); 
    if (rows == other.rows && cols == other.cols){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j){
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
            }
        }
    }
    else{
        result.state = 3;  
    }
    return result;
}


Matrix Matrix::subtract(const Matrix& other) const{
    Matrix result(*this);
    if (rows == other.rows && cols == other.cols){
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
            }
        }
        return result;
    } 
    else{
        result.state = 4;
    }
    return result;
}

Matrix Matrix::multiply(short scalar) const{
    Matrix result(*this);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            result.arr[i][j] = arr[i][j] * scalar;
        }
    }
    return result;
}

void Matrix::print() const{
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

bool Matrix::isEqual(const Matrix& other) const{
    if (rows == other.rows && cols == other.cols){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] != other.arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool Matrix::isGreaterThan(const Matrix& other) const{
    if (rows == other.rows && cols == other.cols){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] <= other.arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}

bool Matrix::isLessThan(const Matrix& other) const{
    if (rows == other.rows && cols == other.cols){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (arr[i][j] >= other.arr[i][j]){
                    return false;
                }
            }
        }
        return true;
    } 
    else{
        return false;
    }
}



int main() {
    Matrix mat1(2, 3, 1);
    Matrix mat2(2, 3, 2);

    mat1.print();
    std::cout << std::endl;

    mat2.print();
    std::cout << std::endl;

    Matrix resultAdd = mat1.add(mat2);
    resultAdd.print();
    std::cout << std::endl;


    Matrix resultSubtract = mat1.subtract(mat2);
    resultSubtract.print();
    std::cout << std::endl;


    Matrix resultMultiplyScalar = mat1.multiply(10);
    resultMultiplyScalar.print();
    std::cout << std::endl;

    if(mat1.isEqual(mat2)){
        std::cout << "Matrices are equal." << std::endl;
    } 
    else{
        std::cout << "Matrices are not equal." << std::endl;
    }

    if(mat1.isGreaterThan(mat2)){
        std::cout << "Matrix 1 is greater than Matrix 2." << std::endl;
    } 
    else{
        std::cout << "Matrix 1 is not greater than Matrix 2." << std::endl;
    }

    if(mat1.isLessThan(mat2)){
        std::cout << "Matrix 1 is less than Matrix 2." << std::endl;
    } 
    else{
        std::cout << "Matrix 1 is not less than Matrix 2." << std::endl;
    }

    return 0;
}

