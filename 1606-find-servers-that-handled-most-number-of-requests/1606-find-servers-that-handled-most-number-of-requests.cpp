
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        int n = arrival.size();
        set<int> available;
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > busy;
        vector<int> count(k, 0);
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        for (int i = 0; i < n; i++) {

            while (!busy.empty() && busy.top().first <= arrival[i]) {
                
                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            if (available.empty()) {
                continue;
            }
            int preferred = i % k;
            auto it = available.lower_bound(preferred);
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;
            available.erase(it);

            count[server]++;
            busy.push({
                arrival[i] + load[i],
                server
            });
        }

        int maxCount = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxCount) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
