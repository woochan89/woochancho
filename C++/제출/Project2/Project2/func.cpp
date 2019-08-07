#include "func.h"

template <typename T>
func<T>::func()
{

}

template <typename T>
void func<T>::Quiz1(T num)
{
	cout<< ++num;
}

template <typename T>
void func<T>::Quiz2(T num1, T num2)
{
	if (num1 <= num2)
		cout<< num1;
	else
		cout << num2;
}

template <typename T>
void func<T>::Quiz3(T num1, T num2, T num3)
{
	if (num1 >= num2 && num1 >= num3)
		cout << num1;
	else if (num2 >= num1 && num2 >= num3)
		cout << num2;
	else
		cout << num3;
}

template <typename T>
func<T>::~func()
{
}
