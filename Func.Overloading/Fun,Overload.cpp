#include <iostream>

using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    void getElements() {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> imag;
    }

    void display() {
        if (imag == 0) {
            cout << real << endl;
        } else if (real == 0) {
            cout << imag << "i" << endl;
        } else if (imag < 0) {
            cout << real << " - " << -imag << "i" << endl;
        } else {
            cout << real << " + " << imag << "i" << endl;
        }
    }

    Complex operator +(const Complex& c) const {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    Complex operator *(const Complex& c) const {
        Complex result;
        result.real = real * c.real - imag * c.imag;
        result.imag = real * c.imag + imag * c.real;
        return result;
    }
};

int main() {
    Complex a, b, c, d;
    cout << "=== Complex Number 1 ===" << endl;
    a.getElements();
    a.display();
    cout << "\n=== Complex Number 2 ===" << endl;
    b.getElements();
    b.display();

    int choice;
    do {
        cout << "\nEnter the choice of problem:" << endl;
        cout << "1 - Add the complex numbers" << endl;
        cout << "2 - Multiply the complex numbers" << endl;
        cout << "3 - Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nThe sum is:" << endl;
                c = a + b;
                c.display();
                break;
            case 2:
                cout << "\nThe Multiplied Ans is:" << endl;
                d = a * b;
                d.display();
                break;
            case 3:
                cout << "\nExit" << endl;
                break;
            default:
                cout << "\nentered num is wrong." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
