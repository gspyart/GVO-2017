#pragma once

#include "IDtable.h"
#include "LexTable.h"

namespace PN
{
	void convertToPolishNotation(LexTable::LexTable &lextable, IDTable::IdTable &idtable);
	void polishNotation(int pos, LexTable::LexTable &lextable, IDTable::IdTable &idtable);
	void WriteLexPN(LexTable::LexTable lt, output::OUTPUT &log);
};