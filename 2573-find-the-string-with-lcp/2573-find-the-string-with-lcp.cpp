class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        string s(n, '?');
        char ch = 'a';
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (ch > 'z') return "";
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = ch;
                    }
                }
                ch++;
            }
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (i == n - 1 || j == n - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
        }

        if (dp != lcp) return "";

        return s;
    }
};