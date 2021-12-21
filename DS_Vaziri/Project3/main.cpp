#include <iostream>
#include "Node.hpp"
#include <stack>
#include <cstring>
using namespace std;

#define N 4
#define M 5
int n = N, m = M, fx, fy;

bool visited[N][M];

bool isReachable(int maze[N][M]) {
	int i = 0, j = 0;
	
	stack<Node> s;
	
	Node temp(i, j);
	
	s.push(temp);

	while (!s.empty()) {

		temp = s.top();
		int d = temp.return_dir();
		i = temp.return_x(), j = temp.return_y();


		temp.dir_incre();
		s.pop();
		s.push(temp);

		if (i == fx and j == fy) {
			return true;
		}

		if (d == 0) {
			if (i - 1 >= 0 and maze[i - 1][j] and
									visited[i - 1][j]) {
				Node temp1(i - 1, j);
				visited[i - 1][j] = false;
				s.push(temp1);
			}
		}

		else if (d == 1) {
			if (j - 1 >= 0 and maze[i][j - 1] and
									visited[i][j - 1]) {
				Node temp1(i, j - 1);
				visited[i][j - 1] = false;
				s.push(temp1);
			}
		}

		else if (d == 2) {
			if (i + 1 < n and maze[i + 1][j] and
									visited[i + 1][j]) {
				Node temp1(i + 1, j);
				visited[i + 1][j] = false;
				s.push(temp1);
			}
		}
		else if (d == 3) {
			if (j + 1 < m and maze[i][j + 1] and
									visited[i][j + 1]) {
				Node temp1(i, j + 1);
				visited[i][j + 1] = false;
				s.push(temp1);
			}
		}


		else {
			visited[temp.return_x()][temp.return_y()] = true;
			s.pop();
		}
	}

	return false;
}

int main()
{

	memset(visited, true, sizeof(visited));
	int maze[N][M] = {
		{ 1, 0, 1, 1, 0 },
		{ 1, 1, 1, 0, 1 },
		{ 0, 1, 0, 1, 1 },
		{ 1, 1, 1, 1, 1 }
	};

	fx = 2;
	fy = 3;

	if (isReachable(maze)) {
		cout << "Path Found!" << '\n';
	}
	else
		cout << "No Path Found!" << '\n';
		
	return 0;
}
