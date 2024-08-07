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

void solve() {
    int n,x;
    cin>>n>>x;
    int a[n];
    rep(i,0,n) {cin>>a[i];}
    map<int,vector<int>> mp;
    vector<int> ans(2,-1);
    rep(i,0,n) {mp[a[i]].pb(i);}
    rep(i,0,n) {
        if (x-a[i] == a[i]) {
            if (mp[a[i]].size() >= 2) {
                ans[0] = mp[a[i]][0];
                ans[1] = mp[a[i]][1];
                break;
            }
            continue;
        }
        if (mp[x-a[i]].size()!=0) {
            ans[0] = i;
            ans[1] = mp[x-a[i]][0];
            break;
        }
    }
    if (ans[0]==-1) {
        cout<<"IMPOSSIBLE\n";
    } else {
        cout<<min(ans[0],ans[1])+1<<" "<<max(ans[0],ans[1])+1<<endl;
    }    
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