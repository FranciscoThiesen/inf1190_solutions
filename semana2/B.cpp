#include <bits/stdc++.h>

using namespace std;

bool pode_ser_stack(const vector< pair<int, int> >& op)
{
    stack<int> S;
    for(const auto& O : op) {
        if(O.first == 2) {
            if(S.empty()) return false;
            int v = S.top();
            if(v != O.second) return false;
            S.pop();
        }
        else S.push(O.second);
    }
    return true;
}

bool pode_ser_queue(const vector< pair<int, int> >& op)
{
    queue<int> Q;
    for(const auto& O : op) {
        if(O.first == 2) {
            if(Q.empty()) return false;
            int v = Q.front();
            if(v != O.second) return false;
            Q.pop();
        }
        else Q.push(O.second);
    }
    return true;
}

bool pode_ser_PQ(const vector< pair<int, int> >& op) {
    priority_queue<int> PQ;
    for(const auto& O : op) {
        if(O.first == 2) {
            if(PQ.empty()) return false;
            int v = PQ.top();
            if(v != O.second) return false;
            PQ.pop(); 
        }
        else PQ.push(O.second);
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    while(cin >> n) {
        vector< pair<int, int> > ops;
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            ops.emplace_back(x, y);
        }
        int msk = 0;
        if(pode_ser_stack(ops)) msk |= 1;
        if(pode_ser_queue(ops)) msk |= 2;
        if(pode_ser_PQ(ops)) msk |= 4;
        if(msk == 0) cout << "impossible";
        else if(msk == 1) cout << "stack";
        else if(msk == 2) cout << "queue";
        else if(msk == 4) cout << "priority queue";
        else cout << "not sure";
        cout << endl;
    }
    return 0;
}
