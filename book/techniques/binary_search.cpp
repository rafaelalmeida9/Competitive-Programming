#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

vector<int> vet;

void solve(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int elem; cin >> elem;
        vet.push_back(elem);
    }

    sort(vet.begin(),vet.end());

    int key; cin >> key;

    int l = 0, r = n-1;
    bool found = false;

    while(r >= l){
        int mid = (r+l)/2;

        if(vet[mid] == key){
            found = true;
            break;
        }
        else if(key > vet[mid]){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }

    if(found){
        cout << "achou\n";
    }
    else{
        cout << "n achou\n";
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}