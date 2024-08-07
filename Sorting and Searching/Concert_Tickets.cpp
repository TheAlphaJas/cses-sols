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
    int n,m;
    cin>>n>>m;
    int a[n], b[m];
    rep(i,0,n) {cin>>a[i];}
    rep(i,0,m) {cin>>b[i];}
    multiset<int> S;
    rep(i,0,n) {S.insert(-a[i]);}
    rep(i,0,m) {
        auto it = S.lower_bound(-b[i]);
        if (it == S.end()) {cout<<"-1\n"; continue;}
        cout<<-1*(*it)<<endl;
        S.erase(it);
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