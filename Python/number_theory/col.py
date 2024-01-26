def col(n):
    max = n
    while n != 1:
        if n%2 == 0:
            n = n/2
            if n !=1:
                print n,"->",
        else:
            n = 3*n + 1
            if n > max:
                max = n
            print n,"->",
    
    print "1"
    print max


while True:
	col(int(raw_input("sayi: ")))
