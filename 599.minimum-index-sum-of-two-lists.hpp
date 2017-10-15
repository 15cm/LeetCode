class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        if(list1.size() < list2.size()) list1.swap(list2);
        for(int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        int minSum = list1.size() + list2.size() - 1;
        for(int i = 0; i < list2.size(); i++) {
            if(mp.count(list2[i])) {
                minSum = min(minSum, i + mp[list2[i]]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < list2.size(); i++) {
            if(mp.count(list2[i])) {
                if(i + mp[list2[i]] == minSum) {
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
