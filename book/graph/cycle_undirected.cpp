#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define ll long long
#define pii pair<int,int>
#define f first
#define s second

int n,m;
const int MAXN = 1e5+5;
vector<int> edges[MAXN];
vector<int> vis(MAXN,0);
vector<int> par(MAXN,0);
int cycle_start,cycle_end;

bool dfs(int u, int p){
    vis[u] = 1;
    for(auto v: edges[u]){
        if(v == p) continue;
        if(vis[v]){
            cycle_start = v;
            cycle_end = u;
            return true;
        }
        par[v] = u;
        if(dfs(v,u)) return true;
    }
    return false;
}

void find_cycles(){
    cycle_start = -1;
    
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i,0)) break;
    }

    if(cycle_start == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        vector<int> ans;
        ans.push_back(cycle_start);
        for(int i=cycle_end; i != cycle_start; i = par[i]){
            ans.push_back(i);
        }
        ans.push_back(cycle_start);

        reverse(ans.begin(),ans.end());

        cout << ans.size() << "\n";

        for(auto x: ans){
            cout << x << " ";
        }
        cout << "\n";
    }
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    find_cycles();
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}