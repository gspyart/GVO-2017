#include "stdafx.h"
#include "Parm.h"
#include "error.h"
namespace Parm
{

	PARM getparm(int argc, _TCHAR* argv[])// : argc Ц количество параметров (int), argv Ц массив указателей на строки 
	{
		PARM structParm;
		wchar_t *fieldIn, *fieldOut, *fieldLog;
		wchar_t q[NAME_MAXSIZE], e[NAME_MAXSIZE];
		for (int i = 0; i < argc; i++)
			if (wcslen(argv[i])>NAME_MAXSIZE)
				throw ERROR_THROW(2);
		if (argc == 1)
		{
			throw ERROR_THROW(1);
		}
		if (argc == 2)
		{
			fieldIn = wcsstr(argv[1], PARM_IN);// "-in:C:\in.txt"
			fieldIn += wcslen(PARM_IN);//"C:\in.txt"
			wcscpy_s(structParm.in, fieldIn);
			wcscpy_s(q, structParm.in);
			wcscpy_s(e, structParm.in);
			wcsncat_s(q, NAME_MAXSIZE, PARM_OUT_DEFAULT_EXT, wcslen(PARM_OUT_DEFAULT_EXT));//"C:\in.txt.out"
			wcscpy_s(structParm.out, q);
			wcsncat_s(e, NAME_MAXSIZE, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT));//"C:\in.txt.log"
			wcscpy_s(structParm.log, e);
			return structParm;
		}
		if (argc == 3)
		{
			fieldIn = wcsstr(argv[1], PARM_IN);// "-in:C:\in.txt"
			fieldIn += wcslen(PARM_IN);//"C:\in.txt"
			wcscpy_s(structParm.in, fieldIn);
			fieldOut = wcsstr(argv[2], PARM_OUT);// "-out:C:\out.txt"
			fieldOut += wcslen(PARM_OUT);//"C:\out.txt"
			wcscpy_s(structParm.out, fieldOut);
			wcscpy_s(e, structParm.in);
			wcsncat_s(e, NAME_MAXSIZE, PARM_LOG_DEFAULT_EXT, wcslen(PARM_LOG_DEFAULT_EXT));//"C:\in.txt.log"
			wcscpy_s(structParm.log, e);
			return structParm;
		}
		if (argc == 4)
		{
			fieldIn = wcsstr(argv[1], PARM_IN);// "-in:C:\in.txt"
			fieldIn += wcslen(PARM_IN);//"C:\in.txt"
			wcscpy_s(structParm.in, fieldIn);
			fieldOut = wcsstr(argv[2], PARM_OUT);// "-out:C:\out.txt"
			fieldOut += wcslen(PARM_OUT);//"C:\out.txt"
			wcscpy_s(structParm.out, fieldOut);
			fieldLog = wcsstr(argv[3], PARM_LOG);// "-log:C:\log.txt"
			fieldLog += wcslen(PARM_LOG);//"C:\log.txt"
			wcscpy_s(structParm.log, fieldLog);
			return structParm;
		}
		return structParm;
	}
};