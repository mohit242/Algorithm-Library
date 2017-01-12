/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

const int MAXN = 1e4+5;
vector<int> adj[MAXN];
bool vis[MAXN];
int n;
int disc[MAXN];     //discovery currTime of vertices
int low[MAXN];  //low[i] is the minimum of visited currTime of all vertices which are reachable from i.
int currTime;

void initialize(){
    currTime = 0;
    FOR(i,n){adj[i].clear();vis[i]=false;AP[i]=false;disc[i]=0;low[i]=INT_MAX;}
}


bool isBiconnected(int u, int parent){
    vis[u] = true;
    disc[u] = low[u] = currTime+1;  //since till now i have not explored the children of u all i know is the lowest numbered vertex which can be reached from u is u itself.
    int child = 0;
    for(int i = 0;i < adj[u].size(); i++){
        int v = adj[u][i];
        if(v == parent)     continue;
        if(!vis[v]){
            child = child+1;
            currTime++;
            bool result = isBiconnected(v, u);
            if(result == false)
                return false;
            //check if subtree rooted at v has a connection to one of the ancestors of u.
            low[u] = min(low[u], low[v]);
            if(parent == -1 && child > 1){ //if u is root and its child is > 1 then it is an A.P.
                return false;
            }
            if(parent != -1 && low[v] >= disc[u]){	//if u is not a root and the lowest reachable vertex from v has time greater than discovery time of u, then u is an A.P.
                return false;
            }
        }else{
            low[u] = min(low[u], disc[v]);
        }
    }
    return true;
}

int main(){
    io;
    cin >> n;
    int m;
    cin >> m;
    initialize();
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool res = isBiconnected(1, -1);	//start from any random vertex, make its parent -1.
    cout << res << endl;
    return 0;
}