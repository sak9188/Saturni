#include <stdlib.h>
#include <string.h>

#include "opcode.h"

#ifndef MAXSYMBOL
#define MAXSYMBOL 1024
#endif

static Symbol table_buffer[MAXSYMBOL] = {
	{"type", {T_CFUNCTION, {satu_type}},
	{"to_number", {T_CFUNCTION, {satu_obj2number}}},
}