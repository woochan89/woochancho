#include <tchar.h>


#include "PictureApp.h"





int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *, int) {


	PictureApp *pApp = nullptr;





	// 객체를 생성하고 실행한다.


	pApp = new PictureApp(hInstance);


	pApp->Run();





	// 종료한다.


	delete pApp;





	return 0;


}