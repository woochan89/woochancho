#include<Windows.h>
#include<math.h>
#include<time.h>
#include<stdio.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND, UINT, UINT, DWORD);
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
LPCTSTR lpszClass = TEXT("HelloWorld"); //Ŭ���� �� : â�̸�

float x = 300;
float y = 300;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{

	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	//WndClass�� �⺻ ������ȯ���� ����� ����ü��. �ɹ������� �ؿ��� ����.
	WndClass.cbClsExtra = 0; //���࿵��
	WndClass.cbWndExtra = 0; //���࿵�� (�Ű�x)
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //����
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW); //Ŀ��
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ ���
	WndClass.hInstance = hInstance; //(���α׷� �ڵ鰪(��ȣ)���)
	WndClass.lpfnWndProc = WndProc; //���μ��� �Լ� ȣ��
	WndClass.lpszClassName = lpszClass; //Ŭ���� �̸�
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW; //�������� ������ ������ ���� �� �ٽ� �׸���.
	RegisterClass(&WndClass); //������� WidClass�� ���

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,
		(HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);


	while (GetMessage(&Message, NULL, 0, 0)) //����ڿ��� �޽����� �޾ƿ��� �Լ�(WM_QUIT �޽��� ���� �� ����), �޽����� ������� ��⸦ �ϰ��ִٰ� ���� �۵�.
	{
		TranslateMessage(&Message); // Ű���� �Է� �޽��� ó���Լ�
		DispatchMessage(&Message); //���� �޽����� WndProc�� �����ϴ� �Լ�
	}
	return (int)Message.wParam;
}


//��Ƣ���
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

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
	static int angle = (timeb % 360) + 1;
	float radian;

	if (((int)x <= 100 || (int)x >= 500) && (angle == 90 || angle == 270))
		angle += 180;
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
		angle += 180;
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

	radian = (angle + 270) * 3.14 / 180;

	x = x + cos(radian);
	y = y + sin(radian);

	InvalidateRect(hWnd, NULL, TRUE);
}



//�ð� �׸���
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//	SYSTEMTIME st;
//	TCHAR sTime[20];
//	int Circle_R = 100;
//	int Circle_X = 200;
//	int Circle_Y = 200;
//	char text[3];
//	int tmphour;
//
//	GetLocalTime(&st);
//	sprintf(sTime, "%d:%d:%d", st.wHour, st.wMinute, st.wSecond);
//
//	switch (iMessage)
//	{
//	case WM_CREATE:
//		SetTimer(hWnd, 1, 1000, NULL);//��
//		SendMessage(hWnd, WM_TIMER, 1, 0);
//		return 0;
//	case WM_TIMER:
//		GetLocalTime(&st);
//		sprintf(sTime, "%d:%d:%d", st.wHour, st.wMinute, st.wSecond);
//		InvalidateRect(hWnd, NULL, TRUE);
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		//���׸���
//		Ellipse(hdc, Circle_X - Circle_R, Circle_Y - Circle_R + 6, Circle_X + Circle_R, Circle_Y + Circle_R + 6);
//
//		//�ð��׸���
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
//		//��ħ �׸���
//		for (int i = 1; i <= 70; i++)
//		{
//			SetPixel(hdc, Circle_X + cos((st.wSecond * 6 - 90) * 3.14 / 180)*i, Circle_Y + sin((st.wSecond * 6 - 90) * 3.14 / 180)*i, RGB(0, 0, 0));
//		}
//		//��ħ �׸���
//		for (int i = 1; i <= 60; i++)
//		{
//			SetPixel(hdc, Circle_X + cos((st.wMinute * 6 - 90) * 3.14 / 180)*i, Circle_Y + sin((st.wMinute * 6 - 90) * 3.14 / 180)*i, RGB(255, 0, 0));
//		}
//		//��ħ �׸���
//		if (st.wHour > 12)
//			tmphour = st.wHour - 12;
//		else
//			tmphour = st.wHour;
//		for (int i = 1; i <= 50; i++)
//		{
//			SetPixel(hdc, Circle_X + cos((tmphour * 30 - 90) * 3.14 / 180)*i, Circle_Y + sin((tmphour * 30 - 90) * 3.14 / 180)*i, RGB(0, 255, 0));
//		}
//
//		//�ð� �׸���
//		TextOut(hdc, Circle_X, Circle_Y + Circle_R + 50, sTime, lstrlen(sTime));
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
