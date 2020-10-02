#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> N(3);
    for(int& x : N) cin >> x;
    
    map<int, int> freq;
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < N[i]; ++j) {
            int v;
            cin >> v;
            freq[v]++;
        }
    }

    vector<int> ans;
    for(const auto& val : freq) {
        if(val.second >= 2) {
            ans.push_back(val.first);
        }
    }
    cout << static_cast<int>(ans.size()) << endl;
    for(const auto& v : ans) cout << v << endl;
    return 0;
}
