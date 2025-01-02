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
    int x,y,k; cin >> x >> y >> k;

    int ans = 0;

    if(x >= k && y >= k){
        ans += x/k;
        ans += y/k;
        x%=k;
        y%=k;
    }

    if(x == 0 && y == 0){
        cout << ans;
        return;
    }

    if(x < y){
        x = 0;
        ans ++;
        if(y > 0){
            y -= k;
            ans++;
        }
    }
    else{
        y = 0;
        x -= k;
        ans++;
    }

    if(x <= 0 && y <= 0) return;

    if(x == 0){
        ans += ((y/k)+1)*2;
    }
    else if(y == 0){
        ans += (((y/k)+1)*2)-1;
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}