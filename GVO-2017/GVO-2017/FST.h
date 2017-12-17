#pragma once

#define CHAIN_MAX_SIZE     255     // максимальный размер цепочки
#define FST_COUNT          16      // общее число автоматов
#define LEX_NEW_LINE       '|'



namespace FST
{



	struct RELATION            // ребро : символ -> вершина графа переходов КА
	{
		char symbol;           // символ перехода
		short nnode;           // номер смежной вершины
		RELATION(
			char c = 0x00,              // символ перехода
			short ns = 0x00	            // новое состояние
			);
	};

	struct NODE                // вершина графа переходов
	{
		short n_relation;      // количество инцидентных рёбер
		RELATION * relations;  // инцидентные рёбра
		NODE();
		NODE(
			short n,           // количество инцидентных рёбер
			RELATION rel, ...  // список рёбер
			);
		NODE(int n);
	};

	struct FST                 // недетерминированный КА
	{

		char lexem;            // соотвутствующая автомату лексемаы
		char* string;          // цепочка (строка, завершается 0x00)
		short position;		   // текущая позиция в цепочке
		short nstates;		   // кол-во состояний КА
		NODE* nodes;		   // граф переходов : [0] - начальное состояние, [nstates - 1] - конечное
		short* rstates;	       // возможные состояния КА на позиции

		FST(char a, short ns, NODE n, ...);
	};

	char LexDefining(              // выполнить распознование цепочки
		char* txt              // недетерминированный КА
		);

	char LexDefining(char txt);

	bool step(
		FST& fst,
		short* & rstates
		);

	void restartFST(           // сброс предыдущих значений автомата	
		FST& fst,
	    char* chain
		);

	FST* getFST();             // получить массив автоматов
};