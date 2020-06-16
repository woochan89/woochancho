#include<Windows.h>
#include<math.h>
#include<time.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND, UINT, UINT, DWORD);

HINSTANCE g_hInst;//글로벌 인스턴스핸들값
LPCTSTR lpszClass = TEXT("HelloWorld"); //클래스 명 : 창이름
TCHAR str[256];

int x = 300;
int y = 300;


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
	SYSTEMTIME st;
	static TCHAR sTime[128];
	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 10, TimeProc);
		SendMessage(hWnd, 0, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 90, 90, 510, 510);
		Ellipse(hdc, x - 10, y - 10, x + 10, y + 10);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	static int timeb = time(NULL);
	//static int angle = (timeb % 360) + 1;
	static int angle = 90;
	int tmpNum;

	if ((x <= 100 || x >= 500) && (angle == 90 || angle == 270))
	{
		angle += 180;
	}
	else if (x <= 100 || x >= 500)
	{
		if (angle >= 270)
			tmpNum = angle - 270;
		else if (angle >= 180)
			tmpNum = angle - 180;
		else if (angle >= 90)
			tmpNum = angle - 90;
		else
			tmpNum = angle;

		angle = angle - tmpNum + 180 - tmpNum;
	}

	if ((y <= 100 || y >= 500) && (angle == 0 || angle == 180))
	{
		angle += 180;
	}
	else if (y <= 100 || y >= 500)
	{
		if (angle >= 270)
			tmpNum = angle - 270;
		else if (angle >= 180)
			tmpNum = x - 180;
		else if (angle >= 90)
			tmpNum = x - 90;
		else
			tmpNum = angle;
		angle = angle - tmpNum + 180 - tmpNum;
	}



	if (angle > 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	x = x + cos(angle) * 1;
	y = y + sin(angle) * 1;


	InvalidateRect(hWnd, NULL, TRUE);
}