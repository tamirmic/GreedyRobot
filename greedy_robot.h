#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_
#include <iostream>
using namespace std;
#include <vector>
#include "point.h"

/*
    GreedyRobot class that finds all the shortest possible paths recursively for a robot to reach a treasure
*/


class GreedyRobot {
    public:
        //constructors
        GreedyRobot();
        GreedyRobot(int max_distance, int x1, int y1, int x2, int y2);
        
        //getters
        int max_distance() const;
        Point treasure_pos() const;

        void FindPaths(vector<string>& paths);

    private:
        Point robot_pos_;
        Point treasure_pos_;
        int max_distance_;
        
        //setter for robot and treasure positions and max distance
        void set_points(int max_distance, int x1, int y1, int x2, int y2);

        //recursion function to find all of the shortest possible paths for the robot to get to the treasure with a specified number of consecutive steps it can take in one direction
        void FindPaths(Point robot, string path, vector<string>& paths, int move_counter, char last_move);
};
#endif