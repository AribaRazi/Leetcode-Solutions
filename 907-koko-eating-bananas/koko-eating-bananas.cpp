class Solution {
public:
bool isPossible(vector<int>& piles, int h,int mid)
{  long long hrs=0; 
      for(int i=0;i<piles.size();i++)
        {   
            hrs += ceil((long double)piles[i] / mid);
        }
    
   
   if(hrs<=h)return true;

   return false;

    
    
    
}
    int minEatingSpeed(vector<int>& piles, int h) {
        //range array
        int maxm=INT_MIN,ans;
        for(int i=0;i<piles.size();i++)
        {
            maxm=max(maxm,piles[i]);
        }

        int low=1,high=maxm,mid;
        while(low<=high)
        {
            mid = low + (high - low) / 2;
            if(isPossible(piles,h,mid))
            {
              ans=mid;
              high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
      return ans;


    }
};