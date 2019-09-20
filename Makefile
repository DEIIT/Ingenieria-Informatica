
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
  # #                                                                     # #
  # #           ____  _____ ___ ___ _____   _   _  ____ ____              # #
  # #          |  _ \| ____|_ _|_ _|_   _| | | | |/ ___|  _ \ _           # #
  # #          | | | |  _|  | | | |  | |   | | | | |  _| |_) (_)          # #
  # #          | |_| | |___ | | | |  | |   | |_| | |_| |  _ < _           # #
  # #          |____/|_____|___|___| |_|    \___/ \____|_| \_(_)          # #
  # #                                                                     # #
  # #                                                                     # #
  # #           __  __    _    _  _______ _____ ___ _     _____           # #
  # #          |  \/  |  / \  | |/ / ____|  ___|_ _| |   | ____|          # #
  # #          | |\/| | / _ \ | ' /|  _| | |_   | || |   |  _|            # #
  # #          | |  | |/ ___ \| . \| |___|  _|  | || |___| |___           # #
  # #          |_|  |_/_/   \_\_|\_\_____|_|   |___|_____|_____|          # #
  # #                                                                     # #
  # #                                                                     # #
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
  # #                                                                     # #
  # #  INSTRUCCIONES DE USO                                               # #
  # #                                                                     # #
  # #    > Deben incluirse instrucciones de compilación de todos los      # #
  # #      archivos que se añadan al repositorio                          # #
  # #    > Lo más sencillo es buscar el código de la asignatura sore la   # #
  # #      que se han añadido archivos para encontrarla rápidamente       # #
  # #    > En caso de crear instrucciones de compilación nuevas, deben    # #
  # #      introducirse en una macro para su uso fácil y documentado      # #
  # #    > Todos los commits deberán haber confirmado previamente la      # #
  # #      correcta ejecución del makefile                                # #
  # #                                                                     # #
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
  # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


  # MACROS SOBRE LA ESTRUCTURA DEL REPOSITORIO
  #
  #    Macros de búsqueda de directorios y resumen de órdenes. Estructura:
  #     - Directorios principales (cuatrimiestres y ramas de 3º y 4º)
  #     - Directorios de asignaturas (orden alfabético de código)
  #     - Directorios out (Donde se guardan los archivos compilados)
  #        - Directorios out principales
  #        - Directorios out de asignaturas
  #     - Macros de instrucciones

 #
  # Directorios principales
 #

HOME = .

# Cuatrimestres
C11  =  $(HOME)/1º\ 1er\ cuatrimestre
C12  =  $(HOME)/1º\ 2º\ cuatrimestre
C21  =  $(HOME)/2º\ 1er\ cuatrimestre
C22  =  $(HOME)/2º\ 2º\ cuatrimestre
C31  =  $(HOME)/3º\ 1er\ cuatrimestre
C32  =  $(HOME)/3º\ 2º\ cuatrimestre
C41  =  $(HOME)/4º\ 1er\ cuatrimestre
C42  =  $(HOME)/4º\ 2º\ cuatrimestre
FCI  =  $(HOME)/Formación\ complementaria\ interdisciplinar
PE   =  $(HOME)/Prácticas\ de\ empresa
TFG  =  $(HOME)/Trabajo\ de\ fin\ de\ grado

# Ramas 3º 2º cuatrimestre
CSI32 =  $(C32)/Computación\ y\ sistemas\ inteligentes
IC32  =  $(C32)/Ingeniería\ de\ computadores
IS32  =  $(C32)/Ingeniería\ de\ software
SI32  =  $(C32)/Sistemas\ de\ información
TI32  =  $(C32)/Tecnología\ de\ la\ información

# Ramas 4º 1er cuatrimestre
CSI41 =  $(C41)/Computación\ y\ sistemas\ inteligentes
IC41  =  $(C41)/Ingeniería\ de\ computadores
IS41  =  $(C41)/Ingeniería\ de\ software
SI41  =  $(C41)/Sistemas\ de\ información
TI41  =  $(C41)/Tecnología\ de\ la\ información

# Ramas 4º 2º cuatrimestre
CSI42 =  $(C42)/Computación\ y\ sistemas\ inteligentes
IC42  =  $(C42)/Ingeniería\ de\ computadores
IS42  =  $(C42)/Ingeniería\ de\ software
SI42  =  $(C42)/Sistemas\ de\ información
TI42  =  $(C42)/Tecnología\ de\ la\ información

 #
  # Directorios de asignaturas
 #

AA   =  $(CSI32)/Aprendizaje\ automático
AC   =  $(C22)/Arquitectura\ de\ computadores
ACAP =  $(CSI32)/Arquitectura\ y\ computación\ de\ altas\ prestaciones
ADB  =  $(SI32)/Administración\ de\ bases\ de\ datos
ALEM =  $(C11)/Álgebra\ lineal\ y\ estructuras\ matemáticas
ALG  =  $(C22)/Algorítmica
AO   =  $(IS42)/Animación\ por\ ordenador
AS   =  $(IC32)/Arquitectura\ de\ sistemas
BDD  =  $(IS41)/Bases\ de\ datos\ distribuidas
CA   =  $(C11)/Cálculo
CEGE =  $(FCI)/Creación\ de\ empresas\ y\ gestión\ emprendedora
CII  =  $(IC42)/Circuitos\ integrados\ e\ impresos
CPD  =  $(IC41)/Centros\ de\ procesamiento\ de\ datos
CRIM =  $(TI41)/Compresión\ y\ recuperación\ de\ información\ multimedia
CRIP =  $(CSI42)/Criptografía\ y\ computación
CUIA =  $(TI32)/Computación\ ubicua\ e\ inteligencia\ ambiental
DAI  =  $(TI41)/Desarrollo\ de\ aplicaciones\ para\ internet
DBA  =  $(IS41)/Desarrollo\ basado\ en\ agentes
DDSI =  $(C31)/Diseño\ y\ desarrollo\ de\ sistemas\ de\ información
DGP  =  $(IS41)/Dirección\ y\ gestión\ de\ proyectos
DHD  =  $(IC32)/Desarrollo\ de\ hardware\ digital
DI   =  $(FCI)/Derecho\ informático
DIU  =  $(IS32)/Diseño\ de\ interfaces\ de\ usuario
DS   =  $(IS32)/Desarrollo\ de\ software
DSE  =  $(IC32)/Diseño\ de\ sistemas\ electrónicos
DSD  =  $(IS32)/Desarrollo\ de\ sistemas\ distribuidos
EC   =  $(C21)/Estructura\ de\ computadores
ED   =  $(C21)/Estructura\ de\ datos
EISI =  $(FCI)/Ética,\ informática\ y\ sociedad\ de\ la\ información
ES   =  $(C12)/Estadística
GRD  =  $(IS41)/Gestión\ de\ recursos\ digitales
FBD  =  $(C22)/Fundamentos\ de\ bases\ de\ datos
FFT  =  $(C11)/Fundamentos\ físicos\ y\ tecnológicos
FIS  =  $(C22)/Fundamentos\ de\ ingeniería\ del\ software
FP   =  $(C11)/Fundamentos\ de\ programación
FR   =  $(C31)/Fundamentos\ de\ redes
FS   =  $(C11)/Fundamentos\ del\ software
IA   =  $(C22)/Inteligencia\ artificial
IC   =  $(CSI32)/Ingeniería\ del\ conocimiento
IES  =  $(C12)/Ingeniería,\ empresa\ y\ sociedad
IG   =  $(C31)/Informática\ gráfica
II   =  $(IC41)/Informátia\ industrial
IN   =  $(IS41)/Inteligencia\ de\ negocio
ISE  =  $(C31)/Ingeniería\ de\ servidores
ISI  =  $(SI32)/Ingeniería\ de\ sistemas\ de\ información
IV   =  $(TI41)/Infraestructura\ virtual
LMD  =  $(C12)/Lógica\ y\ métidos\ discretos
LP   =  $(IS41)/Lógica\ y\ programación
MC   =  $(C31)/Modelos\ de\ computación
MCA  =  $(CSI32)/Modelos\ de\ computación\ avanzada
MDA  =  $(IS41)/Metodologías\ de\ desarrollo\ ágil
MEI  =  $(IC42)/Mantenimiento\ de\ equipos\ informáticos
MH   =  $(CSI32)/Metaheurísticas
MP   =  $(C12)/Metodología\ de\ la\ programación
NPI  =  $(CSI41)/Nuevos\ paradigmas\ de\ interacción
NTP  =  $(IS42)/Nuevas\ tecnologías\ de\ la\ programación
PDIH =  $(SI42)/Periféricos\ y\ dispositivos\ de\ interfaz\ humana
PDM  =  $(TI42)/Programación\ de\ dispositivos\ móviles
PDOO =  $(C21)/Programación\ y\ diseño\ orientado\ a\ objetos
PDS  =  $(TI42)/Procesamiento\ digital\ de\ señales
PGV  =  $(IS41)/Programación\ gráfica\ de\ videojuegos
PL   =  $(CSI41)/Procesadores\ de\ lenguajes
PLD  =  $(CSI42)/Programación\ lúdica
PPR  =  $(IS42)/Programaciones\ paralelas
PTC  =  $(CSI41)/Programación\ técnica\ y\ científica
PW   =  $(SI32)/Programación\ web
RMS  =  $(TI42)/Redes\ multiservicio
RI   =  $(CSI42)/Robótica\ industrial
RINF =  $(IS41)/Recuperación de\ información
RSC  =  $(IS41)/Redes\ y\ sistemas\ complejos
SCD  =  $(C21)/Sistemas\ concurrentes\ y\ distribuidos
SCGC =  $(SI42)/Sistemas\ cooperativos\ y\ gestión\ de\ contenidos
SE   =  $(IC41)/Sistemas\ empotrados
SG   =  $(IS32)/Sistemas\ gráficos
SIBW =  $(IS32)/Sistemas\ de\ información\ basados\ en\ web
SIE  =  $(SI32)/Sistemas\ de\ información\ para\ empresas
SIG  =  $(IS41)/Sistemas\ de\ información\ geográficos
SMD  =  $(SI32)/Sistemas\ multidimensionales
SMM  =  $(TI32)/Sistemas\ multimedia
SMP  =  $(IC32)/Sistemas\ con\ microprocesadores
SO   =  $(C21)/Sistemas\ operativos
SPSI =  $(TI41)/Seguridad\ y\ protección\ de\ sistemas\ informáticos
SS   =  $(CSI41)/Simulación\ de\ sistemas
SSO  =  $(IS41)/Seguridad\ en\ sistemas\ operativos
SWAP =  $(TI32)/Servidores\ web\ de\ altas\ prestaciones
TDRC =  $(TI32)/Transmisión\ de\ datos\ y\ redes\ de\ computadores
TE   =  $(IC41)/Tecnologías\ emergentes
TIC  =  $(CSI41)/Teoría\ de\ la\ información\ y\ la\ codificación
TID  =  $(TI41)/Tratamiento\ de\ imágenes\ digitales
TOC  =  $(C12)/Tecnología\ y\ organización\ de\ los\ computadores
TSI  =  $(CSI32)/Técnicas\ de\ los\ sistemas\ inteligentes
TR   =  $(IC41)/Tecnologías\ de\ red
TW   =  $(TI32)/Tecnologías\ web
VC   =  $(CSI41)/Visión\ por\ computador

 #
  # Directorios out principales
 #

OUT = $(HOME)/Ingenieria-Informatica

# Cuatrimestres
C11_OUT  =  $(OUT)/1º\ 1er\ cuatrimestre
C12_OUT  =  $(OUT)/1º\ 2º\ cuatrimestre
C21_OUT  =  $(OUT)/2º\ 1er\ cuatrimestre
C22_OUT  =  $(OUT)/2º\ 2º\ cuatrimestre
C31_OUT  =  $(OUT)/3º\ 1er\ cuatrimestre
C32_OUT  =  $(OUT)/3º\ 2º\ cuatrimestre
C41_OUT  =  $(OUT)/4º\ 1er\ cuatrimestre
C42_OUT  =  $(OUT)/4º\ 2º\ cuatrimestre
FCI_OUT  =  $(OUT)/Formación\ complementaria\ interdisciplinar
PE_OUT   =  $(OUT)/Prácticas\ de\ empresa
TFG_OUT  =  $(OUT)/Trabajo\ de\ fin\ de\ grado

# Ramas 3º 2º cuatrimestre
CSI32_OUT =  $(C32_OUT)/Computación\ y\ sistemas\ inteligentes
IC32_OUT  =  $(C32_OUT)/Ingeniería\ de\ computadores
IS32_OUT  =  $(C32_OUT)/Ingeniería\ del\ software
SI32_OUT  =  $(C32_OUT)/Sistemas\ de\ información
TI32_OUT  =  $(C32_OUT)/Tecnología\ de\ la\ información

# Ramas 4º 1er cuatrimestre
CSI41_OUT =  $(C41_OUT)/Computación\ y\ sistemas\ inteligentes
IC41_OUT  =  $(C41_OUT)/Ingeniería\ de\ computadores
IS41_OUT  =  $(C41_OUT)/Ingeniería\ del\ software
SI41_OUT  =  $(C41_OUT)/Sistemas\ de\ información
TI41_OUT  =  $(C41_OUT)/Tecnología\ de\ la\ información

# Ramas 4º 2º cuatrimestre
CSI42_OUT = $(C42_OUT)/Computación\ y\ sistemas\ inteligentes
IC42_OUT  =  $(C42_OUT)/Ingeniería\ de\ computadores
IS42_OUT  =  $(C42_OUT)/Ingeniería\ del\ software
SI42_OUT  =  $(C42_OUT)/Sistemas\ de\ información
TI42_OUT  =  $(C42_OUT)/Tecnología\ de\ la\ información

 #
  # Directorios out de asignaturas
 #

AA_OUT   =  $(CSI32_OUT)/Aprendizaje\ automático
AC_OUT   =  $(C22_OUT)/Arquitectura\ de\ computadores
ACAP_OUT =  $(CSI32_OUT)/Arquitectura\ y\ computación\ de\ altas\ prestaciones
ADB_OUT  =  $(SI32_OUT)/Administración\ de\ bases\ de\ datos
ALEM_OUT =  $(C11_OUT)/Álgebra\ lineal\ y\ estructuras\ matemáticas
ALG_OUT  =  $(C22_OUT)/Algorítmica
AO_OUT   =  $(IS42_OUT)/Animación\ por\ ordenador
AS_OUT   =  $(IC32_OUT)/Arquitectura\ de\ sistemas
BDD_OUT  =  $(SI41_OUT)/Bases\ de\ datos\ distribuidas
CA_OUT   =  $(C11_OUT)/Cálculo
CEGE_OUT =  $(FCI_OUT)/Creación\ de\ empresas\ y\ gestión\ emprendedora
CII_OUT  =  $(IC42_OUT)/Circuitos\ integrados\ e\ impresos
CPD_OUT  =  $(IC41_OUT)/Centros\ de\ procesamiento\ de\ datos
CRIM_OUT =  $(TI41_OUT)/Compresión\ y\ recuperación\ de\ información\ multimedia
CRIP_OUT =  $(CSI42_OUT)/Criptografía\ y\ computación
CUIA_OUT =  $(TI32_OUT)/Computación\ ubicua\ e\ inteligencia\ ambiental
DAI_OUT  =  $(TI41_OUT)/Desarrollo\ de\ aplicaciones\ para\ internet
DBA_OUT  =  $(IS41_OUT)/Desarrollo\ basado\ en\ agentes
DDSI_OUT =  $(C31_OUT)/Diseño\ y\ desarrollo\ de\ sistemas\ de\ información
DGP_OUT  =  $(IS41_OUT)/Dirección\ y\ gestión\ de\ proyectos
DHD_OUT  =  $(IC32_OUT)/Desarrollo\ de\ hardware\ digital
DI_OUT   =  $(FCI_OUT)/Derecho\ informático
DIU_OUT  =  $(IS32_OUT)/Diseño\ de\ interfaces\ de\ usuario
DS_OUT   =  $(IS32_OUT)/Desarrollo\ de\ software
DSE_OUT  =  $(IC32_OUT)/Diseño\ de\ sistemas\ electrónicos
DSD_OUT  =  $(IS32_OUT)/Desarrollo\ de\ sistemas\ distribuidos
EC_OUT   =  $(C21_OUT)/Estructura\ de\ computadores
ED_OUT   =  $(C21_OUT)/Estructura\ de\ datos
EISI_OUT =  $(FCI_OUT)/Ética,\ informática\ y\ sociedad\ de\ la\ información
ES_OUT   =  $(C12_OUT)/Estadística
GRD_OUT  =  $(SI41_OUT)/Gestión\ de\ recursos\ digitales
FBD_OUT  =  $(C22_OUT)/Fundamentos\ de\ bases\ de\ datos
FFT_OUT  =  $(C11_OUT)/Fundamentos\ físicos\ y\ tecnológicos
FIS_OUT  =  $(C22_OUT)/Fundamentos\ de\ ingeniería\ del\ software
FP_OUT   =  $(C11_OUT)/Fundamentos\ de\ programación
FR_OUT   =  $(C31_OUT)/Fundamentos\ de\ redes
FS_OUT   =  $(C11_OUT)/Fundamentos\ del\ software
IA_OUT   =  $(C22_OUT)/Inteligencia\ artificial
IC_OUT   =  $(CSI32_OUT)/Ingeniería\ del\ conocimiento
IES_OUT  =  $(C12_OUT)/Ingeniería,\ empresa\ y\ sociedad
IG_OUT   =  $(C31_OUT)/Informática\ gráfica
II_OUT   =  $(IC41_OUT)/Informátia\ industrial
IN_OUT   =  $(SI41_OUT)/Inteligencia\ de\ negocio
ISE_OUT  =  $(C31_OUT)/Ingeniería\ de\ servidores
ISI_OUT  =  $(SI32_OUT)/Ingeniería\ de\ sistemas\ de\ información
IV_OUT   =  $(TI41_OUT)/Infraestructura\ virtual
LMD_OUT  =  $(C12_OUT)/Lógica\ y\ métidos\ discretos
LP_OUT   =  $(IS41_OUT)/Lógica\ y\ programación
MC_OUT   =  $(C31_OUT)/Modelos\ de\ computación
MCA_OUT  =  $(CSI32_OUT)/Modelos\ de\ computación\ avanzada
MDA_OUT  =  $(IS41_OUT)/Metodologías\ de\ desarrollo\ ágil
MEI_OUT  =  $(IC42_OUT)/Mantenimiento\ de\ equipos\ informáticos
MH_OUT   =  $(CSI32_OUT)/Metaheurísticas
MP_OUT   =  $(C12_OUT)/Metodología\ de\ la\ programación
NPI_OUT  =  $(CSI41_OUT)/Nuevos\ paradigmas\ de\ interacción
NTP_OUT  =  $(IS42_OUT)/Nuevas\ tecnologías\ de\ la\ programación
PDIH_OUT =  $(SI42_OUT)/Periféricos\ y\ dispositivos\ de\ interfaz\ humana
PDM_OUT  =  $(TI42_OUT)/Programación\ de\ dispositivos\ móviles
PDOO_OUT =  $(C21_OUT)/Programación\ y\ diseño\ orientado\ a\ objetos
PDS_OUT  =  $(TI42_OUT)/Procesamiento\ digital\ de\ señales
PGV_OUT  =  $(IS41_OUT)/Programación\ gráfica\ de\ videojuegos
PL_OUT   =  $(CSI41_OUT)/Procesadores\ de\ lenguajes
PLD_OUT  =  $(CSI42_OUT)/Programación\ lúdica
PPR_OUT  =  $(IS42_OUT)/Programaciones\ paralelas
PTC_OUT  =  $(CSI41_OUT)/Programación\ técnica\ y\ científica
PW_OUT   =  $(SI32_OUT)/Programación\ web
RMS_OUT  =  $(TI42_OUT)/Redes\ multiservicio
RI_OUT   =  $(CSI42_OUT)/Robótica\ industrial
RINF_OUT =  $(SI41_OUT)/Recuperación\ de\ información
RSC_OUT  =  $(SI41_OUT)/Redes\ y\ sistemas\ complejos
SCD_OUT  =  $(C21_OUT)/Sistemas\ concurrentes\ y\ distribuidos
SCGC_OUT =  $(SI42_OUT)/Sistemas\ cooperativos\ y\ gestión\ de\ contenidos
SE_OUT   =  $(IC41_OUT)/Sistemas\ empotrados
SG_OUT   =  $(IS32_OUT)/Sistemas\ gráficos
SIBW_OUT =  $(IS32_OUT)/Sistemas\ de\ información\ basados\ en\ web
SIE_OUT  =  $(SI32_OUT)/Sistemas\ de\ información\ para\ empresas
SIG_OUT  =  $(SI41_OUT)/Sistemas\ de\ información\ geográficos
SMD_OUT  =  $(SI32_OUT)/Sistemas\ multidimensionales
SMM_OUT  =  $(TI32_OUT)/Sistemas\ multimedia
SMP_OUT  =  $(IC32_OUT)/Sistemas\ con\ microprocesadores
SO_OUT   =  $(C21_OUT)/Sistemas\ operativos
SPSI_OUT =  $(TI41_OUT)/Seguridad\ y\ protección\ de\ sistemas\ informáticos
SS_OUT   =  $(CSI41_OUT)/Simulación\ de\ sistemas
SSO_OUT  =  $(IS41_OUT)/Seguridad\ en\ sistemas\ operativos
SWAP_OUT =  $(TI32_OUT)/Servidores\ web\ de\ altas\ prestaciones
TDRC_OUT =  $(TI32_OUT)/Transmisión\ de\ datos\ y\ redes\ de\ computadores
TE_OUT   =  $(IC41_OUT)/Tecnologías\ emergentes
TIC_OUT  =  $(CSI41_OUT)/Teoría\ de\ la\ información\ y\ la\ codificación
TID_OUT  =  $(TI41_OUT)/Tratamiento\ de\ imágenes\ digitales
TOC_OUT  =  $(C12_OUT)/Tecnología\ y\ organización\ de\ los\ computadores
TSI_OUT  =  $(CSI32_OUT)/Técnicas\ de\ los\ sistemas\ inteligentes
TR_OUT   =  $(IC41_OUT)/Tecnologías\ de\ red
TW_OUT   =  $(TI32_OUT)/Tecnologías\ web
VC_OUT   =  $(CSI41_OUT)/Visión\ por\ computador

 #
  # Otros directorios
 #

# Directorios de recursos para make
MAKEDIR = $(HOME)/.make
EISVOGEL = $(MAKEDIR)/eisvogel

  # FUNCIONES SOBRE INSTRUCCIONES MAKE
  #
  #    Para simplificar el makefile, las instrucciones largas y repetidas
  #    quedan recogidas como macros, de forma que se puedan leer más fácilmente
  #    y se les puedan pasar argumentos más fácilmente.

# Creación de directorios
#  $(1) -> Nombre del directorio, se imprime en pantalla
#  $(2) -> Ruta del directorio a crear (con macros)
define creadir
	@printf "\033[1;32mCreando directorio\033[0m %s\n" $(1)
	@mkdir -p $(2)
endef

# Creación de directorios que no contienen órdenes make
#  $(1) -> Nombre del directorio, se imprime en pantalla
#  $(2) -> Ruta del directorio a crear (con macros)
define creadirv
	@awk 'BEGIN{printf "\033[1;32mCreando directorio\033[0m %-53s \033[1;31m¡VACÍO!\033[0m\n", $(1)}'
	@mkdir -p $(2)
endef

# Compilación de ficheros Markdown a pdf mediante pandoc
#  $(1) -> Nombre del fichero de salida (entrecomillado)
#  $(2) -> Ruta del directorio en el que se encuentran los ficheros de origen
#          (con macros)
#  $(3) -> Ruta del fichero de salida (con macros)
define md-pdf
	@printf " \033[1;33m- \033[35mCreando\033[0m    %s.md...\n" $(1)
	@cp $(2)/.yaml $(3)/$(strip $(1))
	@printf "\n\n" >> $(3)/$(strip $(1))
	@for file in $(2)/*.md;\
	 do\
	 cat "$$file";\
	 printf "\n\n\\pagebreak\n\n";\
	 done >> $(3)/$(strip $(1))
	@mv $(3)/$(strip $(1)) $(3)/$(strip $(1)).md
	@printf " \033[1;33m- \033[34mCompilando\033[0m %s.pdf..." $(1)
	@pandoc --standalone\
	        --template=$(EISVOGEL)/eisvogel.tex\
	        --resource-path=$(strip $(2))\
	        --from markdown+implicit_figures\
	        --pdf-engine=xelatex\
	        --listings\
	        --table-of-contents\
	        $(3)/$(strip $(1)).md -o $(3)/$(strip $(1)).pdf
	@printf "\n \033[1;33m- Eliminando\033[0m %s.md...\n" $(strip $(1))
	@rm $(3)/$(strip $(1)).md
endef


  # INSTRUCCIONES MAKE
  #
  #    Instrucciones de compilación del repositorio. Estructura:
  #     - ALL -> Rama principal. De ella parten todos los cuatrimestres.
  #     - CUATRIMESTRES -> Contienen las asignaturas de cada uno de ellos.
  #     - ASIGNATURAS -> Contienen las instrucciones de compilación.
  #     - MAIN -> Inicialización de cada sección.
  #
  #    Los ficheros de texto deben compilarse siempre y cuando no sean los
  #    README de cada una de las ramas. Estos están diseñados para verse
  #    en GitHub, no para ser compilados en Pandoc.

ALL: INIT_ALL C11 C12 C21 C22 C31 C32 C41 C42 FCI PE TFG FIN

 #
  # Mensaje y preparaciones iniciales de compilación
 #

INIT_ALL:
	@printf    "\n   \033[1;34m=================================================\n"
	@printf      "   #                                               #\n"
	@printf      "   #  \033[1;33mC O M E N Z A N D O   C O M P I L A C I Ó N  \033[1;34m#\n"
	@printf      "   #                                               #\n"
	@printf      "   =================================================\033[0m\n"
	@printf    "\nEliminando compilación anterior\n"
	@rm -rf  $(OUT)
	@printf    "Creando raíz de archivos compilados\n\n"
	@mkdir   $(OUT)

 #
  # 1º 1er cuatrimestre
 #

C11: MAIN_C11 ALEM CA FFT FP FS
MAIN_C11:
	$(call creadir, "1º 1er cuatrimestre", $(C11_OUT))


ALEM: MAIN_ALEM
MAIN_ALEM:
	$(call creadirv, "Álgebra lineal y estructuras matemáticas", $(ALEM_OUT))

CA: MAIN_CA
MAIN_CA:
	$(call creadirv, "Cálculo", $(CA_OUT))


FFT: MAIN_FFT
MAIN_FFT:
	$(call creadirv, "Fundamentos físicos y tecnológicos", $(FFT_OUT))


FP: MAIN_FP
MAIN_FP:
	$(call creadirv, "Fundamentos de programación", $(FP_OUT))


FS: MAIN_FS
MAIN_FS:
	$(call creadirv, "Fundamentos del software", $(FS_OUT))

 #
  # 1º 2º cuatrimestre
 #

C12: MAIN_C12 ES IES LMD MP TOC
MAIN_C12:
	$(call creadir, "1º 2º cuatrimestre", $(C12_OUT))


ES: MAIN_ES
MAIN_ES:
	$(call creadirv, "Estadística", $(ES_OUT))


IES: MAIN_IES
MAIN_IES:
	$(call creadirv, ("Ingeniería, empresa y sociedad"), $(IES_OUT))


LMD: MAIN_LMD
MAIN_LMD:
	$(call creadirv, "Lógica y métodos discretos", $(LMD_OUT))


MP: MAIN_MP
MAIN_MP:
	$(call creadirv, "Metodología de la programación", $(MP_OUT))


TOC: MAIN_TOC
MAIN_TOC:
	$(call creadirv, "Tecnología y organización de los computadores", $(TOC_OUT))

 #
  # 2º 1er cuatrimestre
 #

C21: MAIN_C21 EC ED PDOO SCD SO
MAIN_C21:
	$(call creadir, "2º 1er cuatrimestre", $(C21_OUT))


EC: MAIN_EC
MAIN_EC:
	$(call creadirv, "Estructura de computadores", $(EC_OUT))


ED: MAIN_ED
MAIN_ED:
	$(call creadirv, "Estructura de datos", $(ED_OUT))


PDOO: MAIN_PDOO
MAIN_PDOO:
	$(call creadirv, "Programación y diseño orientado a objetos", $(PDOO_OUT))


SCD: MAIN_SCD
MAIN_SCD:
	$(call creadirv, "Sistemas concurrentes y distribuidos", $(SCD_OUT))


SO: MAIN_SO
MAIN_SO:
	$(call creadirv, "Sistemas operativos", $(SO_OUT))

 #
  # 2º 2º cuatrimestre
 #

C22: MAIN_C22 AC ALG FBD FIS IA
MAIN_C22:
	$(call creadir, "2º 2º cuatrimestre", $(C22_OUT))


AC: MAIN_AC
MAIN_AC:
	$(call creadirv, "Arquitectura de computadores", $(AC_OUT))


ALG: MAIN_ALG
MAIN_ALG:
	$(call creadirv, "Algorítmica", $(ALG_OUT))


FBD: MAIN_FBD
MAIN_FBD:
	$(call creadirv, "Fundamentos de bases de datos", $(FBD_OUT))


FIS: MAIN_FIS
MAIN_FIS:
	$(call creadirv, "Fundamentos de ingeniería del software", $(FIS_OUT))


IA: MAIN_IA
MAIN_IA:
	$(call creadirv, "Inteligencia artificial", $(IA_OUT))

 #
  # 3º 1er cuatrimestre
 #

C31: MAIN_C31 DDSI FR IG ISE MC
MAIN_C31:
	$(call creadir, "3º 1er cuatrimestre", $(C31_OUT))


DDSI: MAIN_DDSI
MAIN_DDSI:
	$(call creadirv, "Diseño y desarrollo de sistemas de información", $(DDSI_OUT))


FR: MAIN_FR
MAIN_FR:
	$(call creadirv, "Fundamentos de redes", $(FR_OUT))


IG: MAIN_IG
MAIN_IG:
	$(call creadirv, "Informática gráfica", $(IG_OUT))


ISE: MAIN_ISE
MAIN_ISE:
	$(call creadirv, "Ingeniería de servidores", $(ISE_OUT))


MC: MAIN_MC
MAIN_MC:
	$(call creadirv, "Modelos de computación", $(MC_OUT))

 #
  # 3º 2º cuatrimestre
 #

C32: MAIN_C32 CSI32 IC32 IS32 SI32 TI32
MAIN_C32:
	$(call creadir, "3º 2º cuatrimestre", $(C32_OUT))

 #
  # Computación y sistemas inteligentes - 3º 2º cuatrimestre
 #

CSI32: MAIN_CSI32 AA IC MCA MH TSI
MAIN_CSI32:
	$(call creadir, "3º 2º - Computación y sistemas inteligentes", $(CSI32_OUT))


AA: MAIN_AA
MAIN_AA:
	$(call creadirv, "Aprendizaje automático", $(AA_OUT))


IC: MAIN_IC
MAIN_IC:
	$(call creadirv, "Ingeniería del conocimiento", $(IC_OUT))


MCA: MAIN_MCA
MAIN_MCA:
	$(call creadirv, "Modelos de computación avanzada", $(MCA_OUT))


MH: MAIN_MH
MAIN_MH:
	$(call creadirv, "Metaheurísticas", $(MH_OUT))


TSI: MAIN_TSI
MAIN_TSI:
	$(call creadirv, "Técnicas de los sistemas inteligentes", $(TSI_OUT))

 #
  # Ingeniería de computadores - 3º 2º cuatrimestre
 #

IC32: MAIN_IC32 ACAP AS DHD DSE SMP
MAIN_IC32:
	$(call creadir, "3º 2º - Ingeniería de computadores", $(IC32_OUT))


ACAP: MAIN_ACAP
MAIN_ACAP:
	$(call creadirv, "Arquitectura y computación de altas prestaciones", $(ACAP_OUT))


AS: MAIN_AS
MAIN_AS:
	$(call creadirv, "Arquitectura de sistemas", $(AS_OUT))


DHD: MAIN_DHD
MAIN_DHD:
	$(call creadirv, "Desarrollo de hardware digital", $(DHD_OUT))


DSE: MAIN_DSE
MAIN_DSE:
	$(call creadirv, "Diseño de sistemas electrónicos", $(DSE_OUT))


SMP: MAIN_SMP
MAIN_SMP:
	$(call creadirv, "Sistemas con microprocesadores", $(SMP_OUT))

 #
  # Ingeniería del software - 3º 2º cuatrimestre
 #

IS32: MAIN_IS32 DIU DS DSD SG SIBW
MAIN_IS32:
	$(call creadir, "3º 2º - Ingeniería del software", $(IS32_OUT))


DIU: MAIN_DIU
MAIN_DIU:
	$(call creadirv, "Diseño de interfaces de usuario", $(DIU_OUT))


DS: MAIN_DS
MAIN_DS:
	$(call creadirv, "Desarrollo de software", $(DS_OUT))


DSD: MAIN_DSD
MAIN_DSD:
	$(call creadirv, "Desarrollo de sistemas distribuidos", $(DSD_OUT))


SG: MAIN_SG
MAIN_SG:
	$(call creadirv, "Sistemas gráficos", $(SG_OUT))


SIBW: MAIN_SIBW
MAIN_SIBW:
	$(call creadirv, "Sistemas de información basados en web", $(SIBW_OUT))

 #
  # Sistemas de información - 3º 2º cuatrimestre
 #

SI32: MAIN_SI32 ABD ISI PW SIE SMD
MAIN_SI32:
	$(call creadir, "3º 2º - Sistemas de información", $(SI32_OUT))


ABD: MAIN_ADB
MAIN_ADB:
	$(call creadirv, "Administración de bases de datos", $(ADB_OUT))


ISI: MAIN_ISI
MAIN_ISI:
	$(call creadirv, "Ingeniería de sistemas de información", $(ISI_OUT))


PW: MAIN_PW
MAIN_PW:
	$(call creadirv, "Programación web", $(PW_OUT))


SIE: MAIN_SIE
MAIN_SIE:
	$(call creadirv, "Sistemas de información para empresas", $(SIE_OUT))


SMD: MAIN_SMD
MAIN_SMD:
	$(call creadirv, "Sistemas multidimensionales", $(SMD_OUT))

 #
  # Tecnologías de la información - 3º 2º cuatrimestre
 #

TI32: MAIN_TI32 CUIA SMM SWAP TDRC TW
MAIN_TI32:
	$(call creadir, "3º 2º - Tecnologías de la información", $(TI32_OUT))


CUIA: MAIN_CUIA
MAIN_CUIA:
	$(call creadirv, "Computación ubicua e inteligencia artificial", $(CUIA_OUT))


SMM: MAIN_SMM
MAIN_SMM:
	$(call creadirv, "Sistemas multimedia", $(SMM_OUT))


SWAP: MAIN_SWAP
MAIN_SWAP:
	$(call creadirv, "Servidores web de altas prestaciones", $(SWAP_OUT))


TDRC: MAIN_TDRC
MAIN_TDRC:
	$(call creadirv, "Transmisión de datos y redes de computadores", $(TDRC_OUT))


TW: MAIN_TW
MAIN_TW:
	$(call creadirv, "Tecnologías web", $(TW_OUT))

 #
  # 4º 1er cuatrimestre
 #

C41: MAIN_C41 CSI41 IC41 IS41 SI41 TI41
MAIN_C41:
	$(call creadir, "4º 1er cuatrimestre", $(C41_OUT))

 #
  # Computación y sistemas inteligentes - 4º 1er cuatrimestre
 #

CSI41: MAIN_CSI41 NPI PL PTC SS TIC VC
MAIN_CSI41:
	$(call creadir, "4º 1er - Computación y sistemas inteligentes", $(CSI41_OUT))


NPI: MAIN_NPI
MAIN_NPI:
	$(call creadirv, "Nuevos paradigmas de interacción", $(NPI_OUT))


PL: MAIN_PL
MAIN_PL:
	$(call creadirv, "Procesadores de lenguajes", $(PL_OUT))


PTC: MAIN_PTC
MAIN_PTC:
	$(call creadirv, "Programación técnica y científica", $(PTC_OUT))


SS: MAIN_SS
MAIN_SS:
	$(call creadirv, "Simulación de sistemas", $(SS_OUT))


TIC: MAIN_TIC
MAIN_TIC:
	$(call creadirv, "Teoría de la información y la codificación", $(TIC_OUT))


VC: MAIN_VC
MAIN_VC:
	$(call creadirv, "Visión por computador", $(VC_OUT))

 #
  # Ingeniería de computadores - 4º 1er cuatrimestre
 #

IC41: MAIN_IC41 CPD II SE TE TR
MAIN_IC41:
	$(call creadir, "4º 1er - Ingeniería de computadores", $(IC41_OUT))


CPD: MAIN_CPD
MAIN_CPD:
	$(call creadirv, "Centros de procesamiento de datos", $(CPD_OUT))


II: MAIN_II
MAIN_II:
	$(call creadirv, "Informática industrial", $(II_OUT))


SE: MAIN_SE
MAIN_SE:
	$(call creadirv, "Sistemas empotrados", $(SE_OUT))


TE: MAIN_TE
MAIN_TE:
	$(call creadirv, "Tecnologías emergentes", $(TE_OUT))


TR: MAIN_TR
MAIN_TR:
	$(call creadirv, "Tecnologías de red", $(TR_OUT))

 #
  # Ingeniería del software - 4º 1er cuatrimestre
 #

IS41: MAIN_IS41 DBA DGP LP MDA PGV
MAIN_IS41:
	$(call creadir, "4º 1er - Ingeniería del software", $(IS41_OUT))


DBA: MAIN_DBA
MAIN_DBA:
	$(call creadirv, "Desarrollo basado en agentes", $(DBA_OUT))


DGP: MAIN_DGP
MAIN_DGP:
	$(call creadirv, "Dirección y gestión de proyectos", $(DGP_OUT))


LP: MAIN_LP
MAIN_LP:
	$(call creadirv, "Lógica y programación", $(LP_OUT))


MDA: MAIN_MDA
MAIN_MDA:
	$(call creadirv, "Metodologías de desarrollo ágil", $(MDA_OUT))


PGV: MAIN_PGV
MAIN_PGV:
	$(call creadirv, "Programación gráfica de videojuegos", $(PGV_OUT))

 #
  # Sistemas de información - 4º 1er cuatrimestre
 #

SI41: MAIN_SI41 BDD GRD IN RINF RSC SIG
MAIN_SI41:
	$(call creadir, "4º 1er - Sistemas de información", $(SI41_OUT))


BDD: MAIN_BDD
MAIN_BDD:
	$(call creadirv, "Bases de datos distribuidas", $(BDD_OUT))


GRD: MAIN_GRD
MAIN_GRD:
	$(call creadirv, "Gestión de recursos digitales", $(GRD_OUT))


IN: MAIN_IN
MAIN_IN:
	$(call creadirv, "Inteligencia de negocio", $(IN_OUT))


RINF: MAIN_RINF
MAIN_RINF:
	$(call creadirv, "Recuperación de información", $(RINF_OUT))


RSC: MAIN_RSC
MAIN_RSC:
	$(call creadirv, "Redes y sistemas complejos", $(RSC_OUT))


SIG: MAIN_SIG
MAIN_SIG:
	$(call creadirv, "Sistemas de información geográficos", $(SIG_OUT))

 #
  # Tecnologías de la información - 4º 1er cuatrimestre
 #

TI41: MAIN_TI41 CRIM DAI IV SPSI TID
MAIN_TI41:
	$(call creadir, "4º 1er - Tecnologías de la información", $(TI41_OUT))


CRIM: MAIN_CRIM
MAIN_CRIM:
	$(call creadirv, "Comprensión y recuperación de información multimedia", $(CRIM_OUT))


DAI: MAIN_DAI
MAIN_DAI:
	$(call creadirv, "Desarrollo de aplicaciones para internet", $(DAI_OUT))


IV: MAIN_IV
MAIN_IV:
	$(call creadirv, "Infraestructura virtual", $(IV_OUT))


SPSI: MAIN_SPSI
MAIN_SPSI:
	$(call creadirv, "Seguridad y protección de sistemas informáticos", $(SPSI_OUT))


TID: MAIN_TID
MAIN_TID:
	$(call creadirv, "Tratamiento de imágenes digitales", $(TID_OUT))

 #
  # 4º 2º cuatrimestre
 #

C42: MAIN_C42 CSI42 IC42 IS42 SI42 TI42
MAIN_C42:
	$(call creadir, "4º 2º cuatrimestre", $(C42_OUT))

 #
  # Computación y sistemas inteligentes - 4º 2º cuatrimestre
 #

CSI42: MAIN_CSI42 CRIP PLD RI
MAIN_CSI42:
	$(call creadir, "4º 2º - Computación y sistemas inteligentes", $(CSI42_OUT))


CRIP: MAIN_CRIP
MAIN_CRIP:
	$(call creadirv, "Criptografía y computación", $(CRIP_OUT))


PLD: MAIN_PLD
MAIN_PLD:
	$(call creadirv, "Programación lúdica", $(PLD_OUT))


RI: MAIN_RI
MAIN_RI:
	$(call creadirv, "Robótica industrial", $(RI_OUT))

 #
  # Ingeniería de computadores - 4º 2º cuatrimestre
 #

IC42: MAIN_IC42 CII MEI
MAIN_IC42:
	$(call creadir, "4º 2º - Ingeniería de computadores", $(IC42_OUT))


CII: MAIN_CII
MAIN_CII:
	$(call creadirv, "Circuitos integrados e impresos", $(CII_OUT))


MEI: MAIN_MEI
MAIN_MEI:
	$(call creadirv, "Mantenimiento de equipos informáticos", $(MEI_OUT))

 #
  # Ingeniería del software - 4º 2º cuatrimestre
 #

IS42: MAIN_IS42 AO NTP PPR
MAIN_IS42:
	$(call creadir, "4º 2º - Ingeniería del software", $(IS42_OUT))


AO: MAIN_AO
MAIN_AO:
	$(call creadirv, "Animación por ordenador", $(AO_OUT))


NTP: MAIN_NTP
MAIN_NTP:
	$(call creadirv, "Nuevas tecnologías de la programación", $(NTP_OUT))


PPR: MAIN_PPR
MAIN_PPR:
	$(call creadirv, "Programaciones paralelas", $(PPR_OUT))

 #
  # Sistemas de información - 4º 2º cuatrimestre
 #

SI42: MAIN_SI42 PDIH SCGC
MAIN_SI42:
	$(call creadir, "4º 2º - Sistemas de información", $(SI42_OUT))


PDIH: MAIN_PDIH
MAIN_PDIH:
	$(call creadirv, "Periféricos y dispositivos de interfaz humana", $(PDIH_OUT))


SCGC: MAIN_SCGC
MAIN_SCGC:
	$(call creadirv, "Sistemas cooperativos y gestión de contenidos", $(SCGC_OUT))

 #
  # Tecnologías de la información - 4º 2º cuatrimestre
 #

TI42: MAIN_TI42 PDM PDS RMS
MAIN_TI42:
	$(call creadir, "4º 2º - Tecnologías de la información", $(TI42_OUT))


PDM: MAIN_PDM
MAIN_PDM:
	$(call creadirv, "Programación de dispositivos móviles", $(PDM_OUT))


PDS: MAIN_PDS
MAIN_PDS:
	$(call creadirv, "Procesamiento digital de señales", $(PDS_OUT))


RMS: MAIN_RMS
MAIN_RMS:
	$(call creadirv, "Redes multiservicio", $(RMS_OUT))

 #
  # Formación complementaria interdisciplinar
 #

FCI: MAIN_FCI CEGE DI EISI
MAIN_FCI:
	$(call creadir, "Formación complementaria interdisciplianr", $(FCI_OUT))


CEGE: MAIN_CEGE
MAIN_CEGE:
	$(call creadirv, "Creación de empresas y gestión emprendedora", $(CEGE_OUT))


DI: MAIN_DI
MAIN_DI:
	$(call creadirv, "Derecho informático", $(DI_OUT))


EISI: MAIN_EISI
MAIN_EISI:
	$(call creadirv, ("Ética, informática y sociedad de la información"), $(EISI_OUT))

 #
  # Prácticas de empresa
 #

PE: MAIN_PE
MAIN_PE:
	$(call creadirv, "Prácticas de empresa", $(PE_OUT))

 #
  # Trabajos de fin de grado
 #

TFG: MAIN_TFG
MAIN_TFG:
	$(call creadirv, "Trabajo de fin de grado", $(TFG_OUT))

 #
  # Mensaje de despedida
 #

FIN:
	@rm -rf $(HOME)/.cache
	@printf "\n   \033[1;34m================================================================\n"
	@printf "   #                                                              #\n"
	@printf "   #               \033[1;32mCOMPILACIÓN COMPLETADA CON ÉXITO               \033[1;34m#\n"
	@printf "   #                                                              #\n"
	@printf "   # \033[1;33mEste repositorio es fruto del esfuerzo de los estudiantes de \033[1;34m#\n"
	@printf "   # \033[1;33mla Universidad de Granada     - MÁS INFO: \033[1;32mdeiit.ugr.es \033[1;33m-     \033[1;34m#\n"
	@printf "   \033[1;34m#                                                              #\n"
	@printf "   \033[1;34m================================================================\n"
	@printf "               \033[1;36m_____     ______     __     __     ______           \n"
	@printf "              /\  __-.  /\  ___\   /\ \   /\ \   /\__  _\          \n"
	@printf "              \ \ \/\ \ \ \  __\   \ \ \  \ \ \  \/_/\ \/          \n"
	@printf "               \ \____-  \ \_____\  \ \_\  \ \_\    \ \_\          \n"
	@printf "                \/____/   \/_____/   \/_/   \/_/     \/_/          \n"
