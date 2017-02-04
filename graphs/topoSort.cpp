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

const int MAXN = 1e4+5;
vector<int> topo;
bool vis[MAXN];
int in_degree[MAXN];    //in_degree[i] denotes the number of vertices that are still not added to topo and there is an edge from them to i.
int n;
vector<int> adj[MAXN];

void topoSort(){
    for(int i = 1;i <= n; i++){
        for(int j = 0;j < adj[i].size(); j++){
            in_degree[adj[i][j]]++;
        }
    }
    set<int> S;
    for(int i = 1;i <= n; i++){
        if(in_degree[i] == 0){
            S.insert(i);
            vis[i] = true;
        }
    }
    while(!S.empty()){
        int curr = *(S.begin());
        S.erase(S.begin());
        topo.pb(curr);
        for(int j = 0;j < adj[curr].size(); j++){
            if(!vis[adj[curr][j]]){
                in_degree[adj[curr][j]]--;
                if(in_degree[adj[curr][j]] == 0){
                    S.insert(adj[curr][j]);
                    vis[adj[curr][j]] = 1;	//since a vertex could be pushed only by one vertex, because in_degree of a vertex could be made 0 only by a single vertex vis could be set to 1 even on pop.
                }
            }
        }
    }
}


int main(){
    io;
    int m;
    cin >> n >> m;
    for(int i = 1;i <= m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    topoSort();
    if(topo.size() != n)
        cout << "Sandro fails." << endl;
    else
        for(int i = 0;i < topo.size(); i++)
            cout << topo[i] << sp;
    return 0;
}
