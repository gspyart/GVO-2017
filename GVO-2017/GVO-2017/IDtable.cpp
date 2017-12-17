	#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Error.h"
#include "IDTable.h"
#include "LexTable.h"
#include "FST.h"
namespace IDTable
{
	IdTable Create(int size)
	{
		if (size > TI_MAXSIZE)						throw ERROR_THROW(120)

			IdTable idtable;

		// инициализируем начальными значениями
		idtable.maxsize = size;			// макс. емкость
		idtable.table = NULL;			// массив элементов
		idtable.size = 0;				// текущий размер

		return idtable;
	}
	// добавить элемент словаря
	void Add(IdTable& idtable, Entry ed)
	{
		if (idtable.size == idtable.maxsize)				throw ERROR_THROW(121);
		idtable.table = (Entry*)realloc(idtable.table, ++idtable.size * sizeof(Entry));
		idtable.table[idtable.size - 1] = ed;
	}
	

	// получить элемент словаря
	Entry GetEntry(IdTable idtable, int n)
	{
		if (n > idtable.size || n < 0)						throw ERROR_THROW(122)
			return idtable.table[n];
	}

	// удалить словарь
	void Delete(IdTable& d)
	{
		delete[] d.table;
		d.table = NULL;		// массив элементов
		d.size = 0;			// текущий размер
	}


	// возврат: номер строки(если есть), TI_NULLIDX(если нет)
	int IsId(IdTable& idtable, char *id, IDTable::IDTYPE a, char* spacename)
	{
		// проверка идентификаторов
		for (int i = 0; i < idtable.size; i++)
		{
			if (strcmp(idtable.table[i].id, id) == 0 && idtable.table[i].idtype == IDTable::F) return i;
			if (idtable.table[i].idtype == IDTable::F && strcmp(idtable.table[i].id, id) == 0) throw ERROR_THROW(11); //проверка на наличие данной функции
			
			/*if (((strncmp(idtable.table[i].id, id, 5) == 0)
				|| (strcmp(idtable.table[i].id, id) == 0) ) && a == idtable.table[i].idtype
				)
				return i; */
			if (((strncmp(idtable.table[i].id, id, 5) == 0 || (strcmp(idtable.table[i].id, id) == 0)) && strcmp(idtable.table[i].spacename, spacename) == 0)) return i;
			
		
		}
		return TI_NULLIDX;
	}
	int IsLex(IdTable& idtable, char* lex)
	{
		for (int i = 0; i < idtable.size; i++)
		{
			char b[10];
			_itoa(idtable.table[i].value.vint, b, 10);
			if ((strncmp(idtable.table[i].value.vstr->str, lex, 5) == 0)
				|| (strcmp(idtable.table[i].value.vstr->str, lex) == 0) ||
				strcmp(b, lex) == 0)
				return i;
		}
		return TI_NULLIDX;
	}

	/*
	Entry getEntry(IdTable &idtable, LexTable::LexTable &lextable, char lex, char* lexeme, char* type, bool isHesis)
	{
		static int literalIndex = 0;
		Entry entry;

		int ind = IsId(idtable, lexeme);

		if (ind == (int)TI_NULLIDX)
		{
			entry.idxfirstLE = (lextable.size == 0) ? 0 : lextable.table[lextable.size - 1].sn;

			if (strcmp(type, "string") == 0)
				entry.iddatatype = STR;
			else
				entry.iddatatype = INT;


			if (lex != LEX_LITERAL)
			{
				entry.idtype = V;
				if (entry.iddatatype == STR)
				{
					strcpy(entry.value.vstr->str, "");
					entry.value.vstr->len = 0;
				}
				else
					entry.value.vint = 0;
			}

			if (lex == LEX_LITERAL)
			{
				literalIndex++;

				if (lexeme[0] == (char)-111)
				{
					entry.iddatatype = STR;
					int len = entry.value.vstr->len = strlen(lexeme) - 2;

					for (int i = 1; i < len + 1; i++)
						entry.value.vstr->str[i - 1] = lexeme[i];
					entry.value.vstr->str[len] = ENDNULL;
				}
				else
				{
					entry.iddatatype = INT;
					entry.value.vint = atoi(lexeme);
				}
				char name[] = { 'L', '0' + (literalIndex / 10), '0' + (literalIndex % 10), ENDNULL };
				memcpy(&entry.name, name, 4);

				entry.idtype = L;
			}

			else if (isHesis)
				entry.idtype = P;

			memset(entry.id, 0x00, 7);
			memcpy_s(entry.id, 6, lexeme, 6);
		}
		else
		{

			for (int i = 0; i < lextable.size; i++)

				if (ind == lextable.table[i].idxTI)
				{
					entry = idtable.table[ind];
					entry.idxfirstLE = lextable.table[i].sn;
					entry.iddatatype = idtable.table[ind].iddatatype;


					if (isHesis)
						entry.idtype = P;
					else if (entry.idtype != L)
						entry.idtype = V;

					if (entry.idtype == L || entry.idtype == V)
					{
						entry.value = idtable.table[ind].value;
					}
					break;
				}
		}

		return entry;
	}
	*/

	

};