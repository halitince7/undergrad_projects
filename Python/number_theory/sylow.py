from math import *

def asal(n):
	k = 1
	while k < sqrt(n):
		k += 1
		if n%k == 0:
			return 0
	return 1


def PP(n,p):
    if asal(p) == 0:
         print "asal degil"
         return 0

    a = 0
    while n%p == 0:
        a += 1
        n = n/p

    return n , p**a

print PP(60,3)

int(raw_input("sayi: "))
