class Solution {
public:
    struct Node {
        int ele, freq;
        bool operator < (const Node& rhs) const {
            return freq > rhs.freq;
        }
        Node(int ele, int freq): ele(ele), freq(freq) {}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num: nums) {
            mp[num]++;
        }
        priority_queue<Node> pq;
        for(auto& pr: mp) {
            if(pq.size() < k) {
                pq.push(Node(pr.first, pr.second));
            } else {
                if(pr.second > pq.top().freq) {
                    pq.pop();
                    pq.push(Node(pr.first, pr.second));
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().ele);
            pq.pop();
        }
        return ans;
    }
};
