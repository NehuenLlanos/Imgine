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

int ProgramGrammarAction(int expression);

int ExpressionImagedefSentenceGrammarAction(int imagedef, int sentence);
int FilterdefExpressionGrammarAction(int filterdef, int expression);
int SetdefExpressionGrammarAction(int setdef, int expression);
int FordefExpressionGrammarAction(int fordef, int expression);

int ImagedefSenteceGrammarAction(int imagedef, int sentence);
int FilterdefSenteceGrammarAction(int filterdef, int sentence);
int SetdefSentenceGrammarAction(int setdef, int sentence);
int FordefSentenceGrammarAction(int fordef, int sentence);
int FunctionsSentenceGrammarAction(int functions, int sentence);

int ImagevarParenthesisGrammarAction(char *path);
int ImagevarVarnameGrammarAction(char *varname);

int ImagedefGrammarAction(char *varname, int imagevar);

int FiltervarParanthesisGrammarAction(char *filtername);
int FiltervarRecursiveGrammarAction(int parametersdef);
int FilterVarnameGrammarAction(char *varname);

int FilterdefGrammarAction(char *varname, int filtervar);

int ParametersdefParenthesisGrammarAction(int property, float value);
int ParametersdefRecursiveGrammarAction(int property, float value, int parametersdef);

int ExposureGrammarAction();
int LuminosityGrammarAction();
int ShadowsGrammarAction();
int ContrastGrammarAction();
int BrightnessGrammarAction();
int SaturationGrammarAction();
int OpacityGrammarAction();

int SetvarParenthesisGrammarAction(int images);
int SetvarVarnameGrammarAction(char *varname);

int SetdefGrammarAction(char *varname, int setvar);

int ImagesGrammarAction(int imagevar);
int ImagesRecursiveGrammarAction(int imagevar, int images);

int FordefGrammarAction(char *varname, int setvar, int block);

int BlockGrammarAction(int functions);
int BlockRecursiveGrammarAction(int functions, int block);

int ApplyFiltersGrammarAction(char *varname, int filters);
int OverlapImagesGrammarAction(char *varname, int imagevar, int position);
int ResizeImageGrammarAction(char *varname, float width, float height);
int UnionImagesGrammarAction(char *varname, int imagevar, int axis);
int TrimImageGrammarAction(char *varname, float width, float height, int position);
int SaveFormatGrammarAction(char *varname, char *format);
int SaveGrammarAction(char *varname);

int AxisXGrammarAction();
int AxisYGrammarAction();

int FiltersGrammarAction(int filtervar);
int FiltersRecursiveGrammarAction(int filtervar, int filters);

int PositionTopLeftGrammarAction();
int PositionTopCenterGrammarAction();
int PositionTopRightGrammarAction();
int PositionCenterLeftGrammarAction();
int PositionCenterCenterGrammarAction();
int PositionCenterRightGrammarAction();
int PositionBottomLeftGrammarAction();
int PositionBottomCenterGrammarAction();
int PositionBottomRightGrammarAction();

#endif
