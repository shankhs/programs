#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
#define MAXINT (INT_MAX-1000)
#define MOD 1e9+7

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    std::unordered_map<int, vector<int> > emp_report;
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> boss;
    for (int i = 0; i < n; ++i) {
        int vi;
        cin >> vi;
        boss.push_back(vi);
        if(emp_report.find(vi)==emp_report.end()) {
            emp_report[vi]={};
        }
        emp_report[vi].push_back(i+2);
    }
    solve();
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve() << endl;
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
