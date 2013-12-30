import numpy as NP
alpha = 0.005	#learning rate
def gradientDescent(x, y, theta, m):
	xTrans = x.transpose()
	for _ in xrange(10**5):
		h = NP.dot(x,theta)
		loss = h - y
		gradient = NP.dot(xTrans,loss)/m
		theta = theta - alpha * gradient
	return theta

m = int(raw_input())
x = NP.zeros((m, 2))			
y = NP.zeros(m)
for i in xrange(m):
	x[i][1],y[i]=map(int,raw_input().split())      #input x and y coordinates
	x[i][0] = 1
print "inputs done"
theta = NP.zeros(2)
theta = gradientDescent(x,y,theta,m)
print theta
