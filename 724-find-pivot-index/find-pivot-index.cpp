class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // prefix array
        int suml=0,sumr=0;
        int l=nums.size()-1;
        vector<int>pref(nums.size());
        pref[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
          pref[i]=pref[i-1]+nums[i];
        }

        for(int i=0;i<nums.size();i++)
        {

          if(i==0){
            suml=0;
          }
          else{
            suml=pref[i-1];
          }

          if(i==nums.size()-1)
          {
            sumr=0;
          }
          else{
            sumr=pref[l]-pref[i];
          }
          if(suml==sumr){
            return i;

          }
          else{
            suml=0;sumr=0;
          }
        }
        return -1;
    }
};