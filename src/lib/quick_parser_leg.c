/* A recursive-descent parser generated by peg 0.1.15 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 20
#ifndef YY_MALLOC
#define YY_MALLOC(C, N)		malloc(N)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(C, P, N)	realloc(P, N)
#endif
#ifndef YY_FREE
#define YY_FREE(C, P)		free(P)
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YYRELEASE
#define YYRELEASE	yyrelease
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yy->__begin= yy->__pos, 1)
#endif
#ifndef YY_END
#define YY_END		( yy->__end= yy->__pos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif
#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_SIZE
#define YY_BUFFER_SIZE 1024
#endif

#ifndef YY_PART

typedef struct _yycontext yycontext;
typedef void (*yyaction)(yycontext *yy, char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

struct _yycontext {
  char     *__buf;
  int       __buflen;
  int       __pos;
  int       __limit;
  char     *__text;
  int       __textlen;
  int       __begin;
  int       __end;
  int       __textmax;
  yythunk  *__thunks;
  int       __thunkslen;
  int       __thunkpos;
  YYSTYPE   __;
  YYSTYPE  *__val;
  YYSTYPE  *__vals;
  int       __valslen;
#ifdef YY_CTX_MEMBERS
  YY_CTX_MEMBERS
#endif
};

#ifdef YY_CTX_LOCAL
#define YY_CTX_PARAM_	yycontext *yyctx,
#define YY_CTX_PARAM	yycontext *yyctx
#define YY_CTX_ARG_	yyctx,
#define YY_CTX_ARG	yyctx
#ifndef YY_INPUT
#define YY_INPUT(yy, buf, result, max_size)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#else
#define YY_CTX_PARAM_
#define YY_CTX_PARAM
#define YY_CTX_ARG_
#define YY_CTX_ARG
yycontext _yyctx= { 0, 0 };
yycontext *yyctx= &_yyctx;
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#endif

YY_LOCAL(int) yyrefill(yycontext *yy)
{
  int yyn;
  while (yy->__buflen - yy->__pos < 512)
    {
      yy->__buflen *= 2;
      yy->__buf= (char *)YY_REALLOC(yy, yy->__buf, yy->__buflen);
    }
#ifdef YY_CTX_LOCAL
  YY_INPUT(yy, (yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#else
  YY_INPUT((yy->__buf + yy->__pos), yyn, (yy->__buflen - yy->__pos));
#endif
  if (!yyn) return 0;
  yy->__limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(yycontext *yy)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  ++yy->__pos;
  return 1;
}

YY_LOCAL(int) yymatchChar(yycontext *yy, int c)
{
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  if ((unsigned char)yy->__buf[yy->__pos] == c)
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(yy, %c) @ %s\n", c, yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(int) yymatchString(yycontext *yy, const char *s)
{
  int yysav= yy->__pos;
  while (*s)
    {
      if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
      if (yy->__buf[yy->__pos] != *s)
        {
          yy->__pos= yysav;
          return 0;
        }
      ++s;
      ++yy->__pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(yycontext *yy, unsigned char *bits)
{
  int c;
  if (yy->__pos >= yy->__limit && !yyrefill(yy)) return 0;
  c= (unsigned char)yy->__buf[yy->__pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yy->__pos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yy->__buf+yy->__pos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yy->__buf+yy->__pos));
  return 0;
}

YY_LOCAL(void) yyDo(yycontext *yy, yyaction action, int begin, int end)
{
  while (yy->__thunkpos >= yy->__thunkslen)
    {
      yy->__thunkslen *= 2;
      yy->__thunks= (yythunk *)YY_REALLOC(yy, yy->__thunks, sizeof(yythunk) * yy->__thunkslen);
    }
  yy->__thunks[yy->__thunkpos].begin=  begin;
  yy->__thunks[yy->__thunkpos].end=    end;
  yy->__thunks[yy->__thunkpos].action= action;
  ++yy->__thunkpos;
}

YY_LOCAL(int) yyText(yycontext *yy, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yy->__textlen < (yyleng + 1))
	{
	  yy->__textlen *= 2;
	  yy->__text= (char *)YY_REALLOC(yy, yy->__text, yy->__textlen);
	}
      memcpy(yy->__text, yy->__buf + begin, yyleng);
    }
  yy->__text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(yycontext *yy)
{
  int pos;
  for (pos= 0;  pos < yy->__thunkpos;  ++pos)
    {
      yythunk *thunk= &yy->__thunks[pos];
      int yyleng= thunk->end ? yyText(yy, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yy->__text));
      thunk->action(yy, yy->__text, yyleng);
    }
  yy->__thunkpos= 0;
}

YY_LOCAL(void) yyCommit(yycontext *yy)
{
  if ((yy->__limit -= yy->__pos))
    {
      memmove(yy->__buf, yy->__buf + yy->__pos, yy->__limit);
    }
  yy->__begin -= yy->__pos;
  yy->__end -= yy->__pos;
  yy->__pos= yy->__thunkpos= 0;
}

YY_LOCAL(int) yyAccept(yycontext *yy, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(yy);
      yyCommit(yy);
    }
  return 1;
}

YY_LOCAL(void) yyPush(yycontext *yy, char *text, int count)
{
  yy->__val += count;
  while (yy->__valslen <= yy->__val - yy->__vals)
    {
      long offset= yy->__val - yy->__vals;
      yy->__valslen *= 2;
      yy->__vals= (YYSTYPE *)YY_REALLOC(yy, yy->__vals, sizeof(YYSTYPE) * yy->__valslen);
      yy->__val= yy->__vals + offset;
    }
}
YY_LOCAL(void) yyPop(yycontext *yy, char *text, int count)   { yy->__val -= count; }
YY_LOCAL(void) yySet(yycontext *yy, char *text, int count)   { yy->__val[count]= yy->__; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yy, yythunkpos0)

YY_RULE(int) yy__line_start_(yycontext *yy); /* 20 */
YY_RULE(int) yy_line_comment(yycontext *yy); /* 19 */
YY_RULE(int) yy_HWS(yycontext *yy); /* 18 */
YY_RULE(int) yy_WS(yycontext *yy); /* 17 */
YY_RULE(int) yy_EOL(yycontext *yy); /* 16 */
YY_RULE(int) yy_double_quoted(yycontext *yy); /* 15 */
YY_RULE(int) yy_single_quoted(yycontext *yy); /* 14 */
YY_RULE(int) yy_comment(yycontext *yy); /* 13 */
YY_RULE(int) yy_EOF(yycontext *yy); /* 12 */
YY_RULE(int) yy_statement_body(yycontext *yy); /* 11 */
YY_RULE(int) yy_quoted(yycontext *yy); /* 10 */
YY_RULE(int) yy_block_comment(yycontext *yy); /* 9 */
YY_RULE(int) yy_escaped_char(yycontext *yy); /* 8 */
YY_RULE(int) yy_line_end(yycontext *yy); /* 7 */
YY_RULE(int) yy___(yycontext *yy); /* 6 */
YY_RULE(int) yy_command_body(yycontext *yy); /* 5 */
YY_RULE(int) yy__(yycontext *yy); /* 4 */
YY_RULE(int) yy_statement(yycontext *yy); /* 3 */
YY_RULE(int) yy_client_command(yycontext *yy); /* 2 */
YY_RULE(int) yy_directive(yycontext *yy); /* 1 */

YY_ACTION(void) yy_1_EOF(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_EOF\n"));
  {
   yy->eof = true; ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_statement(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_statement\n"));
  {
   segment(true, yy); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}
YY_ACTION(void) yy_1_client_command(yycontext *yy, char *yytext, int yyleng)
{
#define __ yy->__
#define yypos yy->__pos
#define yythunkpos yy->__thunkpos
  yyprintf((stderr, "do yy_1_client_command\n"));
  {
   segment(false, yy); ;
  }
#undef yythunkpos
#undef yypos
#undef yy
}

YY_RULE(int) yy__line_start_(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "_line_start_"));  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!( (line_start(yy), 1) )) goto l1;
#undef yytext
#undef yyleng
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_line_start_", yy->__buf+yy->__pos));
  return 1;
  l1:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "_line_start_", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_line_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "line_comment"));  if (!yymatchString(yy, "//")) goto l2;
  l3:;	
  {  int yypos4= yy->__pos, yythunkpos4= yy->__thunkpos;
  {  int yypos5= yy->__pos, yythunkpos5= yy->__thunkpos;  if (!yy_EOL(yy)) goto l5;  goto l4;
  l5:;	  yy->__pos= yypos5; yy->__thunkpos= yythunkpos5;
  }  if (!yymatchDot(yy)) goto l4;  goto l3;
  l4:;	  yy->__pos= yypos4; yy->__thunkpos= yythunkpos4;
  }
  {  int yypos6= yy->__pos, yythunkpos6= yy->__thunkpos;  if (!yy_EOL(yy)) goto l7;  goto l6;
  l7:;	  yy->__pos= yypos6; yy->__thunkpos= yythunkpos6;  if (!yy_EOF(yy)) goto l2;
  }
  l6:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "line_comment", yy->__buf+yy->__pos));
  return 1;
  l2:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "line_comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_HWS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "HWS"));  if (!yymatchClass(yy, (unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l8;
  yyprintf((stderr, "  ok   %s @ %s\n", "HWS", yy->__buf+yy->__pos));
  return 1;
  l8:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "HWS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_WS(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "WS"));
  {  int yypos10= yy->__pos, yythunkpos10= yy->__thunkpos;  if (!yy_HWS(yy)) goto l11;  goto l10;
  l11:;	  yy->__pos= yypos10; yy->__thunkpos= yythunkpos10;  if (!yy_EOL(yy)) goto l9;
  }
  l10:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "WS", yy->__buf+yy->__pos));
  return 1;
  l9:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "WS", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EOL(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EOL"));
  {  int yypos13= yy->__pos, yythunkpos13= yy->__thunkpos;  if (!yymatchChar(yy, '\n')) goto l14;  goto l13;
  l14:;	  yy->__pos= yypos13; yy->__thunkpos= yythunkpos13;  if (!yymatchString(yy, "\r\n")) goto l12;
  }
  l13:;	  if (!yy__line_start_(yy)) goto l12;
  yyprintf((stderr, "  ok   %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 1;
  l12:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOL", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_double_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "double_quoted"));  if (!yymatchChar(yy, '"')) goto l15;
  l16:;	
  {  int yypos17= yy->__pos, yythunkpos17= yy->__thunkpos;
  {  int yypos18= yy->__pos, yythunkpos18= yy->__thunkpos;  if (!yy_escaped_char(yy)) goto l19;  goto l18;
  l19:;	  yy->__pos= yypos18; yy->__thunkpos= yythunkpos18;  if (!yy_EOL(yy)) goto l20;  goto l18;
  l20:;	  yy->__pos= yypos18; yy->__thunkpos= yythunkpos18;
  {  int yypos21= yy->__pos, yythunkpos21= yy->__thunkpos;  if (!yymatchChar(yy, '"')) goto l21;  goto l17;
  l21:;	  yy->__pos= yypos21; yy->__thunkpos= yythunkpos21;
  }  if (!yymatchDot(yy)) goto l17;
  }
  l18:;	  goto l16;
  l17:;	  yy->__pos= yypos17; yy->__thunkpos= yythunkpos17;
  }  if (!yymatchChar(yy, '"')) goto l15;
  yyprintf((stderr, "  ok   %s @ %s\n", "double_quoted", yy->__buf+yy->__pos));
  return 1;
  l15:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "double_quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_single_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "single_quoted"));  if (!yymatchChar(yy, '\'')) goto l22;
  l23:;	
  {  int yypos24= yy->__pos, yythunkpos24= yy->__thunkpos;
  {  int yypos25= yy->__pos, yythunkpos25= yy->__thunkpos;  if (!yy_escaped_char(yy)) goto l26;  goto l25;
  l26:;	  yy->__pos= yypos25; yy->__thunkpos= yythunkpos25;  if (!yy_EOL(yy)) goto l27;  goto l25;
  l27:;	  yy->__pos= yypos25; yy->__thunkpos= yythunkpos25;
  {  int yypos28= yy->__pos, yythunkpos28= yy->__thunkpos;  if (!yymatchChar(yy, '\'')) goto l28;  goto l24;
  l28:;	  yy->__pos= yypos28; yy->__thunkpos= yythunkpos28;
  }  if (!yymatchDot(yy)) goto l24;
  }
  l25:;	  goto l23;
  l24:;	  yy->__pos= yypos24; yy->__thunkpos= yythunkpos24;
  }  if (!yymatchChar(yy, '\'')) goto l22;
  yyprintf((stderr, "  ok   %s @ %s\n", "single_quoted", yy->__buf+yy->__pos));
  return 1;
  l22:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "single_quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "comment"));
  {  int yypos30= yy->__pos, yythunkpos30= yy->__thunkpos;  if (!yy_line_comment(yy)) goto l31;  goto l30;
  l31:;	  yy->__pos= yypos30; yy->__thunkpos= yythunkpos30;  if (!yy_block_comment(yy)) goto l29;
  }
  l30:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 1;
  l29:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_EOF(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "EOF"));
  {  int yypos33= yy->__pos, yythunkpos33= yy->__thunkpos;  if (!yymatchDot(yy)) goto l33;  goto l32;
  l33:;	  yy->__pos= yypos33; yy->__thunkpos= yythunkpos33;
  }  yyDo(yy, yy_1_EOF, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "EOF", yy->__buf+yy->__pos));
  return 1;
  l32:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "EOF", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_statement_body(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "statement_body"));
  l35:;	
  {  int yypos36= yy->__pos, yythunkpos36= yy->__thunkpos;
  {  int yypos37= yy->__pos, yythunkpos37= yy->__thunkpos;  if (!yy_comment(yy)) goto l38;  goto l37;
  l38:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;  if (!yy_quoted(yy)) goto l39;  goto l37;
  l39:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;  if (!yy_escaped_char(yy)) goto l40;  goto l37;
  l40:;	  yy->__pos= yypos37; yy->__thunkpos= yythunkpos37;
  {  int yypos41= yy->__pos, yythunkpos41= yy->__thunkpos;  if (!yy__(yy)) goto l41;  if (!yymatchChar(yy, ';')) goto l41;  goto l36;
  l41:;	  yy->__pos= yypos41; yy->__thunkpos= yythunkpos41;
  }  if (!yymatchDot(yy)) goto l36;
  }
  l37:;	  goto l35;
  l36:;	  yy->__pos= yypos36; yy->__thunkpos= yythunkpos36;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "statement_body", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_quoted(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "quoted"));
  {  int yypos43= yy->__pos, yythunkpos43= yy->__thunkpos;  if (!yy_single_quoted(yy)) goto l44;  goto l43;
  l44:;	  yy->__pos= yypos43; yy->__thunkpos= yythunkpos43;  if (!yy_double_quoted(yy)) goto l42;
  }
  l43:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "quoted", yy->__buf+yy->__pos));
  return 1;
  l42:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "quoted", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_block_comment(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "block_comment"));  if (!yymatchString(yy, "/*")) goto l45;
  l46:;	
  {  int yypos47= yy->__pos, yythunkpos47= yy->__thunkpos;
  {  int yypos48= yy->__pos, yythunkpos48= yy->__thunkpos;  if (!yy_EOL(yy)) goto l49;  goto l48;
  l49:;	  yy->__pos= yypos48; yy->__thunkpos= yythunkpos48;
  {  int yypos50= yy->__pos, yythunkpos50= yy->__thunkpos;  if (!yymatchString(yy, "*/")) goto l50;  goto l47;
  l50:;	  yy->__pos= yypos50; yy->__thunkpos= yythunkpos50;
  }  if (!yymatchDot(yy)) goto l47;
  }
  l48:;	  goto l46;
  l47:;	  yy->__pos= yypos47; yy->__thunkpos= yythunkpos47;
  }  if (!yymatchString(yy, "*/")) goto l45;
  yyprintf((stderr, "  ok   %s @ %s\n", "block_comment", yy->__buf+yy->__pos));
  return 1;
  l45:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "block_comment", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_escaped_char(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "escaped_char"));  if (!yymatchChar(yy, '\\')) goto l51;  if (!yymatchClass(yy, (unsigned char *)"\000\000\000\000\204\000\000\200\000\000\000\020\106\100\124\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l51;
  yyprintf((stderr, "  ok   %s @ %s\n", "escaped_char", yy->__buf+yy->__pos));
  return 1;
  l51:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "escaped_char", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_line_end(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "line_end"));
  {  int yypos53= yy->__pos, yythunkpos53= yy->__thunkpos;  if (!yy_line_comment(yy)) goto l54;  goto l53;
  l54:;	  yy->__pos= yypos53; yy->__thunkpos= yythunkpos53;  if (!yy_EOL(yy)) goto l55;  goto l53;
  l55:;	  yy->__pos= yypos53; yy->__thunkpos= yythunkpos53;  if (!yy_EOF(yy)) goto l52;
  }
  l53:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "line_end", yy->__buf+yy->__pos));
  return 1;
  l52:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "line_end", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy___(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "__"));
  l57:;	
  {  int yypos58= yy->__pos, yythunkpos58= yy->__thunkpos;
  {  int yypos59= yy->__pos, yythunkpos59= yy->__thunkpos;  if (!yy_HWS(yy)) goto l60;  goto l59;
  l60:;	  yy->__pos= yypos59; yy->__thunkpos= yythunkpos59;  if (!yy_block_comment(yy)) goto l58;
  }
  l59:;	  goto l57;
  l58:;	  yy->__pos= yypos58; yy->__thunkpos= yythunkpos58;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "__", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_command_body(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "command_body"));
  l62:;	
  {  int yypos63= yy->__pos, yythunkpos63= yy->__thunkpos;
  {  int yypos64= yy->__pos, yythunkpos64= yy->__thunkpos;  if (!yy_escaped_char(yy)) goto l65;  goto l64;
  l65:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;  if (!yymatchString(yy, "\\;")) goto l66;  goto l64;
  l66:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;  if (!yymatchChar(yy, '\\')) goto l67;  if (!yy___(yy)) goto l67;  if (!yy_line_end(yy)) goto l67;  goto l64;
  l67:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;  if (!yy_block_comment(yy)) goto l68;  goto l64;
  l68:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;  if (!yy_quoted(yy)) goto l69;  goto l64;
  l69:;	  yy->__pos= yypos64; yy->__thunkpos= yythunkpos64;
  {  int yypos70= yy->__pos, yythunkpos70= yy->__thunkpos;
  {  int yypos71= yy->__pos, yythunkpos71= yy->__thunkpos;  if (!yymatchChar(yy, ';')) goto l72;  goto l71;
  l72:;	  yy->__pos= yypos71; yy->__thunkpos= yythunkpos71;  if (!yy___(yy)) goto l70;  if (!yy_line_end(yy)) goto l70;
  }
  l71:;	  goto l63;
  l70:;	  yy->__pos= yypos70; yy->__thunkpos= yythunkpos70;
  }  if (!yymatchDot(yy)) goto l63;
  }
  l64:;	  goto l62;
  l63:;	  yy->__pos= yypos63; yy->__thunkpos= yythunkpos63;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "command_body", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy__(yycontext *yy)
{
  yyprintf((stderr, "%s\n", "_"));
  l74:;	
  {  int yypos75= yy->__pos, yythunkpos75= yy->__thunkpos;
  {  int yypos76= yy->__pos, yythunkpos76= yy->__thunkpos;  if (!yy_WS(yy)) goto l77;  goto l76;
  l77:;	  yy->__pos= yypos76; yy->__thunkpos= yythunkpos76;  if (!yy_comment(yy)) goto l75;
  }
  l76:;	  goto l74;
  l75:;	  yy->__pos= yypos75; yy->__thunkpos= yythunkpos75;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yy->__buf+yy->__pos));
  return 1;
}
YY_RULE(int) yy_statement(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "statement"));  if (!yy__(yy)) goto l78;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l78;
#undef yytext
#undef yyleng
  }  if (!yy_statement_body(yy)) goto l78;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l78;
#undef yytext
#undef yyleng
  }  if (!yy__(yy)) goto l78;
  {  int yypos79= yy->__pos, yythunkpos79= yy->__thunkpos;  if (!yymatchChar(yy, ';')) goto l80;  goto l79;
  l80:;	  yy->__pos= yypos79; yy->__thunkpos= yythunkpos79;  if (!yy_EOF(yy)) goto l78;
  }
  l79:;	  yyDo(yy, yy_1_statement, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "statement", yy->__buf+yy->__pos));
  return 1;
  l78:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "statement", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_client_command(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "client_command"));  if (!yy__(yy)) goto l81;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_BEGIN)) goto l81;
#undef yytext
#undef yyleng
  }  if (!yymatchChar(yy, ':')) goto l81;  if (!yy_command_body(yy)) goto l81;  yyText(yy, yy->__begin, yy->__end);  {
#define yytext yy->__text
#define yyleng yy->__textlen
if (!(YY_END)) goto l81;
#undef yytext
#undef yyleng
  }  if (!yy___(yy)) goto l81;
  {  int yypos82= yy->__pos, yythunkpos82= yy->__thunkpos;  if (!yymatchChar(yy, ';')) goto l83;  goto l82;
  l83:;	  yy->__pos= yypos82; yy->__thunkpos= yythunkpos82;  if (!yy_line_end(yy)) goto l81;
  }
  l82:;	  yyDo(yy, yy_1_client_command, yy->__begin, yy->__end);
  yyprintf((stderr, "  ok   %s @ %s\n", "client_command", yy->__buf+yy->__pos));
  return 1;
  l81:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "client_command", yy->__buf+yy->__pos));
  return 0;
}
YY_RULE(int) yy_directive(yycontext *yy)
{  int yypos0= yy->__pos, yythunkpos0= yy->__thunkpos;
  yyprintf((stderr, "%s\n", "directive"));
  {  int yypos85= yy->__pos, yythunkpos85= yy->__thunkpos;  if (!yy_client_command(yy)) goto l86;  goto l85;
  l86:;	  yy->__pos= yypos85; yy->__thunkpos= yythunkpos85;  if (!yy_statement(yy)) goto l84;
  }
  l85:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "directive", yy->__buf+yy->__pos));
  return 1;
  l84:;	  yy->__pos= yypos0; yy->__thunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "directive", yy->__buf+yy->__pos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(yycontext *yy);

YY_PARSE(int) YYPARSEFROM(YY_CTX_PARAM_ yyrule yystart)
{
  int yyok;
  if (!yyctx->__buflen)
    {
      yyctx->__buflen= YY_BUFFER_SIZE;
      yyctx->__buf= (char *)YY_MALLOC(yyctx, yyctx->__buflen);
      yyctx->__textlen= YY_BUFFER_SIZE;
      yyctx->__text= (char *)YY_MALLOC(yyctx, yyctx->__textlen);
      yyctx->__thunkslen= YY_STACK_SIZE;
      yyctx->__thunks= (yythunk *)YY_MALLOC(yyctx, sizeof(yythunk) * yyctx->__thunkslen);
      yyctx->__valslen= YY_STACK_SIZE;
      yyctx->__vals= (YYSTYPE *)YY_MALLOC(yyctx, sizeof(YYSTYPE) * yyctx->__valslen);
      yyctx->__begin= yyctx->__end= yyctx->__pos= yyctx->__limit= yyctx->__thunkpos= 0;
    }
  yyctx->__begin= yyctx->__end= yyctx->__pos;
  yyctx->__thunkpos= 0;
  yyctx->__val= yyctx->__vals;
  yyok= yystart(yyctx);
  if (yyok) yyDone(yyctx);
  yyCommit(yyctx);
  return yyok;
}

YY_PARSE(int) YYPARSE(YY_CTX_PARAM)
{
  return YYPARSEFROM(YY_CTX_ARG_ yy_directive);
}

YY_PARSE(yycontext *) YYRELEASE(yycontext *yyctx)
{
  if (yyctx->__buflen)
    {
      yyctx->__buflen= 0;
      YY_FREE(yyctx, yyctx->__buf);
      YY_FREE(yyctx, yyctx->__text);
      YY_FREE(yyctx, yyctx->__thunks);
      YY_FREE(yyctx, yyctx->__vals);
    }
  return yyctx;
}

#endif