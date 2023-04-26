%{

#include "bison-actions.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {

	// No-terminales (frontend).
	int program;
	int expression;
	int sentence;
	int imagevar;
	int imagedef;
	int filtervar;
	int filterdef;
	int parametersdef;
	int property;
	int setvar;
	int setdef;
	int images;
	int fordef;
	int block;
	int functions;
	int axises;
	int filters;

	// Terminales.
	token token;
	float floatNum;
	int integerNum;
}

// IDs y tipos de los tokens terminales generados desde Flex.
%token <token> IMAGE
%token <token> FILTER
%token <token> SET
%token <token> FOR
%token <token> IN
%token <token> DOT
%token <token> EQUAL
%token <token> OPEN_PARENTHESIS
%token <token> CLOSE_PARENTHESIS
%token <token> QUOTE
%token <token> COMMA
%token <token> SEMI_COLON
%token <token> OPEN_CURLY_BRACE
%token <token> CLOSE_CURLY_BRACE
%token <token> APPLY
%token <token> OVERLAP
%token <token> RESIZE
%token <token> TRIM
%token <token> UNION
%token <token> SAVE
%token <token> PARAMETER
%token <token> WIDTH
%token <token> HEIGHT
%token <token> POSITION
%token <token> AXIS
%token <token> FORMAT
%token <token> EXPOSURE
%token <token> LUMINOSITY
%token <token> SHADOWS
%token <token> CONTRAST
%token <token> BRIGHTNESS
%token <token> SATURATION
%token <token> OPACITY
%token <token> X
%token <token> Y
%token <token> VAR_NAME
%token <token> STRING
%token <token> COMMENT

%token <floatNum> FLOAT
%token <integerNum> INTEGER

// Tipos de dato para los no-terminales generados desde Bison.
%type <program> program
%type <expression> expression
%type <sentence> sentence;
%type <imagevar> imagevar;
%type <imagedef> imagedef;
%type <filtervar> filtervar;
%type <filterdef> filterdef;
%type <parametersdef> parametersdef;
%type <property> property;
%type <setvar> setvar;
%type <setdef> setdef;
%type <images> images;
%type <fordef> fordef;
%type <block> block;
%type <functions> functions;
%type <axises> axises;
%type <filters> filters;
// Reglas de asociatividad y precedencia (de menor a mayor).


// El símbolo inicial de la gramatica.
%start program

%%

program: expression													{ $$ = ProgramGrammarAction($1); }
	;

expression: imagedef sentence   									{ $$ = AdditionExpressionGrammarAction($left, $right); }
	| filterdef expression						{ $$ = SubtractionExpressionGrammarAction($left, $right); }
	| setdef expression						{ $$ = MultiplicationExpressionGrammarAction($left, $right); }
	| fordef expression						{ $$ = DivisionExpressionGrammarAction($left, $right); }
	| COMMENT expression {}
	| COMMENT {}
	;

sentence: imagedef sentence {}
	| filterdef sentence {}
	| setdef sentence 		{}
	| fordef sentence		{}
	| functions sentence	{}
	| COMMENT sentence {}
	| COMMENT {}
	;

imagevar: IMAGE OPEN_PARENTHESIS QUOTE STRING QUOTE CLOSE_PARENTHESIS {}
	| VAR_NAME {}
	; 

imagedef: IMAGE VAR_NAME EQUAL imagevar SEMI_COLON {}
	;

filtervar: FILTER OPEN_PARENTHESIS QUOTE STRING QUOTE CLOSE_PARENTHESIS {}
	| FILTER  OPEN_PARENTHESIS CLOSE_PARENTHESIS parametersdef {}
	| VAR_NAME {}
	;

filterdef: FILTER VAR_NAME EQUAL filtervar SEMI_COLON {}
	;

parametersdef: DOT PARAMETER OPEN_PARENTHESIS property EQUAL FLOAT CLOSE_PARENTHESIS {} 
	| DOT PARAMETER OPEN_PARENTHESIS property EQUAL FLOAT CLOSE_PARENTHESIS parametersdef {}
	;

property: EXPOSURE {}
	| LUMINOSITY {}
	| SHADOWS {}
	| CONTRAST {}
	| BRIGHTNESS {}
	| SATURATION {}
	| OPACITY {}
	;

setvar: SET OPEN_PARENTHESIS images CLOSE_PARENTHESIS {}
	| VAR_NAME {}
	;

setdef: SET VAR_NAME EQUAL setvar SEMI_COLON {}
	;

images: imagevar {}
	| imagevar COMMA images {}
	;	

fordef: FOR VAR_NAME IN setvar OPEN_CURLY_BRACE block CLOSE_CURLY_BRACE {}
	;

block: functions {}
	| functions block {}
	;

functions: VAR_NAME DOT APPLY OPEN_PARENTHESIS filters CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT OVERLAP OPEN_PARENTHESIS	imagevar COMMA POSITION EQUAL INTEGER CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT RESIZE OPEN_PARENTHESIS WIDTH EQUAL FLOAT COMMA HEIGHT EQUAL FLOAT CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT UNION OPEN_PARENTHESIS imagevar COMMA AXIS EQUAL axises CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT TRIM OPEN_PARENTHESIS WIDTH EQUAL FLOAT COMMA HEIGHT EQUAL FLOAT COMMA POSITION EQUAL INTEGER CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT SAVE OPEN_PARENTHESIS FORMAT EQUAL QUOTE STRING QUOTE CLOSE_PARENTHESIS SEMI_COLON {}
	| VAR_NAME DOT SAVE OPEN_PARENTHESIS CLOSE_PARENTHESIS SEMI_COLON {}
	;

axises: X {}
	| Y {}
	;

filters: filtervar {}
	| filtervar COMMA filters {}
	;

%%
