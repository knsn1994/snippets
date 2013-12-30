import math
import numpy as NP

alpha = 0.2	#learning rate

def f(z):
	return 1/(1 + math.e ** (-z))


def gradientDescent(x, y, theta, m):
	xTrans = x.transpose()
	for _ in xrange(10**5):
		h = NP.dot(x,theta)
		for i in xrange(len(h)):
			h[i] = f(h[i])
		loss = h - y
		gradient = NP.dot(xTrans,loss)/m
		theta = theta - alpha * gradient
	return theta

print "Enter the number of data points"

m = int(raw_input())
x = NP.zeros((m, 2))			
y = NP.zeros(m)

print "Now enter the feature value followed by the 0 or 1 for classification"

for i in xrange(m):
	x[i][1],y[i]=map(float,raw_input().split())      #input x and y coordinates
	x[i][0] = 1

print "inputs done"

theta = NP.zeros(2)
theta = gradientDescent(x,y,theta,m)


print "start entering the test data"


while True:
	T =float(raw_input())
	print "The confidence value that the object is of type 1 is:", f(NP.dot([1,T],theta))
