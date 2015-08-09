//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n, k;
ull num[200005];
map<ull, ull> mp, dpl;
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%lld", &num[i]);
	ull count = 0;
	for(int i = n-1; i >= 0; i--){
		map<ull, ull>::iterator it, it2, dit;
		it = mp.find(num[i]);
		it2 = mp.find(num[i]*k);
		dit = dpl.find(num[i]*k);
		if(dit != dpl.end()) 
			count += dit->snd;
		if(it2 != mp.end()){
			dit = dpl.find(num[i]);
			if(dit == dpl.end())
				dpl.insert(make_pair(num[i], it2->snd));
			else{
				ull v = dit->snd;
				dpl.erase(dit);
				dpl.insert(make_pair(num[i], v + it2->snd));
			}
		}
		if(it == mp.end())
			mp.insert(make_pair(num[i], 1));
		else{
			ull v = it->snd;
			mp.erase(it);
			mp.insert(make_pair(num[i], v+1));
		}
	}
	printf("%lld\n", count);
	return 0;
}
