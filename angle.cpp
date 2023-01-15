#include <iostream>
#include <math.h>

#define ll long long // long long

struct vec2 {
    double x;
    double y;

    vec2(double a, double b) : x(a), y(b) {}
    double dot(vec2 other) {
        return x * other.x + y * other.y;
    }

    double len() {
        return sqrt( x * x + y * y );
    }

    void normalize() {
        double m = len();
        x /= m;
        y /= m;
    }
};

double rad_to_deg(double rads) {
    return rads * (180 / M_PI);
}

double get_angleRad(vec2 a, vec2 b) {
    // angle = arccos(dot(A,B) / (|A|* |B|))
    return acos((a.dot(b)) / (a.len() * b.len()));
}

double get_angleDeg(vec2 a, vec2 b) {
    // angle = arccos(dot(A,B) / (|A|* |B|))
    return rad_to_deg(acos((a.dot(b)) / (a.len() * b.len()))); // Method one
    // a.x * b.x + a.y * b.y == cos(angle)
    // a.normalize(); b.normalize(); return rad_to_deg( acos( a.x * b.x + a.y * b.y ) ); // Method two
}

int main() {
    std::cout.precision(3);

    std::cout << "This little program finds angle between two 2D vectors that originate in (0, 0)." << std::endl;

    ll x, y;

    std::cout << "Please enter coordinates of a vector A (x, y), ex. 1 3: ";
    std::cin >> x >> y;
    vec2 a = vec2(x, y);

    std::cout << "Please enter coordinates of a vector B (x, y), ex. 1 3: ";
    std::cin >> x >> y;
    vec2 b = vec2(x, y);

    a.normalize(); b.normalize();

    std::cout << get_angleDeg(a, b) << " degrees between two vectors." << std::endl;
    std::cout << get_angleRad(a, b) << " radians between two vectors." << std::endl;

    return 0;
}