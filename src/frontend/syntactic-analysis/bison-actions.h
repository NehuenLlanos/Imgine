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

// Nuestras
int ProgramGrammarAction(char *expression);

int ExpressionImagedefSentenceGrammarAction(char *imagedef, char *sentence);
int FilterdefExpressionGrammarAction(char *filterdef, char *expression);
int SetdefExpressionGrammarAction(char *setdef, char *expression);
int FordefExpressionGrammarAction(char *fordef, char *expression);
int CommentExpressionGrammarAction(char *expression);

int ImagedefSenteceGrammarAction(char *imagedef, char *sentence);
int FilterdefSenteceGrammarAction(char *filterdef, char *sentence);
int SetdefSentenceGrammarAction(char *setdef, char *sentence);
int FordefSentenceGrammarAction(char *fordef, char *sentence);
int FunctionsSentenceGrammarAction(char *functions, char *sentence);
int CommentSentenceGrammarAction(char *sentence);

int ImagevarParenthesisGrammarAction(char *path);
int ImagevarVarnameGrammarAction(char *varname);

int ImagedefGrammarAction(char *varname, char *imagevar);

int FiltervarParanthesisGrammarAction(char *filtername);
int FiltervarRecursiveGrammarAction(char *parametersdef);
int FilterVarnameGrammarAction(char *varname);

int FilterdefGrammarAction(char *varname, char *filtervar);

int ParametersdefParenthesisGrammarAction(char *property, float value);
int ParametersdefRecursiveGrammarAction(char *property, float value, char *parametersdef);

int ExposureGrammarAction();
int LuminosityGrammarAction();
int ShadowsGrammarAction();
int ContrastGrammarAction();
int BrightnessGrammarAction();
int SaturationGrammarAction();
int OpacityGrammarAction();

int SetvarParenthesisGrammarAction(char *images);
int SetvarVarnameGrammarAction(char *varname);

int SetdefGrammarAction(char *varname, char *setvar);

int ImagesGrammarAction(char *imagevar);
int ImagesRecursiveGrammarAction(char *imagevar, char *images);

int FordefGrammarAction(char *varname, char *setvar, char *block);

int BlockGrammarAction(char *functions);
int BlockRecursiveGrammarAction(char *functions, char *block);

int ApplyFiltersGrammarAction(char *varname, char *filters);
int OverlapImagesGrammarAction(char *varname, char *imagevar, int position);
int ResizeImageGrammarAction(char *varname, float width, float height);
int UnionImagesGrammarAction(char *varname, char *imagevar, char *axis);
int TrimImageGrammarAction(char *varname, float width, float height, int position);
int SaveFormatGrammarAction(char *varname, char *format);
int SaveGrammarAction(char *varname);

int AxisXGrammarAction();
int AxisYGrammarAction();

int FiltersGrammarAction(char *filtervar);
int FiltersRecursiveGrammarAction(char *filtervar, char *filters);

#endif
