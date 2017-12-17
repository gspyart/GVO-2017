#pragma once
#define LT_MAXSIZE     4096           // максимальное кол-во строк в таблице лексем
#define LT_TI_NULLDIX  0xffffffff     // нет элемента таблицы идентификаторов
#define LEX_MODULE     'm'            // лексема для module
#define LEX_TYPE       't'            // лексема для типа (integer или string)
#define LEX_FUNCTION   'f'            // лексема для function
#define LEX_RETURN     'r'		      // лексема для ,
#define LEX_INTEGER    't'            // лексема для integer
#define LEX_STRING     't'   	      // лексема для string
#define LEX_ID         'i'   	      // лексема для идентификаторов
#define LEX_LITERAL	   'l'  	      // лексема для литерала
#define LEX_END        ';'            // лексема для ;
#define LEX_DOTS       ':'            // лексема для :
#define LEX_PPROCESS   'p'            // лексема для preprocess
#define LEX_COMMA      ','		      // лексема для ,
#define LEX_LEFTBRACE  '{'		      // лексема для {
#define LEX_RIGHTBRACE '}'		      // лексема для }
#define LEX_LEFTHESIS  '('            // лексема для (
#define	LEX_RIGHTHESIS ')'		      // лексема для )
#define LEX_SEPARATOR  '|'            // лексема для сепараторов
#define LEX_OPERATOR   'v'            // лексема для операторов (+, -, *)
#define LEX_EQUAL      'e'            // лексема для =
#define SEPARATOR      '|'
#define ENDNULL        '\0'
#define SPACE          ' '

namespace LexTable{



	struct Entry					  // строка ТЛ
	{
		char lexema;                  // лексема
		int sn;                       // номер строки в исходном тексте
		int idxTI;                    // индекс в таблице идентификаторов или LT_TI_NULLIDX
		char z;
		Entry() {}
		Entry(char l, int s, int i) {
			lexema = l;
			sn = s;
			idxTI = i;
			z = ' ';
		}
	};

	struct LexTable                   // экземпляр ТЛ
	{
		int maxsize;                  // ёмкость таблицы лексем < LT_MAXSIZE
		int size;                     // текущий размер ТЛ < maxsize
		Entry* table;                 // массив строк ТЛ
	};

	LexTable Create(                  // создать ТЛ
		int size                      // ёмкость таблицы лексем < LT_MAXSIZE
	);

	void Add(                         // добавить строку в ТЛ
		LexTable& lextable,           // экземпляр ТЛ
		Entry entry					  // строка ТЛ
	);

	Entry GetEntry(                   // получить строку ТЛ
		LexTable& lextable,			  // экземпляр ТЛ
		int n						  // номер получаемой строки
	);

	void Delete(LexTable& lextable);  // удалить ТЛ (освободить память)


}