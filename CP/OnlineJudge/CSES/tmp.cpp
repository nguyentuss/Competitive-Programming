#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF INT_MAX
#define int long long
typedef vector<int> vi;
typedef pair<int, int> pi;
#define f first
#define s second
#define pb push_back
#define POB pop_back
#define mp make_pair
const int MOD = 1e9 + 7;
/*
.______        ___      .______      .______        ______   .___________..___________.  ______        _______.
|   _  \      /   \     |   _  \     |   _  \      /  __  \  |           ||           | /  __  \      /       |
|  |_)  |    /  ^  \    |  |_)  |    |  |_)  |    |  |  |  | `---|  |----``---|  |----`|  |  |  |    |   (----`
|   ___/    /  /_\  \   |      /     |      /     |  |  |  |     |  |         |  |     |  |  |  |     \   \
|  |       /  _____  \  |  |\  \----.|  |\  \----.|  `--'  |     |  |         |  |     |  `--'  | .----)   |
| _|      /__/     \__\ | _| `._____|| _| `._____| \______/      |__|         |__|      \______/  |_______/
*/
void start()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> b(k, vector<int>());
    vector<int> prev(k, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> a(k);
        for (int j = 0; j < k; j++)
            cin >> a[j];
        for (int j = 0; j < k; j++)
        {
            int val = prev[j] | a[j];
            b[j].push_back(val);
            prev[j] = val;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < k ; j++) {
            cout << b[j][i] << " ";
        }
        cout << '\n';
    }

    while (q--)
    {
        int m;
        cin >> m;
        int l = 1;
        int r = n;
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            int j, c;
            char o;
            cin >> j >> o >> c;
            j--;
            if (j < 0 || j >= k)
            {
                flag = true;
                continue;
            }
            if (o == '<')
            {
                r = min(r, upper_bound(b[j].begin(), b[j].end(), c - 1) - b[j].begin());
            }
            else if (o == '>')
            {
                l = max(l, (upper_bound(b[j].begin(), b[j].end(), c) - b[j].begin() + 1));
            }
            else
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }
        if (l <= r && l >= 1 && l <= n)
        {
            cout << l << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("", "r", stdin);
    // freopen("", "w", stdout);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        start();
    }
    return 0;
}
