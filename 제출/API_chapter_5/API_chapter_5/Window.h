#pragma once





#include <Windows.h>


#include <string>





class Window {


private:


	// 멤버 변수는 가급적 대입 연산으로 초기화 하는 것이 좋다.


	HWND m_hWnd = nullptr;





public:


	// 창 생성 과정이다. CreateWindow와 매우 유사한 모습니다.


	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName, int nX, int nY, int nWidth, int nHeight, HINSTANCE hInstance, void *pData = nullptr);


	// 창 생성 시 위치를 기본 값으로 사용한다.


	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName, HINSTANCE hInstance, void *pData = nullptr);


	inline virtual ~Window(void) { if (IsWindow(m_hWnd)) DestroyWindow(m_hWnd); }





	inline void Show(bool bShow) { ShowWindow(m_hWnd, bShow ? SW_SHOW : SW_HIDE); }


	inline HWND GetHwnd(void) const { return m_hWnd; }


};