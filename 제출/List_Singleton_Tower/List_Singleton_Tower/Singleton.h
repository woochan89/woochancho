#pragma once
#include<iostream>

template<typename T>
class Singleton
{
	static T* m_tThis;
protected:
	Singleton() {}
	virtual~Singleton() {}
public:
	static T* GetInstance()
	{
		if (m_tThis == NULL)
			m_tThis = new T;
		return m_tThis;
	}

	static void DestroyInstance()
	{
		if (m_tThis != NULL)
			delete m_tThis;
	}

};