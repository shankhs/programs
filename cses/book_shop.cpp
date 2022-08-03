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

int solve(int x, vector<int> h, vector<int> s, int start, std::unordered_map<int, int>& table)
{
    if (x <= 0) {
        return 0;
    }
    int pages = 0;
    for (int i = start; i < sz(h); i++) {
        if (h[i] <= x) {
            if (table.find(x) != table.end()) {
                //std::cout << "Not recurring for " << x << std::endl;
                pages = max(pages, table[x]);
            } else {
                std::cout << "Recurring for " << x << std::endl;
                pages = max(pages, s[i] + solve(x - h[i], h, s, i + 1, table));
            }
        }
    }
    table[x] = pages;
    //std::cout << x << " "<<start<<" " << table[x] << std::endl;
    return table[x];
}

int solve(int x, vector<int> h, vector<int> s)
{
    int n = sz(h);
    vector<vector<int>> table(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < x + 1; j++) {
            if (h[i - 1] <= j) {
                //std::cout << i << " " << j << " " << table[i - 1][j] << " " << s[i - 1] + table[i - 1][j - h[i - 1]] << std::endl;
                table[i][j] = max(table[i - 1][j], s[i - 1] + table[i - 1][j - h[i - 1]]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    //for (int i = 0; i < n + 1; i++) {
    //  for (int j = 0; j < x + 1; j++) {
    //    std::cout << table[i][j] << " ";
    //}
    //std::cout << std::endl;
    //}
    return table[n][x];
}

int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int x;
    if (!(cin >> x)) {
        return 1;
    }
    std::vector<int> h;
    for (int i = 0; i < n; i++) {
        int hi;
        if (!(cin >> hi)) {
            return 1;
        }
        h.push_back(hi);
    }

    std::vector<int> s;
    for (int i = 0; i < n; i++) {
        int si;
        if (!(cin >> si)) {
            return 1;
        }
        s.push_back(si);
    }

    std::unordered_map<int, int> table;
    // return solve(x, h, s, /*start=*/0, table);
    return solve(x, h, s);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve() << endl;
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
