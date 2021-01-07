#include <iostream>
#include<vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1000000007
#define ff first
#define ss second
#define in >>
#define out <<
#define space << " " <<
#define spacef << " "
#define fo(i,a,b) for(ll i = a; i <= b; i++)
#define nextline out "\n"
#define print(x) for(auto i : x ) cout out i spacef
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    tc{
        ll k,n;
        cin in k in n;

        if(k == 1){
            if(n%3 == 0) cout out "1\n";
            else cout out "0\n";
        }

        if(k == 2){
            vi dp(n+5);

            dp[1] = 0;
            dp[2] = 1;
            dp[3] = 1;

            fo(i,4,n) {
                dp[i] = dp[i-2] + dp[i-3];
                dp[i] %= MOD;
            }

            cout out dp[n]%MOD nextline;
        }

        if(k == 3){

            vi f(n+5);
            vi g(n+5);
            vi h(n+5);

            f[1] = 1;
            f[2] = 1;
            f[3] = 2;

            g[1] = 0;
            g[2] = 0;
            g[3] = 1;

            h[1] = 0;
            h[2] = 1;
            h[3] = 1;

            fo(i,4,n){
                f[i] = f[i-1] + f[i-3] + 2*g[i-3];
                g[i] = h[i-1]+g[i-3];
                h[i] = f[i-2]+h[i-3];

                f[i] %= MOD;
                g[i] %= MOD;
                h[i] %= MOD;
            }

            cout out f[n]%MOD nextline;
        }
    }

    return 0;
}
