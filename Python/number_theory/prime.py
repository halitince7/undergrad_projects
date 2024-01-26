from math import *

def asal(n):
        if n == 1:
                return 0
        if n == 2:
                return 1

	k = 1
	while k < sqrt(n):
		k += 1
		if n%k == 0:
			return 0
	return 1


def kadar(i,n):
	k = 1
	
	while i < n:
		i += 1
		if asal(i) == 1:
		    k += 1
		    print i,
		    
	print 
	print k


	
while True:
    sec = int(raw_input("asal sayi testi 1, aralik arasi asal bulma 2: "))
    if sec == 1:
	    print asal(int(raw_input("asal mi: ")))
    elif sec == 2:
	    kadar(int(raw_input("basla: ")),int(raw_input("bitir: ")))	
    
