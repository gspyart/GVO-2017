#pragma once
#define ID_MAXSIZE 100
#define TI_MAXSIZE 4096
#define TI_INT_DEFAULT 0x00000000
#define TI_STR_DEFAULT 0x00
#define TI_NULLIDX 0xffffffff
#define TI_STR_MAXSIZE 255
#define TI_NAMESPACE 255
namespace IDTable
{
	enum IDDATATYPE { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };
	struct Entry
	{
		
		int idxfirstLE;
		char id[ID_MAXSIZE];
		IDDATATYPE iddatatype;
		IDTYPE idtype;
		char spacename[TI_NAMESPACE];
		union
		{
			int vint;
			struct
			{
				int len;
				char str[TI_STR_MAXSIZE - 1];
			} vstr[TI_STR_MAXSIZE];
		}value;
	
	};
	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsId(IdTable& idtable, char *id, IDTable::IDTYPE a, char* spacename);
	int IsLex(IdTable& idtable, char* lex);
	void Delete(IdTable& idtable);

//	Entry getEntry(IdTable& idtable, LexTable::LexTable& lextable, char lex, char* lexeme, char* type, bool isHesis);
};