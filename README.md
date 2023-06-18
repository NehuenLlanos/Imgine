<img src="https://user-images.githubusercontent.com/48220676/234736990-d0f68e88-f800-4df6-b18e-52cc5a969052.jpg" width="100%">

# Imgine - Image Engine

Un compilador construido con Flex y Bison, en el marco de la materia Autómatas, Teoría de Lenguajes y Compiladores del Instituto Tecnológico de Buenos Aires.

|Alumno|Legajo|Mail|
|-|-|-|
|Alejo Flores Lucey|62622|afloreslucey@itba.edu.ar|
|Andrés Carro Wetzel|61655|acarro@itba.edu.ar
|Juan Segundo Arnaude|62184|jarnaude@itba.edu.ar
|Nehuén Gabriel Llanos|62511|nllanos@itba.edu.ar

<hr>

* [Introducción](#introducción)
* [Utilización del compilador](#utilización-del-compilador)
  * [Requerimientos](#requerimientos)
  * [Construcción](#construcción)
  * [Ejecución](#ejecución)
  * [Testing](#testing)
* [Desarrollo del proyecto](#desarrollo-del-proyecto)
* [Ejemplos de código](#ejemplos-de-código)
* [Limitaciones y dificultades encontradas](#limitaciones-y-dificultades-encontradas)
* [Futuras extensiones y modificaciones](#futuras-extensiones-y-modificaciones)
* [Conclusiones](#conclusiones)

<hr>

## Introducción

Imgine es un lenguaje que permite manipular y aplicar transformaciones a archivos de imágenes. El lenguaje facilita aplicar ciertas acciones repetitivas y comunes relacionadas a las fotografías, como redimensionar, escalar, recortar y unir imágenes, así como modificar los parámetros de la imagen como luminosidad, brillo, contraste, saturación, exposición, entre otros.

Asimismo, se pueden aplicar filtros de tipo batch como agregar una marca de gua o replicar un conjunto de modificaciones a un grupo de archivos.

Para reducir la complejidad del proyecto, se utilizaron las librerías de Python Pillow y NumPy para aplicar de manera más simple todas las transformaciones deseadas.

La idea de este lenguaje nace con la idea de centralizar y versionar el proceso de generación de assets estáticos para proyectos informáticos, permitiendo aplicar las mismas técnicas de desarrollo que a una aplicación; a saber, revisión, testing y análisis estático.

A modo de ejemplo, utilizar este servicio automatizaría en cierta manera la forma en la que se procesan las imágenes utilizadas para una página web: se podrían generar distintos assets de  manera automática en relación al dispositivo utilizado, evitando que un diseñador lo tenga que hacer manualmente, una por una. Además, se podría utilizar en páginas web del estilo de WordPress para unificar el estilo de todas las imágenes de un blog.

## Utilización del compilador

### Requerimientos

Para construir el compilador, se requiere tener instalado [Docker](https://docs.docker.com/engine/install/), junto con la imagen de compilación.

Dicha imagen se puede descargar de Docker Hub con el siguiente comando:

```
$ docker pull alejofl/tla-compiler
```

Alternativamente, se puede crear la imagen necesaria utilizando el archivo `Dockerfile`:

```
$ docker build -t compiler .
```

### Construcción

Para construir el proyecto por completo, ejecute en la raíz del repositorio los siguientes comandos:

```
$ chmod u+x --recursive script
$ docker run -v "${PWD}:/root" -ti --rm alejofl/tla-compiler
$ ./script/build.sh
```

### Ejecución

Para compilar, primero cree un archivo con el contenido del programa. A modo de ejemplo, el path al archivo (relativo a la raíz del proyecto) será `program`.

Luego, dentro del contenedor de Docker, ejecute el compilador desde el directorio raíz del proyecto, pasando por parámetro el path hacia el programa a compilar:

```
$ ./script/start.sh program
```

El comando anteriormente mencionado compilará el archivo `program` y dejará como resultado un archivo con código Python llamado `imgine_generator.py`, que estará alojado en la carpeta donde se ejecutó el comando.

Si se quisiera ejecutar ese archivo Python, se puede agregar el flag `-g` al comando, para así generar las imágenes descriptas en el archivo Imgine. Todas las imágenes resultantes serán guardadas en un nuevo directorio `imgine_output`, que estará alojado en el mismo directorio donde se ejecutó el comando:

```
$ ./script/start.sh -g program
```

### Testing

Dentro del contenedor de Docker,

```
$ ./script/test.sh
```

Si desea agregar nuevos casos de uso, deberá crear un archivo por cada uno, que contenga el programa a testear dentro de las carpetas `test/accept` o `test/reject` según corresponda (es decir, si el mismo debe ser aceptado o rechazado por el compilador).

## Desarrollo del proyecto

El desarrollo del compilador tuvo tres iteraciones bastante marcadas. En primer lugar, se tuvieron que plantear las funcionalidades que el lenguaje iba a proveer. Esto resultó un desafío debido a la necesidad de condensar lo máximo posible los requerimientos externos, sumado a las limitaciones existentes de Pillow. El grupo logró ponerse de acuerdo en una batería de funcionalidades que no agregaban gran complejidad al desarrollo y hacían que el lenguaje sirva en un entorno de producción real.

En segundo lugar, se debió pensar la sintaxis de Imgine, para luego convertirla en una gramática propiamente dicha, que pueda ser programada. Se tuvieron en cuenta otros lenguajes de programación existentes, como Python y C, para combinar lo mejor de cada uno y lograr un lenguaje fácilmente utilizable. Para el equipo fue primordial lograr un lenguaje cuya sintaxis no agregue complejidad a la hora de programar. Luego de eso, se programó la gramática de Imgine, utilizando Lex (Flex) y Yacc (Bison).

Por último, se debió implementar el análisis semántico del lenguaje, donde se agregaron la mayoría de las limitaciones del mismo. Inicialmente, se concentraron los esfuerzos en crear el árbol de sintaxis abstracta del programa. Luego, se programó la parte de generación de código. Dentro de este proceso, gran parte del esfuerzo se concentró en encontrar las maneras de lograr las funcionalidades que habíamos propuesto en Python. Finalmente, se crearon las estructuras necesarias para soportar una tabla de símbolos, así permitiendo detectar errores de tipos de datos y de variables no definidas.

Adicionalmente a lo propuesto por el enunciado, se desarrolló una extensión de Visual Studio Code para lograr el *syntax highlighting* de los archivos Imgine. Para ello, se utilizaron los recursos disponibles en la documentación de VS Code, todo sobre JavaScript. Creemos que este desarrollo adicional es muy beneficioso para futuros usos del lenguaje, pues permite adelantar ciertos errores de sintaxis sin necesidad de compilar, además de hacer el proceso de codificación más visualmente atractivo.

## Ejemplos de código

1. El siguiente fragmento de código crea y superpone una marca de agua a un conjunto de imágenes:
    
    ```
    image watermark = image("path/to/watermark.png");
    image image_1 = image("path/to/image_1.jpg");
    image image_2 = image("path/to/image_2.tiff");
    image image_3 = image("path/to/image_3");
    
    watermark.apply(filter().parameter(opacity=0.5));
    
    for im in set(image_1, image_2, image_3) {
        im.overlap(watermark, position=bottom-right);
        im.save();
    }
    ```
    
2. El siguiente fragmento de código toma ciertas imágenes y las modifica para que sirvan para fondos de pantalla para el celular:
    
    ```
    filter blur = filter("BLUR");
    filter other_filter = filter()
                              .parameter(shadows=0.6)
                              .parameter(brightness=0.5);
    
    for wallpaper in set(image("playa.jpg");, image("mar.jpg"), image("cielo.png")) {
        wallpaper.apply(blur, other_filter);
        wallpaper.trim(width=1080.0, height=1920.0, position=center-center);
        wallpaper.save();
    }
    ```
    

## Limitaciones y dificultades encontradas

No se han encontrado grandes dificultades a la hora de desarrollar el lenguaje. Vale la pena mencionar que se subestimó la tediosa y difícil tarea de cumplir con todos los requerimientos presentados en la primera entrega en Python. Se pensó que las funcionalidades que proponíamos eran estándar en las diferentes librerías disponibles, cuando muchas veces no lo fueron. Dichos problemas fueron solucionados mediante la implementación de clases y funciones propias que resuelvan ciertos problemas. 

Solo a modo demostrativo, tuvimos problemas a la hora de declarar filtros como variables, pues las librerías no contaban con esa funcionalidad. Para sortear esta dificultad, se programó la clase `Filter` y `NamedFilter`, que encapsulan funcionalidades de Pillow.

La mayor limitación que presenta Imgine hoy en día es que no se permiten la redefinición de variables, aunque estas tengan diferente alcance. Esto hace imposible el *shadowing* de variables o reutilizar las variables identificadoras de un ciclo.

## Futuras extensiones y modificaciones

A continuación se listan una serie de modificaciones que harían de Imgine un lenguaje más potente:

- Permitir la redefinición de variables en diferentes *scopes*. No debería ser una modificación de gran complejidad, pero requeriría de un cambio en la lógica de la generación de código. Sería altamente beneficioso para permitir el *shadowing* de variables y hacer el código más legible.
- Agregar más filtros predefinidos. Ahora mismo se ofrecen los que la librería externa Pillow ofrece por defecto. Se podrían agregar otras opciones con la adición de código Python adicional. Esto permitiría hacer acciones comunes y repetidas por todos de manera más fácil, como convertir fotos a blanco y negro.
- Permitir abrir en un ciclo todas las imágenes de un directorio, en vez de tener que abrir una imagen a la vez, manualmente. Este cambio supone una complejidad mayor, por la necesidad de modificar la gramática y la sintaxis del lenguaje, así como todos los procedimientos siguientes a ello. Este cambio permitiría aplicar modificaciones *batch* de manera más amigable.
- Permitir guardar las imágenes en distintos formatos. Esta funcionalidad había sido propuesta en un principio, pero luego fue descartada debido a la complejidad que suponía a la hora de generar el código Python. Esto se debe a que para que el resto de funcionalidades sea compatible, se debía saber el formato de guardado de la imagen a la hora de abrirla. Esto podría ser solucionado recorriendo más de una vez el árbol de sintaxis abstracta.

Por otro lado, se podría agregar una página de documentación de Imgine, donde se liste todo lo que el lenguaje ofrece. Además, la extensión de Visual Studio Code tiene gran potencial de crecimiento: se le puede agregar autocompletado, documentación *inline*, entre otros.

## Conclusiones

En conclusión, creemos que este trabajo práctico ha sido una gran manera de aplicar los conocimientos teóricos vistos en clase a algo más práctico. Consideramos que permite obtener un *insight* interesante a los compiladores, que muchas veces son vistos como cajas negras.

El trabajo tiene un alto grado de libertad, por lo que cada alumno puede incursionar en el área que más le atraiga. Consideramos que eso es algo muy positivo.

Asimismo, no queremos dejar de mencionar la rigurosidad con la que fue corregida las entregas pasadas del trabajo práctico. No siempre hay una correlación entre la complejidad de la consigna del trabajo con su posterior calificación. Este no fue el caso y se aprecia.

Por último, a modo de crítica constructiva, consideramos que se podría adelantar unas semanas la última entrega del trabajo práctico. De esta manera, se evita que se junte con parciales de esta misma materia y otras entregas de materias del mismo cuatrimestre. Esto permitiría que se le dedique más tiempo al compilador, tal vez logrando un mejor resultado.
