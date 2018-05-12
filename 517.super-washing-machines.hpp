class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        if(!n) return 0;
        int sum = 0;
        for(int x: machines) sum += x;
        if(sum % n != 0) return -1;
        int avg = sum / n;

        int ans = -1;
        int cnt = 0;
        for(int load: machines) {
            int toBalance = load - avg;
            cnt += toBalance;
            ans = max(ans, max(abs(cnt), toBalance));
        }
        return ans;
    }
};
