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
	NOP,
	PUSH_NONE,
} OpCode;

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
	/* data */
	CFunction	f;
	float		n;
	char		*s;
	Byte		*b;
	void		*u;
} Value;

typedef struct Object
{
	/* data */
	Type	tag;
	Value	value;
} Object;

typedef struct
{
	/* data */
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
