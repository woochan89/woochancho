#pragma once





#include <Windows.h>


#include <string>





class Window {


private:


	// ��� ������ ������ ���� �������� �ʱ�ȭ �ϴ� ���� ����.


	HWND m_hWnd = nullptr;





public:


	// â ���� �����̴�. CreateWindow�� �ſ� ������ ����ϴ�.


	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName, int nX, int nY, int nWidth, int nHeight, HINSTANCE hInstance, void *pData = nullptr);


	// â ���� �� ��ġ�� �⺻ ������ ����Ѵ�.


	Window(const std::basic_string<TCHAR> &ClassName, const std::basic_string<TCHAR> &WindowName, HINSTANCE hInstance, void *pData = nullptr);


	inline virtual ~Window(void) { if (IsWindow(m_hWnd)) DestroyWindow(m_hWnd); }





	inline void Show(bool bShow) { ShowWindow(m_hWnd, bShow ? SW_SHOW : SW_HIDE); }


	inline HWND GetHwnd(void) const { return m_hWnd; }


};