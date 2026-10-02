#include <iostream>
#include <cmath>

using std::abs;
using std::cout;
using std::endl;

// Calculates horizontal distance (X coordinates)
int A_input(int m[2], int n[2]) { 
    return abs(m[0] - n[0]);
}
// Calculates vertical distance (Y coordinates)
int B_input (int x[2], int z[2]) {
    return abs(x[1] - z[1]);
}
// Calculates the final hypotenuse
int D_input( int a, int b ) { 
    int c = (a*a + b*b) ; 
    return 0;
    }                     
                     
int main() {
    int p1[2] = {1, 2};
    int p2[2] = {4, 3};

    // Calculate and print the final Pythagorean result directly
    /*cout << A_input(p1,p2) << endl;
    cout << B_input( p1, p2) << endl;
    cout << D_input ( A_inputs(p1, p2), B_inputs (p1, p2)) << endl;
 return 0;
}*/
// uas i was so dumb i kept miss match inputs for a and b so i did
// the same for d  and input input and inputs are very different looked a the code for 30 min
// then figure out i dont need all the dam cout
cout  << D_input(A_input(p1, p2), B_input(p1, p2)) << endl;

    return 0;
}
