#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	long long t , n , k , x , a , b; ; cin >> t;
	for (long long j = 1 ; j <= t ; j ++){
		cin >> n >> k;
		priority_queue <long long> pq;
		pq.push(n);
		for (long long i = 1; i <= k ; i++){
			x = pq.top();
			pq.pop();
			a = x / 2;
			b = x - a - 1;
			pq.push(a); pq.push(b);
		}
		cout << "Case #" << j << ": " <<  a << " " << b << endl;
	}
	return 0;
}