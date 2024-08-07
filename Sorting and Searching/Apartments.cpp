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
    int n,m,k;
    cin>>n>>m>>k;
    int a[n], b[m];
    rep(i,0,n) {cin>>a[i];}
    rep(i,0,m) {cin>>b[i];}
    sort(a,a+n);
    sort(b,b+m);
    int j=0;
    int cnt=0;
    rep(i,0,n) {
        int z = lower_bound(b+j,b+m,max(a[i] - k,0)) - b;
        if (z == m) {break;}
        // cout<<a[i]<<" "<<b[z]<<endl;
        if (b[z] > a[i] + k) {continue;}
        cnt++;
        j = z+1;
    }
    cout<<cnt<<endl;
}
int main() {
    //add quote incase input output file
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