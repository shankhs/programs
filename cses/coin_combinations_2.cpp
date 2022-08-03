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
    std::vector<int> c;
    for (int i = 0; i < n; i++) {
        int ci;
        if (!(cin >> ci)) {
            return 1;
        }
        c.push_back(ci);
    }
    sort(c.begin(), c.end());
    ll mod = 1e9 + 7;
    std::vector<ll> table(x + 1, 0);
    table[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = c[0]; j < x + 1; j++) {
            if (j - c[i] >= 0) {
                table[j] = (table[j] + table[j - c[i]]) % mod;
            }
        }
    }
    std::cout << table[x] << std::endl;
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
