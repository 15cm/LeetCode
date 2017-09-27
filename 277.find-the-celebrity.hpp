// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> candidates;
        for(int i = 0; i < n; i++)
            candidates.insert(i);
        for(int step = 1; step < n; step++)
            for(int cand: list<int>(candidates.begin(), candidates.end()))
                if(knows(cand, (cand + step) % n))
                    candidates.erase(cand);
        for(int cand: list<int>(candidates.begin(), candidates.end()))
            for(int i = 0; i < n; i++)
                if(cand != i && !knows(i, cand)) {
                    candidates.erase(cand);
                    break;
                }
        return candidates.empty() ? -1 : *(candidates.begin());
    }
};
