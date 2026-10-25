#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAXN 5005
#define boost ios::sync_with_stdio(0); cin.tie(NULL);
 
priority_queue<long long, vector<long long>, greater<long long> > pq;
 
int main(){
	boost;
    int n;
    long long m;
 
    while(cin >> n && n){
        while(!pq.empty()) pq.pop();
        for(int i = 0; i < n; i ++){
            cin >> m;
            pq.push(m);
        }
        long long sum=0, ans=0, a, b, t;
        while(!pq.empty()){
            a = pq.top();
            pq.pop();
            if(pq.empty()) break;
            b = pq.top();
            pq.pop();
            sum = a + b;
            ans += sum;
            pq.push(sum);
        }
        cout << ans << endl;  
    } 
    return 0;
}