>> #### Actividad 6 so1
# Procesos e hilos

## P1 ¿Cuantos procesos son creados por el siguiente programa?

[![Programa de procesos en lenguaje c](https://i.postimg.cc/zvT5hTvx/Screenshot-from-2024-09-12-09-14-24.png)](https://postimg.cc/0K5LRMpS)  


_Resultado_:  
**Numero de procesos creados**:  
[![Procesos creados](https://i.postimg.cc/Vvcjt7tS/Screenshot-from-2024-09-12-09-42-32.png)](https://postimg.cc/62Y2JfYw)

## P2 Creación de un proceso hijo que se convierta en zombie.  
Programa:  
[![Programa zombie](https://i.postimg.cc/MHGJFRkx/Screenshot-from-2024-09-12-23-44-44.png)](https://postimg.cc/R62Y3WVb)

Ejecucion del programa `./p2_proceso_zombie`     
[![ejeucion de p2_proceso_zombie](https://i.postimg.cc/jSzbFRW8/Screenshot-from-2024-09-12-23-29-27.png)](https://postimg.cc/9DFK45YT)

Ejeucion del comando `ps aux`
[![ps aux of process](https://i.postimg.cc/5t7wddTz/Screenshot-from-2024-09-12-23-28-44.png)](https://postimg.cc/NyXymVgG)


Ejecución del comando `top`  
[![commando top](https://i.postimg.cc/L5XPxyNT/Screenshot-from-2024-09-12-23-43-25.png)](https://postimg.cc/ftGkLv4t)


## P3 Procesos unicos e hilos unicos

Progrma de Procesos e hilos unicos usando el comando fork  

p3_procesos_hilos.c  
[![Programa de procesos e hilos unicos usando fork](https://i.postimg.cc/MHMFY7X4/Screenshot-from-2024-09-13-13-18-33.png)](https://postimg.cc/n9x2FQ4Y)

Visualizando la información de los procesos e hilos unicos   

Ejecucion del programa  `./p3_procesos_hilos`  
[![ejecucion de ./p3_procesos_hilos](https://i.postimg.cc/90CvcRfN/Screenshot-from-2024-09-13-13-14-53.png)](https://postimg.cc/bDV6TvkQ)



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

