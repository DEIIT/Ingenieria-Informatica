# §1 - ENUNCIADO

Dado un conjunto de 6 enteros sacados aleatoriamente del conjunto:

\begin{center}
$R=\{1,2,3,4,5,6,7,8,9,10,25,50,75,100\}$
\end{center}

podemos plantearnos conseguir otro entero aleatorio de 3 cifras usando para ello sólo las operaciones de suma, resta, producto y división entera, teniendo encuenta que sólo se puede usar cada número (de los 6) como mucho una vez, aunque es posible que no todos se usen para conseguir el número de 3 cifras.

**Ejemplo:**

Se sacan aleatoriamente del conjunto $C$ los números:

\begin{center}
$6,8,10,9,4,75$
\end{center}

y se pide que con ellos se consiga el número (también aleatoriamente generado):

\begin{center}
$835$
\end{center}

Una posible solución (que no tiene por qué ser única) es ésta:

> $\frac{8}{4}=2$
>
> $9+2=11$
>
> $75\cdot11=825$
>
> $825+10=835$

Como veis, se han usado sólo 5 de los 6 números y sin usar ninguno más de una vez (el dígito $6$ no ha hecho falta en esta solución) y sólo operaciones de $+$, $\cdot$ y $/$ (la resta en este caso tampoco ha hecho falta) para conseguir llegar al número exacto.
No pueden tenerse resultados temporales negativos, es decir, pasos intermedios como $4-8=-4$ y usar ese $-4$ no están permitidos, como tampoco está permitido hacer una división no exacta, es decir, no puede hacerse $\frac{75}{11}$ y redondear.

Obviamente, puede que sea imposible que con 6 números aleatorios se pueda conseguir el aleatorio de 3 cifras y en ese caso hay dos salidas:

- **La más simple:** Que el algoritmo diga que no hay solución.
- **La más interesante:** Que la salida del algoritmo sea conseguir el número más próximo posible al que nos piden.

Evidentemente, en la generación aleatoria podría haber repeticiones y salir, p.ej., estos 6 números:

\begin{center}
$1,3,5,3,100,5$
\end{center}

donde el $3$ y el $5$ aparecen 2 veces.
No pasa nada, esto es válido, simplemente que para alcanzar la solución contáis con dos treses y dos cincos, nada más, pero sigue estando presente la restricción de la no repetición, es decir, que contáis con 6 números: un $1$, dos $3$, dos $5$ y un $100$, es decir, se puede usar cada número de la serie SÓLO UNA VEZ (como mucho, una vez el $1$, una vez el primer $3$, una vez el primer $5$, una vez el segundo $3$, una vez el $100$ y una vez el segundo $5$).

Como curiosidad, indicar que existen combinaciones de 6 números de $C$ con las que puede obtenerse cualquier número de 3 cifras (y sería interesante pensar en cómo podrían conseguirse tales combinaciones).
P.ej., a partir del conjunto $C={2,6,7,9,50,75}$ se puede conseguir cualquier número de 3 cifras.

El reto consiste en crear un algoritmo para resolver el problema de las cifras.
La idea es que deis (si es posible) un algoritmo (secuencia de pasos) para resolver el problema.
No quiero un programa, quiero una solución que haga uso de vuestra capacidad de abstracción.
Ánimo con las soluciones.
Veamos en qué punto está vuestra creatividad y vuestra capacidad de abstracción de cara a resolver un problema.
Es un reto intelectualmente interesante para un ingeniero informático.

\pagebreak

# §2 - CONSIDERACIONES PREAMBULARES

Dados seis números aleatorios tomados de una reserva formada por nueve números de una cifra, cuatro de dos y uno de tres, buscamos encontrar, mediante las cuatro operaciones elementales, un número de 3 cifras.
Debido a que 9 de cada 14 números ($~64.28%$) tomados en cada caso van a ser de una cifra, parece sensato comenzar buscando los valores más aproximados a la solución.

Dado un valor obtenido como aproximación al valor objetivo de tres cifras, no importa si la diferencia entre ambos es positiva o negativa, por lo que la definiremos como $|objetivo-valor|$.

Dados dos valores iguales, es posible que para llegar a uno se hayan utilizado más cifras que para el otro ($4=2\cdot2$ y $4=2+1\cdot2$).
Consideraremos más cercano a la solución el valor que menos valores haya utilizado para ser calculado, ya que la mayor cantidad de valores restantes le ofrece una mayor probabilidad de llegar al número objetivo.

Tras la primera aproximación obtenemos una diferencia entre el valor objetivo y el valor aproximado.
Para simplificar los cálculos operaremos con esta diferencia y los valores restantes.
Es importante tener en cuenta que, tras la primera aproximación, sí se pueden obtener valores negativos.

\pagebreak

# §3 - DESARROLLO DEL ALGORITMO

## §3.1 - Resumen esquemático

Para intentar resolver este problema vamos a utilizar un algoritmo que busque aproximarse al valor objetivo lo más rápido posible en su primer paso.
De esta forma, esperamos simplificar las siguientes operaciones buscando aproximaciones a un objetivo más pequeño con un menor número de valores.

**VARIABLES Y CONSTANTES:**

- **Reserva:** $R=\{1,2,3,4,5,6,7,8,9,10,25,50,75,100\}$.
- **Candidatos:** $C=\{Seis\ valores\ elegidos\ aleatoriamente\ de\ la\ reserva\}$.
- **Objetivo:** $O\in\mathbb{N}:101\leq O\leq999$.
- **Aproximación:** Tipo de dato abstracto utilizado para buscar aproximaciones al objetivo.

**INICIO:**

- Cálculo de las sumas, diferencias, productos y cocientes de todas las combinaciones de candidatos.
- Si no se ha llegado al objetivo:
  - Ordenación de todas las aproximaciones por cercanía a la solución.
  - **ITERATIVO:** Para cada aproximación obtenida:
    - Cálculo de las sumas, diferencias y cocientes de todos los productos y candidatos restantes.
    - Si no se ha llegado al objetivo:
      - Ordenación de todas las aproximaciones por cercanía a la solución.
      - Salto a ITERATIVO con los candidatos restantes.
  - **FIN ITERATIVO**
- Si se ha llegado al objetivo:
  - Devolver las operaciones realizadas para llegar a él.
- Si no se ha llegado al objetivo:
  - Devolver la aproximación más cercana al objetivo y las operaciones realizadas para llegar a él.

**FIN**

## §3.2 - TDA "Aproximación"

El tipo de dato abstracto `Aprox` está compuesto por tres atributos:

- `int valor`: Entero cuyo valor es el de la aproximación.
- `int candidatos[]`: Vector dinámico que almacena, de forma ordenada, los candidatos (no los valores intermedios) utilizados para el cálculo de `valor`
- `string operaciones`: Cadena de caracteres que almacena las operaciones utilizadas para llegar a `valor`.

Un ejemplo de un `Aprox` sería el siguiente:

```cpp
valor = 536;
candidatos = {0, 2, 3, 4}
operaciones = "(4 * 9) + (10 * 50)"
```

Consideramos que dos `Aprox` son iguales si tienen el mismo `valor` y `candidatos`.

## §3.3 - Cálculo de las sumas, diferencias, productos y cocientes de todas las combinaciones de candidatos

Para calcular las sumas, diferencias, productos y cocientes de todas las combinaciones de números crearemos cuatro matrices cuadradas de tamaño $candidatos\ restantes$ en las que insertaremos los resultados de todas las respectivas operaciones con las diferentes combinaciones de candidatos.
Debido a las restricciones del reto y para no utilizar más memoria de la necesaria, suprimimos todos los valores de la diagonal principal y todos los que quedan a su derecha.
De esta forma, obtenemos la siguiente plantilla de matriz ($\times$ indica que la posición es válida y $\otimes$, que no lo es):


\begin{center}
$\begin{matrix}
[0] & \times  & \times  & \times  & \times  & \times  & \times \\
[1] & \otimes & \times  & \times  & \times  & \times  & \times \\
[2] & \otimes & \otimes & \times  & \times  & \times  & \times \\
[3] & \otimes & \otimes & \otimes & \times  & \times  & \times \\
[4] & \otimes & \otimes & \otimes & \otimes & \times  & \times \\
[5] & \otimes & \otimes & \otimes & \otimes & \otimes & \times \\
    &   [0]   &   [1]   &   [2]   &   [3]   &   [4]   &   [5]  \\
\end{matrix}$

Modelo de matriz con índices ordenados de menor a mayor
\end{center}

\pagebreak

Conocida la forma de la matriz, conocemos los valores de cada uno de sus elementos (donde los números de cada elemento representan, respectivamente, el índice de filas y columnas):

\begin{center}
$\begin{matrix}
\times  & \times  & \times  & \times  & \times  & \times \\
1+0     & \times  & \times  & \times  & \times  & \times \\
2+0     & 2+1     & \times  & \times  & \times  & \times \\
3+0     & 3+1     & 3+2     & \times  & \times  & \times \\
4+0     & 4+1     & 4+2     & 4+3     & \times  & \times \\
5+0     & 5+1     & 5+2     & 5+3     & 5+4     & \times \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
\times  & \times  & \times  & \times  & \times  & \times \\
1-0     & \times  & \times  & \times  & \times  & \times \\
2-0     & 2-1     & \times  & \times  & \times  & \times \\
3-0     & 3-1     & 3-2     & \times  & \times  & \times \\
4-0     & 4-1     & 4-2     & 4-3     & \times  & \times \\
5-0     & 5-1     & 5-2     & 5-3     & 5-4     & \times \\
\end{matrix}$

Matriz de sumas (izquierda) y de diferencias (derecha)

$\begin{matrix}
\times  & \times  & \times  & \times  & \times  & \times \\
1\cdot0 & \times  & \times  & \times  & \times  & \times \\
2\cdot0 & 2\cdot1 & \times  & \times  & \times  & \times \\
3\cdot0 & 3\cdot1 & 3\cdot2 & \times  & \times  & \times \\
4\cdot0 & 4\cdot1 & 4\cdot2 & 4\cdot3 & \times  & \times \\
5\cdot0 & 5\cdot1 & 5\cdot2 & 5\cdot3 & 5\cdot4 & \times \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
\times      & \times      & \times      & \times      & \times      & \times \\
\frac{1}{0} & \times      & \times      & \times      & \times      & \times \\
\frac{2}{0} & \frac{2}{1} & \times      & \times      & \times      & \times \\
\frac{3}{0} & \frac{3}{1} & \frac{3}{2} & \times      & \times      & \times \\
\frac{4}{0} & \frac{4}{1} & \frac{4}{2} & \frac{4}{3} & \times      & \times \\
\frac{5}{0} & \frac{5}{1} & \frac{5}{2} & \frac{5}{3} & \frac{5}{4} & \times \\
\end{matrix}$

Matriz de productos (izquierda) y de cocientes (derecha)
\end{center}

Mediante el uso de este tipo de matrices nos aseguramos de considerar para la solución aquellas aproximaciones que, en el árbol de operaciones creado por el algoritmo, no tomen valores directamente de las hojas sino de operaciones ramificadas.

\begin{center}
\begin{tikzpicture}[grow'=up]
\Tree [.$825+10=835$ [.$75+11=825$ [.$9+2=11$ [.$\frac{8}{4}=2$ [.$4$ ] [.$8$ ] ] $11$ ] $75$ ] $10$ ]
\end{tikzpicture}
\begin{tikzpicture}[grow'=up]
\Tree [.$28\cdot13=364$ [.$20+8=28$ [.$\frac{100}{5}=20$ [.$5$ ] [.$100$ ] ] [.$4\cdot2=8$ [.$4$ ] [.$8$ ] ] ] [.$9+4=13$ [.$9$ ] [.$4$ ] ] ]
\end{tikzpicture}

Árbol de operaciones troncal (izquierda) y ramificado (derecha)
\end{center}

Este orden nos asegura que, siempre que el vector de candidatos esté ordenado de menor a mayor, no se producirán valores negativos en la matriz de diferencias ni resultados menores que $1$ en la matriz de cocientes.

Para realizar los cálculos sobre las matrices de forma consistente entre ejercicios, nos aseguraremos de que para cada índice `i` de `matriz`, `matriz[i] <= matriz[i+1]`.
Realizados los cálculos sobre ellas, debemos tener en cuenta que, aunque no se han obtenido valores negativos, sí se obtendrán valores no naturales en la matriz de cocientes, que habrá que descartar.

Teniendo esto en cuenta, almacenamos cada valor en un elemento de un vector dinámico de `Aprox`, que ordenaremos en el paso siguiente.

En general, el número de aproximaciones que obtenemos de esta forma se calcula recursivamente:

\begin{center}
$$\Bigg(\sum_{i=1}^{k}k-1\Bigg)-x$$

Donde $k$ es el número de candidatos y $x$, el número de aproximaciones no válidas.
\end{center}

Si durante el cálculo de los elementos de la matriz se llegara al objetivo, damos por finalizado el ejercicio.

## §3.4 - Ordenación de todas las aproximaciones por cercanía a la solución.

Obtenido el vector completo del paso anterior con las primeras aproximaciones, procedemos a ordenarlas por cercanía a la solución.
Para ello, definimos la diferencia de cada `Aprox` al objetivo como $|valor-objetivo|$ y los ordenamos de menor a mayor diferencia.

Como consideramos antes de comenzar el ejercicio, si dos `Aprox` tuvieran la misma diferencia al objetivo, se considerará más cercano aquél cuyo vector de candidatos sea de menor tamaño.
En caso de que dos `Aprox` tuvieran el mismo `valor` y el mismo `candidatos` **no** se eliminan por considerarse duplicados, ya que existe la posibilidad de que se elijan varios candidatos iguales al inicio del ejercicio.

## §3.5 - Iteraciones posteriores

Una vez ordenado el vector de `Aprox`, lo recorremos secuencialmente realizando las operaciones anteriores recursivamente hasta encontrar (o no) una combinación de operaciones cuyo resultado sea el valor objetivo.

Para construir las nuevas matrices tenemos en cuenta los candidatos que se han utilizado previamente.
Por ejemplo, si hubiéramos aproximado a $536$ con los candidatos de índice `0`, `2`, `3` y `4`, tendríamos las siguientes matrices:

\begin{center}
$\begin{matrix}
[1] & \times  & \times \\
[5] & \otimes & \times \\
    &   [1]   &   [5]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[1] & \times  & \otimes \\
[5] & \otimes & \times  \\
    &   [1]   &    [5]  \\
\end{matrix}$
\end{center}

En estos pasos debemos tener en cuenta que los valores obtenidos en las matrices aritméticas no son válidos hasta que no se hayan sumado o restestado a, multiplicado por o dividido entre el `valor` de la aproximación de la que partimos.

De forma recursiva, vamos realizando los mismo productos, sumas, diferencias y divisiones hasta obtener el valor objetivo o crear un nuevo vector de `Aprox`, que iremos recorriendo secuencialmente haciendo lo mismo hasta quedarnos sin aproximaciones.

\pagebreak

# §4 - EJEMPLO DE CÁLCULO EXITOSO

Detallamos aquí el funcionamiento del algoritmo para hallar la solución del enunciado, con candidatos $C={4,6,8,9,10,75}$ y número objetivo $835$.

## §4.1 - Cálculo de las matrices iniciales

\begin{center}
$\begin{matrix}
[4]  & \times  & \times  & \times  & \times  & \times  & \times \\
[6]  & 10      & \times  & \times  & \times  & \times  & \times \\
[8]  & 12      & 14      & \times  & \times  & \times  & \times \\
[9]  & 13      & 15      & 17      & \times  & \times  & \times \\
[10] & 14      & 16      & 18      & 19      & \times  & \times \\
[75] & 79      & 81      & 83      & 84      & 85      & \times \\
     &   [4]   &   [6]   &   [8]   &   [9]   &  [10]   &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[4]  & \times  & \times  & \times  & \times  & \times  & \times \\
[6]  & 2       & \times  & \times  & \times  & \times  & \times \\
[8]  & 4       & 2       & \times  & \times  & \times  & \times \\
[9]  & 5       & 3       & 1       & \times  & \times  & \times \\
[10] & 6       & 4       & 2       & 1       & \times  & \times \\
[75] & 71      & 69      & 67      & 66      & 65      & \times \\
     &   [4]   &   [6]   &   [8]   &   [9]   &  [10]   &  [75]  \\
\end{matrix}$

$\begin{matrix}
[4]  & \times  & \times  & \times  & \times  & \times  & \times \\
[6]  & 24      & \times  & \times  & \times  & \times  & \times \\
[8]  & 32      & 48      & \times  & \times  & \times  & \times \\
[9]  & 36      & 54      & 72      & \times  & \times  & \times \\
[10] & 40      & 60      & 80      & 90      & \times  & \times \\
[75] & 300     & 450     & 600     & 675     & 750     & \times \\
     &   [4]   &   [6]   &   [8]   &   [9]   &  [10]   &  [75]  \\
\end{matrix}$

Matrices de sumas (sup. izq.), diferencias (sup. dch.) y productos (inf.)

$\begin{matrix}
[4]  & \times       & \times       & \times       & \times       & \times        & \times \\
[6]  & \frac{6}{4}  & \times       & \times       & \times       & \times        & \times \\
[8]  & \frac{8}{4}  & \frac{8}{6}  & \times       & \times       & \times        & \times \\
[9]  & \frac{9}{4}  & \frac{9}{6}  & \frac{9}{8}  & \times       & \times        & \times \\
[10] & \frac{10}{4} & \frac{10}{6} & \frac{10}{8} & \frac{10}{9} & \times        & \times \\
[75] & \frac{75}{4} & \frac{75}{6} & \frac{75}{8} & \frac{75}{9} & \frac{75}{10} & \times \\
     &      [4]     &      [6]     &      [8]     &      [9]     &      [10]     &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \rightarrow\ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[4]  & \times & \times & \times & \times & \times & \times \\
[6]  & \times & \times & \times & \times & \times & \times \\
[8]  & 2      & \times & \times & \times & \times & \times \\
[9]  & \times & \times & \times & \times & \times & \times \\
[10] & \times & \times & \times & \times & \times & \times \\
[75] & \times & \times & \times & \times & \times & \times \\
     &  [4]   &  [6]   &  [8]   &  [9]   &  [10]  &  [75]  \\
\end{matrix}$

Matriz de cocientes con resultados inválidos (izquierda) y sin ellos (derecha)
\end{center}

## §4.2 - Ordenación de las aproximaciones obtenidas

De las operaciones anteriores obtenemos las siguientes aproximaciones, que representamos esquemáticamente como $valor[candidatos]$:

**Sumas:**

+:----------:+:----------:+:----------:+:----------:+:-----------:+
|  $10[4,6]$ |  $12[4,8]$ |  $13[4,9]$ | $14[4,10]$ |  $79[4,75]$ |
+:----------:+:----------:+:----------:+:----------:+:-----------:+
|  $14[6,8]$ |  $15[6,9]$ |  $16[6,9]$ | $81[6,75]$ |  $17[8,10]$ |
+:----------:+:----------:+:----------:+:----------:+:-----------:+
| $18[8,10]$ | $83[8,75]$ | $19[9,10]$ | $84[9,75]$ | $85[10,75]$ |
+:----------:+:----------:+:----------:+:----------:+:-----------:+

Ordenados localmente: $\{85,84,83,81,79,19,18,17,16,15,14,14,13,12,10\}$

**Diferencias:**

+:---------:+:----------:+:---------:+:----------:+:-----------:+
| $2[4,6]$  | $4[4,8]$   | $5[4,9]$  | $6[4,10]$  | $71[4,75]$  |
+:---------:+:----------:+:---------:+:----------:+:-----------:+
| $2[6,8]$  | $3[6,9]$   | $4[6,10]$ | $69[6,75]$ | $1[8,9]$    |
+:---------:+:----------:+:---------:+:----------:+:-----------:+
| $2[8,10]$ | $67[8,75]$ | $1[9,10]$ | $66[9,75]$ | $65[10,75]$ |
+:---------:+:----------:+:---------:+:----------:+:-----------:+

Ordenados localmente: $\{71,69,67,66,65,6,5,4,4,3,2,2,2,1,1\}$

**Productos:**

+:----------:+:-----------:+:----------:+:-----------:+:------------:+
| $24[4,6]$  | $32[4,8]$   | $36[4,9]$  | $40[4,10]$  | $300[4,75]$  |
+:----------:+:-----------:+:----------:+:-----------:+:------------:+
| $48[6,8]$  | $54[6,9]$   | $60[6,10]$ | $450[6,75]$ | $72[8,9]$    |
+:----------:+:-----------:+:----------:+:-----------:+:------------:+
| $80[8,10]$ | $600[8,75]$ | $90[9,10]$ | $675[9,75]$ | $750[10,75]$ |
+:----------:+:-----------:+:----------:+:-----------:+:------------:+

Ordenados localmente: $\{750,675,600,450,300,90,80,72,60,54,48,40,36,32,24\}$

**Cocientes:** $2[4,8]$

**Ordenación de todas las aproximaciones:**

\begin{center}
$\{750,675,600,450,300,90,85,84,83,81,80,79,72,71,69,67,66,65,60,54,$

$48,40,36,32,24,19,18,17,16,15,14,14,13,12,10,6,5,4,4,3,2,2,2,2,1,1\}$
\end{center}

\pagebreak

## §4.3 - Iteraciones posteriores

Tras muchos cálculos infructuosos, se llega al `Aprox` $2[4,8]$, el único `Aprox` obtenido de la matriz de cocientes.
Con esta aproximación, recuperamos las matrices anteriores sin las filas ni columnas de los candidatos $4$ y $8$:

\begin{center}
$\begin{matrix}
[6]  & \times & \times & \times & \times \\
[9]  & 15     & \times & \times & \times \\
[10] & 16     & 19     & \times & \times \\
[75] & 81     & 84     & 85     & \times \\
     &   [6]  &   [9]  &  [10]  &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times & \times & \times \\
[9]  & 3      & \times & \times & \times \\
[10] & 4      & 1      & \times & \times \\
[75] & 69     & 66     & 65     & \times \\
     &   [6]  &   [9]  &  [10]  &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times & \times & \times \\
[9]  & 54     & \times & \times & \times \\
[10] & 60     & 90     & \times & \times \\
[75] & 450    & 675    & 750    & \times \\
     &   [6]  &   [9]  &  [10]  &  [75]  \\
\end{matrix}$

Matrices de sumas (izquierda), diferencias (centro) y productos (derecha) de la primera iteración
\end{center}

Relacionamos ahora estos números y el resto de candidatos con el $2$ mediante la suma, diferencia, producto y cociente para generar nuevas aproximaciones.
Para simplificar, se muestran únicamente las relaciones brutas, sin simplificar las fracciones ni desechar los resultados fraccionarios o negativos.
A pesar de ello, se sigue teniendo en cuenta que no son resultados válidos para este ejercicio.

\begin{center}
\bf{Relaciones con los resultados de la matriz de sumas:}
\end{center}

| $x$  | $2+x$ | $2-x$ | $x-2$ | $2x$  | $\frac{2}{x}$  | $\frac{x}{2}$  |
| :--: | :---: | :---: | :---: | :--:  | :------------: | :------------: |
| $15$ | $17$  | $-13$ | $13$  | $30$  | $\frac{2}{15}$ | $\frac{15}{2}$ |
| $16$ | $18$  | $-14$ | $14$  | $32$  | $\frac{2}{16}$ | $\frac{16}{2}$ |
| $19$ | $21$  | $-17$ | $17$  | $38$  | $\frac{2}{19}$ | $\frac{19}{2}$ |
| $81$ | $83$  | $-79$ | $79$  | $162$ | $\frac{2}{81}$ | $\frac{81}{2}$ |
| $84$ | $86$  | $-82$ | $82$  | $168$ | $\frac{2}{84}$ | $\frac{84}{2}$ |
| $85$ | $87$  | $-83$ | $83$  | $170$ | $\frac{2}{85}$ | $\frac{85}{2}$ |

\pagebreak

\begin{center}
\bf{Relaciones con los resultados de la matriz de diferencias:}
\end{center}

| $x$  | $2+x$ | $2-x$ | $x-2$ | $2x$  | $\frac{2}{x}$  | $\frac{x}{2}$  |
| :--: | :---: | :---: | :---: | :--:  | :------------: | :------------: |
| $1$  | $3$   | $1$   | $-1$  | $2$   | $\frac{2}{1}$  | $\frac{1}{2}$  |
| $3$  | $5$   | $-1$  | $1$   | $3$   | $\frac{2}{3}$  | $\frac{3}{2}$  |
| $4$  | $6$   | $-2$  | $2$   | $8$   | $\frac{2}{4}$  | $\frac{4}{2}$  |
| $65$ | $67$  | $-63$ | $63$  | $130$ | $\frac{2}{65}$ | $\frac{65}{2}$ |
| $66$ | $68$  | $-64$ | $64$  | $132$ | $\frac{2}{66}$ | $\frac{66}{2}$ |
| $69$ | $71$  | $-67$ | $67$  | $138$ | $\frac{2}{69}$ | $\frac{69}{2}$ |

\begin{center}
\bf{Relaciones con los resultados de la matriz de productos:}
\end{center}

| $x$   | $2+x$  | $2-x$  | $x-2$  | $2x$   | $\frac{2}{x}$   | $\frac{x}{2}$   |
| :---: | :----: | :----: | :----: | :---:  | :-------------: | :-------------: |
| $54$  | $56$   | $-52$  | $52$   | $108$  | $\frac{2}{54}$  | $\frac{54}{2}$  |
| $60$  | $62$   | $-58$  | $58$   | $120$  | $\frac{2}{60}$  | $\frac{60}{2}$  |
| $90$  | $92$   | $-88$  | $88$   | $180$  | $\frac{2}{90}$  | $\frac{90}{2}$  |
| $450$ | $452$  | $-448$ | $448$  | $900$  | $\frac{2}{450}$ | $\frac{450}{2}$ |
| $675$ | $677$  | $-673$ | $673$  | $1350$ | $\frac{2}{675}$ | $\frac{675}{2}$ |
| $750$ | $752$  | $-748$ | $748$  | $1500$ | $\frac{2}{750}$ | $\frac{750}{2}$ |

\begin{center}
\bf{Relaciones con el resto de candidatos:}
\end{center}

| $x$  | $2+x$ | $2-x$ | $x-2$  | $2x$  | $\frac{2}{x}$   | $\frac{x}{2}$   |
| :--: | :---: | :---: | :----: | :---: | :-------------: | :-------------: |
| $6$  | $8$   | $-4$  | $4$    | $12$  | $\frac{2}{6}$   | $\frac{6}{2}$   |
| $9$  | $11$  | $-7$  | $7$    | $18$  | $\frac{2}{8}$   | $\frac{8}{2}$   |
| $10$ | $12$  | $-8$  | $8$    | $20$  | $\frac{2}{10}$  | $\frac{10}{2}$  |
| $75$ | $77$  | $-73$ | $73$   | $150$ | $\frac{2}{75}$  | $\frac{75}{2}$  |

\pagebreak

Obtenidos todos estos resultados, los ordenamos igual que en el paso anterior e iteramos por ellos hasta llegar al `Aprox` $11[4,8,9]$, obtenido mediante la siguiente secuencia:

\begin{center}
$$\frac{8}{4}+9$$
\end{center}

En esta iteración, operamos con las siguientes matrices:

\begin{center}
$\begin{matrix}
[6]  & \times & \times & \times \\
[10] & 16     & \times & \times \\
[75] & 81     & 85     & \times \\
     &   [6]  &  [10]  &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times & \times \\
[10] & 4      & \times & \times \\
[75] & 69     & 65     & \times \\
     &   [6]  &  [10]  &  [75]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times & \times \\
[10] & 60     & \times & \times \\
[75] & 450    & 750    & \times \\
     &   [6]  &  [10]  &  [75]  \\
\end{matrix}$

Matrices de sumas (izquierda), diferencias (centro) y productos (derecha) de la segunda iteración
\end{center}

Con las relaciones de los valores de estas matrices y de los candidatos restantes, obtenemos el `Aprox` $825[4,8,9,11]$, obtenido mediante la siguiente secuencia:

\begin{center}
$$\bigg(\frac{8}{4}+9\bigg)\cdot11$$
\end{center}

Por último, trabajamos con las siguientes matrices:

\begin{center}
$\begin{matrix}
[6]  & \times & \times \\
[10] & 16     & \times \\
     &   [6]  &  [10]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times \\
[10] & 4      & \times \\
     &   [6]  &  [10]  \\
\end{matrix}
\ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \ \begin{matrix}
[6]  & \times & \times \\
[10] & 60     & \times \\
     &   [6]  &  [10]  \\
\end{matrix}$

Matrices de sumas (izquierda), diferencias (centro) y productos (derecha) de la última iteración
\end{center}

Con las relaciones de los valores de estas matrices y de los candidatos restantes, finalizamos el ejercicio obteniendo el `Aprox` $825[4,8,9,10,11]$, obtenido mediante la siguiente secuencia:

\begin{center}
$$\bigg(\frac{8}{4}+9\bigg)\cdot11+10$$
\end{center}

\pagebreak

# §5 - EJEMPLO DE CÁLCULO NO EXITOSO

Como ejemplo simple de un cálculo no exitoso, supongamos los siguientes datos:

- **Candidatos:** $C=\{1,1,2,3,4,5\}$.
- **Objetivo:** $O=500$.

Sabemos que el valor más cercano alcanzable con estos candidatos es $122=2\cdot3\cdot4\cdot5+1+1$.

Como primera y más cercana aproximación al objetivo, obtenemos $4\cdot5=20$.
Buscando aproximar en la primera iteración, el algoritmo llega a $3\cdot2\cdot aproximaci\acute on=120$.
Registrado este `valor` como el más alto conseguido hasta el momento, se intenta aproximar en una nueva iteración sumando $1$ a la aproximación, consiguiendo $121$.
Una última vez más, sumamos $1$ y obtenemos $122$, siendo éste el valor más cercano alcanzable por el algoritmo.

Dado que no tenemos un sistema de control del algoritmo, éste continuará hasta agotar el resto de valores sin éxito.
