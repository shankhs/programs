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

int MaxDigit(int n)
{
    int max_digit = 0;
    while (n > 0) {
        max_digit = max(max_digit, n % 10);
        n /= 10;
    }
    return max_digit;
}

ll solve(int n, std::vector<ll>& table)
{
    if (n == 0) {
        return 0;
    }
    if (table[n] != 0) {
        return table[n];
    }
    table[n] = 1 + solve(n - MaxDigit(n), table);
    return table[n];
}

int solve()
{
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    std::vector<ll> table(n + 1, 0);
    for (int i = 1; i < 10; i++) {
        table[i] = 1;
    }
    for (int i = 10; i < n + 1; i++) {
        table[i] = solve(i, table);
    }
    return table[n];
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout << solve() << std::endl;
#ifdef ONPC
    cerr << endl
         << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
