%{

#include "bison-actions.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {

	// No-terminales (frontend).
	int program;
	int expression;
	int factor;
	int constant;

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
%type <factor> factor
%type <constant> constant

// Reglas de asociatividad y precedencia (de menor a mayor).
%left ADD SUB
%left MUL DIV

// El símbolo inicial de la gramatica.
%start program

%%

program: expression													{ $$ = ProgramGrammarAction($1); }
	;

expression: expression[left] ADD expression[right]					{ $$ = AdditionExpressionGrammarAction($left, $right); }
	| expression[left] SUB expression[right]						{ $$ = SubtractionExpressionGrammarAction($left, $right); }
	| expression[left] MUL expression[right]						{ $$ = MultiplicationExpressionGrammarAction($left, $right); }
	| expression[left] DIV expression[right]						{ $$ = DivisionExpressionGrammarAction($left, $right); }
	| factor														{ $$ = FactorExpressionGrammarAction($1); }
	;

factor: OPEN_PARENTHESIS expression CLOSE_PARENTHESIS				{ $$ = ExpressionFactorGrammarAction($2); }
	| constant														{ $$ = ConstantFactorGrammarAction($1); }
	;

constant: INTEGER													{ $$ = IntegerConstantGrammarAction($1); }
	;

%%
