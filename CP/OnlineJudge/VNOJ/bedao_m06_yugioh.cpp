
#include <bits/stdc++.h>
using namespace std;

#define MAX_N (int) (1e6 + 7)

int n , k;
int arr[MAX_N];

bool is_prime(int x)
{
    if (x <= 1)
        return false;
    if (x <= 3)
        return true;
  
    if (x % 2 == 0 || x % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= x; i = i + 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
  
    return true;
}

int minSwap() {
	int count = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] <= k && is_prime(arr[i])) ++count;
	}
	int bad = 0;
	for (int i = 0; i < count; i++){
		if (arr[i] > k || (arr[i] <= k && !is_prime(arr[i])))
			++bad;
	}
	int ans = bad;
	for (int i = 0, j = count; j < n; i++, j++) {
		if (arr[i] > k || (arr[i] <= k && !is_prime(arr[i])))
			--bad;
		
		if (arr[j] > k || (arr[j] <= k && !is_prime(arr[j])))
			++bad;
		ans = min(ans, bad);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0 ; i < n ;i++) cin >> arr[i];
	cout << minSwap();
	return 0;
}
