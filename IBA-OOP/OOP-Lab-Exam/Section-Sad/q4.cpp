#include <iostream>
#include <vector>

using std::vector;

class Matrix{
private:
    vector<vector<int>> data;
    size_t rows;
    size_t cols;
public:
    Matrix(size_t m, size_t n) : rows(m), cols(n){
        for (int i = 0; i < rows; ++i)
            data.emplace_back(cols, 0);
    };

    void Insert(const vector<vector<int>>& matrix){
        if (matrix.size() != rows || matrix[0].size() != cols){
            std::cout << "Invalid Dimensions\n";
            return;
        }
        data = matrix;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
        for (const auto& row : matrix.data){
            for (const auto& element : row){
                os << element << ' ';
            }
            os << '\n';
        }
        return os;
    }

    Matrix operator+(const Matrix& other) const {
        if (other.rows != rows || other.cols != cols){
            std::cout << "Invalid Dimensions\n";
            throw;
        }

        Matrix sum(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                sum.data[i][j] = data[i][j] + other.data[i][j];

        return sum;
    }

    Matrix operator-(const Matrix& other) const {
        if (other.rows != rows || other.cols != cols){
            std::cout << "Invalid Dimensions\n";
            throw;
        }

        Matrix difference(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                difference.data[i][j] = data[i][j] - other.data[i][j];

        return difference;
    }

    Matrix operator*(const Matrix& other) const {
        if (other.rows != cols || other.cols != rows){
            std::cout << "Invalid Dimensions\n";
            throw;
        }

        Matrix product(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < other.data.size(); ++k)
                    product.data[i][j] += data[i][k] * other.data[k][j];

        return product;
    }
};

int main(){
    Matrix A(2, 3);
    A.Insert({{1, 2, 3},
              {4, 5, 6}});

    Matrix B(2, 3);
    B.Insert({{4, 7, 9},
              {1, 5, 3}});

    Matrix C(3, 2);
    C.Insert({{7, 2},
              {6, 7},
              {5, 4}});

    std::cout << "Matrix A:\n" << A << '\n';
    std::cout << "Matrix B:\n" << B << '\n';
    std::cout << "Matrix C:\n" << C << '\n';

    std::cout << "A + B =\n" << (A + B) << '\n';
    std::cout << "A - B =\n" << (A - B) << '\n';
    std::cout << "A * C =\n" << (A * C) << '\n';

    return 0;
}