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

int n, s[MAXN], res[MAXN];

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
	}
	int ans = 0;
	int ultb = s[0];
	int ulti = 0, is = 1;
	res[0] = s[0];
	for(int a=1;a<n;a++){
		res[a] = s[a];
		if(is){
			if(s[a] == s[a-1]){
				ulti = a;
			}
			else{
				is = 0;
				if(s[a] == s[a+1]){
					is = 1;
					ulti = a;
					ultb = s[a];
				}
			}
		}
		else{
			if(s[a] == s[a+1] || a==n-1){
				if(ultb == s[a]){
					ans = max(ans, (a-ulti)/2);
					for(int i = ulti+1;i<a;i++){
						res[i] = ultb;
					}
				}
				else{
					ans = max(ans,(a-ulti)/2);
					for(int i = ulti+1;i<a;i++){
						if(i <= ulti+1 + (a-1 - (ulti+1))/2){
							res[i] = ultb;
						}
						else{
							res[i] = s[a];
						}
					}
				}
				ultb = s[a];
				ulti = a;
				is = 1;
			}
		}
	}
	printf("%d\n", ans);
	for(int a=0;a<n;a++){
		printf("%d ", res[a]);
	}
}