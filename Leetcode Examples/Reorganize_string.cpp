class Solution {
public:
    string reorganizeString(string s) {  // eg. ffb or fffb
        vector<int> frequency(26, 0);

        // {0, 1, 2, 3, 4, 5, 6, .... 26}
        // { , 1 ,  ,  ,  , 2 ,  , ....   }

        for (char c : s)  //'a' = 97 
        {
            frequency[c - 'a']++;   // f -> (102 - 97)++ ; f-> (102 - 97)++ ; b-> 98-97 = 1 index 1++
        }

        int maxCount = 0, letter_idx = 0;
        for (int i = 0; i <frequency.size(); ++i) 
        {
            if (frequency[i] > maxCount)  // for i = 1, 1 > 0; for i = 5, 2 > 1
            {
                maxCount = frequency[i];  // 1 -> 2
                letter_idx = i;     // letter = 5
            }
        }
        if (maxCount > (s.length() + 1)/ 2)   // 3 + 1 / 2 = 2;
        {
            return "";
        }
        
        string ans = s;   // ffb after = f _ f
        int index = 0;  

        while (frequency[letter_idx] != 0)  // frequency[5] != 0 
        {
            ans[index] = char(letter_idx + 'a');  // ans[0] = char(5 + a) = f; 
            index += 2; // index = 2;
            frequency[letter_idx]--;  // {0, 1, 0, 0, 0, 1}  
        }

        for (int i = 0; i < frequency.size(); i++)
        {
            while (frequency[i] > 0)   // f[1] > 0 = 1
            {
                if (index >= s.length())
                {
                    index = 1;
                }
                ans[index] = char(i + 'a'); // char(1 + 'a') = b
                index += 2;    // index = 3
                frequency[i]--;
            }
        }
        return ans;
}
};


