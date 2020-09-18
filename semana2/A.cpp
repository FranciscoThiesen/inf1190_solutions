#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m) {
        if(n + m == 0) break;
        set<int> v;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.insert(x);
        }

        int res = 0;
        for(int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if(v.find(x) != v.end()) ++res;
        }
        cout << res << '\n';
    }
    return 0;
}
