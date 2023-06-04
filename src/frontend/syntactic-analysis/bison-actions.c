#include "../../backend/domain-specific/calculator.h"
#include "../../backend/support/logger.h"
#include "../../backend/support/garbage-collector.h"
#include "bison-actions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Implementación de "bison-grammar.h".
 */

/**
 * Esta función se ejecuta cada vez que se emite un error de sintaxis.
 */
void yyerror(const char * string) {
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

Program ProgramGrammarAction(Expression expression) {
	LogDebug("\tProgramGrammarAction(%p)", expression);

	Program program = Malloc(sizeof(struct ProgramNode));
	program->expression = expression;

	/*
	 * "state" es una variable global que almacena el estado del compilador,
	 * cuyo campo "succeed" indica si la compilación fue o no exitosa, la cual
	 * es utilizada en la función "main".
	 */
	state.succeed = true;
	state.program = program;

	return program;
}

Expression ExpressionImagedefSentenceGrammarAction(Imagedef imagedef, Sentence sentence) {
	LogDebug("\tExpressionImagedefSentenceGrammarAction(%p, %p)", imagedef, sentence);

	Expression new_guy = Malloc(sizeof(struct ExpressionNode));
	new_guy->type = EXPRESSIONTYPE_IMAGEDEF;
	new_guy->imagedef = imagedef;
	new_guy->sentence = sentence;

	return new_guy;
}

Expression FilterdefExpressionGrammarAction(Filterdef filterdef, Expression expression) {
	LogDebug("\tFilterdefExpressionGrammarAction(%p, %p)", filterdef, expression);

	Expression new_guy = Malloc(sizeof(struct ExpressionNode));
	new_guy->type = EXPRESSIONTYPE_FILTERDEF;
	new_guy->filterdef = filterdef;
	new_guy->expression = expression;

	return new_guy;
}

Expression SetdefExpressionGrammarAction(Setdef setdef, Expression expression) {
	LogDebug("\tSetdefExpressionGrammarAction(%p, %p)", setdef, expression);

	Expression new_guy = Malloc(sizeof(struct ExpressionNode));
	new_guy->type = EXPRESSIONTYPE_SETDEF;
	new_guy->setdef = setdef;
	new_guy->expression = expression;

	return new_guy;
}

Expression FordefExpressionGrammarAction(Fordef fordef, Expression expression) {
	LogDebug("\tFordefExpressionGrammarAction(%p, %p)", fordef, expression);

	Expression new_guy = Malloc(sizeof(struct ExpressionNode));
	new_guy->type = EXPRESSIONTYPE_FORDEF;
	new_guy->fordef = fordef;
	new_guy->expression = expression;

	return new_guy;
}

Expression LambdaExpressionGrammarAction() {
	LogDebug("\tLambdaExpressionGrammarAction");

	Expression new_guy = Malloc(sizeof(struct ExpressionNode));
	new_guy->type = EXPRESSIONTYPE_LAMBDA;

	return new_guy;
}

Sentence ImagedefSenteceGrammarAction(Imagedef imagedef, Sentence sentence) {
	LogDebug("\tImagedefSenteceGrammarAction(%p, %p)", imagedef, sentence);

	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_IMAGEDEF;
	new_guy->imagedef = imagedef;
	new_guy->sentence = sentence;

	return new_guy;
}

Sentence FilterdefSenteceGrammarAction(Filterdef filterdef, Sentence sentence) {
	LogDebug("\tFilterdefSenteceGrammarAction(%p, %p)", filterdef, sentence);
	
	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_FILTERDEF;
	new_guy->filterdef = filterdef;
	new_guy->sentence = sentence;

	return new_guy;
}

Sentence SetdefSentenceGrammarAction(Setdef setdef, Sentence sentence) {
	LogDebug("\tSetdefSentenceGrammarAction(%p, %p)", setdef, sentence);
	
	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_SETDEF;
	new_guy->setdef = setdef;
	new_guy->sentence = sentence;

	return new_guy;}

Sentence FordefSentenceGrammarAction(Fordef fordef, Sentence sentence) {
	LogDebug("\tFordefSentenceGrammarAction(%p, %p)", fordef, sentence);
	
	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_FORDEF;
	new_guy->fordef = fordef;
	new_guy->sentence = sentence;

	return new_guy;
}

Sentence FunctionsSentenceGrammarAction(Functions functions, Sentence sentence) {
	LogDebug("\tFunctionsSentenceGrammarAction(%p, %p)", functions, sentence);
	
	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_FUNCTIONS;
	new_guy->functions = functions;
	new_guy->sentence = sentence;

	return new_guy;
}

Sentence LambdaSentenceGrammarAction() {
	LogDebug("\tLambdaSentenceGrammarAction");

	Sentence new_guy = Malloc(sizeof(struct SentenceNode));
	new_guy->type = SENTENCETYPE_LAMBDA;

	return new_guy;
}

Imagevar ImagevarParenthesisGrammarAction(char * path) {
	LogDebug("\tImagevarParenthesisGrammarAction(%s)", path);
	
	Imagevar new_guy = Malloc(sizeof(struct ImagevarNode));
	new_guy->type = IMAGEVARTYPE_PATH;
	new_guy->path = path;

	return new_guy;
}

Imagevar ImagevarVarnameGrammarAction(char * varname) {
	LogDebug("\tmagevarVarnameGrammarAction(%s)", varname);

	Imagevar new_guy = Malloc(sizeof(struct ImagevarNode));
	new_guy->type = IMAGEVARTYPE_VAR_NAME;
	new_guy->var_name = varname;

	return new_guy;
}

Imagedef ImagedefGrammarAction(char * varname, Imagevar imagevar) {
	LogDebug("\tImagedefGrammarAction(%s, %p)", varname, imagevar);

	Imagedef new_guy = Malloc(sizeof(struct ImagedefNode));
	new_guy->var_name = varname;
	new_guy->imagevar = imagevar;

	return new_guy;
}

Filtervar FiltervarParanthesisGrammarAction(char * filtername) {
	LogDebug("\tFiltervarParanthesisGrammarAction(%s)", filtername);

	Filtervar new_guy = Malloc(sizeof(struct FiltervarNode));
	new_guy->type = FILTERVARTYPE_FILTER_NAME;
	new_guy->filter_name = filtername;

	return new_guy;
}

Filtervar FiltervarRecursiveGrammarAction(Parametersdef parametersdef) {
	LogDebug("\tFiltervarRecursiveGrammarAction(%p)", parametersdef);
	
	Filtervar new_guy = Malloc(sizeof(struct FiltervarNode));
	new_guy->type = FILTERVARTYPE_PARAMETERSDEF;
	new_guy->parametersdef = parametersdef;

	return new_guy;
}

Filtervar FilterVarnameGrammarAction(char * varname) {
	LogDebug("\tFilterVarnameGrammarAction(%s)", varname);

	Filtervar new_guy = Malloc(sizeof(struct FiltervarNode));
	new_guy->type = FILTERVARTYPE_VAR_NAME;
	new_guy->var_name = varname;

	return new_guy;
}

Filterdef FilterdefGrammarAction(char * varname, Filtervar filtervar) {
	LogDebug("\tFilterdefGrammarAction(%s, %p)", varname, filtervar);

	Filterdef new_guy = Malloc(sizeof(struct FilterdefNode));
	new_guy->var_name = varname;
	new_guy->filtervar = filtervar;

	return new_guy;
}

Parametersdef ParametersdefParenthesisGrammarAction(Properties property, float value) {
	LogDebug("\tParametersdefParenthesisGrammarAction(%p, %.2f)", property, value);
	
	Parametersdef new_guy = Malloc(sizeof(struct ParametersdefNode));
	new_guy->type = PARAMETERSDEFTYPE_LAST;
	new_guy->property = property;
	new_guy->value = value;

	return new_guy;
}

Parametersdef ParametersdefRecursiveGrammarAction(Properties property, float value, Parametersdef parametersdef) {
	LogDebug("\tParametersdefRecursiveGrammarAction(%p, %.2f, %p)", property, value, parametersdef);

	Parametersdef new_guy = Malloc(sizeof(struct ParametersdefNode));
	new_guy->type = PARAMETERSDEFTYPE_PARAMETER;
	new_guy->property = property;
	new_guy->value = value;
	new_guy->parametersdef = parametersdef;

	return new_guy;
}

Properties ExposureGrammarAction() {
	LogDebug("\tExposureGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_EXPOSURE;

	return new_guy;
}

Properties LuminosityGrammarAction() {
	LogDebug("\tLuminosityGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_LUMINOSITY;

	return new_guy;
}

Properties ShadowsGrammarAction() {
	LogDebug("\tShadowsGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_SHADOWS;

	return new_guy;
}

Properties ContrastGrammarAction() {
	LogDebug("\tContrastGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_CONTRAST;

	return new_guy;
}

Properties BrightnessGrammarAction() {
	LogDebug("\tBrightnessGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_BRIGHTNESS;

	return new_guy;
}

Properties SaturationGrammarAction() {
	LogDebug("\tSaturationGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_SATURATION;

	return new_guy;
}

Properties OpacityGrammarAction() {
	LogDebug("\tOpacityGrammarAction");

	Properties new_guy = Malloc(sizeof(struct PropertiesNode));
	new_guy->property = PROPERTY_OPACITY;

	return new_guy;
}

Setvar SetvarParenthesisGrammarAction(Images images) {
	LogDebug("\tSetvarParenthesisGrammarAction(%p)", images);

	Setvar new_guy = Malloc(sizeof(struct SetvarNode));
	new_guy->type = SETVARTYPE_SET;
	new_guy->images = images;

	return new_guy;
}

Setvar SetvarVarnameGrammarAction(char * varname) {
	LogDebug("\tSetvarVarnameGrammarAction(%s)", varname);

	Setvar new_guy = Malloc(sizeof(struct SetvarNode));
	new_guy->type = SETVARTYPE_VAR_NAME;
	new_guy->var_name = varname;

	return new_guy;
}

Setdef SetdefGrammarAction(char * varname, Setvar setvar) {
	LogDebug("\tSetdefGrammarAction(%s, %p)", varname, setvar);

	Setdef new_guy = Malloc(sizeof(struct SetdefNode));
	new_guy->var_name = varname;
	new_guy->setvar = setvar;

	return new_guy;
}

Images ImagesGrammarAction(Imagevar imagevar) {
	LogDebug("\tImagesGrammarAction(%p)", imagevar);

	Images new_guy = Malloc(sizeof(struct ImagesNode));
	new_guy->type = IMAGESTYPE_SINGLE;
	new_guy->imagevar = imagevar;

	return new_guy;
}

Images ImagesRecursiveGrammarAction(Imagevar imagevar, Images images) {
	LogDebug("\tImagesRecursiveGrammarAction(%p, %p)", imagevar, images);

	Images new_guy = Malloc(sizeof(struct ImagesNode));
	new_guy->type = IMAGESTYPE_MULTIPLE;
	new_guy->imagevar = imagevar;
	new_guy->images = images;

	return new_guy;	
}

Fordef FordefGrammarAction(char * varname, Setvar setvar, Block block) {
	LogDebug("\tFordefGrammarAction(%s, %p, %p)", varname, setvar, block);
	
	Fordef new_guy = Malloc(sizeof(struct FordefNode));
	new_guy->var_name = varname;
	new_guy->setvar = setvar;
	new_guy->block = block;

	return new_guy;
}

Block BlockGrammarAction(Functions functions) {
	LogDebug("\tBlockGrammarAction(%p)", functions);

	Block new_guy = Malloc(sizeof(struct BlockNode));
	new_guy->type = BLOCKTYPE_SINGLE;
	new_guy->functions = functions;

	return new_guy;
}

Block BlockRecursiveGrammarAction(Functions functions, Block block) {
	LogDebug("\tBlockRecursiveGrammarAction(%p, %p)", functions, block);

	Block new_guy = Malloc(sizeof(struct BlockNode));
	new_guy->type = BLOCKTYPE_MULTIPLE;
	new_guy->functions = functions;
	new_guy->block = block;

	return new_guy;
}

Functions ApplyFiltersGrammarAction(char * varname, Filters filters) {
	LogDebug("\tApplyFiltersGrammarAction(%s, %p)", varname, filters);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_APPLY_FILTERS;
	new_guy->var_name = varname;
	new_guy->filters = filters;

	return new_guy;
}

Functions OverlapImagesGrammarAction(char * varname, Imagevar imagevar, Positions position) {
	LogDebug("\tOverlapImagesGrammarAction(%s, %p, %p)", varname, imagevar, position);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_OVERLAP;
	new_guy->var_name = varname;
	new_guy->imagevar = imagevar;
	new_guy->position = position;

	return new_guy;
}

Functions ResizeImageGrammarAction(char * varname, float width, float height) {
	LogDebug("\tResizeImageGrammarAction(%s, %.2f, %.2f)", varname, width, height);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_RESIZE;
	new_guy->var_name = varname;
	new_guy->width = width;
	new_guy->height = height;

	return new_guy;
}

Functions UnionImagesGrammarAction(char * varname, Imagevar imagevar, Axises axis) {
	LogDebug("\tUnionImagesGrammarAction(%s, %p, %p)", varname, imagevar, axis);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_UNION;
	new_guy->var_name = varname;
	new_guy->imagevar = imagevar;
	new_guy->axis = axis;

	return new_guy;
}

Functions TrimImageGrammarAction(char * varname, float width, float height, Positions position) {
	LogDebug("\tTrimImageGrammarAction(%s, %.2f, %.2f, %p)", varname, width, height, position);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_TRIM;
	new_guy->var_name = varname;
	new_guy->width = width;
	new_guy->height = height;
	new_guy->position = position;

	return new_guy;
}

Functions SaveGrammarAction(char * varname) {
	LogDebug("\tSaveGrammarAction(%s)", varname);

	Functions new_guy = Malloc(sizeof(struct FunctionsNode));
	new_guy->type = FUNCTIONSTYPE_SAVE;
	new_guy->var_name = varname;

	return new_guy;
}

Axises AxisXGrammarAction() {
	LogDebug("\tAxisXGrammarAction");

	Axises new_guy = Malloc(sizeof(struct AxisesNode));
	new_guy->axis = AXIS_X;

	return new_guy;
}

Axises AxisYGrammarAction() {
	LogDebug("\tAxisYGrammarAction");

	Axises new_guy = Malloc(sizeof(struct AxisesNode));
	new_guy->axis = AXIS_Y;

	return new_guy;
}

Filters FiltersGrammarAction(Filtervar filtervar) {
	LogDebug("\tFiltersGrammarAction(%p)", filtervar);

	Filters new_guy = Malloc(sizeof(struct FiltersNode));
	new_guy->type = FILTERSTYPE_SINGLE;
	new_guy->filtervar = filtervar;

	return new_guy;
}

Filters FiltersRecursiveGrammarAction(Filtervar filtervar, Filters filters) {
	LogDebug("\tFiltersRecursiveGrammarAction(%p, %p)", filtervar, filters);

	Filters new_guy = Malloc(sizeof(struct FiltersNode));
	new_guy->type = FILTERSTYPE_MULTIPLE;
	new_guy->filtervar = filtervar;
	new_guy->filters = filters;

	return new_guy;
}

Positions PositionTopLeftGrammarAction() {
	LogDebug("\tPositionTopLeftGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_TOP_LEFT;

	return new_guy;
}

Positions PositionTopCenterGrammarAction() {
	LogDebug("\tPositionTopCenterGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_TOP_CENTER;

	return new_guy;
}

Positions PositionTopRightGrammarAction() {
	LogDebug("\tPositionTopRightGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_TOP_RIGHT;

	return new_guy;
}

Positions PositionCenterLeftGrammarAction() {
	LogDebug("\tPositionCenterLeftGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_CENTER_LEFT;

	return new_guy;
}

Positions PositionCenterCenterGrammarAction() {
	LogDebug("\tPositionCenterCenterGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_CENTER_CENTER;

	return new_guy;
}

Positions PositionCenterRightGrammarAction() {
	LogDebug("\tPositionCenterRightGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_CENTER_RIGHT;

	return new_guy;
}

Positions PositionBottomLeftGrammarAction() {
	LogDebug("\tPositionBottomLeftGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_BOTTOM_LEFT;

	return new_guy;
}

Positions PositionBottomCenterGrammarAction() {
	LogDebug("\tPositionBottomCenterGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_BOTTOM_CENTER;

	return new_guy;
}

Positions PositionBottomRightGrammarAction() {
	LogDebug("\tPositionBottomRightGrammarAction");

	Positions new_guy = Malloc(sizeof(struct PositionsNode));
	new_guy->position = POSITION_BOTTOM_RIGHT;

	return new_guy;
}
