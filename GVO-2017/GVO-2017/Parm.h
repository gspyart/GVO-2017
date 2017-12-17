#pragma once
#include "stdafx.h"

#define PARM_IN		L"-in:"  //ключ  для файла исходного кода
#define PARM_OUT	L"-out:" //ключ для файла для объектноо кода
#define PARM_LOG	L"-log:" //ключ для файла журнала
#define NAME_MAXSIZE 50    //максимальная длинна строки парамтра
#define PARM_OUT_DEFAULT_EXT L".html" //расширение файла объектного кода по умолчанию
#define PARM_LOG_DEFAULT_EXT L".log" //расширение файла протокола по умолчанию

namespace Parm //обработка входных параметров
{
	struct PARM //входные параметры
	{
		wchar_t in[NAME_MAXSIZE]; //имя файла исходного кода
		wchar_t out[NAME_MAXSIZE]; //имя файла объектного файла
		wchar_t log[NAME_MAXSIZE]; //имя файла протокола
	};

	PARM getparm(int argc, _TCHAR* argv[]); //сформировать struct PARM на основе параметров функции main
};