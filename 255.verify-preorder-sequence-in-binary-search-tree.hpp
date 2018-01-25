class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        for(int i = 0, j = -1; i < preorder.size(); i++) {
            int x = preorder[i];
            if(x < low)
                return false;
            while(j >= 0 && x > preorder[j]) {
                low = preorder[j--];
            }
            preorder[++j] = x;
        }
        return true;
    }
};
