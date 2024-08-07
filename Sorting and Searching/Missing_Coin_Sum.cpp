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
    int n;
    cin>>n;
    long long int a[n];
    long long int s=0;
    bool fl=0;
    rep(i,0,n) {cin>>a[i];}
    sort(a,a+n);
    if (a[0]!=1) {
        cout<<1<<endl;
    } else {
        s = a[0];
        for(int i=1;i<n;i++) {
            if (a[i] > s+1) {cout<<s+1<<endl; fl=1; break;} else {
                s+=a[i];
            }
        }
        if (fl==0) {
            cout<<s+1<<endl;
        }
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