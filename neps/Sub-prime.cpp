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
    
    int b,n;
    
    while(cin >> b >> n){
        if(b == 0 and n == 0) break;

        vector<int> vet(b);

        for(int i=0;i<b;i++){
            cin >> vet[i];
        }

        int devedor,credor,valor;
        for(int i=0;i<n;i++){
            cin >> devedor >> credor >> valor;
            vet[devedor-1] -=valor;
            vet[credor-1] +=valor;
        }

        bool ans = true;
        for(int i=0;i<b;i++){
            if(vet[i] < 0){
                ans = false;
            }
        }

        if(ans){
            cout << "S\n";
        }
        else{
            cout << "N\n";
        }
    }

}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}