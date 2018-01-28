class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cm = citations[mid];
            if(cm == n - mid) return cm;
            else if(cm < n - mid) left = mid + 1;
            else right = mid - 1;
        }
        return n - (right + 1);
    }
};
