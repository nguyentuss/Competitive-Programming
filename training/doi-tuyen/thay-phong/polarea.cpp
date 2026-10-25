#include <bits/stdc++.h>

using namespace std;

struct pos {
	double x , y;
};

struct vec {
	double x , y;
	int id;
};

pos origin;
vector <pos> v;

bool IsClockwise(vector <pos> v)
{
    double sum = 0.0;
    for (int i = 0; i < v.size() ; i++) {
        pos v1 = v[i];
        pos v2 = v[(i + 1) % v.size()];
        sum += (v2.x - v1.x) * (v2.y + v1.y);
    }
    return sum > 0.0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);	
	int n; cin >> n;
	int xmin = INT_MAX;
	vec tmp;
	for (int i = 0 ; i < n ; i++) {
		double x , y; cin >> x >> y;
		v.push_back({x , y});
	}
	double tc = 0;
	int j = n - 1;
	for (int i = 0 ; i < v.size(); i++) {
        tc += (v[j].x + v[i].x) * (v[j].y - v[i].y);
        j = i;
    }
    double x = abs(tc/2.0);
    if (IsClockwise(v)) cout << "CW ";
    else cout << "CCW ";
    cout << fixed << setprecision(1) << x;
	return 0;
}