#include<Windows.h>
#include<math.h>
#include<time.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND, UINT, UINT, DWORD);

HINSTANCE g_hInst;//글로벌 인스턴스핸들값
LPCTSTR lpszClass = TEXT("HelloWorld"); //클래스 명 : 창이름
TCHAR str[256];

float x = 300;
float y = 300;


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
		SetTimer(hWnd, 1, 5, TimeProc);
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
	static int angle = 30;
	int tmpNum;

	if (((int)x <= 100 || (int)x >= 500) && (angle == 90 || angle == 270))
	{
		angle += 180;
	}
	else if ((int)x <= 100 || (int)x >= 500)
	{
		if (angle >= 270)
			angle = 270 * 2 - angle;
		else if (angle >= 180)
			angle = 180 * 2 - angle;
		else if (angle >= 90)
			angle = 90 * 2 - angle;
		else
			angle = -angle;
	}

	if (((int)y <= 100 || (int)y >= 500) && (angle == 0 || angle == 180))
	{
		angle += 180;
	}
	else if ((int)y <= 100 || (int)y >= 500)
	{
		if (angle >= 270)
			angle = 270 * 2 - angle;
		else if (angle >= 180)
			angle = 180 * 2 - angle;
		else if (angle >= 90)
			angle = 90 * 2 - angle;
		else
			angle = -angle;
	}



	if (angle > 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;


	float tmp;

	tmp = ((double)angle + 270) * 3.14 / 180;

	x = x + cos(tmp) * 1;
	y = y + sin(tmp) * 1;


	//x = x + cos(angle) * 1;
	//y = y + sin(angle) * 1;


	InvalidateRect(hWnd, NULL, TRUE);
}



//
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	SYSTEMTIME st;
//	static TCHAR sTime[128];
//	int Circle_R = 100;
//	int Circle_X = 200;
//	int Circle_Y = 200;
//	char text[3];
//	int tmphour = 0;
//
//	switch (iMessage)
//	{
//	case WM_CREATE:
//		SetTimer(hWnd, 1, 1000, TimeProc);//초
//		SendMessage(hWnd, 0, 1, 0);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		//원그리기
//
//		Ellipse(hdc, Circle_X - Circle_R, Circle_Y - Circle_R + 6, Circle_X + Circle_R, Circle_Y + Circle_R + 6);
//
//
//		//시간그리기
//
//		for (int tmp = 4, i = 1; i <= 360; i++)
//		{
//			SetTextAlign(hdc, TA_CENTER);
//			if (i % 30 == 0)
//			{
//				if (tmp < 10)
//					sprintf(text, "%d%d", 0, tmp);
//				else
//					sprintf(text, "%d", tmp);
//				tmp++;
//				if (tmp > 12)
//					tmp = 1;
//				TextOut(hdc, Circle_X + cos(i * 3.14 / 180) *(Circle_R - 15), Circle_Y + sin(i * 3.14 / 180)*(Circle_R - 15), TEXT(text), 2);
//
//			}
//		}
//
//
//		//for (int i = 1; i <= 12; i++)
//		//{
//		//	SetTextAlign(hdc, TA_CENTER);
//		//	if (i < 10)
//		//		sprintf(text, "%d%d", 0, i);
//		//	else
//		//		sprintf(text, "%d", i);
//		//	TextOut(hdc, Circle_X + cos(i * 30 * 3.14 / 180)*(Circle_R - 15), Circle_Y + sin(i * 30 * 3.14 / 180)*(Circle_R - 15), TEXT(text), 2);
//		//}
//
//		//초침 그리기
//		for (int i = 1; i <= 70; i++)
//		{
//			SetPixel(hdc, Circle_X + cos(ct->tm_sec / 60 * 3.14 / 180)*i, Circle_Y + sin(ct->tm_sec / 60 * 3.14 / 180)*i, RGB(0, 0, 0));
//		}
//
//		//분침 그리기
//		for (int i = 1; i <= 60; i++)
//		{
//			SetPixel(hdc, Circle_X + cos(ct->tm_min / 60 * 3.14 / 180)*i, Circle_Y + sin(ct->tm_min / 60 * 3.14 / 180)*i, RGB(255, 0, 0));
//		}
//
//		//시침 그리기
//		for (int i = 1; i <= 50; i++)
//		{
//			if (ct->tm_hour > 12)
//				tmphour = ct->tm_hour - 12;
//			SetPixel(hdc, Circle_X + cos(tmphour / 12 * 3.14 / 180)*i, Circle_Y + sin(tmphour / 12 * 3.14 / 180)*i, RGB(0, 255, 0));
//		}
//
//
//
//		EndPaint(hWnd, &ps);
//		return 0;
//	case WM_DESTROY:
//		KillTimer(hWnd, 1);
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
//
//void CALLBACK TimeProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
//{
//
//
//	(ct->tm_sec)++;
//	if (ct->tm_sec >= 60)
//	{
//		ct->tm_sec = 0;
//		(ct->tm_min)++;
//		if (ct->tm_min >= 60)
//		{
//			(ct->tm_hour)++;
//			if (ct->tm_hour > 12)
//				ct->tm_hour = 1;
//		}
//	}
//
//
//
//
//
//	InvalidateRect(hWnd, NULL, TRUE);
//}