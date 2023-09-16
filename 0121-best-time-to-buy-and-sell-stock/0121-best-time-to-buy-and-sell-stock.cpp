class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int buy=prices[0];
        int profit=0;
        // for(int i=0;i<prices.size();i++){
        //     profit=max(profit,prices[i]-buy);
        //     buy=min(prices[i],buy);
        // }
        int n=prices.size();
        int sell=0;
        for(int i=n-1;i>=0;i--){
            profit=max(profit,sell-prices[i]);
            sell=max(sell,prices[i]);
        }
        return profit;
    }
};