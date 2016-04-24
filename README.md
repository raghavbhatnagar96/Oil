# Oil
DAA Project Documentation

Given an MxN matrix and a number K (K<M and K<N), our code searches for 3 disjoint matrices of order KxK such that their total sum is maximised.

1. Pseudo Code of the Algorithm
	a)tfunc.cpp:
		This file has Tfun function which splits the entire matrix into 3regions from a given point. It does this for 4 rotations of the splitting line, and hence 12 regions are got, wherein a max matrix of order KxK is found in each of them (provided the region does noe enclose or intersect any of the given two matrices) and finally the maximun of all the matrices are found, which gives the third max possible matrix for the given two matrices.
	b)gentest.cpp
		This generates a test case for any range of rows and columns from 1 to 40, and saves it in a "testfile".dat. Subsequent executions of this code will rewrite test cases over the previous ones in the same "testfile".dat

	c)intersect(w,x,y,z,a,b,k):
		//Given the coordinates of an area and a upper left coordinated of the matrix, it checks if the matrix intersects with the area.
		if(arealength<k)or(areabreadth<K)
			return 1;
			else if (isInside(w, x, y, z, a, b))or(isInside(w, x, y, z, a+k-1, b))or(isInside(w, x, y, z, a, b+k-1))or(isInside(w, x, y, z, a+k-1, b+k-1))
			return 1;
		else
			return 0;

	d)isInside(w,x,y,z,a,b):
		//Checks if given point (a,b) is inside the given region.
		if(a>=w)and(a<=y)and(b>=x)and(b<=z)
			return 1;
		else
			return 0;

	e)inputFunction:
		//Takes input and stores in a 2D matrix.
		input>>M;
		input>>N;
		int** inputArray = new int*[M];
		for j=0 to N
			for i=0 to M
				input>>inputArray[i][j];
		return inputArray;

	f)getSumArray:
		//Calculates sum of submatrix and stores in a 2D matrix for further processing.
		for i=0 to M-K+1
			for j=0 to N-K+1
				sum=0;
				for x=i to i+K
					for y=j to j+K
						sum=sum+inputArray[x][y];
				sumArray[i][j]=sum;
		return sumArray;

2. Data Structures Used
	We used array data structure, consisting of both 2-dimensional as well as 3-dimensional ones.
	2D arrays were used to store the input and sum of subarrays while 3D array was used to store max array in any region.

3. Compiling Instructions
	Proper compiling instructions are to be done as stated in the makefile. The max sum of the 3 matrices are then outputted on the screen.

4. Defects in Code
	i)Time taken for execution is more than 2 seconds, for higher order of input matrices.

5. Individual Contributions
	We discussed and came up with a possible yet efficient enough algorithm, together. When it came to coding and implementation:-
	Anshul- wrote the functions in areas.cpp, parallel.cpp helped in debugging as well as documentation
	Raghav- wrote the intersect function, intersection.cpp as well as the input.cpp, helped in debugging as well as documentation
	Pranav- wrote the Tfunction tfunc.cpp as well as gentest.cpp, helped in debugging as well as documentation
