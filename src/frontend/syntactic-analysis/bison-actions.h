#ifndef BISON_ACTIONS_HEADER
#define BISON_ACTIONS_HEADER

#include "../../backend/support/shared.h"
#include "../../backend/semantic-analysis/abstract-syntax-tree.h"

/**
 * Se definen las acciones a ejecutar sobre cada regla de producción de la
 * gramática. El objetivo de cada acción debe ser el de construir el nodo
 * adecuado que almacene la información requerida en el árbol de sintaxis
 * abstracta (i.e., el AST).
 */

Program ProgramGrammarAction(Expression expression);

Expression ExpressionImagedefSentenceGrammarAction(Imagedef imagedef, Sentence sentence);
Expression FilterdefExpressionGrammarAction(Filterdef filterdef, Expression expression);
Expression SetdefExpressionGrammarAction(Setdef setdef, Expression expression);
Expression FordefExpressionGrammarAction(Fordef fordef, Expression expression);
Expression LambdaExpressionGrammarAction();

Sentence ImagedefSenteceGrammarAction(Imagedef imagedef, Sentence sentence);
Sentence FilterdefSenteceGrammarAction(Filterdef filterdef, Sentence sentence);
Sentence SetdefSentenceGrammarAction(Setdef setdef, Sentence sentence);
Sentence FordefSentenceGrammarAction(Fordef fordef, Sentence sentence);
Sentence FunctionsSentenceGrammarAction(Functions functions, Sentence sentence);
Sentence LambdaSentenceGrammarAction();

Imagevar ImagevarParenthesisGrammarAction(char * path);
Imagevar ImagevarVarnameGrammarAction(char * varname);

Imagedef ImagedefGrammarAction(char * varname, Imagevar imagevar);

Filtervar FiltervarParanthesisGrammarAction(char * filtername);
Filtervar FiltervarRecursiveGrammarAction(Parametersdef parametersdef);
Filtervar FilterVarnameGrammarAction(char * varname);

Filterdef FilterdefGrammarAction(char * varname, Filtervar filtervar);

Parametersdef ParametersdefParenthesisGrammarAction(Properties property, float value);
Parametersdef ParametersdefRecursiveGrammarAction(Properties property, float value, Parametersdef parametersdef);

Properties ExposureGrammarAction();
Properties LuminosityGrammarAction();
Properties ShadowsGrammarAction();
Properties ContrastGrammarAction();
Properties BrightnessGrammarAction();
Properties SaturationGrammarAction();
Properties OpacityGrammarAction();

Setvar SetvarParenthesisGrammarAction(Images images);
Setvar SetvarVarnameGrammarAction(char * varname);

Setdef SetdefGrammarAction(char * varname, Setvar setvar);

Images ImagesGrammarAction(Imagevar imagevar);
Images ImagesRecursiveGrammarAction(Imagevar imagevar, Images images);

Forvar ForvarGrammarAction(char * varname);
Fordef FordefGrammarAction(Forvar forvar, Setvar setvar, Block block);

Block BlockGrammarAction(Functions functions);
Block BlockRecursiveGrammarAction(Functions functions, Block block);

Functions ApplyFiltersGrammarAction(char * varname, Filters filters);
Functions OverlapImagesGrammarAction(char * varname, Imagevar imagevar, Positions position);
Functions ResizeImageGrammarAction(char * varname, float width, float height);
Functions UnionImagesGrammarAction(char * varname, Imagevar imagevar, Axises axis);
Functions TrimImageGrammarAction(char * varname, float width, float height, Positions position);
Functions SaveGrammarAction(char * varname);

Axises AxisXGrammarAction();
Axises AxisYGrammarAction();

Filters FiltersGrammarAction(Filtervar filtervar);
Filters FiltersRecursiveGrammarAction(Filtervar filtervar, Filters filters);

Positions PositionTopLeftGrammarAction();
Positions PositionTopCenterGrammarAction();
Positions PositionTopRightGrammarAction();
Positions PositionCenterLeftGrammarAction();
Positions PositionCenterCenterGrammarAction();
Positions PositionCenterRightGrammarAction();
Positions PositionBottomLeftGrammarAction();
Positions PositionBottomCenterGrammarAction();
Positions PositionBottomRightGrammarAction();

#endif
