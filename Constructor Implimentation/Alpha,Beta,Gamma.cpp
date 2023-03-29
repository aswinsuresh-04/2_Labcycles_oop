#include <iostream>
using namespace std;

class alpha {
private:
    int alphaData;
public:
    alpha() {
        alphaData = 0;
        cout << "Default constructor of alpha called" << endl;
    }
    alpha(int a) {
        alphaData = a;
        cout << "Parameterized constructor of alpha called with value " << a << endl;
    }
    void setAlpha(int a) {
        alphaData = a;
    }
    int getAlpha() {
        return alphaData;
    }
};

class beta {
private:
    int betaData;
public:
    beta() {
        betaData = 0;
        cout << "Default constructor of beta called" << endl;
    }
    beta(int b) {
        betaData = b;
        cout << "Parameterized constructor of beta called with value " << b << endl;
    }
    void setBeta(int b) {
        betaData = b;
    }
    int getBeta() {
        return betaData;
    }
};

class gamma : public alpha, public beta {
private:
    int gammaData;
public:
    gamma() {
        gammaData = 0;
        cout << "Default constructor of gamma called" << endl;
    }
    gamma(int a, int b, int c) : alpha(a), beta(b) {
        gammaData = c;
        cout << "Parameterized constructor of gamma called with values "<< c << endl;
    }
    void setGamma(int c) {
        gammaData = c;
    }
    int getGamma() {
        return gammaData;
    }
};

int main() {
    int a, b, c;
    cout << "Enter values for alpha, beta, and gamma:" << endl;
    cin >> a >> b >> c;
    gamma g(a, b, c);
    cout << "Gamma: " << g.getGamma() << endl;
    cout << "Alpha: " << g.getAlpha() << endl;
    cout << "Beta: " << g.getBeta() << endl;

    cout << "Enter new values for alpha, beta, and gamma:" << endl;
    cin >> a >> b >> c;
    g.setGamma(c);
    g.setAlpha(a);
    g.setBeta(b);

    cout << "Gamma: " << g.getGamma() << endl;
    cout << "Alpha: " << g.getAlpha() << endl;
    cout << "Beta: " << g.getBeta() << endl;

    return 0;
}
