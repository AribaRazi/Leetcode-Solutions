class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            if(m.find(need)!=m.end())
            {
            ans.push_back(m[need]);
            ans.push_back(i);
            return ans;
            }

            m[nums[i]]=i;
        }
        return ans;
    }
};