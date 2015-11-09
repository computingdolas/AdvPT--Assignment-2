#include <iostream>
#include "Matrix.h"
using namespace std;

int main()

{
	
	//bool result;
	 Matrix<double> m1( 2,2,0 );
 	 Matrix<double> m2( 2,2,0 );
 	 Matrix<int> m3( 2,2,0 );
 	 

   	m1(0,0) = 2;
   	m1(0,1) = 2;
   	m1(1,0) = 3;
   	m1(1,1) = 2;
   	cout<< m1<<endl;
   	m2= m1.inverseDiagonal();
   	cout<< m2<<endl;

   

	//cout << a <<endl;	
	
	
	
	return 0;
	
}

	
	
	
	
	
	
	
