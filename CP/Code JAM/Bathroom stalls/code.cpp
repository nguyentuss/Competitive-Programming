#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	long long n , t , k , half1 , half2 , maxval ; 
	cin >> t;

	for (int i = 1 ; i <= t ; i ++) {
		bool check = true;
		cin >> n >> k;
		map <long long , long long> m;
		priority_queue <long long> pq;
		pq.push(n);
		m[pq.top()] ++;
		//cout << m[pq.top()] << " " ;
		while (check){
			maxval = pq.top();
			//cout << maxval << " " << m[maxval] << endl;
			pq.pop();
			if (k <= m[maxval]) {
				half1 = maxval / 2;
				half2 = maxval - half1 - 1;
				//cout << half1 << " " << half2 << endl;
				cout << "Case #" << i << ": " << half1 << " " << half2 << endl;
				check = false;
				break;
			}
			else {
				k -= m[maxval];
				half1 = maxval / 2;
				half2 = maxval - half1 - 1;
				if (m[half1] == 0) 
					pq.push(half1);
				

				m[half1] += m[maxval];
				if (m[half2] == 0) 
					pq.push(half2);
				m[half2] += m[maxval]; 
				

			}
		}

	}

	return 0;
}