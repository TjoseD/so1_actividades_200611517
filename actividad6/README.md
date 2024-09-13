>> #### Actividad 6 so1 semestre 2
-----
# Procesos e hilos

## P1 ¿Cuantos procesos son creados por el siguiente programa?
Codigo fuente del _programa_`p1_procesos` para la *creacion de procesos* con __fork__  
[![Programa de creacion de procesos con fork](https://i.postimg.cc/rmTqY3gL/Screenshot-from-2024-09-13-14-26-26.png)](https://postimg.cc/VS7yJ737)  



_Resultado_:  
**Numero de procesos creados**:  

Procesos creados con la _ejecución_ del programa `p1_procesos`  
[![Procesos creados](https://i.postimg.cc/nzGW2c3q/Screenshot-from-2024-09-13-14-33-24.png)](https://postimg.cc/gXr4kdF0)

> Como se puede ver se crearon __8 procesos unicos__ siendo el _proceso padre_ ___bash___ con **PID: 243717**  
Estos __8 procesos__ se pueden verificar al revisar _los procesos activos_ con el comando __ps aux__  

**Procesos en ejecucion** `ps aux`  
[![Procesos en ejecución](https://i.postimg.cc/6qWtBP7x/Screenshot-from-2024-09-13-14-30-15.png)](https://postimg.cc/47Sr5BbW)   
Lo que esta _resaltado en blanco_ son los ___8 procesos___ creados por la ejecucion del programa __p1_procesos__  
Los PID de los 8 procesos son: 265617, 265619, 265621,265622, 265623, 265624, 265625 y 265627.   


## P2 Creación de un proceso hijo que se convierta en zombie.  

Codigo fuente del _programa_ **`p2_proceso_zombie`** el cual __crea__ un __proceso zombie__     
[![Programa zombie](https://i.postimg.cc/MHGJFRkx/Screenshot-from-2024-09-12-23-44-44.png)](https://postimg.cc/R62Y3WVb)


Al ___ejecutar___ el proceso, el _proceso hijo_ tiene como tarea ___mostrar los procesos activos___ con el comando **`ps`**. Este proceso tiene un **PID: 72245**   
***Ejecucion del programa*** `./p2_proceso_zombie`     
[![ejeucion de p2_proceso_zombie](https://i.postimg.cc/jSzbFRW8/Screenshot-from-2024-09-12-23-29-27.png)](https://postimg.cc/9DFK45YT)


Podemos ver el ___proceso zombie___ al revisar _los proceso activos_ con el comando __ps aux__, y como se puede notar _el proceso_ con **PID: 72245** tiene un estado **Z+** el cual indica que es ___proceso zombie___, y al mismo tiempo tiene en su descripcion __defunct__ que es otra forma de indicar lo mismo.  
#### Ejeución del comando **`ps aux`**
[![ps aux of process](https://i.postimg.cc/5t7wddTz/Screenshot-from-2024-09-12-23-28-44.png)](https://postimg.cc/NyXymVgG)


Tambien se puede **verificar** _los procesos zombie_ al ***ejecutar*** el comando __top__   que nos muestra informacion de ___cuantos procesos zombie existen___. En este caso nos indica que **existe uno**, dicha información esta _resaltado_ con ___fondo blanco___.  
___Ejecución del comando___ **`top`**  
[![commando top](https://i.postimg.cc/L5XPxyNT/Screenshot-from-2024-09-12-23-43-25.png)](https://postimg.cc/ftGkLv4t)


## P3 Procesos unicos e hilos unicos

El _programa_ ___p3_procesos_hilos___ tiene como tarea _crear procesos e hilos_ usando **fork y pthread_create(...)**    

>> __Codigo fuente del programa `p3_procesos_hilos`__  
[![Programa de procesos e hilos unicos usando fork](https://i.postimg.cc/MHMFY7X4/Screenshot-from-2024-09-13-13-18-33.png)](https://postimg.cc/n9x2FQ4Y)


#### _Visualizando_ la información de los procesos e hilos unicos.   
Para visualizar cuantos procesos fueron creados al ejecutar el programa **p3_procesos_hilos** solo debemos de _ejecutar_ el programa y los __printf__ en el programa nos proporciona la _información_ concerniente a ___los procesos creados.___  


> **Ejecucion del programa  `./p3_procesos_hilos`**    
[![Ejecución del programa p3_procesos_hilos](https://i.postimg.cc/zG7Q3LKs/Screenshot-from-2024-09-13-15-31-13.png)](https://postimg.cc/k2Vspgjs)  

Como se puede ver nos muestra cuantas veces fue ejecutada la instruccion __printf__ y que _proceso_ lo realizo.  
Cada __printf__ nos muestra el ___pid retornado___ por __fork()__, el __getpid()__ nos permite obtner  el __PID__ del proceso y el  __TID__: que es el ___hilo del proceso___.  

Cuando se crea un proceso con __fork()__ retorna un __PID__ por cada proceso. Si **PID = 0**  significa que es un ___proceso hijo___ porque _no tiene hijos_. Si  **PID > 0** entonces es un __proceso padre__  y el  __PID__ corresponde al pid de su  hijo.  

El __getpid()__ nos permite _obtener el PID del proceso_  y el __TID__ el _hilo vinculado al  proceso_, como se darán cuenta  ___el getpid() y el TID coinciden___ porque para cada proceso tiene un hilo relacionado.   

#### En total se crearon  __6 Proces__ y  __6 Hilos__ 
El ___primer proceso___ e hilo corresponde al ___pronceso principal___ el del programa y se crean 5 procesos mas.  
El __primer  fork()_ crea **1 proceso ** y  un hilo mas   
El ___segundo fork()___ es ejecutado solo por ___el proceso hijo___  y crea **1 proceso**       
El __tercer fork()___ es ejecutado por ___el padre e hijo del primer fork___ y crean **2 procesos** mas, y tambien es __ejecutado__ por ___el proceso hijo del segundo fork___ que crea **otro proceso**.   

_Resumiedo_   
>> __Total de procesos__ = proceso principal **+** Proceso creados por fork1 **+** proceso creados por fork2 **+** proceso creados por fork3  

###  Total de procesos = 1 + 1 + 1 + 3 = **6** 

#### + PID de los Procesos: **231556,  231557, 231558, 231559 , 231562, 231563** 
#### + TID de los Hilos: ___2315556, 231557,  231558, , 231559,  231562, 231563___  



Para ___visualizar___ estos ***procesos creados**, solo ejecutamos **`ps aux`** para que nos muestre los ___procesos activos___.  

> **Ejecutar `ps aux`**  
  [![Visualización de procesos activos](https://i.postimg.cc/rydCrdXB/Screenshot-from-2024-09-13-15-32-53.png)](https://postimg.cc/NLcHhj0D)   

Los ___procesos resaltados___ con *fondo blanco* son los proceso vinculados a la ___ejecución___ de  **p3_procesos_hilos**  


### procesos: 231556,  231557, 231558, 231559 , 231562, 231563 
#### HIlos: 2315556, 231557, 231556*, 231558, 231557*, 231559, 231557*, 231559*, 231559*, 231557*, 231562, 231563

-----

___Resumen___  

>> ##### Compilacion de programa c 
> :~$`gcc nombre_fuente.c -o nombre_ejecutable`


#### Comandos o funciones:
> ~:$`ps aux`  
 ~:$`ps -el`  
 ~:$ `~:$pstree`  
 ~:$ `top` 
 `fork()`  
 `pthread_create()`  
 `exit(-1)`   
 `exit(NULL)`  
 `getpid()`  


___  

>> ##### _SO1 ECYS FIUSAC 2024_  

