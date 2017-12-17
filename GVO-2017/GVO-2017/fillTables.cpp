#include "stdafx.h"
#include <climits>
#include "LexTable.h"
#include "FST.h"
#include "IDtable.h"
#include <stdlib.h>
#include "InFile.h"
#include <iostream>
#include "output.h"
#include "fillTables.h"
#include <stack>

namespace fillTables {

	void LexemScan(IDTable::IdTable &idtable, LexTable::LexTable &lextable, In::IN &in, output::OUTPUT &log) {

		char buffer[999];
		char buffer2[999];
		char spacename[TI_NAMESPACE];
		bool spacename_bool = false;
		int pos = 0; //позиция буфера
		int lex_pos = 0;
		char tempchar;
		bool help = false;
		char index;
		IDTable::IDDATATYPE TMemory = IDTable::INT;
		IDTable:: IDTYPE SMemory = IDTable::V;
		bool isHesis = false;
		bool ischar = false;
		int wat = 0; //название лексемы
		char type[10];
		char *lexem_text = new char[strlen(in.text)];
		int lt = 0;  //позиция  в тексте лексем
		int ns = 0;  //номер строки
		char lexname[10];  //название лексемы
		bool o = false;
		int iti = 0;
		char* p = in.text;
		for (; *p != '\0'; p++)
		{
			lexname[0] = '\0';

			tempchar = *p;
			buffer[pos] = tempchar;

			if (tempchar == (char)147) { ischar = true; pos = 0; };
			if (tempchar == (char)148) { //литерал
				ischar = false; buffer[pos + 1] = '\0';  lexem_text[lt] = FST::LexDefining(buffer);

				int k = IDTable::IsLex(idtable, buffer);
				if (k == TI_NULLIDX) {
					_itoa(wat, lexname, 8); //название лексемы
					IDTable::Entry entry;

					entry.iddatatype = IDTable::STR;
					entry.idtype = IDTable::L;
					entry.idxfirstLE = (lextable.size == 0) ? 0 : lextable.size ;

					strcpy_s(entry.value.vstr->str, buffer); //значение лексемы
					entry.value.vstr->len = strlen(entry.value.vstr->str)-2; //длина лексемы
					memset(entry.id, 0x00, 7);
					memcpy_s(entry.id, ID_MAXSIZE, lexname, ID_MAXSIZE); //название лексемы

				

					IDTable::Add(idtable, entry);  //добавление лексемы

					LexTable::Entry *qw = new LexTable::Entry;
					*qw = { lexem_text[lt], ns, idtable.size-1 };
					LexTable::Add(lextable, *(qw));

					lt++;  pos = 0; wat++;  continue;
				}
				else {
					LexTable::Entry *qw = new LexTable::Entry;
					*qw = { lexem_text[lt], ns, k };
					LexTable::Add(lextable, *(qw));
				}
			};





			if (ischar == true) {
				buffer[pos] = tempchar;
				pos++;
			}
			else {
				index = FST::LexDefining(tempchar);
			

				if (index != CHAR_MIN || tempchar == SPACE) {
				
					
					if (index == LEX_LEFTBRACE) { SMemory = IDTable::V; }
					if (index == LEX_END) SMemory = IDTable::V;

					buffer[pos] = '\0';
					pos = 0;

					if (buffer[0] != '\0') {
						lexem_text[lt] = FST::LexDefining(buffer); 

						if (lexem_text[lt] == LEX_FUNCTION) { SMemory = IDTable::F; spacename_bool =true; }
						if (lexem_text[lt] == LEX_MODULE) strcpy(spacename, "module");

						if (lexem_text[lt]==LEX_TYPE) {
							strcpy_s(type, buffer);
							if (strcmp(type, "string")) TMemory = IDTable::INT;
							else TMemory = IDTable::STR;
						}
						
						
						

						if (lexem_text[lt] == LEX_ID) {
							memset(buffer2, 0x00, ID_MAXSIZE);
							memcpy_s(buffer2, ID_MAXSIZE, buffer, ID_MAXSIZE);

							if (spacename_bool == true) { strcpy(spacename, buffer); spacename_bool = false; }
							int k = IDTable::IsId(idtable, buffer2, SMemory,spacename);

							

							if (k == TI_NULLIDX) {
								
								
								IDTable::Entry entry;
								entry = { ns, ' ', IDTable::INT, IDTable::V};
								entry.idxfirstLE = (lextable.size == 0) ? 0 : lextable.size ;
					
								entry.idtype = SMemory;
								entry.iddatatype = TMemory;
								if (TMemory == IDTable::INT) entry.value.vint = 0;
								if (TMemory == IDTable::STR) { entry.value.vstr->str[0] = 0; entry.value.vstr->len = 0; }
								memset(entry.id, 0x00, ID_MAXSIZE);
								memcpy_s(entry.id, ID_MAXSIZE, buffer, ID_MAXSIZE);
								
								if (entry.idtype == IDTable::V || entry.idtype == IDTable::P) strcpy(entry.spacename, spacename);
								IDTable::Add(idtable, entry);
								

								LexTable::Entry *qw = new LexTable::Entry;
								*qw = { lexem_text[lt], ns, idtable.size-1 };
								LexTable::Add(lextable, *(qw));
								
								
								if (SMemory == IDTable::F) SMemory = IDTable::P;

							}
							else {

								LexTable::Entry *qw = new LexTable::Entry;
								*qw = { lexem_text[lt], ns, k };
								LexTable::Add(lextable, *(qw));
							}
						
							/*IDTable::Entry ent;
							if(lexem_text[lt]==LEX_LITERAL) ent = getEntry(idtable, lextable, index, buffer, buffer, isHesis);
							else ent = getEntry(idtable, lextable, index, buffer, buffer, isHesis);
							IDTable::Add(idtable, ent);
							*/
						

						}
						 else if (lexem_text[lt] == LEX_LITERAL) {			//для числового литерала
							int k = IDTable::IsLex(idtable, buffer);

							if (k == TI_NULLIDX) {
								
								_itoa(wat, lexname, 8);
								IDTable::Entry entry;

							
								entry = { ns, ' ', IDTable::INT, IDTable::L };
								entry.iddatatype = IDTable::INT;
								entry.idtype = IDTable::L;
								entry.value.vint = atoi(buffer);
								entry.idxfirstLE = (lextable.size == 0) ? 0 : lextable.size;
							
								memset(entry.id, 0x00, ID_MAXSIZE);
								memcpy_s(entry.id, ID_MAXSIZE, lexname, ID_MAXSIZE);

								IDTable::Add(idtable, entry);


								LexTable::Entry *qw = new LexTable::Entry;
								*qw = { lexem_text[lt], ns, idtable.size-1};
								LexTable::Add(lextable, *(qw));
								wat++;
							}
							else {

								LexTable::Entry *qw = new LexTable::Entry;
								*qw = { lexem_text[lt], ns, k };
								LexTable::Add(lextable, *(qw));
							}
							
						}
						 else {
							 LexTable::Entry *qw = new LexTable::Entry;
							 *qw = { lexem_text[lt], ns, (int)LT_TI_NULLDIX };
							 LexTable::Add(lextable, *(qw));
						 }
					

						lt++;
					}

					if (index != CHAR_MIN && index != '|') {
						lexem_text[lt] = index; 
						LexTable::Entry *qw = new LexTable::Entry;
						*qw = { lexem_text[lt], ns, (int)LT_TI_NULLDIX };
						if (lexem_text[lt] == 'v') qw->z = tempchar;
						LexTable::Add(lextable, *(qw));
						lt++; 
					}
					if (index == SEPARATOR) { lexem_text[lt] = IN_CODE_ENDL; lt++; ns++;}

				
				}

				else {
					pos++;
				}
			}
		}
		lexem_text[lt] = '\0';
		output::LTlist(log, lexem_text, ns, lextable, idtable);
	}
}