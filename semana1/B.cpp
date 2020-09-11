#include <bits/stdc++.h>

using namespace std;

bool attack(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.first == b.first) return true;
    if(a.second == b.second) return true;
    if(a.first + a.second == b.first + b.second) return true;
    if(a.first - a.second == b.first - b.second) return true;
    return false;
}

int main() {
    vector< string > vec(8);
    for(int i = 0; i < 8; ++i) cin >> vec[i];
    
    vector< pair<int, int> > pos;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(vec[i][j] == '*') {
                pos.emplace_back(i, j);
            }
        }
    }
    
    int Q = static_cast<int>(pos.size());
    if(Q != 8) {
        cout << "invalid" << endl;
        return 0;
    }

    bool under_attack = false;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(i == j) continue; 
            under_attack |= attack(pos[i], pos[j]);  
        }
    }
    if(under_attack) cout << "invalid" << endl;
    else cout << "valid" << endl;
    return 0;
}
