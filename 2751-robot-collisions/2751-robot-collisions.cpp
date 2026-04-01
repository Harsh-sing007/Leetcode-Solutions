class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st;
        vector<int> currHealth(n);

        for(int i = 0; i < n; i++) {
            currHealth[i] = get<1>(robots[i]);
        }

        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];

            if(dir == 'R') {
                st.push(i);
            } else {
                while(!st.empty() && currHealth[i] > 0) {
                    int j = st.top();

                    if(currHealth[j] < currHealth[i]) {
                        st.pop();
                        currHealth[i]--;
                    }
                    else if(currHealth[j] > currHealth[i]) {
                        currHealth[j]--;
                        currHealth[i] = 0;
                        break;
                    }
                    else {
                        st.pop();
                        currHealth[i] = 0;
                        break;
                    }
                }
            }
        }
        vector<pair<int,int>> survivors;

        for(int i = 0; i < n; i++) {
            if(currHealth[i] > 0) {
                survivors.push_back({get<3>(robots[i]), currHealth[i]});
            }
        }

        sort(survivors.begin(), survivors.end());

        vector<int> result;
        for(auto &p : survivors) {
            result.push_back(p.second);
        }

        return result;
    }
};