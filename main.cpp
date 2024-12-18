#include "greedy_robot.h"
#define ARGS
const int kArgSize = 5;

//adds all the arguments passed in into an array
void ParseArgs(char *argv[], int *args){
    for(int i = 1; i <= kArgSize; i++){
        args[i] = atoi(argv[i]);
    }
}

int main(int argc, char* argv[]){
    //manage args
    #ifdef ARGS
    if(argc != 6){
        return -1;
    }
    int args[kArgSize];
    ParseArgs(argv, args);
    if(args[1] < 1){ //max distance can't be less than 1
        return -1;
    }
    //calls greedy robot using the 5 arguments passed in
    GreedyRobot robot(args[1], args[2], args[3], args[4], args[5]);
    #else
    GreedyRobot robot(2, -1, -1, 1, 2);
    #endif

    vector<string> paths = {};
    robot.FindPaths(paths);
    for(int i = 0; i < paths.size(); i++){
        cout << paths[i] << endl;
    }
    cout << "Number of paths: " << paths.size() << endl;
}