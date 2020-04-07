#include <bits/stdc++.h>
using namespace std;
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        //d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main( ) {
    extendedEuclid(8, 3);
    cout << "The GCD of 8 and 3 is " << d << endl;
    cout << "Coefficients x and y are "<< x <<  "and  " << y << endl;
    return 0;   
}