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

set<char> GetUniqChars(string s)
{
    set<char> uniq_chars;
    for (int i = 0; i < sz(s); i++) {
        uniq_chars.insert(s[i]);
    }
    return uniq_chars;
}

int solve()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        set<char> uniq_chars = GetUniqChars(s);
        //std::cout << "uniq_chars size: " << sz(uniq_chars) << std::endl;
        bool flag = false;
        for (int j = 0; j < sz(s) - (int)uniq_chars.size() + 1; j++) {
            set<char> local_uniq_chars = GetUniqChars(s.substr(j, uniq_chars.size()));
            //std::cout << "local_uniq_chars size: " << local_uniq_chars.size() << std::endl;
            if (uniq_chars.size() != local_uniq_chars.size()) {
                std::cout << "NO" << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << "YES" << std::endl;
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
