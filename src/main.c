#include "backend/code-generation/generator.h"
#include "backend/support/logger.h"
#include "backend/support/shared.h"
#include "backend/support/garbage-collector.h"
#include "frontend/syntactic-analysis/bison-parser.h"
#include <stdio.h>
#include <string.h>

// Estado de la aplicación.
CompilerState state;

// Punto de entrada principal del compilador.
const int main(const int argumentCount, const char ** arguments) {
	// Inicializar estado de la aplicación.
	state.program = NULL;
	state.errors = NULL;
	state.last_error = NULL;
	state.error_count = 0;
	state.succeed = false;
	state.generate_images = false;

	// Verificar si se deben generar las imágenes
	if (argumentCount == 2 && strcmp(arguments[1], "-g") == 0) {
		state.generate_images = true;
    } else if (argumentCount > 2) {
		LogError("Argumentos Invalidos. Uso: ./script/start.sh [-g] path/a/archivo.imgine");
		return -1;
	}

    

	// Mostrar parámetros recibidos por consola.
	for (int i = 0; i < argumentCount; ++i) {
		LogInfo("Argumento %d: '%s'", i, arguments[i]);
	}

	// Compilar el programa de entrada.
	LogInfo("Compilando...\n");
	const int result = yyparse();
	switch (result) {
		case 0:
			// La variable "succeed" es la que setea Bison al identificar el símbolo
			// inicial de la gramática satisfactoriamente.
			if (state.succeed) {
				LogInfo("La compilacion fue exitosa.");
				Generate(state.program);
			}
			else {
				LogError("Se produjo un error de compilación.");
				while (state.errors != NULL) {
					printf("%s", state.errors->message);
					state.errors = state.errors->next;
				}
				return -1;
			}
			break;
		case 1:
			LogError("Bison finalizo debido a un error de sintaxis.");
			while (state.errors != NULL) {
				printf("%s", state.errors->message);
				state.errors = state.errors->next;
			}
			break;
		case 2:
			LogError("Bison finalizo abruptamente debido a que ya no hay memoria disponible.");
			break;
		default:
			LogError("Error desconocido mientras se ejecutaba el analizador Bison (codigo %d).", result);
	}
	FreeAll();
	LogInfo("Fin.");
	return result;
}
