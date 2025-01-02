#include <bits/stdc++.h>
using namespace std;

//segtree para consultas de soma e update.
//para outras operações como min ou max: alterar elemento neutro, cálculo de cada nó, overflow, etc.

const int MAXN = 2e5+5;
int vet[MAXN];
long long int seg[MAXN*4];

void build(int p, int i, int j){
    if(i==j){
        seg[p] = vet[i];
    }
    else{
        int m = (i+j)/2;

        build(2*p,i,m);
        build(2*p+1,m+1,j);

        seg[p] = seg[2*p] + seg[2*p+1];
    }
}

long long int query(int p, int i, int j, int l, int r){
    if(i >= l && j <= r){
        return seg[p];
    }

    if(i > r || j < l) return 0;

    int m = (i+j)/2;

    long long int L = query(2*p,i,m,l,r);
    long long int R = query(2*p+1,m+1,j,l,r);

    return (L+R);
}
void update(int p, int i, int j, int id, int x){
    if(i == j){
        seg[p] = x;
    }
    else{
        int m = (i+j)/2;

        if(id <= m){
            update(2*p,i,m,id,x);
        }
        else{
            update(2*p+1,m+1,j,id,x);
        }

        seg[p] = seg[2*p]+seg[2*p+1];
    }
}

int main(){

    int n,q; cin >> n >> q;

    for(int i=1;i<=n;i++){
        cin >> vet[i];
    }

    build(1,1,n);

    while(q--){
        int op,a,b; cin >> op >> a >> b;
        if(op == 1){
            update(1,1,n,a,b);
        }
        else{
            cout << query(1,1,n,a,b) << "\n";
        }
    }

    return 0;
}