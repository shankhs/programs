#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
#define MAXINT (INT_MAX - 1000)

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int solve(const std::vector<string>& grid, int start_x, int start_y, vector<vector<int>>& table)
{
    if (start_x == sz(grid) - 1 && start_y == sz(grid) - 1) {
        return 1;
    }
    if (table[start_x][start_y] != -1) {
        return table[start_x][start_y];
    }
    int total = 0;
    if (start_x + 1 < sz(grid) && grid[start_x + 1][start_y] != '*') {
        total = (total + solve(grid, start_x + 1, start_y, table)) % mod;
    }
    if (start_y + 1 < sz(grid) && grid[start_x][start_y + 1] != '*') {
        total = (total + solve(grid, start_x, start_y + 1, table)) % mod;
    }
    table[start_x][start_y] = total % mod;
    return table[start_x][start_y];
}

int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    std::vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grid[i];
    }
    if (grid[0][0] == '*') {
        return 0;
    }
    std::vector<std::vector<int>> table(n);
    for (int i = 0; i < n; i++) {
        std::vector<int> v(n, -1);
        table[i] = v;
    }
    return solve(grid, 0, 0, table);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout << max(solve(), 0) << std::endl;
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
