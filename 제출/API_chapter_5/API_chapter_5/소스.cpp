#include <tchar.h>


#include "PictureApp.h"





int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *, int) {


	PictureApp *pApp = nullptr;





	// ��ü�� �����ϰ� �����Ѵ�.


	pApp = new PictureApp(hInstance);


	pApp->Run();





	// �����Ѵ�.


	delete pApp;





	return 0;


}