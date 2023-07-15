class Solution {
public:
    vector<int> parent;
        vector<int> rank;
    
    int find_parent(int kid) {
        while(parent[kid] != kid) {
            kid = parent[kid];
        }
        return kid;
    }
    
    void make_union(int i, int j) {
        int p = find_parent(i);
        int q = find_parent(j);
        if (p == q)
            return;
        if (rank[p] > rank[q]) {
            rank[p] += rank[q];
            parent[q] = p;
        }
        
        else {
            rank[q] += rank[p];
            parent[p] = q;
        }
        
        
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        parent.resize(n, 0);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1)
                    make_union(i, j);
            }
            for (int i = 0; i < n; i++) {
                cout << parent[i] << " ";
            }
            cout << "\n";
        }
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(find_parent(i));
        }
        
        return s.size();
    }
};