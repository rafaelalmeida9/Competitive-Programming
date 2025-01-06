#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define ull unsigned long long int
#define ll long long int
#define pii pair<int,int>
#define f first
#define s second

void solve(){
    vector<int> vet(10);

    for(int i=0;i<10;i++){
        cin >> vet[i];
    }

    for(int i=9;i>=0;i--){
        cout << vet[i] << "\n";
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}