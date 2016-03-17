#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <queue>
#include "CreatMaze.h"
#include "CrossMaze.h"


#define x  fuck.MAP.st_x

int main(){
    Walk fuck = Walk(2);
    fuck.MAP.printMaze();
    while(fuck.MAP.st!=fuck.MAP.ed){
        fuck.React();
    }
    return 0;
}
