#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

double DEG_to_RAD(double theta){
    return theta * PI / 180.0;
}

double RAD_to_DEG(double theta){
    return theta * 180.0 / PI;
}

template <typename T>
struct point{
    T x,y;

    point(){
        x = y = 0.0;
    }

    point(T _x, T _y) : x(_x), y(_y) {}

    bool operator < (point other) const{
        if(fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const{
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }

    double hypot(T dx, T dy){
        return sqrt(dx*dx + dy*dy);
    }

    double euclidian_distance(point other){
        return hypot(x - other.x, y - other.y);
    }

    point rotate(double theta){
        double rad = DEG_to_RAD(theta);
        return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }

};

int main(){
    return 0;
}