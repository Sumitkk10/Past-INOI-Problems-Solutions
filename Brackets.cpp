#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
#define print(x) for(auto i : x ) cout out i spacef;
#define mmax(x,i) x = max(x,i)
#define mmin(x,i) x = min(x,i)

int main() {

    ll n,k;
    cin in n in k;

    vi value(n+5);
    vi bracket(n+5);

    fo(i,1,n) cin in value[i];
    fo(i,1,n) cin in bracket[i];

    vector<vi> dp(n+5,vi(n+5));

    // dp[i][j] = maximum sum possible of well bracketed sequence if we consider only from i to j ( both inclusive )

    // base case :

    fo(i,1,n){
        fo(j,1,i-1) dp[i][j] = 1;
    }
    fo(i,1,n) dp[i][i]= 0;
    fo(i,1,n-1){
        if(bracket[i+1]-bracket[i] == k){
            dp[i][i+1] = value[i] + value[i+1];
        }
    }

    // recurrence :

    fo(diff,2,n-1){
        ll i = 1;
        ll j = 1+diff;

        while(j <= n){

            if(bracket[j]-bracket[i] == k){
                dp[i][j] = value[i]+value[j]+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }

            fo(m,i+1,j-1){
                mmax(dp[i][j],dp[i][m-1]+dp[m][j]);
            }

            i++;
            j++;
        }
    }

    // answer :

    cout out dp[1][n];

    return 0;
}
