#include "WndClass.h"





MyWndClass::MyWndClass(HINSTANCE hInstance) {


	// WNDCLASS의 값을 채운다.


	this->cbClsExtra = 0;


	this->cbWndExtra = 0;


	this->hbrBackground = CreateSolidBrush(RGB(255, 255, 255));  // 흰색 브러시.


	this->hCursor = LoadCursor(nullptr, IDC_ARROW);


	this->hIcon = LoadIcon(nullptr, IDC_ICON);


	this->hInstance = hInstance;


	this->lpfnWndProc = WndProc;


	this->lpszClassName = TEXT("MyWndClass");


	this->lpszMenuName = nullptr;


	this->style = 0;





	// 이 클래스는 WNDCLASS로부터 상속 받았다.


	RegisterClass(this);


}





LRESULT CALLBACK MyWndClass::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {


	switch (iMsg) {


	case WM_DESTROY:


		PostQuitMessage(0);


		break;


	}





	return DefWindowProc(hWnd, iMsg, wParam, lParam);


}