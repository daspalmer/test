#include <stdio.h>
#include <stdarg.h>

int DEBUGLVL = 0;

int dbgtext(const char *format, ...) 
{
	va_list args;
	va_start(args,format);
	vprintf(format,args);
	va_end(args);
};
