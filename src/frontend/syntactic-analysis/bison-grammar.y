%{

#include "bison-actions.h"

%}

// Tipos de dato utilizados en las variables semánticas ($$, $1, $2, etc.).
%union {
	// No-terminales (frontend).
	Program program;
	Expression expression;
	Sentence sentence;
	Imagevar imagevar;
	Imagedef imagedef;
	Filtervar filtervar;
	Filterdef filterdef;
	Parametersdef parametersdef;
	Properties properties;
	Setvar setvar;
	Setdef setdef;
	Images images;
	Fordef fordef;
	Block block;
	Functions functions;
	Axises axises;
	Filters filters;
	Positions positions;

	// Terminales.
	token token;
	float floatNum;
	char * string;
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
%token <token> EXPOSURE
%token <token> LUMINOSITY
%token <token> SHADOWS
%token <token> CONTRAST
%token <token> BRIGHTNESS
%token <token> SATURATION
%token <token> OPACITY
%token <token> X
%token <token> Y
%token <token> TOP_LEFT
%token <token> TOP_CENTER
%token <token> TOP_RIGHT
%token <token> CENTER_LEFT
%token <token> CENTER_CENTER
%token <token> CENTER_RIGHT
%token <token> BOTTOM_LEFT
%token <token> BOTTOM_CENTER
%token <token> BOTTOM_RIGHT

%token <string> VAR_NAME
%token <string> STRING

%token <floatNum> FLOAT

// Tipos de dato para los no-terminales generados desde Bison.
%type <program> program
%type <expression> expression
%type <sentence> sentence;
%type <imagevar> imagevar;
%type <imagedef> imagedef;
%type <filtervar> filtervar;
%type <filterdef> filterdef;
%type <parametersdef> parametersdef;
%type <properties> properties;
%type <setvar> setvar;
%type <setdef> setdef;
%type <images> images;
%type <fordef> fordef;
%type <block> block;
%type <functions> functions;
%type <axises> axises;
%type <filters> filters;
%type <positions> positions;

// Reglas de asociatividad y precedencia (de menor a mayor).


// El símbolo inicial de la gramatica.
%start program

%%

program: expression																				{ $$ = ProgramGrammarAction($1); }
	;					

expression: imagedef sentence   																{ $$ = ExpressionImagedefSentenceGrammarAction($1, $2); }
	| filterdef expression																		{ $$ = FilterdefExpressionGrammarAction($1, $2); }
	| setdef expression																			{ $$ = SetdefExpressionGrammarAction($1, $2); }
	| fordef expression																			{ $$ = FordefExpressionGrammarAction($1, $2); }
	| %empty																					{ $$ = LambdaExpressionGrammarAction(); }
	;					

sentence: imagedef sentence 																	{ $$ = ImagedefSenteceGrammarAction($1, $2); }
	| filterdef sentence 																		{ $$ = FilterdefSenteceGrammarAction($1, $2); } 
	| setdef sentence 																			{ $$ = SetdefSentenceGrammarAction($1, $2); } 
	| fordef sentence																			{ $$ = FordefSentenceGrammarAction($1, $2); } 
	| functions sentence																		{ $$ = FunctionsSentenceGrammarAction($1, $2); } 
	| %empty																					{ $$ = LambdaSentenceGrammarAction(); }
	;					

imagevar: IMAGE OPEN_PARENTHESIS STRING CLOSE_PARENTHESIS 										{ $$ = ImagevarParenthesisGrammarAction($3); }
	| VAR_NAME 																					{ $$ = ImagevarVarnameGrammarAction($1); }
	; 

imagedef: IMAGE VAR_NAME EQUAL imagevar SEMI_COLON 												{ $$ = ImagedefGrammarAction($2, $4); }
	;

filtervar: FILTER OPEN_PARENTHESIS STRING CLOSE_PARENTHESIS 									{ $$ = FiltervarParanthesisGrammarAction($3); }
	| FILTER OPEN_PARENTHESIS CLOSE_PARENTHESIS parametersdef 									{ $$ = FiltervarRecursiveGrammarAction($4); }
	| VAR_NAME 																					{ $$ = FilterVarnameGrammarAction($1); }
	;

filterdef: FILTER VAR_NAME EQUAL filtervar SEMI_COLON 											{ $$ = FilterdefGrammarAction($2, $4); }
	;

parametersdef: DOT PARAMETER OPEN_PARENTHESIS properties EQUAL FLOAT CLOSE_PARENTHESIS 			{ $$ = ParametersdefParenthesisGrammarAction($4, $6); }
	| DOT PARAMETER OPEN_PARENTHESIS properties EQUAL FLOAT CLOSE_PARENTHESIS parametersdef 	{ $$ = ParametersdefRecursiveGrammarAction($4, $6, $8); }
	;

properties: EXPOSURE 																			{ $$ = ExposureGrammarAction(); }
	| LUMINOSITY 																				{ $$ = LuminosityGrammarAction(); }
	| SHADOWS 																					{ $$ = ShadowsGrammarAction(); }
	| CONTRAST 																					{ $$ = ContrastGrammarAction(); }
	| BRIGHTNESS 																				{ $$ = BrightnessGrammarAction(); }
	| SATURATION 																				{ $$ = SaturationGrammarAction(); }
	| OPACITY 																					{ $$ = OpacityGrammarAction(); }
	;

setvar: SET OPEN_PARENTHESIS images CLOSE_PARENTHESIS 											{ $$ = SetvarParenthesisGrammarAction($3); }
	| VAR_NAME 																					{ $$ = SetvarVarnameGrammarAction($1); }
	;

setdef: SET VAR_NAME EQUAL setvar SEMI_COLON 													{ $$ = SetdefGrammarAction($2, $4); }
	;

images: imagevar 																				{ $$ = ImagesGrammarAction($1); }
	| imagevar COMMA images 																	{ $$ = ImagesRecursiveGrammarAction($1, $3); }
	;	

fordef: FOR VAR_NAME IN setvar OPEN_CURLY_BRACE block CLOSE_CURLY_BRACE 						{ $$ = FordefGrammarAction($2, $4, $6); }
	;

block: functions 																				{ $$ = BlockGrammarAction($1); }
	| functions block 																			{ $$ = BlockRecursiveGrammarAction($1, $2); }
	;

functions: VAR_NAME DOT APPLY OPEN_PARENTHESIS filters CLOSE_PARENTHESIS SEMI_COLON 																{ $$ = ApplyFiltersGrammarAction($1, $5); }
	| VAR_NAME DOT OVERLAP OPEN_PARENTHESIS	imagevar COMMA POSITION EQUAL positions CLOSE_PARENTHESIS SEMI_COLON 									{ $$ = OverlapImagesGrammarAction($1, $5, $9); }
	| VAR_NAME DOT RESIZE OPEN_PARENTHESIS WIDTH EQUAL FLOAT COMMA HEIGHT EQUAL FLOAT CLOSE_PARENTHESIS SEMI_COLON 									{ $$ = ResizeImageGrammarAction($1, $7, $11); }
	| VAR_NAME DOT UNION OPEN_PARENTHESIS imagevar COMMA AXIS EQUAL axises CLOSE_PARENTHESIS SEMI_COLON 											{ $$ = UnionImagesGrammarAction($1, $5, $9); }	
	| VAR_NAME DOT TRIM OPEN_PARENTHESIS WIDTH EQUAL FLOAT COMMA HEIGHT EQUAL FLOAT COMMA POSITION EQUAL positions CLOSE_PARENTHESIS SEMI_COLON 	{ $$ = TrimImageGrammarAction($1, $7, $11, $15); }
	| VAR_NAME DOT SAVE OPEN_PARENTHESIS CLOSE_PARENTHESIS SEMI_COLON 																				{ $$ = SaveGrammarAction($1); }
	;

axises: X 																						{ $$ = AxisXGrammarAction(); }
	| Y 																						{ $$ = AxisYGrammarAction(); }
	;

filters: filtervar 																				{ $$ = FiltersGrammarAction($1); }
	| filtervar COMMA filters 																	{ $$ = FiltersRecursiveGrammarAction($1, $3); }
	;

positions: TOP_LEFT																				{ $$ = PositionTopLeftGrammarAction(); }
	| TOP_CENTER																				{ $$ = PositionTopCenterGrammarAction(); }
	| TOP_RIGHT																					{ $$ = PositionTopRightGrammarAction(); }
	| CENTER_LEFT																				{ $$ = PositionCenterLeftGrammarAction(); }
	| CENTER_CENTER																				{ $$ = PositionCenterCenterGrammarAction(); }
	| CENTER_RIGHT																				{ $$ = PositionCenterRightGrammarAction(); }
	| BOTTOM_LEFT																				{ $$ = PositionBottomLeftGrammarAction(); }
	| BOTTOM_CENTER																				{ $$ = PositionBottomCenterGrammarAction(); }
	| BOTTOM_RIGHT																				{ $$ = PositionBottomRightGrammarAction(); }
	;

%%
