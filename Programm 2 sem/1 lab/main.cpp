#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

//Класс точка
class Point {
public:
    Point() : x(0), y(0) {};

    Point(int x1, int y1) : x(x1), y(y1) {};

    Point(const Point &Point_)
            : x(Point_.x), y(Point_.y) {};

    Point &operator=(const Point &Point_) {

        x = Point_.x;
        y = Point_.y;
        return *this;
    }

    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

private:
    int x;
    int y;
};

class PolygonalChain {
public:
    PolygonalChain() = default;

    PolygonalChain(int k, vector<Point> &vec) : vec_points(vec), size(k) {};

    PolygonalChain(const PolygonalChain &PolygonalChain_)
            : size(PolygonalChain_.size), vec_points(PolygonalChain_.vec_points) {};

    PolygonalChain &operator=(const PolygonalChain &PolygonalChain_) {

        size = PolygonalChain_.size;
        vec_points = PolygonalChain_.vec_points;
        return *this;
    }

    int get_size() {
        return size;
    }

    Point get_point(int i) {
        return vec_points[i];
    }

    double Perimeter_calc() {
        double l = 0;
        int x, y;
        int x1, y1;
        for (int i = 1; i < size; i++) {

            x = vec_points[i].getx();
            y = vec_points[i].gety();
            x1 = vec_points[i - 1].getx();
            y1 = vec_points[i - 1].gety();
            l += sqrt(abs(x * x - x1 * x1 + y * y - y1 * y1));

        }

        Perimeter = l;
        return Perimeter;
    }


protected:
    double Perimeter;
    int size;
    vector<Point> vec_points;
};


class ClosedPolygonalChain : public PolygonalChain {
public:

    ClosedPolygonalChain() = default;

    ClosedPolygonalChain(int k, vector<Point> &vec) {
        vec_points = vec,
        size = k;
    }

    ClosedPolygonalChain(const ClosedPolygonalChain &ClosedPolygonalChain_) {
        size = (ClosedPolygonalChain_.size);
        vec_points = (ClosedPolygonalChain_.vec_points);

    }

    ClosedPolygonalChain &operator=(const ClosedPolygonalChain &ClosedPolygonalChain_) {
        size = ClosedPolygonalChain_.size;
        vec_points = ClosedPolygonalChain_.vec_points;
        return *this;
    }

    double Area_calc() {
        double s=0;
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
        Area = s;
        return Area;
    };

protected:
    double Area;


};

class Polygon : public ClosedPolygonalChain {
public:
    Polygon() = default;

    Polygon(int k, vector<Point> &vec) {
        vec_points = vec,
                size = k;
    }

    Polygon(const Polygon &Polygon_) {
        size = (Polygon_.size);
        vec_points = (Polygon_.vec_points);
        //Проверка на выпуклость
        int ABx, ABy;
        int BCx, BCy;
        bool flag;
        bool Proof = true;
        ABx = vec_points[1].getx() - vec_points[0].getx();
        ABy = vec_points[1].gety() - vec_points[0].gety();
        BCx = vec_points[2].getx() - vec_points[1].getx();
        BCy = vec_points[2].gety() - vec_points[1].gety();
        double product = ABx * BCy - ABy * BCx;
        if (product > 0) {
            flag = 1;
        } else flag = 0;
        for (int i = 1; i < size - 2; i++) {
            ABx = vec_points[i + 1].getx() - vec_points[i].getx();
            ABy = vec_points[i + 1].gety() - vec_points[i].gety();
            BCx = vec_points[i + 2].getx() - vec_points[i + 1].getx();
            BCy = vec_points[i + 2].gety() - vec_points[i + 1].gety();
            double product = ABx * BCy - ABy * BCx;
            if (((product > 0) and (flag == 0)) or ((product < 0) and (flag == 1))) {
                Proof = 0;
                break;
            }
            if (Proof == 0) {
                cout << "This is not a convex polygon" << '\n';
            }

        }
    }

    Polygon &operator=(const Polygon &Polygon_) {
        size = Polygon_.size;
        vec_points = Polygon_.vec_points;
        return *this;
    }

};

class Triangle : public ClosedPolygonalChain {
public:

    Triangle() = default;

    Triangle(int k, vector<Point> &vec) {
        vec_points = vec,
        size = k;
    }

    Triangle(const Triangle &Triangle_) {
        size = (Triangle_.size);
        vec_points = (Triangle_.vec_points);
    }

    Triangle &operator=(const Triangle &Triangle_) {
    }

};

class Trapezoid : public ClosedPolygonalChain {
public:
    Trapezoid() = default;

    Trapezoid(int k, vector<Point> &vec) {
        vec_points = vec,
        size = k;

    }
    Trapezoid(const Trapezoid &Trapezoid_) {
        size = (Trapezoid_.size);
        vec_points = (Trapezoid_.vec_points);
    }


};

void work_point(){
    //Point
    int a,b;
    cout << "Work with Point\n";
    cout << "Enter the coordinates of the point:";
    cin >> a >> b;
    Point P(a, b);

}
void work_PolygonalChain(){
    //PolygonalChain
    int n,a,b;
    cout << "Work with PolygonalChain\n";
    cout << "Enter the number of points:";
    cin >> n;
    vector<Point> v;
    for (int i=0;i<n;i++ ){
        cout << "Enter X and Y :";
        cin >> a >> b;
        v.push_back(Point(a, b));
    }

    PolygonalChain PC(n, v);
    cout <<"Perimeter =" << PC.Perimeter_calc() << '\n';
}
void work_ClosedPolygonalChain(){
    //ClosedPolygonalChain
    int n,a,b;
    cout << "Work with ClosedPolygonalChain\n";
    cout << "Enter the number of points:";
    cin >> n;
    vector<Point> v;
    for (int i=0;i<n;i++ ){
        cout << "Enter X and Y :";
        cin >> a >> b;
        v.push_back(Point(a, b));
    }
    v.push_back(v[0]);
    ClosedPolygonalChain CPC(n+1, v);
    cout <<"Perimeter =" << CPC.Perimeter_calc() << '\n';
    cout <<"Area =" << CPC.Area_calc() << '\n';
}
void work_Polygon(){
    //Polygon
    int n,a,b;
    cout << "Work with Polygon\n";
    cout << "Enter the number of points:";
    cin >> n;
    vector<Point> v;
    for (int i=0;i<n;i++ ){
        cout << "Enter X and Y :";
        cin >> a >> b;
        v.push_back(Point(a, b));
    }
    v.push_back(v[0]);
    Polygon P(n+1, v);
    cout <<"Perimeter =" << P.Perimeter_calc() << '\n';
    cout <<"Area"<< P.Area_calc() << '\n';
}
void work_Triangle(){
    //Triangle
    int a,b;
    int n=3;
    cout << "Work with Triangle\n";

    vector<Point> v;
    for (int i=0;i<n;i++ ){
        cout << "Enter X and Y :";
        cin >> a >> b;
        v.push_back(Point(a, b));
    }
    v.push_back(v[0]);
    Triangle T(n+1, v);
    cout <<"Perimeter =" << T.Perimeter_calc() << '\n';
    cout <<"Area"<< T.Area_calc() << '\n';
}
void work_Trapezoid(){
    //Trapezoid
    int a,b;
    int n=4;
    cout << "Work with Trapezoid\n";

    vector<Point> v;
    for (int i=0;i<n;i++ ){
        cout << "Enter X and Y :";
        cin >> a >> b;
        v.push_back(Point(a, b));
    }
    v.push_back(v[0]);
    Trapezoid T(n+1, v);
    cout <<"Perimeter =" << T.Perimeter_calc() << '\n';
    cout <<"Area"<< T.Area_calc() << '\n';
}
void hello(){
    int a;
    cout <<"Select a number geometric figure to work with \n";
    cout <<"1.Point\n";
    cout <<"2.PolygonalChain\n";
    cout <<"3.ClosedPolygonalChain\n";
    cout <<"4.Polygonal\n";
    cout <<"5.Triangle\n";
    cout <<"6.Trapezoid\n";
    cout <<"Your figure has a number :";
    cin >> a;
    while (not(1<=a<=6)){
        cout <<"You enter a wrong number, try again :";
        cin >> a;
    }
    if (a==1){
        work_point();
    }
    if (a==2){
        work_PolygonalChain();
    }
    if (a==3){
        work_ClosedPolygonalChain();
    }
    if (a==4){
        work_Polygon();
    }
    if (a==5){
        work_Triangle();
    }
    if (a==6){
        work_Trapezoid();
    }

}

int main() {

    //hello();
    Point p(1,20);
    Point k = p;


    vector<Point> v = {Point(1,2)};
    Trapezoid a(1,v);
    Trapezoid b;
    b=a;
    cout << b.get_size();

    return 0;

}