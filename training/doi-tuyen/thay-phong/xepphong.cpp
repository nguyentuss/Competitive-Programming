#include <bits/stdc++.h>
using namespace std;

int n,a;
int main()
{
	ios::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <int> m(5);
	for (int i = 1 ; i <= n ;i++) 
	{
		cin >> a;
		m[a]++;
	}
	m[1] -= min(m[1] , m[3]);
	m[2] *= 2;
	int tmp = m[2]%4;
	m[2] += min(tmp , m[1]);
	m[1] -= min(tmp , m[1]);
	m[2] = (m[2] + 3)/4;
	m[1] = (m[1] + 3)/4;
	cout << m[1] + m[2] + m[3] + m[4];
	return 0;
}