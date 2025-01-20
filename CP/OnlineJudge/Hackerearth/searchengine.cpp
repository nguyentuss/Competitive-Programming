#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n , q , weight;
map <char , int> m;
string s , v;

struct node {
	bool isEnd;
	int maxiWeight = -1;
	node *child[26];
};

void init(){
	for (int i = 'a' ; i <= 'z' ; i++) 
		m[i] = i - 'a';
}

int findpos(char x) {
	return m[x];
}


node *creatNode(){
	node *ret = new node;
	ret -> isEnd = false;
	for (int i = 0 ; i < 26 ; i++) {
		ret -> child[i] = NULL;		
	}
	return ret;
}

int isFound( string &v , node* root) {
	node *p = root;
	for (int i = 0 ; i < (int) v.size() ; i ++) {
		int pos = findpos(v[i]);
		if (p -> child[pos] == NULL) 
			return -1;
		p = p -> child[pos];
	}
	return p->maxiWeight;
}

void add(string &s , node *root , int weight) {
	node *p = root;
	p->maxiWeight = max(p->maxiWeight , weight);
	for (int i = 0 ; i < (int) s.size() ; i++) {
		int pos = findpos(s[i]);
		if (p -> child[pos] == NULL) 
			p -> child[pos] = creatNode();
		p = p -> child[pos];
		p -> maxiWeight = max(p->maxiWeight , weight);
		if (i == (int) s.size() - 1) {
			p -> isEnd = true;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	init();
	cin >> n >> q;
	node *root = creatNode();
	for (int i = 0 ; i < n; i++) {
		cin >> s >> weight;
		add(s , root , weight);
	}
	for (int i = 0 ; i < q ; i++) {
		cin >> v;
		cout << isFound(v , root) << endl;
	}
	return 0;
}