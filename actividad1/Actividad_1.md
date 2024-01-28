Conceptos de Sistemas Operativos

Kernel: es la base que permite la interacción entre hardware y software. Se divide en capas, desde la mas cercana al hardware hasta el mas cercano al usuario. Todas las órdenes que recibe tienen una secuencia que seguir para ser ejecutadas, el kernel acompaña y sirve como guía durante todo el recorrido de la orden.


Tipos de kernel y sus diferencias


User vs kernel mode
existen dos modos de operacion: modo user y modo kernel.
el sistema establece el modo de operacion a traves de un bit llamado mode bit, se agrega al hardware para indicar el modo actual de operacion. 0 para el modo kernel y  1 para el modo usuario. con esto se puede dinstinguir entre una tarea que es ejecutada en representación del sistema operativo y una que es ejecutada en representacion del usuario.

el modo  usuario(1): tiene acceso restringido al SCI(interfaz de llamaas al sistema). 
el modo kernel(2), tambien llamado modo supervisor, modo sistema, o modo privilegiado: tiene acceso ilimitado al hardware,  


en el acceso a hardware: toda tarea ejecutada en modo kernel tiene full acceso a todo, mienstras que en modo usuario tiene ese acceso restringido. 
En la ocurrencia de un error, en el modo usuario no pasa mayor cosa, el kernel interviene como mediador, toma el control, corrige o repara los daños y regresa el control y todo vuelve a la normalidad, mientras que en modo kernel lleva a un fallo total y puede significar la caida del sistema. 

La diferencia en acceso al hardware y otros recursos segun el modo es lo que permite cierta seguridad en el sistema, ya que aisla los fallos y procura que niguna aplicacion interfiera con la actividad y los recursos de otra aplicacion.


Interruptions vs traps
Una de las cualidades de un sistema operativo es que sea  multitarea, permitiendo aprovechar de la mejor forma el uso del procesador, varias tareas son ejecutadas al mismo tiempo como si fueran uno. La forma en que se logra eso esque exciste mecanismos para compartir el procesador a traves de eventos que captura la atencion del procesador. Existe una jerarquia en las tareas para determinar que tarea puede suspender momentaneamente a otra.  las interrumpciones y los traps juegan un rol importante en esto.

La interrupcion es usada por los sistemas operativos para el manejo de eventos asincronas.




Interrumpciones:
Una interrupcion(evento) es una solicitud del hardware al CPU, que no implica el cambio de modo de operacion, para ser atendido, se mantiene en modo usuario; 
![interrupcion](https://xatimg.com/image/XWF4Hb8cqFlf.png)

![trap](https://xatimg.com/image/1skR6bpbGKRv.png)
