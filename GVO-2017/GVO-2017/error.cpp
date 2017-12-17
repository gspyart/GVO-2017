#include "error.h"
#include "stdafx.h"

namespace ERROR {

	error error_list[100] = {
		SINGLE_ERROR(0, "���������� ������"),SINGLE_ERROR(1, "������� 0 ����������"),
		SINGLE_ERROR(2, "��������� ����� ������ ���������"),SINGLE_ERROR(3, "epmty"),
		SINGLE_ERROR(4, "�� ������ ����"),
		SINGLE_ERROR(5, "Log file wasn't opened"),SINGLE_ERROR(6, "������������ �������������"),SINGLE_ERROR(7, ""),SINGLE_ERROR(9, ""),SINGLE_ERROR(10, ""),
		SINGLE_ERROR(10, "������������ ������"),
		SINGLE_ERROR(11, "���������� ��������������"),
	


	};

	error get(int id) {
		return error_list[id];
	}
	error getDetail(int id, int line, int pos) {
		error a = error_list[id];
		a.line = line;
		a.pos = pos;
		return a;
	}
	error getMsg(int id, char* msg) {
		error  a = SINGLE_ERROR(6, *msg);
		return a;
	}
};