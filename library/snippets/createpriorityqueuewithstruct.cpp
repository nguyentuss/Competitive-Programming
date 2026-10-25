#include <bits/stdc++.h>

using namespace std;

struct segment
{
	int id , l  , r;
};

struct cmp{
	bool operator ()(segment &a , segment &b) {
		return a.id > b.id;
	}
};

priority_queue<segment , vector <segment> , cmp> pq;


int main(){
	pq.push((segment) {2 , 3 , 4});
	pq.push((segment) {5 , 6 , 3});
	pq.push((segment) {1  , 3 , 4});
	cout << pq.top().id;
	return 0;
}