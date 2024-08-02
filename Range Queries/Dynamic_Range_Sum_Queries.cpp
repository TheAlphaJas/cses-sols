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

void build(lli l, lli r, lli pos, vector<lli> &nums, vector<lli>&arr) {
    if (l == r) {
        arr[pos] = nums[l];
        return;
    }
    lli mid = (l+r)/2;
    build(l,mid,2*pos + 1,nums,arr);
    build(mid+1,r,2*pos+2,nums,arr);
    arr[pos] = arr[2*pos+1]+ arr[2*pos+2];
}

void update(lli l, lli r, lli pos, lli newidx, vector<lli> &nums, vector<lli> &arr) {
    if (l==r && r==newidx) {
        arr[pos] = nums[newidx];
        return;
    }
    lli mid = (l+r)/2;
    if (newidx <= mid) {
        update(l,mid,2*pos+1,newidx,nums,arr);
    }   else {
        update(mid+1,r,2*pos+2,newidx,nums,arr);
    }
    arr[pos] = arr[2*pos+1] + arr[2*pos+2];
}

lli query(lli l, lli r, lli rl, lli rr, lli pos, vector<lli> &arr) {
    if (l==rl && r==rr) {return arr[pos];}
    lli mid = (l+r)/2;
    if (rr<=mid) {
        return query(l,mid,rl,rr,2*pos+1,arr);
    }   else if (rl>=mid+1) {
        return query(mid+1,r,rl,rr,2*pos+2,arr);
    }   else {
        return (query(l,mid,rl,mid,2*pos+1,arr) + query(mid+1,r,mid+1,rr,2*pos+2,arr));
    }
}

void solve() {
    lli n,q;
    cin>>n>>q;
    vector<lli> nums(n);
    vector<lli> arr(4*n);
    rep(i,0,n) {cin>>nums[i];}
    build(0,n-1,0,nums,arr);
    lli t;
    rep(i,0,q) {
        cin>>t;
        if (t==1) {
            lli k,u;
            cin>>k>>u;
            nums[k-1]=u;
            update(0,n-1,0,k-1,nums,arr);
        } else {
            lli a,b;
            cin>>a>>b;
            cout<<query(0,n-1,a-1,b-1,0,arr)<<endl;
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