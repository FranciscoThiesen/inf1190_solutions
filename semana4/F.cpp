#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector< int > killed_by(n + 1, 0); 
    set<int> group_leader;
    for(int i = 1; i <= n; ++i) group_leader.insert(i);
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        vector< int > rmv; 
        auto it = group_leader.lower_bound(a);
        while(*it <= b && it != group_leader.end()) {
            if(*it != c) {
                killed_by[*it] = c;
                rmv.push_back(*it);
            }
            ++it;
        }
        for(const auto& v : rmv) group_leader.erase(v);
    }

    for(int i = 1; i <= n; ++i) {
        cout << killed_by[i] << " ";
    }
    cout << endl;
    
}
