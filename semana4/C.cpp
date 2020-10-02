#include <bits/stdc++.h>

using namespace std;

struct uf {
    vector<int> parent, sz;
    
    uf(int n) {
        parent.resize(n);
        for(int i = 0; i < n; ++i) parent[i] = i;
        sz.assign(n, 1);
    }

    int find(int x) {
        if(parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] >= sz[y]) {
            parent[y] = x;
            sz[x] += sz[y];
        }
        else {
            parent[x] = y;
            sz[y] += sz[x];
        }
    }

};

constexpr int ms = 100'001;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        uf uniao(1000001);
        int id = 0;
        map<string, int> memo;

        for(int i = 0; i < n; ++i) {
            string a, b;
            cin >> a >> b;
            if(memo.count(a) == 0) {
                memo[a] = ++id;
            }
            if(memo.count(b) == 0) {
                memo[b] = ++id;
            }
            
            uniao.unite(memo[a], memo[b]);
            int X = uniao.find(memo[a]);
            cout << uniao.sz[X] << endl;
        }
    }
    return 0;
}
