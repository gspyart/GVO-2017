// GVO-2017.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cstring"
#include "error.h"
#include "Parm.h"
#include "InFile.h"
#include "js.h"
#include "Greibach.h"
#include "Polish.h"
#include "MFST.h"
#include "output.h"
#include "LexTable.h"
#include "IDtable.h"
#include "fillTables.h"
#include "FST.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])

{
	setlocale(LC_ALL, "rus");

	try {

		Parm::PARM input = Parm::getparm(argc, argv);//входные параметры
		In::IN file = In::getin(input.in);//получение и обработка входного файла
		output::OUTPUT logfile = output::createFile(input.log); // формирование log файл


		output::Lexical(logfile, file);	
		LexTable::LexTable lextable = LexTable::Create(LT_MAXSIZE); //таблица лексем	
		IDTable::IdTable idtable = IDTable::Create(TI_MAXSIZE); // таблица идентификаторов

		

		fillTables::LexemScan(idtable, lextable, file, logfile); //Лексический анализ
	


		MFST_TRACE_START(logfile);
		MFST::Mfst mfst(lextable, GRB::getGreibach());
		mfst.start(logfile);
		mfst.savededucation();


		//output::Syntax(logfile, file); 

		output::OUTPUT js = output::createFile(input.out); // формирование лог файл
		Generation(lextable, idtable, js);

		PN::convertToPolishNotation(lextable, idtable);           //польская нотация
		PN::WriteLexPN(lextable, logfile);




		cout << "Исходный код успешно скомпилирован! " << endl << endl;
	}
	catch (ERROR::error error_msg) {
		cout <<"Ошибка номер: "<< error_msg.id << endl;
		cout <<"Сообщение об ошибке: " << error_msg.msg << endl;
		cout <<"Строка " << error_msg.line << endl;
		cout <<"Позиция " << error_msg.pos << endl;


	}


}

