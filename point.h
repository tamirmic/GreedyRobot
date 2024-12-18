#ifndef POINT_H_
#define POINT_H_

/*
    Point class to represent the x and y positions of a robot navigating towards a treasure
*/

class Point {
    public:
        //constructors
        Point();
        Point(int x, int y);

        //getters
        int x() const;
        int y() const;

        //setters
        void set_x(int x);
        void set_y(int y);
        void set_point(int x, int y);

        //operator overload
        bool operator==(const Point& other) const;

    private:
        int x_;
        int y_;
};
#endif