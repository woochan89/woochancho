#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//글로벌 인스턴스핸들값
LPCTSTR lpszClass = TEXT("HelloWorld"); //클래스 명 : 창이름
TCHAR str[256];




int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass는 기본 윈도우환경을 만드는 구조체다. 맴버변수는 밑에와 같다.
	WndClass.cbClsExtra = 0; //예약영역
	WndClass.cbWndExtra = 0; //예약영역 (신경x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //배경색
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //커서
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 모양
	WndClass.hInstance = hInstance; //(프로그램 핸들값(번호)등록)
	WndClass.lpfnWndProc = WndProc; //프로세스 함수 호출
	WndClass.lpszClassName = lpszClass; //클레스 이름
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //윈도우의 수직과 수평이 변경 시 다시 그린다.
	RegisterClass(&WndClass); //만들어진 WidClass를 등록

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);


	while (GetMessage(&Message, NULL, 0, 0)) //사용자에게 메시지를 받아오는 함수(WM_QUIT 메시지 받을 시 종료), 메시지가 오기까지 대기를 하고있다가 오면 작동.
	{
		TranslateMessage(&Message); // 키보드 입력 메시지 처리함수
		DispatchMessage(&Message); //받은 메시지를 WndProc에 전달하는 함수
	}
	return (int)Message.wParam;
}


//문제 1번

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static int x = 100;
	static int y = 100;


	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:			x += 2;			break;		case VK_LEFT:			x -= 2;			break;		case VK_UP:			y -= 2;			break;		case VK_DOWN:			y += 2;			break;		case VK_ESCAPE:			return 0;		}		InvalidateRect(hWnd, NULL, TRUE);
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}


//2번

//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	int len;
//	static int x;
//	static int y;
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Ellipse(hdc, x - 10, y - 10, x + 10, y + 10);
//		EndPaint(hWnd, &ps);
//		return 0;
//	}	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}


//3번

//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	static int x;
//	static int y;
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		x = LOWORD(lParam);
//		y = HIWORD(lParam);
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Rectangle(hdc, 390, 190, 510, 310);
//		if (x > 500)
//			x = 500;
//		else if (x < 400)
//			x = 400;
//		if (y > 300)
//			y = 300;
//		else if (y < 200)
//			y = 200;
//		Ellipse(hdc, x - 10, y - 10, x + 10, y + 10);
//		EndPaint(hWnd, &ps);
//		return 0;
//	}	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}


//4번

//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	static int flag = -1;
//	static int MessageFlag;
//
//	switch (iMessage)
//	{
//	case WM_LBUTTONDOWN:
//
//		MessageFlag = MessageBox(hWnd, TEXT("사각형 : 예, 원 : 아니오"), TEXT("MessageBox"), MB_YESNO);
//		if (MessageFlag == IDYES)
//		{
//			flag = true;
//		}
//		else if (MessageFlag ==IDNO)
//		{
//			flag = false;
//		}
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//
//		if (flag == false)
//		{
//			Ellipse(hdc, 300, 400, 500, 600);
//		}
//		else if(flag==true)
//		{
//			Rectangle(hdc, 600, 400, 800, 600);
//		}
//
//		EndPaint(hWnd, &ps);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}