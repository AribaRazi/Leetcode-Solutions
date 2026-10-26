class Solution {
public:

bool isPossible(int weight,int days,vector<int>& weights)
{
    int count=1,sum=0;
    for(int i=0;i<weights.size();i++)
    {
    if(sum+weights[i]<=weight)
    {
        sum=sum+weights[i];
    }
    else
    {
        sum=weights[i];
        count++;
    }
    }
     return count<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,ans;
        int maxm=INT_MIN;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]>maxm)
            {
                maxm=weights[i];
            }
            sum=sum+weights[i];
        }


        int low=maxm,high=sum,mid;

        while(low<=high)
        {
         mid=low+(high-low)/2;
         if(isPossible(mid,days,weights))
         {  ans=mid;
            high=mid-1;
         }
         else{
            low=mid+1;
         }
        }
        return ans;
    }
};