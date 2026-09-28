class Solution {
public:
    bool isPalindrome(string s) {
       string sen;
        for(char c : s)
        {
            if(isalnum(c))
            {
                sen += tolower(c);
            }
        }
       int l=0,r=sen.size()-1;
       while(l<=r){
             if(sen[l]!=sen[r])
             {
               return false;
             }
              l++;
                r--;
       }
   return true;
    }
};