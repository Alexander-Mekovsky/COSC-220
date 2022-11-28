#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

Complex::Complex(double a, double b)
{
    real = a;
    imag = b;
}

Complex::Complex(const Complex &obj)
{
    real = obj.real;
    imag = obj.imag;
}

Complex::~Complex()
{

}

void Complex::setReal(double r)
{
    real = r;
}

void Complex::setImag(double i)
{
    imag = i;
}

double Complex::getReal()
{
    return real;
}

double Complex::getImag()
{
    return imag;
}

void Complex::set(double r, double i)
{
    real = r;
    imag = i;
}

Complex Complex::operator +(const Complex &right)
{
    Complex temp;
    temp.real = real + right.real;
    temp.imag = imag;
    return temp;
}

Complex Complex::operator +(double value)
{
    Complex temp;
    temp.real = value + real;
    temp.imag = imag;
    return temp;
}

Complex operator +(double value, const Complex &right)
{
    Complex temp;
    temp.real = value + right.real;
    temp.imag = right.imag;
    return temp;
}

Complex Complex::operator -(const Complex &right)
{
    Complex temp;
    temp.real = real - right.real;
    temp.imag = imag;
    return temp;
}

Complex Complex::operator -(double value)
{
    Complex temp;
    temp.real = value - real;
    temp.imag = imag;
    return temp;
}

Complex operator -(double value, const Complex &right)
{
    Complex temp;
    temp.real = value - right.real;
    temp.imag = right.imag;
    return temp;
}

Complex Complex::operator *(const Complex &right)
{
    Complex temp;
    temp.real = real * right.real;
    temp.imag = imag;
    return temp;
}

Complex Complex::operator *(double value)
{
    Complex temp;
    temp.real = value * real;
    temp.imag = imag;
    return temp;
}

Complex operator *(double value, const Complex &right)
{
    Complex temp;
    temp.real = value * right.real;
    temp.imag = right.imag; 
    return temp;
}

Complex Complex::operator /(const Complex &right)
{
    Complex temp;
    temp.real = real / right.real;
    temp.imag = imag;
    return temp;
}

Complex Complex::operator /(double value)
{
    Complex temp;
    temp.real = value / real;
    temp.imag = imag;
    return temp;
}

Complex operator /(double value, const Complex &right)
{
    Complex temp;
    temp.real = value / right.real;
    temp.imag = right.imag;
    return temp;
}

void Complex::operator+=(const Complex &right)
{
    *this = *this + right;
}
void Complex::operator-=(const Complex &right)
{
   *this = *this - right;
}
Complex Complex::operator ^(int pow)
{
    Complex x(real, imag);
    Complex zero(0);
    Complex value(1);
    if(x == zero)
        return zero;
    if(pow < 0)
    {
        pow = -pow;
    }
    for(int i = 0; i < pow; i++)
    {
        value = value * x;
    }
    return value;
}
bool Complex::operator ==(const Complex &right)
{
    bool status;
    if(real == right.real && imag == right.imag)
        status = true;
    else
        status = false;
    return status;
}
bool Complex::operator !=(const Complex &right)
{
    bool status;
    if(real != right.real && imag != right.imag)
        status = true;
    else   
        status = false;
    return status;
}
 const Complex Complex::operator=(const Complex &right)
{
    real = right.real;
    imag = right.imag;
    return *this;
} 
istream& operator >>(istream &strm, Complex &right)
{
    cout << "Input a complex number by simply entering" << endl;
    cout << "the real and imaginary parts with a space" << endl;
    cout << "between them." << endl;
    cout << "C = ";
    strm >> right.real;
    strm >> right.imag;
    cout << " ";
    strm >> right.imag;

    return strm;
}
ostream &operator <<(ostream &strm, const Complex &right)
{
    cout << "c = ";
    strm << right.real;
    cout << " ";
    strm << right.imag;
    cout << "i" << endl;
    return strm;
}

