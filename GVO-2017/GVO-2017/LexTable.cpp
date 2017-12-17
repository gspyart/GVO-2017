#include "stdafx.h"
#include <climits>
#include "LexTable.h"
#include "FST.h"
#include "IDtable.h"
#include "InFile.h"
#include "output.h"
using namespace std;

namespace LexTable {


	LexTable Create(int size)
	{
		LexTable lt;

		lt.maxsize = size;
		lt.size = 0;
		lt.table = new Entry[lt.maxsize];
		memset(lt.table, NULL, sizeof(Entry)*lt.maxsize);

		return lt;
	};

	void Add(LexTable& lextable, Entry entry)
	{
		lextable.table[lextable.size++] = entry;
	};

	Entry GetEntry(LexTable& lextable, int n)
	{
		return lextable.table[n];
	};

	void Delete(LexTable& lextable)
	{
		delete &lextable;
	};



}
