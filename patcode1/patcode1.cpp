#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<queue>
bool A[61][1287][129];
bool vis[61][1287][129];
int n, m,k,T;
using namespace std;

class node {
public:
	int x, y, z;
	node() {
		x = y = z = 0;
	}
	node(int X, int Y, int Z) {
		x = X;
		y = Y;
		z = Z;
	}
};
queue<node>q;
int cnt = 0;
void bfs(int x,int y,int z) {
	q.push(node(x,y,z));
	vis[x][y][z] = 1;
	int tcnt = 0;
	while (!q.empty()){
		node t = q.front();
		q.pop();
		tcnt++;
		//cout << t.x << t.y << t.z << endl;
		if (t.x - 1 >= 0) {
			if (vis[t.x - 1][t.y][t.z] == 0&& A[t.x - 1][t.y][t.z] == 1) {
				q.push( node(t.x - 1, t.y, t.z));
				vis[t.x - 1][t.y][t.z] = 1;
			}
		}
		if (t.x + 1 < k) {
			if (vis[t.x + 1][t.y][t.z] == 0 && A[t.x + 1][t.y][t.z] == 1) {
				q.push(node(t.x + 1, t.y, t.z));
				vis[t.x + 1][t.y][t.z] = 1;
			}
		}

		if (t.y + 1 < n) {
			if (vis[t.x][t.y+1][t.z] == 0 && A[t.x][t.y+1][t.z] == 1) {
				q.push(node(t.x, t.y+1, t.z));
				vis[t.x][t.y+1][t.z] = 1;
			}
		}
		if (t.y - 1 >= 0) {
			if (vis[t.x][t.y - 1][t.z] == 0 && A[t.x][t.y-1][t.z] == 1) {
				q.push(node(t.x, t.y - 1, t.z));
				vis[t.x][t.y - 1][t.z] = 1;
			}
		}
		if (t.z + 1 < m) {
			if (vis[t.x][t.y][t.z+1] == 0 && A[t.x][t.y][t.z+1] == 1) {
				q.push(node(t.x, t.y , t.z+1));
				vis[t.x][t.y][t.z+1] = 1;
			}
		}
		if (t.z - 1 >= 0) {
			if (vis[t.x][t.y][t.z-1] == 0 && A[t.x][t.y][t.z-1] == 1) {
				q.push(node(t.x, t.y, t.z-1));
				vis[t.x][t.y][t.z-1] = 1;
			}
		}

	}
	
	if (tcnt >= T)cnt += tcnt;
}
int main()
{
	freopen("./test.txt", "r", stdin);
	scanf("%d %d %d %d",&n,&m,&k,&T);
	for (int i = 0; i < k; i++) 
		for (int j = 0; j < n; j++){
			for (int v = 0; v < m; v++) {
				int t;
				scanf("%d", &t);
				//cout << t << " ";
				if (t == 1)A[i][j][v] = true;
			}
		//cout << endl;
		}
	for (int i = 0; i<k; i++)
		for (int j = 0; j<n; j++)
			for (int v = 0; v < m; v++) {
				if (vis[i][j][v] == 0 && A[i][j][v] == 1)bfs(i, j, v);
			}
	printf("%d",cnt);
    return 0;
}


