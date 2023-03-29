#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
};

class Test : virtual public Student {
public:
    int scores[3];
};

class Sports : virtual public Student {
public:
    int score;
};

class Result : public Test, public Sports {
public:
    int totalScore() {
        int sum = score;
        for (int i = 0; i < 3; i++) {
            sum += scores[i];
        }
        return sum;
    }
    void displayResult() {
        cout << "Roll No: " << rollNo << endl;
        cout << "Total Score: " << totalScore() << endl;
    }
};

int main() {
    Result r;
    cout << "Enter Roll No: ";
    cin >> r.rollNo;
    cout << "Enter Sports Score: ";
    cin >> r.score;
    cout << "Enter Test Scores (separated by spaces): ";
    for (int i = 0; i < 3; i++) {
        cin >> r.scores[i];
    }
    r.displayResult();
    return 0;
}
