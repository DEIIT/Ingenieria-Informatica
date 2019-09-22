# Tema 3: Gestión de Memoria

Todas las referencias a diapositivas se refieren a los apuntes usados por Patricia, profesora de SO de la UGR, pero que usa unas diapositiva con derechos de autor, luego me es imposible poner capturas o imágenes de estas.

## Jerarquía de memoria

Se basa en dos principios sobre memoria:

1. Menor cantidad -  acceso mas rapido (memoria cache)
2. Mayor cantidad - menor coste por byte (memoria principal)

Los elementos más frecuentes interesa almacenarlos en la memoria más rápida.


## Conceptos sobre caches

### Definición
Copia que puede ser accedida mas rapidamente que el original

### Idea

Hacer que los accesos frecuentes a parte de la memoria sean eficientes

Existen varias situaciones con la cache:

1. Acierto de cache: item necesario en la cache (no hay que acceder a memoria)
2. Fallo de cache: item no esta en cache, hay que realizar un acceso completo a memoria


Tiempo de Acceso Efectivo = probabilidad_acierto \* coste_acierto + probabilidad_fallo \* coste_fallo


Esto se puede realizar gracias a la localidad de los programas, es decir, es muy probable que si un programa necesita un elemento en una dirección de memoria N, más adelante necesite datos con direccion en un intervalo cercano a N.

## Objetivos generales de la gestion de memoria

1. Organización: como esta dividida

2. Gestión: esquemas, estrategias de asignacion, sustitucion y busqueda

3. Protección


## Asignación contigua y no contigua

### Asignación contigua

Los datos se asigna de forma secuencial en mamoria

### Asignación no contigua

Un programa puede estar repartido en distintas zonas de la memoria

#### Tipos

1. Paginación

2. Segmentación

3. Segmentación paginada

(Son explicadas más adelante)


## Intercambio (swapping)

Se basa en intercambiar el espacio de direcciones de un proceso que no se este ejecutando de memoria principal a un almacenamiento secundario. Ha de ser rapido para que no afecte a la gestión de memoria.

Se usara un intercambiador, con las siguientes reponsabilidades:

1. Seleccionar procesos para retirarlos de MP (memoria principal) (planificador a medio plazo)
2. Seleccionar procesos para incorporarlos a MP
3. Gestionar y asignar el espacio de intercambio




## Memoria virtual

### Organización

Se utiliza cuando el tamaño de programa, datos, pila y demas excede la cantidad de memoria física.

Se usan almacenamiento a dos niveles:

1. Memoria principal : partes necesarias en un momento dado

2. Memoria secundaria : espacio de direcciones completo

Es necesario saber que se encuentra en memoria, para saber que es necesario rescatar de la memoria secundaria.

Permite aumentar el grado de multiprogramación


## Unidad de Gestion de Memoria (MMU en ingles)

Es un dispositivo que traduce direcciones virtuales a direcciones físicas, es gestionado por el SO.

En el esquema más simple de MMU, el valor del registro base se añade a cada dirección generada por el proceso de usuario al mismo tiempo que es enviado a memoria.

El programa de usuario solo trata direcciones lógicas, nunca reales.

Pasos:

1. CPU genera direccion virtual
2. MMU comprueba la dirección
3. Si no es legal, genera excepcion
4. Si es legal, comprueba que esta cargada en memoria principal
5. En caso de no estar cargada en MP, genera excepcion para cargarla



## Paginación

El espacio de direcciones fisicas de un proceso no es contiguo

La memoria física se divide en bloques de tamaño fijo (marcos de paágina)

El espacio lógico se divide en bloques del mismo tamaño, denomidadas páginas (puede que no todas las páginas esten cargadas en memoria)

Existe una tabla de páginas por cada proceso.

Existe una tabla de ubucación en disco, una entrada por cada página, cada entrada almacena donde esta cada página en disco.

Existe una tabla de marcos de página, contiene informacion sobre cada marco de página, usada por el SO.

### Contenido de la tabla de páginas

1. Numero de marco
2. Bit de presencia: si esta a 1 nos dice si la página es valida y esta cargada en memoria principal

  ejemplo de página invalida : memoria reservada pero sin usar entre el heap y la pila

3. Bit de modificacion: nos dice si se ha modificado la página en memoria principal, para saber si tenemos que salvar en el disco secundario cuando se retire la página

 ejemplo: páginas de codigo, el codigo nunca se modifica, nunca lo vamos a tener que sobreescribir

4. Modo de acceso (bits de protección)


### Tratamiento de falta de página

Pasos:

1. Bloquear el proceso

2. Encontrar ubicación en disco de la página solicitada (usando tabla de ubicación en disco)

3. Encontrar marco libre, si no hubiera, se podria optar por desplazar una página de MP, es decir, intercambiarlas, si esto no ocurre o no es posible, se bloquea hasta que exista un marco libre en MP.

4. Inicia E/S a disco para cargarla (para traerla a memoria principal)

5. Actualiza tabla de páginas

6. Desbloquea el proceso

7. Reinicia la operación que genero la falta de página


### Implementación de la tabla de páginas (diapositiva 22)

Siempre se mantiene en memoria principal

Existe un registro base de la tabla de páginas (RBTP) que apunta a la tabla de páginas

Cada acceso a instruccion o dato requiere dos accesos a memoria.

Ejemplo:

		direccion virtual : 32 bits
		tam página : 4Kbytes (2^12 bytes)
		tam campo desplazamiento = 12 bits
		tam numero página virtual = 20 bits

		numero de páginas virtuales = 2^20 = 1 048 576

Problema: Se necesitan demasiadas páginas virtuales.

Solucion : Páginación multinivel


### Paginación multinivel

Se basa en paginar las tablas de páginas, es decir, tendremos una tabla que apuntara a otras tablas de páginas.

Ejemplo:
 Paginación a dos niveles, se mantiene la del nivel 1 siempre cargada, y el segundo nivel se cargan las partes necesarias


#### Ejemplo: Paginacion a dos niveles

Dividimos la tabla de páginas en partes del tamaño de una página

La direccion lógica se divide en :

1. Número de página (primer nivel)
		Número de página primer nivel -> p1 (k)
		Desplazamiento de página (nos marcara la de segundo nivel) -> p2 (n-k)
2. Desplazamiento de página (dentro del segundo nivel):  d (m bits)

Sintaxis:

		[p1 | p2 | d]

## Segmentación

División en segmentos independientes

Sintaxis:

	<numero_segmento, desplazamiento>


### Tabla de segmentos

Usa direcciones bidimensionales.

Cada entrada contiene:

1. Bit de presencia
2. Bit de modificación
3. Bit de protección
4. Base : direccion fiisca donde reside el segmento en memoria
5. Tamaño : longitud del segmento

La dirección es legal si:

		s < STLR (segmento menor que longitud de tabla de segmentos)



## Segmantacion paginada

Se combinan paginación y segmentación

El espacio de direcciones lo dividimos en segmentos, y cada segmento se gestiona con una tabla de páginas.

No todo el segmento tiene que cargarse en memoria principal, y las páginas del segmento no tienen poque estar contiguas en memoria.


## Memoria virtual

### Gestión

Gestiona la Memoria Virtual con paginación

Criterios de clasificacion respecto a:

1. Políticas de asignación: fija o variable
2. Políticas de busqueda (recuperación)

	* Paginación por demanda (cuando el proceso lo necesite se carga la página)
	* Paginación anticipada (SO prevee que páginas va a necisitar y las carga) (!= prepaginacion -> la prepaginacion es la carga inicial de páginas)

3. Políticas de sustitucion (reemplazo)

	* Sustitución local
	* Sustitución global



Independientemente de la política de sustitución, han de cumplir:

1. Páginas limpias frente a sucias
	* Se pretende reducir E/S a discos, las sucias hay que guardar copia

2. Páginas compartidas
	* Se pretende reducir el número de faltas de página

3. Páginas especiales
	* Algunos marcos pueden estar bloqueados (ej: buffer de E/S mientras realiza una transferencia)



### Influencia del tamaño de página

Páginas pequeñas:

* Aumento del número de páginas
* Aumento del número de transferencias, es decir, muchas operaciones de E/S
* Reducen la fragmentación interna

Páginas grandes:

* Carga mucha información no usada en MP
* Aumenta la fragmentación interna

Hay que buscar un equilibrio en el tamaño de las páginas


## Algoritmos de sustitución

Combinaciones de algoritmos:

* Asignación fija y sustitución local (número fijo de marcos, sustitución entre páginas del mismo proceso)

* Asignación variable y sustitución local (número variable de marcos de páginas, pero sustitucion solo entre sus páginas)

* Asignación variable y sustitución global (número variable marcos de páginas, sustitucion entre todas páginas de todos procesos)

### Algoritmos:

Se ejecutan cuando se produce falta de página y no hay espacio para más páginas

1. Óptimo

 * Sustituye la página que no se va a referencia en un futuro, o la que se referencie más tarde (es teorico, nunca se podra realizar, ya que necesitamos saber las páginas que vamos a referenciar en el futuro)

2. FIFO

	* Sustituye la página más antigua

3. LRU

	* Sustituye la página que fue objeto de la referencia más antigua, debemos almacenar cuando fue referenciada, y cuando quiera sustituirla, tiene que buscar por todas las páginas (es muy costoso)

4. Algoritmo de reloj (aproximacion LRU)

	* La idea es la misma, se escoge una de las que se referenciaron hace más tiempo (no tiene por que ser la última)

	* Cada página tiene asociada un bit de referencia R (lo pone a 1 el hardware (el MMU con la traducción de memoria lógica a física) )

		- Si una página tiene bit de referencia 1, ha sido usada al menos una vez

		- Tenemos un puntero a la página que se ha usado hace mas tiempo (la mas antigua, la que llevamos mas tiempo sin acceder)

	Pasos:

		1. Consulta la página del marco actual

		2. Si R = 0 : hace tiempo que no se ha usado (si no, tendria R = 1), la escoge para la sustitución e incrementa la posición del puntero.

			Si R = 1 : ponemos R = 0, e incrementamos el puntero a la siguiente posición



Orden de algoritmos (de mejor a peor)

1. Optimo (imposible de realizar)
2. LRU
3. Reloj
4. FIFO


## Comportamiento de los programas

Caracteristicas:

1. Localidad: conjunto de páginas frecuentemente consultadas

	* Tipos

		* Temporal: una posición referenciada recientemente tiene probabilidad alta de ser referenciada en un futuro próximo.

		* Espacial: si una posición de memoria ha sido referenciada, es altamente probable que las zonas adyacentes sean referenciadas en un futuro próximo.

2. Conjunto de trabajo (WS):

	* Conjunto de páginas que son referenciadas frecuentemente en un determinado intervalo de tiempo

	* El objetivo es mantener el conjunto de trabajo de un proceso en memoria

	* Propiedades:

		1. Un proceso segun se ejecuta, va variando sus conjuntos de trabajo

		2. Los conjuntos de trabajo son variables, según el estado del proceso

		3. Hay periodos de transición entre los conjuntos de trabajo, en los que tendre páginas de un WS anterior, hasta que cargo las del nuevo WS.

		4. Difieren unos de otros sustancialmente

	* Teoría del conjunto de trabajo:

		* Un proceso solo puede ejecutarse si tiene su conjunto de trabajo esta en memoria principal.

		* Una página no puede retirarse de memoria principal si esta en el conjunto de trabajo de un proceso.


## Hiperpaginacion (ver diapositivas para ejemplo)

Problema de la paginación:

* Si tenemos mucho grado de multiprogramación (muchos procesos en memoria), llegamos a un valor umbral en el que el numero de falta de páginas se dispara, y disminuye la productividad

* La CPU usa más tiempo en resolver faltas de página, que ejecutando procesos.


Formas de evitarla:

1. Asegurar que cada proceso tiene asignado un espacio en relación a su comportamiento (asignación de memoria dinámica) (algoritmos de asignación variables)

	* A cada proceso, se le asigna el espacio estrictamente necesario para que funcione correctamente

2. Actuar directamente sobre el grado de multiprogramación (cambiar número de procesos máximos cargados en memoria) (algoritmos de regulación de carga)

	* Ej: algoritmo de 50%, si la carga del sistema pasa de ese %, no se cargan mas procesos, y si se pasa del tope, se descargan procesos en memoria secundaria.




## Algoritmo basado en el modelo del WS (working set / espacio de trabajo)

En cada referencia se determina el conjunto de trabajo, es decir, las páginas referenciadas en el intervalo ]t -x , t] y solo esas páginas son mantenidas en MP

	* t = instante de tiempo actual
	* x = tiempo establecido por el algoritmo

El problema de este algoritmo es que necesita mucho coste de CPU.

## Algoritmo FFP (Frecuencia de Falta de Página)

Este algoritmo se basa en la eliminación de páginas que no se han referenciado entre el instante de falta de página actual, y el anterior instante de falta de página. Si dicho instante es pequeño, quiere decir que el espacio de memoria asignado a ese proceso es poco, y el nuevo espacio de trabajo (WS) es más grande que el anterior, asi que simplemente se asigna (si es posible) un nuevo marco de página al proceso. Si no es posible realizar esta operacion, se bloque el proceso hasta que quede algún marco disponible.


 Tc = instante de actual falta de página
 Tc-1 = instante de la anterior falta de página
 Z = conjunto de páginas referenciadas en un intervalo de tiempo
 R = conjunto de páginas residentes en MP

Si: Tc - Tc-1 > Y

    R(Tc, Y) = Z(Tc-1, Tc)

en otro caso

    R(Tc, Y) = R(Tc-1, Y) + Z(Tc)


Este algoritmo se comporta mal en etapas de transición entre WS, ya que añadiria páginas sin eliminar las antiguas, ya que el periodo de transicion impide considerarlas como innecesarias.



## Gestion de memoria en Linux

### Gestión de memoria a bajo nivel

#### struct_page

La página física es la unidad básica de gestión de memoria: struct_page

Contiene la información de un marco de página en memoria principal.

Esta formada por:

1. Flags
   * Página sucia (página inutil, puedes ser borrada o reutilizada)
   * Página bloqueada (no puede ser sustituida)
   * Otros flags de estado

2. Contador
   * Número de páginas que tienen asignado ese marco de página. Varios procesos pueden estar usando la misma página, este contador es usado para saber cuando es posible limpiar este marco de página. Un ejemplo de esto son las bibliotecas compartidas, o los segmentos de código de padre/hijo.

3. Direcciones virtuales y físicas


Una página puede ser usada por:

1. Cache de páginas. El campo mapping apunta al objeto representado  por addres_space.
2. Datos privados.
3. Proyección de tabla de páginas de un proceso
4. Espacio de direcciones de un proceso
5. Datos del kernel alojados dinámicamente
6. Código del kernel
7.	Interfaces para la asignación de memoria de páginas

Ejemplos:

`struct_page * alloc_pages(gfp_t gfp_mask, unsigned int order)`

Asigna 2^order páginas físicas contiguas y devuelve el puntero a la struct_page de la primera página, si falla devuelve NULL.

`unsigned long __get_free_pages(gfp_t gfp_mask, unsigned int order)`

Asigna 2^order páginas físicas contiguas y devuelve la dirección lógica de la primera página.



`void __free_pages(struct page *page, unsigned int order)`

`void free_pages(unsigned long addr, unsigned int order) `

Liberan 2^order páginas a partir de la estructura de la página o la dirección de memoria dada.




#### Zonas de memoria
El tipo gfp_t permite especificar el tipo de memoria mediante tres categorias de flags:

1. Modificadores de acción  (GFP_WAIT, GFP_IO)
2. Modificadores de zona  (GFP_DMA)
3. Tipos (especificación más abstracta)

Ejemplos de tipos:
1. GFP_KERNEL: solicitud de memoria para el kernel
2. GFP_USER: solicitud de memoria para el espacio de usuario de un proceso


## Cache de bloques.

### Organizacion

La asignación y liberación de estructuras de datos es una de las operaciones más comunes en el kernel de un SO.

Para agilizar la solicitud/liberación de memoria Linux usa el nivel de bloques. (No confundir cache con la cache de procesador)

El nivel de bloques actua como un nivel de cache de estructuras genérico:

1. Existe una cache para una de las distintas estructuras del SO. Por ejemplo:
   * task_struc cache
   * inode cache

	* Se basa en reutilizar la task_struct en la cache de un proceso que ha finalizado, en lugar de eliminar esta task_struct y crear una nueva para el nuevo proceso

2. Cada cache contiene múltiples bloques constituidos por una o más páginas físicas contiguas.

3. Cada bloque aloja estructuras del tipo correspondiente a la cache.

### Funcionamiento

Cada bloque puede estar en uno de los siguientes estados:

1. Lleno
2. Parcial
3. Vacio

Cuando el kernel solicita una nueva estructura lo hace siguiente forma:

1. Se satisface desde un bloque parcial
2. Si no es posible, se satisface a partir de un bloque vacio
3. Si no existe ningún bloque vacio, se crea uno nuevo y la solicitud se satisface con este nuevo bloque.


## Espacio de direcciones de proceso

Es el espacio de direcciones de los procesos ejecutandose en modo usuario. Linux usa memoria virtual (VM).

A cada proceso se le asigna un espacio de memoria plano de 32 o 64 bits unico. No obstante se puede compartir el espacio de memoria (CLONE_VM para hebras)

El proceso solo tiene permiso para acceder a determinados intervalos de direcciones de memoria, denominados áreas de memoria.


¿Que puede contener un area de memoria?

1. Mapa de memoria de la sección de codigo (text section)
2. Mapa de memoria de la sección de variables globales inicializadas (data section)
3. Mapa de memoria con una proyección de la página cero para variables globales no inicializadas (bss section)
4. Mapa de memoria con una proyección de la página cero para la pila de espacio de usuario



El espacio de direcciones de memoria de un proceso en linux se almacena con el descriptor de memoria, mm_struct:

```
struct mm_struct {
   struct vm_area_struct *mmap;  /*Lista de áreas de memoria (VMAs)*/
   struct rb_root mm_rb;
   /* árbol red-black de VMAs, para buscar un elemento
   concreto */
   struct list_head mmlist;  /* Lista con todas las mm_struct: espacios de
   direcciones */
   atomic_t mm_users; /* Número de procesos utilizando este espacio de
   direcciones */
   atomic_t mm_count; /* Contador que se activa con la primera referencia al
   espacio de direcciones y se desactiva cuando mm_users vale 0 */

   /*
   (cont. struct mm_struct)
    Límites de las secciones principales */
   unsigned long start_code; /* start address of code */
   unsigned long end_code; /* final address of code */
   unsigned long start_data; /* start address of data */
   unsigned long end_data; /* final address of data */
   unsigned long start_brk; /* start address of heap */
   unsigned long brk; /* final address of heap */
   unsigned long start_stack; /* start address of stack */
   unsigned long arg_start; /* start of arguments */
   unsigned long arg_end; /* end of arguments */
   unsigned long env_start; /* start of environment */
   unsigned long env_end; /* end of environment */
   /* Información relacionada con páginas */
   pgd_t *pgd; /* page global directory */
   unsigned long rss; /* pages allocated */
   unsigned long total_vm; /* total number of pages */
}
```


Cuando hacemos una hebra, apunta al mismo mm_struct, luego si liberamos a dicha hebra, tendremos que tener en cuenta a otras hebras con el mismo mm_struct, para no liberar memoria que la esten usando otros hilos.

Con hijos esto no ocurre, ya que con hijos no comparten el mismo espacio de direcciones

¿Como se asigna un descriptor de memoria?
   * Con un fork, se crea una copia

	* Con clone, se comparte el descriptor

¿Como se libera el descriptor de memoria?

   * El núcleo decrementa el contador mm_users incluido en el mm_struct, si llega a 0 se decrementa mm_count y si el mm_count vale 0, se libera la mm_struct en la caché


Un área de memoria (struct vm_area_struct) describe un intervalo contiguo del espacio de direcciones:

```
struct vm_area_struct {
struct mm_struct *vm_mm; /* struct mm_struct asociada que
representa el espacio de direcciones */
unsigned long vm_start; /* VMA start, inclusive */
unsigned long vm_end; /* VMA end , exclusive */
unsigned long vm_flags; /* flags */
struct vm_operations_struct *vm_ops; /* associated ops */
struct vm_area_struct *vm_next; /* list of VMA’s */
struct rb_node vm_rb; /* VMA’s node in the tree */
};
```


Utilizando el archivo /proc/<pid>/maps podemos ver las VMAs de un proceso

El formato del archivo es:

`start-end permisiion offset major:minor inode file`

Donde:

1. start-end
   * Dirección de comienzo y fin de la VMA

2. permission
   * Permisos de acceso al conjunto de páginas de la VMA

3. offset
   * Si la VMA proyecta un archivo, indica el offset de este, si no vale 0

4. major:minor
   * Se corresponden con los números major,minor del dispositivo en donde reside el archivo.

5. inode
   * Número de inodo del archivo

6. file
   * Nombre del archivo



¿Como se crea un intervalo de direcciones?
   * Usando do_mmap() para:
		1. Expandir una VMA ya existente

		2. Crear una nueva VMA que represente el nuevo intervalo de direcciones

   * `unsigned long do_mmap(struct file *file, unsigned long addr, unsigned long len, unsigned long prot, unsigned long flag, unsigned long offset)`


¿Como se elimina un intervalo de direcciones?
   * Usando do_munmap()
   * `int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)`


Linux implimenta una paginación multinivel de 3 niveles

Las direcciones virtuales deben convertirse a direcciones físicas mediante tablas de páginas. En linux tenemos 3 niveles de tablas de páginas:

1. Tabla de páginas de más alto nivel, es el directorio global de páginas (PGD, page global directory) que consta de un array de tipo pgd_t

2. Las PGD apuntan a entradas de la tabla de páginas de segundo nivel (PMD, page middle directory)  que consta de un array de tipo pmd_t

3. Las entradas del PMD apuntan a entradas en la PTE. El último nivel es la tabla de páginas y contiene entradas de tabla de páginas del tipo "pte_t" que apuntan a páginas físicas: struct_page


## Caché de páginas

### Concepto

La cache de páginas esta constituida por páginas físicas de RAM, y los contenidos se corresponden a bloques físicos de disco

El tamaño de la caché de páginas es dinámico

El dispositivo sobre el que se realiza la tecnica de caché se denomina almacén de respaldo

L/E de datos de/a disco

Fuentes de datos para la cache:
   * Archivos regulares
   * Dispositivos
   * Archivos proyectados en memoria

Se basa en:
   * De disco, cogemos los datos y los mandamos a caché en MP, la L/E se realizara en MP, minimizando los tiempos de L/E.

El objetivo es minimizar el tiempo de E/S o E/L en los archivos

Si solo leo una vez, no optimizamos nada, incluso malgastamos en duplicados



### Seleccion de víctimas de página

#### LRU

Requiere mantener la información de cuando se accede a cada página y seleccionar las páginas más antiguas. El problema es el acceso a archivos una única vez

Linux soluciona el problema usando dos listas pseudo-LRU: active list e inactive list

1. active list
	* No pueden ser seleccionadas como víctimas y se añaden páginas accedidas solamente si residen en la inactive list



3. inactive list
   * Pueden ser seleccionadas como victimas

La cola de la inactive list serán los que llevan tiempo sin referenciar, al leer una página de memoria, metemos la página en la inactive list y la más antigua (la primera de la lista) la liberamos (eliminarmos la primera página de la lista, e insertamos al final la nueva página)

Si el bloque que hay en una entrada de la inactive list se llama dos veces, pasa a la  active list, y si la active list, se llena, el ultimo de la active list pasa a la inactive list.


### Operaciones

1. Una página puede contener varios bloques de disco, posiblemente no contiguos

2. La caché de páginas en linux usa una estructura para gestionar entradas de caché y operaciones de E/S de páginas: addres_space

3. L/E de páginas en caché

4. Hebras de estructura retardada.








[![Creative Commons License][image-1]][1]  
This work is licensed under a [Creative Commons Attribution 4.0 Unported License][1].

[1]:    http://creativecommons.org/licenses/by/4.0/deed.en_US

[image-1]:    http://i.creativecommons.org/l/by/4.0/80x15.png


Antonio David Villegas Yeguas
