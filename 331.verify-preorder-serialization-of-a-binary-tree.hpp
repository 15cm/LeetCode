class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        stringstream ss(preorder);
        string s;
        return verify(ss) && !(ss >> s);
    }
    bool verify(stringstream& ss) {
        string s;
        if(!getline(ss, s, ',')) return false;
        if(s[0] == '#') return true;
        return verify(ss) && verify(ss);
    }
};
