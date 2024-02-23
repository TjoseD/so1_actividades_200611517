 #### Actividad 3 so1
# Creación de un Systemd Unit

>> #### Preview de la secuencia de comandos para crear el demonio en ubuntu 22.04
> ![System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png " Proceso de creación de un Systemd Unit desde consola.")

====
## Proceso de creación, inicializacion y habilitación del Demonio.
====
### Proceso de creacion del Servicio o Demonio *fsecys.service*
crear el programa
    El primer paso es crear un archivo que tendra el programa que se ejecutara, esta debe de tener extension **.sh** porque sera ejecutable y debe estar en la sigiuente ruta */usr/local/bin/*, esta ubicación es un estandard que hace accesible a los usuarios del sistema sin la necesidad que indiquen la ruta especifica. Nuestro archivo se llamara *HolaMundo_fecys.sh*. 
    Abrimos un editor de texto para crear el archivo, en nuestro caso usamos *nano* y lo hacemos  ejecutando la siguiente linea de comando.  
:~$ `sudo nano /usr/local/bin/HolaMundo_fecys.sh` 
y nos abre el editor donde escribimos el siguiente bloque de codigo.
> ![System Unit](https://i.postimg.cc/0jtPGDxZ/Screenshot-105.png "Programa que muestra un mensaje y la fecha en consola.")
 recuerdo que para guardar y salir del editor de texto se usan: para grabar  **Ctrl+O** y para salir **Ctrl+X**

 > Una vez creado el archivo del programa, debemos asignarles permiso de ejecutable con *chmod + x*, lo hacemos ejecuando la siguiente linea de comando.  
#### :~$ `sudo chmod +x /usr/local/bin/HolaMundo_fsecys.sh` 
  
 Bien estamos listos para crear el servicio o demonio y para ello debemos de crear un nuevo archivo y guardarlo en el siguiente path */etc/systemd/system/*, este ruta debe ser exacta, es una ruta estandard 
:~$ **`sudo nano /etc/systemd/system/fsecys.service`** 

### :~$  `systemd-analyze verify /etc/systemd/system/fsecys.service` 

-----
### Proceso de inicializacion y habilitacion del demonio

#### :~$  `sudo systemctl daemon-reload`

### :~$  `systemctl start fsecysmundo` 

:~$ *`systemctl enable fsecysmundo`*
----
### Chequeo del estado del servicio y de su logo.

====
acion de un servicio o demonio en Linux y chequeo de su log de funcionamiento






--
Secuencia de comandos e instrucciones:

:~$ sudo nano /usr/local/bin/HolaMundo_fhwecys.sh 
 
# :~$ sudo chmod +x /usr/local/bin/Hola_fsecysmundo.sh 
  
## :~$ sudo nano /etc/systemd/system/fsecysmundo.service 

### :~$  systemd-analyze verify /etc/systemd/system/fsecysmundo.service 

#### :~$  sudo systemctl daemon-reload

##### :~$  systemctl start fsecysmundo 

###### :~$ systemctl enable fsecysmundo
====
- :~$ systemctl status fsecysmundo

:~$ *journalctl -u* fsecysmundo.service 

*:~$  journalctl -u  fsecysmundo.service*

> :~$ systemctl status fsecysmundo

:~$ ***journalctl -u*** fsecysmundo.service 


:~$ `systemctl status fsecysmundo`

### :~$ `systemctl status fsecysmundo`
#### :~$ `systemctl status fsecysmundo`

":~$ `systemctl status` fsecysmundo"

![System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png " Proceso de creación de un Systemd Unit desde consola.")

Referencia: [Step by Step create a System Unit on Linux](https://www.fosslinux.com/111815/a-guide-to-creating-linux-services-with-systemd.htm "Una de mies fuentes de consulta").

[![](https://markdown-videos-api.jorgenkh.no/youtube/qHGTs1NSB1s)](https://youtu.be/qHGTs1NSB1s "Porque Linus Torvals no usaba Distribuciónes Debian.")

