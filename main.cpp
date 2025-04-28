#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= n; ++i){
            int curNum = s[i - 1] - '0';
            if(curNum != 0) dp[i] = dp[i - 1];
            int twodigits = stoi(s.substr(i - 2, 2));
            if(twodigits >= 10 && twodigits <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    
    string s1 = "12";
    cout << "Input: s = \"" << s1 << "\"" << endl;
    cout << "Output: " << solution.numDecodings(s1) << endl;
    
    string s2 = "226";
    cout << "Input: s = \"" << s2 << "\"" << endl;
    cout << "Output: " << solution.numDecodings(s2) << endl;
    
    string s3 = "06";
    cout << "Input: s = \"" << s3 << "\"" << endl;
    cout << "Output: " << solution.numDecodings(s3) << endl;
    
    return 0;
}
