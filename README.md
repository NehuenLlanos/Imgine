# Imgine - Image Engine

Un compilador construido con Flex y Bison, en el marco de la materia Autómatas, Teoría de Lenguajes y Compiladores del Instituto Tecnológico de Buenos Aires.

|Alumno|Legajo|Mail|
|-|-|-|
|Alejo Flores Lucey|62622|afloreslucey@itba.edu.ar|
|Andrés Carro Wetzel|61655|acarro@itba.edu.ar
|Juan Segundo Arnaude|62184|jarnaude@itba.edu.ar
|Nehuén Gabriel Llanos|62511|nllanos@itba.edu.ar

## Requerimientos

Para construir el compilador, se requiere tener instalado [Docker](https://docs.docker.com/engine/install/), junto con la imagen de compilación:

```Bash
$ docker pull alejofl/tla-compiler
```

## Construcción

Para construir el proyecto por completo, ejecute en la raíz del repositorio los siguientes comandos:

```bash
$ chmod u+x --recursive script
$ docker run -v "${PWD}:/root" -ti --rm alejofl/tla-compiler
$ ./script/build.sh
```

## Ejecución

Para compilar, primero cree un archivo con el contenido del programa. A modo de ejemplo, el path al archivo (relativo a la raíz del proyecto) será `program`.

Luego, dentro del contenedor de Docker, ejecute el compilador desde el directorio raíz del proyecto, pasando por parámetro el path hacia el programa a compilar:

```bash
$ ./script/start.sh program
```

## Testing

Dentro del contenedor de Docker,

```bash
$ ./script/test.sh
```

Si desea agregar nuevos casos de uso, deberá crear un archivo por cada uno, que contenga el programa a testear dentro de las carpetas `test/accept` o `test/reject` según corresponda (es decir, si el mismo debe ser aceptado o rechazado por el compilador).
