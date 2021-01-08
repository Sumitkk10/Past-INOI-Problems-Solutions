#include <iostream>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;
#define tc ll test;cin >> test;while(test--)
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f3f
#define MOD 1e9 + 7
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

vector<bool> visited(105, false);
vi child[105];
vi maxdp(105, -INF);
vi mindp(105, INF);
vi wealth(105);

void dfs(ll s) {

    if (visited[s] == true ) return;
    visited[s] = true;

    for (auto u : child[s]) {
        dfs(u);

        mmax(maxdp[s], maxdp[u]);
        mmin(mindp[s], mindp[u]);
    }

    if (child[s].size() == 0) {
        mindp[s] = wealth[s];
        maxdp[s] = wealth[s];
    }
}

int main() {

    ll n;
    cin in n;

    fo(i, 0, n - 1) cin in wealth[i];

    ll boss;

    vi parent(n + 5);

    fo(i, 0, n - 1) {
        cin in parent[i];
        if (parent[i] == -1) {
            boss = i;
            continue;
        }
        parent[i]--;
        child[parent[i]].pb(i);
    }

    dfs(boss);

    ll ans = -INF;

    fo(i, 0, n - 1) mmax(ans, max(wealth[i] - mindp[i] , wealth[i] - maxdp[i]));

    cout out ans;

    return 0;
}
