#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100
int V, E;
bool visited[MAX];
int path[MAX];
int u, v;
vector<int> graph [MAX];

void BFS (int s){
  for(int i = 0; i < v ; i++){
      visited[i] = false;
    path[i] = -1;
  }
  queue <int > q;
  visited [s] = true;
  q.push (s);
  while (!q.empty()){
    int u = q.front();
    q.pop ();
    for(int i = 0 ; i < graph[u].size() ; i ++){
        int v = graph[u][i];
        if (!visited [v]){
            visited[v] = true;
            q.push (v);
            path [v] = u;
        }
    }
  
  }
}

void printPath(int s, int f) {
  if(s == f)
    cout<< f << " ";
  else {
    if(path[f] == -1)
      cout << "No path" << endl;
    else{
        printPath (s, path[f]);	
        cout << f << " ";
    }
  }
}

int main (){
    freopen ("INPUT.INP", "rt" , stdin);
    cin >> V >> E;
    for(int i = 0; i < E; i ++){
      cin >> u >> v;	
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  int s = 1;
  int f = 5;
  BFS(s);
  printPath (s, f);
  return 0;
}