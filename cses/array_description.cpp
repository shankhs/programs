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
const int mod = 1e9+7;

int solve(int n, int m, std::vector<int>& x, int lastCount, int totalCount) {
    for (int i = 0; i < sz(x); i++) {
        if(x[i]==0) {
            if(i==0) {
                if(totalCount==0) {
                    totalCount = 3;
                    lastCount = 3;
                } else {
                    if(x[i-1]!=0 && x[i-1]==1) {
                        totalCount = (totalCount * 2)%mod;
                        lastCount = 2;
                    } else if(x[i-1]!=0 && x[i-1]>1) {
                        totalCount = (totalCount*3)%mod;
                        lastCount = 3;
                    } else if(x[i-1]==0) {
                        totalCount = (totalCount * 
                    }
                }
            }
        }
    }
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    if (!(cin >> m)) {
        return 1;
    }
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        int vi;
        cin >> vi;
        x.push_back(vi);
    }   

    return solve(n,m,x);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve() << endl;
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
