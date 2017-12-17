#include "stdafx.h"

#include <stack>
#include <map>

#include "Polish.h"
#include "LexTable.h"
#include "IDtable.h"

namespace PN
{
	void convertToPolishNotation(LexTable::LexTable &lextable, IDTable::IdTable &idtable)
	{
		for (int i = 0; i < lextable.size; i++)
		{
			if (lextable.table[i].lexema == LEX_EQUAL)
			{
				polishNotation(i + 1, lextable, idtable);
			};
		};
	};

	void polishNotation(int startPos, LexTable::LexTable &lextable, IDTable::IdTable &idtable)
	{
		std::stack<LexTable::Entry> stack;
		std::map<char, int> priority =
		{
			{ '(', 1 },
			{ ')', 1 },
			{ '+', 2 },
			{ '-', 2 },
			{ '*', 3 },
			{ '/', 3 }
		};

		int i_lt = startPos;
		int i_pn = 0;

		for (; lextable.table[i_lt].lexema != LEX_END; i_lt++)
		{
			char lexema = lextable.table[i_lt].lexema;

			switch (lexema)
			{
			case LEX_LEFTHESIS: stack.push({ lexema, lextable.table[i_lt].sn , 0}); break;
			case LEX_OPERATOR:
				while
					(
						!stack.empty() &&
						stack.top().lexema == LEX_OPERATOR &&
						priority[idtable.table[stack.top().idxTI].id[0]] >= priority[idtable.table[idtable.table[i_lt].idxfirstLE].id[0]]
						)
				{
					lextable.table[startPos + i_pn++] = stack.top();
					stack.pop();
				};

				stack.push(lextable.table[i_lt]);

				break;
			case LEX_RIGHTHESIS:
				while (!stack.empty() && stack.top().lexema != LEX_LEFTHESIS)
				{
					lextable.table[startPos + i_pn++] = stack.top();
					stack.pop();
				};

				if (!stack.empty()) stack.pop();

				break;
			/* case LEX_DEC:
			case LEX_LENLET:
			case LEX_INC:

				stack.push(lextable.table[i_lt]);
				stack.push(lextable.table[i_lt + 2]);
				lextable.table[startPos + i_pn++] = stack.top();
				stack.pop();
				lextable.table[startPos + i_pn++] = stack.top();
				stack.pop();
				i_lt += 3;
				break;
			case LEX_SHOW:

				lt.table[startPos + i_pn++] = lt.table[i_lt];
				break;
			case LEX_ANS:
				lt.table[startPos + i_pn++] = lt.table[i_lt];
				break;
				*/
			default:
				if (idtable.table[lextable.table[i_lt].idxTI].idtype != IDTable::F)
				{
					lextable.table[startPos + i_pn++] = lextable.table[i_lt];
				}
				else
				{
					int idT = lextable.table[i_lt].idxTI;
					while (lextable.table[i_lt].lexema != LEX_RIGHTHESIS)
					{
						if ((lextable.table[i_lt].lexema == LEX_ID) || (lextable.table[i_lt].lexema == LEX_LITERAL)) stack.push(lextable.table[i_lt]);
						i_lt++;
					}

					while (!stack.empty() && (stack.top().idxTI != idT))
					{
						lextable.table[startPos + i_pn++] = stack.top();
						stack.pop();
					}
					lextable.table[startPos + i_pn++] = stack.top();
					stack.pop();
				};

				break;
			};
		};

		for (int j = startPos + i_pn; j < i_lt; j++)
		{
			if (!stack.empty())
			{
				lextable.table[startPos + i_pn++] = stack.top();
				stack.pop();
			}
			else
			{
				lextable.table[j] = { '#', lextable.table[j].sn, 0 };
			};
		};

	};
	void WriteLexPN(LexTable::LexTable lt, output::OUTPUT &log )
	{

		*log.txt << std::endl << "================================= Обратная польская запись =================================" << std::endl << std::endl;

		for (int i = 0; i < lt.size; i++)
		{
			if (lt.table[i].sn != lt.table[i - 1].sn)
			{
				*log.txt << std::endl;
				*log.txt << lt.table[i].sn + 1 << " ";
			};

			*log.txt << lt.table[i].lexema;
			if (lt.table[i].idxTI != -1) *log.txt << "[" << lt.table[i].idxTI << "]";
		};

		*log.txt << std::endl << std::endl;
	};
};