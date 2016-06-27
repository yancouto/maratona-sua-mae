import java.util.ArrayList
val g = ArrayList<String>()

class obj(il : Int, jl : Int, ip : Int, jp : Int, l : Int, p : Int) {
	var il = il
	var jl = jl
	var ip = ip
	var jp = jp
	var l = l
	var p = p
	fun smaller(o : obj) : Boolean {
		if(p != o.p) return p < o.p
		return l < o.l
	}
	fun ok(n : Int, m : Int) : Boolean {
		if(!(il >= 0 && jl >= 0 && ip >= 0 && jp >= 0 && il < n && jl < m && ip < n && jp < m)) return false;
		if(g[il][jl] == 'X') return false;
		if(g[ip][jp] == 'X') return false;
		return true
	}
}

val st = Array<obj>(3123456, { i -> obj(0, 0, 0, 0, 0, 0) })
var sz = 0
fun top() : obj {
	var bk = st[1]
	st[1] = st[sz--]
	var i = 1
	while(2 * i <= sz) {
		if(2 * i + 1 <= sz && !st[2*i].smaller(st[2*i+1]) && !st[i].smaller(st[2*i+1])) {
			var tmp = st[2*i+1]
			st[2*i+1] = st[i]
			st[i] = tmp
			i = 2 * i + 1
		} else if(!st[i].smaller(st[2*i])) {
			var tmp = st[2*i]
			st[2*i] = st[i]
			st[i] = tmp
			i = 2 * i
		} else break
	}
	return bk
}

fun add(o : obj) {
	st[++sz] = o
	var i = sz
	while(i > 1 && !st[i / 2].smaller(st[i])) {
		var tmp = st[i]
		st[i] = st[i / 2]
		st[i / 2] = tmp
		i /= 2
	}
}

val di = intArrayOf(1, -1, 0, 0)
val dj = intArrayOf(0, 0, 1, -1)

val pai = Array<Array<Array<Array<obj>>>>(40, {il -> Array<Array<Array<obj>>>(40, {jl -> Array<Array<obj>>(40, {ip -> Array<obj>(40, {i -> obj(-1, -1, -1, -1, 100000000, 100000000)})})})})

val seen = Array<Array<Array<Array<Boolean>>>>(40, {il -> Array<Array<Array<Boolean>>>(40, {jl -> Array<Array<Boolean>>(40, {ip -> Array<Boolean>(40, {i -> false})})})})



fun go(n : Int, m : Int) : Boolean {
	var il = 0
	var jl = 0
	for(i in 0..n-1)
		for(j in 0..m-1)
			if(g[i][j] == 'Y') {
				il = i
				jl = j
			}
	for(i in 0..n-1)
		for(j in 0..m-1)
			if(g[i][j] == 'B')
				add(obj(il, jl, i, j, 0, 0))
	while(sz > 0) {
		var o = top()
		if(seen[o.il][o.jl][o.ip][o.jp]) continue
		seen[o.il][o.jl][o.ip][o.jp] = true
		if(g[o.ip][o.jp] == 'T') {
			println("YES")
			var s = ArrayList<Char>()
			while(g[o.il][o.jl] != 'Y' || g[o.ip][o.jp] != 'B') {
				var pr = pai[o.il][o.jl][o.ip][o.jp]
				if(o.il != pr.il) {
					if(o.il == pr.il + 1) {
						var c = 's'
						if(o.ip != pr.ip || o.jp != pr.jp) c = c.toUpperCase()
						s.add(c)
					} else {
						var c = 'n'
						if(o.ip != pr.ip || o.jp != pr.jp) c = c.toUpperCase()
						s.add(c)
					}
				} else {
					if(o.jl == pr.jl + 1) {
						var c = 'e'
						if(o.ip != pr.ip || o.jp != pr.jp) c = c.toUpperCase()
						s.add(c)
					} else {
						var c = 'w'
						if(o.ip != pr.ip || o.jp != pr.jp) c = c.toUpperCase()
						s.add(c)
					}
				}
				o = pr
			}
			for(i in 0..(s.size - 1))
				print("${s[s.size - 1 - i]}")
			println("")
			return true
		}
		for(d in 0..3) {
			var od = obj(o.il + di[d], o.jl + dj[d], o.ip, o.jp, o.l + 1, o.p)
			if(od.il == od.ip && od.jl == od.jp) {
				od.ip += di[d]
				od.jp += dj[d]
				od.p++
			}
			if(!od.ok(n, m) || seen[od.il][od.jl][od.ip][od.jp] || pai[od.il][od.jl][od.ip][od.jp].smaller(od)) continue
			pai[od.il][od.jl][od.ip][od.jp] = obj(o.il, o.jl, o.ip, o.jp, od.l, od.p)
			add(od)
		}
	}
	return false
}

fun main(args : Array<String>) {
	//var (a, x, y) = readLine()!!.split(' ').map(String::toInt)
	val (n, m) = readLine()!!.split(' ').map(String::toInt)
	for(i in 1..n)
		g.add(readLine()!!)
	if(!go(n, m)) println("NO")
}
