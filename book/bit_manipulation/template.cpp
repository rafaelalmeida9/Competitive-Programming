#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
#define ull unsigned long long int
#define ll long long int
#define pii pair<int,int>
#define f first
#define s second

void binary_representation(int n){
    for(int i=31;i>=0;i--){
        cout << ((n>>i)&1);
    }cout << "\n";
}

void check_bits(int n, int i){
    if((n>>i)&1){
        cout << "bit " << i  << " of " << n << " is set\n";
    }
    else{
        cout << "bit " << i  << " of " << n << " is not set\n";
    }
}

int count_set_bits(int n){
    int count = 0;
    for(int i=31;i>=0;i--){
        if((n>>i)&1) count++;
    }
    return count;
}

//A number is power of two when it has only one 1
bool is_power_of_2(int n){
    if( n&(n-1) ) return false;
    else return true;
}


void solve(){
    int number = 10;

    printf("printing binary representation\n");
    binary_representation(number);

    printf("\nchecking bits\n");
    check_bits(number,0);
    check_bits(number,1);
    check_bits(number,2);
    check_bits(number,3);

    printf("\ncounting set bits\n");
    int set_bits = count_set_bits(number);
    cout << "number of set bits: " << set_bits << "\n";

    printf("\nchecking if it's power of two\n");
    if(is_power_of_2(number)) cout << number << " it's power of two\n";
    else cout << number << " it's not power of two\n";

    printf("\ndividing and multiplying by two\n");
    cout << (number>>1) << "\n";
    cout << (number<<1) << "\n";

    printf("\nmore operations\n");
    cout << "union " << number << " with " << 5 << " : " << (number | 5) << "\n";
    cout << "intersection " << number << " with " << 5 << " : " << (number & 5) << "\n";
    cout << "set bit " << 2 << " : " << (number |= 1 << 2)<< "\n";
    cout << "clear bit " << 2 << " : " << (number &= ~(1 << 2)) << "\n";


    
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
