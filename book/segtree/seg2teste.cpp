#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
typedef long long int ll;

ll vet[MAXN];
ll seg[4*MAXN];
ll lazy[4*MAXN];

void build(int p, int i, int j){
    if(i == j){
        seg[p] = vet[i];
        lazy[p] = 0;
    }
    else{
        int m = (i+j)/2;

        build(2*p,i,m);
        build(2*p+1,m+1,j);

        seg[p] = seg[2*p] + seg[2*p+1];
    }
}

void propagation(int p, int i, int j){
    seg[p] += lazy[p]*(j-i+1);

    if(i!=j){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }

    lazy[p] = 0;
}

void update(int p, int i, int j, int l, int r, int x){
    propagation(p,i,j);
    if(i > r || j < l) return;

    if(i >= l && j <= r){
        lazy[p] += x;
        propagation(p,i,j);
    }
    else{
        int m = (i+j)/2;

        update(2*p,i,m,l,r,x);
        update(2*p+1,m+1,j,l,r,x);

        seg[p] = seg[2*p] + seg[2*p+1];
    }
}

ll query(int p, int i, int j, int l, int r){
    propagation(p,i,j);
    if(i > r || j < l) return 0;

    if(i >= l && j <= r){
        return seg[p];
    }
    else{
        int m = (i+j)/2;

        ll L = query(2*p,i,m,l,r);
        ll R = query(2*p+1,m+1,j,l,r);

        return (L+R);
    }
}

int main(){

    int n,q; cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> vet[i];
    }

    build(1,1,n);

    while(q--){
        int op; cin >> op;
        if(op == 2){
            int a; cin >> a;
            cout << query(1,1,n,a,a) << "\n";
        }
        else{
            int a,b,x; cin >> a >> b >> x;
            update(1,1,n,a,b,x);
        }
    }

    return 0;
}