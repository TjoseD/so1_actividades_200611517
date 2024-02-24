>> #### Actividad 3 so1
# Creación de un Systemd Unit

> #### Preview de la secuencia de comandos para crear un demonio en ubuntu 22.04
> ![System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png " Proceso de creación de un Systemd Unit desde consola.")

# Proceso de creación, inicialización y habilitación del Demonio _fsecys_.

## Proceso de creacion del Servicio o demonio *fsecys.service*
**crear el programa**

El primer paso es crear un archivo que tendra el programa que se ejecutara, esta debe de tener extension **.sh** porque sera ejecutable y debe estar en la sigiuente ruta */usr/local/bin/*, esta ubicación es un estandard que hace accesible a los usuarios del sistema sin la necesidad que indiquen la ruta especifica. Nuestro archivo se llamara *HolaMundo_fecys.sh*. 
Abrimos un editor de texto para crear el archivo, en nuestro caso usamos *nano* y lo hacemos  ejecutando la siguiente linea de comando.  
### :~$ `sudo nano /usr/local/bin/HolaMundo_fecys.sh`  

y nos abre el editor donde escribimos el siguiente bloque de codigo.
> ![System Unit](https://i.postimg.cc/0jtPGDxZ/Screenshot-105.png "Programa que muestra un mensaje y la fecha en consola.")  
>recuerde que para guardar y salir del editor de texto se usan: para grabar  **Ctrl+O** y para salir **Ctrl+X**

Una vez creado el archivo del programa, debemos asignarles permiso de ejecutable con *chmod + x*, lo hacemos ejecuando la siguiente linea de comando.  
### :~$ `sudo chmod +x /usr/local/bin/HolaMundo_fsecys.sh` 
  
 Bien estamos listos para crear el servicio o demonio y para ello debemos de crear un nuevo archivo y guardarlo en el siguiente path */etc/systemd/system/*, este ruta debe ser exacta, es una ruta estandard  
### :~$ `sudo nano /etc/systemd/system/fsecys.service`  
 Y escribimos el siguiente codigo en el archivo.  

> ![System Unit](https://i.postimg.cc/k5gj36b3/Screenshot-115.png "Programa que muestra un mensaje y la fecha en consola.")  

Es recomendable verificar si el archivo fue contruido correctamente. Pdemos hacer uso del comando **system-analyze verify** para verificar si todo esta correcto. lo hacemos con la siguiente linea de comando. 

### :~$  `systemd-analyze verify /etc/systemd/system/fsecys.service`  
Si en caso hubiera algun error nos mostraria un mensaje como el siguiente.  
![System Unit](https://i.postimg.cc/D07QLmKy/Screenshot-278.png ) 


-----
## Proceso de inicializacion y habilitacion del demonio  

Una vez validado todo, se debe recargar el ***systemd*** para sea consiente del nuevo servicio recien creado y para ello hacemos uso del comando **systemctl** y  le indicamos la tarea de recargar con el parametro ***reload***. Este comando se comunica con el systemd para que reinicie los demonios.  
> Lo hacemos ejecutando la siguiente linea de comando. 

### :~$  `sudo systemctl daemon-reload`  
Una ves recargado los demonios hay que inicializar el nuevo servicio con la instrucción **systemclt start**, pasandole como parametro el servicio a iniciar. En nuestro caso es el servicio *fsecys.service*

### :~$  `systemctl start fsecys`  
Bien si es un servicio que queremos que se inicie automaticamente cuando arranca el sistema, debemos indicarle al comando **systemctl** que lo habilite pasandole el parametro ***enable*** y el nombre del servicio, en este caso *fsecys*.
> La siguiente línea de comando realiza eso.  

#### :~$ `systemctl enable fsecys`  

Con esto queda finalizada y puesta en marcha el servicio.

----
## Chequeo del estado del servicio y de su logfile.
Estado del servicio o demonio.
> Para verificar el estado del servicio, podemos verificar su ___status___ con el comando __systemctl__ .

> #### :~$ `systemctl status fsecys`  
> Esta linea de comando nos mostrara si el servicio esta activo o inactivo entre otra información.  
  ![System Unit](https://i.postimg.cc/QNBTtRKW/Screenshot-279.png "") 

---
Consulta del archivo log del servicio.
> Para consultar el logfile del servicio, en este caso _fsecys.service_ hacemos uso el comando **journalctl** con  el parametro ***-u*** seguido del nombre del servicio.  
> ####`:~$ `journalctl -u fsecysmundo.service`  
> Nos mostrara la siguiente información.  
![System Unit](https://i.postimg.cc/WpMsXnQH/Screenshot-128.png "")  


Y de esta manera terminamos con este manual. Good luk!

---
>> Elementos 

Comandos: 
>__chmod +x__  |  __system-analyze verify__   |  __systemctl daemon-reaload__  |  __system start__  |  __systemctl enable__  |  __systemctl status__  |  __journalctl -u__.  

Directorios:  

+ _/usr/local/bin_
+ _/etc/systemd/system_  

Archivos:

- HolaMundo_fsecys.sh
- fsecys.service  

<img src="https://i.postimg.cc/HLcg54w3/Screenshot-131.png" width="250" height="150">
<img src="https://i.postimg.cc/QCNYgjLs/Screenshot-132.png" width="300" height="200">
---
Resumen  
Creacion:![Creacion de System Unit](https://i.postimg.cc/9QWPs1Ff/Screenshot-114.png "Pasos para crear un demonio en Ubuntu 22.04") 

Inicializacion y habilitacion:
![Creacion de System Unit](https://i.postimg.cc/xdrsxvr6/Screenshot-121.png "Pasos para poner en marcha y habilitar demonio en Ubuntu 22.04")

___  

>> ##### _SO1 ECYS FIUSAC 2024_  

