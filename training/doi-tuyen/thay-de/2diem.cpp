#include <bits/stdc++.h>

using namespace std;

#define ii pair<double ,double>
#define f first
#define s second

ii A , B;

double dist(ii x , ii y) {
	return (sqrt((x.f - y.f)*(x.f - y.f) + (x.s - y.s)*(x.s - y.s)));
}

void pt(ii x , ii y) {
	int a = x.s - y.s , b = y.f - x.f;
	int c = -(a*x.f + b*x.s);
	cout << a << " " << b << " " << c;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> A.f >> A.s >> B.f >> B.s;
	cout << dist(A , B) << '\n';
	pt(A , B);
	return 0;
}