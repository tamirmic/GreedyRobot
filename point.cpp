#include "point.h"

Point::Point(){
    set_x(0);
    set_y(0);
}

Point::Point(int x, int y){
    set_x(x);
    set_y(y);
}

int Point::x() const{
    return x_;
}

int Point::y() const{
    return y_;
}

void Point::set_x(int x){
    x_ = x;
}

void Point::set_y(int y){
    y_ = y;
}

void Point::set_point(int x, int y){
    set_x(x);
    set_y(y);
}

bool Point::operator==(const Point& other) const{
    return ((x() == other.x()) && (y() == other.y()));
}