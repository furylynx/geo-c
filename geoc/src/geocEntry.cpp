/**
 * This file contains the bada application entry point.
 */
#include "GeoC.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

_EXPORT_ int OspMain(int argc, char *pArgv[]);
#ifdef _PROFILE
extern void start_profile (void);
extern void end_profile (void);
#else
#define start_profile()
#define end_profile()
#endif


/**
 * The entry function of bada application called by the operating system.
 */
int
OspMain(int argc, char *pArgv[])
{
	result r = E_SUCCESS;

	AppLog("Application started.");
	ArrayList* pArgs = new ArrayList();
	pArgs->Construct();
	for (int i = 0; i < argc; i++)
		pArgs->Add(*(new String(pArgv[i])));

// String conversions !!
//	const char* testString1 = "TestString 123";
//	AppLog("Ein Test: %s", testString1);
//
//	Osp::Base::String s = Osp::Base::String("Bumm!");
//	AppLog("Zwei Test: %s", s.GetPointer());
//
//	Osp::Base::ByteBuffer* buf = Osp::Base::Utility::StringUtil::StringToUtf8N(s);
//	char* charBuf = (char*)buf->GetPointer();
//	AppLog("Drei Test: %s", buf->GetPointer());

	start_profile();
	r = Osp::App::Application::Execute(GeoC::CreateInstance, pArgs);
	if (IsFailed(r))
	{
		AppLogException("Application execution failed-[%s].", GetErrorMessage(r));
		r &= 0x0000FFFF;
	}
	end_profile();

	pArgs->RemoveAll(true);
	delete pArgs;
	AppLog("Application finished.");

	return static_cast<int>(r);
}
#ifdef __cplusplus
}
#endif // __cplusplus
