#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector< string > v(n);
        for(auto& x : v) cin >> x;

        sort(v.begin(), v.end(), [&] (const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        set<string> S;

        bool ok = true;
        for(int i = 0; i < n; ++i) {
            string cur;
            for(char& c : v[i]) {
                cur += c;
                if(S.find(cur) != S.end()) {
                    ok = false;
                    break;
                }
            }
            S.insert(v[i]);
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;

    
}
