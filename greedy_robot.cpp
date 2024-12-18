#include "greedy_robot.h"
#include <algorithm>

GreedyRobot::GreedyRobot(int max_distance, int x1, int y1, int x2, int y2){
   set_points(max_distance, x1, y1, x2, y2);
}

int GreedyRobot::max_distance() const{
    return max_distance_;
}

Point GreedyRobot::treasure_pos() const{
    return treasure_pos_;
}

void GreedyRobot::set_points(int max_distance, int x1, int y1, int x2, int y2){
    max_distance_ = max_distance;
    robot_pos_.set_point(x1, y1);
    treasure_pos_.set_point(x2, y2);
}

void GreedyRobot::FindPaths(vector<string>& paths){
    FindPaths(robot_pos_, "", paths, 0, ' ');
}

void GreedyRobot::FindPaths(Point robot, string path, vector<string>& paths, int move_counter, char last_move){
    if(move_counter > max_distance()){
        return;
    }

    if(robot == treasure_pos()){
        //checks to see if the path is already in the vector so no duplicates
        if(find(paths.begin(), paths.end(), path) == paths.end()){
            if(path != ""){
                paths.push_back(path);
            }
            else{
                cout << "Already there" << endl;
            }
        }
        return;
    }

    //move South
    if(robot.y() > treasure_pos().y()){
        int move_counter_move;
        if(last_move == 'S'){
           move_counter_move = move_counter + 1;
        } else{
            move_counter_move =  1;
        }
        FindPaths(Point(robot.x(), robot.y() - 1), path + "S", paths, move_counter_move, 'S');
    }

    //move North
    if(robot.y() < treasure_pos().y()){
        int move_counter_move;
        if(last_move == 'N'){
           move_counter_move = move_counter + 1;
        } else{
            move_counter_move =  1;
        }
        FindPaths(Point(robot.x(), robot.y() + 1), path + "N", paths, move_counter_move, 'N');
    }

    //move West
    if(robot.x() > treasure_pos().x()){
        int move_counter_move;
        if(last_move == 'W'){
           move_counter_move = move_counter + 1;
        } else{
            move_counter_move =  1;
        }
        FindPaths(Point(robot.x() - 1, robot.y()), path + "W", paths, move_counter_move, 'W');
    }

    //move East
    if(robot.x() < treasure_pos().x()){
        int move_counter_move;
        if(last_move == 'E'){
           move_counter_move = move_counter + 1;
        } else{
            move_counter_move =  1;
        }
        FindPaths(Point(robot.x() + 1, robot.y()), path + "E", paths, move_counter_move, 'E');
    }
}