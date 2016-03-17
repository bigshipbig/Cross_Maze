#ifndef CreatMaze_H_
#define CreatMaze_H_

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <queue>

using namespace std;

const int maxn = 55;

typedef pair<int, int > pii;

const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };

struct point
{
	int x, y;
	bool operator != (point &tmp);
};

class Maze {
private:
	int Size;
public:
	char maze[maxn][maxn];
	point st, ed;
	int level[10] = { 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 };
	void getMaze(int Difficulty);
	bool check(int st_x, int st_y, int ed_x, int ed_y);
	void printMaze();
	void updatemaze(int x);
	Maze();
	~Maze();
};

#endif
