from __future__ import print_function
import sys

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

p = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,  101,  103, 107, 109, 113]

for n in range(1, 31):
	eprint("%d" % n)
	bestA = -1
	bestB = -1
	for j in range(1 << n):
		a = 1
		b = 1
		for k in range(n):
			if j & (1 << k) == 0:
				a *= p[k]
			else:
				b *= p[k]
		if a > b:
			a, b = b, a
		if bestA == -1 or (bestB - bestA) >= b - a :
			bestA, bestB = a, b
	print("if(n == %d) ans = \"%d\";" % (n, bestA))
	
