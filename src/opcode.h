#ifndef opcode_h
#define opcode_h

#ifndef STACKGAP
#define STACKGAP	128
#endif

typedef unsigned char Byte;
typedef unsigned short Word;

// 这里是定义的指令
typedef enum
{
	// 这个是程序中断
	NOP,

	PUSH_NONE,

	// 把一些常用数字推入栈中
	PUSH_0, PUSH_1, PUSH_2, PUSH_3, PUSH_4, PUSH_5, PUSH_6, PUSH_7,

	// 把一些基础变量推入栈中
	PUSH_BYTE, PUSH_WORD, PUSH_FLOAT, PUSH_STRING, 

	PUSH_LOCAL0, PUSH_LOCAL1, PUSH_LOCAL2, PUSH_LOCAL3,
	PUSH_LOCAL4, PUSH_LOCAL5, PUSH_LOCAL6, PUSH_LOCAL7,
	PUSH_LOCAL8, PUSH_LOCAL9, PUSH_LOCAL10, PUSH_LOCAL11,
	PUSH_LOCAL12, PUSH_LOCAL13, PUSH_LOCAL14, PUSH_LOCAL15,

	STORE_LOCAL0, STORE_LOCAL1, STORE_LOCAL2, STORE_LOCAL3,
	STORE_LOCAL4, STORE_LOCAL5, STORE_LOCAL6, STORE_LOCAL7,
	STORE_LOCAL8, STORE_LOCAL9, STORE_LOCAL10, STORE_LOCAL11,
	STORE_LOCAL12, STORE_LOCAL13, STORE_LOCAL14, STORE_LOCAL15,

	PUSH_GLOBAL, PUSH_INDEX, 
	STORE_GLOBAL, STORE_INDEX,

	PUSH_MARK, PUSH_OBJECT,
	
	STORE_FIELD,
	ADJUST,

	CREAT_DICT,
	CREAT_ARRAY,

	// 等于	
	EQOP,

	// 小于等于
	LTOP,

	// 小于
	LEOP,

	// 加
	ADDOP,
	SUBOP,
	MULTOP,
	DIVOP,
	CONCOP,
	MINUSOP,
	NOTOP,
	JMP,
	POP,
	CALLFUNC,
	HALT,
	SET,
	GET,
	RESET,
} OpCode;

// 自己定义的一些基础类型
typedef enum
{
	T_MARK,
	T_NONE,
	T_NUM,
	T_STRING,
	T_FUNCTION,
	T_CFUNCTION,
	T_ARRAY,
	T_USERDATA,
	T_DICT
} Type;

typedef void (*CFunction) (void);

typedef union
{
	CFunction	f;
	float		n;
	char		*s;
	Byte		*b;
	void		*u;
} Value;

typedef struct Object
{
	Type	tag;
	Value	value;
} Object;

typedef struct
{
	char	*name;
	Object	object;
} Symbol;

#define tag(o)		((o)->tag)
#define nvalue(o)	((o)->value.n)
#define svalue(o)	((o)->value.s)
#define bvalue(o)	((o)->value.b)
#define fvalue(o)	((o)->value.f)
#define uvalue(o)	((o)->value.u)

#define s_name(i)	(sat_dict[i].name)
#define s_object(i)	(sat_dict[i].object)
#define s_tag(i)	(tag(&s_object(i)))
#define s_nvalue(i)	(nvalue(&s_object(i)))
#define s_bvalue(i)	(bvalue(&s_object(i)))
#define s_fvlaue(i)	(fvalue(&s_object(i)))
#define s_uvalue(i)	(uvalue(&s_object(i)))

int		sat_execute		(Byte *pc);
void	sat_mark_stack	(void);
#endif
