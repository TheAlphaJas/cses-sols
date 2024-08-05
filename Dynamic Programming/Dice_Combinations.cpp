#include <bits/stdc++.h>
using namespace std;
//author: von_Braun
#define ll long long
#define lli long long int
#define pb push_back
#define rep(var, start, num) for(ulli var = start; var <start + num; var++)
#define all(x) x.begin(), x.end()
#define ulli unsigned long long int
#define ull unsigned long long
bool sortbysec(const pair<ll,ll> &a,const pair<ll,ll> &b) { return (a.second < b.second); }
long int MOD = 1e9 + 7;
long int ans(int n, vector<int> &dp){
    if (dp[n]!=-1) {return dp[n];}
    if (n==0) {
        return dp[n] = 1;
    }
    long int ret=0;
    for(int i=1;i<=6;i++) {
        if (n-i>=0) {
            ret = (ret%MOD + ans(n-i,dp)%MOD)%MOD;
        }
    }
    return dp[n] = ret%MOD;
}

void solve() {
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<ans(n,dp);  
}
int main() {
    //add quotes incase input output file
    //freopen(input.txt,r,stdin);
    //freopen(output.txt,w,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}