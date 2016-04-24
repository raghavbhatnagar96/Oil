# Oil
DAA Project Documentation

Given an MxN matrix and a number K (K<M and K<N), our code searches for 3 disjoint matrices of order KxK such that their total sum is maximised.

1. Pseudo Code of the Algorithm
	a)tfunc.cpp:
		This file has Tfun function which splits the entire matrix into 3regions from a given point. It does this for 4 rotations of the splitting line, and hence 12 regions are got, wherein a max matrix of order KxK is found in each of them (provided the region does noe enclose or intersect any of the given two matrices) and finally the maximun of all the matrices are found, which gives the third max possible matrix for the given two matrices.

	b)gentest.cpp
		This generates a test case for any range of rows and columns from 1 to 40, and saves it in a "testfile".dat. Subsequent executions of this code will rewrite test cases over the previous ones in the same "testfile".dat
	c)intersection.cpp:
		Given the coordinates of an area and a upper left coordinated of the matrix, it checks if the matrix intersects with the area.
		PseudoCode:
	d)input.cpp:
		Takes input and stores in a 2D matrix. Then calculates sum of submatrix and stores in a 2D matrix for further processing.

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
