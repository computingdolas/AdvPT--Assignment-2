
#include <iostream>
#include <fstream>
#include <cassert>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

// this is a copy program and This is for second assignment 

// this is version 2 

// This is a copy program 
template <class T>
class Matrix 
{
	private :
	int row;
	int col;
	T *ptr;
	
	
	public:
	int getrow()
	{
		return row;	
	}
	
	
	Matrix(int nrow ,int ncol ,T ini);//Constructor 
	~Matrix();//Destructor
	Matrix(const Matrix &obj);// Copy constructor 
	Matrix(int nrow ,int ncol);// Assignment Constructor 
	



	Matrix& operator = (const Matrix& obj);//Assignment Operator 
 	void display() const ;// Dislplay Function
 
 	Matrix& operator+=(const Matrix& obj);
 	Matrix& operator-=(const Matrix& obj);
 	const T& operator()(int r, int c) const;
	T& operator()(int r, int c ) ;
	
	
	Matrix operator+(const Matrix& obj) const;
 	Matrix operator-(const Matrix& obj) const;
 	Matrix& operator*=(const Matrix& obj);
 	Matrix operator*(const Matrix& obj);
 	bool operator==(const Matrix& obj);

 	bool operator!=(const Matrix& obj); 
 	Matrix inverseDiagonal() const;


};
template <class T>
const T& Matrix<T>::operator()(int r, int c) const 
{
   	return(*(ptr + r * col + c ));
}

template <class T>
T& Matrix<T>:: operator()(int r, int c ) 
{
	return (*(ptr +r * col + c));	

}

template <class T>
Matrix<T>::Matrix(int nrow, int ncol ,T ini)
{
	cout<<" constructor created "<<endl;
	
	row= nrow ;
	col= ncol ;
	ptr = new T [row*col];
	for (int i =0;i < row*col ;++i)
		*(ptr+ i)= ini ;
}
template <class T>
Matrix<T>::Matrix(int nrow, int ncol)
{
	int i;	
	row= nrow;
	col= ncol ;
	ptr = new T [row * col ];
	for (i =0;i < row*col ;++i)
		*(ptr+ i)= 0 ;

}


template <class T>
Matrix<T>::~Matrix()
{

	cout<<" Destructor called"<<endl;
	delete [] ptr;
			
}
template <class T>
Matrix<T>& Matrix<T>:: operator = (const Matrix& obj)
{
	cout<<"The Assignment copy constructor is created"<<endl;
	if (this != &obj)
	{
		row= obj.row;
		col = obj.col;
		for (int i =0;i < row * col; ++i)
			*(ptr+i)= *(obj.ptr + i);
		
	}

	return *this ;
}

template <class T>
Matrix<T>::Matrix(const Matrix &obj)

{
	cout<<" The copy constructor is created "<<endl;
	row= obj.row ;
	col = obj.col ;
	ptr = new T [row*col];
	for (int j =0;j<row*col ;++j)
		*(ptr+j)= *(obj.ptr +j);
		
}
template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& obj)
{
	cout<<" Assignment addition operator is called"<<endl;
	row=obj.row;
	col=obj.col;
	for (int i= 0;i <row*col;++i)
	{
		*(ptr +i)+= *(obj.ptr +i) ;
	}
	return(* this);
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& obj)
{
	cout<<" Assignment subtraction operator is called "<<endl;
	row=obj.row;
	col=obj.col;
	for(int i=0;i<row*col;++i)
	{
		*(ptr +i)-= *(obj.ptr +i);
	}
	return (*this);
}


template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix& obj) const
{
	cout<<" the Assignment binary addition operator is created"<<endl;
	Matrix temp(*this);
	temp+= obj;
	return temp;

}


template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix& obj) const
{	
	cout<<" the Assignment binary substraction operator is created"<<endl;
	Matrix temp(* this);
	temp-=obj;
	return temp;

}


template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& obj)
{
	 assert(this->col == obj.row);
		
		Matrix temp (* this );		
		cout<<"Assignment Matrix Mult is created"<<endl;
		int j;
		double sum;
		int colu =obj.col;
		cout<<" col"<<colu<<endl;
		Matrix m3(this->row,obj.col,0);
		for (int i=0;i<this->row;++i)
		{
			for ( j=0;j<colu;++j)
			{
			sum =0;	
				for (int k=0;k< obj.row;++k)
				{
					
					sum+= temp(i,k)* obj(k,j);
				}
				cout<<"the total sum is"<<sum<<endl;
			*(m3.ptr +  i*(obj.col) +j) = sum;	
			}
		}
		(*this) = m3;
		return (*this);
	
	
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix& obj)
{
	cout<<" The binary Assignment multiplication operator is initialised "<<endl;
	Matrix temp(*this);
	temp *= obj;
	return temp;
}


template <class T>
bool Matrix<T>::operator==(const Matrix& obj)
{
	bool var =true ;
	row= obj.row;
	col= obj.col;
	
	if(this->row!=obj.row || this->col!=obj.col)
	{
		var =false;
	}	
	else
	{	
		for(int i =0; i <row* col ;++i)
		{
			if(*(ptr +i) != *(obj.ptr +i))
			{
			var=false;
			break;
			}
			
		}
	}	
	return var;
}

template <class T>
bool Matrix<T>:: operator !=(const Matrix& obj)
 {
 	
 	if(*this == obj)
 		return false;
 	else
 		return true;	
 } 


template <class T>
void Matrix<T>::display() const 
{
	Matrix m3 = (* this);	
	cout<<" The contents of the matrix are being displayed "<<endl;
	int i ;
	int j;
		for (i=0;i<row;++i)
		{		
			cout<<endl;		
			for (j=0; j<col;++j)
			//cout<<i<<"  "<<j<<endl;
			cout<<(m3(i,j))<<"\t\t";
			
		}
		
}
template<class T>
Matrix<T> Matrix<T>::inverseDiagonal() const
{
	
	assert(this->row == this->col);
	Matrix m3(this->row,this->col,0);
	int i=0;
	int j=0;
	for (i=0;i<this->row;++i)
	{
		j = i;	
		m3(i,j)= 1/ (*this)(i,j);
			
	}
	return m3;

}

template <class T>
ostream& operator<<(ostream& os,const Matrix<T>& obj ) 
{
	
	
	
	obj.display();
	return os;

	
}

