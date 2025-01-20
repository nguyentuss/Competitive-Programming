#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")

const long long MAX_SIZE = 10000007;

vector<long long>isprime(MAX_SIZE , true);
vector<long long>prime;
vector<long long>SPF(MAX_SIZE);

// function generate all prime number less then N in O(n)
void manipulated_seive(int N)
{
	isprime[0] = isprime[1] = false ;
	for (long long int i=2; i<N ; i++)
	{
		if (isprime[i])
		{
			prime.push_back(i);
			SPF[i] = i;
		}

		for (long long int j=0;
			j < (int)prime.size() &&
			i*prime[j] < N && prime[j] <= SPF[i];
			j++)
		{
			isprime[i*prime[j]]=false;
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	int N = MAX_SIZE;

	manipulated_seive(N);

	int q; cin >> q;
	for (int i = 1 ; i <= q ; i++) {
		int x; cin >> x;
		if (isprime[x]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
