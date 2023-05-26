#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

typedef struct ProgramNode * Program;
typedef struct ExpressionNode * Expression;
typedef struct SentenceNode * Sentence;
typedef struct ImagevarNode * Imagevar;
typedef struct ImagedefNode * Imagedef;
typedef struct FiltervarNode * Filtervar;
typedef struct FilterdefNode * Filterdef;
typedef struct ParametersdefNode * Parametersdef;
typedef struct PropertiesNode * Properties;
typedef struct SetvarNode * Setvar;
typedef struct SetdefNode * Setdef;
typedef struct ImagesNode * Images;
typedef struct FordefNode * Fordef;
typedef struct BlockNode * Block;
typedef struct FunctionsNode * Functions;
typedef struct AxisesNode * Axises;
typedef struct FiltersNode * Filters;
typedef struct PositionsNode * Positions;

struct ProgramNode {
	Expression expression;
};

typedef enum {
	EXPRESSIONTYPE_IMAGEDEF,
	EXPRESSIONTYPE_FILTERDEF,
	EXPRESSIONTYPE_SETDEF,
	EXPRESSIONTYPE_FORDEF,
	EXPRESSIONTYPE_LAMBDA
} ExpressionNodeType;

struct ExpressionNode {
	ExpressionNodeType type;
	Imagedef imagedef;
	Filterdef filterdef;
	Setdef setdef;
	Fordef fordef;
	Sentence sentence;
	Expression expression;
};

typedef enum {
	SENTENCETYPE_IMAGEDEF,
	SENTENCETYPE_FILTERDEF,
	SENTENCETYPE_SETDEF,
	SENTENCETYPE_FORDEF,
	SENTENCETYPE_FUNCTIONS,
	SENTENCETYPE_LAMBDA
} SentenceNodeType;

struct SentenceNode {
	SentenceNodeType type;
	Imagedef imagedef;
	Filterdef filterdef;
	Setdef setdef;
	Fordef fordef;
	Functions functions;
	Sentence sentence;
};

typedef enum {
	IMAGEVARTYPE_VAR_NAME,
	IMAGEVARTYPE_PATH
} ImagevarNodeType;

struct ImagevarNode {
	ImagevarNodeType type;
	char * var_name;
	char * path;
};

struct ImagedefNode {
	char * var_name;
	Imagevar imagevar;
};

typedef enum {
	FILTERVARTYPE_PARAMETERSDEF,
	FILTERVARTYPE_FILTER_NAME,
	FILTERVARTYPE_VAR_NAME
} FiltervarNodeType;

struct FiltervarNode {
	FiltervarNodeType type;
	char * filter_name;
	char * var_name;
	Parametersdef parametersdef;
};

struct FilterdefNode {
	char * var_name;
	Filtervar filtervar;
};

typedef enum {
	PARAMETERSDEFTYPE_PARAMETER,
	PARAMETERSDEFTYPE_LAST,
} ParametersdefNodeType;

struct ParametersdefNode {
	ParametersdefNodeType type;
	Properties property;
	float value;
	Parametersdef parametersdef;
};

typedef enum {
	PROPERTY_EXPOSURE,
	PROPERTY_LUMINOSITY,
	PROPERTY_SHADOWS,
	PROPERTY_CONTRAST,
	PROPERTY_BRIGHTNESS,
	PROPERTY_SATURATION,
	PROPERTY_OPACITY
} Property;

struct PropertiesNode {
	Property property;
};

typedef enum {
	SETVARTYPE_VAR_NAME,
	SETVARTYPE_SET
} SetvarNodeType;

struct SetvarNode {
	SetvarNodeType type;
	Images images;
	char * var_name;
};

struct SetdefNode {
	char * var_name;
	Setvar setvar;
};

typedef enum {
	IMAGESTYPE_SINGLE,
	IMAGESTYPE_MULTIPLE
} ImagesNodeType;

struct ImagesNode {
	ImagesNodeType type;
	Imagevar imagevar;
	Images images;
};

struct FordefNode {
	char * var_name;
	Setvar setvar;
	Block block;
};

typedef enum {
	BLOCKTYPE_SINGLE,
	BLOCKTYPE_MULTIPLE
} BlockNodeType;

struct BlockNode {
	BlockNodeType type;
	Functions functions;
	Block block;
};

typedef enum {
	FUNCTIONSTYPE_APPLY_FILTERS,
	FUNCTIONSTYPE_OVERLAP,
	FUNCTIONSTYPE_RESIZE,
	FUNCTIONSTYPE_UNION,
	FUNCTIONSTYPE_TRIM,
	FUNCTIONSTYPE_SAVE_WITH_FORMAT,
	FUNCTIONSTYPE_SAVE
} FunctionsNodeType;

struct FunctionsNode {
	FunctionsNodeType type;
	char * var_name;
	Filters filters;
	Imagevar imagevar;
	Positions position;
	float width;
	float height;
	Axises axis;
	char * format;
};

typedef enum {
	AXIS_X,
	AXIS_Y
} Axis;

struct AxisesNode {
	Axis axis;
};

typedef enum {
	FILTERSTYPE_SINGLE,
	FILTERSTYPE_MULTIPLE
} FiltersNodeType;

struct FiltersNode {
	FiltersNodeType type;
	Filtervar filtervar;
	Filters filters;
};

typedef enum {
	POSITION_TOP_LEFT,
	POSITION_TOP_CENTER,
	POSITION_TOP_RIGHT,
	POSITION_CENTER_LEFT,
	POSITION_CENTER_CENTER,
	POSITION_CENTER_RIGHT,
	POSITION_BOTTOM_LEFT,
	POSITION_BOTTOM_CENTER,
	POSITION_BOTTOM_RIGHT
} Position;

struct PositionsNode {
	Position position;
};

#endif
