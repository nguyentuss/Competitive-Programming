#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map <char , int> m;
string s , v;

struct node {
	bool isEnd;
	node *child[4];
};

node *createNode() {
	node *ret = new node;
	ret -> isEnd = false;
	for (int i = 0 ; i < 4 ; i++) {
		ret -> child[i] = NULL;
	}
	return ret;
}

int findPos(char x) {
	return m[x];
}

bool isFound(string &v , node *root) {
	node *p = root;
	for (int i = 0 ; i < (int) v.size() ; i++) {
		int pos = findPos(v[i]);
		if (p-> child[pos] == NULL) 
			return false;
		p = p -> child[pos];
	}
	return p -> isEnd;
}

void add(node *root , string &s) {
	node *p = root;
	for (int i = 0 ; i < (int) s.size() ; i++) {
		int pos = findPos(s[i]);
		if (p -> child[pos] == NULL) {
			p->child[pos] = createNode();
		}
		p = p->child[pos];
		if (i == (int) s.size() - 1) {
			p -> isEnd = true;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(NULL);
	m['A'] = 0 , m['C'] = 1 , m['G'] = 2 , m['T'] = 3;	
	node *root = createNode();
	int qs , qv; cin >> qs;
	for (int i = 0 ; i < qs; i++) {
		cin >> s;
		add(root , s);
	}	
	cin >> qv;
	for (int i = 0  ; i < qv ; i++){
		cin >> v; 
		if (isFound(v , root)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}	