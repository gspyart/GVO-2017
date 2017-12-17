#include "stdafx.h"
#include "InFile.h"
#include "Parm.h"
#include "Error.h"
#include "output.h"
#include <cstring>
#include <string.h>
#include "LexTable.h"
#include "InFile.h"
using namespace std;

namespace output
{

	OUTPUT createFile(wchar_t logfile[])					// ������������ ��������� LOG
	{
		OUTPUT tempLog = { L" ", new std::ofstream };        // �������������� ��������� ��������� ���������� �����������

		tempLog.txt = new std::ofstream;   // ��������� ���������
		tempLog.txt->open(logfile);        // ��������� ����

		if (!tempLog.txt)                  //���� ���� �� ������
		{
			throw ERROR_THROW(5);             // ���������� ����������
		};

		return tempLog;
	}


	void OUTPUT::WriteInLog(char* stream) //����� char
	{
		OUTPUT *a = this;
		char *p = stream;                        // ���� ����� ������ ��������� ������

		while (*p != '\0')                      // �� ��� ���, ���� �� �����
		{
			*(a->txt) << *p;              // ������� � ����
			p++;                 // ���������
		}
	};
	void Lexical(OUTPUT logfile, In::IN file) {


		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		char buffer[100];
		strftime(buffer, 100, "����� �������� �����: %H:%M:%S %d.%m.%y \n\n", timeinfo);
		*logfile.txt << endl << "====================������ ������������ �����������==================== " << endl << endl;
		logfile.WriteInLog(buffer);
		*logfile.txt << "���������� �������������� ����� " << file.lines << endl;
		*logfile.txt << "���������� ����������������� ��������: " << file.ignor << endl;
		*logfile.txt << "���������� ������: " << file.Errors << endl << endl;
		In::Err* p;
		p = file.err;
		for (int i = 0; i != file.Errors; i++) {
			*logfile.txt << "������: " << p->lin << " ";
			*logfile.txt << "�������: " << p->pos << endl;
			p++;
		}
		*logfile.txt << endl;
		logfile.WriteInLog("������������ ������� ����: \n");
		logfile.WriteInLog(file.text);

		if (file.Errors != 0) throw ERROR_THROW(10);


	}
	void LTlist(OUTPUT logfile, char* a, int ns, LexTable::LexTable lextable, IDTable::IdTable id) {
		*logfile.txt << endl;
		int line = 1;
		char* p = a;
		*logfile.txt << endl << "==================������� ������================= " << ns+1 << endl;
		
		int k = 1;
		int sn;
		*logfile.txt << k << ": ";
		for (int i = 0; i != lextable.size; i++) {

			*logfile.txt << lextable.table[i].lexema;
			
			if (lextable.table[i].idxTI != LT_TI_NULLDIX) { *logfile.txt << '[' << lextable.table[i].idxTI << ']'; }
			
			sn = lextable.table[i].sn;
			if (sn != lextable.table[i + 1].sn && i != lextable.size - 1) { k++;  *logfile.txt << endl << k << ": "; }
			
		}
		*logfile.txt << endl;

		*logfile.txt << "===================================== ������� ��������������� =====================================\n" <<
			std::setw(10) << std::left << "ID " <<
			std::setw(16) << std::left << "��� ������ " <<
			std::setw(15) << std::left << "��� " <<
			std::setw(30) << std::left << "������ � ������� ������ " <<
			std::setw(20) << std::left << "�������� " <<
			std::setw(20) << std::left << "������������" <<
			std::endl;

		for (int i = 0; i != id.size; i++) {

			*logfile.txt << std::setw(9) << std::left <<  id.table[i].id << " ";
			switch (id.table[i].iddatatype) {
			case IDTable::INT: *logfile.txt << std::setw(16) << std::left << "Integer"; break;
			case IDTable::STR: *logfile.txt << std::setw(16) << std::left << "String"; break;
			}

			*logfile.txt << std::setw(15) << std::left;
			switch (id.table[i].idtype) {
			case IDTable::P: *logfile.txt <<  "��������"; break;
			case IDTable::F: *logfile.txt << "�������"; break;
			case IDTable::V: *logfile.txt << "����������"; break;
			case IDTable::L: *logfile.txt << "�������"; break;
			}
			*logfile.txt << std::setw(31) << std::left;
			*logfile.txt << id.table[i].idxfirstLE;

			*logfile.txt << std::setw(29) << std::left;

			if (id.table[i].iddatatype == IDTable::INT) 	*logfile.txt <<  id.table[i].value.vint;
			if (id.table[i].iddatatype == IDTable::STR) { *logfile.txt << id.table[i].value.vstr->str << '[' << id.table[i].value.vstr->len << ']'; }

			*logfile.txt << id.table[i].spacename;

			*logfile.txt << endl;
		
		}
		*logfile.txt << endl;
		*logfile.txt << "=============================================================================================================================\n\n";
	
	}
	void Syntax(OUTPUT logfile, In::IN file) {

		*logfile.txt << endl << endl << endl << "====================������ ��������������� �����������==================== " << endl << endl;
		cout << endl << endl;
	}

};