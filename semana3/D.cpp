#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector< long long > v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 1; i < n; ++i) v[i] += v[i - 1];
    
    for(int i = 0; i < m; ++i) {
        long long x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x);
        int id = (int) (it - v.begin());
        long long prv = 0;
        if(it != v.begin()) {
            auto lst = it;
            lst--;
            prv = *lst;
        }
        cout << id + 1 << " " << x - prv  << endl;
    }
    return 0;
}
