import BigInt

class TestBigInt:

    def __init__(self):
	self.__testAdd__(0,23)
        self.__testAdd__(2,3)
        self.__testAdd__(2235563455,3)
        self.__testAdd__(223443468,3453487903)
        self.__testAdd__(-2,3)
        self.__testAdd__(2,3123434566789)
        self.__testAdd__(1232,3645)
        self.__testAdd__(23434,67683)
        self.__testAdd__(28,33)
        self.__testAdd__(21234,68903)
        self.__testAdd__(276889787231434,45676898045634567873)

	print( "mul tests:")

	self.__testmul__(0,12)
	self.__testmul__(-1,12)
	self.__testmul__(12323445,12)
	self.__testmul__(1236,76544553434)
	self.__testmul__(2345,172)
	self.__testmul__(0456,167682)
	self.__testmul__(8765,15642)
	self.__testmul__(5,2)
	self.__testmul__(345,512)
	self.__testmul__(2345432,6456712)
	self.__testmul__(34532345345634,76545674568123412)

        return None

    def __testAdd__(self, a, b):
	


        x = BigInt.BigInt(a)

        y = BigInt.BigInt(b)

        z = x.__add__(y)

        intSum = a + b
	print a , '+' , b , '=' , a+b

        if intSum != int(z.__str__()):

            print ("test fail")

        return None
    def __testmul__(self, a, b):
	


        x = BigInt.BigInt(a)

        y = BigInt.BigInt(b)

        z = x.__mul__(y)

        intSum = a * b
	print a , '*' , b , '=' , a*b

        if intSum != int(z.__str__()):

            print ("test fail")

        return None



if __name__ == '__main__':

    a = TestBigInt()
