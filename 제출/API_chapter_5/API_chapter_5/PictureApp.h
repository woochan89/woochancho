#pragma once





#include <Windows.h>


#include "WndClass.h"


#include "Window.h"





class PictureApp {


private:


	MyWndClass *m_pClass = nullptr;


	Window *m_pMainWindow = nullptr;





public:


	PictureApp(HINSTANCE hInstance);


	virtual ~PictureApp() {


		delete m_pClass;


		delete m_pMainWindow;


	}





	void Run(void);


};