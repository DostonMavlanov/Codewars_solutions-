#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int go[4][2] = {
  0, 1, 
  0, -1, 
  1, 0,
  -1, 0
};


struct Node {
  int x, y;
};

queue<Node> Q;

bool BFS (int length, string maze) {
  while (!Q.empty()) {
    Node now = Q.front();
    Q.pop();
    for (int i = 0; i < 4; ++i) {
      int nx = now.x + go[i][0];
      int ny = now.y + go[i][1];
      if (nx == length - 1 && ny == length - 1) return true;
      if (nx < 0 || nx >= length || ny < 0 || ny >= length) continue;
      if (maze[nx * (length + 1) + ny] == 'W') continue;
      maze[nx * (length + 1) + ny] = 'W';
      Node tmp;
      tmp.x = nx;
      tmp.y = ny;
      Q.push(tmp);
    }
  }
  return false;
}

bool path_finder(string maze) {
  int length = std::floor(std::sqrt( (double) maze.size() ));
  while (!Q.empty()) Q.pop();
  maze[0] = 'W';
  Node tmp;
  tmp.x = tmp.y = 0;
  Q.push(tmp);
  return BFS(length, maze);
  return false;
}