#include<Windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;//�۷ι� �ν��Ͻ��ڵ鰪
LPCTSTR lpszClass = TEXT("HelloWorld"); //Ŭ���� �� : â�̸�
TCHAR str[256];




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


//���� 1��

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


//2��

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


//3��

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


//4��

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
//		MessageFlag = MessageBox(hWnd, TEXT("�簢�� : ��, �� : �ƴϿ�"), TEXT("MessageBox"), MB_YESNO);
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