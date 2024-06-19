#pragma once
#include <iostream>
using namespace std;

template<typename T>
class matrix
{
	int i_size;
	int j_size;
	T** matr;
public:
	matrix();
	matrix(int i, int j);
	matrix(const matrix& obj);
	matrix(matrix&& obj);
	int Get_i_size()
	{
		return i_size;
	}
	int Get_j_size()
	{
		return j_size;
	}
	T Get_element(int i, int j)
	{
		return matr[i][j];
	}
	T* Get_mass(int i)
	{
		return matr[i];
	}
	T** Get_matr()
	{
		return matr;
	}
	void Set_size(int i, int j);
	void input();
	void show();
	T max();
	T min();
	matrix<T> operator +(int a);
	matrix<T>& operator +=(int a);
	matrix<T> operator -(int a);
	matrix<T>& operator -=(int a);
	matrix<T> operator *(int a);
	matrix<T>& operator *=(int a);
	matrix<T> operator /(int a);
	matrix<T>& operator /=(int a);
	//matrix<T>& operator =(matrix<T> obj);
	matrix<T>& operator =(matrix<T> && obj);
	~matrix();
};

template<typename T>
matrix<T>::matrix()
{
	i_size = 5;
	j_size = 5;
	srand(time(0));
	matr = new T * [i_size];
	for (int i = 0; i < i_size; i++)
	{
		matr[i] = new T [j_size];
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] = rand() % 90 + 33;
			if (sizeof(T) == sizeof(double))
			{
				matr[i][j] += (rand() % 10) / 10.0;
			}
		}
	}
}

template<typename T>
matrix<T>::matrix(int i, int j)
{
	i_size = i;
	j_size = j;
	srand(time(0));
	matr = new T * [i_size];
	for (int i = 0; i < i_size; i++)
	{
		matr[i] = new T[j_size];
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] = rand() % 90 + 33;
			if (sizeof(T) == sizeof(double))
			{
				matr[i][j] += (rand() % 10) / 10.0;
			}
		}
	}
}

template<typename T>
matrix<T>::matrix(const matrix& obj)
{
	i_size = obj.i_size;
	j_size = obj.j_size;
	if (matr != nullptr)
	{
		for (int i = 0; i < i_size; i++)
		{
			if (matr[i] != nullptr)
			{
				delete[] matr[i];
			}
		}
		delete[] matr;
	}
	matr = new T * [i_size];
	for (int i = 0; i < i_size; i++)
	{
		matr[i] = new T[j_size];
	}
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] = obj.matr[i][j];
		}
	}
}

template<typename T>
matrix<T>::matrix(matrix&& obj)
{
	i_size = obj.i_size;
	j_size = obj.j_size;
	matr = obj.matr;
	obj.matr = nullptr;
}

template<typename T>
void matrix<T>::Set_size(int i, int j)
{
	i_size = i;
	j_size = j;
	matr = new T * [i_size];
	for (int i = 0; i < j_size; i++)
	{
		matr[i] = new T[j_size];
	}
}

template<typename T>
void matrix<T>::input()
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			cin >> matr[i][j];
		}
	}
}

template<typename T>
void matrix<T>::show()
{
	if (matr == nullptr)
	{
		cout << "Matrix isn't filled." << endl;
		return;
	}
	cout << "Matrix:" << endl;
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
}

template<typename T>
T matrix<T>::max()
{
	T max = matr[0][0];
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			if (matr[i][j] > max)
			{
				max = matr[i][j];
			}
		}
	}
	return max;
}

template<typename T>
T matrix<T>::min()
{
	T min = matr[0][0];
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			if (matr[i][j] < min)
			{
				min = matr[i][j];
			}
		}
	}
	return min;
}

template<typename T>
matrix<T> matrix<T>::operator+(int a)
{
	matrix<T> _matr(i_size,j_size);
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			_matr.matr[i][j] = matr[i][j] + a;
		}
	}
	return _matr;
}

template<typename T>
matrix<T>& matrix<T>::operator+=(int a)
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] += a;
		}
	}
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator-(int a)
{
	matrix<T> _matr(i_size, j_size);
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			_matr.matr[i][j] = matr[i][j] - a;
		}
	}
	return _matr;
}

template<typename T>
matrix<T>& matrix<T>::operator-=(int a)
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] -= a;
		}
	}
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator*(int a)
{
	matrix<T> _matr(i_size, j_size);
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			_matr.matr[i][j] = matr[i][j] * a;
		}
	}
	return _matr;
}

template<typename T>
matrix<T>& matrix<T>::operator*=(int a)
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] *= a;
		}
	}
	return *this;
}

template<typename T>
matrix<T> matrix<T>::operator/(int a)
{
	matrix<T> _matr(i_size, j_size);
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			_matr.matr[i][j] = matr[i][j] / a;
		}
	}
	return _matr;
}

template<typename T>
matrix<T>& matrix<T>::operator/=(int a)
{
	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < j_size; j++)
		{
			matr[i][j] /= a;
		}
	}
	return *this;
}

//template<typename T>
//matrix<T>& matrix<T>::operator=(matrix<T> obj)
//{
//	if (this == &obj) return *this;
//	if (matr != nullptr)
//	{
//		for (int i = 0; i < i_size; i++)
//		{
//			if (matr[i] != nullptr)
//			{
//				delete[] matr[i];
//			}
//		}
//		delete[] matr;
//	}
//	i_size = obj.i_size;
//	j_size = obj.j_size;
//	matr = new T * [i_size];
//	for (int i = 0; i < i_size; i++)
//	{
//		matr[i] = new T[j_size];
//	}
//	for (int i = 0; i < i_size; i++)
//	{
//		for (int j = 0; j < j_size; j++)
//		{
//			matr[i][j] = obj.matr[i][j];
//		}
//	}
//	return *this;
//}

template<typename T>
matrix<T>& matrix<T>::operator=(matrix<T>&& obj)
{
	i_size = obj.i_size;
	j_size = obj.j_size;
	if (matr != nullptr)
	{
		for (int i = 0; i < i_size; i++)
		{
			if (matr[i] != nullptr) delete[] matr[i];
		}
		delete[] matr;
	}
	matr = obj.matr;
	obj.matr = nullptr;
	return *this;
}

template<typename T>
matrix<T>::~matrix()
{
	if (matr != nullptr)
	{
		for (int i = 0; i < i_size; i++)
		{
			if (matr[i] != nullptr) delete[] matr[i];
		}
		delete[] matr;
	}
}