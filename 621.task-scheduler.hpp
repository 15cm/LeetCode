#define INF numeric_limits<int>::max();
class Solution {
public:
    // Brute force
    // int leastInterval(vector<char>& tasks, int n) {
    //     const int R = 26;
    //     int cnt[R] = {0};
    //     int itv[R] = {0};
    //     int taskTotal = 0;
    //     int ans = 0;
    //     for(char c: tasks) {
    //         cnt[charToIndex(c)]++;
    //         taskTotal++;
    //     }
    //     for(int i = 0; i < R; i++)
    //         if(!cnt[i]) itv[i] = INF;

    //     while(taskTotal) {
    //         int index = 0;
    //         for(int i = 0; i < R; i++) {
    //             if(itv[i] < itv[index] || (itv[i] == itv[index] && cnt[i] > cnt[index]))
    //                 index = i;
    //         }
    //         if(itv[index] == 0) {
    //             cnt[index]--;
    //             taskTotal--;
    //             itv[index] = n + 1;
    //             if(!cnt[index]) itv[index] = INF;
    //         }
    //         for(int i = 0; i < R; i++)
    //             if(itv[i] > 0) itv[i]--;
    //         ans++;
    //     }
    //     return ans;
    // }

    // int charToIndex(char c){
    //     return c -'A';
    // }

    // Count idle slots
    int leastInterval(vector<char>& tasks, int n) {
        int R = 26;
        int cnt[R] = {0};
        for(char c: tasks) cnt[c - 'A']++;
        sort(cnt, cnt + R);
        int maxVal = cnt[25] - 1, idleSlots = maxVal * n;
        for(int i = 24; i >= 0 && cnt[i] > 0; i--) {
            idleSlots -= min(maxVal, cnt[i]);
        }
        return tasks.size() + max(0, idleSlots);
    }

};
