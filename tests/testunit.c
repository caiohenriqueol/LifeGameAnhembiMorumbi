#include "testunit.h"

void __msg(char color[10], const char *fmt, va_list args) {
	char *new;
	new = (char *)malloc(1*sizeof(char));
	new = strcat(new, color);
	new = strcat(new, fmt);
	new = strcat(new, RESET);
	vprintf(new , args);
}

void FAIL(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	__msg(RED,fmt, args);
	va_end(args);    
}

void SUCESS(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	__msg(GRN,fmt, args);
	va_end(args);    
}
