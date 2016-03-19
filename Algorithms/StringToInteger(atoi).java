public class Solution {
    public int myAtoi(String str) {
        int i = 0, n = str.length();
        int ans = 0;
        boolean minus = false;
        if(n == 0) return 0;
        while(str.charAt(i) == ' ') i++;
        if(i >= n) return 0;
        if(str.charAt(i) == '-'){
            minus = true;
            i++;
        }
        else if(str.charAt(i) == '+') i++;
        else if(!Character.isDigit(str.charAt(i))) return 0;
        while(i < n && Character.isDigit(str.charAt(i))){
            int digit = str.charAt(i) - '0';
            if(Integer.MAX_VALUE/10 < ans || Integer.MAX_VALUE/10 == ans && Integer.MAX_VALUE % 10 < digit)
                return minus ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            ans = ans * 10 + digit;
            i++;
        }
        return minus ? -ans : ans;
    }
}
