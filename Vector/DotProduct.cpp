#include <iostream>
using namespace std;

class Vector {
private:
    float i_comp, j_comp, k_comp;

public:
    friend float operator*(Vector &a, Vector &b);
    friend istream& operator>>(istream &in, Vector &a);
    friend ostream& operator<<(ostream &out, Vector &a);
};

float operator*(Vector& a, Vector& b) {
    return (b.i_comp * a.i_comp) + (b.j_comp * a.j_comp) + (b.k_comp * a.k_comp);
}

istream& operator>>(istream &in, Vector& a) {
    cout << "Enter the i value: ";
    in >> a.i_comp;

    cout << "Enter the j value: ";
    in >> a.j_comp;

    cout << "Enter the k value: ";
    in >> a.k_comp;

    return in;
}

ostream& operator<<(ostream &out , Vector& a) {
    out << "Vector : ";

    if ((a.j_comp >= 0) && (a.k_comp >= 0))
        out << a.i_comp << "i + " << a.j_comp << "j + " << a.k_comp << "k " << endl;
    else {
        if ((a.j_comp < 0) && (a.k_comp < 0))
            out << a.i_comp << "i " << a.j_comp << "j " << a.k_comp << "k " << endl;
        else if (a.j_comp < 0)
            out << a.i_comp << "i " << a.j_comp << "j + " << a.k_comp << "k " << endl;
        else
            out << a.i_comp << "i + " << a.j_comp << "j " << a.k_comp << "k " << endl;
    }

    return out;
}

int main() {
    int choice;

    do {
        cout << "Enter 1 to start or any other number to quit: ";
        cin >> choice;

        if (choice != 1) {
            break;
        }

        Vector v1, v2;

        cout << "Enter values of Vector 1: " << endl;
        cin >> v1;

        cout << "Enter values of Vector 2: " << endl;
        cin >> v2;

        cout << v1;
        cout << v2;

        int choice2;

        cout << "Enter 2 to find the dot product of these 2 vectors or any other number to exit: " << endl;
        cin >> choice2;

        if (choice2 == 2) {
            float product = v1 * v2;
            cout << "The dot product is: " << product << endl;
        } else {
            break;
        }

    } while (choice == 1);

    return 0;
}
