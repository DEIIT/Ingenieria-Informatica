# Tema 4: Gestión de archivos

## Interfaz de los sistemas de archivo

### Concepto de archivo

Un archivo es una colección de información relacionada y almacenada en un dispositivo de almacenamiento secundario.


Un archivo se almacena de forma contigua en el espacio de direcciones lógicas

#### Estructura interna (lógica)

* Secuencia de bytes
* Secuencia de registros de longitud fija
* Secuencia de registros de longitud variable


#### Tipos

* Regulares
* Directorios
* De dispositivo

#### Formas de acceso

* Secuencial
* Aleatorio
* Otros


#### Atributos (metadatos)

* Nombre: Única informacion en formato legible
* Tipos
* Localización (en dispositivo de almacenamiento)
* Tamaño
* Protección (permisos)
* Tiempo, fecha e identificación del usuario


#### Operaciones sobre archivos

1.	Gestión
	- Crear
	- Borrar
	- Renombrar
	- Copiar
	- Establecer y obtener atributos

2. Procesamiento
	- Abrir y cerrar
	- Leer
	- Escribir

## Estructura de directorios

Colección de nodos conteniendo información acerca de todos los archivos (Organización)


La organización de los directorios debe proporcionar: 

- Eficiencia: Localización rápida de un archivo
- Denominación: adecuada a los usuarios (mismo nombre para diferentes archivos, mismo archivo puede tener varios nombres)

- Agrupación: agrupar los archivos de forma lógica según sus propiedades


### Tipos de estructuras de directorios

#### En árbol

- Necesidad de búsquedas eficientes
- Posibilidad de agrupación
- Directorio actual
- Nombres de camino absolutos y relativos


#### En grafo

- Compartición de subdirectorios y archivos
- Más flexibles y complejos



## Protección

Consiste en controlar el acceso a archivos por parte de los usuarios en:

- Lo que puede hacerse
- Por quiénn puede realizarse


### Listas y grupos de acceso

La principal solución a la protección es hacer el acceso dependiente a la identificativo del usuario

Las listas de acceso de usuarios individuales tienen el problema de la longitud

Solución con clases de usuario:

- Propietario
- Grupo
- Público


Propuesta alternatica
- Asociar un password con el archivo

Problemas:
- Recordar datos
- Si solo se asocia un password, o se puede acceder a todo, o a nada



## Semánticas de consistencia

Especifica que ocurre si dos programas abren un archivo y lo usan (tanto lectura como escritura) a la vez.

### Ejemplos de como solucionarlo:

#### Semántica de Unix

Se tiene una única copia del archivo en memoria principal, y todos los programas que usen ese archivo, trabajan sobre la misma copia en memoria principal.

La escritura es directamente observable.

Existe un modo en el que los usuarios comparten el puntero actual de posición de escritura/lectura de un archivo (hebras e hijos).


#### Semanticas de sesión

Sistemas de archivos distribuidos (no comparten memoria).

Si se abre un archivo, se trabaja desde la máquina en la que se abre.

La escritura de un archivo no es directamente observable.

Cuando un archivo se cierra sus cambios solo se observan en sesiones posteriores.


#### Archivos inmutables

Cuando un archivo se declara compartido, no se puede modificar.


## Funciones básicas del Sistema de Archivos (SA)

Tener conocimiento de todos los archivos.

Controlar la compartición de archivos y forzar su protección.

Gestionar el espacio del sistema de archivos:
   - Asignación/liberación del espacio en disco

Traducir las direcciones lógicas del archivo en direcciones físicas del disco.
	- Los usuarios especifican las partes que quieren leer/escribir en términos de direcciones lógicas relativas al archivo.


## Diseño software del SA

Un sistema de archivos presenta dos problemas de diseño diferentes:

   1. Definir cómo deve ver el usuario el SA
      * Definir un archivo y sus atributos
      * Definir operaciones permitidas sobre un archivo
		* Definir la estructura de directorios

   2. Definir los algoritmos y estructuras de datos que deben crearse para establecer la correspondencia entre el sistema de archivos lógico y los dispositivos fisicos donde se almacenan.



## Estructura del SA

Organizacion en niveles (capas):

```

                dispositivo
                     ^
                     |
                control E/S
                     ^
                     |
         sistemas de archivos basico
                     ^
                     |
      modulo de organizacion de archivos
                     ^
                     |
         sistema logico de archivos
                     ^
                     |
                 programas

```

Por eficiencia, el SO mantiene una tabla indexada (por descriptor de archivo) de archivos abiertos.

Bloque de control de archivo : estructura con la información de un archivo.


## Metodos de asignación de espacio

### Contiguo

Cada archivo ocupa un conjunto de bloques contiguos en disco.

#### Ventajas: 

1. Sencillo: solo necesita la localización de comienzo (n bloque) y la longitud.

2. Buenos tanto al acceso secuencial como el directo.


#### Desventajas:
1. No se conoce inicialmente el tamaño.

2. Derroche de espacio (problema de asignación dinámica -> fragmentación externa)

3. Los archivos no pueden crecer, a no ser que se realice compactación -> ineficiente

#### Asociación lógica a física

Supongamos bloques de 512 bytes:

- direccion logica (DL)/512 -> C(cociente), R(resto)

- bloque a acceder -> C-esimo

- desplazamiento en el bloque -> R


### No contiguo - Enlazado

Cada archivo es una lista enlazada de bloques de disco, los cuales pueden estar dispersos.

#### Ventajas:

1. Evita fragmentación externa.

2. El archivo puede crecer dinámicamente cuando hay bloques de disco libres -> no es necesario compactar.

3. Basta almacenar el puntero al primer bloque del archivo.


#### Desventajas:

1. Acceso directo no efectivo, necesita ir avanzado por los bloques del archivo, hasta llegar al que necesita.

2. Espacio requerido para los punteros de enlace.
	- Solución: Agrupaciones de bloque (clusters)

3. Seguridad por la pérdida de punteros.
	- Solución: lista doblemente enlazada (overhead)


#### Asociación lógica a física (dirección = 1 byte)

- Dirección lógica: (DL)/511 -> C(cociente), R(resto)

- Bloque a acceder -> C-ésimo

- Desplazamiento en el bloque -> R+1


#### Tabla de asignacion de archivos (tabla FAT) : variación del método enlazado

Los punteros los sacamos a una tabla aparte, indexada por el número de bloques físicos del SA.

Esa tabla (tabla FAT) se almacena en una sección del disco al comienzo de la partición

Contiene una entrada por cada bloque del disco y esta indexada por número de bloque de disco


Mejora el acceso directo, no necesita cargar las páginas anteriores, se mueve por la tabla que esta en memoria principal, y se trae el bloque de datos que necesite una vez encontrado.


Principales problemas: si se rompe la tabla FAT, perdemos toda la informacion del SA.


### No contiguo - Indexado

Todos los punteros a bloques estan juntos en una localización concreta: bloque índice.

El directorio tiene la localización a este bloque índice y cada archivo tiene asociado su propio bloque índice.

Para leer el i-ésimo bloque buscamos el puntero en la i-ésima entrada del bloque índice.

#### Ventajas:

1. Buen acceso directo
2. No produce fragmentación externa

#### Desventajas:

1. Posible desperdicio de espacio en los bloques índices

2. Tamaño del bloque índice. Soluciones:
	* Bloques índice enlazados

   * Bloques índice multinivel
      
		- Problema: acceso a disco necesario para recuperar la direccion del bloque para cada nivel de indexación.
	
		- Solución: mantener algunos bloques índices en memoria principal.

   * Esquema combinado(Unix)
		- Se basa en una tabla i-nodo con entradas a bloques de datos, de la 1 a 10 (1 a 12 en linux) entradas directas a datos, en la página 11 a un bloque índice de nivel 1, en la página 12 a un bloque índice de 2 niveles, en la página 13 a un bloque índice de 3 niveles.


## Gestión del espacio libre

El sistema mantiene una lista de los bloques que están libres: lista de espacio libre

La FAT no necesita ningún método de gestión de espacio libre, la propia FAT almacena que bloques están libres.

A pesar de su nombre, la lista de espacio libre tiene diferentes implementaciones:

   1. Mapa o vector de bits:
      
		- Un bit por cada bloque o cluster de archivos, 0 bloque libre, 1 bloque ocupado.

      - Fácil encontrar bloque/s libre/s consecutivos.

      - Ineficiente si no se mantiene en memoria principal.


   2. Lista enlazada:

      - Enlaza los bloques libres del disco, teniendo un puntero al primer bloque, en cada bloque libre se almacena la dirección del siguiente bloque libre.

      - No derrocha espacio, el espacio usado (para información de siguiente bloque libre) es espacio no utilizado.

      - Relativamente ineficiente -> no es normal atravesar bloques vacíos.

   3. Lista enlazada con agrupación

      - Misma idea que lista enlazada, solo que en un bloque libre tengo información de los n siguientes bloques libres.

      - Obtener información de muchos bloques libres es más rápido.

   4. Cuenta
      
		- Cada entrada de la lista: una dirección de bloque libre y un contador con el número de bloques libres que le sigue.



## Implementación de Directorios.

Contenido de una entrada de directorio. Casos:

   1. Toda en la entrada de información del archivo:
      
		- Nombre_archivo + atributos + direccion de bloques de datos (como MS-D0S)

   2. Linux, usando i-nodos:
      
		- Nombre_archivo + puntero a estructura de datos (linux)

      - Se pone el inodo + nombre_archivo, y el inodo guarda la información del archivo.


Cuando se abre un archivo:

   1. El SO busca en su directorio la entrada correspondiente.

   2. Extrae sus atributos y la localización de sus bloques de datos y los coloca en una tabla de memoria principal.

   3. Cualquier referencia posterior usa la información de dicha tabla.



Implementación de archivos compartidos (o enlace):

1. Enlaces simbólicos:
	
	- Se crea una nueva entrada en el directorio, de tipo enlace y se almacena el camino de acceso absoluto o relativo del archivo a enlazar.

	- Se puede usar en entornos distribuidos

	- Gran número de accesos a disco

2. Enlaces absolutos (o hard):
	
	- Se crea una nueva entrada en el directorio y se copia la dirección de la estructura de datos con la información del archivo.

	-Problema al borrar los enlaces: solución -> Contador de enlaces


## Distribución del Sistema de Archivos

Los sistemas de archivos se almacenan en discos que puedan dividirse en una o más particiones.

Formateo del disco:

- Físico: pone los sectores (cabecera y código de corrección de errores) por pista

- Lógico: escribe la información que el SO necesita para conocer y mantener los contenidos del disco.

Bloque de arranque para inicializar el sistema localizado por bootstrap.

Métodos necesarios para detectar y manejar bloques dañados.


## Recuperación

Como los archivos y directorios se mantienen tanto en MP como en disco, el sistema debe asegurar que un fallo no genere pérdida o inconsistencia de datos.

Existen distintas formas de comprobar esto:
   
1. Comprobador de consistencia:
	- Compara los datos en la estructura de directorios con los bloques de datos en disco y trata cualquier inconsistencia.

	- Más fácil en listas enlazadas que con bloques índices (listas enlazadas mejores que bloques índices)

2. Usar programas del sistema para realizar copias de seguridad de los datos de disco a otros dispositivos y de recuperación de los archivos perdidos


## Implementación de la gestión de archivos

i-nodo: representación interna de un archivo.

Un archivo tiene asociado un único i-nodo, aunque éste puede tener distintos nombres (enlaces)

Los i-nodos son creados al crear el SA.

Si un proceso:
   
- Crea un archivo -> asigna un i-nodo (si no hay inodos no se puede crear el archivo)

- Referencia a un archivo por su nombre -> se analizan los permisos y se lleva el i-nodo a memoria principal hasta que se cierre.

El número de i-nodos es limitado, queda marcado al crear el SA.

El i-nodo no contiene el nombre del archivo, el nombre va en los metadatos (permite enlaces, con distinto nombre pero mismo archivo).


## Sistema de Archivos

El SO implementa al menos un SA estandar o nativo.

En linux: ext2, ext3 y ext4.

Necesidad de dar soporte a otros SA (FAT, s5fs, etc) el kernel incluye una capa entre procesos de usuario (o la biblioteca estándar) y la implementación del SA -> Sistema de Archivos Virtual (VFS - Virtual File System).


Linux abstrae el acceso a archivos y a los SA mediante una interfaz virtual.

Flujo de operaciones/datos por las distintas partes del sistema en una llamada al sistema de escritura (write).

La forma de escribir dependera del SA usado.


### Tipos de SA


1. SA basados en disco
   
	- Forma clasica de almacenar archivos en medios no volátiles (exfat extN, FAT, etc)

2. SA Virtuales

   - Generados por el kernel y constituyen una forma simple de permitir la comunicación entre programas y usuarios.

	- Están en MP, no usan espacio en disco.

3. SA en red

   - Permite acceder a datos a traves de la red.



## Modelo de archivo común

Para un programa de usuario, un archivo se identifica por un descriptor de archivo(número entero usado como indice en la tabla de descriptores que identifica el archivo en las operaciones relacionadas con él).

El descriptor lo asigna el kernel cuando se abre el archivo, es válido solo dentro del proceso.

Dos procesos distintos pueden usar el mismo descriptor, pero no apuntan al mismo archivo (excepto si es con herencia padre-hijo).

Un i-nodo es la estructura asociada a cada archivo y directorio y contiene sus metadatos.

## Contenido de un i-nodo

1. Identificador del propietario
2. Tipo de archivo (regular, directorio, cauce, dispositivo, link). Si es 0, indica que el i-nodo esta libre
3. Permisos de acceso
4. Tiempos de acceso
5. Contador de enlaces
6. Tabla de contenidos para las direcciones de los datos en disco del archivo
7. Tamaño


## Acceso a archivos

Ejemplo: Acceso al archivo /usr/ast/correo

Pasos:

   1. Lee el inodo de **usr** en la tabla de inodos de / (*) (si no existe la entrada correspondiente a **usr**, da error, path incorrecto)

   2. Busca el número de i-nodo leido.

   3. Lee desde disco (*) la dirección del bloque de datos de **/usr** (supongamos que esta en el bloque N).

   4. Trae a disco (*) el bloque N.

   5. Busca en el bloque N una entrada de i-nodo que coincida con **ast**.

   6. Trae el i-nodo (*) que ha encontrado que coincide con **ast**, y lee que bloque necesita para **ast** (suponemos que necesita el bloque M).

   7. Trae el bloque M (*) de memoria, y busca el la entrada **correo**

   8. Una vez encontrada, la trae a MP(*).


   Si en cualquier caso no encuentra un dato en las distintas entradas a tablas, da error de PATH incorrecto.

   Necesitamos 6 accesos a MP -> cada * = acceso a MP


## Estructura VFS

VFS es orientado a objetos, consta de archivos y SA, que necesita gestionar y abstraer.

Se representa a un archivo y a un SA con una familia de estructuras en C.

Existen 4 tipos de objetos primaros del VFS:

1. Objeto superblock: representa a un SA montado

2. Objeto i-node : representa a un archivo (cualquier tipo)

3. Objeto dentry: representa a una entrada a un directorio

4. Objeto file : representa a un archivo abierto y es una estructura por proceso, las anteriores son de sistema.


Cada uno de los objetos tiene un vector de **operations** que contiene las funciones de cada SA. Se usa para distinguir de las llamadas de SA, por ejemplo, el write de extN es distinto a write de FAT.

Estas funciones describen los métodos que el kernel invoca sobre los objetos primarios.

* super_operations : métodos que el kernel puede invocar sobre un SA. Ejemplo: write_inodo() y sync_fs()

* inode_operations : métodos que el kernel puede invocar sobre un archivo concreto. Ejemplo : create() y link()

* dentry_operations : métodos que el kernel puede invocar sobre una entrada de directorio. Ejemplo: d_compare() y d_delete()

* file_operations : métodos que un proceso puede invocar sobre un archivo abierto. Ejemplo: read() y write()



Cada SA tiene una estructura **file_system_type** para marcar el SA y sus capacidades.

Cada punto de montaje esta representado por la estructura **vfsmount**, para contener la información sobre punto de montaje y flags sobre ese punto de montaje.

Finalmente existen dos estructuras por proceso que describen el SA y archivos asociados:
   
1. **fs_struct** 
2. **file_struct**


## Sistemas de archivos ext2

Divide el disco duro en un conjunto de bloques de igual tamaño donde se almacenan los datos de los archivos y de administración.

El elemento central de ext2 es el "grupo de bloques" compuesto de la siguiente forma:

`[super bloque (1 bloque) | group descriptors (k bloques) | data bitmap (1 bloque) | inode bitmap (1 bloque) | inode tables (n bloques) | grupo de bloques (m bloques) ]`


El super bloque esta duplicado en todos los bloques por seguridad, si se pierde ese bloque perdemos todos los datos.


Cada SA consta de un gran número de grupos de bloques secuenciales.

Boot sector (boot block) almacena información importante de la BIOS y programa de arranque.

Cuando un SA se monta, el superbloque, sus datos se almacenan en MP.

## Descripción de un grupo de bloques

1. Superbloque (superblock): Estructura central para almacenar meta-información del SA.

2. Descriptores de grupo (group descriptors): Contienen información que refleja el estado de grupos de bloques individiales del SA, por ejemplo, el número de bloques libres e i-nodos libres.

3. Mapa de bits de bloques de datos y de i-nodos (data bitmap e i-node bitmap): contienen un bit por bloque de datos y por i-nodo respectivamente para indicar si están libres o no.

4. Tabla de i-nodos (i-node tables): contiene todos los i-nodos del grupo de bloques. Cada i-node mantiene los metadatos asociados con un archivo o directorio del SA.


## Estructuras en el dispositivo

Estructura para el superbloque:

`struct ext2_super_block`


Estructura para el descriptor de grupo:

`struct ext2_group_desc`


Estructura para el i-nodo:

`struct ext2_inode`


Estructura para directorios y archivos:

`struct ext2_dir_entry_2`



## Información sobre los bloques de un archivo

Linux usa un método de asignación de bloques no contiguo y cada bloque de SA se identifica con un número.

En el inodo se almacenan 12 direcciones directas a BD (bloques de datos), un primer nivel de indexacion, un segundo nivel de indexación, y un tercer nivel de indexación (si son necesarios).

En total, 15 entradas.

## Montaje y desmontaje de SA

La llamada al sistema **mount** conecta un sistema de archivos existente y la llamada **umount** lo desconecta

El núcleo tiene una tabla de montaje con una entrada por cada sistema de archivos montado:

- Número de dispositivo que identifica el SA montado
- Puntero a un buffer que contiene una copia del superbloque
- Puntero al i-nodo raíz del SA montado
- Puntero al i-nodo del directorio del punto de montaje








[![Creative Commons License][image-1]][1]  
This work is licensed under a [Creative Commons Attribution 4.0 Unported License][1].

[1]:    http://creativecommons.org/licenses/by/4.0/deed.en_US

[image-1]:    http://i.creativecommons.org/l/by/4.0/80x15.png

Antonio David Villegas Yeguas
