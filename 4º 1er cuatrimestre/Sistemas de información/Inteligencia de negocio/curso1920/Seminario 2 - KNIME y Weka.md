# Seminario 2. KNIME y Weka

# Clasificación

En este seminario aprenderemos a utilizar el Workflow de KNIME mediante algunos de ejemplos.

Comenzamos creando un nuevo archivo: KNIME Explorer > Local (click derecho) > New KNIME Workflow... Para añadir nodos al Workflow los iremos buscando en Node Repository.

En primer lugar leeremos los datos mediante el nodo File Reader (IO/Read/File Reader) que nos permite leer CSV entre otros formatos, lo arrastramos al Workflow Editor, saldrá con el triángulo amarillo de "warning". Para solucionarlo, hacemos doble click en él y seleccionamos un .data previamente preparado (buscamos en UCI iris.data y damos nombre a sus variables añadiendo una primera línea:
sepal length, sepal width, petal length, petal width, class).
KNIME asignará directamente D (double) para los 4 primeros y S (string) para el último, esto es correcto.
Al cargar los datos, el nodo pasará de rojo a amarillo.
Le doy a ejecutar y mostrar los datos (shift+F7) y pasa de amarillo a verde.

Buscamos el nodo Partitioning y lo arrastramos al Workflow Editor.
Unimos ambos nodos con la flecha, para ello hacemos click en la flecha que sale de File Reader y la unimos a la que llega a Partitioning.
Tenemos que configurar el Partitioning. Doble click. 
Cambiaremos la configuración por defecto, usaremos:
Relative 80% (irán 80% de los datos a entrenamiento y el 20% para test).
En general, usaríamos Draw Randomly para un muestreo aleatorio.
Pero en algunos problemas podemos tener clases desbalanceadas, que no tengan una naturaleza equilibrada. Sin mantener la distribución clases original. Ponemos Stratified Sampling y usamos random seed. 
Esta opción tiene un comportamiento aleatorio pero garantiza la distribución de clases (o de la variable categórica que elijamos).
Cuando fijo una semilla garantizo que la ejecución del nodo sea igual siempre para poder comparar los resultados que me aparezcan cada vez y poder arreglar errores.

## Decision Tree

Para realizar el aprendizaje utilizaremos el nodo Decision Tree Learner (que devolverá un árbol de decisión) y para realizar las pruebas usaremos Decision Tree Predictor, arrastramos estos nodos al Workflow Editor. Unimos la flecha superior del nodo Partitioning al Learner y la inferior al Predictor. El cuadrado azul del Learner irá conectado con el cuadrado azul del Predictor.
Nos aparece warning en Learner, hacemos doble click y mantenemos la  configuración por defecto. Ejecutamos. Para ver los resultados tenemos que darle a Clasified Data en el Predictor.
Aparece el 20% de los datos totales, el conjunto de test. La última columna será la predicción hecha.

Buscamos el nodo Scorer y lo arrastramos al Workflow Editor.
Lo unimos con la flecha de salida del Predictor.
Configuramos Scorer por defecto. Ejecutamos y vemos como resultado la matriz de confusión.

Podemos agrupar los nodos Decision Tree Learner y Decision Tree Predictor seleccionándolos > Click derecho > Create Metanode.

## Prism

Ahora cambiaremos el algoritmo de aprendizaje.
Buscamos los nodos Prism y Weka Predictor y los arrastramos al Workflow.
Los unimos con el Partitioning de igual forma que hemos en el caso anterior. Hacemos doble click en Prism para configurarlo, Prism tiene un error, Prism trabaja con variables categóricas. Necesitamos categorizar las variables. Para ello añadimos el nodo Auto-Binner, arrastrándolo al arco entre Partitioning y Prism. Configuramos Auto-Binner, eligiendo como Bin Naming la opción Borders y marcando "Replace target column(s)".

Para categorizar los datos de test de la misma forma, antes de pasárselos al nodo Weka Predictor utilizaremos el nodo Auto-Binner (Apply). Lo colocamos entre Auto-Binner y Weka-Predictor. Para ver los resultados utilizaremos un nodo Scorer de forma similar al caso anterior.

Observamos que el C4.5 es mejor que Prism. 

Agrupamos los nodos Auto-Binner, Auto-Binner (Apply), Prism y Weka Predictor.

## Tabla comparativa

Podemos ver las estadísticas de precisión en ambos nodos Scorer, el dato que nos interesa está en la fila Overall, columna Accuracy. Para crear una tabla comparativa necesitaremos añadir algunos nodos.

Buscamos Row Filter que conectamos con el puerto de abajo de un Scorer de arriba. En su configuración marcamos: Include rows by row ID, regular expression: Overall (que era el nombre de la fila).

Buscamos Column Filter, lo unimos con el Row Filter y en la configuración solo mantemos a la derecha.

Seleccionamos los dos Row Filter, copiamos y pegamos (así se mantendrá la configuración) al lado del otro Scorer y los conectamos con él.

Buscamos el nodo Concatenate (Optional in). Unimos su primera y segunda salida con los Column Filter.

Para unirlas y que quede bonito buscar el nodo Table Creator lo arrastramos al Workflow Editor. Hacemos doble click, seleccionamos en la cabecera de la columna y la llamamos "Algoritmo". En row0 ponemos C4.5 y en row1 ponemos Prism.

Añadimos el nodo Column Appender. Unimos la salida de Table Creator con la entrada superior de Column Appender y la salida de Concatenate con la inferior. 

Tenemos problema con los id ya que se llaman de forma diferente. En la configuración de Column Appender desmarcar identical row keys y marcamos generate row keys. Ejecutando este nodo podemos ver la comparativa.

## Validación cruzada

Vamos a resolver el mismo problema mediante el uso de validación cruzada. Para ello buscamos el nodo Cross Validation y lo arrastramos al Workflow Editor. Unimos la salida del nodo File Reader al Cross Validation. Duplicamos el nodo Scorer y lo unimos con el Cross Validation. Configuramos X Partitioner con 5 validaciones, Stratified samplig y usamos una semilla. En este caso se está usando otra vez un árbol de decisiones.

Copiamos y pegamos el nodo Cross Validation dentro de él borramos los nodos Decision Tree Learner y Decision Tree Predictor, que lo sustituiremos por la agrupación de nodos necesarios para el algoritmo Prism.

Después, duplicamos la parte de análisis y unimos el nodo Cross Validation con el nodo Scorer.

