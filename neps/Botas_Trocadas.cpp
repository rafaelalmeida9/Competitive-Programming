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
    int vet[61][2];
    memset(vet,0,sizeof(vet));

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int v; char c;
        cin >> v;
        cin >> c;

        if(c == 'E'){
            vet[v][0]++;
        }
        else{
            vet[v][1]++;
        }
    }

    int ans = 0;

    for(int i=30;i<=60;i++){
        ans += min(vet[i][0],vet[i][1]);
    }

    cout << ans << "\n";

}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}