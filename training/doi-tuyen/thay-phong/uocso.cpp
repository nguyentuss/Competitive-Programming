#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (1e6 + 2)
long long n, res;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector <bool> eratosthenes(MAX_N, false);
	vector <int> snt;
	for (int i = 2; i <= MAX_N; i++)
		if (!eratosthenes[i])
		{ 
			snt.push_back(i);
			for (int j=i*2;j<=MAX_N;j+=i)
				eratosthenes[j]=true;
		}
	for (int i = 0; i < (int) snt.size() ; i++)
		if (snt[i]*snt[i] <= n)
			res+=1;
		else break;
	cout << res;
	return 0;
}