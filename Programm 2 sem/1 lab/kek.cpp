#include "kek.h"
#include <cmath>

Point::Point(){
    x=0;
    y=0;
}
Point::Point(const int x1,const int y1){
    x=x1;
    y=y1;
}
Point::Point(const Point &point_){
    x=point_.x;
    y=point_.y;
}
int Point::getx() const {return x;}
int Point::gety() const {return y;}
Point &Point::operator=(const Point &point_) {
    if (this==&point_) {
        return *this;
    }
    x = point_.x;
    y = point_.y;
    return *this;
}


PolygonalChain::PolygonalChain(){
    size=0;
    vec_points={};
}
PolygonalChain::PolygonalChain(const int k, const std::vector<Point> &vec){
    vec_points=vec;
    size=k;
}
PolygonalChain::PolygonalChain(const PolygonalChain &polygonalchain_){
    size=polygonalchain_.size;
    vec_points=polygonalchain_.vec_points;
}
int PolygonalChain::get_size()const {return size;}
Point PolygonalChain::get_point(const int i)const {
    return vec_points[i];
}
double PolygonalChain::perimeter_calc() {
    double length = 0;
    int x, y;
    int x1, y1;
    for (int i = 1; i < size; i++) {
        x = vec_points[i].getx();
        y = vec_points[i].gety();
        x1 = vec_points[i - 1].getx();
        y1 = vec_points[i - 1].gety();
        length += sqrt(abs(x * x - x1 * x1 + y * y - y1 * y1));
    }
    perimeter = length;
    return perimeter;
}
PolygonalChain &PolygonalChain::operator=(const PolygonalChain &polygonalchain_) {
    if (this==&polygonalchain_) {
        return *this;
    }
    size = polygonalchain_.size;
    vec_points = polygonalchain_.vec_points;
    return *this;
}


ClosedPolygonalChain::ClosedPolygonalChain() = default;
ClosedPolygonalChain::ClosedPolygonalChain(const int k,const std::vector<Point> &vec) {
    vec_points = vec,
            size = k;
}
ClosedPolygonalChain::ClosedPolygonalChain(const ClosedPolygonalChain &closedpolygonalchain_) {
    size = (closedpolygonalchain_.size);
    vec_points = (closedpolygonalchain_.vec_points);
}
double ClosedPolygonalChain::area_calc() {
    double s = 0;
    int x1, y1;
    int x2, y2;
    for (int i = 0; i < size - 1; i++) {
        x1 = vec_points[i].getx();
        y1 = vec_points[i].gety();
        x2 = vec_points[i + 1].getx();
        y2 = vec_points[i + 1].gety();
        s += x1 * y2 - x2 * y1;
    };
    s += vec_points[size - 1].getx() * vec_points[0].gety();
    s -= vec_points[0].getx() * vec_points[size - 1].gety();
    s = abs(s) / 2;
    area = s;
    return area;
};
ClosedPolygonalChain &ClosedPolygonalChain::operator=(const ClosedPolygonalChain & closedpolygonalchain_){
    if (this==&closedpolygonalchain_) {
        return *this;
    }
    size = closedpolygonalchain_.size;
    vec_points = closedpolygonalchain_.vec_points;
    return *this;
}



Polygon::Polygon() = default;
Polygon::Polygon(const int k,const std::vector<Point> &vec) {
    vec_points = vec,
    size = k;
}
Polygon::Polygon(const Polygon &polygon_) {
    size = (polygon_.size);
    vec_points = (polygon_.vec_points);
}
Polygon &Polygon::operator=(const Polygon &polygon_) {
    if (this==&polygon_) {
        return *this;
    }
    size = polygon_.size;
    vec_points = polygon_.vec_points;
    return *this;
}



Triangle::Triangle() = default;
Triangle::Triangle(const int k, const std::vector<Point> &vec) {
    vec_points = vec,
            size = k;
}
Triangle::Triangle(const Triangle &triangle_) {
    size = (triangle_.size);
    vec_points = (triangle_.vec_points);
}
Triangle &Triangle::operator=(const Triangle &triangle_) {
    size = triangle_.size;
    vec_points = triangle_.vec_points;
    return *this;
}


Trapezoid::Trapezoid() = default;
Trapezoid::Trapezoid(const int k,const std::vector<Point> &vec) {
    vec_points = vec,
            size = k;
}
Trapezoid::Trapezoid(const Trapezoid &trapezoid_) {
    size = (trapezoid_.size);
    vec_points = (trapezoid_.vec_points);
}
Trapezoid &Trapezoid::operator=(const Trapezoid &trapezoid_) {
    size = trapezoid_.size;
    vec_points = trapezoid_.vec_points;
    return *this;
}