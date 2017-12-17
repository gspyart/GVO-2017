#include "stdafx.h"
#include "FST.h"
#include <vector>
#include "LexTable.h"
std::vector<FST::FST> returnFSTsingle() {

	
	std::vector<FST::FST> AllFST = {

		FST::FST(
			LEX_OPERATOR,
			2,
			FST::NODE(4, FST::RELATION('+', 1), FST::RELATION('-', 1), FST::RELATION('*', 1), FST::RELATION('/', 1)),
			FST::NODE()
		),
		FST::FST(              // автомат #14 (dec)
			LEX_EQUAL,
			2, 							// количество состояний
			FST::NODE(1, FST::RELATION('=', 1)),
			FST::NODE()
		),
		FST::FST(
			SEPARATOR,
			2,
			FST::NODE(1, FST::RELATION('|', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_LEFTHESIS,
			2,
			FST::NODE(1, FST::RELATION('(', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_RIGHTHESIS,
			2,
			FST::NODE(1, FST::RELATION(')', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_LEFTBRACE,
			2,
			FST::NODE(1, FST::RELATION('{', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_RIGHTBRACE,
			2,
			FST::NODE(1, FST::RELATION('}', 1)),
			FST::NODE()
		),

		FST::FST(
			LEX_COMMA,
			2,
			FST::NODE(1, FST::RELATION(',', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_END,
			2,
			FST::NODE(1, FST::RELATION(';', 1)),
			FST::NODE()
		),
		FST::FST(
			LEX_DOTS,
			2,
			FST::NODE(1, FST::RELATION(':', 1)),
			FST::NODE()
		),

	}; //==================================== конец массива
	return AllFST;
}
std::vector<FST::FST> returnFST() {


	std::vector<FST::FST> AllFST={
	 FST::FST(
		LEX_MODULE,
		7, 							// количество состояний
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('o', 2)),
		FST::NODE(1, FST::RELATION('d', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('l', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE()
	),
		FST::FST(
			LEX_PPROCESS,
			11, 							// количество состояний
			FST::NODE(1, FST::RELATION('p', 1)),
			FST::NODE(1, FST::RELATION('r', 2)),
			FST::NODE(1, FST::RELATION('e', 3)),
			FST::NODE(1, FST::RELATION('p', 4)),
			FST::NODE(1, FST::RELATION('r', 5)),
			FST::NODE(1, FST::RELATION('o', 6)),
			FST::NODE(1, FST::RELATION('c', 7)),
			FST::NODE(1, FST::RELATION('e', 8)),
			FST::NODE(1, FST::RELATION('s', 9)),
			FST::NODE(1, FST::RELATION('s', 10)),
			FST::NODE()
		),
	FST::FST(              // автомат #14 (dec)
		LEX_INTEGER,
		8, 							// количество состояний
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE(1, FST::RELATION('g', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE(1, FST::RELATION('r', 7)),
		FST::NODE()
	),

	FST::FST(              // автомат #14 (dec)
		LEX_FUNCTION,
		9, 							// количество состояний
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE(1, FST::RELATION('i', 6)),
		FST::NODE(1, FST::RELATION('o', 7)),
		FST::NODE(1, FST::RELATION('n', 8)),
		FST::NODE()
	),

	FST::FST(              // автомат #14 (dec)
		LEX_RETURN,
		7, 							// количество состояний
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('r', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
	),

	FST::FST(              // автомат #14 (dec)
		LEX_STRING,
		7, 							// количество состояний
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE(1, FST::RELATION('i', 4)),
		FST::NODE(1, FST::RELATION('n', 5)),
		FST::NODE(1, FST::RELATION('g', 6)),
		FST::NODE()
	),


	FST::FST(              // автомат #14 (dec)
		LEX_LITERAL,
		3, 							// количество состояний
		FST::NODE(1, FST::RELATION((char)147, 1)),\
		FST::NODE(149, FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1),\
			FST::RELATION('e', 1), FST::RELATION('f', 1), FST::RELATION('g', 1), FST::RELATION('h', 1),\
			FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),\
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1),\
			FST::RELATION('q', 1), FST::RELATION('r', 1), FST::RELATION('s', 1), FST::RELATION('t', 1),\
			FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),\
			FST::RELATION('y', 1), FST::RELATION('z', 1), \
			FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1),\
			FST::RELATION('E', 1), FST::RELATION('F', 1), FST::RELATION('G', 1), FST::RELATION('H', 1),\
			FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),\
			FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1),\
			FST::RELATION('Q', 1), FST::RELATION('R', 1), FST::RELATION('S', 1), FST::RELATION('T', 1),\
			FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),\
			FST::RELATION('Y', 1), FST::RELATION('Z', 1),\
			FST::RELATION((char)32, 1), FST::RELATION(',', 1), FST::RELATION('.', 1), FST::RELATION(';', 1),\
			FST::RELATION('-', 1), FST::RELATION('+', 1), FST::RELATION('*', 1), FST::RELATION('/', 1),\
			FST::RELATION('=', 1), FST::RELATION(':', 1), FST::RELATION(')', 1), FST::RELATION('(', 1),\
			FST::RELATION('}', 1), FST::RELATION('{', 1), FST::RELATION(']', 1), FST::RELATION('[', 1),\
			FST::RELATION('!', 1), FST::RELATION('?', 1), FST::RELATION('#', 1), FST::RELATION('&', 1),\
			FST::RELATION('1', 1), FST::RELATION('2', 1),\
			FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),\
			FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),\
			FST::RELATION((char)148, 2)),\
		FST::NODE()
	),

		 FST::FST(              // автомат #14 (dec)
			 LEX_LITERAL,
			 3, 							// количество состояний
			 FST::NODE(19, FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
				 FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
				 FST::RELATION('8', 1), FST::RELATION('9', 1), \
				 FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
				 FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), \
				 FST::RELATION('8', 2), FST::RELATION('9', 2)), \
			 FST::NODE(20, FST::RELATION('0', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), \
				 FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), \
				 FST::RELATION('8', 1), FST::RELATION('9', 1), \
				 FST::RELATION('0', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), \
				 FST::RELATION('4', 2), FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), \
				 FST::RELATION('8', 2), FST::RELATION('9', 2)), \
			 FST::NODE()
		 ),



	FST::FST (         // автомат #3 (литарал для numera)
	LEX_LITERAL,
	2, 							// количество состояний
	FST::NODE(                  // состояние №1
		20,                     // инцидентные рёбра
		FST::RELATION('1', 0), FST::RELATION('1', 1), FST::RELATION('2', 0), FST::RELATION('2', 1),
		FST::RELATION('3', 0), FST::RELATION('3', 1), FST::RELATION('4', 0), FST::RELATION('4', 1),
		FST::RELATION('5', 0), FST::RELATION('5', 1), FST::RELATION('6', 0), FST::RELATION('6', 1),
		FST::RELATION('7', 0), FST::RELATION('7', 1), FST::RELATION('8', 0), FST::RELATION('8', 1),
		FST::RELATION('9', 0), FST::RELATION('9', 1), FST::RELATION('0', 0), FST::RELATION('0', 1)),
	FST::NODE()                 // состояние №2 (конечное)
),


FST::FST(         // автомат #2 (индентификатор)
	LEX_ID,
	2, 							// количество состояний
	FST::NODE(                  // состояние №1
		52,                     // инцидентные рёбра
		FST::RELATION('a', 0), FST::RELATION('a', 1), FST::RELATION('b', 0), FST::RELATION('b', 1),
		FST::RELATION('c', 0), FST::RELATION('c', 1), FST::RELATION('d', 0), FST::RELATION('d', 1),
		FST::RELATION('e', 0), FST::RELATION('e', 1), FST::RELATION('f', 0), FST::RELATION('f', 1),
		FST::RELATION('g', 0), FST::RELATION('g', 1), FST::RELATION('h', 0), FST::RELATION('h', 1),
		FST::RELATION('i', 0), FST::RELATION('i', 1), FST::RELATION('j', 0), FST::RELATION('j', 1),
		FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
		FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1),
		FST::RELATION('o', 0), FST::RELATION('o', 1), FST::RELATION('p', 0), FST::RELATION('p', 1),
		FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
		FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1),
		FST::RELATION('u', 0), FST::RELATION('u', 1), FST::RELATION('v', 0), FST::RELATION('v', 1),
		FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
		FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
	FST::NODE()                 // состояние №2 (конечное)
)

};//==================================== конец массива
return AllFST;
}

bool FST::step(FST &fst, short*& rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates); //свапаем основной массив с буферным
	for (int i = 0; i < fst.nstates; i++) // до кол-ва состояний
	{
		if (rstates[i] == fst.position)
			for (int j = 0; j < fst.nodes[i].n_relation; j++) // до кол-ва состояний
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position]) // если символ перехода совпадает с текущим
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1; // записываем  в буферный массив значение
					rc = true;
				};
			};
	};
	return rc;
};

char FST::LexDefining(char* txt) {
		
		
	
	std::vector<FST> dd = returnFST();

		for (int i = 0; i != dd.size(); i++) {
			FST d = dd[i];
		d.string = txt;


		short* rstates = new short[d.nstates]; // создаём буферный массив
		memset(rstates, 0xff, sizeof(short)*d.nstates); //заполняем его -1
		short lstring = strlen(d.string); //определяем длину строки
		bool rc = true;
		for (int i = 0; i < lstring &&rc; i++)
		{
			d.position++;
			rc = step(d, rstates);
		};
		delete[] rstates;
		if (d.rstates[d.nstates - 1] == lstring) { d.position = 0; return d.lexem; }
		}
		
		throw ERROR_THROW(6);

}

char FST::LexDefining(char txt) {



	std::vector<FST> dd = returnFSTsingle();
	
	
	for (int i = 0; i != dd.size(); i++) {
		FST d = dd[i];
		d.string = &txt;


		short* rstates = new short[d.nstates]; // создаём буферный массив
		memset(rstates, 0xff, sizeof(short)*d.nstates); //заполняем его -1
		short lstring = strlen(d.string); //определяем длину строки
		bool rc = true;
		for (int i = 0; i < lstring &&rc; i++)
		{
			d.position++;
			rc = step(d, rstates);
		};
		delete[] rstates;
		if (d.rstates[d.nstates - 1] == lstring) { d.position = 0; return d.lexem; }
	} 
	return CHAR_MIN;

}















FST::RELATION::RELATION(char c, short ns)           // конструктур структуры RELATION
{
	symbol = c; // символ перехода == пришедшему
	nnode = ns; // номер смежной вершины == пришедшей
};

FST::NODE::NODE()                                  // конструктур NODE по умолчанию
{
	n_relation = 0;     // кол-во инцидентных рёбер == 0
	relations = NULL;   // самих инцидентных рёбер пока что нет
};

FST::NODE::NODE(int n)
{
	n_relation = n;
	relations = new RELATION[n_relation];
};

FST::NODE::NODE(short n, RELATION rel, ...)        // констрктор NODE при добавлении рёбер
{
	n_relation = n;                         // кол-во ребёр == пришедшму
	relations = new RELATION[n_relation];   // выделяем память под n рёбер
	RELATION *r = &rel;                     // сохраняем первый пришедший из списка 
	for (short i = 0; i < n_relation; i++)  // прогоняемся по всему массиву
		relations[i] = r[i];                // и записываем рёбра
};

FST::FST::FST(char a,short ns, NODE n, ...)
{
	lexem = a;
	nstates = ns;                 // запоминает кол-во всех возможных состояний
	nodes = new NODE[ns];         // выделяем память для ns NODE структур
	NODE *p = &n;                 // сохраняем пришедшую структуру
	for (short i = 0; i < ns; i++)
		nodes[i] = p[i];
	rstates = new short[nstates]; // выдкляем память для nstates возмоных состояний в вершине
	memset(rstates, -1, sizeof(short)*nstates);  // основной массив алгоритма заполняем -1 (0xff == -1)
	rstates[0] = 0;               // первоначальное возможное состояние == 0
	position = -1;                // первоначальная позиция == -1
};



