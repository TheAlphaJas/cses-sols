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

int ans(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (dp[i][j]!=-1) {return dp[i][j];}
    if (i==0) {
        if (j==0) {
            return dp[i][j] = !(s1[i] == s2[j]);
        }   else {
            bool fl=0;
            for(int k =0;k<=j;k++) {
                if (s1[i]==s2[k]) {fl=1; break;}
            }
            return dp[i][j] = !fl + j;
        }
    }
    if (j == 0) {
        //i!=0
        bool fl=0;
            for(int k =0;k<=i;k++) {
                if (s1[k]==s2[j]) {fl=1; break;}
            }
            return dp[i][j] = !fl + i;

        // return dp[i][j] = !(s1[i] == s2[j]) + ans(i-1,j,s1,s2,dp);
    }
    if (s1[i] == s2[j]) {
        return dp[i][j] = ans(i-1,j-1,s1,s2,dp);
    }
    //if not same, I can remove, add, modify;
    int remove_i = 1+ans(i-1,j,s1,s2,dp); 
    int remove_j = 1 + ans(i,j-1,s1,s2,dp);
    int edit = 1 + ans(i-1,j-1,s1,s2,dp);
    // int add_i = 1 + ans(i-1,j,s1,s2);
    // int add_j = 1 + ans(i,j-1,s1,s2);
    return dp[i][j] = min({remove_i, remove_j, edit});
}
void solve() {
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<ans(n-1,m-1,s1,s2,dp);
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