class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 1; i <= n; i++) {
            bool fizz = i % 3 == 0;
            bool buzz = i % 5 == 0;
            if(fizz && buzz)
                ans[i-1] = "FizzBuzz";
            else if(fizz)
                ans[i-1] = "Fizz";
            else if(buzz)
                ans[i-1] = "Buzz";
            else
                ans[i-1] = to_string(i);
        }
        return ans;
    }
};
