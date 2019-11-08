# Fundamentos de Redes

**3º Grado en Ingeniería Informática - Universidad de Granada - Curso 2018-2019**

> **Advertencia:** puede que estos apuntes no estén completos. Si quieres continuarlos, siéntete libre de hacer una *pull request*.

Este documento recoge apuntes de la asignatura **Fundamentos de Redes**, basados en el material docente ofrecido por el *departamento de Teoría de la Señal, Telemática y Comunicaciones* de la Universidad de Granada, y en los apuntes recogidos por [Marta Gómez y Braulio Vargas](https://github.com/mgmacias95/Apuntes/blob/master/FR/apuntesfr.tex).

---

## Índice

<!--ts-->

* [Tema 1: Introducción a los Fundamentos de Redes](#tema-1-introducción-a-los-fundamentos-de-redes)
   * [1. Sistemas de comunicación y redes](#1-sistemas-de-comunicación-y-redes)
      * [1.1. Conceptos básicos](#11-conceptos-básicos)
      * [1.2. Razones para usar redes](#12-razones-para-usar-redes)
      * [1.3. Clasificación de redes](#13-clasificación-de-redes)
      * [1.4. Estructura y elementos de una red](#14-estructura-y-elementos-de-una-red)
   * [2. Diseño y estandarización de redes](#2-diseño-y-estandarización-de-redes)
      * [2.1. Problemas a resolver](#21-problemas-a-resolver)
      * [2.2. Conceptos y principios de diseño](#22-conceptos-y-principios-de-diseño)
   * [3. Terminología y servicios](#3-terminología-y-servicios)
      * [3.1. Modelo OSI: comunicación real frente a comunicación virtual](#31-modelo-osi-comunicación-real-frente-a-comunicación-virtual)
      * [3.2. Servicios](#32-servicios)
   * [4. Internet: arquitectura y direccionamiento](#4-internet-arquitectura-y-direccionamiento)
      * [4.1. Arquitectura](#41-arquitectura)
      * [4.2. Direccionamiento](#42-direccionamiento)
* [Tema 2: servicios y protocolos de aplicación en Internet](#tema-2-servicios-y-protocolos-de-aplicación-en-internet)
* [Referencias](#referencias)

<!-- Added by: patchispatch, at: 2018-12-01T22:03+01:00 -->

<!--te-->

---

## Tema 1: Introducción a los Fundamentos de Redes

### 1. Sistemas de comunicación y redes

#### 1.1. Conceptos básicos

Un **Sistema de comunicación** es una infraestructura que permite el intercambio de información. Podemos expresarlo como un conjunto de elementos: 

- **Emisor:** origen de la información.
- **Destino:** destinatario de la información transmitida.
- **Transmisor:** intermediario entre el canal y el emisor, encargado de adaptar la señal transmitida a las características del medio de transimisión.
- **Receptor:** intermediario entre el canal y el receptor, encargado de adaptar las características de la señal a las del destino.


![conceptos basicos](https://i.imgur.com/NGO3Alr.png)


La **información** es un conjunto de datos con significado.

Una **red de dispositivos** es un caso particular de sistema de comunicación, y dispone de sistemas finales (terminales) *autónomos* que facilita el intercambio *eficaz* y *transparente* de información.

#### 1.2. Características de las redes

- **Interconexión:** la existencia de canales de transmisión permite la comunicación entre los equipos de la red.
- **Autonomía:** los equipos son independientes en cuanto a funcionamiento.
- **Intercambio de información.**

El objetivo principal de las redes es el de **compartir recursos**. Sin embargo, hay más razones por las que resultan de gran utilidad:

- **Escalabilidad:** una red es mucho más fácil de escalar que un computador tradicional, ya que si necesitamos ampliar recursos, en la red bastaría con añadir equipos, sin necesidad de sustituir componentes.
- **Fiabilidad:** al disponer de varios equipos conectados, puede haber *duplicidad* de recursos, por lo que es menos probable que se pierdan.
- **Ahorro de costes:** los equipos de una red son más fáciles de mantener que un supercomputador; por tanto, saldrá más barato.

#### 1.3. Clasificación de redes

Las redes se clasifican en base a dos principales criterios:

**Por escala: **
- *Local* Area Network (LAN)
- *Medium* Area Network (MAN)
- *Wide* Area Network (WAN)

**Por tecnología de transmisión o uso del canal de comunicación**
- **Difusión:** las transmisiones se realizan desde un único medio, compartido por todos los equipos.
- **Punto a punto:** existen enlaces entre dos equipos en los que ambos actúan de emisor y receptor, dependiendo de la transmisión. Cuando el número de enlaces es igual al de parejas posibles de equipos, se llama *topología*, pero no es usual debido a su alto coste.

![tecnologia transmision](https://i.imgur.com/kbpwu0w.png)

Las redes LAN utilizan tecnología de difusión, mientras que las WAN usan la comunicación punto a punto.

#### 1.4. Estructura y elementos de una red

Podemos definir los siguientes elementos en una red:

**Hosts:** sistemas finales (terminales) autónomos.

**Subred:** infraestructura para el transporte de información, compuesta por:
- **Líneas de transmisión**.
- **Nodos o elementos de conmutación:** dispositivos que transportan datos desde un origen a un destino. Ejemplos:
  - Routers
  - Switches
  - Estaciones base
  - Etc.

	![Nodos](https://i.imgur.com/a2QUSPS.png)

### 2. Diseño y estandarización de redes

#### 2.1. Problemas a resolver

Existen una serie de **problemas** que la red debe resolver, para garantizar *transparencia* y *eficacia*:
- ¿Cómo enviar físicamente la información?
- Compartición del medio y segmentación de la información.
- Control de flujo y de errores.
- Control de encaminamiento (*routing*) de los mensajes.
- Control de congestión.
- Entrega ordenada de los mensajes.
- Gestión del diálogo o turno de palabra.
- Representación de los datos (sintaxis).
- Significado de los datos (semántica).

Veremos a continuación diferentes soluciones a estos problemas.

#### 2.2. Conceptos y principios de diseño

El diseño de una red se plantea por **capas**. Cada capa se encarga de una función, obteniendo así un sistema modular, mucho más flexible. Una vez disponemos de un conjunto de capas, cada una con su funcionalidad, ya tenemos un **modelo de referencia**.

Existen dos tipos de modelos de red:

- ***De facto*:** se adoptan sin haber seguido un proceso de estandarización.
- ***De jure*:** han sido desarrollados por organismos de estandarización reconocidos.

Los modelos más conocidos son **OSI** y **TCP/IP**.

![OSI TCP](https://i.imgur.com/TKxmJHy.png)

**Modelo OSI**
El modelo OSI (*Open System Interconnection*) es un modelo de referencia para los protocolos de red creado por la ISO en 1980

El modelo define las siguientes **capas** (de arriba a abajo):
- **Aplicación:** servicios finales que se ofrecen al usuario (correo electrónico, Discord, etc).
- **Presentación:** en esta capa se resuelven problemas sobre la representación de datos que provienen de la capa superior (codificación, por ejemplo).
- **Sesión:** esta capa se encarga de gestionar el turno de palabra entre los hosts participantes.
- **Transporte:** controla la transmisión de datos entre los hosts, y se asegura de que se realiza correctamente.
- **Red:** tiene tres funciones principales:
  - *Encaminamiento*: establecimiento de la ruta a seguir desde un host a otro.
  - *Control de congestión*: evita la saturación de la subred como consecuencia de un tráfico elevado.
  - *Interconexión de redes*: posibilita la transmisión de datos entre hosts situados en diferentes redes.
- **Enlace:** en esta capa, los bits de datos se agrupan en bloques llamados "tramas". Realiza las siguientews funciones:
  - *Delimitación de tramas*: permite conocer el inicio y fin de un bloque de datos y sincronizar al emisor y al receptor.
  - *Control de errores*: comprueba que la información recibida corresponde con la enviada.
  - *Control de flujo*: evita que el emisor sature el *buffer* de recepción del destino debido a una velocidad diferente entre las dos partes.
- **Física:** en ella se llevan a cabo funciones relacionadas con la transmisión de datos desde el punto de vista de la gestión de características eléctricas, mecánicas y funcionales para una adecuada transferencia sobre el canal. Sería la tarjeta de red.

El modelo OSI tiene capas con muy poco contenido. Por eso es normal ver un numero menor de capas en otros modelos, ya que varias funciones se asocian a la misma capa. En **TCP/IP** se distinguen las siguientes capas:

- **Aplicación:** se definen en esta capa servicios como *telnet* (acceso remoto), *ftp* (transmisión de archivos), *http* (web), etc.
- **Transporte:** control de flujo, de errores, de congestión y de conexión (extremo a extremo).
- **Red:** encaminamiento.

TCP/IP es el modelo que se utiliza en internet, y es una red software, ya que se puede implementar sobre cualquier tecnología de red. Es un ejemplo de modelo *de facto*, y el más extendido en la actualidad.
La red subyacente no se tiene en consideración en TCP/IP, ya que al ser un modelo software, no especifica las características de la misma, pudiendo variar en cada ordenador.

### 3. Terminología y servicios

#### 3.1. Modelo OSI: comunicación real frente a comunicación virtual

![OSI capas](https://i.imgur.com/iE6Ki8u.png)

Dadas dos capas adyacentes, la capa inferior se denomina **proveedora de servicios**, y la inferior, **usuaria de servicios**, ya que la capa inferior ofrece una serie de servicios transparentes a la superior.

Los elementos software o hardware de una capa se conocen como **entidades de nivel N**. Las entidades de nivel N en el emisor y en el receptor se conocen como **entidades pares**, ya que se conectan dos a dos.

Existen dos tipos de comunicación entre emisor y receptor:
- **Comunicación real (vertical):** es el flujo que sigue la información entre el emisor y el receptor, en sentido descendente (aplicación a física) en el emisor y ascendente (física a aplicación) en el receptor.
- **Comunicación virtual (horizontal):** comunicación entre entidades pares. En la transmisión de un mensaje se necesita la colaboración de las entidades pares emisora y recepotora. Para ello, en cada capa (salvo en la física) se añade una cabecera para ayudar a comunicar las partes involucradas.

Un **protocolo** es el conjunto de reglas y convenciones que se tienn que aplicar en una comunicación entre dos entidades. A las capas y protocolos asociados se les denomina **arquitectura de red**. En este sentido, OSI no es una arquitectura, ya que no define protocolos, mientras que TCP/IP sí, ya que en cada capa se conocen los protocolos que se tienen que tener en cuenta. La especificación en capas de una arquitectura de red se denomina **pila de protocolos**.

La comunicación vertical se realiza mediante la **interfaz**, concretamente con los **puntos de acceso (*Service Access Points, SAP*)**. Dentro de la información que se transmite se distinguen la **unidad de datos de servicio (*Data Service Unit, SDU*)**, que son los datos que se quieren enviar (provienen de la capa superior), y la **unidad de datos de protocolo (*Protocol Data Unit, PDU*)**, que es la cabecera añadida para llevar a cabo las operaciones con entidades paritarias.


#### 3.2. Retardo

El **retardo** es el tiempo que tarda la información en llegar desde el host origen al destino.

![Retardo](https://i.imgur.com/w48FNJX.png)

Deben distinguirse dos tiempos:
- **Tiempo de transmisión:** cuánto se tarda en transmitir todos los bits a la red.


![img](http://www.sciweavers.org/tex2img.php?eq=T_%7Bt%7D%20%3D%20%5Cfrac%7BTam%20%28B%29%7D%7BV_%7Bt%7D%20%28bps%29%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)

- **Tiempo de propagación:** cuánto tarda la información en llegar al destino.


![img2](http://www.sciweavers.org/tex2img.php?eq=T_%7Bt%7D%20%3D%20%5Cfrac%7BDistancia%20%28m%29%7D%7BV_%7Bpropagacion%7D%20%28m%2Fs%29%7D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)


#### 3.3. Servicios

Los diferentes servicios que se pueden ofrecer son los siguientes:

- **Orientado a Conexión:** se establece una conexión como paso previo a la transmisión de datos entre el emisor y el receptor. Se realiza enviando un paquete de un tamaño por parte del emisor que el receptor debe devolver. Una vez devuelto, comienza el envío del resto de paquetes. Este tipo de servicios se utilizan cuando necesitamos que no haya pérdidas de información.
- **No Orientado a Conexión:** no requiere de una conexión como el anterior, y el envío se realiza con una gran rapidez, aunue existan pérdidas en la transmisión. Un ejemplo de estos servicios es la reproducción de contenido multimedia online, en el que no importa si perdemos un frame o dos, pero necesitamos que lleguen constantemente para que la reproducción sea fluida.
- **Confirmado (fiable):** el host emisor tiene constancia de que el receptor tiene el paquete.
- **No confirmado (no fiable):** el host emisor no tiene forma de saber si el receptor tiene el paquete.



### 4. Internet: arquitectura y direccionamiento

#### 4.1. Arquitectura 

Se establece una **topología jerárquica** entre diferentes tipos de redes:
- **Intranets (*Ethernet*) del usuario:** zona pública + zona privada. Son las redes locales de usuario, en las que se incluyen direcciones privadas para la subred local y direcciones públicas para acceder a la red.
- **Redes de acceso:** diferentes métodos de acceso, como el ADSL o la fibra óptica, pertenecientes al ISP (*Internet Service Provider*).
- **Redes troncales:** son diferentes redes de grandes operadores de telecomunicaciones. Un ejemplo sería la *red Iris*, que conecta la comunidad investigadora y las universidades españolas. Hay varios tipos según su tamaño: *Tier-1*, *Tier-2* y *Tier-3*.
- **Internet Exchange Points (IXP):** también conocidos como **puntos neutros**, son aquellos en los que las redes ISP se encuentran para intercambiar tráfico.

#### 4.2. Direccionamiento

Cuando queremos, por ejemplo, acceder a una página web, se genera un paquete de datos con la información necesaria para que las distintas capas por las que va a pasar sepan qué hacer con él, y lo transmitan entre los diferentes nodos por los que debe pasar hasta llegar a su destino. Una vez llegue, se nos devolverá la información que hemos pedido.

Para conseguir que el paquete llegue a su destino necesitamos **direccionarlo**.
El direccionamiento necesitamos los siguientes elementos:

- **Nombre de dominio:** El nombre de dominio se especifica en la capa de aplicación, ya que es la que interactúa con el usuario. La capa se encarga de traducirlo a una dirección IP. Ej: https://github.com/patchispatch
- **Dirección IP:** necesaria para identificar los host, se enuentra en la capa de red. Existen dos tipos:
  - *Públicas:* direccionan a un único dispositivo y se paga (o se alquila) por ella. Son unívocas en todo Internet.
  - *Privadas:* son direcciones que se pueden repetir en el mundo, pero no dentro de una red privada, ya que identifican a los diferentes dispositivos de la misma. Sin ellas, habríamos agotado el número de IPs disponibles en el mundo hace años.
- **Puertos:** sieven para establecer diferentes conexiones y responder peticiones de otros dispositivos. Se localizan en la capa de transporte.



---

## Tema 2: servicios y protocolos de aplicación en Internet

### 1. Introducción a las aplicaciones de red

#### 1.1. Arquitectura Cliente/Servidor

Un  **servidor** es una aplicación que permite el acceso remoto a recursos software o hardware en un host. Estará en escucha hasta recibir alguna solicitud por parte de un **cliente**.

Las características del cliente y el servidor son diferentes:

**Servidor**
- Siempre en funcionamiento.
- IP permanente y pública.
- Pueden estar agrupados en *granjas*.

**Clientes**
- Funcionan de forma intermitente.
- Pueden tener IP dinámica y privada.
- Se comunican con el servidor.
- No se comunican entre sí.

Son los clientes los que inician la conexión, y por lo general no se comunican entre sí.

El proceso envía y recibe mensajes desde su **socket**.
Para poder recibir mensajes, un proceso debe estar identificado por su IP y su puerto.

#### 1.2. La interfaz socket

Un **socket** es un descriptor de transmisión entre aplicaciones. Cuenta con una especie de API que los procesos utilizan para acceder a los servicios de transporte de forma segura. Cuando se quiere realizar una comunicación, se le asigna un **puerto**.

En definitiva, un socket es un proceso o thread que existe en el cliente y el servidor, que se utiliza para que ambos escriban y lean la información, que será transmitida por las capas de red. Es un puntero a una estructura.

![socket](https://i.imgur.com/qvMMbjZ.png)

#### 1.3. Protocolos de aplicación

¿Qué define un protocolo?
- **El tipo de servicio**
  - Orientado a conexión o no.
  - Realimentado o no.
- **El tipo de mensaje**
- **La sintaxis**
  Definición y estructura de campos en el mensaje.
- **La semántica**
  Significado de los campos.
- **Las reglas**
  Envío y respuesta de mensajes por parte de los procesos.

Existen varios tipos de protocolos:
- **Protocolos de dominio público:** están definidos en los [RFCs](https://www.wikiwand.com/en/Request_for_Comments), y buscan ser estandarizados. Ejemplos: HTTP, FTP.
- **Protocolos propietarios:** son creados por un organismo privado, y buscan ser lo más opacos posible, para que nadie sepa cómo funcionan.

También hay varias clasificaciones de protocolos, aunque menos importantes:
- **Protocolos in-band *versus* out-of-band:** los protocolos *in-band* envían en el mismo mensaje tanto la información como los datos de control, mientras que en *out-of-band* se utilizan diferentes canales para cada cosa.
- **Protocolos stateless *versus* state-full:** los protocolos *stateless* no guardan información de los clientes en el servidor, mientras que los *state-full* sí. HTTP por ejemplo es stateless, ya que no guarda nuestros datos. Sin embargo, utiliza **cookies**, ficheros almacenados localmente en el cliente. 
- **Protocolos persistentes *versus* no persistentes:** los protocolos *persistentes* se mantienen conectados, mientras que los *no persistentes* crean una conexión para cada envío de información.

La tendencia es **definir los protocolos de forma flexible**, utilizando una cabecera fija y una serie de trozos (*chunks*), algunos obligatorios y otros opcionales.

Los trozos pueden incluir una cabecera específica más una serie de datos como parámetros. Para los parámetros se usa el formato TLV (*Type-Length-Value*).

![TLV](https://i.imgur.com/l1l7IRh.png)


#### 1.4. Características

**Pérdida de datos**
Algunas aplicaciones soportan mejor la pérdida de datos que otras. En audio, por ejemplo, es tolerable; otros servicios como *telnet* o *ssh* requieren fiabilidad en la transmisión.

**Requisitos temporales**
Algunas apps requieren retardo acotado (bajo *delay*) para ser efectivas, como pueden ser las de telefonía o juegos.

**Rendimiento (*throughput*)**
Algunas apps necesitan enviar datos a una determinada tasa de transmisión. Por ejemplo, al ver una película por streaming necesitamos que cada cierto tiempo nos lleguen frames, o se parará. 

**Seguridad**
Encriptación, autenticado, etc.

A continuación se muestran ejemplos de aplicaciones de red, y la importancia que le dan a las anteriores características:

| **Aplicación**            | **Pérdida de datos** | **Rendimiento**            | **Sensible al tiempo** |
|---------------------------|----------------------|----------------------------|------------------------|
| Transferencia de archivos | no hay pérdida       | elástico                   | no                     |
| E-mail                    | no hay pérdida       | elástico                   | no                     |
| Documentos web            | no hay pérdida       | elástico                   | no                     |
| Multimedia en tiempo real | se puede perder algo | audio: 5kpbs video: 10kbps | sí                     |
| Audio o vídeo almacenado  | se puede perder algo | audio: 5kpbs video: 10kbps | sí                     |
| Videojuegos online        | se puede perder algo | unos cuantos kbps          | sí                     |
| Mensajería instantánea    | no hay pérdida       | elástica                   | depende                |


En la mensajería instantánea es preferible que el mensaje tarde algo más en llegar a que existan pérdidas, de ahí el *depende* en la tabla.

#### 1.5. Protocolos

Los protocolos están estructurados de la siguiente forma:



![Protocolos](https://i.imgur.com/75FvHlr.png)



Nos vamos a centrar en **TCP** y **UDP**.

| **Protocolo TCP**     | **Protocolo UDP**         |
|-----------------------|---------------------------|
| Orientado a conexión  | No orientado a conexión   |
| Transporte fiable     | Transporte no fiable      |
| Control de flujo      | Sin control de flujo      |
| Control de congestión | Sin control de congestión |

Al ser usuarios del protocolo IP, ni TCP ni UDP garantizan
- Retardo acotado
- Fluctuaciones acotadas
- Mínimo *throughput*
- Seguridad

### 2. Domain Name Service (DNS)

Para comunicarse en Internet, necesitamos direcciones IP, que identifican a cada máquina involucrada en la comunicación y se utilizan para direccionarlas. Sin embargo, es más cómodo utilizar los llamados **nombres de dominio**, más legibles y fáciles de recordar, para acceder a las diferentes direcciones. 

Para ello, se usa el **Servicio de Nombre de Dominio (DNS)**, que traduce nombres a direcciones IP (servicio de resolución de nombres). 

Sus características principales son:

- Suele ser el paso previo al resto de aplicaciones TCP/IP, ya que las conexiones suelen realizarse mediante un nombre de dominio. Sin embargo, si la conexión se realiza directamente utilizando una IP, el servicio DNS no llega a ejecutarse.
- Es transparente al usuario, es decir, no tiene por qué darse cuenta de que se está ejecutando, pues se realiza de forma automática.

El nombre de dominio, al igual que la dirección IP, debe ser único y universal. Para asegurar esto, los dominios se estructuran de forma jerárquica de la siguiente forma:

	deiit.ugr.es

En este ejemplo, *.es* es el dominio de nivel 1 o superior, que engloba al subdominio *ugr*. Este, a su vez, engloba a *deiit*.

El dominio de nivel 1 se denomina **dominio genérico**. Originalmente se crearon nueve dominios genéricos, aunque ahora existen muchos más:

| **.com**  | organizaciones comerciales                                                       |
|-----------|----------------------------------------------------------------------------------|
| **.edu**  | instituciones educativas                                                         |
| **.gov**  | instituciones gubernamentales de EEUU                                            |
| **.mil**  | grupos militares de EEUU                                                         |
| **.net**  | proveedores de red                                                               |
| **.org**  | organizaciones diferentes a las anteriores                                       |
| **.arpa** | propósitos de infraestructura de Internet (*Address and Routing Parameter Area*) |
| **.int**  | organizaciones estableidas por tratados internacionales                          |
| **.xy**   |  indicativos de zona geográfica (*.es, .uk, .jp, etc*)                           |

El dominio raíz "." está gestionado por la [ICANN](http://www.icann.org), que suele delegar en centros regionales. En España, este centro es [Red.es](https://red.es/redes/).

#### 2.1. Servidores DNS

Para que DNS pueda funcionar, debe existir una base de datos que contenga todos los dominios existentes y su respectiva traducción a IP, para poder traducir los valores. 
Si esta base de datos estuviese centralizada, prácticamente *todo* el tráfico de internet pasaría por un mismo lugar, ralentizando mucho el servicio, por no hablar de lo complejísimo que sería mantener un servidor de tales magnitudes. 

Es por ello que esta base de datos se halla distribuida en una gran cantidad de servidores a lo largo del mundo, y son de diferentes tipos:

- **Servidores raíz ".":** este tipo de servidores se encargan de resolver una petición para un nombre. Devuelven los dominios **TLD** capaces de resolver la petición. Existen trece servidores "." primarios en el mundo, aunque cada uno realmente es una red de servidores, haiendo realmente unos 250 servidores *root*.
- **Servidores de dominio (TLD, *Top-Level Domain*)**: estos servidores se encargan de los dominios de más alto nivel, como los *genéricos*. Se encargan de resolver la petición DNS, y si no son capaces de hacerlo, darán la dirección del **servidor autorizado** que pueda resolverla.
- **Servidores autorizados:** es un servidor que contiene una base de datos con todas las direcciones IP asociadas a él. Es el más actualizado, y el que resolverá las peticiones DNS en caso de que el servidor local o el TLD no sean capaces de hacerlo. Responderá al **servidor local** con la IP.
- **Servidor local:** un servidor local es aquel que posee cada proveedor de Internet (ISP). Resolverá todas las peticiones DNS que correspondan a su dominio (ej: ```deiit.ugr.es``` es resuelto por el servidor local de la red de la UGR). Suele estar cerca del host al que pertenece.

#### 2.2. Resolución de DNS

La resolución puede realizarse de dos formas distintas, según cómo se recorren los diferentes servidores:

- **Resolución recursiva:** el host que realiza la consulta se la manda a un servidor. Si este no puede resolverla, se la envía a otro, y este a otro distinto, hasta que uno pueda hacerlo. Una vez resuelta la consulta por el servidor *n*, devolverá la IP al servidor *n - 1*, y la irán pasando hacia atrás hasta que llegue al host.
*Problema:* hasta que no se resuelva la petición, el servidor tiene que almacenar la información.
- **Resolución iterativa:** cuando se realiza una consulta DNS y el servidor no la puede responder, se la devuelve al host, que la envía a otro. Si este tampoco puede, la devuelve de nuevo al host, que lo intenta con otro. Esto ofrece una solución al problema de la resolución recursiva. 

#### 2.3. Gestión de la base de datos DNS

La base de datos DNS es distribuida, como hemos comentado anteriormente. Esto presenta ventajas en términos de congestión, pero a la hora de actualizar registros puede volverse un problema: pueden existir varias copias de una traducción en distintos servidores, ya que utilizan memorias caché para aligerar traducciones. A la hora de actualizar una entrada, ¿cómo nos aseguramos de que lo hacemos correctamente? Pues se hace actualizando la tradución en el **servidor autorizado** en el que se aloja.

Las traducciones actualizadas se hallan en servidores primarios, que mantienen la coherencia de la base de datos. No obstante, existen servidores secundarios con copias de serguridad, en caso de necesitarse debido a fallos.

#### 2.4. Respuestas del servidor

¿Qué tipo de respuesta podemos esperar tras realizar una petición DNS?

- **Respuesta con autoridad:** el servidor tiene autoridad sobre la zona en la que se encuentra el nombre solicitado y devuelve la IP.
- **Respuesta sin autoridad:** el servidor no tiene autoridad sobre la zona en la que se encuentra el nombre solicitado, pero tiene la traducción almacenada en caché.
- **No conoce la respuesta:** el servidor enviará la consulta a otros servidores de forma recursiva o iterativa. Se suele elevar la petición a uno de los servidores *root*.

### 3. La navegación web

Cuando navegamos por Internet, no hacemos más que realizar peticiones a un servidor, y este nos responde con algo que nuestro navegador puede interpretar. Este *algo* no es más que un fichero HTML, que contiene el esqueleto de la página, *hiperenlaces* a otras páginas que albergan contenido, imágenes, audio, etc.

El contenido de las páginas se direcciona mediante una **URL** (*Uniform Resource Locator*), que indica el protocolo (*http* o *https* normalmente), el servidor (o el dominio) y el puerto (si es necesario), de la siguiente forma:

	https://dominio[:puerto]/path/al/recurso

#### 3.1. El protocolo HTTP

El protocolo HTTP utiliza el modelo *cliente-servidor*:

- **Cliente:** navegador web, que realiza peticiones de objetos, los recibe y los muestra
- **Servidor:** atiende a las peticiones que le llegan, enviando los objetos solicitados.

HTTP utiliza el puerto 80 para realizar las conexiones. El cliente inicia la conexión TCP para solicitar datos, recibiéndola el servidor en el socket correspondiente. El servidor envía por ese socket la información solicitada, y cierra la conexión. El cliente puede estar en uno de estos tres rangos de puertos:

- **Superusuarios:** desde el 0 hasta el 1023.
- **Puertos reservados:** desde el 1024 al 49151. Los utilizan aplicaciones que no requieren permisos de administrador, y son puertos que no están asignados a otro servicio, como por ejemplo el 80 (http).
- **Puertos dinámicos, privados o efímeros:** desde el 49152 al 65535. El sistema operativo los da y libera a los clientes. Una vez un puerto se asigna a un cliente ya no puede ser asignado a otro.

HTTP es un protocolo *stateless*, es decir, no mantiene información sobre las peticiones de los clientes. Para ello utiliza *cookies*, que almacenan la información en el propio cliente.

Existen dos tipos de conexiones HTTP:

- **No persistentes:** se envía un objeto en cada conexión TCP, cerrándose esta cuando se ha terminado el envío.
- **Persistentes:** se pueden enviar varios objetos sobre una única conexión TCP entre el cliente y el servidor.

Podría parecer que la conexión persistente es la más idónea, ya que no hay que abrir y cerrar conexiones por cada elemento que queramos solicitar. Sin embargo, el navegador lanza conexiones no persistentes de forma *pseudo-paralela*, estando bastante optimizados en este aspecto.


##### 3.1.1. Mensajes HTTP

En una conexión HTTP se dan los siguientes pasos:

1. El cliente inicia la conexión y accede al servidor de una determinada dirección web, normalmente en el puerto 80.
2. El servidor acepta (o no) la conexión y envía una confirmación al cliente.
3. Si el servidor ha aceptado, el cliente envía el primer paquete o *request message*
4. El servidor responde con la información solicitada. Si la conexión es persistente, se realizan los pasos 3 y 4 varias veces. Si no, se cierra la conexión.


#### 3.2. Web cache

La caché sirve para ahorrar ancho de banda al resolver una petición que se ha realizado recientemente, o lo que es lo mismo, satisfacer el requisito del cliente sin involucrar al servidor destino.

La caché se basa en disponer de un servidor proxy. Un proxy HTTP es un intermediario por el que pasan todas las conexiones HTTP de la red, y es la única forma de comprobar si una petición se encuentra almacenada o no en caché.

Si un cliente realiza una petición, esta pasará por el proxy, que la guardará en caché. Si otro cliente la realiza tiempo después, será el propio proxy quien responda, ya que la tiene almacenada, respondiendo mucho más rápido.

Las respuestas en caché caducan, o pueden no estar actualizadas. Cuando otro cliente realiza la petición y esta se encuentra en la caché, el proxy envía una petición al servidor para comprobar que su copia está actualizada. Si lo está, envía la respuesta al cliente; si no, actualiza la caché y envía la respuesta al cliente.


### 4. El correo electrónico

En el **correo electrónico** intervienen cuatro componentes principales:

- **Cliente de correo (*user agent*)** y **servidor de correo(*mail server*):** son los agentes de la conversación (remitente y destinatario) y los servidores, respectivamente. Por cada origen y cada destino, hay un cliente y un servidor.
- **Simple Mail Transfer Protocol (SMTP):** es el protocolo utilizado para el correo electrónico, aunque no el único implicado en el proceso. 
- **Protocolos de descarga:** sirven para descargar el correo recibido. Algunos de ellos son **POP3**, **IMAP** y **HTTP**.

#### 4.1. SMTP (RFC 2821)

![SMTP](https://i.imgur.com/tywMwh8.png)


En la imagen podemos ver los pasos necesarios para el envío y recepción de un correo electrónico. Si pensamos bien, el modelo cliente-servidor no nos sirve para esto, ya que no es necesario que el destinatario del correo esté conectado para poder enviarlo. Necesitamos disponer de una especie de intermediario que recoja el correo por él, al que pueda pedírselo cuando sí esté en línea. 

Los pasos para el envío de un correo electrónico, algo más explicados que en la imagen, son los siguientes:

1. El usuario origen compone el correo dirigido al usuario destino, utilizando su *agente de usuario*.
2. Cada usuario tiene asociado un servidor de correo, válido tanto para enviar como para recibir. El usuario origen envía mediante SMTP o HTTP el mensaje a su servidor de correo, que dispone de dos colas: la **cola de salida**, a la que llegan los correos que han sido enviados, y la **cola de entrada**, en la que cada usuario del servidor tiene un espacio reservado en el que se reciben sus correos. 
3. Periodicamente, el servidor libera todos los correos de la cola de salida, estableciendo una **conexión TCP** con los servidores destino y enviándolos a través de la misma. Se establece una comunicación servidor-servidor.
4. El servidor del usuario destino ubica los mensajes dirigidos a él en su *mailbox* o espacio reservado.
5. El usuario, a través de su agente de usuario, descarga los correos utilizando **POP3**, **IMAP** o **HTTP**.

La comunicación entre los agentes es cliente-servidor, pero no siempre en el mismo sentido. El envío de correos entre servidores siempre se realiza utilizando SMTP, pero cuando un usuario descarga el correo, lo hace con el protocolo de descarga de su elección.

##### 4.1.1. Características de SMTP

SMTP se implementa en dos programas:

- **Cliente SMTP:** el servidor actúa como cliente cuando recibe un correo y tiene que reenviarlo a otro servidor. Para ello, activa un puerto dinámico que se conecta con el puerto 25 del destino, y envía el correo a través de esa conexión.
- **Servidor SMTP:** cuando enviamos un correo, el servidor escucha peticiones en el pueto 25.

Se utiliza el protocolo de transporte **TCP**, ya que no queremos perder información, y no necesitamos un envío instantáneo.

Las fases de SMTP, sin contar con las de conexión y desconexión de TCP, son tres:

- Conexión o *handshaking*.
- Transferencia de mensajes.
- Cierre.

La interacción entre cliente y servidor SMTP es interactiva, y se realiza mediante comandos-respuesta, de forma muy parecida a *telnet*. Cuando realizamos acciones desde nuestro cliente de correo (Thunderbird, Mailspring, web), están enviando comandos al servidor web.

Los mensajes deben estar codificados en ASCII de 7 bits, lo cual limita mucho la capacidad de enviar multimedia. Para sortear este problema se añadieron las **extensiones MIME**, para añadir otro tipo de codificación, sobre todo para archivos adjuntos.

#### 4.2. Protocolos de acceso al correo

El protocolo **POP3**, al igual que SMTP, tiene tres fases:

- **Fase de conexión:** se realiza una autenticación mediante usuario y contraseña.
- **Fase de transacción:** se listan los correos, asociándolos a un índice para operar con ellos (leer, eliminar, etc.). En POP3, tras leer un correo se elimina inmediatamente, ya que no está preparado para guardar correos a largo plazo.
- **Fase de actualización:** tras cerrar la conexión, se eliminan los correos que se le han indicado al servidor.

**IMAP** tiene ventajas frente a POP3:

- Es ***state-full***: permite organizar los correos en el servidor, y almacenarlos a largo plazo.
- Permite descargar partes de los mensajes.
- Se puede acceder desde varios clientes.

Y por último, **webmail** dispone de todas las ventajas de HTTP:

- **Organización total en el servidor:** el agente de correo está integrado en el servidor web.
- **Seguridad:** se utiliza HTTPS, y los emails se envían encriptados.

### 5. Protocolos seguros

#### 5.1. Primitivas de seguridad

Las primitivas de seguridad se clasifican en:

- **Confidencialidad:** sólo podrá acceder a la información quien deba hacerlo.
- **Responsabilidad:** es una primitiva muy amplia. Incluye:
  - Autenticación: los agentes de la comunicación deben estar identificados.
  - No repudio: no se puede negar la autoría de una determinada acción en la red.
  - Control de accesos: se debe comprobar quién se ha conectado, desde qué dispositivo, etc.
- **Integridad:** detección de alteraciones de la información, ya sean intencionadas o no. Nadie debería poder modificar la comunicación entre dos agentes, ni la información transmitida.
- **Disponibilidad:** los servicios deberían mantenerse de forma independiente al grueso de la demanda.

#### 5.2. Mecanismos de seguridad

**Cifrado**
Cifrar un mensaje consiste en alterarlo de forma que pueda ser recuperado, utilizando algún tipo de mecanismo. Normalmente suele utilizarse una clave para realizarlo, así como para deshacerlo (estas claves no tienen por qué coincidir). Hay varios tipos:

- **Cifrado simétrico:** la clave de cifrado es la misma que la de descifrado, y debe ser conocida únicamente por el remitente y el destinatario. Algunos de los algoritmos más utilizados para este cifrado son 3DES y AES.
*Problema:* si ambos agentes de la comunicación necesitan conocer la clave, esta debe ser enviada, de una forma u otra. Si es capturada junto con el mensaje, de nada sirve el cifrado.
- **Cifrado asimétrico:** surge para solucionar el problema de la clave única. Este cifrado utiliza dos claves, una para cifrar y otra para descifrar, y este par de claves se generan a partir de un algoritmo, de forma que no se puede calcular una a partir de otra. Estas dos claves funconan de la siguiente forma:
  - *Clave pública:* como su nombre indica, es pública, visible para todo el mundo.
  - *Clave privada:* solo la conoce el propio usuario, y no se envía nunca.

  El cifrado se realiza con la clave pública del destinatario, ya que   únicamente él, con su clave privada, podrá descifrar el mensaje. De esta forma evitamos enviar claves, y la pública no tiene ningún valor por sí misma. Los algoritmos son suficientemente complejos como para evitar que se pueda calcular una clave a partir de la otra, así que podemos respirar tranquilos.

**Funciones hash**
Las funciones hash son aquellas que, recibiendo un input, generan un identificador unívoco, minimizando colisiones. Como mecanismos de seguridad, se utilizan para asegurar que los mensajes no han sido modificados.

- **Message Authentication Code (MAC):** no se debe confundir con la dirección MAC de una tarjeta de red. Se trata de un hash que nos permite saber si un mensaje ha sido modificado o no. Suele combinarse con el cifrado, ya que si el hash está encriptado es imposible modificarlo. Ejemplos de algoritmos son MD5 y SHA-1.
- **Firma digital:** se utiliza para autenticar la autoría de un documento. El procedimiento consiste en hacer un hash del documento utilizando la clave privada, ya que es algo que únicamente posee el autor del documento. Utilizando la clave pública se podría comprobar quién ha firmado el documento. Esto funcionaría idealmente, pero no podemos garantizar que una persona es quien dice ser, así que suele entrar en la comunicación un tercer agente, la *entidad certificadora*.
- **Certificado:** las autoridades certificadoras permiten la creación de certificados, que son la asociación entre una identidad y una clave pública. En HTTPS, se comprueban los certificados de las páginas para evitar ataques de *phishing*.


#### 5.3. Seguridad perimetral

Hemos visto mecanismos para garantizar conexiones seguras, pero nos queda por ver la **seguridad perimetral**. Mientras que la seguridad perimetral física podría ser una valla, cámaras de seguridad o un foso lleno de cocodrilos, en nuestro ámbito nos referimos a los firewalls, sistemas de detección de intrusiones, etc. que nos permiten reaccionar ante determinados ataques.

**Firewalls**
Los firewalls a los que estamos acostumbrados son de sistemas finales. Sin embargo, aquí hablamos de los de redes, que se basan en una serie de reglas definidas par bloquear aquello que no tiene por qué pasar por la red.

**Sistemas de detección de intrusiones**
No bloquean el tráfico como los firewalls, sino que lo analizan en busca de anomalías según reglas definidas. El mas famoso es *Snort*, y es open source.


#### 5.4. Protocolos seguros

En las distintas capas de TCP/IP se definen una serie de **protocolos seguros**. Dependiendo de la capa en la que se encuentren, encontramos algunos.

**Capa de aplicación**
- **Secure Shell (SSH):** es el protocolo más usado en la capa de aplicación, ya que nos permite conectarnos remotamente al shell de un servidor, y está bastante estandarizado.
- **Pretty Good Privacy (PGP):** esquema general de seguridad. Originalmente se diseñó para correo electrónico, pero es prácticamente genérico. Utiliza cifrado asimétrico, simétrico, firma electrónica y certificado, y es fácil de implementar.

**Capa de sesión (entre aplicación y transporte)**
- **Secure Socket Layer (SSL) y Transport Secure Layer (TLS):** estos protocolos se encuentran realmente en la capa de aplicación, pero son necesarios para algunos protocolos. Por ejemplo, HTTPS está basado en aplicar SSL o TLS.

**Capa de red:** debajo se encuentra *IPSec*, que se utiliza para conexiones VPN. Encripta toda la comunicación en la capa de red.

### 6. Aplicaciones multimedia

Las **aplicaciones multimedia** son aquellas relacionadas con el audio y el vídeo, y en ellas la **calidad de servicio (*QoS*)** es muy importante, refiriéndonos a ella como la capacidad de ofrecer el rendimiento necesario para que la aplicación funcione correctamente. La calidad se puede medir en *máximo delay* o en *throughput necesario*.

Otra forma de evaluar la calidad sería preguntando al cliente si todo ha ido bien, como cuando terminamos una llamada en Skype o Telegram. Esto se denomina **calidad de experiencia**.

Gracias a estas medidas de calidad se intenta proveer un servicio multimedia en Internet, un medio que apenas ofrece garantías en este aspecto: no podemos asegurar un delay mínimo ni un throughput máximo, pero nuestro servicio los necesita.

#### 6.1. Tipos de aplicaciones

Existen tres tipos de aplicaciones multimedia, cada cual más complejo de implementar que el anterior:

- **Flujo de audio y vídeo almacenado (*streaming*):** no da muchos problemas, ya que, al almacenarse el audio o vídeo en un buffer intermedio, tenemos cierto margen para recibir el resto. En otras palabras, aunque se siga necesitando un throughput elevado, el delay no nos importa tanto, aunque es posible que debido a esto el usuario tenga que esperar un poco para iniciar la reproducción.
- **Flujo de audio y vídeo en vivo:** no podemos relajarnos tanto con el delay como en el caso anterior, aunque no importa que la retransmisión vaya un par de segundos por detrás de lo que está ocurriendo; el buffer intermedio sigue pudiendo utilizarse.
- **Audio y vídeo interactivo:** aquí la cosa se complica, ya que si queremos que la interactividad entre en juego necesitamos disponer de los paquetes lo antes posible. Si no, al hablar con alguien a través de servicios como Discord nos escucharían con segundos de retraso, y sería algo incómodo. Necesitamos que parezca que no hay una red entre los usuarios, sino que todo es inmediato.

#### 6.2. Características

- **Ancho de banda elevado.**
- Las aplicaciones son **tolerantes a la pérdida de datos**.

Para asegurar un buen funcionamiento, existen los siguientes mecanismos:

- **Delay acotado:** necesitamos asegurarnos de que debido al delay no llenemos el buffer intermedio, o empezaremos a sufrir desconexiones y se cortarña el audio o vídeo.
- ***Jitter* acotado:** el jitter es la *fluctuación* del delay. Si disponemos de un delay más o menos fijo, podremos gestionar el buffer intermedio correctamente. Si no es así, tendremos problemas, ya que podemos sufrir un delay mayor del esperado y tener cortes.
- **Multicast:** una forma de compensar el gran ancho de banda que necesitan las aplicaciones multimedia es el uso de **multicast**. Las comunicaciones en internet suelen ser *unicast*, es decir, tienen un único destino. Utilizando multicast, podemos establecer una especie de difusión parecida a la radio o a la televisión, a la que los usuarios se pueden suscribir para recibir el contenido, que se dividirá las veces que sea necesario hasta llegar a cada destino. De esta forma, únicamente necesitamos transmitir una señal para llegar a diferentes usuarios, ahorrando ancho de banda.




![multicast](https://i.imgur.com/u7bY3mE.png)



### 7. Aplicaciones para interconectividad de redes locales

#### 7.1. DHCP

Al conectarnos a una red, el router nos asigna una dirección IP de forma dinámica, ya que si no tendríamos que hacerlo de forma manual. De esto se encarga **DHCP (*Dynamic Host Configuration Protocol*)**, consiguiendo que la conexión a una red sea sencilla y accesible para usuarios sin conocimiento técnico.

DHCP nos asigna una dirección IP dentro del rango en el que esté configurado, la IP del servidor DNS primario y secundario, y el punto de acceso (normalmente un router) que vamos a utilizar.

DHCP no es usado únicamente para direcciones IP privadas, sino que los ISP lo utilizan al asignar las direcciones de los routers de forma que se ahorran costes, variando según el número de usuarios conectados cada cierto tiempo.

Los pasos que realiza DHCP para asignar una dirección son los siguientes:
1. El cliente, aún sin IP, envía un mensaje a una dirección **broadcast**, ya que no conoce la dirección del servidor DHCP. Este mensaje se denomina **DHCPDISCOVER**.
2. El servidor DHCP estará escuchando en el puerto 69, y al recibir la petición, responderá con un paquete llamado **DHCPOFFER**, enviándolo a la dirección broadcast de nuevo, de forma que el cliente la escuche en el puerto 68. El paquete incluye una dirección IP para el cliente y un identificador, por si hubiese más clientes solicitando direcciones.
3. El cliente, al escuchar el paquete anterior, puede solicitar dicha IP, ya que no se le ha asignado, sino simplemente ofrecido. Envía el paquete **DHCPREQUEST** a la dirección broadcast.
4. El servidor, al recibir el paquete, asignará la dirección al cliente, y enviará una confirmación mediante el paquete **DHCPACK**, de nuevo, a la dirección broadcast.

#### 7.2. DynDNS y No-IP

Estos servicios permiten instalar servidores detrás de un router y con una IP privada, previniendo los cambios de IP que los ISP realizan sobre la dirección pública del router mediante DHCP.

Desde fuera de casa podemos acceder a nuestro router, pero no a las máquinas conectadas a él. Estos servicios hacen posible el acceso, pudiendo utilizar los diferentes equipos conectados a él como servidores.

**DynDNS** asocia un nombre de dominio a la máquina a la que queremos acceder, y cuando la IP de nuestro router cambie, los servidores DNS se actualizarán rápidamente. El router deberá estar configurado para que redirija las peticiones a ese nombre de dominio a la máquina seleccionada. **No-IP** funciona de la misma forma.


#### 7.3. Universal Plug and Play

Este servicio es parecido a los anteriores, pero no utiliza un nombre de dominio para que se pueda acceder desde fuera. Lo utilizan servicios como Skype, que se comunican con el router para que realice la redirección comentada en el punto anterior.



## Tema 3: Capa de transporte en Internet

### 1. Introducción

La capa de transporte es aquella en la que se sitúan los protocolos que utilizaremos para enviar los paquetes de datos desde un punto a otro, controlando la comunicación de diferentes formas.

Veremos los protocolos **UDP** y **TCP**, y hablaremos de la multiplexación/demultiplexación de aplicaciones utilizando **puertos**. También estudiaremos algunas de las medidas de control que implementa TCP, tales como el **control de flujo**, **de errores** y **de congestión**.


### 2. UDP (*User Datagram Protocol*)

**UDP** es un servicio **no orientado a conexión**, en el que no se implementan medidas tales como control de flujo, errores o congestión. Se trata de un protocolo *best-effort*, ya que, al enviar los datos, no tiene ninguna forma de asegurarse de que han llegado al receptor. Por hacer una comparación, sería como enviar una carta; no puedes saber si la otra persona la ha recibido, ni si se ha perdido por el camino.

#### 2.1. Formato de cabecera UDP

La cabecera de un paquete UDP se compone de los siguientes campos:

- **Puerto origen** (2 Bytes)
- **Puerto destino** (2 Bytes)
- **Longitud UDP:** cabecera + datos (2 Bytes)
- **Checksum:** permite hacer un pequeño control de errores. Incluye cabecera, datos y una *pseudocabecera*, que incluye información de la capa de red, como la IP origen, destino, tipo de protocolo (en este caso UDP) y un campo que siempre se encuentra a 0 (también ocupa 2 Bytes).

En la **pseudocabecera** se incluyen las IPs para el cálculo del checksum, que se utiliza tanto para encontrar errores en las IPs como en la cabecera UDP. De esta forma podremos comprobar que el paquete que hemos recibido es para nosotros o se ha extraviado.

![demul-udp](https://i.imgur.com/gmeNgvn.png "Demultiplexación UDP")


En esta imagen vemos cómo realiza UDP la demultiplexación de paquetes, enviando los datos de todas las aplicaciones por el mismo canal, es decir, por la misma tarjeta de red; la información se **multiplexa** cuando se recibe y se **demultiplexa** cuando se envía.


#### 2.2. Cálculo del ckecksum

El **ckecksum** es algo utilizado tanto en UDP como TCP e IP, y se calcula siempre de la misma forma: calculando el complemento a uno de la suma en complemento a uno de las palabras de 16 bits de la pseudocabecera, cabecera y datos del paquete. Si el resultado contiene un número impar de octetos, se rellena con ceros por la derecha hasta obtener una palabra de 16 bits.

#### 2.3. Ejemplos de protocolos que utilizan UDP

| **Puerto** | **Servicio** | **Descripción** |
|------------|--------------|
| 53 | DNS | Servicio de nombre de dominio |
| 69 | TFTP | Versión simple de FTP |
| 123 | NTP | Protocolo de sincronización de tiempo de red |
| 161 | SNMP | Protocolo simple de administración de red |
| 520 | RIP | Protocolo de información de encaminamiento |

UDP también se utiliza en protocolos multimedia debido a su rapidez, ya que necesitamos que la información llegue rápido, y no nos importa perder algún paquete por el camino.


### 3. TCP (*Transmission Control Protocol*)

**TCP**, al contrario que UDP, e sun servicio **orientado a conexión**, ya que a la hora de enviar información se encarga de establecer una conexión entre las dos partes (conocido como *handshaking*), asegurarse de que los envíos se realizan correctamente (y si no es así, volver a realizarlos) y cerrar la conexión. Permite la entrega ordenada y el *full-duplex*.

En TCP, a cada paquete del flujo de datos se le llama **segmento**.

#### 3.1. Formato de cabecera TCP

Las cabeceras TCP contienen los siguientes campos:

- **Puerto origen**.

- **Puerto destino**.

- **Número de secuencia:** permite saber cuántos paquetes se han enviado.

- **Número de acuse de recibo:** permite saber cuántos paquetes han llegado al receptor.

- **Longitud de cabecera**.

- **Flags** con información especial.

- **Ventana:** se utiliza en control de flujo para poder enviar varios segmentos a la vez.

- **Checksum**.

- **Puntero de datos urgentes:** permite diferenciar los datos más importantes del resto dentro del *payload*.

- **Opciones:** este parámetro es variable, y se puede definir, por ejemplo, que la longitud de la cabecera sea variable.

  

![TCP](https://i.imgur.com/iWLTK8t.png "Campos de cabecera TCP")



#### 3.2. Control de conexión

##### 3.2.1. Conexión
Dado que TCP es un protocolo orientado a conexión, existe el concepto de **conexión**, con su inicio, transmisión de datos y desconexión. 

La conexión inicial en TCP se realiza con el llamado ***three way handshake***, llamado así porque utiliza tres segmentos: uno del origen al destino, otro del destino al origen y un último de nuevo del origen al destino. 

En el primer paquete se inicializa el número de secuencia (de forma pseudo-aleatoria, para evitar colisiones entre distintas conexiones paralelas), que se envía del origen al destino, inicializando el flag **SYN (sincronización)** a uno. Tras esto, el sistema operativo asigna un puerto a la conexión y envía el paquete sin payload, ya que es simplemente un paquete de control.

Cuando el paquete llega al destino, si consiguen conectarse, este enviará un paquete con el flag **ACK (acknowledge)** establecido a uno. Esto quiere decir que el número del acuse de recibo es válido, concretamente es el número de secuencia más uno. Esta información le da a conocer al emisor que la confirmación es de su paquete. Esto es muy importante, ya que el emisor estará enviando paquetes consecutivos, que pueden llegar desordenados, y tiene que saber cuáles han sido recibidos.

Al ser una conexión *full-duplex*, el destino también realizará lo mismo, inicializando su número de secuencia y estableciendo el flag SYN a uno. 

Cuando el origen recibe el segundo paquete, establece el flag ACK a uno, y comienzan a enviarse los segmentos con datos. el número de secuencia contabiliza los bytes que van en el flujo de datos, actuando como un puntero que señala a lo último que se ha enviado.


##### 3.2.2. Desconexión

Para realizar la **desconexión**, se realizan casi los mismos pasos que para establecer la conexión, pero utilizando un flag llamado **FIN**.
El host que quiere desconectar envía un segmento en el que establece el flag FIN a uno. Se enviarán el resto de datos, y cuando el otro lo reciba se confirmará la desconexión, enviando un paquete con el flag FIN.

Cuando el host que quiere desconectarse envía el paquete, inicia un temporizador antes de cerrar la conexión, por si el paquete de desconexión ha llegado antes que otros con datos.


##### 3.2.3. Números de secuencia

Los **números de secuencia** son campos de 32 bits, lo cual limita el número de valores en una conexión a 2^32. Si agotásemos los valores, empezarían de nuevo.

Para inicializar los números se utiliza el **ISN (Initial Sequence Number)**, que puede ser elegido por el sistema operativo o un número aleatorio. Según el estándar, se sugiere utilizar un contador entero que incremente su valor cada 4 microsegundos. Este contador no afecta a los flujos TCP, simplemente se consulta al iniciar una conexión.

Una vez inicializado, se incrementa según los datos enviados en el payload, no según el número de segmentos enviados. Existen, sin embargo, dos excepciones: los segmentos que lleven el flag SYN o el flag FIN a uno incrementan el número de secuencia en uno.



#### 3.3. Diagrama de estados de TCP

Este diagrama de estados está especificado en el RFC de TCP.

![tcp-state](https://i.imgur.com/RNYSVXM.png)



---



Cada nodo representa un estado en el que puede estar cualquiera de las dos máquinas conectadas mediante TCP.

En el lado del cliente se realiza una **apertura activa**, enviando un SYN (estado **SYN_SENT**), y tras esto esperaráun segmento con SYN + ACK. Finalmente, mandará un ACK, y pasará al estado **ESTABLISHED**, tras el cual se empiezan a enviar datos.

Desde el servidor se realiza una **apertura pasiva**. Inicialmente se encuentra en el estado **LISTEN**, escuchando peticiones en un puerto determinado. En cuanto reciba un SYN, responderá con un SYN + ACK, pasando al estado **SYN_RCVD**. Cuando reciba un ACK en este estado, pasará a **ESTABLISHED**.

Si nos fijamos, podemos ver que el **three way handshake** no es la única forma de establecer una conexión, aunque sí es la más simple y directa.

El cierre de la conexión funciona de forma similar, pudiendo realizar un **cierre activo** (enviar el flag FIN, recibir FIN + ACK, enviar ACK) o uno **pasivo** (recibir FIN, enviar FIN + ACK, recibir ACK).

Existen métodos alternativos, pero más largos, siendo muchos de ellos **four way handshake**, ya que necesitamos un paso más para terminar de enviar los datos antes de iniciar la desconexión.



#### 3.4. Control de errores y flujo

El **control de flujo** y el **control de congestión** se encargan de reducir la velocidad de la transmisión, el primero para no congestionar la red, y el segundo para no saturar al receptor. Además, comprueba que todos los paquetes se han recibido, y además en orden.

TCP envía segmentos juntos, ya que si tuviese que esperar a recibir el ACK de un segmento para enviar el siguiente, se perdería mucho tiempo (esta técnica se llama *stop&wait*).

Como queremos minimizar ese **tiempo muerto**, en lugar de enviar un único segmento se envían grupos llamados **ventanas**. Al enviar varios segmentos de golpe sin esperar ACK, reducimos el tiempo muerto. Aun así, seguimos recibiendo ACK de cada paquete, ya que si recibiésemos uno por ventana estaríamos en la misma situación que antes.

Esto suena bien, pero necesitamos saber si el receptor puede recibir todos esos datos a la velocidad de transmisión con la que se están enviando. Aquí entra en juego el **control de flujo**.

Utilizaremos dos medidas:

- **Confirmaciones positivas:** los ACK. Cuando llega un segmento que está bien, se pone un ACK indicando el siguiente valor que esperamos.
- **Timeout:** tiempo que se inicializa cuando se envía un segmento para que, en caso de que se pierda el segmento o el ACK, se envíe de nuevo la información.

El timeout puede dar problemas, ya que fijar un tiempo muy corto puede resultar en que se agote cuando se había enviado el ACK, y enviemos la información de nuevo sin necesidad, esperando el receptor el siguiente segmento.

Podemos ver las acciones que realiza TCP en esta tabla:

| **Evento**                                                   | **Acción del TCP receptor**                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Llegada ordenada de segmento, sin discontinuidad, todo lo anterior ya confirmado. | Retrasar ACK. Esperar a recibir el siguiente segmento hasta 500ms. Si no llega, enviar ACK. |
| Llegada ordenada del segmento, sin discontinuidad, hay pendiente un ACK retrasado. | Inmediatamente enviar un único ACK acumulativo.              |
| Llegada desordenada de segmento con número de secuencia mayor que el esperado, discontinuidad detectada. | Enviar un ACK duplicado, indicando el número de secuencia del siguiente byte esperado. |
| Llegada de un segmento que completa una discontinuidad parcial o totalmente. | Confirmar ACK inmediatamente si el segmento comienza en el extremo inferior de la discontinuidad. |



Mientras que en el emisor llevamos la cuenta de lo que hemos enviado, en el receptor lo tenemos para lo que nos ha llegado y lo que no, para que, una vez lo tengamos todo, lo mandemos a la capa de aplicación.



##### 3.4.1. Estimar los *timeouts*

Ya hemos visto lo que pasa si especificamos mal el timeout: podemos enviar datos más veces de las necesarias.  Por ello, hay que **estimar el timeout** de forma dinámica, dependiendo de la velocidad de la red.

Existe un modelo al que se ajustan más o menos las propuestas para estimar el timeout, y es fijarlo a partir de dos variables:

- **Estimador promedio (RTTmedido):** una especie de media del tiempo que se tarda desde que se emite un segmento hasta que se recibe su ACK.
- **Estimador sobre la desviación del promedio (Desviación):** desviación típica del timeout.

Nuestro timeout será RTTmedido + 4*Desviación. 

Estas variaciones siguen una distribución Gaussiana, es decir, aunque algunos puntos no concuerden, el 99.96% estarán entre la media más/menos la desviación típica multiplicada por tres. Si multiplicamos la desviación típica por cuatro, tendremos un timeout perfecto. 



##### 3.4.2. Ventana de transmisión

La ventana por la que transmitimos los segmentos se conoce como **ventana deslizante**, ya que se mueve por el flujo de datos, dividido en segmentos por TCP. Envía lo que está dentro, y avanza a medida que recibe ACKs, enviando más datos.

El control de flujo en TCP es un **sistema crediticio**, y su objetivo es no saturar al receptor (evitar un *buffer overflow*). Para implementar esto, el receptor avisa al emisor cuando quiere recibir datos, y esta información se mide en créditos: si el receptor puede aceptar 6KB, el crédito tendrá ese valor, mientras que si no puede recibir nada el valor del crédito será 0KB y se detendrá el envío de datos.

Este crédito se refleja en el parámetro **window** de la cabecera. Al enviar información también dejamos claro cuánta información podemos recibir, y si esto nos llega en los ACK del receptor, podemos saber cuánto tenemos que enviar.

El parámetro window refleja la capacidad del buffer de recepción que TCP utiliza para guardar los segmentos recibidos antes de enviarlos a la capa de aplicación. Dicho buffer es finito, y puede estar lleno o a medias. La parte del buffer que queda libre se denomina **ventana ofertada**.

Cuando el emisor recibe un segmento con la información del parámetro window, resta a la ventana ofertada los bytes que ha enviado pero no confirmado, ya que en el segmento en el que hemos recibido los datos de la ventana se nos ha confirmado la recepción hasta un determinado valor. Esto se llama **ventana útil**, y determina la cantidad de información que podemos enviar en cada momento.

Considerar los bytes en tránsito parece algo razonable, pero puede dar problemas. El buffer de recepción cada vez tendrá segmentos más pequeños si la capa de aplicación procesa los datos muy lentamente, y estaremos enviando paquetes con prácticamente más cabecera que contenido. Esto es conocido como el **síndrome de la ventana tonta**, y una posible solución es considerar que el receptor procesará los datos a medida que los vaya recibiendo (**ventana optimista**). Si se produce un buffer overflow, el emisor tendrá que enviar de nuevo algunos datos, pues no recibirá confirmación.

Otra posible solución sería retrasar el envío de la confirmación hasta acumular un mínimo de espacio libre en el buffer de recepción, y así el parámetro window siempre tendrá un crédito mínimo. El emisor también podría implementar esto, esperando a recibir un crédito determinado para reanudar el envío.



##### 3.4.3. Información urgente

Existen dos flags para indicar a TCP que debe dar prioridad a algunos datos:

- **URG:** cuando al receptor le llega un paquete con el flag URG activo, ignora el buffer de recepción y envía la información directamente a la capa de aplicación. Estos datos están situados al inicio de un paquete, y el puntero que marca la separación se activa cuando el flag está a uno.
- **PSH (Push):** este flag se inicializa desde la capa del emisor, e indica a TCP que esa información es tan importante que debe ser mandada, sin esperar a leer datos para rellenar un segmento completo. Cuando llega al receptor se hace lo mismo que con URG: enviar los datos directamente a la capa de aplicación.

URG está prácticamente obsoleto.



#### 3.5. Control de congestión

Mientras que el control de flujo se aseguraba de que el receptor no se saturase, en el **control de congestión** se procurará que la red no se sature.

Esto nos da algún que otro problema, ya que la red no tiene un parámetro **window** que nos diga cuánta información podemos mandar, sino que se debe detectar cuándo está saturada la red. Para ello, el emisor debe medir de alguna forma el tiempo, y la forma más sencilla es controlando **el retraso o la pérdida de ACKs**: si un ACK no llega a tiempo (o directamente no llega), algo debe haber pasado, aunque no tiene por qué ser debido a la congestión de la red. Esto es algo que debemos estimar de algún modo.

Existen diferentes versiones de TCP, y su mayor diferencia es cómo gestionan la congestión de la red. La versión inicial de TCP, **TCP Tahoe**, prefiere perder velocidad de transmisión antes que saturar la red.

TCP Tahoe realiza el control de congestión de la siguiente forma:

La velocidad de transmisión se controla con la **ventana de congestión**, y al iniciar la conexión, TCP la inicializa al tamaño máximo que puede ocupar un segmento. Este estado se denomina **inicio lento**, ya que comenzamos con una ventana pequeña y vamos aumentándola exponencialmente.

Si el tamaño de congestión se encuentra por debajo de un determinado **umbral**, por cada ACK recibido se **duplica** el tamaño de la ventana de congestión.

Una vez se alcance el umbral, cada vez que se reciba un ACK se aumentará el tamaño de la ventana de forma **lineal**, aumentando el tamaño de la ventana de congestión en un MSS. Esta estrategia se denomina **prevención de la congestión**.

Una vez se detecta que la red se ha saturado mediante un **timeout**, realizamos lo siguiente:

1. Fijamos un nuevo umbral como la mitad de la ventana de congestión:
     ![umbral](http://www.sciweavers.org/tex2img.php?eq=Umbral%20%3D%20%5Clceil%20%5Cfrac%7BVcongestion%7D%7B2%7D%20%5Crceil&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0)
2. Reestablecemos el tamaño de la ventana de congestión a un MSS.

Cada vez que se produzca un timeout, el algoritmo Tahoe reducirá drásticamente la velocidad de conexión, por lo que se han planteado alternativas, como **TCP Reno**. En Reno, cuando se produce un timeout, la ventana de congestión vuelve a la mitad del tamaño que había alcanzado, creciendo de forma lineal a partir de ese punto.

![tahoe reno](https://i.imgur.com/YzKyHWc.png)

Tahoe funciona mejor cuando realmente la red se ha congestionado, ya que reducirá bastante la velocidad y la red podrá recuperarse. Sin embargo, en las falsas alarmas (un ACK perdido o retrasado), Reno sería mejor, ya que no perdemos todo lo que habíamos alcanzado por error, solo una parte.



#### 3.6. Combinación entre control de flujo y congestión

El control de flujo limita la velocidad cuando el receptor se satura, y el de congestión lo hace cuando es la red la que lo hace. Entonces, ¿cómo debemos actuar cuando sucede una de estas dos cosas? Fácil: escogemos la más restrictiva, es decir, el mínimo entre la ventana de congestión y la que ofrece el receptor en el parámetro window.

A la hora de enviar, a no ser que queramos evitar la ventana tonta, debemos calcular también la ventana útil, restando al resultado anterior los bytes en tránsito.



## Tema 4: Redes conmutadas e Internet

La capa de red actúa como una interfaz para la capa de enlace, permitiendo que las distintas tecnologías de las redes presentes en Internet se comuniquen entre sí. Para ello, la capa de red cuenta con las siguientes funcionalidades:

- Conmutación.
- Encaminamiento.
- Interconexión de redes.
- Control de congestión.

En el modelo OSI, el control de congestión se encuentra en la capa de red. Sin embargo, en TCP/IP está en la capa de transporte, es decir, lo realiza el protocolo TCP, como ya hemos visto.

El ejemplo más claro de protocolo de red es **IP**.



### 1. Conmutación

> *La **Conmutación** se considera como la acción de establecer una vía, un camino, de extremo a extremo entre dos puntos, un emisor (Tx) y un receptor (Rx) a través de nodos o equipos de transmisión. La conmutación permite la entrega de la señal desde el origen hasta el destino requerido.*

Definición de conmutación en [Wikipedia](https://es.wikipedia.org/wiki/Conmutación_%28redes_de_comunicación%29).

La **conmutación** en internet se encarga de conectar dos puntos para transmitir información. Podría verse como una redirección, pero es más complejo. Hay diferentes formas de realizarla:

- **Conmutación basada en *circuitos*:** se establece un circuito entre los dos puntos para realizar la comunicación, pasando por nodos intermedios, al iniciar la comunicación. Dicho circuito permanecerá durante el resto de la comunicación, y los recursos del mismo estarán destinados únicamente a esa comunicación. Un ejemplo de este tipo de conmutación es la *red telefónica*.

- **Conmutación basada en *paquetes***, que se divide en:

  - **Conmutación basada en *datagramas*:** esta es la conmutación basada en paquetes como tal. La comunicación se divide en paquetes y cada uno es una entidad independiente que viaja a través de Internet por posibles caminos diferentes.
  - **Conmutación basada en *circuitos virtuales*:** es una mezcla entre la conmutación por circuitos y por paquetes, en la que se envían los paquetes siguiendo el mismo camino.

#### 1.1. Conmutación de circuitos

Como hemos comentado antes, el ejemplo más claro de conmutación de circuitos es la red telefónica tradicional. cada línea instalada en casa está conectada con una central local. Esa central, a su vez, está conectada con más nodos a nivel regional, y estos a nivel nacional. Cada vez que realizamos una llamada, se define un circuito entre un terminal y otro pasando por estos nodos, completamente dedicado a la llamada.

Aunque no estemos enviando información, seguimos teniendo esa porción de línea asignada. Por ejemplo, cuando nos quedamos callados en una llamada, se está enviando información vacía. Dicho de otro modo, estamos malgastando recursos, pero de esta forma minimizamos retardos, ya que si no, tendríamos que volver a reservar recursos cuando quisiésemos volver a hablar. El único retardo existente es el tiempo que tarda la red en asignar el circuito entre los dos nodos terminales.

La conmutación de circuitos tiene varios pasos:

1. **Conexión:** se reservan los recursos para la comunicación. En la llamada telefónica, se conectan las dos líneas. Una vez se escucha señal ya se ha establecido la comunicación, independientemente de que el receptor descuelgue la llamada o no.
2. **Transmisión.**
3. **Desconexión.**

En TCP considerábamos Internet como un medio uniforme por el cual se transmitían los datos de forma directa. Sin embargo, en la capa de red ya percibimos con más detalle los distintos nodos intermedios por los que pasa la información.



![diagrama circuito](https://i.imgur.com/C61K0HW.png)

En este diagrama podemos observar el tiempo que se tarda en transmitir la información utilizando conmutación basada en circuitos. En el primer envío se establece la comunicación, y en los posteriores apenas hay retardos, ya que se han reservado los recursos.

La parte negativa de la conmutación por circuitos es que necesitamos una infraestructura mucho mayor que una red de comunicación basada en paquetes para el mismo número de usuarios.



#### 1.2. Conmutación de paquetes

##### 1.2.1. Conmutación de datagramas

La **conmutación de datagramas** es la versión más purista de la conmutación de paquetes, y es la utilizada por el protocolo IP. En ella no existe la conexión como tal, pues no es necesario reservar recursos. Sin embargo, cada paquete que enviemos sufrirá un retardo de procesamiento al pasar por cada nodo.

![diagrama paquetes](https://i.imgur.com/vzkGag6.png)



Cada paquete deberá llevar información sobre su destino, al ser entidades lógicas independientes. Por tanto, cada paquete puede ser encaminado por un sitio distinto, y los paquetes no tienen por qué llegar ordenados, ni el número de nodos intermedios ser el mismo. El diagrama de arriba no es realista, pero ayuda a comprender cómo viajan los paquetes por la red.

##### 1.2.2. Conmutación de paquetes con circuitos virtuales

En este tipo de conmutación, se crea un circuito por encima de la red basada en datagramas para enviar por él todos los paquetes y reducir el tiempo de procesamiento. 

No obstante, existe un problema: la **menor robustez**. En la red conmutada por datagramas sabemos que, aunque un enlace entre dos nodos se caiga, los paquetes podrán llegar por otras vías, ya que son independientes . Si el circuito virtual que se ha definido cae, habrá que realizar uno nuevo, algo que también pasaba en la conmutación por circuitos. 

Al contrario que la conmutación basada en circuitos, no dispone de recursos dedicados exclusivamente a la comunicación, simplemente utiliza una ruta para enviar todos los paquetes por ella, pero no es exclusiva. Esto hace que no necesitemos una infraestructura mayor, como sí pasaba con los circuitos.



### 2. El protocolo IP

El protocolo **IP** o protocolo de Internet se utiliza para enviar datos de forma bidireccional a través de distintas redes físicas intercomunicadas.  Actualmente se utilizan dos versiones, **IPv4**, la más extendida, e **IPv6**. IPv6 soluciona bastantes problemas que IPv4 tenía, y se ha hecho un gran esfuerzo por extenderlo.

IP permite la interconexión de redes y el direccionamiento en internet mediante las **direcciones IP**. Se utiliza el enrutamiento para enviar paquetes. Es un protocolo no orientado a conexión, muy parecido a UDP.

También gestiona la fragmentación, ya que en Internet coexisten muchos tipos de tecnologías, cada una de ellas preparada para un **tamaño máximo de paquete (MTU)**. IP se encarga de fragmentar los paquetes en caso de que sea necesario al pasar de una red a otra.

#### 2.1. Direcciones IP

Cada punto conectado en Internet dispone de una dirección IP que lo identifica. Aunque normalmente utilicemos el nombre de dominio para acceder a servidores y sitios, el protocolo DNS se encarga de traducirlo automáticamente a su dirección IP correspondiente.







