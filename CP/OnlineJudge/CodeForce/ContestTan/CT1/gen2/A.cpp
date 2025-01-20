#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 3;

int n, state;
int a[4][N], cnt = 0, cnt2 = 0, cnt3 = 0;

bool check(int x, int y, int z)
{
    return (x + y > z) && (y + z > x) && (z + x > y);
}

void xuat()
{
    for (int i = 1; i <= 3; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

/// trau
void cal1()
{
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            for (int k = 1; k <= n; ++ k)
                if (a[1][i] == a[2][j] && a[2][j] == a[3][k])
                    ++ cnt;
    cout << cnt;
}



void cal2()
{
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            for (int k = 1; k <= n; ++ k)
                if ((a[1][i] == a[2][j] || a[2][j] == a[3][k] || a[3][k] == a[1][i]) && check(a[1][i], a[2][j], a[3][k]))
                    ++ cnt;
    cout << cnt;
}

void cal3()
{
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            for (int k = 1; k <= n; ++ k)
                if (check(a[1][i], a[2][j], a[3][k]))
                    ++ cnt;
    cout << cnt;
}
/// ---

/// sol
void sol1(bool ok)
{
    map <int, int> m1, m2, m3;
    for (int i = 1; i <= n; ++ i)
    {
        ++ m1[a[1][i]];
    }
    for (int i = 1; i <= n; ++ i)
    {
        ++ m2[a[2][i]];
    }
    for (int i = 1; i <= n; ++ i)
    {
        ++ m3[a[3][i]];
    }
    for (int i = 1; i <= n; ++ i)
    {
        cnt = cnt + m1[a[1][i]] * m2[a[1][i]] * m3[a[1][i]];
        m1[a[1][i]] = m2[a[1][i]] = m3[a[1][i]] = 0;
    }
    if (ok == 1)
        cout << cnt;
}

int findRight(int x, int val)
{
    int l = 1, r = n, res = 0;
    if (val < a[x][1])
    {
        return 0;
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[x][mid] <= val)
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

int findLeft(int x, int val)
{
    int l = 1, r = n, res = 0;
    if (val > a[x][n])
    {
        return 0;
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[x][mid] >= val)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

void process(int x, int y)
{
    int z = 6 - x - y;
//    cout << x << ' ' << y << endl;
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            if (a[x][i] == a[y][j])
            {
//                cout << "*" << i << ' ' << j << endl;
                int r = findRight(z, 2 * a[x][i] - 1);
                cnt2 = cnt2 + r;
            }
        }
    }
}

void sol2()
{
    sort (a[1] + 1, a[1] + n + 1);
    sort (a[2] + 1, a[2] + n + 1);
    sort (a[3] + 1, a[3] + n + 1);
//    xuat();
    process(1, 2);
    process(2, 3);
    process(3, 1);
    cout << cnt2 - 2 * cnt;
}

void sol3()
{
    sort (a[1] + 1, a[1] + n + 1);
    sort (a[2] + 1, a[2] + n + 1);
    sort (a[3] + 1, a[3] + n + 1);
    /// 1 2
//    xuat();
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
//            cout << "*" << a[1][i] << ' ' << a[2][j] << endl;
            int l = findLeft(3, abs(a[1][i] - a[2][j]) + 1);
            int r = findRight(3, a[1][i] + a[2][j] - 1);
//            cout << "**" << l << ' ' << r << endl;
            if (l != 0 && r != 0)
                cnt3 = cnt3 + max(0, r - l + 1);
        }
    }
    cout << cnt3;
}

/// ---

int main()
{
    freopen("input.inp","r",stdin);
    freopen("A.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> state;
    for (int i = 1; i <= 3; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            cin >> a[i][j];
        }
    }
    if (n <= 100)
    {
        if (state == 1) cal1();
        else if (state == 2) cal2();
        else cal3();
    }
    else
    {
        if (state == 1) sol1(1);
        else if (state == 2)
        {
            sol1(0);
            sol2();
        }
        else sol3();
    }
}
