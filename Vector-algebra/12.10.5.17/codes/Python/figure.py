import numpy as np 
import matplotlib.pyplot as plt 
from numpy import linalg as LA 
import math

  
O = np.array(([0, 0])) 
A = np.array(([1, 0])) 
B = np.array(([-1/2, math.sqrt(3)/2]))
C = np.array(([-1, 0])) 

def line_gen(A,B):
   len =2
   dim = A.shape[0]
   x_AB = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = A + lam_1[i]*(B-A)
     x_AB[:,i]= temp1.T
   return x_AB

#Generating all lines
x_OA = line_gen(O,A)
x_OB = line_gen(O,B)
x_OC = line_gen(O,C)
x_CB = line_gen(C,B)


#Plotting all lines
plt.plot(x_OA[0,:],x_OA[1,:],label='$OA$')
plt.plot(x_OB[0,:],x_OB[1,:],label='$OB$')
plt.plot(x_OC[0,:],x_OC[1,:],label='$OC$')
plt.plot(x_CB[0,:],x_CB[1,:],label='$CB$')

#Labeling the coordinates
tri_coords = np.vstack((O,A,B,C)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O''(0,0)', 'A''(1,0)', 'B''($\dfrac{-1}{2}$,$\dfrac{\sqrt{3}}{2}$)', 'C''(-1,0)']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,20), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.title('Sum of two unit vectors',size=15)
#if using termux
plt.savefig('figs/fig')
#plt.show()
