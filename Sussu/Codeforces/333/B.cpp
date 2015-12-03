#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 500010;

int n, s[MAXN], pos[MAXN];


int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int mini=s[0], maxi=s[0];
	pos[s[0]]=0;
	int i=0, res = 0;
	for(int a=0;a<n;a++){ 	
		pos[s[a]] = a;
		mini = min(mini,s[a]);
		maxi = max(maxi,s[a]);
		while(maxi - mini > 1){
			i++;
			while(pos[mini] < i){
				mini++;
			}
			while(pos[maxi] < i){
				maxi--;
			}
		}
		//printf("%d %d\n", i, a);
		res = max(res, a-i+1);
	}
	printf("%d\n", res);
	return 0;
}