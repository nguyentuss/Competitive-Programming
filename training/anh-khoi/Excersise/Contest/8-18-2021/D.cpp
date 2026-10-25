#include <bits/stdc++.h> 

using namespace std; 

const int N = 1e5 + 10;
int h[N];
bool mark[N];
string s;
vector<int> adj[N], vec[10];

void BFS(int u){
	queue<int> q;
	q.push(u);
	mark[0] = 1;
	while(q.size()){
		int v = q.front();
		if(v == s.size() - 1){
			return;
		}
		q.pop();
		for(auto x : vec[s[v] - '0']){
			if(!mark[x]){
				h[x] = h[v] + 1;
				mark[x] = 1;
				q.push(x);
			}
		}
		vec[s[v] - '0'].clear();
		if(v + 1 < s.size() && !mark[v + 1]){
			h[v + 1] = h[v] + 1;
			mark[v + 1] = 1;
			q.push(v + 1);
		}
		if(v - 1 > -1 && !mark[v - 1]){
			h[v - 1] = h[v] + 1;
			mark[v - 1] = 1;
			q.push(v - 1);
		}
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		vec[s[i] - '0'].push_back(i);
	}
	BFS(0);
	cout << h[s.size() - 1] << "\n";
	return 0;
}