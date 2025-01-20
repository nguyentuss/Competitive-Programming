#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1e9
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
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int r, c, n;
vector<string> matrix;
vector<pair<int, int>> pos;
vector<vector<int>> dist(101, vector<int>(101, -1));
vector<vector<int>> D(101, vector<int>(101, 0));

void bfs(int idx)
{
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
        {
            dist[i][j] = -1;
        }
    queue<pair<int, int>> q;
    int sx = pos[idx].first;
    int sy = pos[idx].second;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (0 <= xx && xx < r && 0 <= yy && yy < c)
            {

                if (matrix[xx][yy] != '#' && dist[xx][yy] == -1)
                {
                    dist[xx][yy] = dist[x][y] + 1;
                    q.push({xx, yy});
                }
            }
        }
    }
    for (int j = 0; j < pos.size(); ++j)
    {
        int tx = pos[j].first;
        int ty = pos[j].second;
        if (dist[tx][ty] != -1)
        {
            D[idx][j] = dist[tx][ty];
        }
        else
        {
            D[idx][j] = INF;
        }
    }
}

void start()
{
    cin >> r >> c >> n;
    matrix.resize(r);
    for (int i = 0; i < r; ++i)
    {
        cin >> matrix[i];
    }
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (matrix[i][j] == 'S')
            {
                pos.push_back({i, j});
            }
        }
    }
    n = pos.size();
    pos.push_back({0, 0});
    bool flag = true;

    for (int i = 0; i <= n; ++i)
    {
        bfs(i);
    }
    for (int i = 0; i < n; ++i)
    {
        if (D[n][i] == INF)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << -1 << endl;
        return;
    }
    int mask_size = 1ll << n;
    vector<vector<int>> dp(mask_size, vector<int>(n, INF));
    for (int i = 0; i < n; ++i)
        dp[1 << i][i] = D[n][i];
    for (int mask = 0; mask < mask_size; ++mask)
    {
        for (int u = 0; u < n; ++u)
        {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 0; v < n; ++v)
            {
                if (mask & (1 << v))
                    continue;
                if (D[u][v] == INF)
                    continue;
                int nxt = mask | (1 << v);
                if (dp[nxt][v] > dp[mask][u] + D[u][v])
                {
                    dp[nxt][v] = dp[mask][u] + D[u][v];
                }
            }
        }
    }
    int ans = INF;
    for (int u = 0; u < n; ++u)
    {
        if (dp[(1 << n) - 1][u] < ans)
        {
            ans = dp[(1 << n) - 1][u];
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    }
    else cout << ans << endl;
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
