### so1 Actividad 5  

# Conceptos de Sistemas Operativos
---
>**Kernel:** es la base que permite la interacción entre _hardware_ y _software_. Se divide en capas desde la mas cercana al hardware hasta el más cercano al usuario. Todas las órdenes que recibe tienen una secuencia que seguir para ser ejecutadas. El _kernel_ acompaña y sirve como guía durante todo el recorrido de la orden.


## Tipos de kernel y sus diferencias
Existen diferentes tipos de kernel para diferentes sistemas operativos y dispositivos.
atendiendo a las caracteristicas encontramos 3:
- Kernel monolítico
- Microkernel
- Kernel Hibrido

### Kernel Monolítico:
Se trata de un kernel grande para todas las tareas. Es el único responsable para la gestión de memoria, gestion de procesos, proveer de soporte de drivers y hardware. 
*Ejemplos de estos kernel: los kernel de Linux, OS y Windows.*

### Microkernel:
Estos se diseñan intencionalmente de tamaño pequeño, esto como mecanismo contra fallos y evitar que se paralice todo el sistema cuando ocurra un error.  estan divididos en varios modulos con la finalidad de poder asumir las mismas funciones que un kernel grande realiza. 
*Ejemplo de este es Mach de OS X, hasta el momento no hay ningun sistema operativo con microkernel.*

### Kernel Híbrido:
Este Kernel combina las caracteristicas de las dos anteriores. El kernel grande se hace mas compacto y modulable. Otras partes del kernel pueden cargarse dinámicamente. 
*Ejemplos: este comportamiento ya se encuentra de cierta forma en Linux y OS X.*

## User vs kernel mode
>El *Sistema Operativo* y sus *Usuarios* comparten los recursos de hardware y software de un Sistema de computo. Y para ello existen dos modos de operación en un sistema de computación: ***modo user*** y ***modo kernel***.

El Sistema establece el _modo de operación_ a traves de un bit llamado ***mode bit***, se agrega al hardware para indicar el modo actual de operacion. El **0** para el *modo kernel* y  **1** para el *modo usuario*. Esto permite que se pueda dinstinguir entre una tarea que es ejecutada en representación del Sistema Operativo y una que es ejecutada en representacion del Usuario.

- __El modo  usuario__: tiene ***acceso restringido*** al **SCI**(*interfaz de llamaas al sistema*). 
- __El modo kernel__ tambien llamado modo supervisor, modo sistema, o modo privilegiado: tiene ***acceso ilimitado*** al hardware,  


Las implicaciones de la  *ocurrencia de un error* segun el modo de operacion. En el __modo usuario__ no pasa mayor cosa, el kernel interviene como mediador, toma el control, corrige o repara los daños y regresa el control y todo vuelve a la normalidad; mientras que en __modo kernel__ lleva a un fallo total y puede significar la caida del sistema. 

La diferencia en *acceso al hardware* y otros recursos segun el modo de operación, es lo que permite cierta *seguridad* en el sistema, ya que aisla los fallos y procura que niguna aplicación interfiera con la actividad y los recursos de otra aplicación.


## Interruptions vs traps
>Una de las cualidades de un sistema operativo es que sea __Multitasking__( *multitarea*), permitiendo aprovechar de la mejor manera el uso del procesador, donde varias tareas son ejecutadas al mismo tiempo como si fueran uno.

La forma en que se logra la cualidad de multitarea esque existen mecanismos para compartir el procesador a traves de *eventos* que captura la atencion del procesador. Existe una jerarquía en las tareas para determinar que tarea puede suspender momentaneamente a otra.  
> Las interrumpciones y los traps juegan un rol importante en esto.

La interrupción es usada por los sistemas operativos para el manejo de eventos asincronas.




Una __interrupción__(*evento*) es una solicitud del hardware al __CPU__, que __no__ implica el cambio del modo de operacion para ser atendido, se mantiene en modo usuario. 

![interrupcion](https://xatimg.com/image/XWF4Hb8cqFlf.png)
_ _ _
Un __trap__ (*excepción*) es una interrupción generado por software  causado por un error o falla del hardware o por una solicitud específica para una operación especial a traves de una *llamada al sistema* por medio de ***syscall***. > Cuando el sistema atiende y toma el control __implica en cambio en el modo de operación__ de *usuario* a *kernel*.
![trap](https://xatimg.com/image/1skR6bpbGKRv.png)
_ _ _

Una __interrupción__ se da cuando un _evento_ interrumpe la actividad del __CPU__ por la solicitud de un _controlador de hardware o dispositivo_  para que le pueda atender con una __rutina de servicio_. El CPU al recibir la señal por la línea de interrupcion, detiene la actividad que está realizando e inmediátamente transfiere la actividad de ejecución a _la rutina de servicio_ correspondiente, y solo una vez que haya finalizado, retoma la actividad en la que estaba anteriormente.

Un __trap__ (_excepción_) se da cuando un programa realiza una petición al sistema a traves de ___syscall___ para que intervenga y atienda una solicitud específica que puede ser una _falla_ o una _operación especial_, el sistema atiende el llamado, toma el control, __cambia de modo de operación__ y realiza la actividad correspondiente y una vez terminada la actividad finaliza la intervención, cambia de nuevo el *modo* de operación de *kernel* a *usuario* y regresa el control.

-----

>> ##### _SO1 ECYS FIUSAC 2024_  
