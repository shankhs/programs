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
    int num_coins, target;
    vector<int> coins;
    cin >> num_coins >> target;
    //cout << "num_coins: " << num_coins << endl;
    //cout << "target: " << target << endl;
    for (int i = 0; i < num_coins; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    sort(coins.begin(), coins.end());
    //for (int i = 0; i < sz(coins); i++) {
    //  cout << "coin: " << i << " " << coins[i] << endl;
    //}
    std::vector<int> table(target + 1, MAXINT);
    table[0] = 0;
    for (int i = coins[0]; i <= target; i++) {
        for (int j = 0; j < sz(coins) && (i - coins[j] >= 0); j++) {
            if (table[i - coins[j]] != MAXINT) {
                table[i] = min(table[i], 1 + table[i - coins[j]]);
            }
        }
    }
    if (table[target] == MAXINT) {
        cout << -1 << endl;
    } else {
        cout << table[target] << endl;
    }
    return 1;
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
