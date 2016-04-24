DAA Project Documentation

Given an MxN matrix and a number K (K<M and K<N), our code searches for 3 disjoint matrices of order KxK such that their total sum is maximised.

1. Pseudo Code of the Algorithm

We first choose two matrices of order K x K. The third matrix has to be the maximum K x K matrix such that it does not intersect with the other two.

Choosing the first two matrices is O(MN)^2. We check the remaining region for the maximum matrix. By storing the maximum K x K matrix in different possible areas in an array of size M x N x 4 (stored in O(MN)^2), this can be obtained in order one.

Order of algorithm - O(MN)^2


	a)tfunc.cpp:
		This file has Tfun function which splits the entire matrix into 3regions from a given point. It does this for 4 rotations of the splitting line, and hence 12 regions are obtained, wherein a max matrix of order KxK is found in each of them (provided the region does not enclose or intersect any of the given two matrices) and finally the maximum of all the matrices are found, which gives the third max possible matrix for the given two matrices.
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

    g)main()
        sumArray[M][N] stores the partial sums of all the K x K matrices
        areas[M][N][4] stores the maximum K x K matrix in a given area
        getMaxSum() returns the maximum sum of three disjoint matrices for the given input

    h)getMaxSum:
        //select first two matrices
        int sum=0
        for i=0 to M
            for j=0 to N
                for x=0 to M
                    for y=0 to N
                        int max=0

                        a = Tfunc(x-1,y-1)  //T function for top left corner
                        b = Tfunc(x-1,y+K)  //T function for bottom left corner
                        c = Tfunc(x+K,y-1)  //T function for top right corner
                        d = Tfunc(x+K,y+K)  //T function for bottom right corner
                        //e = bottom(y+K)
                        //f = right(x+K)
                        max=MAX(a,b,c,d)

                        sum=MAX(sum,sumArray[i][j] + sumArray[x][y] + max)

        return sum

    i)getMaxinArea:
        //stores max K x K matrix in every possible area size from 1 x 1 to M x N in the four corners of the input matrix
        //Note - the middle areas are not necessary as those are never called in Tfun
        for i=1 to M
            for j=0 to N
                fourCorners(area,i,j)

    j)fourCorners:
        //max K x K matrix in area of size i X j from all four corners
        area[i][j][0]=maxMatrix(top left corner)
        area[i][j][1]=maxMatrix(top right corner)
        area[i][j][2]=maxMatrix(bottom right corner)
        area[i][j][3]=maxMatrix(bottom left corner)

    k)matrixMax:
        //returns max K x K matrix in an area defined from (startx,starty) to (endx,endy)
        int max=0
        for i=startx to endx
            for j=starty to end y
                max=MAX(max,sumArray[i][[j])

        return max


2. Data Structures Used
	We used the data structure arrays, consisting of both 2-dimensional as well as 3-dimensional ones.

3. Compiling Instructions
	Proper compiling instructions are to be done as stated in the makefile. The max sum of the 3 matrices are then outputted on the screen.

4. Defects in Code
	i) Algorithm is of O(mn)^2 so can take an input of maximum size approximately 100 X 100.

5. Individual Contributions
	We discussed and came up with a possible yet efficient enough algorithm, together. When it came to coding and implementation:-
	Anshul- wrote the functions in main.cpp, maximum K x K matrix in a given area in areas.cpp, parallel.cpp helped in debugging as well as documentation
	Raghav- wrote the intersection function as well as the input.cpp, helped in debugging as well as documentation
	Pranav- wrote the Tfunction tfunc.cpp as well as gentest.cpp, helped in debugging as well as documentation
