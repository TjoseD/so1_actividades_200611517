>> #### Actividad 4 so1
# Chat basdo en named pipe y bash

> #### Preambulo
#### Breve historia de pipe

Los ___Pipes___ fueron inventados por ___Douglas Mcilroy___ y fueron incorporados dentro de sistemas UNIX en 1973. Son _archivos especiales_ o ___buffer___ que se pueden visualizar como tubos fisicos que conectan la salidas del predecesor con la entrada del sucesor.
 

### ¿Que es un named pipe?

En sistemas operativos basados en UNIX como lo es ___LINUX___  un ___named pipe___, o __FIFO__, es un tipo de archivo especial usado para establecer una _comunicación entre procesos_ **IPC**(___Inter ¨Process Comunication___).  
A diferencia de un _pipe estandard_ un __named  pipe__ es accesado como parte del _sistema de archivos_ como cualquier otro tipo de archivo.
Al crear un archivo __FIFO__ (___named pipe___), este aparecerá en el directorio como _un archivo  estandard_ pero vacio. 
La diferencia entre un archivo normal y un ___pipe nombrado___ es que este ultimo ___no es para almacenar información___. La ___data___ que es pasado a un __named pipe__  sera _directamente gestionado_ por el __kernel__.  El archivo __FIFO__ sera usado solo como referencia.
    


### ¿Como crear  un named pipe?
Para crear un named pipe, en un sistema operativo Linux, se hace con el comando __mkfifo__. Este comando no necesita permisos de super usuario para ser utilizado. 
Al comando  __mkfifo__ solo hay que pasarle el ___nombre___  que queremos para nuestro archivo __FIFO__. 
Si ademas del nombre queremos _especificarle_ los ___permisos___ para el archivo, debemos usar la opcion __-m__  (abreviación de __--mode__) del comando __mkfifo__. Esta opción acepta bits que definen el ___permiso___.  
 Por ejemplo: crearemos un _named pipe_ llamado ___mipipe1___ y le especificamos el permiso __644__ en la siguiente linea de comando.  
#### :~$ `mkfifo -m 644 mipipe1`  
  
Se suele utilizar letras _mayusculas_ para los nombres de _pipe nombrados_, esto es porque es mas fácil la visualización de los directorios y reconocér que un archivo es un __named pipe__.
 
### ¿Como reconocer un named pipe?
Al verificar un directorio donde se encuentran ___archivos FIFO___ , estos se reconocen al ver que la primera letra que se encuentran justo antes de los permisos es una letra __p__. 
Esta letra indica que es un __named pipe__. 

### ¿Como trabaja un named pipe?
Como lo hace un ___pipe estandard___ que toma la ___salida___ estandard del proceso a su izquierda y lo comvierte como ___entrada___ estandard del proceso a su derecha. De forma similar lo hace un __named pipe__.  
Lo primero que hay que hacer es enviarle esa salida al named pipe, despues otro proceso puede leer la información que estara _resguardada temporalmente_ en el __named pipe__. Lo digo ___temporal___ porque solo se puede leer una vez ese contenido, si se intenta leer de nuevo, ya no mostrara ese contenido. 
Para que una ___dato___ sea pasado a traves de un __named pipe__, el archivo __FIFO__ debe estar ___abierto en ambos lados___, Tanto para el proceso que ___escribe___ en él como tambien para el proceso que ___lee___ de él.  
Si no hay nadie que esta leyendo  del __named pipe__ y consuma su contenido, el pipe es ___bloqueado___, Hasta que sea leido.  
Para enviarle un dato al named pipe solo hay que enviarselo.  

Ejemplo: mandaremos un mensaje con el comando __echo__ pero en lugar a que ese mensaje vaya a la salida estándard  lo reenviaremos  hacia el __named pipe__ con el simbolo de redireccionamiento __>__. Otro proceso podra leer el contenido de ese named pipe, posteriormente.
#### :~$ `echo "Hola Guatemala " > mipipe1`  
Para leer el contenido lo hacemos con el comando __cat__ seguido del ___nombre___ del _named pipe_  
#### :~$ `cat mipipe1`  
>Hola Guatemala 
 
### ¿Como borrar un named pipe?
Para borrar un archivo __FIFO__  lo hacemos con el comando __rm__ seguido por el _nombre del archivo_.  
#### :~$ `rm mipipe1` 
 
 ____
 
# Crear un chat utilizando named pipe y bash

## Preparacion del escenario.
Abrimos dos terminales para ver la comunicacién por el chat a traves del archivo __FIFO__, __named pipe__
[![Screenshot-from-2024-03-03-17-14-20.png](https://i.postimg.cc/ZRVg9NhN/Screenshot-from-2024-03-03-17-14-20.png)](https://postimg.cc/vgxXkcT8)  


## Crear un named pipe 
Creamos un ___named pipe___  con el comando __mkfifo__ y lo llamaremos ___MICHATFIFO___.   
Por convensión se escribe con letras mayusculas los nombres de los ___named pipe___ para que sea mas facil de visualizarlos en el directorio de archivos.
[![Screenshot-from-2024-03-03-17-30-13.png](https://i.postimg.cc/gcMFjCY7/Screenshot-from-2024-03-03-17-30-13.png)](https://postimg.cc/DmbYYY4Q)  

### Ver el archivo FIFO recien creado
Para ver el directorio donde se creó el archivo FIFO  utilizamos el comando __ls__ con el parametro __-l__ 
[![Screenshot-from-2024-03-03-17-30-41.png](https://i.postimg.cc/J0Bn7Zyr/Screenshot-from-2024-03-03-17-30-41.png)](https://postimg.cc/H8dHBJ4R)
 


##### Caracteristicas del __named pipe__  
Como se podrá notar en la siguiente imagen, el archivo FIFO iniciara con una letra __p__ para indicarnos que es un ___named pipe___ esta letra está justo antes de los ___bits de permiso___ del archivo.  

[![Screenshot-from-2024-03-03-17-31-20.png](https://i.postimg.cc/fWvX9vFp/Screenshot-from-2024-03-03-17-31-20.png)](https://postimg.cc/xqccrL93)  

### Enviar un mensaje
Enviamos un mensaje a traves del chat, con el comando __echo__ y redirigimos el mensaje con el símbolo de redireccionamiento __>__ hacia ___MICHATPIPE___.   

[![Screenshot-from-2024-03-03-17-32-20.png](https://i.postimg.cc/rmNd58hx/Screenshot-from-2024-03-03-17-32-20.png)](https://postimg.cc/62T5XNxp)  
Importante destacar que el proceso queda _a la espera_ en el terminal donde se envio el mensaje hasta que el mensaje sea leido por el cliente, o el otro terminal. 


#### Manejo del kernel del contenido de un named pipe 
Como se dijo antes un __archivo FIFO__ _no es para almacenar_ o _guardar_ información sino que el contenido es ___administrado directamente___ por el __kernel__,  por tal razón, se da una espera desde el terminal donde se envió el mensaje hasta que en el otro terminal sea leido el mensaje.  

[![Screenshot-from-2024-03-03-17-41-03.png](https://i.postimg.cc/PNsqCJZm/Screenshot-from-2024-03-03-17-41-03.png)](https://postimg.cc/JHx8g1pn)  


### Lectura del mensaje  
Para leer el contenido del __named pipe__ ___MICHATPIPE___ el cual es el mensaje enviado anteriormente, utilizamos el comando __cat__  

[![Screenshot-from-2024-03-03-17-41-19.png](https://i.postimg.cc/L8gnNkCH/Screenshot-from-2024-03-03-17-41-19.png)](https://postimg.cc/5X14tzWG)  
Al ser leido el mensaje, automaticamente en el otro terminal se libera y se queda en la espera de la siguiente instrucción. 
___

# Chat en acción
Se muestra en la siguiente imagen con los _menajes_ compartidos entre los dos usuarios. 
[![Screenshot-from-2024-03-03-17-45-39.png](https://i.postimg.cc/FRzzq2NJ/Screenshot-from-2024-03-03-17-45-39.png)](https://postimg.cc/jwVRn3Ws)

Video  
En sl siguiente video se puede ver como se va dando esa comunicación e intercambio de mensajes.  

[![VER EL VIDEO de  la HOJA DE TRABAJO 1](https://i.postimg.cc/gcMFjCY7/Screenshot-from-2024-03-03-17-30-13.png)](https://www.loom.com/share/2b50d9a8dacb45d184ecaebbd84c7df7?sid=5aa2ebc3-6ae2-49c3-8b57-73246abc9460)  





____
____  
Conceptos:  
pipe, named pipe, FIFO, IPC, redireccionamiento , kernel, proceso, comunicación. 


Comandos:  

    mkfifo -m ,  ls -l, cat, echo   


Archivos:  MICHATFIFO

___  

>> ##### _SO1 ECYS FIUSAC 2024_  
