//Athena Jafari
#include <iostream>
using namespace std;
class Complex {
public:
    Complex(double r, double i)  {
        real=r;
        imag=i;
    }
    Complex(double r) {
    	imag=0;
    	real=r;
    }

    void print() const;
    Complex& operator+=(const Complex& c);
    Complex& operator++(int);
    double re() const { return real; }
    double im() const { return imag; }

private:
    double real;
    double imag;
};
Complex& Complex::operator+=(const Complex& c)
{
    real += c.real;
    imag += c.imag;
    return *this;
}
Complex& Complex::operator++(int) {
    real += 1;
    imag += 1;
    return *this;
}

void Complex::print() const
{
    cout << real;
    if (imag > 0)
        cout << '+' << imag << 'i' << endl;
    else if (imag < 0)
        cout << imag << 'i' << endl;
}

int main()
{
    Complex a(3.4 );
    Complex b(2.5, 5);
    b+=a;
    b.print();
    b++;
    b.print();


    return 0;
}