#include <iostream>
#include "Node.hpp"
#include <stack>
#include <ctime>
#include <unistd.h>
#include <cstring>
using namespace std;
#define M 5
#define N 4
int n = N, m = M, dx=0, dy=0;
bool visited[N][M];
int isReachable(int maze[N][M]) {
	int i = 0, j = 0;
	stack<Node> path;
	Node temp(i, j);
	path.push(temp);
	while (!path.empty()) {
		temp = path.top();
		int d = temp.return_dir();
		i = temp.return_x(), j = temp.return_y();
		temp.dir_incre();
		path.pop();
		path.push(temp);
		if (i ==dx && j == dy)		return true;
		if (d == 0) {
			if (i - 1 >= 0 && maze[i - 1][j] && visited[i - 1][j]) {
				Node temp1(i - 1, j);
				visited[i - 1][j] = false;
				path.push(temp1);
			}
		}
		else if (d == 1) {
			if (j - 1 >= 0 && maze[i][j - 1] && visited[i][j - 1]) {
				Node temp1(i, j - 1);
				visited[i][j - 1] = false;
				path.push(temp1);
			}
		}
		else if (d == 2) {
			if (i + 1 < n && maze[i + 1][j] && visited[i + 1][j]) {
				Node temp1(i + 1, j);
				visited[i + 1][j] = false;
				path.push(temp1);
			}
		}
		else if (d == 3) {
			if (j + 1 < m && maze[i][j + 1] && visited[i][j + 1]) {
				Node temp1(i, j + 1);
				visited[i][j + 1] = false;
				path.push(temp1);
			}
		}
		else {
			visited[temp.return_x()][temp.return_y()] = true;
			path.pop();
		}
	}
	return false;
}

int main()
{
	memset(visited, true, sizeof(visited));
	int maze[N][M];
	srand(time(NULL));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			maze[i][j]=rand()%2;

	cout << "\033[1;37;41m!! 1 is available node and 0 is unavailable node !!\033[0m\n";
	while((dx==0 && dy==0) || maze[dx][dy]==0) {
		dx = rand()%4;
		dy = rand()%5;
	}
	cout << "destination is set on (" << dx << ", " << dy << ")\n";
	cout << "start point is set to green and end point is set to pink\n";
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(i==0 && j==0 && maze[0][0]!=0)	cout << "\033[1;30;42m" << maze[0][0] << "\033[0m ";
			else if(i==0 && j==0 && maze[0][0]==0)	cout << "\033[1;37;41m" << maze[0][0] << "\033[0m ";
			else if(i==dx && j==dy)		cout << "\033[1;30;45m" << maze[dx][dy] << "\033[0m ";
			else	cout << maze[i][j] << " ";
		}
		cout << endl;
	}

	if(maze[0][0]==true){
		if (isReachable(maze)) 		cout << "Found!" << '\n';
		else 	cout << "Nothing was Found!" << '\n';
	}
	else	cout << "\033[1;37;41mEntrance node is unavailable\nrat is not in the maze!\033[0m\n";
	sleep(5);
	system("clear");
	return 0;
}
