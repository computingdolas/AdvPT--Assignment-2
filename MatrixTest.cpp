#include "Matrix.h" // put your solution into Matrix.h

#include <iostream>
#include <cassert>


using std::cout;
using std::endl;


void testCopy()
{
   cout << "Copy Test:                ";

   // Create a 3x4 matrix, where all elements are initialized with 1
   Matrix<int> m1( 3,4,1 );
   
   // Create a 2x2 matrix, where all elements are initialized with 2   
   Matrix<int> m2( 3,4,2 );

   m2 = m1;
   assert( m1 == m2 );

   m2 = m2; // test self assignment

   cout << "OK" << endl;
}

void testArithmeticOperators()
{
   cout << "Arithmetic Operator Test: ";

   // Create a 2x2 matrix, where all elements are initialized with zero
   Matrix<int> m1( 2,2,0 );
   Matrix<int> m2( 2,2,0 );

   m1(0,0) = 1;
   m1(0,1) = 2;
   m1(1,0) = 3;
   m1(1,1) = 1;

   m2(0,0) = 4;
   m2(0,1) = 5;
   m2(1,0) = 2;
   m2(1,1) = 3;

   Matrix<int> sum  ( m1+m2 );
   Matrix<int> prod ( m1*m2 );
   
   

   assert( sum(0,0) == 5 );
   assert( sum(0,1) == 7 );
   assert( sum(1,0) == 5 );
   assert( sum(1,1) == 4 );

   assert( prod(0,0) ==  8 );
   
   assert( prod(0,1) == 11 );
   assert( prod(1,0) == 14 );
   assert( prod(1,1) == 18 );


   m1 += m2;
   assert( m1 == sum );

   m1 -= m1;
   assert( m1 == Matrix<int>(2,2,0) );

   cout << "OK" << endl;
}

void testMemoryLayout()
{
   cout << "Memory Layout Test :      ";

   // create uninitialized 3x4 matrix
   Matrix<int> m( 3,4 );

   // Check if rows are adjacent in memory
   int * ptr1 = &m( 1,2 );
   int * ptr2 = &m( 1,3 );
   assert( (ptr2 - ptr1) == 1 );

   int * ptrEndOfRow0   = &m(0,3);
   int * ptrBeginOfRow1 = &m(1,0);
   assert( (ptrBeginOfRow1-ptrEndOfRow0) == 1 );

   cout << "OK" << endl;
}




template<typename T>
void functionTakingConstMatrix( const Matrix<T> & m )
{
    std::cout << m(0,0) << std::endl;
     //Print to cout in the following format:
     //columns should be separated with one or more spaces or tabs, rows with newlines
    cout << m << std::endl;
}

void testConstCapabilities()
{
   cout << "Const Capability Test:    ";

   Matrix<double> m( 2,2, 1.0 );
   m(0,1) = 5.0;
   cout << "OK" << endl;

   functionTakingConstMatrix( m );
}

int main(int argc, char** argv)
{
   testArithmeticOperators();
   testCopy();
   testMemoryLayout();
   testConstCapabilities();
}
