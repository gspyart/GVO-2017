#include "stdafx.h"
#include "InFile.h"
#include "Error.h"
#include <initializer_list>
#include <locale>
#include <fstream>
#include <iostream>
#include "output.h"

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN myIn;

		int position = 0;
		myIn.size = 0;
		myIn.lines = 1;
		myIn.ignor = 0;

		myIn.Errors = 0;
		myIn.err = new Err[IN_MAX_LEN_TEXT];
		myIn.text = new char[IN_MAX_LEN_TEXT];

		bool check_text = 0;
		std::ifstream inFile;
		inFile.open(infile);
		bool comment = false;

		if (!inFile)
		{
			throw ERROR_THROW(4);
		}
		else
		{

			unsigned char tempChar;
			while ((tempChar = inFile.get()) && !inFile.eof())
			{
				if (tempChar == 0x09) continue; //удаление tab'ов
				
				if (tempChar == IN_CODE_ENDL) 
				{
					comment = false;
					if (myIn.text[myIn.size - 1] == '|') { position = 0; continue; }
					myIn.text[myIn.size] = '|';
					myIn.lines++;
					position = 0;
				}
				

					else if (myIn.code[tempChar] == 0) //допустимость символа
					{
						myIn.text[myIn.size] = '!';
						myIn.err[myIn.Errors].lin = myIn.lines;
						myIn.err[myIn.Errors].pos = position;
						myIn.err[myIn.Errors] = In::Err(myIn.lines, position);
						myIn.Errors++;
						
					}
					else if (myIn.code[tempChar] == 1)
					{

						if (tempChar == (unsigned char)145) { check_text = 1; }
						if (tempChar == (unsigned char)146) { check_text = 0; }
						if (check_text == 0) {
							if ((int)tempChar == 32) {

								if ((myIn.text[myIn.size - 1] == ' ' || myIn.text[myIn.size - 1] == ';' || //удаление лишних пробелов
									myIn.text[myIn.size - 1] == ',' || myIn.text[myIn.size - 1] == '=' ||
									myIn.text[myIn.size - 1] == ')' || myIn.text[myIn.size - 1] == '+' ||
									myIn.text[myIn.size - 1] == '-' || myIn.text[myIn.size - 1] == '*' ||
									myIn.text[myIn.size - 1] == '/' || myIn.text[myIn.size - 1] == '|') &&
									tempChar == ' ') {
									continue;

								}
							}
							if ((tempChar == '=' || tempChar == '+' || tempChar == '-' ||
								tempChar == '*' || tempChar == '/' || tempChar == '(' ||
								tempChar == ')' || tempChar == '|' || tempChar == ',' || tempChar == ';' || tempChar == ':') && myIn.text[myIn.size - 1] == ' ' ) {
								myIn.text[myIn.size - 1] = tempChar; 
								continue;

							}
						}
						
						myIn.text[myIn.size] = tempChar;
					}
					else if (myIn.code[tempChar] == 2)
					{
						myIn.ignor++;
						continue;
					}
				if (tempChar == '/' && myIn.text[myIn.size - 1] == '/') { myIn.size--; comment = true; } //удаление комментариев
				if (comment == true) { continue; }

					position++;
					myIn.size++;
				}

				myIn.text[myIn.size] = '\0';
				myIn.size--;


				inFile.close();
			}
			

			if (myIn.size == 0)
			{
				myIn.lines = 0;
			}
		
			return myIn;
		}
	}
