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

int solve()
{
    int t;
    cin >> t;
    //unordered_set<int> distinct_ints;
    //set<int> distinct_ints;
    std::vector<int> distinct_ints;
    while (t--) {
        int n;
        cin >> n;
        distinct_ints.emplace_back(n);
    }
    sort(distinct_ints.begin(), distinct_ints.end());
    int uniqs = 1;
    int last_seen = distinct_ints[0];
    for (int i = 1; i < sz(distinct_ints); i++) {
        if (distinct_ints[i] != last_seen) {
            ++uniqs;
            last_seen = distinct_ints[i];
        }
    }
    cout << uniqs;
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
