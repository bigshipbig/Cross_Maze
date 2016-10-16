#include "CreatMaze.h"

bool point::operator != (point &tmp){
    return x!=tmp.x||y!=tmp.y;
}

Maze::Maze(){
	memset(maze, 0, sizeof(maze));
	Size = 0;
}

Maze::~Maze(){
}
/*
BFS判断生成的地图是否可行
*/
bool Maze::check(int st_x, int st_y, int ed_x, int ed_y) {
	queue< pii > Q;
	Q.push(make_pair(st_x, st_y));
	bool vis[maxn][maxn];
	memset(vis, 0, sizeof(vis));
	vis[st_x][st_y] = 1;
	while (!Q.empty()) {
		pii top = Q.front();
		Q.pop();
		if (top.first == ed_x&&top.second == ed_y) return true;
		for (int i = 0; i<4; i++) {
			int tmpx = top.first + dx[i], tmpy = top.second + dy[i];
			if (tmpx >= 0 && tmpx<Size&&tmpy >= 0 && tmpy<Size&&maze[tmpx][tmpy] != '#'&&!vis[tmpx][tmpy]) {
				Q.push(make_pair(tmpx, tmpy));
				vis[tmpx][tmpy] = 1;
			}
		}
	}
	return false;
}
/*
打印地图
*/
void Maze::printMaze(){
	cout << "Size " << Size << endl;
	for (int i = 0; i<Size; i++){
		for (int j = 0; j<Size; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
}

/*
随机算法生成地图
*/
void Maze::getMaze(int Difficulty){
	Size = level[Difficulty];
	while (1){
		int st_x = rand() % Size;
		int st_y = rand() % Size;
		st.x = st_x;
		st.y = st_y;
		maze[st_x][st_y] = 'S';
		int ed_x = st_x, ed_y = st_y;
		while (ed_x == st_x&&ed_y == st_y||(abs(ed_x-st_x)+abs(ed_y-st_y))<Difficulty*level[Difficulty]/2){
			ed_x = rand() % Size;
			ed_y = rand() % Size;
		}
		maze[ed_x][ed_y] = 'E';
		ed.x = ed_x;
		ed.y = ed_y;
		for (int i = 0; i<Size; i++){
			for (int j = 0; j<Size; j++){
				if ((i == st_x&&j == st_y) || (i == ed_x&&j == ed_y))
					continue;
				int tmp = rand() % 2;
				if (tmp) maze[i][j] = '.';
				else maze[i][j] = '#';
			}
		}
		if (check(st_x, st_y, ed_x, ed_y))
			break;
	}
}
/*
更新地图
*/
void Maze::updatemaze(int x){
	int tmpx = st.x + dx[x];
	int tmpy = st.y + dy[x];
	if(tmpx==ed.x&&tmpy==ed.y){
        maze[tmpx][tmpy]='S';
        maze[st.x][st.y]='.';
        st.x=tmpx;
        st.y=tmpy;
        cout<<"Congratulations!,You win!!"<<endl;
        return;
	}
	if (tmpx < 0 || tmpy < 0 || tmpx >= Size || tmpy >= Size || maze[tmpx][tmpy] != '.')
		cout << "这里不可以走你不知道咩~" << endl;
	else
	{
		swap(maze[tmpx][tmpy], maze[st.x][st.y]);
		swap(tmpx ,st.x);
		swap(tmpy, st.y);
	}
}
