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

bool possible(int n, vector<int> &pos, vector<int> &coins) {
    if (n<coins[0]) {return 0;}
    // cout<<"pos called "<<n<<endl;
    if (n<0) {return 0;}
    if (n==0) {return 1;}
    if (pos[n]!=-1) {return pos[n];}
    bool ret=0;
    for(auto x:coins) {
        if (n-x>=0) {ret = ret||possible(n-x,pos,coins);}
    }
    return pos[n] = ret;
}

int ncoins(int t, vector<int> &coins, vector<int> &dp, vector<int> &pos) {
    int ans=INT_MAX;
    if (t==0) {return 0;}
    if (dp[t]!=-1) {return dp[t];}
    for(auto x:coins) {
        if (possible(t-x,pos,coins)) {
            ans = min(ans,1+ncoins(t-x, coins, dp, pos));
            pos[t]=1;
        }
    }
    return dp[t]=ans;
}

void solve() {
    int n, t;
    cin>>n>>t;
    vector<int> coins(n);
    rep(i,0,n) {cin>>coins[i];}
    sort(coins.begin(),coins.end());
    vector<int> dp(t+1,-1);
    vector<int> pos(t+1,-1);
    if (possible(t,pos,coins)==0) {cout<<"-1\n";} else {
        cout<<ncoins(t,coins, dp, pos);
    }
}
int main() {
    //add quotes incase input output file
    //freopen(input.txt,r,stdin);
    //freopen(output.txt,w,stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}