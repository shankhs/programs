#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

int solve()
{
    int n;
    cin >> n;
    std::vector<ll> table(n + 1, 0);
    table[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                table[i] = (table[i] + table[i - j]) % mod;
            }
        }
    }
    cout << table[n] << endl;
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
