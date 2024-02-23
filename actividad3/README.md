 Actividad 3 so1
# Systemd unit
### Proceso de instalacion de un servicio y chequeo de su log
Secuencia de comandos e instrucciones:
-----------------
:~$ sudo nano /usr/local/bin/HolaMundo_fhwecys.sh 
 
# :~$ sudo chmod +x /usr/local/bin/Hola_fsecysmundo.sh 
  
## :~$ sudo nano /etc/systemd/system/fsecysmundo.service

### :~$  systemd-analyze verify /etc/systemd/system/fsecysmundo.service

#### :~$  sudo systemctl daemon-reload

##### :~$  systemctl start fsecysmundo 

###### :~$ systemctl enable fsecysmundo
===========
- :~$ systemctl status fsecysmundo

:~$ ** journalctl -u ** fsecysmundo.service 

* :~$  journalctl -u  fsecysmundo.service *

> :~$ systemctl status fsecysmundo

:~$ *** journalctl -u *** fsecysmundo.service 

:~$ 'systemctl status fsecysmundo'

:~$ `systemctl status fsecysmundo`

":~$ `systemctl status` fsecysmundo"

![System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png "Imagen de los comandos ejecutados en consola  crear el Systemd Unit.")

Use [Step by Step create a System Unit on Linux](https://www.fosslinux.com/111815/a-guide-to-creating-linux-services-with-systemd.htm "Una de mies fuentes de consulta").

[![](https://youtu.be/qHGTs1NSB1s)](https://youtu.be/qHGTs1NSB1s)

