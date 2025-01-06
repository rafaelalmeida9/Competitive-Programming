#include <bits/stdc++.h>
using namespace std;

//segtree com lazy propagation

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
    seg[p] += lazy[p]*(i-j+1);

    if(i != j){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }

    lazy[p] = 0;
}

ll query(int p, int i, int j, int l, int r){
    propagation(p,i,j);

    if(i >= l && j <= r) return seg[p];
    if(i > r || j < l) return 0;

    int m = (i+j)/2;

    ll L = query(2*p,i,m,l,r);
    ll R = query(2*p+1,m+1,j,l,r);

    return (L+R);
}

void update(int p, int i, int j, int l, int r, int x){
    propagation(p,i,j);
    if(i > r || j < l) return;

    if(i >= l && j <= r){
        lazy[p] = x;
        propagation(p,i,j);
    }
    else{
        int m = (i+j)/2;
        
        update(2*p,i,m,l,r,x);
        update(2*p+1,m+1,j,l,r,x);

        seg[p] = seg[2*p] + seg[2*p+1];
    }
}

int main(){


    
    return 0;
}