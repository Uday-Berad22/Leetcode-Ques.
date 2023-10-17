class Solution {
public:
    int pre(char c)
    {
        if(c=='I')
        return 1;
        else if(c=='V')
        return 5;
        else if(c=='X')
        return 10;
        else if(c=='L')
        return 50;
        else if(c=='C')
        return 100;
        else if(c=='D')
        return 500;
        else 
        return 1000;
    }
    int romanToInt(string s) {
        int ans=0;
        int n=s.size();
        int last=-1;
        for(int i=n-1;i>=0;i--)
        {
            int num=pre(s[i]);
            if(num<last) ans-=num;
            else ans+=num;
            last=num;
        }
        return ans;
    }
};