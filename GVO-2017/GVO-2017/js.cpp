#include "stdafx.h"
#include <fstream>
#include "js.h"
#define IfDEC lt.table[i - 2].lexema == LEX_DEC
#define IfINC lt.table[i - 2].lexema == LEX_INC
#define IfLEN lt.table[i - 2].lexema == LEX_LENLET
using namespace std;
ofstream content("start.html");
void Generation(LexTable::LexTable &lt, IDTable::IdTable &it, output::OUTPUT &js)
{

	*js.txt << "<html>" << endl;
	*js.txt << "<head>" << endl;
	*js.txt << "</head>" << endl;
	*js.txt << "<body>" << endl;
	*js.txt << "<script src=\" function.js\">" << "</script>" << endl; //библиотека
	*js.txt << "<script>" << endl << endl << endl;
	bool hf = false;
	bool p = false;
	int s;
	s = lt.table[0].sn;
	for (int i = 0; i < lt.size; i++)
	{
		if (lt.table[i].sn != s) { *js.txt << endl; s++; }
		if (lt.table[i].lexema == '{' && hf == true) hf = false;

		switch (lt.table[i].lexema)
		{
		case 'm': *js.txt << "function module ()"; break;
		case 'f': {
			hf = true;
			*js.txt << "function ";
			break;
		}
		case 't': {
			if (hf == false) *js.txt << "var ";
			break;

		}
		case '(' :{
			if(lt.table[i+1].lexema != 't') *js.txt << "(";  break;
		}
		case ')': {
			if (lt.table[i-1].lexema != 't') *js.txt << ")";  break;
		}
		case 'v': {
			*js.txt << lt.table[i].z; break;
		}
		case 'e': {*js.txt << "="; break; }
		case ',': { *js.txt << ','; break; }
		case 'i': {
			
			*js.txt << it.table[lt.table[i].idxTI].id << " ";
			//if (it.table[lt.table[i].idxTI].idtype == IDTable::F) { *js.txt << "("; }
	
			break;
		}
		case ';': {*js.txt << ';'; break; }
		case '{': {
			*js.txt << "{";
			break;
		}
		case '}': *js.txt << "}"; break;
		
	

		case 'r':
		{
			*js.txt << "return ";
			break;
		}
		case 'l': {
			if (it.table[lt.table[i].idxTI].value.vint != NULL) *js.txt << it.table[lt.table[i].idxTI].value.vint;
			else *js.txt << it.table[lt.table[i].idxTI].value.vstr->str;
				break;
		}
		}
		
	}
	*js.txt << endl << "alert(module());" << endl;
	*js.txt << endl << endl << endl;
	*js.txt << "</script>" << endl;
	*js.txt << "</p>" << endl;
	*js.txt << "</body>" << endl;
	*js.txt << "</html>" << endl;
}
