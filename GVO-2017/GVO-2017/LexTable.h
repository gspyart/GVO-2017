#pragma once
#define LT_MAXSIZE     4096           // ������������ ���-�� ����� � ������� ������
#define LT_TI_NULLDIX  0xffffffff     // ��� �������� ������� ���������������
#define LEX_MODULE     'm'            // ������� ��� module
#define LEX_TYPE       't'            // ������� ��� ���� (integer ��� string)
#define LEX_FUNCTION   'f'            // ������� ��� function
#define LEX_RETURN     'r'		      // ������� ��� ,
#define LEX_INTEGER    't'            // ������� ��� integer
#define LEX_STRING     't'   	      // ������� ��� string
#define LEX_ID         'i'   	      // ������� ��� ���������������
#define LEX_LITERAL	   'l'  	      // ������� ��� ��������
#define LEX_END        ';'            // ������� ��� ;
#define LEX_DOTS       ':'            // ������� ��� :
#define LEX_PPROCESS   'p'            // ������� ��� preprocess
#define LEX_COMMA      ','		      // ������� ��� ,
#define LEX_LEFTBRACE  '{'		      // ������� ��� {
#define LEX_RIGHTBRACE '}'		      // ������� ��� }
#define LEX_LEFTHESIS  '('            // ������� ��� (
#define	LEX_RIGHTHESIS ')'		      // ������� ��� )
#define LEX_SEPARATOR  '|'            // ������� ��� �����������
#define LEX_OPERATOR   'v'            // ������� ��� ���������� (+, -, *)
#define LEX_EQUAL      'e'            // ������� ��� =
#define SEPARATOR      '|'
#define ENDNULL        '\0'
#define SPACE          ' '

namespace LexTable{



	struct Entry					  // ������ ��
	{
		char lexema;                  // �������
		int sn;                       // ����� ������ � �������� ������
		int idxTI;                    // ������ � ������� ��������������� ��� LT_TI_NULLIDX
		char z;
		Entry() {}
		Entry(char l, int s, int i) {
			lexema = l;
			sn = s;
			idxTI = i;
			z = ' ';
		}
	};

	struct LexTable                   // ��������� ��
	{
		int maxsize;                  // ������� ������� ������ < LT_MAXSIZE
		int size;                     // ������� ������ �� < maxsize
		Entry* table;                 // ������ ����� ��
	};

	LexTable Create(                  // ������� ��
		int size                      // ������� ������� ������ < LT_MAXSIZE
	);

	void Add(                         // �������� ������ � ��
		LexTable& lextable,           // ��������� ��
		Entry entry					  // ������ ��
	);

	Entry GetEntry(                   // �������� ������ ��
		LexTable& lextable,			  // ��������� ��
		int n						  // ����� ���������� ������
	);

	void Delete(LexTable& lextable);  // ������� �� (���������� ������)


}