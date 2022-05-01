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

int SumSubstring(string s)
{
    int sum = 0;
    for (int i = 0; i < sz(s); i++) {
        sum += (s[i] - 'a' + 1);
    }
    return sum;
}

int solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        if (sz(s) == 1) {
            cout << "Bob " << s[0] - 'a' + 1 << endl;
            continue;
        }
        if (sz(s) % 2 == 0) {
            cout << "Alice " << SumSubstring(s) << endl;
            continue;
        }
        int left_sum = SumSubstring(s.substr(0, sz(s) - 1));
        int right_sum = SumSubstring(s.substr(1));
        if (left_sum > right_sum) {
            cout << "Alice " << left_sum - (s[sz(s) - 1] - 'a' + 1) << endl;
        } else {
            cout << "Alice " << right_sum - (s[0] - 'a' + 1) << endl;
        }
    }
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
