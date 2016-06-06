

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

int s[112345], n;

int main (){
	for_tests(t, tt){
		scanf("%d", &n);
		int cnt = 0, ult = 0;
		int fodeu = 0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			if(cnt == 0){
				cnt = (s[a] != 0);
				ult = s[a];
			}
			else{
				if(s[a] == ult) cnt++;
				else{
					if(cnt >= 3)
						cnt = cnt*(s[a]!=0);
					else{
						if(s[a] != 0)
							cnt = 1;
						else
							fodeu = 1;
					}
					ult = s[a];
				}
			}
		}
		if(cnt < 3 && cnt != 0) fodeu = 1;
		if(fodeu)
			puts("No");
		else
			puts("Yes");
	}
}
