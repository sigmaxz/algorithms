"""
CS 141 Project 1

Samuel Vilarreal
861021551
Revision history
"""

class BigInt:
    def __init__(self, x=0):
        """
       	constructs a new BigInt objects for integer x
        """
	if x < 0 :
		print("error")
		tself = [-1]
		self.arr = tself
		return None
	temp = x
	place_in_number = 10 #shift for decimal place
	mtemp = temp % place_in_number # getting the first place
	temp = temp - mtemp
	size = 1
	tself = [mtemp] #initializing the first element in my array
	while temp != 0 : #while the value given is not zero
		size += 1 
		place_in_number *= 10 #next decimal place
		mtemp = temp % place_in_number #getting the decimal number
		temp -= mtemp #subtracting the gotten value
		mtemp /= (place_in_number/10)
		tself.append(mtemp) # append to array
	self.arr = tself #finally store the arr
		
        return None


	
    def __str__(self):
        """
        returns the string representation of a BigInt number
        """
	i = 0
	string = ""
	#make an empty string then traverse the array to append onto string
	while i < len(self.arr): 
		num = self.arr[i]
		string = str(num) +string
		i += 1
        return string

    def __cmp__(self, other):
        """
        returns a negative integer if self < other, zero if self ==
        other, a positive integer if self > other
        """
	#compare lengths to make easy comparison
	if len(self.arr) < len(other.arr):
		return -1
	elif len(self.arr) > len(other.arr):
		return 1
	# when they are equail lengths traverse from msb downto lsb checking 
	#which is greater stopping on first difference
	else:
		i = len(self.arr) -1
		while i >= 0:
			if self.arr[i] < other.arr[i]:
				return -1
			if self.arr[i] > other.arr[i]:
				return 1
			i -= 1
		
        return 0

    def __add__(self, other):
        """
        returns the sum of self and other
        """
	if self.arr[0] == -1 or other.arr[0] == -1:
		return -1
	result = ""
	#first determine which arr is longer keeping the lens
	#respectively short/long and then puts a flag to show wether 
	#self or other was the longer 
	if len(self.arr) > len(other.arr):
		flag = 0
		short = len(other.arr)
		long = len(self.arr)
	else:
		short = len(self.arr)
		flag = 1
		long = len(other.arr)
	carry = 0
	#this block adds them in elementary matter while traversing the arr
	for i in range(0, short):
		temp = self.arr[i] + other.arr[i] + carry #carry added as well
		carry = temp/10 #carry update
		if  (temp % 10) == 0:
			result =  '0' + result # appending the zero 
		else:
			result = str( temp % 10 ) + result
	
	#for loop to finish up the longer array
	for i in range(short,long):
		if flag:
			result =  str(other.arr[i] + carry) + result
		else:
			result =  str(self.arr[i] + carry) + result
		carry = 0
        return result

    def __mul__(self, other,flag = 0 , n1="", n2=""):
        """
        returns the product of self and other
        currently implemented as repeated addition
        need to be reimplemented according the the specs
        """
	#flag is used to determine first call vs internal call
	#it allows me to let the normal interface work without helper function
	if self.arr[0] == -1 or other.arr[0] == -1:
		return -1
        if flag == 0:
		q =  self.__mul__(other, 1, self.__str__() , other.__str__())
		return q
	#from here on its taken as interpreted from karatsuba wiki
	elif flag == 1 :
		if (int(n1) < 10) or (int(n2) < 10):
			return (int(n1)) * (int(n2))
		else:
			m = max(len(n1), len(n2))
			strsub = m/2	
			#slicing the strings to get halves
			low1 = n1[-strsub:]
			low2 = n2[-strsub:] 
			high1 = n1[:-strsub]
			high2 = n2[:-strsub]
			#handling possible zero highs 
			if len(n1) <= strsub:
				high1 = '0'
			if len(n2) <= strsub:
				high2 = '0'
			z0 = self.__mul__(other, 1,low1 ,low2)
			z1 = self.__mul__(other, 1, str( int(low1) + int(high1)), str( int(low2) + int(high2) )) 
			z2 = self.__mul__(other, 1, high1 , high2)
			return (z2*(10**(2*strsub))) + ( (z1-z2-z0) * (10**(m/2))) + (z0)
	else :
		return NONE

def fact(n):
    """
    the definition of factorial to compare results
    """
    if n == 0:
        return 1
    else:
        return n*fact(n-1)

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        sys.exit('Usage: %s <number>' % sys.argv[0])
    prod = BigInt(1)
    k = int(sys.argv[1])
    for i in range(k):
        prod = prod * BigInt(i+1)
        print prod, fact(i+1)

"""
x = BigInt.BigInt(2) example of how to instanciate the class
y.___str__() call for str
and so on...

import BigInt
x = BigInt.BigInt(12345678987654321)
x.__str__()
y = BigInt.BigInt(98765432123456789)
x.__add__(y)
x.__mul__(y)

Hints/tips
-change internal representation
-stay in base
-Kasatsuba's(wiki)
"""
