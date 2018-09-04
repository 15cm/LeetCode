class Solution {
public:
    bool checkValidString(string s) {
        multiset<int> left, star;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            switch(s[i]) {
            case '(':
                left.insert(i);
                break;
            case '*':
                star.insert(i);
                break;
            case ')':
                if(!left.empty()) {
                    left.erase(--left.end());
                } else if(!star.empty()) {
                    star.erase(--star.end());
                } else {
                    return false;
                }
            }
        }
        for(int pos: star) {
            if(left.empty()) break;
            auto it = left.lower_bound(pos);
            if(it != left.begin()) {
                left.erase(--it);
            }
        }
        return left.empty();
    }
};
