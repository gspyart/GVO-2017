#pragma once
#include "stdafx.h"
#include "InFile.h"
#include "Parm.h"
#include "IDtable.h"
#include "Error.h"
#include "LexTable.h"
#include <fstream>

namespace output //������ � ����������
{
	struct OUTPUT
	{
		wchar_t logfile[NAME_MAXSIZE]; // ��� ����� ���������
		std::ofstream * txt; // �������� ����� ���������


		void WriteInLog(char *stream);

	};

	OUTPUT createFile(wchar_t logfile[]); // ������������ ��������� LOG
	void Lexical(OUTPUT logfile, In::IN file);
	void LTlist(OUTPUT logfile, char* a, int ns, LexTable::LexTable lextable, IDTable::IdTable id);
	void Syntax(OUTPUT logfile, In::IN file);
};