#include<Windows.h>
#include<math.h>
#include<time.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND, UINT, UINT, DWORD);

HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
LPCTSTR lpszClass = TEXT("HelloWorld"); //Ŭ���� �� : â�̸�
TCHAR str[256];

int x = 300;
int y = 300;


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