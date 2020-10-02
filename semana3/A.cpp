#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        auto it = upper_bound(v.begin(), v.end(), m);
        int res = (int) (it - v.begin());
        cout << res << endl;
    }
    return 0;
}
