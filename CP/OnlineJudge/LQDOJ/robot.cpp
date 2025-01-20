#include <iostream>
    #include <queue>
    #include <cmath>
    #include <algorithm>
    #include <utility>
    #include <functional>
    #include <vector>
    #include <stdio.h>

    using namespace std;

    #pragma GCC optimize("Ofast")
    #define oo (long long ) (1e18 + 7)

    struct pos {
        long long  x , y;
    };
    struct segment{
        long long  x , y;
    };

    long long  n , m , k;
    vector <vector <long long >> v(5000 , vector <long long > (5000));
    vector <vector <long long >> dist(5000 , vector <long long > (5000));
    vector <vector <long long >> go(5000 , vector<long long > (5000 , -1));
    vector <pos> adj;
    queue <segment> pq;

    void init() {
        for (long long  i = 1 ; i <= n ; i++)
            for (long long  j = 1 ; j <= m ; j++)
                dist[i][j] = oo;
    }

    void distance(int i , int j , int X , int Y) {
    	if (i > 0 && i <= n && j > 0 && j <= m) {
    		if (dist[X][Y] >= v[i][j] && dist[X][Y] + 1 < dist[i][j]) {
    			dist[i][j] = dist[X][Y] + 1;
    			pq.push((segment) {i , j});
    		}
    		else if (dist[X][Y] < v[i][j] && v[i][j] < dist[i][j]) {
    			dist[i][j] = v[i][j];
    			pq.push((segment) {i , j});
    		}
    	}
    }

    void calc(long long  startx , long long  starty) {
        init();
        pq.push((segment) {startx , starty});
        dist[startx][starty] = 0;
        while (!pq.empty()) {
            long long  i = pq.front().x;
            long long  j = pq.front().y;
            pq.pop();
            distance(i + 1 , j + 1 , i , j);
            distance(i + 1 , j - 1 , i , j);
            distance(i - 1 , j - 1 , i , j);
            distance(i - 1 , j + 1 , i , j);
            distance(i , j + 1 , i , j);
            distance(i , j - 1 , i , j);
            distance(i + 1 , j , i , j);
            distance(i - 1 , j , i , j);

        }
        for (long long  i = 1 ; i <= n ; i++) {
            for (long long  j = 1 ; j <= m ; j++)
                go[i][j] = max(go[i][j] , dist[i][j]);
        }
    }

    int main(){
        cin >> n >> m >> k;
        for (long long  i = 1; i <= n; i++) {
            for (long long  j = 1 ; j <= m; j ++) {
                cin >> v[i][j];
                if (v[i][j] == -1) {
                    adj.push_back((pos) {i , j});
                }
            }
        }
        long long  ans = oo;
        for (long long  i = 0 ; i < (long long ) adj.size() ; i++) calc(adj[i].x , adj[i].y);
        //for (int i = 0 ; i < (int) adj.size(); i++) cout << adj[i].x << " " << adj[i].y << endl;
        for (long long  i = 1 ; i <= n; i++) {
            for (long long  j = 1 ; j <= m ; j ++) {
                ans = min(ans , go[i][j]);
            }
        }
        cout << ans;
        return 0;
    }