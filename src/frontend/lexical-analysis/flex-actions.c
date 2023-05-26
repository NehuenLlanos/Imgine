#include "../../backend/support/logger.h"
#include "flex-actions.h"
#include <stdlib.h>
#include <string.h>

/**
 * Implementación de "flex-actions.h".
 *
 * Cada función debe realizar 2 operaciones básicas para lograr el streaming
 * de tokens hacia Bison:
 *
 *	1) Computar los atributos del token y almacenarlos donde sea conveniente
 *		(en la tabla de símbolos, en "yylval", o en ambos).
 *	2) Retornar el token que identifica el terminal identificado.
 *
 * Bison utilizará el token retornado en el punto (2) para matchear dicho
 * terminal en la gramática. Por otro lado, el valor almacenado en "yylval" es
 * el que Bison proveerá como valor semántico al realizar una reducción
 * (mediante $1, $2, $3, etc.).
 */

token ImagePatternAction(const char * lexeme) {
	LogDebug("ImagePatternAction: '%s'.", lexeme);
	yylval.token = IMAGE;
	return IMAGE;
}

token FilterPatternAction(const char * lexeme) {
	LogDebug("FilterPatternAction: '%s'.", lexeme);
	yylval.token = FILTER;
	return FILTER;
}

token SetPatternAction(const char * lexeme) {
	LogDebug("SetPatternAction: '%s'.", lexeme);
	yylval.token = SET;
	return SET;
}

token ForPatternAction(const char * lexeme) {
	LogDebug("ForPatternAction: '%s'.", lexeme);
	yylval.token = FOR;
	return FOR;
}

token InPatternAction(const char * lexeme) {
	LogDebug("InPatternAction: '%s'.", lexeme);
	yylval.token = IN;
	return IN;
}

token DotPatternAction(const char * lexeme) {
	LogDebug("DotPatternAction: '%s'.", lexeme);
	yylval.token = DOT;
	return DOT;
}

token EqualPatternAction(const char * lexeme) {
	LogDebug("EqualPatternAction: '%s'.", lexeme);
	yylval.token = EQUAL;
	return EQUAL;
}

token OpenParenthesisPatternAction(const char * lexeme) {
	LogDebug("OpenParenthesisPatternAction: '%s'.", lexeme);
	yylval.token = OPEN_PARENTHESIS;
	return OPEN_PARENTHESIS;
}

token CloseParenthesisPatternAction(const char * lexeme) {
	LogDebug("CloseParenthesisPatternAction: '%s'.", lexeme);
	yylval.token = CLOSE_PARENTHESIS;
	return CLOSE_PARENTHESIS;
}

token CommaPatternAction(const char * lexeme) {
	LogDebug("CommaPatternAction: '%s'.", lexeme);
	yylval.token = COMMA;
	return COMMA;
}

token SemiColonPatternAction(const char * lexeme) {
	LogDebug("SemiColonPatternAction: '%s'.", lexeme);
	yylval.token = SEMI_COLON;
	return SEMI_COLON;
}

token OpenCurlyBracePatternAction(const char * lexeme) {
	LogDebug("OpenCurlyBracePatternAction: '%s'.", lexeme);
	yylval.token = OPEN_CURLY_BRACE;
	return OPEN_CURLY_BRACE;
}

token CloseCurlyBracePatternAction(const char * lexeme) {
	LogDebug("CloseCurlyBracePatternAction: '%s'.", lexeme);
	yylval.token = CLOSE_CURLY_BRACE;
	return CLOSE_CURLY_BRACE;
}

token ApplyPatternAction(const char * lexeme) {
	LogDebug("ApplyPatternAction: '%s'.", lexeme);
	yylval.token = APPLY;
	return APPLY;
}

token OverlapPatternAction(const char * lexeme) {
	LogDebug("OverlapPatternAction: '%s'.", lexeme);
	yylval.token = OVERLAP;
	return OVERLAP;
}

token ResizePatternAction(const char * lexeme) {
	LogDebug("ResizePatternAction: '%s'.", lexeme);
	yylval.token = RESIZE;
	return RESIZE;
}

token TrimPatternAction(const char * lexeme) {
	LogDebug("TrimPatternAction: '%s'.", lexeme);
	yylval.token = TRIM;
	return TRIM;
}

token UnionPatternAction(const char * lexeme) {
	LogDebug("UnionPatternAction: '%s'.", lexeme);
	yylval.token = UNION;
	return UNION;
}

token SavePatternAction(const char * lexeme) {
	LogDebug("SavePatternAction: '%s'.", lexeme);
	yylval.token = SAVE;
	return SAVE;
}

token ParameterPatternAction(const char * lexeme) {
	LogDebug("ParameterPatternAction: '%s'.", lexeme);
	yylval.token = PARAMETER;
	return PARAMETER;
}

token WidthPatternAction(const char * lexeme) {
	LogDebug("WidthPatternAction: '%s'.", lexeme);
	yylval.token = WIDTH;
	return WIDTH;
}

token HeightPatternAction(const char * lexeme) {
	LogDebug("HeightPatternAction: '%s'.", lexeme);
	yylval.token = HEIGHT;
	return HEIGHT;
}

token PositionPatternAction(const char * lexeme) {
	LogDebug("PositionPatternAction: '%s'.", lexeme);
	yylval.token = POSITION;
	return POSITION;
}

token AxisPatternAction(const char * lexeme) {
	LogDebug("AxisPatternAction: '%s'.", lexeme);
	yylval.token = AXIS;
	return AXIS;
}

token FormatPatternAction(const char * lexeme) {
	LogDebug("FormatPatternAction: '%s'.", lexeme);
	yylval.token = FORMAT;
	return FORMAT;
}

token ExposurePatternAction(const char * lexeme) {
	LogDebug("ExposurePatternAction: '%s'.", lexeme);
	yylval.token = EXPOSURE;
	return EXPOSURE;
}

token LuminosityPatternAction(const char * lexeme) {
	LogDebug("LuminosityPatternAction: '%s'.", lexeme);
	yylval.token = LUMINOSITY;
	return LUMINOSITY;
}

token ShadowsPatternAction(const char * lexeme) {
	LogDebug("ShadowsPatternAction: '%s'.", lexeme);
	yylval.token = SHADOWS;
	return SHADOWS;
}

token ContrastPatternAction(const char * lexeme) {
	LogDebug("ContrastPatternAction: '%s'.", lexeme);
	yylval.token = CONTRAST;
	return CONTRAST;
}

token BrightnessPatternAction(const char * lexeme) {
	LogDebug("BrightnessPatternAction: '%s'.", lexeme);
	yylval.token = BRIGHTNESS;
	return BRIGHTNESS;
}

token SaturationPatternAction(const char * lexeme) {
	LogDebug("SaturationPatternAction: '%s'.", lexeme);
	yylval.token = SATURATION;
	return SATURATION;
}

token OpacityPatternAction(const char * lexeme) {
	LogDebug("OpacityPatternAction: '%s'.", lexeme);
	yylval.token = OPACITY;
	return OPACITY;
}

token XAxisPatternAction(const char * lexeme) {
	LogDebug("XAxisPatternAction: '%s'.", lexeme);
	yylval.token = X;
	return X;
}

token YAxisPatternAction(const char * lexeme) {
	LogDebug("YAxisPatternAction: '%s'.", lexeme);
	yylval.token = Y;
	return Y;
}

token VariableNamePatternAction(const char * lexeme, int length) {
	LogDebug("VariableNamePatternAction: '%s'.", lexeme);
	char * str = malloc(length+1);
	strncpy(str, lexeme, length);
	yylval.string = str;
	return VAR_NAME;
}

token StringPatternAction(const char * lexeme, int length) {
	LogDebug("StringPatternAction: '%s'.", lexeme);
	char * str = malloc(length+1);
	strncpy(str, lexeme, length);
	yylval.string = str;
	return STRING;
}

token FloatPatternAction(const char * lexeme) {
	LogDebug("FloatPatternAction: '%s'.", lexeme);
	yylval.floatNum = atof(lexeme);
	return FLOAT;
}

token IntegerPatternAction(const char * lexeme) {
	LogDebug("IntegerPatternAction: '%s'.", lexeme);
	yylval.integerNum = atoi(lexeme);
	return INTEGER;
}

void CommentPatternAction(const char * lexeme) {
	LogDebug("CommentPatternAction: '%s'.", lexeme);
}

token UnknownPatternAction(const char * lexeme) {
	LogDebug("UnknownPatternAction: '%s'.", lexeme);
	yylval.token = YYUNDEF;
	return YYUNDEF;
}

void IgnoredPatternAction(const char * lexeme) {
	LogDebug("IgnoredPatternAction: '%s'.", lexeme);
}
