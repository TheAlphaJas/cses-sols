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

int ans(int l, int r, int rl, int rr,int pos, vector<int> &arr) {
    if (l==rl && r == rr) {
        return arr[pos];
    }
    int mid = (r+l)/2;
    if (rr <= mid) {
        return ans(l,mid,rl,rr,2*pos+1,arr);
    } else if (rl >= mid+1) {
        return ans(mid+1,r,rl,rr,2*pos + 2,arr);
    } else {
        return min(ans(l,mid,rl,mid,2*pos + 1,arr), 
        ans(mid+1,r,mid+1,rr,2*pos +2,arr));
    }
}

void update(vector<int> &a, vector<int> &arr, int pos, int l, int r) {
    if (l==r) {
        arr[pos] = a[l];
        return;
    }
    int mid = (l+r)/2;
    update(a,arr,2*pos + 1,l,mid);
    update(a,arr,2*pos + 2,mid+1,r);
    arr[pos] = min(arr[2*pos+1],arr[2*pos+2]);
}

void solve() {
    int n,q; cin>>n>>q;
    vector<int> a(n);
    rep(i,0,n) {cin>>a[i];}
    int l,r;
    vector<int> arr(4*n+1);
    update(a,arr,0,0,n-1);
    rep(i,0,q) {
        cin>>l>>r;
        cout<<ans(0,n-1,l-1,r-1,0,arr)<<endl;
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