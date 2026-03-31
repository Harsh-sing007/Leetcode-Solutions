class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int len = n + m - 1;

        vector<char> word(len, '?');
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return ""; 
                    }
                }
            }
        }
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') word[i] = 'a';
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool changed = false;
                    for (int j = m - 1; j >= 0; j--) {
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                char old = word[i + j];
                                word[i + j] = c;
                                bool valid = true;
                                for (int k = max(0, i + j - m + 1); k <= min(i + j, n - 1); k++) {
                                    if (str1[k] == 'T') {
                                        for (int x = 0; x < m; x++) {
                                            if (word[k + x] != str2[x]) {
                                                valid = false;
                                                break;
                                            }
                                        }
                                        if (!valid) break;
                                    }
                                }

                                if (valid) {
                                    changed = true;
                                    break;
                                }

                                word[i + j] = old;
                            }
                        }
                        if (changed) break;
                    }

                    if (!changed) return "";
                }
            }
        }

        return string(word.begin(), word.end());
    }
};