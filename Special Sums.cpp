#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define INF 1e18
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
#define mmax(x,i) x = max((x),(i))
#define mmin(x,i) x = min((x),(i))
#define N 105

int main() {

    fast;

    ll n;
    cin in n;

    ll ans = -INF;

    vi a(n+5);
    vi b(n+5);
    vi presum(n+5);

    fo(i,1,n) {
        cin in a[i];
        mmax(ans,a[i]);
    }
    fo(i,1,n) {
        cin in b[i];
        presum[i] = presum[i-1] + b[i];
    }

    // i...j

    vi dp1(n+5);

    dp1[1] = a[1];
    dp1[2] = a[1] + a[2];

    fo(i,3,n){
        dp1[i] = max(dp1[i-1] + a[i] + b[i-1] - a[i-1],a[i-1] + a[i]);
        mmax(ans,dp1[i]);
    }

    if(n <= 3000) {

        fo(i, 1, n) {
            fo(j, 1, n) {
                if(i > j)mmax(ans, a[i] + a[j] + presum[n] - presum[i] + presum[j-1]);
            }
        }
    }

    cout out ans;

    return 0;
}
