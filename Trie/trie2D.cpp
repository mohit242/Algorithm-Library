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
#define read(arr, n)	for(int i = 0;i < n; i++)cin>>arr[i];

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

const int MAXN = 500005;
int sz = 0;

int trie[26][MAXN];	//MAXN represents the maximum number of nodes.
int end1[MAXN];		//to indicate the end of word

void insert(string s){
    int v = 0;  //root is represented by 0;
    for(int i = 0;i < s.size(); i++){
        int current = s[i]-'a';
        if(trie[current][v] == -1){	//initially trie is filled with -1
            trie[current][v] = ++sz;
        }
        v = trie[current][v];
    }
    ++end1[v];
}

bool searchPrefix(string prefix){
    int v = 0;
    int i;
    for( i = 0;i < prefix.size(); i++){
        int current = prefix[i]-'a';
        if(trie[current][v] == -1)
            return false;
        v = trie[current][v];
    }
    return i == prefix.size();
}


bool searchWord(string prefix){
    int v = 0;
    int i;
    for( i = 0;i < prefix.size(); i++){
        int current = prefix[i]-'a';
        if(trie[current][v] == -1)
            return false;
        v = trie[current][v];
    }
    return end1[v] > 0;
}


bool comp(string a, string b){
	return a.size() > b.size();
}


int main(){
	FILL(trie, -1);
	insert("karan");
	cout << searchWord("kara") << endl;
	cout << searchPrefix("kara") << endl;
	return 0;
}
