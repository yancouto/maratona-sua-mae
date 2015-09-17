//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
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

int n, info[100005], jog1[100005], jog2[100005];

int bs(int b, int e, int x, int jog[100005]){
	if(b == e) {
		if(jog[b] > x) return b - 1;
		else if(jog[b] == x) return b;
		else return b+1;
	}
	int mid = (b + e) / 2;
	if(jog[mid] < x)
		return bs(mid+1, e, x, jog);
	return bs(b, mid, x, jog);
}

vector<pii> resp;

bool myfunction(pii a, pii b){
	if(a.fst == b.fst)
		return a.snd < b.snd;
	return a.fst < b.fst;
}

int main(){	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &info[i]);
		info[i]--;
	}
	jog1[0] = !(info[0]); jog2[0] = info[0];
	for(int i = 1; i < n; i++){
		jog1[i] = jog1[i-1] + !(info[i]);
		jog2[i] = jog2[i-1] + info[i];
	}
	for(int t = 1; t <= n; t++){
		bool found = true;
		int b, e, s1, s2, w1, w2, count;
		b = 0; e = min(n-1, 2*t -1); 
		s1 = s2 = t;
		w1 = w2 = 0;
		while(42){
			int i1 = bs(b, e, s1, jog1);
			int i2 = bs(b, e, s2, jog2);
			int u, v;
			u = v = 0;
			if(i1 < b || i1 > e) u = 1;
			if(i2 < b || i2 > e) v = 1;
			if(u && v) {
				found = false;
				break;
			}
			if(i1 < i2) b = i1;
			else if(i2 < i1) b = i2;
			else b = (jog1[i1] == s1)?i1:i2;
			s1 = jog1[b] + t;
			s2 = jog2[b] + t;
			w1 += (b == i1);
			w2 += (b == i2);
			b++;
			if(b == n) break;
			e = min(n-1, b + 2*t - 1);	
		}
		if(found){
			if(info[n-1] && w2 > w1)
				resp.pb(make_pair(w2, t));
			else if(!info[n-1] && w1 > w2)
				resp.pb(make_pair(w1, t));
		}
	}
	sort(resp.begin(), resp.end(), myfunction);
	printf("%lu\n", resp.size());
	for(int i = 0; i < resp.size(); i++)
		printf("%d %d\n", resp[i].fst, resp[i].snd);
	return 0;
}
