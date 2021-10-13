#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcode.h"

#ifndef MAXSTACK
#define MAXSTACK 512
#endif

static Object stack[MAXSTACK] = {{T_MARK, {NULL}}};
static Object *top=stack+1, *base=stack+1;

static Object* sat_convt2number(Object* obj)
{
	static Object cvt;

	if(tag(obj) == T_NUM)
	{
		cvt = *obj;
		return &cvt;
	}

	tag(&cvt) == T_NONE;

	if(tag(obj) = T_STRING)
	{
		char *ptr;

		// 
		nvalue(&cvt) = strtod(svalue(obj), &ptr);
		if(*ptr == 0)
		{
			tag(&cvt) = T_NUM;
		}
	}
	
	return &cvt;
}

static Object* sat_convt2string(Object* obj)
{
	static Object cvt;
	// TODO 
}

static sat_execute(Byte* pc)
{
	while(1)
	{
		switch ((OpCode)*pc++)
		{
			case NOP: break;
		
			case PUSH_NONE: tag(top++) = T_NONE; break;

			case PUSH_BYTE: tag(top) = T_NUM; nvalue(top++) = *pc++; break;

			case PUSH_WORD: tag(top) = T_NUM; nvalue(top++) = *((Word*)(pc));
				pc += sizeof(Word);
				break;

			case PUSH_FLOAT: tag(top) = T_NUM; nvalue(top++) = *((float*)(pc));
				pc += sizeof(float);
				break;

			case PUSH_STRING:
			{
				int w = *((Word*)(pc));

				pc += sizeof(Word);

				tag(top) = T_STRING;
				svalue(top++) = sat_constant[w];
			}
			break;
			
			case PUSH_0: tag(top) = T_NUM; nvalue(top++) = 0; break;
			case PUSH_1: tag(top) = T_NUM; nvalue(top++) = 1; break;
			case PUSH_2: tag(top) = T_NUM; nvalue(top++) = 2; break;
			case PUSH_3: tag(top) = T_NUM; nvalue(top++) = 3; break;
			case PUSH_4: tag(top) = T_NUM; nvalue(top++) = 4; break;
			case PUSH_5: tag(top) = T_NUM; nvalue(top++) = 5; break;
			case PUSH_6: tag(top) = T_NUM; nvalue(top++) = 6; break;
			case PUSH_7: tag(top) = T_NUM; nvalue(top++) = 7; break;

			case PUSH_OBJECT: *top = *(top - 3); top++; break;

			case EQOP:
			{
				Object* l = top-2;
				Object* r = top-1;
				--top;

				if(tag(l) != tag(r))
				{
					tag(top-1) = T_NONE;
				}else
				{
					switch (tag(l))
					{
					case T_NONE:
						break;
					
					default:
						break;
					}
				}

			}
			break;

			default:
				break;
		}
	}
}

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
			printf("%s\n", sat_getstring(obj));
		}else if(sat_is_cfunction(obj))
		{
			printf("cfunction: ");
		}else if(sat_is_userdata(obj))
		{
			printf("userdata:");
		}else if(sat_is_table(obj))
		{
			printf("table");
		}else if(sat_is_none(obj))
		{
			printf("None\n");
		}
	}
	
}
