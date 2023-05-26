%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Contextos */
%x string

/* Patrones reutilizables. */
position	    [1-9]
whitespace		[ \f\n\r\t\v]
float           [0-9]+\.[0-9]+
variableName    [a-zA-Z][a-zA-Z0-9_]*

%%

"image"										{ return ImagePatternAction(yytext); }
"filter"									{ return FilterPatternAction(yytext); }
"set"										{ return SetPatternAction(yytext); }

"for"									    { return ForPatternAction(yytext); }
"in"									    { return InPatternAction(yytext); }

"."                                         { return DotPatternAction(yytext); }
"="											{ return EqualPatternAction(yytext); }
"("											{ return OpenParenthesisPatternAction(yytext); }
")"											{ return CloseParenthesisPatternAction(yytext); }
","											{ return CommaPatternAction(yytext); }
";"											{ return SemiColonPatternAction(yytext); }
"{"											{ return OpenCurlyBracePatternAction(yytext); }
"}"											{ return CloseCurlyBracePatternAction(yytext); }

"apply"										{ return ApplyPatternAction(yytext); }
"overlap"									{ return OverlapPatternAction(yytext); }
"resize"									{ return ResizePatternAction(yytext); }
"trim"				    					{ return TrimPatternAction(yytext); }
"union"										{ return UnionPatternAction(yytext); }
"save"										{ return SavePatternAction(yytext); }
"parameter"									{ return ParameterPatternAction(yytext); }

"width"                                     { return WidthPatternAction(yytext); }
"height"                                    { return HeightPatternAction(yytext); }
"position"                                  { return PositionPatternAction(yytext); }
"axis"                                      { return AxisPatternAction(yytext); }
"format"                                    { return FormatPatternAction(yytext); }
"exposure"                                  { return ExposurePatternAction(yytext); }
"luminosity"                                { return LuminosityPatternAction(yytext); }
"shadows"                                   { return ShadowsPatternAction(yytext); }
"contrast"                                  { return ContrastPatternAction(yytext); }
"brightness"                                { return BrightnessPatternAction(yytext); }
"saturation"                                { return SaturationPatternAction(yytext); }
"opacity"                                   { return OpacityPatternAction(yytext); }

"x"                                         { return XAxisPatternAction(yytext); }
"y"                                         { return YAxisPatternAction(yytext); }

\"                                          { BEGIN(string); }
<string>\"                                  { BEGIN(INITIAL); }
<string>((\\.)|([^\"]))+					{ return StringPatternAction(yytext, yyleng); }

{variableName}								{ return VariableNamePatternAction(yytext, yyleng); }
{float}                                     { return FloatPatternAction(yytext); }
{position}                                  { return IntegerPatternAction(yytext); }

{whitespace}								{ IgnoredPatternAction(yytext); }

\/\/.*                                      { CommentPatternAction(yytext); }

.											{ return UnknownPatternAction(yytext); }

%%
