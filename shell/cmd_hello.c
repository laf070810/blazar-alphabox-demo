#include "Blazar_shell.h"

int32_t do_hello(p_shell_context_t context, int32_t argc, char **argv)
{
	char s[] = "hello world!\r\n";
	
	SHELL_SendDataCallback((uint8_t *)s, strlen(s));
	return 0;
}
