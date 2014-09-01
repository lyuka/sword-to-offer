import ctypes

# 2D array class ADT
class myArray2D:
	def __init__( self, numRows, numCols ):
		self._theRows = myArray( numRows )

		for i in range( numRows ):
			self._theRows[i] = myArray( numCols )

	def numRows( self ):
		return len( self._theRows )

	def numCols( self ):
		return len( self._theRows[0] )

	def __setitem__( self, ndxTuple, value ):
		assert len(ndxTuple) == 2, "invalid number of array subscripts."
		row = ndxTuple[0]
		col = ndxTuple[1]
		assert row >= 0 and row < self.numRows() and col >= 0 and col < self.numCols(), \
		"array subscripts out of range."
		the1dArray = self._theRows[row]
		the1dArray[col] = value

	def __getitem__( self, ndxTuple ):
		assert len(ndxTuple) == 2, "invalid number of array subscripts."
		row = ndxTuple[0]
		col = ndxTuple[1]
		assert row >= 0 and row < self.numRows() and col >= 0 and col < self.numCols(), \
		"array subscripts out of range."
		the1dArray = self._theRows[row]
		return the1dArray[col]

# 1D array used in 2D array
class myArray:
	def __init__( self, size ):
		assert size > 0, "array size must be >0."
		self._size = size
		PyArrayType = ctypes.py_object * size
		self._elements = PyArrayType()
		self.clear( None )

	def __len__( self ):
		return self._size

	def __setitem__( self, index, value ):
		assert index >= 0 and index < len( self ), \
		"array subscripts out of range."
		self._elements[index] = value

	def __getitem__( self, index ):
		assert index >= 0 and index < len( self ), \
		"array subscripts out of range."
		return self._elements[index]

	def clear( self, value ):
		for i in xrange( len( self) ):
			self._elements[i] = value

def find_ele_sorted_mat( mat, rows, cols, element ):
	found = False
	assert mat is not None, "invalid matrix."
	assert rows > 0 and cols > 0, "rows and cols must be >0."
	row = 0
	col = cols-1
	while row < rows and col >= 0:
		if mat[row, col] == element:
			found = True
			break
		elif mat[row, col] > element:
			col = col - 1
		else:
			row = row + 1
	return found

if __name__ == "__main__":
	mat = myArray2D( 4, 4 )
	for i in xrange(4):
		for j in xrange(4):
			value = input()
			mat[i, j] = value
	for i in xrange(4):
		for j in xrange(4):
			print mat[i, j],
		print ""
	print find_ele_sorted_mat( mat, 4, 4, 7 )
