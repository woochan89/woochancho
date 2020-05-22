#pragma once
#include<iostream>

template<typename T>

class Singleton
{

private:
	static T* m_pThis;

protected:
	Singleton() {};
	virtual~Singleton() {
		DestroyInstance();
	};

public:
	static T *GetInstance()
	{
		if (m_pThis == NULL)
			m_pThis = new T;
		return m_pThis;
	}

	static void DestroyInstance()
	{
		if (m_pThis != NULL)
			delete m_pThis;
	}
};

