#include<iostream>
#include<math.h>
using namespace std;
class complex
{
    friend std::ostream &operator<<(std::ostream &os, complex & c);
    friend std::istream &operator>>(std::istream& is,complex& c);
private:
    int a; // real part of complex number
    int b;//imaginary part of complex number
public:
    complex();
    complex(int, int);
    complex operator+(complex);
    complex operator-(complex);
    complex operator*(complex);
    complex operator/(complex);
    void show();
    int real();
    int imaginary();
    double mod();
    ~complex();
};
complex::complex() : a {0}, b{0}{
};
complex::complex(int x,int y) : a {x},b {y} {
};
complex complex :: operator+(complex c)
{
    complex temp {};
    temp.a = a + c.a;
    temp.b = b + c.b;
    return temp;
}
complex complex :: operator-(complex c)
{
    complex temp {};
    temp.a = a - c.a;
    temp.b = b - c.b;
    return temp;
}
complex complex :: operator*(complex c)
{
    complex temp {};
    temp.a = a*c.a + b*c.b;
    temp.b = a*c.b+b*c.a;
    return temp;
}
complex complex::operator/(complex c)
{
    complex temp{};
    temp.a = (a*c.a + b*c.b)/(c.a*c.a - c.b*c.b);
    temp.b = (a*c.b+b*c.a)/(c.a*c.a - c.b*c.b);
    return temp;
}
complex::~complex(){
}
istream & operator>>(istream &is, complex & c){
    is>>c.a;
    is>>c.b;
    return is;
}
ostream &operator<<(ostream &os, complex & c){
        string sign = (c.b >= 0) ? "+" : "";
        os<<c.a<<sign<<c.b<<"i ";
        return os;
}
int complex::real(){
    return a;
}
int complex::imaginary() {
    return b;
}
double complex::mod() {
    return sqrt(a*a + b*b);
}
int main()
{
    complex c1 ,c2;
    cout<<"Enter the first complex number : ";
    cin>>c1;
    cout<<"Enter the second complex number : ";
    cin>>c2;
    cout<<"Addition of complex number : "<<endl;
    complex c3 = c1 + c2;
    cout<<c3<<endl;
    cout<<"Subtraction of complex number : "<<endl;
    c3 = c1 - c2;
    cout<<c3<<endl;
    cout<<"Multiplication of complex number : "<<endl;
    c3 = c1 * c2;
    cout<<c3<<endl;
    cout<<"Division of complex number : "<<endl;
    c3 = c1 / c2;
    cout<<c3<<endl;
    cout << "Real part of "<<c3 <<" is : "<<c3.real() << endl;
    cout << "Imaginary part of "<<c3 <<" is : "<< c3.imaginary() << endl;
    cout << "Modulus of "<<c3 <<" is : "<< c3.mod() << endl;
    return 0;
}
