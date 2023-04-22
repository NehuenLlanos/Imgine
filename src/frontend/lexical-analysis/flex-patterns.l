%{

#include "flex-actions.h"

%}

/* Obliga a crear una regla explícita para manejar lexemas desconocidos. */
%option nodefault

/* Escanea un único archivo y se detiene. */
%option noyywrap

/* Dispone una variable global "yylineno" con el número de línea actual. */
%option yylineno

/* Patrones reutilizables. */
digit			[0-9]
whitespace		[ \f\n\r\t\v]
float           [0-9]+\.[0-9]+
variableName    [a-zA-Z][a-zA-Z0-9]*
str             .+

%%

"image"										{ return ImagePatternAction(yytext); }
"filter"									{ return FilterPatternAction(yytext); }
"set"										{ return SetPatternAction(yytext); }

"for"									    { return ForPatternAction(yytext, yyleng); }
"in"									    { return InPatternAction(yytext, yyleng); }

"."                                         { return DotPatternAction(yytext); }
"="											{ return EqualPatternAction(yytext); }
"("											{ return OpenParenthesisPatternAction(yytext); }
")"											{ return CloseParenthesisPatternAction(yytext); }
"\""										{ return QuotePatternAction(yytext); }
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

"width"                                     { return WidthPatternAction(yytext, yyleng); }
"height"                                    { return HeightPatternAction(yytext, yyleng); }
"position"                                  { return PositionPatternAction(yytext, yyleng); }
"axis"                                      { return AxisPatternAction(yytext, yyleng); }
"format"                                    { return FormatPatternAction(yytext, yyleng); }
"exposure"                                  { return ExposurePatternAction(yytext, yyleng); }
"luminosity"                                { return LuminosityPatternAction(yytext, yyleng); }
"shadows"                                   { return ShadowsPatternAction(yytext, yyleng); }
"contrast"                                  { return ContrastPatternAction(yytext, yyleng); }
"brightness"                                { return BrightnessPatternAction(yytext, yyleng); }
"saturation"                                { return SaturationPatternAction(yytext, yyleng); }
"opacity"                                   { return OpacityPatternAction(yytext, yyleng); }

{variableName}+								{ return VariableNamePatternAction(yytext, yyleng); }
{str}									    { return StringPatternAction(yytext, yyleng); }
{float}                                     { return FloatPatternAction(yytext, yyleng); }

{whitespace}								{ IgnoredPatternAction(yytext, yyleng); }

\/\/.*                                      { return CommentPatternAction(yytext, yyleng); }

.											{ return UnknownPatternAction(yytext, yyleng); }

%%
