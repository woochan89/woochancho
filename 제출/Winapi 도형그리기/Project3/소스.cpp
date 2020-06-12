#include<Windows.h>
#include<math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//글로벌 인스턴스핸들값
LPCTSTR lpszClass = TEXT("HelloWorld"); //클래스 명 : 창이름


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

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		int Circle_R = 100;
		int Circle_X = 200;
		int Circle_Y = 200;
		//for (int i = 0; i < 360; i++)
		//	SetPixel(hdc, Circle_X + int(sin(i*3.141592 / 180)*Circle_R),
		//		Circle_Y + int(cos(i*3.141592 / 180)*Circle_R), RGB(0,0,0));
		for (int i = 0; i < 360; i++)
		{
			SetPixel(hdc, Circle_X + cos(i*3.14 / 180)*Circle_R, Circle_Y + sin(i*3.14 / 180)*Circle_R,RGB(0,0,0));
		}
		//for (int i = 0; i < 360; i++)
		//{
		//	SetPixel(hdc, Circle_X + cos(i*3.14 / 180)*Circle_R, Circle_Y + sin(i*3.14 / 180)*Circle_R, RGB(0,0,0));
		//}
		//for (int i = 0; i < 360; i++) 
		//{
		//	SetPixel(hdc, 100 + int(sin(i*3.141592 / 180) * 50),
		//		100 + int(cos(i*3.141592 / 180) * 30), RGB(0, 0, 0));
		//}
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}