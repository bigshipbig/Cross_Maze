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
    // ���¼��и��������ж��û������ĸ������
    if(c==72)   return 2; // printf("����");
    if(c==80)   return 3; // printf("����");
    if(c==75)   return 1; // printf("����");
    if(c==77)   return 0; // printf("����");
}


void Walk::React(){
    int dict = getdirection();
    MAP.updatemaze(dict);
    MAP.printMaze();
}
