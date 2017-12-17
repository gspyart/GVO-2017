#include "stdafx.h"
#include "Greibach.h"

#define GRB_ERROR_SERIES 0

namespace GRB
{
	Greibach greibach(NS('S'), TS('$'),
		7, //количесто всех правил

		Rule(NS('S'), GRB_ERROR_SERIES, 2,   //  Структура программы		
			Rule::Chain(8, TS('p'), TS(':'), NS('P'),  TS('m'),  TS('{'), NS('M'), TS('}'), TS(';')),
			Rule::Chain(5, TS('m'), TS('{'), NS('M'), TS('}'), TS(';'))
		),
		Rule(NS('P'), GRB_ERROR_SERIES + 1, 2,// модуль preprocess
			Rule::Chain(12, TS('f'), TS('('), TS('t'), TS(')'), TS('i'), TS('('), NS('H'), TS(')'), TS('{'), NS('M'), TS('}'), TS(';')),
			Rule::Chain(13, TS('f'), TS('('), TS('t'), TS(')'), TS('i'), TS('('), NS('H'), TS(')'), TS('{'), NS('M'), TS('}'), TS(';'), NS('P'))
		),
		Rule(NS('H'), GRB_ERROR_SERIES + 2, 2, // параметры функции preprocess
			Rule::Chain(6, TS('('), TS('t'), TS(')'), TS('i'), TS(','), NS('H')),
			Rule::Chain(4, TS('('), TS('t'), TS(')'), TS('i'))

		),
		Rule(NS('M'), GRB_ERROR_SERIES + 3, 7,  // возможные конструкции в ф-иях
			Rule::Chain(6, TS('('), TS('t'), TS(')'), TS('i'), TS(';'), NS('M')), //присвоение переменной
			Rule::Chain(5, TS('i'), TS('e'), NS('E'), TS(';'), NS('M')), //присвоение переменной
			Rule::Chain(5, TS('i'), TS('e'), NS('E'), TS(';'),NS('M')), //присвоение переменной
			Rule::Chain(8, TS('i'), TS('e'), TS('i'), TS('('), NS('W'), TS(')'), TS(';'), NS('M')), //иницилизация через вызов функции
			Rule::Chain(6, TS('i'), TS('{'), NS('M'), TS('}'), TS(';'), NS('M')), //тело функции
			Rule::Chain(6, TS('i'), TS('('), NS('J'), TS(')'), TS(';'), NS('M')), //вызов функции

			Rule::Chain(3, TS('r'), NS('E'), TS(';'))
		),
		Rule(NS('E'), GRB_ERROR_SERIES + 4, 6, // выражения
			Rule::Chain(1, TS('i')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(3, TS('('), NS('E'), TS(')')),
			Rule::Chain(4, TS('('), NS('E'), TS(')'), NS('M')),
			Rule::Chain(2, TS('i'), NS('V')),
			Rule::Chain(4, TS('i'), TS('('), NS('J'), TS(')'))
		),
		Rule(NS('J'), GRB_ERROR_SERIES + 5, 5, // принимаемые параметры ф-ии
			Rule::Chain(3, TS('i'), TS(','), NS('W')),
			Rule::Chain(3, TS('l'), TS(','), NS('W')),
			Rule::Chain(1, TS('l')),
			Rule::Chain(1, TS('i')),
			Rule::Chain(4, TS('i'), TS('('), NS('J'), TS(')'))
		),
		Rule(NS('V'), GRB_ERROR_SERIES + 6, 2, // знаки
			Rule::Chain(2, TS('v'), NS('E')),
			Rule::Chain(3, TS('v'), NS('E'), NS('M'))
		)
	);
	
	Rule::Chain::Chain(short psize, GRBALPHABET s, ...)  //конструктор цепочки - праыой части правила(кол-во символов в цепочке, терминал или нетерминал...)
	{
		nt = new GRBALPHABET[size = psize];    //цепочка терминалов
		int*p = (int*)&s;                      //присваиваем символ указателю п
		for (short i = 0; i < psize; ++i)
			nt[i] = (GRBALPHABET)p[i]; //заполняем цепочку терминалов
	};

	Rule::Rule(GRBALPHABET pnn, int piderror, short psize, Chain c, ...) //конструктор правила
	{															//(нетерминал, идентификатор диагностического сообщения, количество цепочек(правых частей правила), множество цепочек (правых частей правила)
		nn = pnn;    //нетерминал
		iderror = piderror; //идентификатор
		chains = new Chain[size = psize]; //место для цепочки
		Chain*p = &c;
		for (int i = 0; i < size; i++)
			chains[i] = p[i]; //заполняем множество цепочек
	};

	Greibach::Greibach(GRBALPHABET pstartN, GRBALPHABET pstbottom, short psize, Rule r, ...)//конструктор гграматики Грейбаха(стартовый символ, дно стека, количество правил, правила...)
	{
		startN = pstartN; //стартовый символ
		stbottomT = pstbottom;//дно стека
		rules = new Rule[size = psize];//выделяем память
		Rule*p = &r;
		for (int i = 0; i < size; i++) rules[i] = p[i];//заполняем правила
	};
	Greibach getGreibach() { return greibach; }; //получить грамматику

	short Greibach::getRule(GRBALPHABET pnn, Rule& prule) //получить правило (левый символ правила, возвращаемое правило грамматики)
	{
		short rc = -1;
		short k = 0;
		while (k < size&&rules[k].nn != pnn)
			k++;   //пока К меньше количества правил и пока левый символ правила не равен парметру ф-ции
		if (k < size)
			prule = rules[rc = k];    //возвращаемое правило граматики равно правилу с индексом К
		return rc; //возвращается номер правила или -1
	};

	Rule Greibach::getRule(short n) //получить правило по номеру
	{
		Rule rc;      //создаём правило рц
		if (n < size)rc = rules[n];  //присваиваем правилу рц правило н
		return rc; //возвращаем созданное правило
	};

	char*Rule::getCRule(char*b, short nchain) //получить правило в виде N->цепочка (буфер, номер цепочки(правой части) в правиле)
	{
		char bchain[200]; //строка
		b[0] = Chain::alphabet_to_char(nn); b[1] = '-'; b[2] = '>'; b[3] = 0x00; //терминал -> 
		chains[nchain].getCChain(bchain); //получает правую сторонц правила
		strcat_s(b, sizeof(bchain) + 5, bchain);//добавляем строку (куда, с какого элемента, строку)
		return b;
	};

	short Rule::getNextChain(GRBALPHABET t, Rule::Chain& pchain, short j) //получить следующую за j подходящую цепочку, вернуть её номер или -1 
	{                                                                //(первый символ цепочки, возвращаемая цепочка, номер цепочки)
		short rc = -1;
		while (j < size&&chains[j].nt[0] != t)++j;
		rc = (j < size ? j : -1);
		if (rc >= 0)pchain = chains[rc];
		return rc;
	};

	char*Rule::Chain::getCChain(char*b) //получить правую сторону правила
	{
		for (int i = 0; i < size; i++)b[i] = Chain::alphabet_to_char(nt[i]);
		b[size] = 0x00;
		return b;
	};
};