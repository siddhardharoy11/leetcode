class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1000000007;
        vector<long long> dp(n+1);
        long long shareable = 0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {   if(i-delay>=1){
            shareable=(shareable+dp[i-delay]) % MOD;}
            if(i-forget>=1)
            {
                shareable=(shareable-dp[i-forget]+ MOD) % MOD;
            }
            dp[i]=shareable;
        }
        long long ans=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            ans=(ans+dp[i])%MOD;
        }
        return (int)ans;
    }
};
