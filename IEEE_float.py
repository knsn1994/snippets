def IEEE_float(f):
	f = float(f)
	sign = 0
	exp = 0
	if f < 0: 
		sign = 1 
		f = -f 
	while f >= 2:
		exp += 1
		f /= 2
	while f < 1 : 
		exp -= 1
		f *= 2
	mantisa = int((f-1)* 2 ** 23)
	mantisa = "{0:b}".format(mantisa)
	return sign,mantisa,exp
	
print IEEE_float(24/17.0)