#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")

int n , k , x , ans = 0;
vector <int> sum;

struct node {
	node *child[2];
	int cnt;
};

node *creatNode(){
	node *ret = new node;
	ret -> cnt = 0;
	ret -> child[0] = NULL;
	ret -> child[1] = NULL;
	return ret;
}

void travel(int pos , int &value , node *p) {
	int bitv = (value&(1 << pos)) > 0;
	int bitk = (k&(1 << pos)) > 0;
	if (p -> child[bitv] != NULL){
		if (bitk == 1) {
			ans += p-> child[bitv] -> cnt;
			return;
		}
		else {
			travel(pos - 1 , value , p -> child[bitv]);
		}
	}
	if (p -> child[!bitv] != NULL) {
		if (bitk == 1) {
			travel(pos - 1 , value , p -> child[!bitv]);
		}
	}
}

void add(int &value , node *root) {
	node *p = root;
	for (int i = 20 ; i >= 0 ; i--) {
		int b = (value&(1 << i)) > 0;
		if (p -> child[b] == NULL) {
			p -> child[b] = creatNode();
		}
		p = p->child[b];
		p -> cnt++;
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k;
	int ans = 0;
	node *root = creatNode();
	x = 0;
	travel(20 , x , root);
	add(x, root);
	for (int i = 0 ; i < n ; i++) {
		cin >> x;
		if (i == 0) sum.push_back(x);
		else sum.push_back(sum[i - 1]^x);
		travel(20 , sum[i] , root);
		add(sum[i] , root);
	}
	cout << ans;

	return 0;
}