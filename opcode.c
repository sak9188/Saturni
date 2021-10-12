#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcode.h"

// 一些快捷函数
int sat_is_number(Object* obj)
{
	return (obj != NULL && tag(obj) == T_NUM);
}

int sat_is_none(Object* obj)
{
	return (obj != NULL && tag(obj) == T_NONE);
}

int sat_is_cfunction(Object* obj)
{
	return (obj != NULL && tag(obj) == T_CFUNCTION);
}

int sat_is_function(Object* obj)
{
	return (obj != NULL && tag(obj) == T_FUNCTION);
}

int sat_is_userdata(Object* obj)
{
	return (obj != NULL && tag(obj) == T_USERDATA);
}

int sat_is_string(Object* obj)
{
	return (obj != NULL && tag(obj) == T_STRING);
}

void sat_type(void)
{
	Object *o = sat_getparam(1);
	sat_push_object(sat_convt2nummber(o));
}

void sat_print(void)
{
	int i = 1;
	void *obj;

	while ((obj=sat_getparam(i++)) != NULL)
	{
		if (sat_is_number(obj))
		{
			printf("%g\n", sat_getnum(obj));
		}else if(sat_is_string(obj))
		{
			print("%s\n", sat_getstring(obj));
		}else if(sat_is_cfunction(obj))
		{
			print("cfunction: ")
		}else if()
		{

		}
		/* code */
	}
	
}