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

int ProgramGrammarAction(int expression)
{
	LogDebug("\tProgramGrammarAction(%d)", expression);
	/*
	 * "state" es una variable global que almacena el estado del compilador,
	 * cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	 * es utilizada en la función "main".
	 */
	state.succeed = true;
	return true;
}

int ExpressionImagedefSentenceGrammarAction(int imagedef, int sentence)
{
	LogDebug("\tExpressionImagedefSentenceGrammarAction(%d, %d)", imagedef, sentence);
	return true;
}

int FilterdefExpressionGrammarAction(int filterdef, int expression)
{
	LogDebug("\tFilterdefExpressionGrammarAction(%d, %d)", filterdef, expression);
	return true;
}

int SetdefExpressionGrammarAction(int setdef, int expression)
{
	LogDebug("\tSetdefExpressionGrammarAction(%d, %d)", setdef, expression);
	return true;
}

int FordefExpressionGrammarAction(int fordef, int expression)
{
	LogDebug("\tFordefExpressionGrammarAction(%d, %d)", fordef, expression);
	return true;
}

int ImagedefSenteceGrammarAction(int imagedef, int sentence)
{
	LogDebug("\tImagedefSenteceGrammarAction(%d, %d)", imagedef, sentence);
	return true;
}

int FilterdefSenteceGrammarAction(int filterdef, int sentence)
{
	LogDebug("\tFilterdefSenteceGrammarAction(%d, %d)", filterdef, sentence);
	return true;
}

int SetdefSentenceGrammarAction(int setdef, int sentence)
{
	LogDebug("\tSetdefSentenceGrammarAction(%d, %d)", setdef, sentence);
	return true;
}

int FordefSentenceGrammarAction(int fordef, int sentence)
{
	LogDebug("\tFordefSentenceGrammarAction(%d, %d)", fordef, sentence);
	return true;
}

int FunctionsSentenceGrammarAction(int functions, int sentence)
{
	LogDebug("\tFunctionsSentenceGrammarAction(%d, %d)", functions, sentence);
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

int ImagedefGrammarAction(char *varname, int imagevar)
{
	LogDebug("\tImagedefGrammarAction(%s, %d)", varname, imagevar);
	return true;
}

int FiltervarParanthesisGrammarAction(char * filtername)
{
	LogDebug("\tFiltervarParanthesisGrammarAction(%s)", filtername);
	return true;
}

int FiltervarRecursiveGrammarAction(int parametersdef)
{
	LogDebug("\tFiltervarRecursiveGrammarAction(%d)", parametersdef);
	return true;
}

int FilterVarnameGrammarAction(char *varname)
{
	LogDebug("\tFilterVarnameGrammarAction(%s)", varname);
	return true;
}

int FilterdefGrammarAction(char *varname, int filtervar)
{
	LogDebug("\tFilterdefGrammarAction(%s, %d)", varname, filtervar);
	return true;
}

int ParametersdefParenthesisGrammarAction(int property, float value)
{
	LogDebug("\tParametersdefParenthesisGrammarAction(%d, %.2f)", property, value);
	return true;
}

int ParametersdefRecursiveGrammarAction(int property, float value, int parametersdef)
{
	LogDebug("\tParametersdefRecursiveGrammarAction(%d, %.2f, %d)", property, value, parametersdef);
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

int SetvarParenthesisGrammarAction(int images)
{
	LogDebug("\tSetvarParenthesisGrammarAction(%d)", images);
	return true;
}

int SetvarVarnameGrammarAction(char * varname)
{
	LogDebug("\tSetvarVarnameGrammarAction(%s)", varname);
	return true;
}

int SetdefGrammarAction(char *varname, int setvar)
{
	LogDebug("\tSetdefGrammarAction(%s, %d)", varname, setvar);
	return true;
}

int ImagesGrammarAction(int imagevar)
{
	LogDebug("\tImagesGrammarAction(%d)", imagevar);
	return true;
}

int ImagesRecursiveGrammarAction(int imagevar, int images)
{
	LogDebug("\tImagesRecursiveGrammarAction(%d, %d)", imagevar, images);
	return true;
}

int FordefGrammarAction(char *varname, int setvar, int block)
{
	LogDebug("\tFordefGrammarAction(%s, %d, %d)", varname, setvar, block);
	return true;
}

int BlockGrammarAction(int functions)
{
	LogDebug("\tBlockGrammarAction(%d)", functions);
	return true;
}

int BlockRecursiveGrammarAction(int functions, int block)
{
	LogDebug("\tBlockRecursiveGrammarAction(%d, %d)", functions, block);
	return true;
}

int ApplyFiltersGrammarAction(char *varname, int filters)
{
	LogDebug("\tApplyFiltersGrammarAction(%s, %d)", varname, filters);
	return true;
}

int OverlapImagesGrammarAction(char *varname, int imagevar, int position)
{
	LogDebug("\tOverlapImagesGrammarAction(%s, %d, %d)", varname, imagevar, position);
	return true;
}

int ResizeImageGrammarAction(char *varname, float width, float height)
{
	LogDebug("\tResizeImageGrammarAction(%s, %.2f, %.2f)", varname, width, height);
	return true;
}

int UnionImagesGrammarAction(char *varname, int imagevar, int axis)
{
	LogDebug("\tUnionImagesGrammarAction(%s, %d, %d)", varname, imagevar, axis);
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

int FiltersGrammarAction(int filtervar)
{
	LogDebug("\tFiltersGrammarAction(%d)", filtervar);
	return true;
}

int FiltersRecursiveGrammarAction(int filtervar, int filters)
{
	LogDebug("\tFiltersRecursiveGrammarAction(%d, %d)", filtervar, filters);
	return true;
}

int PositionTopLeftGrammarAction()
{
	LogDebug("\tPositionTopLeftGrammarAction");
	return true;
}

int PositionTopCenterGrammarAction()
{
	LogDebug("\tPositionTopCenterGrammarAction");
	return true;
}

int PositionTopRightGrammarAction()
{
	LogDebug("\tPositionTopRightGrammarAction");
	return true;
}

int PositionCenterLeftGrammarAction()
{
	LogDebug("\tPositionCenterLeftGrammarAction");
	return true;
}

int PositionCenterCenterGrammarAction()
{
	LogDebug("\tPositionCenterCenterGrammarAction");
	return true;
}

int PositionCenterRightGrammarAction()
{
	LogDebug("\tPositionCenterRightGrammarAction");
	return true;
}

int PositionBottomLeftGrammarAction()
{
	LogDebug("\tPositionBottomLeftGrammarAction");
	return true;
}

int PositionBottomCenterGrammarAction()
{
	LogDebug("\tPositionBottomCenterGrammarAction");
	return true;
}

int PositionBottomRightGrammarAction()
{
	LogDebug("\tPositionBottomRightGrammarAction");
	return true;
}
