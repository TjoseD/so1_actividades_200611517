>> #### Actividad 6 so1 semestre 2
-----
# Procesos e hilos

## P1 ¿Cuantos procesos son creados por el siguiente programa?
Codigo fuente del programa `p1_procesos` para la creacion de procesos con fork  
[![Programa de creacion de procesos con fork](https://i.postimg.cc/rmTqY3gL/Screenshot-from-2024-09-13-14-26-26.png)](https://postimg.cc/VS7yJ737)  



_Resultado_:  
**Numero de procesos creados**:  

Procesos creados con la ejecución del programa `p1_procesos`  
[![Procesos creados](https://i.postimg.cc/nzGW2c3q/Screenshot-from-2024-09-13-14-33-24.png)](https://postimg.cc/gXr4kdF0)

Como se puede ver se crearon 8 procesos unicos siendo el proceso padre bash con PID: 
estos 8 procesos se pueden verificar al revisar los procesos activos con el comando __ps aux__  

Procesos en ejecucion `ps aux`  
[![Procesos en ejecución](https://i.postimg.cc/6qWtBP7x/Screenshot-from-2024-09-13-14-30-15.png)](https://postimg.cc/47Sr5BbW)   
Lo que esta resaltado en blanco son los 8 procesos creados por la ejecucion del programa __p1_procesos__


## P2 Creación de un proceso hijo que se convierta en zombie.  

Codigo fuetne del programa`p2_proceso_zombie` el cual crea un proceso zombie   
[![Programa zombie](https://i.postimg.cc/MHGJFRkx/Screenshot-from-2024-09-12-23-44-44.png)](https://postimg.cc/R62Y3WVb)

Al ejecutar el proceso, el proceso hijo tiene como tarea mostrar los procesos activos con el comando `ps` el cual tiene un **PID: 72245**  

Ejecucion del programa `./p2_proceso_zombie`     
[![ejeucion de p2_proceso_zombie](https://i.postimg.cc/jSzbFRW8/Screenshot-from-2024-09-12-23-29-27.png)](https://postimg.cc/9DFK45YT)

Podemos ver el proceso zombie al revisar los proceso activos con el comando __ps aux__ y como se puede notar el proceso con PID: 72245 tiene un estado **Z+** el cual indica que es proceso zombie, y al mismo tiempo tiene en su descripcion __defunct__ que es otra forma de indicar lo mismo. 
Ejeucion del comando `ps aux`
[![ps aux of process](https://i.postimg.cc/5t7wddTz/Screenshot-from-2024-09-12-23-28-44.png)](https://postimg.cc/NyXymVgG)

Tambien al ejecutar el comando __top__ se puede ver  que existe un proceso zombie, y esta resaltado con fondo blanco.  

Ejecución del comando `top`  
[![commando top](https://i.postimg.cc/L5XPxyNT/Screenshot-from-2024-09-12-23-43-25.png)](https://postimg.cc/ftGkLv4t)


## P3 Procesos unicos e hilos unicos

El programa p3_procesos_hilos tiene como tarea crear procesos e hilos usando fork y Create_thread()  


Codigo fuente del programa `p3_procesos_hilos`  
[![Programa de procesos e hilos unicos usando fork](https://i.postimg.cc/MHMFY7X4/Screenshot-from-2024-09-13-13-18-33.png)](https://postimg.cc/n9x2FQ4Y)

Visualizando la información de los procesos e hilos unicos   

Ejecucion del programa  `./p3_procesos_hilos`  
[![ejecucion de ./p3_procesos_hilos](https://i.postimg.cc/90CvcRfN/Screenshot-from-2024-09-13-13-14-53.png)](https://postimg.cc/bDV6TvkQ)

Se puede visualizar que se crean en total 10 procesos 


-----

___Resumen___  

>> ##### Compilacion de programa c 
> :~$`gcc nombre_fuente.c -o nombre_ejecutable`


#### Comandos o funciones:
> `ps aux`  
 `ps -el`  
 `pstree`  
+ fork()  
+ pthread_create()  
+ exit(-1)   
+ exit(NULL)  
+ getpid()  


___  

>> ##### _SO1 ECYS FIUSAC 2024_  

