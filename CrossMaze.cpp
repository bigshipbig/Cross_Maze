#include "CrossMaze.h"
#include "CreatMaze.h"

Walk::Walk() {
    MAP.getMaze(0);
}
Walk::Walk(int k) {
    MAP.getMaze(k);
}

Walk::~Walk() {

}

int Walk::getdirection() {
    char c;
    c = getch();
    c = getch();
    // 以下几行告诉怎样判断用户按的哪个方向键
    if(c==72)   return 2; // printf("向上");
    if(c==80)   return 3; // printf("向下");
    if(c==75)   return 1; // printf("向左");
    if(c==77)   return 0; // printf("向右");
}


void Walk::React(){
    int dict = getdirection();
    MAP.updatemaze(dict);
    MAP.printMaze();
}
