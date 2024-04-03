
### so1 Actividad 7
# Completely Fair Scheduler (CFS)



-----

### Características  
La caractarística principal del algoritmo CFS es  la de hacer promesas reales acerca de su rendimiento y luego complir esas promesas.

Considerando que si se tiene en una máquina con ___n usuarios___, el algoritmo  intentará asignarle __1/n del poder del CPU__ a cada usuario. De la misma manera si es una una máquina de un solo usuario donde se ejecutan ___n procesos___, el algoritmo intentará asignarle a cada proceso __1/n__ del poder del CPU a cada proceso.

Enseguida se enumeran las otras caractiristicas que permiten que se pueda cumplir las promesas:  
- __Lleva la cuenta__ de _cuanta potencia de CPU_ ha _tenido cada proceso desde su creación_.  
- __Calcula__ _cuanto poder de la CPU_ debe ___asignarle a cada proceso___, teniendo en cuenta el tiempo desde que se creo dividido n procesos.  
- __Calcula__ la _proporción del tiempo de CPU que se consumió_ y contrastándolo con _el tiempo de CPU  al que cada proceso tiene derecho_.  
    Al ver la proporción consumida del poder de la CPU al que tiene derecho. Si la proporci+pn es de 0.5 significa que solo ha tenido la mitad del tiempo al que tiene derecho. Y si la proporción indica 2.0 indica que un proceso ha tenido el doble del tiempo del que debería de tener.  
- El algoritmo ___ejecuta el proceso con la menor proporción___ hasta que se haya desplazado por debajo de su competidór más cercano.  

## Como se implementa CFS en linux
En linux se implementa, __manteniendo un registro del _tiempo de ejecución invertido_ para los procesos y guardarlos en una eficiente estructura de datos conocido como _Arbol red-black_.__  

El __nodo mas a la izquierda__ en el arbol corresponde al proceso con ___el menor tiempo invertido___.  

El planificador (Scheduler) __indexa__ el arbol por ___el tiempo de ejecución___ y selecciona ___el nodo mas a la izquierda___ para ejecutarlo.  

Cuando el proceso es detenido en su ejecución, ya  sea por que se le terminó su tiempo, o por bloqueo o por interrupción, el planificadór lo __reinserta__ en el arbol basado en su ___nuevo tiempo  de ejecución invertido___. 

[![red-black tree imagen](https://xatimg.com/image/2xwQnCPdX1qy.png)](https://postimg.cc/1f68tmbB)

El _CFS scheduler_ tiene una instancia, el  __`task_struct`__ en c, para _rastrear información detallada_ sobre  de cada tarea que se planificará. Esta estructura incorpora una estructura __`sched_entity`__, que a su vez tiene información específica de la programación, en particular, ___el tiempo de ejecucion por tarea___ o grupo de tareas.

[![task_struct imagen](https://xatimg.com/image/gnIdKeuJcZyY.png)](https://postimg.cc/1f68tmbB)

Una instancia de estructura __`cfs_rq`__ incorpora un campo __`rb_root`__ llamado ___`task_timeline`___, que apunta a la raíz de un arbol _`red-black`_. Cada uno de los nodos internos del arbol tiene punteros al nodo principal y a los dos nodos secundarios; los nodos hoja tienen cero como valor.


----  
## Gráficas  
    Red-Black Tree:  
[![Arbol red-black](https://xatimg.com/image/jnKTPA0x4GLk.gif)](https://postimg.cc/1f68tmbB)

Estructura de datos, binario balanceado, con __O(log N)__ para las operaciones de _inserción_ y _eliminación_.  

Cada nodo respresenta uan tarea planificada, y el arbol completo respresenta la línea de tiempo para la ejcución de tareas.

En conclusión, ___la tarea con el menor tiempo de ejecucion___ y por consiguiente ___el que mas necesita por la atecion del CPU___, esta en algun lugar del _subarbol izquierdo_.


___  


>> ##### _SO1 ECYS FIUSAC 2024_  
