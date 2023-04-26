#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>

/**
 * Implementación de "bison-grammar.h".
 */

/**
 * Esta función se ejecuta cada vez que se emite un error de sintaxis.
 */
void yyerror(const char *string)
{
	LogError("Mensaje: '%s' debido a '%s' (linea %d).", string, yytext, yylineno);
	LogError("En ASCII es:");
	LogErrorRaw("\t");
	const int length = strlen(yytext);
	for (int i = 0; i < length; ++i)
	{
		LogErrorRaw("[%d]", yytext[i]);
	}
	LogErrorRaw("\n\n");
}

int ProgramGrammarAction(char *expression)
{
	LogDebug("\tProgramGrammarAction(%s)", expression);
	/*
	 * "state" es una variable global que almacena el estado del compilador,
	 * cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	 * es utilizada en la función "main".
	 */
	state.succeed = true;
	/*
	 * Por otro lado, "result" contiene el resultado de aplicar el análisis
	 * sintáctico mediante Bison, y almacenar el nood raíz del AST construido
	 * en esta variable. Para el ejemplo de la calculadora, no hay AST porque
	 * la expresión se computa on-the-fly, y es la razón por la cual esta
	 * variable es un simple entero, en lugar de un nodo.
	 */
	state.result = 1;
	return true;
}

int ExpressionImagedefSentenceGrammarAction(char *imagedef, char *sentence)
{
	LogDebug("\tExpressionImagedefSentenceGrammarAction(%s, %s)", imagedef, sentence);
	return true;
}

int FilterdefExpressionGrammarAction(char *filterdef, char *expression)
{
	LogDebug("\tFilterdefExpressionGrammarAction(%s, %s)", filterdef, expression);
	return true;
}

int SetdefExpressionGrammarAction(char *setdef, char *expression)
{
	LogDebug("\tSetdefExpressionGrammarAction(%s, %s)", setdef, expression);
	return true;
}

int FordefExpressionGrammarAction(char *fordef, char *expression)
{
	LogDebug("\tFordefExpressionGrammarAction(%s, %s)", fordef, expression);
	return true;
}

int CommentExpressionGrammarAction(char *expression)
{
	LogDebug("\tCommentExpressionGrammarAction(%s)", expression);
	return true;
}

int ImagedefSenteceGrammarAction(char *imagedef, char *sentence)
{
	LogDebug("\tImagedefSenteceGrammarAction(%s, %s)", imagedef, sentence);
	return true;
}

int FilterdefSenteceGrammarAction(char *filterdef, char *sentence)
{
	LogDebug("\tFilterdefSenteceGrammarAction(%s, %s)", filterdef, sentence);
	return true;
}

int SetdefSentenceGrammarAction(char *setdef, char *sentence)
{
	LogDebug("\tSetdefSentenceGrammarAction(%s, %s)", setdef, sentence);
	return true;
}

int FordefSentenceGrammarAction(char *fordef, char *sentence)
{
	LogDebug("\tFordefSentenceGrammarAction(%s, %s)", fordef, sentence);
	return true;
}

int FunctionsSentenceGrammarAction(char *functions, char *sentence)
{
	LogDebug("\tFunctionsSentenceGrammarAction(%s, %s)", functions, sentence);
	return true;
}

int CommentSentenceGrammarAction(char *sentence)
{
	LogDebug("\tCommentSentenceGrammarAction(%s)", sentence);
	return true;
}

int ImagevarParenthesisGrammarAction(char *path)
{
	LogDebug("\tImagevarParenthesisGrammarAction(%s)", path);
	return true;
}

int ImagevarVarnameGrammarAction(char *varname)
{
	LogDebug("\tmagevarVarnameGrammarAction(%s)", varname);
	return true;
}

int ImagedefGrammarAction(char *varname, char *imagevar)
{
	LogDebug("\tImagedefGrammarAction(%s, %s)", varname, imagevar);
	return true;
}

int FiltervarParanthesisGrammarAction(char *filtername)
{
	LogDebug("\tFiltervarParanthesisGrammarAction(%s)", filtername);
	return true;
}

int FiltervarRecursiveGrammarAction(char *parametersdef)
{
	LogDebug("\tFiltervarRecursiveGrammarAction(%s)", parametersdef);
	return true;
}

int FilterVarnameGrammarAction(char *varname)
{
	LogDebug("\tFilterVarnameGrammarAction(%s)", varname);
	return true;
}

int FilterdefGrammarAction(char *varname, char *filtervar)
{
	LogDebug("\tFilterdefGrammarAction(%s, %s)", varname, filtervar);
	return true;
}

int ParametersdefParenthesisGrammarAction(char *property, float value)
{
	LogDebug("\tParametersdefParenthesisGrammarAction(%s, %.2f)", property, value);
	return true;
}

int ParametersdefRecursiveGrammarAction(char *property, float value, char *parametersdef)
{
	LogDebug("\tParametersdefRecursiveGrammarAction(%s, %.2f, %s)", property, value, parametersdef);
	return true;
}

int ExposureGrammarAction()
{
	LogDebug("\tExposureGrammarAction");
	return true;
}

int LuminosityGrammarAction()
{
	LogDebug("\tLuminosityGrammarAction");
	return true;
}

int ShadowsGrammarAction()
{
	LogDebug("\tShadowsGrammarAction");
	return true;
}

int ContrastGrammarAction()
{
	LogDebug("\tContrastGrammarAction");
	return true;
}

int BrightnessGrammarAction()
{
	LogDebug("\tBrightnessGrammarAction");
	return true;
}

int SaturationGrammarAction()
{
	LogDebug("\tSaturationGrammarAction");
	return true;
}

int OpacityGrammarAction()
{
	LogDebug("\tOpacityGrammarAction");
	return true;
}

int SetvarParenthesisGrammarAction(char *images)
{
	LogDebug("\tSetvarParenthesisGrammarAction(%s)", images);
	return true;
}

int SetvarVarnameGrammarAction(char *varname)
{
	LogDebug("\tSetvarVarnameGrammarAction(%s)", varname);
	return true;
}

int SetdefGrammarAction(char *varname, char *setvar)
{
	LogDebug("\tSetdefGrammarAction(%s, %s)", varname, setvar);
	return true;
}

int ImagesGrammarAction(char *imagevar)
{
	LogDebug("\tImagesGrammarAction(%s)", imagevar);
	return true;
}

int ImagesRecursiveGrammarAction(char *imagevar, char *images)
{
	LogDebug("\tImagesRecursiveGrammarAction(%s, %s)", imagevar, images);
	return true;
}

int FordefGrammarAction(char *varname, char *setvar, char *block)
{
	LogDebug("\tFordefGrammarAction(%s, %s, %s)", varname, setvar, block);
	return true;
}

int BlockGrammarAction(char *functions)
{
	LogDebug("\tBlockGrammarAction(%s)", functions);
	return true;
}

int BlockRecursiveGrammarAction(char *functions, char *block)
{
	LogDebug("\tBlockRecursiveGrammarAction(%s, %s)", functions, block);
	return true;
}

int ApplyFiltersGrammarAction(char *varname, char *filters)
{
	LogDebug("\tApplyFiltersGrammarAction(%s, %s)", value, filters);
	return true;
}

int OverlapImagesGrammarAction(char *varname, char *imagevar, int position)
{
	LogDebug("\tOverlapImagesGrammarAction(%s, %s, %d)", varname, imagevar, position);
	return true;
}

int ResizeImageGrammarAction(char *varname, float width, float height)
{
	LogDebug("\tResizeImageGrammarAction(%s, %.2f, %.2f)", varname, width, height);
	return true;
}

int UnionImagesGrammarAction(char *varname, char *imagevar, char *axis)
{
	LogDebug("\tUnionImagesGrammarAction(%s, %s, %s)", varname, imagevar, axis);
	return true;
}

int TrimImageGrammarAction(char *varname, float width, float height, int position)
{
	LogDebug("\tTrimImageGrammarAction(%s, %.2f, %.2f, %d)", varname, width, height, position);
	return true;
}

int SaveFormatGrammarAction(char *varname, char *format)
{
	LogDebug("\tSaveFormatGrammarAction(%s, %s)", varname, format);
	return true;
}

int SaveGrammarAction(char *varname)
{
	LogDebug("\tSaveGrammarAction(%s)", varname);
	return true;
}

int AxisXGrammarAction()
{
	LogDebug("\tAxisXGrammarAction");
	return true;
}

int AxisYGrammarAction()
{
	LogDebug("\tAxisYGrammarAction");
	return true;
}

int FiltersGrammarAction(char *filtervar)
{
	LogDebug("\tFiltersGrammarAction(%s)", filtervar);
	return true;
}

int FiltersRecursiveGrammarAction(char *filtervar, char *filters)
{
	LogDebug("\tFiltersRecursiveGrammarAction(%s)", filtervar, filters);
	return true;
}
