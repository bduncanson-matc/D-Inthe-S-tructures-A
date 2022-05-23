/*

*/one and zeros
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
            sort(strs.begin(), strs.end(), [](const string& first, 
                const string& second){
                    return first.size() < second.size();
                });

        vector<vector<int>> dp(m+2,vector<int>(n+3,0));
        for(string &str : strs){
            int zero = 0;
            if(str.length() < 30){ 
                zero = count(str.begin(), str.end(),'0');
            }else{
                sort(str.begin(),str.end());
                while(str[zero]=='0'){
                    ++zero;
                }
            }
                
            int one = str.length()-zero;
            dp[m+1][n+1]+=zero;
            dp[m+1][n+2]+=one;
            if((dp[m+1][n+1] > m+(m/2) && dp[m+1][n+2] > n+(n/2))) break;
            for(int i = m; i >= zero; i--){
               for(int j = n; j>=one;j--){
                 dp[i][j] = max(dp[i][j], 1 + dp[i - zero][j - one]);
               }
            }
        }
    return dp[m][n];
    }
};
