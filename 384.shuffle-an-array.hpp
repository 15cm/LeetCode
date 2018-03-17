class Solution {
    vector<int> nums;
    int n;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        n = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> aux = nums, res(n);
        for(int i = 0, j = n-1; i < n; i++, j--) {
            int k = rand() % (j+1);
            res[i] = aux[k];
            swap(aux[k], aux[j]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
