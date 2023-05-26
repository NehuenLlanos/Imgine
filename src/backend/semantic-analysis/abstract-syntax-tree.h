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
	IMAGEDEF,
	FILTERDEF,
	SETDEF,
	FORDEF
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
	IMAGEDEF,
	FILTERDEF,
	SETDEF,
	FORDEF,
	FUNCTIONS
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
	VAR_NAME,
	PATH
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
	PARAMETERSDEF,
	FILTER_NAME,
	VAR_NAME
} FiltervarNodeType;

struct FiltervarNode {
	FiltervarNodeType type;
	char * filter_name;
	char * var_name;
	Parametersdef parametersdef;
};

struct FilterdefNode {
	char * var_name;
	Filtervar imagevar;
};

typedef enum {
	PARAMETER,
	LAST,
} ParametersdefNodeType;

struct ParametersdefNode {
	ParametersdefNodeType type;
	Properties property;
	float value;
	Parametersdef parametersdef;
};

typedef enum {
	EXPOSURE,
	LUMINOSITY,
	SHADOWS,
	CONTRAST,
	BRIGHTNESS,
	SATURATION,
	OPACITY
} Property;

struct PropertiesNode {
	Property property;
};

typedef enum {
	VAR_NAME,
	SET
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
	SINGLE,
	MULTIPLE
} ImagesNodeType;

struct ImagesNode {
	ImagesNodeType typr;
	Imagevar imagevar;
	Images images;
};

struct FordefNode {
	char * var_name;
	Setvar setvar;
	Block block;
};

typedef enum {
	SINGLE,
	MULTIPLE
} BlockNodeType;

struct BlockNode {
	BlockNodeType typr;
	Functions functions;
	Block block;
};

typedef enum {
	APPLY_FILTERS,
	OVERLAP,
	RESIZE,
	UNION,
	TRIM,
	SAVE_WITH_FORMAT,
	SAVE
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
	X,
	Y
} Axis;

struct AxisesNode {
	Axis axis;
};

typedef enum {
	SINGLE,
	MULTIPLE
} FiltersNodeType;

struct FiltersNode {
	FiltersNodeType type;
	Filtervar filtervar;
	Filters filters;
};

typedef enum {
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	CENTER_LEFT,
	CENTER_CENTER,
	CENTER_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT
} Position;

struct PositionsNode {
	Position position;
};

#endif
