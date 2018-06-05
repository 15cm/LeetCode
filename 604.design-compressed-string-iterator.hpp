class StringIterator {
    vector<char> chars;
    vector<int> cnts;
    int p, n;
public:
    StringIterator(string compressedString) {
        for(int i = 0; i < compressedString.size();) {
            chars.push_back(compressedString[i++]);
            int acc = 0;
            while(isdigit(compressedString[i])) {
                acc *= 10;
                acc += compressedString[i] - '0';
                i++;
            }
            cnts.push_back(acc);
        }
        this->p = 0;
        this->n = chars.size();
    }
    
    char next() {
        if(p >= n) return ' ';
        char rc = chars[p];
        if(--cnts[p] == 0) p++;
        return rc;
    }
    
    bool hasNext() {
        return p < n;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
