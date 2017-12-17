#pragma once
#define ERROR_THROW(num) ERROR::get(num); //��������� �� ������
#define ERROR_THROW_DETAIL(num, line, pos) ERROR::getDetail(num, line, pos); //��������� �� ������
#define ERROR_THROW_MSG(num, msg) ERROR::getMsg(num, msg); //��������� �� ������
#define SINGLE_ERROR(num, msg) {num, msg, -1, 1} //������� ������

#define MFST_DIAGN_MAXSIZE 100;
#define ERROR_MAXSIZE_MESSAGE 100;
//������ ������
#define FIVE_ERROR(num, msg)	SINGLE_ERROR(num, msg),SINGLE_ERROR(num+1, msg),SINGLE_ERROR(num+2, msg),SINGLE_ERROR(num+3, msg),SINGLE_ERROR(num+4, msg)


namespace ERROR {

	struct error {
		int id;
		char msg[100];
		int line;
		int pos;
	};

	error get(int num);
	error getDetail(int num, int line, int pos);
	error getMsg(int num, char* msg);
};