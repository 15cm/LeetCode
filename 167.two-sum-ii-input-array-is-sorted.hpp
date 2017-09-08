class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0, j = numbers.size() - 1; i < j;) {
            int diff = target - numbers[i] - numbers[j];
            if(diff > 0) i++;
            else if(diff < 0) j--;
            else return vector<int>{i + 1, j + 1};
        }
        return vector<int>();
    }
};
