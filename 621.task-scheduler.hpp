class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for(char t: tasks) cnt[t - 'A']++;
        int* maxIt = max_element(cnt, cnt + 26);
        int h = *maxIt - 1;
        *maxIt = 0;
        int area = h * n;
        for(int i = 0; i < 26; i++) {
            area -= min(cnt[i], h);
        }
        return tasks.size() + max(area, 0);
    }
};
