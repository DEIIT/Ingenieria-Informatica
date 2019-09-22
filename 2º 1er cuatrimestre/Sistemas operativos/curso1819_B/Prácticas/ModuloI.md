## Obtener root (UML)

```
cp /fenix/depar/lsi/UML/*.gz /tmp
gunzip /tmp/*.gz

./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=1024m
```


## Crear archivo /dev

```
mknod /dev/loop0 b 7 0
mknod /dev/loop1 b 7 1
```

## Crear archivos de cierto tamaño

```
dd if=/dev/zero of=/root/archivo bs=2k count=10000
```
## Asociar archivo loop a archivo creado

```
losetup /dev/loop0 /root/archivo_SA20
```

## Desasociar archivo loop
```
losetup -d /dev/loop0
```

## Mostrar información de una partición
```
fdisk -l /dev/loop0
```

## Crear particiones con etiqueta
```
	mke2fs -L LABEL_ext? -t ext? <dispositivo>
```

## Mostrar información con tune2fs
```
tune2fs -l <dispositivo>
```

## Cambiar maximo de montajes sin realizar comprobación
```
tune2fs -c max-mount-counts <dispositivo>
```

## Cambiar etiqueta a un SA
```
tune2fs -L label <dispositivo>
```

## Montar particiones
```
mkdir <sitio_montaje>

#montar sistema de archivos con etiqueta <label> en modo solo lectura
#-o ro quiere decir: usar opciones(-o), y entre las opciones solo lectura (ro)
mount -L <label> -o ro <sitio_montaje>

#montar sistema de archivos con etiqueta <label> y con E/S sincronizada
mount -L <label> -o sync <sitio_montaje>

```

## Montar automaticamente al arranque usando /etc/fstab

### Sintaxis del fichero /etc/fstab

```
<sistema_de_ficheros>   <punto_montaje>    <tipo_SA> <opciones>  <dump> <pass>

<sistema_de_ficheros> archive de bloques de /dev o LABEL=<label>

<punto_montaje> carpeta a montar

<tipo_SA> tipo, ext3, ext4, auto ,...

<opciones> ro , rw, async ... (mirar man mount)

<dump> si su valor es distinto de 0 indica la frecuencia con la que se realizará una copia de seguridad del SA.

<pass> , durante el arranque del sistema este campo especifica el orden en el que la orden fsck realizará las comprobaciones sobre los SAs.

#ejemplo:
	LABEL=LABEL_ext4          /mnt/SA_ext4    ext4    sync            0 0
```

## Montar dirección del sistema en el root
```
mount none <directorio_donde_montar> -t hostfs -o <directorio_externo_a_montar>
```

## Instalar paquetes en el root (Fedora 14)
```
rpm -i <paquetes>
```

## Eliminar paquetes (Fedora 14)
```
rpm -e <nombre-paquete>
```

## Orden ps, ver procesos en ejecución
```
ps -ef
```

## Orden uptime
```
# en orden: hora actual, tiempo que lleva encendido, num usuario, carga media (1,5 y 15 minutos)
uptime
```

## Orden w
```
# lo mismo solo que con los usuarios
w
```

## Medir tiempo de una orden
```
time <orden>
```

## Orden nice
```
#ejecutar un proceso con prioridad n, n esta entre [-20,19]
nice -n <programa>
```

## Orden renice
```
#cambiar prioridad de un programa en ejecucion a n

renice n <PID>
#mirar PID ejecutando con <programa> & o usando top
```

## Orden pstree
```
#orden ps en forma de arbol - pag 46 guia
pstree
```

## Orden top - pag 49
```
top
```

## Orden free - liberar memoria
```
free
```

## Orden du - numero de bloques de disco
```
du
```

## Crear enlaces - orden ln

```
#enlaces duros
ln <archivo1> <enlace>

#enlaces blandos
ln -s <archivo1> <enlace>
```


## Archivos crontab
```
	crontab <archivo_cron>
```

## Sintaxis archivo cron
```
minuto    hora     dia-del-mes    mes     dia-de-la-semana        orden

# * : cualquier valo posible
# n : numero entero
# n-n: dos enteros separados por - , indican rango de valores
# n,n,n,n : serie de enteros

#ver en pagina 71
```



[![Creative Commons License][image-1]][1]  
This work is licensed under a [Creative Commons Attribution 4.0 Unported License][1].

[1]:    http://creativecommons.org/licenses/by/4.0/deed.en_US

[image-1]:    http://i.creativecommons.org/l/by/4.0/80x15.png
