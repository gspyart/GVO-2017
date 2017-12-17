#pragma once
#include "stdafx.h"

#define PARM_IN		L"-in:"  //����  ��� ����� ��������� ����
#define PARM_OUT	L"-out:" //���� ��� ����� ��� ��������� ����
#define PARM_LOG	L"-log:" //���� ��� ����� �������
#define NAME_MAXSIZE 50    //������������ ������ ������ ��������
#define PARM_OUT_DEFAULT_EXT L".html" //���������� ����� ���������� ���� �� ���������
#define PARM_LOG_DEFAULT_EXT L".log" //���������� ����� ��������� �� ���������

namespace Parm //��������� ������� ����������
{
	struct PARM //������� ���������
	{
		wchar_t in[NAME_MAXSIZE]; //��� ����� ��������� ����
		wchar_t out[NAME_MAXSIZE]; //��� ����� ���������� �����
		wchar_t log[NAME_MAXSIZE]; //��� ����� ���������
	};

	PARM getparm(int argc, _TCHAR* argv[]); //������������ struct PARM �� ������ ���������� ������� main
};