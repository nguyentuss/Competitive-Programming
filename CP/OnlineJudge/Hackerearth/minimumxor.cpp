#include <bits/stdc++.h>

using namespace std;

struct node{
	int cnt;
	node *child[2];
};
long long x;
int q , k;
int cnt[2] = {0 , 1};

node *createNode() {
	node *ret = new node();
	ret ->cnt = 0;
	for (int i = 0 ; i < 2 ; i++) {
		ret -> child[i] = NULL;
	}
	return ret;
}
void add(node *root , const long long &X) {
	node *p = root;
	for (int i = 63 ; i >= 0 ; i--) {
		int bit = 0;
		if ((X & (1LL << i)) > 0) {
			bit = 1;
		}
		if (p -> child[bit] == NULL) 
			p ->child[bit] = createNode();
		p = p -> child[bit];
		p -> cnt ++;
	}
	return;
}

long long isfound(node *root , const long long &X , const int &k){
	long long ret = 0LL;
	node *p = root;
	int order = k;
	for (int i = 63 ; i >= 0 ; i--) {
		int bit = 0;
		if ((X & (1LL << i))>0) bit = 1;
		int bit0 = bit , bit1 = bit^1 , nextbit;
		ret = ret*2LL;
		if (bit0 < bit1) {
			if (p->child[0] != NULL && p->child[0]->cnt >= order) {
				nextbit = 0;
			}
			else {
				nextbit = 1;
				if (p->child[0] != NULL) {
					order -= p->child[0]->cnt;
				}
				ret++;
			}
		}
		else {
			if (p->child[1] != NULL && p->child[1]->cnt >= order) {
				nextbit = 1;
			}
			else {
				nextbit = 0;
				if (p->child[1] != NULL) {
					order -= p->child[1]->cnt;
				}
				ret++;	
			}
		}
		p = p->child[nextbit];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> q;
	node *root = createNode();
	int ask;
	for (int i = 1 ; i <= q ; i++) {
		cin >> ask ;
		if (ask == 1) {
			cin >> x;
			add(root , x);
		}
		else {
			cin >> x >> k;
			cout << isfound(root , x , k) << '\n';
		}
	}

	return 0;
}