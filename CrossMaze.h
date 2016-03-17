#ifndef CrossMaze_H_
#define CrossMaze_H_


#include <cstdio>
#include <cstring>
#include <conio.h>
#include "CreatMaze.h"

class Walk {
public:
    Maze MAP;
    Walk();
    Walk(int k);
    ~Walk();
    int getdirection();
    void React();
};

#endif
