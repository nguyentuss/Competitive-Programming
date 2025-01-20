#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define oo (int) 1e5;

struct segment{
	int posx , posy;
};

int n , m;
char arr[51][51];
int dist[51][51];
segment posrobot , posexit;

void init() {
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= m ; j++) {
			dist[i][j] = oo;
		}
	}
}

void trace(int i , int j) {
		
}

void calc(int left , int right) {
	init();
	queue <segment> q;
	q.push((segment) {left , right});
	dist[left][right] = 0;
	while (!q.empty()) {
		int i = q.front().posx;
		int j = q.front().posy;
		q.pop();
		if (arr[i][j + 1] != '#' && j + 1 <= m && dist[i][j + 1] > dist[i][j] + 1) {
			q.push((segment) {i , j + 1});
			dist[i][j + 1] = dist[i][j] + 1;
		}
		if (arr[i][j - 1] != '#' && j - 1 > 0 && dist[i][j - 1] > dist[i][j] + 1) {
			q.push((segment) {i , j - 1});
			dist[i][j - 1] = dist[i][j] + 1;
		}
		if (arr[i - 1][j] != '#' && i - 1 > 0 && dist[i - 1][j] > dist[i][j] + 1) {
			q.push((segment) {i - 1 , j});
			dist[i - 1][j] = dist[i][j] + 1;
		}
		if (arr[i + 1][j] != '#' && i + 1 <= n && dist[i + 1][j] > dist[i][j] + 1) {
			q.push((segment) {i + 1 , j});
			dist[i + 1][j] = dist[i][j] + 1;
		}
	}
	trace(posrobot.posx , posrobot.posy);
	/*for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1 ; i <= n; i++) {
		for (int j = 1 ; j <= m ; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'R') {
				posrobot.posx = i;
				posrobot.posy = j;
			}
			if (arr[i][j] == 'E') {
				posexit.posx = i;
				posexit.posy = j;
			}
		}
	}	
	char command;
	segment run;
	run.posx = posrobot.posx;
	run.posy = posrobot.posy;
	string noname = "";
	string s;
	cin >> s;
	for (int i = 0 ; i < (int) s.size(); i++) {
		command = s[i];
		if (command == 'R' && arr[run.posx][run.posy + 1]  != '#' && run.posy + 1 <= m) {
			noname += command;
			run.posy ++;
		}
		else if (command == 'L' && arr[run.posx][run.posy - 1] != '#' && run.posy - 1 > 0) {
			noname += command;
			run.posy --;
		}
		else if (command == 'U' && arr[run.posx - 1][run.posy] != '#' && run.posx - 1 > 0) {
			noname += command;
			run.posx --;
		}
		else if (command == 'D' && arr[run.posx + 1][run.posy] != '#' && run.posx + 1 <= n) {
			noname += command;
			run.posx ++;
		}
		if (run.posx == posexit.posx && run.posy == posexit.posy) {
			cout << 0;	
			return 0;
		}
	}
	calc(posrobot.posx , posrobot.posy);
	return 0;
}