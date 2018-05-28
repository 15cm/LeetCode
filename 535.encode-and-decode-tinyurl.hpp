class Solution {
    unordered_map<string, string> url2code, code2url;
    vector<char> alphabet;
public:

    Solution() {
        for(int i = 0; i < 26; i++) {
            alphabet.push_back('a' + i);
            alphabet.push_back('A' + i);
        }
        for(int i = 0; i < 10; i ++)
            alphabet.push_back('0' + i);
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(url2code.count(longUrl)) {
            return url2code[longUrl];
        }
        string code;
        do {
            code = genCode();
        }while(code2url.count(code));
        code2url[code] = longUrl;
        url2code[longUrl] = code;
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return code2url[shortUrl.substr(shortUrl.size() - 6, 6)];
    }

    string genCode() {
        string code;
        for(int i = 0; i < 6; i++) {
            int idx = rand() % alphabet.size();
            code.push_back(alphabet[idx]);
        }
        return code;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
