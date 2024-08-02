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

int query(int l, int r,int rl, int rr, int pos, vector<int> &tree) {
    // cout<<"query for - \n";
    // cout<<"current range "<<l<<" "<<r<<endl;
    // cout<<"req range "<<rl<<" "<<rr<<endl;
    int mid = (l+r)/2;
    if (l==rl && r==rr) {
        return tree[pos];
    }
    if (rr <= mid) {
        return query(l,mid,rl,rr,2*pos+1,tree);
    }   else if (rl >= 1+mid) {
        return query(mid+1,r,rl,rr,2*pos+2,tree);
    }   else {
        return min(query(l,mid,rl,mid,2*pos+1,tree), query(mid+1,r,mid+1,rr,2*pos+2,tree));
    }   
} 

void build(int l, int r, int pos, vector<int> &main, vector<int> &tree) {
    if (l==r) {
        tree[pos] = main[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,2*pos+1,main,tree);
    build(mid+1,r,2*pos+2,main,tree);
    tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
}

void update(int l, int r, int newidx, int pos, vector<int> &main, vector<int> &tree) {
    if (l==r && r == newidx) {
        tree[pos] = main[l];
        return; 
    }
    int mid = (l+r)/2;
    if (newidx<=mid) {
        update(l,mid,newidx,2*pos+1,main,tree);
    } 
    else {
        update(mid+1,r,newidx,2*pos+2,main,tree);
    }
    tree[pos] = min(tree[2*pos+1],tree[2*pos+2]);
}

void solve() {
    int n,q;
    int t;
    cin>>n>>q;
    vector<int> main(n);
    vector<int> tree(4*n);
    rep(i,0,n) {cin>>main[i];}
    build(0,n-1,0,main,tree);
    // for(int i=0;i<4*n;i++) {cout<<tree[i]<<" ";} cout<<endl;
    rep(i,0,q) {
        cin>>t;
        if (t==1) {
            int k,u; cin>>k>>u;
            main[k-1]=u;
            update(0,n-1,k-1,0,main,tree);
        }   else {
            int a,b;
            cin>>a>>b;
            cout<<query(0,n-1,a-1,b-1,0,tree)<<endl;
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