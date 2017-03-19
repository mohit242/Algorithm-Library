/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
vector<ii> adj[MAXN];   //{dist, adjacent_vertex}
ll dist[MAXN];
bool vis[MAXN];
int n, m, st, finish;

void init(){
    FORE(i,1,n){adj[i].clear();dist[i]=1e6;vis[i]=false;}
}

void dijkstra(){
    dist[st] = 0;
    multiset<ii> S; // acts as min priority queue.
    S.insert({0,st});    // {dist, vertex}.
    while(!S.empty()){
        ii p = *(S.begin());
        S.erase(S.begin());
        int u = p.S;
        if(vis[u])     //according to the algorithm the distance to the visited vertices is minimal.
            continue;
        vis[u] = true;
        for(auto adjacent_pair : adj[u]){
            int adjacent_vertex = adjacent_pair.S;
            int weight = adjacent_pair.F;
            if(dist[u] + weight < dist[adjacent_vertex]){
                dist[adjacent_vertex] = dist[u] + weight;
                S.insert({dist[adjacent_vertex], adjacent_vertex}); //a vertex can be pushed multiple times do not mark vis as true while pushing instead mark it while popping out.
            }
        }
    }
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> st >> finish;
        init();
        FOR(i,m){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].pb({w, b});
            adj[b].pb({w, a});
        }
        dijkstra();
        if(dist[finish] == 1e6)
            cout << "NONE" << endl;
        else
            cout << dist[finish] << endl;
    }
    return 0;
}