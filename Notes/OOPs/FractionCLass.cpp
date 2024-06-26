#include <iostream>
#include<algorithm>

using namespace std;

class Fraction {
private:

    int numerator;
    int denominator;

public:

    Fraction(int numerator, int denominator) {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print() const {
        cout << this -> numerator << "/" << denominator << endl;
    }

    void simplify() {
        int gcd = __gcd(this -> numerator, this -> denominator);
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    void add(Fraction const & f2) {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
    }

    void multiply(Fraction const & f2) {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }

};

int main() {
    int num1, den1;
    cin >> num1 >> den1;
    Fraction f(num1, den1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int num2, den2;
            cin >> num2 >> den2;
            Fraction f2(num2, den2);
            f.add(f2);
            f.print();
        } else if (type == 2) {
            int num2, den2;
            cin >> num2 >> den2;
            Fraction f2(num2, den2);
            f.multiply(f2);
            f.print();
        }
    }

    return 0;
} 