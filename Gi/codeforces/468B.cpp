//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
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

int info[100005];
int resp[100005], mask[100005];
map<int, int> mp;

int main(){
	int n;
	int a, b;
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for(int i = 0; i < n; i++){
		scanf("%d", &info[i]);
		mp[info[i]] = i;
	}
	for(int i = 0; i < n; i++){
		if(mp.empty()) continue;
		if(mask[mp[info[i]]]) continue;
	
		//printf("(%d,%d,%d) = %lu, %lu\n", info[i], a-info[i], b-info[i], mp.count(a-info[i]), mp.count(b-info[i]));
		if(mp.count(a-info[i]) && !mask[mp[a-info[i]]]){
			//printf("%d e %d\n", info[i], a-info[i]);
			resp[i] = resp[mp[a-info[i]]] = 0;
			mask[mp[a-info[i]]] = mask[i] = 1;
		}
		else {
			if(mp.count(b-info[i]) && !mask[mp[b-info[i]]]){
			//	printf("%d e %d\n", info[i], b-info[i]);
				resp[i] = resp[mp[b-info[i]]] = 1;
				mask[mp[b-info[i]]] = mask[i] = 1;
			}
			else{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i = 0; i < n; i++)
		printf("%d ", resp[i]);
	printf("\n");	
	return 0;
}
