class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> ans;
        int st=0,end=n-1;
        while(st<end){
            if(numbers[st]+numbers[end]==target){
                ans.push_back(st+1);
                ans.push_back(end+1);
                break;
            }
            else if(numbers[st]+numbers[end]<target) st++;
            else end--;
        }
        return ans;
    }
};