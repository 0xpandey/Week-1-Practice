#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double radius;
    int steps;
    cout << "Enter radius of sphere: ";
    cin >> radius;
    cout << "Enter number of steps (higher = smoother sphere): ";
    cin >> steps;
    cout << "\n3D Coordinates of Sphere:\n";
    for (int i = 0; i <= steps; i++) {
        double theta = M_PI * i / steps;       
        for (int j = 0; j <= steps; j++) {
            double phi = 2 * M_PI * j / steps; 
            double x = radius * sin(theta) * cos(phi);
            double y = radius * sin(theta) * sin(phi);
            double z = radius * cos(theta);
            cout << "x: " << x
                 << " y: " << y
                 << " z: " << z << endl;
        }
    }
    return 0;
}
