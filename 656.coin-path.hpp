class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> w(n, -1);
        vector<vector<int>> p(n);
        w[0] = A[0];
        p[0].push_back(1);
        for(int i = 1; i < n; i++) {
            if(A[i] < 0) continue;
            int minIndex = max(0, i - B);
            for(int j = minIndex + 1; j < i; j++) {
                if(w[j] < 0) continue;
                if(w[minIndex] < 0 || w[j] < w[minIndex] ||
                   w[j] == w[minIndex] && pathLessThan(p[j], p[minIndex], i + 1))
                    minIndex = j;
            }
            if(w[minIndex] < 0) continue;
            w[i] = w[minIndex] + A[i];
            p[i] = p[minIndex];
            p[i].push_back(i+1);
        }
        return p[n-1];
    }
    bool pathLessThan(vector<int> &p1, vector<int> &p2, int cur) {
        int n = p1.size(), m = p2.size();
        for(int i = 0; i <= n || i <= m; i++) {
            if(i > n) return true;
            else if(i > m) return false;
            else {
                int v1 = (i == n ? cur : p1[i]);
                int v2 = (i == m ? cur : p2[i]);
                if(v1 < v2) return true;
                else if(v1 > v2) return false;
            }
        }
        return true;
    }
};
