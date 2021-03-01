#pragma once
#include <cmath>
#include <vector>

class Point {
public:
    Point();
    Point(const int,const int) ;
    Point(const Point &);
    int getx() const;
    int gety() const;
    Point &operator=(const Point &);
private:
    int x;
    int y;
};

class PolygonalChain {
public:
    PolygonalChain() ;
    PolygonalChain(const int , const std::vector<Point> &) ;
    PolygonalChain(const PolygonalChain &);
    int get_size() const ;
    Point get_point(const int )const;
    double perimeter_calc() ;
    PolygonalChain &operator=(const PolygonalChain &) ;

protected:
    double perimeter;
    int size;
    std::vector<Point> vec_points;
};

class ClosedPolygonalChain : public PolygonalChain {
public:
    ClosedPolygonalChain() ;
    ClosedPolygonalChain(const int ,const std::vector<Point> &) ;
    ClosedPolygonalChain(const ClosedPolygonalChain &);
    ClosedPolygonalChain &operator=(const ClosedPolygonalChain &) ;
    double area_calc() ;
protected:
    double area;
};

class Polygon : public ClosedPolygonalChain {
public:
    Polygon();
    Polygon(const int, const std::vector<Point> &);
    Polygon(const Polygon &);
    Polygon &operator=(const Polygon &);

};

class Triangle : public ClosedPolygonalChain {
public:

    Triangle() ;
    Triangle(const int ,const std::vector<Point> &);
    Triangle(const Triangle &) ;
    Triangle &operator=(const Triangle &) ;
};

class Trapezoid : public ClosedPolygonalChain {
public:
    Trapezoid() ;
    Trapezoid(const int ,const std::vector<Point> &);
    Trapezoid(const Trapezoid &);
    Trapezoid &operator=(const Trapezoid &);


};


