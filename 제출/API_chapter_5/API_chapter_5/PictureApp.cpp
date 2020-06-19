#include "PictureApp.h"





PictureApp::PictureApp(HINSTANCE hInstance) {


	m_pClass = new MyWndClass(hInstance);


	m_pMainWindow = new Window(m_pClass->GetName(), TEXT("PictureApp"), hInstance);


}





void PictureApp::Run(void) {


	MSG msg = { };





	m_pMainWindow->Show(true);





	while (GetMessage(&msg, nullptr, 0, 0)) {


		TranslateMessage(&msg);


		DispatchMessage(&msg);


	}


}