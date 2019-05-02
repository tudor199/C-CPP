#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class complex{
public:
    double r, i;
    complex(): r(0), i(0){}
    complex(double a): r(a), i(0){}
    complex(double a,double b): r(a), i(b){}
    complex& operator+= (const complex z);
    complex& operator-= (const complex z);
    complex& operator*= (const complex z);
    complex& operator/= (const complex z);
    friend istream& operator>> (istream& in, complex &z){
        double a,b;
        in>> a >> b;
        z = complex(a,b);
        return in;
    }
    friend ostream& operator<< (ostream& out, const complex z){
        out<< z.r;
        if(z.i){
            out<< "+" << z.i << "i";
        }
        return out;
    }
    int abs(){
        return sqrt(r * r + i * i);
    }
private:
};

/// +
complex operator+ (const complex z1, const complex z2){
    complex result(z1.r + z2.r , z1.i + z2.i);
    return result;
}
template < typename T > complex operator+ (const complex z1, const T real){
    complex result(z1.r + real, z1.i);
    return result;
}
complex& complex::operator+= (const complex z){
    r+= z.r;
    i+= z.i;
    return *this;
}
/// -
complex operator- (const complex z1, const complex z2){
    complex result(z1.r - z2.r , z1.i - z2.i);
    return result;
}
template < typename T > complex operator- (const complex z1, const T real){
    complex result(z1.r - real, z1.i);
    return result;
}
complex& complex::operator-= (const complex z){
    r-= z.r;
    i-= z.i;
    return *this;
}
/// *
complex operator* (const complex z1 , const complex z2){
    complex result(z1.r * z2.r - z1.i * z2.i , z1.r * z2.i +z1.i * z2.r);
    return result;
}
template < typename T > complex operator* (const complex z1, const T real){
    complex result(z1.r * real, z1.i * real);
    return result;
}
complex& complex::operator*= (const complex z){
    double rthis=r;
    r = r * z.r - i * z.i;
    i = rthis * z.i + i * z.r;
    return *this;
}
/// /
complex operator/ (const complex z1, const complex z2){
    double a=(z1.r * z2.r + z1.i * z2.i) / (z1.r * z1.r + z2.i * z2.i);
    double b=(z1.i * z2.r - z1.r * z2.i) / (z1.r * z1.r + z2.i * z2.i);
    complex result(a,b);
    return result;
}
template < typename T > complex operator/ (const complex z1, const T real){
    complex result(z1.r / real, z1.i / real);
    return result;
}
complex& complex::operator/= (const complex z){
    double rthis=r;
    r = (r * z.r + i * z.i) / (r * r + z.i * z.i);
    i = (i * z.r - rthis * z.i) / (rthis * rthis + z.i * z.i);
    return *this;
}


bool operator==(const complex z1, const complex z2){
    return (z1.r == z2.r && z1.i == z2.i);
}
bool operator!=(const complex z1, const complex z2){
    return !(z1.r == z2.r && z1.i == z2.i);
}


int main()
{
    complex c1, c2(22), c3(5,6);
    c1+= complex(1,1) * complex(1,1);
    cout<<c1.abs();
    return 0;
}
