#include <iostream>
#include <limits>
#include <stdexcept>
using namespace std;

class Matrix {
  private:
    int **data;
    int rows;
    int cols;

  public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int *[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        cout << "Enter value of the matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument("Invalid input.");
                }
            }
        }
    }

    void display() const {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Can't Add.");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw invalid_argument("Can't Multiply.");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns of matrix 1:\n";
    cin >> rows1 >> cols1;
    Matrix matrix1(rows1, cols1);
    matrix1.input();

    cout << "Enter the number of rows and columns of matrix 2:\n";
    cin >> rows2 >> cols2;
    Matrix matrix2(rows2, cols2);
    matrix2.input();

    try {
        Matrix sum = matrix1 + matrix2;
        sum.display();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        Matrix product = matrix1 * matrix2;
        product.display();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const bad_alloc& e) {
        cout << "Error: " << e.what() <<endl;
    }
    return 0;
}
