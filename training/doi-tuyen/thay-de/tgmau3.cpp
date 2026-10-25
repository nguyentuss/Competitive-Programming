#include <bits/stdc++.h>

using namespace std;

#define ii pair<int ,int>
#define f first
#define s second
#define MAX_N (int) (2*1e5 + 7)


struct seg{
	int f , s , c;
};

string s;
vector<seg> v; 
int n;
int ke[MAX_N];
int color[MAX_N];


bool cmp(seg &a , seg &b) {
	return (min((a.f - a.s + n)%n , (a.s - a.f + n)%n) < 
		min((b.f - b.s + n)%n , (b.s - b.f + n)%n));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
		cin >> n;
		cin >> s;
		for (int i = 0 ; i < n - 3 ; i++) {
			int x , y , c; cin >> x >> y >> c;
			v.push_back({x - 1, y - 1, c});
		}
		sort(v.begin() , v.end() , cmp);
		for (int i = 0 ; i < s.size() ; i++) {
			ke[i] = (i + 1)%n;
			color[i] = s[i] - '0';
		}
		bool found = false;
		bool check1 = false;
		for (int i = 0 ; i < v.size() ; i++) {
			if (ke[ke[v[i].f]] == v[i].s) {
				if (!(color[v[i].f] != v[i].c && color[ke[v[i].f]] != v[i].c && 
				color[v[i].f] != color[ke[v[i].f]])) {
					check1 = true;
					break;
				}
				ke[v[i].f] = v[i].s;
				ke[ke[v[i].f]] = ke[v[i].f];
				color[v[i].f] = v[i].c;		
			}
			else {
				found = true;
				break;
			}			
		}
		if (found) {
			cout << "neispravna triangularcija" << '\n';
		}
		else {
			if (check1) {
				cout << "neispravno bojenje" << '\n';
			}
			else {
				cout << "tocno" << '\n';
			}
		}

	return 0;
}