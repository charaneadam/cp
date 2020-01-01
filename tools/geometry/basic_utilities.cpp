#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

struct angle{
    static double DEG_to_RAD(double theta){
        return theta * PI / 180.0;
    }

    static double RAD_to_DEG(double theta){
        return theta * 180.0 / PI;
    }
};

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
        double rad = angle::DEG_to_RAD(theta);
        return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }

};

struct line{
    double a, b, c;

    static line line_from_points(point<double> p1, point<double> p2){
        line l{};
        if(fabs(p1.x - p2.x) < EPS){
            l.a = 1.0;
            l.b = 0.0;
            l.c = -p1.x;
        }
        else{
            l.a = -(p1.y - p2.y) / (p1.x - p2.x);
            l.b = 1.0;
            l.c = -(l.a * p1.x) - p1.y;
        }
        return l;
    }

    bool is_parallel(line other){
        return (fabs(a - other.a) < EPS && fabs(b - other.b) < EPS);
    }

    bool is_same(line other){
        return is_parallel(other) && fabs(c - other.c) < EPS;
    }

    pair<bool, point<double>> does_intersect(line other){
        point<double> intersection;
        if(is_parallel(other)) return {false, intersection};
        intersection.x = (other.b * c - b * other.c);
        if(fabs(b) > EPS) intersection.y = -(a * intersection.x + c);
        else intersection.y = -(other.a * intersection.x + other.c);
        return {true, intersection};
    }
};

struct vec{
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}

    static vec vec_from_points(point<double> a, point<double> b){
        return {b.x - a.x, b.y - a.y};
    }

    vec scale(double s){
        return {x*s, y*s};
    }

    point<double> translate(point<double> p){
        return {p.x + x, p.y + y};
    }

    double dot(vec other){
        return x * other.x + y * other.y;
    }

    double norm(){
        return x*x + y*y;
    }

};

int main(){
    return 0;
}