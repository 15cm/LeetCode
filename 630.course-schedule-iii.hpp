typedef vector<int> VI;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](VI& lhs, VI& rhs) { return lhs[1] < rhs[1]; });
        auto cmp = [](VI& lhs, VI& rhs) { return lhs[0] < rhs[0]; };
        priority_queue<VI, vector<VI>, decltype(cmp)> pq(cmp);
        int time = 0;

        for(auto& c: courses) {
            if(time + c[0] <= c[1]) {
                time += c[0];
                pq.push(c);
            } else if(!pq.empty() && pq.top()[0] > c[0]) {
                time += c[0] - pq.top()[0];
                pq.pop();
                pq.push(c);
            }
        }
        return pq.size();
    }
};
