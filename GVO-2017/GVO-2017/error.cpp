#include "error.h"
#include "stdafx.h"

namespace ERROR {

	error error_list[100] = {
		SINGLE_ERROR(0, "Незвестная ошибка"),SINGLE_ERROR(1, "введено 0 аргументов"),
		SINGLE_ERROR(2, "превышена длина строки параметра"),SINGLE_ERROR(3, "epmty"),
		SINGLE_ERROR(4, "Не найден файл"),
		SINGLE_ERROR(5, "Log file wasn't opened"),SINGLE_ERROR(6, "Недопустимый идентификатор"),SINGLE_ERROR(7, ""),SINGLE_ERROR(9, ""),SINGLE_ERROR(10, ""),
		SINGLE_ERROR(10, "Недопустимый символ"),
		SINGLE_ERROR(11, "Повторение идентификатора"),
	


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