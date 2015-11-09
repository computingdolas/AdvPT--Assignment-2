
// These changes are made on github 
#include <iostream>
#include "Matrix.h"
#include <vector>
#include <string>
using namespace std;

//void initialmatrix(int r,int c, Matrix& obj);

int main()

{
	int i =0;	
	int j=0;
	int value=0;
	int choice=0;	
	string dtype;
	std::vector<int > v;
	cout<<" Welcome to our matric computation program "<<endl;
	cout<<" Enter the three numbers for the dimension s1xs2xs3"<<endl;
	for (i=0; i<3;++i)
	{
		cout<<"Enter the "<<i+1<<" dimension"<<endl;
		cin>>value;
		v.push_back(value);
		
	}
	
	//cout<<" The value of the first dimension is "<<v[1];

	int firstrow=v[0];
	int firstcol=v[1];
	int secondcol=v[2];
	cout<<" Enter the type of element you want to enter in small letters"<<endl;
	cout<< "now initialising matrix ..........."<<endl;
	cin>>dtype;
	if(dtype == "int")
	{
		Matrix<int> m1(firstrow,firstcol,0);
		Matrix<int> m2(firstcol,secondcol,0);
		Matrix<int> m3(firstrow,secondcol,0);
		cout<<" pLease enter the elements of first matrix "<<endl;
		for (i=0; i<firstrow;++i)
			{
				for (j=0; j<firstcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m1(i,j) = value;
				}
			}
		cout<<" pLease enter the elements of second matrix "<<endl;
			for (i=0; i<firstcol;++i)
			{
				for (j=0; j<secondcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m2(i,j) = value;
				}
			}
		m1.display();
		cout<<endl;
		m2.display();
		cout<<endl;
		cout<<" The multiplication of matrix m1 and m2 is "<<endl;
		m3= m1*m2 ;
		m3.display();
		
		
	}
	else if (dtype == "float")
	{
		Matrix<float> m1(firstrow,firstcol,0);
		Matrix<float> m2(firstcol,secondcol,0);
		Matrix<float> m3(firstrow,secondcol,0);
		cout<<" pLease enter the elements of first matrix "<<endl;
		for (i=0; i<firstrow;++i)
			{
				for (j=0; j<firstcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m1(i,j) = value;
				}
			}
		cout<<" pLease enter the elements of second matrix "<<endl;
		for (i=0; i<firstcol;++i)
			{
				for (j=0; j<secondcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m2(i,j) = value;
				}
			}
		
		m1.display();
		cout<<endl;
		m2.display();
		cout<<endl;
		cout<<" The multiplication of matrix m1 and m2 is "<<endl;
		m3= m1*m2 ;
		m3.display();
	}
	else if (dtype =="double")
	{
		Matrix<double> m1(firstrow,firstcol,0);
		Matrix<double> m2(firstcol,secondcol,0);
		Matrix<double> m3(firstrow,secondcol,0);
		cout<<" pLease enter the elements of first matrix "<<endl;
		for (i=0; i<firstrow;++i)
			{
				for (j=0; j<firstcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m1(i,j) = value;
				}
			}
		cout<<" pLease enter the elements of second matrix "<<endl;
		for (i=0; i<firstcol;++i)
			{
				for (j=0; j<secondcol;++j)
				{
					cout<<" Enter the value of "<<i+1<<"  "<<j+1<<" cordinate"<<endl;
					cin>> value ;
					m2(i,j) = value;
				}
			}
		
		m1.display();
		cout<<endl;
		m2.display();
		cout<<endl;
		cout<<" The multiplication of matrix m1 and m2 is "<<endl;
		m3= m1*m2 ;
		m3.display();
	}
	
	
		
return 0;
	
	
}


