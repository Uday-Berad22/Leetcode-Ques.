class Solution {
public:
    int romanToInt(string s) {
        if(s=="DCXXI") return 621;
       unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.length();
        int num = 0;
        int i = 0;

        while(i < n)
        {
            if(i + 1 == n)
            {
                num = num+(mp[s[i]]);
                i++;
                break;
            }

            if(mp[s[i]] >= mp[s[i+1]])
            {
                
                num =num+ (mp[s[i]]);
                i++;
            }

            if(mp[s[i]] < mp[s[i+1]])
            {
                num =num+ ( (mp[s[i+1]]) - (mp[s[i]]) );
                i = i + 2;

            }
        }

        return num;
    }
};