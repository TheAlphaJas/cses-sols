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
    int n,q;
    cin>>n>>q;
    vector<long long int> a(n+1);
    a[0]=0;
    int s,e;
    rep(i,1,n) {cin>>a[i];} 
    rep(i,1,n) {a[i]+=a[i-1];}
    rep(i,0,q) {
        cin>>s>>e;
        cout<<a[e]-a[s-1]<<endl;
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