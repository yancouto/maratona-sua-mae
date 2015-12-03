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

const int MAXN = 100010;

int s[MAXN], n;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char c;
		scanf(" %c", &c);
		s[a] = (int) c-'0';
	}
	int i=1, j=n-2;
	while(i < n && s[i] != s[i-1])
		i++;
	while(j >= 0 && s[j] != s[j+1])
		j--;
	if(i <= j){
		for(int a=i;a<=j;a++)
			s[a]=1-s[a];
	}
	else{
		for(int a=i;a<n;a++){
			s[a] = 1-s[a];
		}
	}
	int q = 0;
	int ans=0, res=0;
	for(int a=0;a<n;a++){
		//printf("%d ", s[a]);
		if(s[a]==q){
			ans++;
			q=1-q;
		}
	}
	//printf("\n");
	res = max(ans,res);
	q = 1;
	ans = 0;
	for(int a=0;a<n;a++){
		if(s[a]==q){
			ans++;
			q=1-q;
		}
	}
	res = max(ans,res);
	printf("%d\n", res);
	return 0;
}