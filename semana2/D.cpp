#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m) {
        unordered_map<int, vector<int> > M;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            M[x].push_back(i + 1);
        }
        for(int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            if(a > static_cast<int>(M[b].size())) cout << 0 << endl;
            else cout << M[b][a - 1] << endl;
        }
    }
    return 0;
}
