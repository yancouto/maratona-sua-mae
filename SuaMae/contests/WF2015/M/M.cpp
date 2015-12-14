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

int sign(int x) {
	return (x > 0) - (x < 0);
}

int W, H;
struct window {
	int x, y, w, h, i;
	bool intersects(window o) {
		if(x >= o.x + o.w) return false;
		if(x + w <= o.x) return false;
		if(y >= o.y + o.h) return false;
		if(y + h <= o.y) return false;
		return true;
	}
	bool in_bounds() {
		return x >= 0 && y >= 0 && x + w <= W && y + h <= H;
	}
	bool point_in(int xx, int yy) {
		return xx >= x && xx <= x + w && yy >= y && yy <= y + h;
	}
	int walk_ri(window a) {
		if(x < a.x + a.w) return INT_MAX;
		if(y >= a.y + a.h) return INT_MAX;
		if(y + h <= a.y) return INT_MAX;
		return x - (a.x + a.w);
	}
	int walk_le(window a) {
		if(x + w > a.x) return INT_MAX;
		if(y >= a.y + a.h) return INT_MAX;
		if(y + h <= a.y) return INT_MAX;
		return a.x - (x + w);
	}
	int walk_up(window a) {
		if(y + h > a.y) return INT_MAX;
		if(x >= a.x + a.w) return INT_MAX;
		if(x + w <= a.x) return INT_MAX;
		return a.y - (y + h);
	}
	int walk_do(window a) {
		if(y < a.y + a.h) return INT_MAX;
		if(x >= a.x + a.w) return INT_MAX;
		if(x + w <= a.x) return INT_MAX;
		return y - (a.y + a.h);
	}
};

vector<window> v;
int window_at(int x, int y, const char *com, int c) {
	int i;
	for(i = 0; i < v.size() && !v[i].point_in(x, y); i++);
	if(i == v.size()) { printf("Command %d: %s - no window at given position\n", c, com); return -1; }
	return i;
}

void deb() {
	for(window w : v)
		printf("%d %d %d %d\n", w.x, w.y, w.w, w.h);
}

char s[50];
int main() {
	int a, b, x, y, w, h, dx, dy;
	scanf("%d %d", &W, &H);
	while(true) {
		v.clear();
		int c = 0, i;
		while(true) {
			c++;
			int ret = scanf("%d %d", &a, &b);
			if(ret == EOF || ret != 0) break;
			scanf("%s", s);
			//printf("windows before %s:\n", s);
			//deb();
			if(s[0] == 'O') {
				scanf("%d %d %d %d", &x, &y, &w, &h);
				window n = {x, y, w, h, c};
				bool ok = n.in_bounds();
				for(window w : v)
					ok &= !n.intersects(w);
				if(!ok) { printf("Command %d: OPEN - window does not fit\n", c); continue; }
				v.pb(n);
			} else if(s[0] == 'C') {
				scanf("%d %d", &x, &y);
				i = window_at(x, y, s, c);
				if(i == -1) continue;
				swap(v[i], v.back());
				v.pop_back();
			} else if(s[0] == 'R') {
				scanf("%d %d %d %d", &x, &y, &h, &w);
				i = window_at(x, y, s, c);
				if(i == -1) continue;
				window n = v[i];
				window n2 = v[i];
				n2.w = w; n2.h = h;
				swap(v[i], v.back());
				v.pop_back();
				bool ok = n2.in_bounds();
				for(window w : v)
					ok &= !n2.intersects(w);
				if(!ok) { printf("Command %d: RESIZE - window does not fit\n", c); v.pb(n); continue; }
				v.pb(n2);
			} else {
				scanf("%d %d %d %d", &x, &y, &dx, &dy);
				int ini = max(abs(dx), abs(dy));
				int mov = 0;
				vector<window> g;
				i = window_at(x, y, s, c);
				if(i == -1) continue;
				if(ini == 0) continue;
				g.pb(v[i]);				
				v.erase(v.begin() + i);
				while(mov < ini) {
					i = -1; int d;
					if(dx > 0) {
						d = 0;
						for(window w : g)
							d = max(d, w.x + w.w);
						d = W - d;
						for(int j = 0; j < v.size(); j++)
							for(window w2 : g)
								if(v[j].walk_ri(w2) < d) {
									d = v[j].walk_ri(w2);
									i = j;
								}
					} else if(dx < 0) {
						d = INT_MAX;
						for(window w : g)
							d = min(d, w.x);
						for(int j = 0; j < v.size(); j++)
							for(window w2 : g)
								if(v[j].walk_le(w2) < d) {
									d = v[j].walk_le(w2);
									i = j;
								}
					} else if(dy > 0) {
						d = 0;
						for(window w : g)
							d = max(d, w.y + w.h);
						d = H - d;
						for(int j = 0; j < v.size(); j++)
							for(window w2 : g)
								if(v[j].walk_do(w2) < d) {
									d = v[j].walk_do(w2);
									i = j;
								}
					} else {
						d = INT_MAX;
						for(window w : g)
							d = min(d, w.y);
						for(int j = 0; j < v.size(); j++)
							for(window w2 : g)
								if(v[j].walk_up(w2) < d) {
									d = v[j].walk_up(w2);
									i = j;
								}
					}
					d = min(d, ini - mov);
					mov += d;
					for(window &w : g)
						w.x += sign(dx) * d,
						w.y += sign(dy) * d;
					if(i == -1 && mov < ini) { printf("Command %d: MOVE - moved %d instead of %d\n", c, mov, ini); break; }
					if(i == -1) break;
					g.pb(v[i]);
					v.erase(v.begin() + i);
				}
				for(window w : g)
					v.pb(w);
			}
			//printf("windows after %s:\n", s);
			//deb();
		}
		printf("%d window(s):\n", (int) v.size());
		sort(v.begin(), v.end(), [](window a, window b) { return a.i < b.i; });
		for(window w : v)
			printf("%d %d %d %d\n", w.x, w.y, w.w, w.h);
		if(feof(stdin)) return 0;
	}
}
