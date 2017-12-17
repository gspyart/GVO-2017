#pragma once

#define CHAIN_MAX_SIZE     255     // ������������ ������ �������
#define FST_COUNT          16      // ����� ����� ���������
#define LEX_NEW_LINE       '|'



namespace FST
{



	struct RELATION            // ����� : ������ -> ������� ����� ��������� ��
	{
		char symbol;           // ������ ��������
		short nnode;           // ����� ������� �������
		RELATION(
			char c = 0x00,              // ������ ��������
			short ns = 0x00	            // ����� ���������
			);
	};

	struct NODE                // ������� ����� ���������
	{
		short n_relation;      // ���������� ����������� ����
		RELATION * relations;  // ����������� ����
		NODE();
		NODE(
			short n,           // ���������� ����������� ����
			RELATION rel, ...  // ������ ����
			);
		NODE(int n);
	};

	struct FST                 // ������������������� ��
	{

		char lexem;            // ��������������� �������� ��������
		char* string;          // ������� (������, ����������� 0x00)
		short position;		   // ������� ������� � �������
		short nstates;		   // ���-�� ��������� ��
		NODE* nodes;		   // ���� ��������� : [0] - ��������� ���������, [nstates - 1] - ��������
		short* rstates;	       // ��������� ��������� �� �� �������

		FST(char a, short ns, NODE n, ...);
	};

	char LexDefining(              // ��������� ������������� �������
		char* txt              // ������������������� ��
		);

	char LexDefining(char txt);

	bool step(
		FST& fst,
		short* & rstates
		);

	void restartFST(           // ����� ���������� �������� ��������	
		FST& fst,
	    char* chain
		);

	FST* getFST();             // �������� ������ ���������
};