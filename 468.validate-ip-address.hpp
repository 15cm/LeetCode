class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find_first_of(".") != string::npos) {
            int dots = 0;
            for(char c: IP) {
                if(!(c >= '0'  && c <='9' || c == '.')) return "Neither";
                if(c == '.') dots++;
            }
            if(dots != 3) return "Neither";
            stringstream ss(IP);
            string s;
            int cnt = 0;
            while(getline(ss, s, '.')) {
                if(s.empty() || s.length() > 3 || stoi(s) > 255) {
                    return "Neither";
                }
                if(s[0] == '0' && s.length() != 1)
                    return "Neither";
                cnt++;
            }
            if(cnt == 4) return "IPv4";
        } else if(IP.find_first_of(":") != string::npos) {
            int colons = 0;
            for(char c: IP) {
                if(!(c >= '0' && c <= '9' || c >= 'a' && c <='f' || c>='A' && c <= 'F' || c == ':'))
                    return "Neither";
                if(c == ':') colons++;
            }
            if(colons != 7) return "Neither";
            stringstream ss(IP);
            string s;
            int cnt = 0;
            while(getline(ss, s, ':')) {
                if(s.empty() || s.length() > 4)
                    return "Neither";
                cnt++;
            }
            if(cnt == 8) return "IPv6";
        }
        return "Neither";
    }
};
