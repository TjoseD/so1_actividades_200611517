 #### Actividad 3 so1
# Creación de un Systemd Unit
=====
>> #### Preview de la secuencia de comandos para crear el demonio en ubuntu 22.04
> ![System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png " Proceso de creación de un Systemd Unit desde consola.")

====
## Proceso de creación, instalación, inicializacion y habilitación del Demonio.
====
### Proceso de creacion del Servicio 
:~$ `sudo nano /usr/local/bin/HolaMundo_fhwecys.sh` 
 
#### :~$ `sudo chmod +x /usr/local/bin/Hola_fsecysmundo.sh` 
  
:~$ **`sudo nano /etc/systemd/system/fsecysmundo.service`** 

### :~$  systemd-analyze verify /etc/systemd/system/fsecysmundo.service 

-----
### Proceso de inicializacion y habilitacion del demonio

#### `:~$  sudo systemctl daemon-reload`

### `:~$  systemctl start fsecysmundo` 

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

