#pragma once
#include <iostream>
#include "Greibach.h"
#include "output.h"
#include "LexTable.h"
#include <stack>

#define MFST_DIAGN_MAXSIZE 200
#define MFST_DIAGN_NUMBER 3

typedef std::stack<short> MFSTSTSTACK;	//���� ��������

namespace MFST
{
	struct ParseTree                  // ������ �������
	{
		short* nrule;
		short* nrulechain;
		int    size;

	//	ParseTree();
	//	ParseTree(int psize);
	};

	struct MfstState				//��������� ��������(��� ����������
	{
		short lenta_position;		//������� �� �����
		short nrule;				//����� �������� �������
		short nrulechain;			//����� ������� �������
		MFSTSTSTACK st;				//���� ��������
		MfstState();
		MfstState(
			short pposition,		//������� �� �����
			MFSTSTSTACK pst,		//���� ��������
			short pnrulechain		//����� ������� �������, �������� �������
		);
		MfstState(
			short pposition,		//������� �� �����
			MFSTSTSTACK pst,		//���� ��������
			short pnrule,			//����� �������� �������
			short pnrulechain		//����� ������� �������, �������� �������
		);
	};

	struct Mfst					//���������� �������	
	{
		enum RC_STEP			//��� �������� ������� step
		{
			NS_OK,				//������� ������� � �������, ������� �������� � ����
			NS_NORULE,			//�� ������� ������� ���������� (������ � ����������)
			NS_NORULECHAIN,		//�� ������� ���������� ������� ������� (������ � �������� ����)
			NS_ERROR,			//����������� �������������� ������ ����������
			TS_OK,				//������� ������ ����� == ������� �����, ������������ �����, ��� �����
			TS_NOK,				//������� ������ ����� != ������� �����, ������������� ���������
			LENTA_END,			//������� ������� ����� >= lenta_size
			SURPRISE			//����������� ��� �������� ( ������ � step)
		};
		struct MfstDiagnosis		//�����������
		{
			short lenta_position;	//������� �� �����
			RC_STEP rc_step;		//��� ���������� ����
			short nrule;			//����� �������
			short nrule_chain;		//����� ������� �������
			MfstDiagnosis();
			MfstDiagnosis(			//�����������
				short plenta_position,	//������� �� �����
				RC_STEP prc_step,		//��� ���������� ����
				short pnrule,			//����� �������
				short pnrule_chain		//����� ������� �������
			);
		}
		diagnosis[MFST_DIAGN_NUMBER];	//��������� ����� �������� ���������
		GRBALPHABET* lenta;				//����������������(TS/NS) ����� (�� LEX)
		short lenta_position;			//������� ������� �� �����
		short nrule;					//����� �������� �������
		short nrulechain;				//����� ������� �������, �������� �������
		short lenta_size;				//������ �����
		GRB::Greibach grebach;			//���������� �������
		LexTable::LexTable lex;					//��������� ������ ������������ �����������
		MFSTSTSTACK st;					//���� ��������		
		std::stack<MfstState> storestate;	//���� ��� ���������� ���������
		ParseTree PT;
		Mfst();
		Mfst(
			LexTable::LexTable plex,			//��������� ������ ������������ �����������
			GRB::Greibach pgrebach		//���������� �������
		);
		char* getCSt(char*buf);			//�������� ���������� �����
		char* getCLenta(char* buf, short pos, short n = 25);//�����: n �������� � pos
		char*getDiagnosis(short n, char*buf);			//�������� n-�� ������ ����������� ��� 0�00
		bool savestate(const output::OUTPUT &log);					//��������� ��������� ��������
		bool reststate(const output::OUTPUT &log);					//������������ ��������� ��������
		bool push_chain(					//��������� ������� ������� � ����
			GRB::Rule::Chain chain				//������� �������
		);
		RC_STEP step(const output::OUTPUT &log);			//��������� ��� ��������
		bool start(const output::OUTPUT &log);			//��������� �������
		bool savediagnois(
			RC_STEP pprc_step			//��� ���������� ����
		);
		void printrules(const output::OUTPUT &log);		//������� ������������������ ������
		struct Deducation		//�����
		{
			short size;		//���������� ����� � ������
			short* nrules;	//������ ������ ����������
			short* nrulechains;//������ ������� ������ ���������� (nrules)
			Deducation() { size = 0; nrules = 0; nrulechains = 0; };
		}deducation;
		bool savededucation();	//��������� ������ ������
	
	};
};