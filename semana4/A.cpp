#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, sz;
    vector<long long> sum;

    union_find(int n) {
        parent.resize(n);
        sum.assign(n, 0);
        sz.assign(n, 1);
    }

    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[y] > sz[y]) swap(x, y); 
        parent[y] = x;
        sz[x] += sz[y];
        sum[x] += sum[y];
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    while(cin >> n >> m) {
        auto uf = union_find(n + m + 13);
        int nxt_id = n;
        vector<int> current(n);
        iota(current.begin(), current.end(), 0);
        for(int i = 0; i < n; ++i) uf.parent[i] = i, uf.sum[i] = i + 1;
        
        for(int i = 0; i < m; ++i) {
            int t;
            cin >> t;
            if(t == 1) {
                int x, y;
                cin >> x >> y;
                --x; --y;
                int cur_x = current[x], cur_y = current[y];
                uf.unite(cur_x, cur_y);
            }
            else if(t == 2) {
                int x, y;
                cin >> x >> y;
                --x; --y;
                int cur_x = current[x], cur_y = current[y];
                if(uf.find(cur_x) == uf.find(cur_y)) continue;
                else {
                    int v = uf.find(cur_x);
                    uf.sum[v] -= (x + 1);
                    uf.sz[v]--;
                    current[x] = nxt_id++;
                    uf.parent[current[x]] = current[x];
                    uf.sum[current[x]] = (x + 1);
                    uf.sz[current[x]] = 1;
                    uf.unite(current[x], cur_y);
                }
            }
            else {
                int p;
                cin >> p;
                --p;
                int pai = uf.find(current[p]);
                cout << uf.sz[pai] << " " << uf.sum[pai] << endl;
            }
        }
    }
    return 0;
}
