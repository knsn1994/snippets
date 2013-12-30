def sieve(n):
	p = []
	l = [0,0] + [1 for _ in xrange(n-2)]
	x = 2
	while x*x < n: 
		if(l[x] == 1):
			p.append(x)
			j = x*x
			while j < n:
				l[j] = 0
				j += x
		x += 1
	while x < n:
		if l[x] == 1:
			p.append(x)
		x+=1
	return p
	
print len(sieve(50))
print sieve(50)