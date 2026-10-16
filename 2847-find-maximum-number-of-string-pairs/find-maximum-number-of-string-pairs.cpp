class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int pair=0;
           for (int i = 0; i < words.size(); i++) {
        sort(words[i].begin(), words[i].end());
    }

    // Step 2: Sort the array of strings
    sort(words.begin(), words.end());

    for (string s : words) {
        cout << s << " ";
    }
        for(int i=1;i<words.size();i++)
        {
         if(words[i]==words[i-1])
         {
            pair++;
         }
        }
        return pair;
    }
};