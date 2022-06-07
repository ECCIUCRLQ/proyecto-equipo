## Resumen de producto


El producto consistirá en la base proporcionada por el enunciado.
Este diseño contiene, en orden presentado en la imagen;
 - Dispositivo virtualizado, creado con simics
 - Protocolo de comunicación entre el driver y el dispositivo, es imperativo que este protocolo funcione con todos los equipos, por lo tanto, necesitara seguir requerimientos y lineamientos para asegurar su funcionamiento general
- Driver, comunicara el dispositivo virtualizado con una aplicación 
- Aplicación, la cual debe demostrar el correcto funcionamiento tanto del dispositivo como el funcionamiento del driver
- Pruebas de validación, las cuales demuestran el funcionamiento descrito anteriormente por medio de una serie de pruebas



![Diseño](https://user-images.githubusercontent.com/56287760/171331662-9dd27edd-53ca-4d50-ab91-b60635354431.png)


Este mapa fluye de la siguiente manera:

1. El dispositivo virtualizado se comunica con el protocolo.
2. El protocolo se comunica con el driver, este permite la comunicación entre el dispositivo y el computador/programa.
3. A este se le aplican las pruebas de validación para cerciorar su correcto funcionamiento.

Se utilizara este diseño para crear un sistema que proporcione lo siguiente;
- Inicializar el dispositivo virtualizado
- Arrancar y/o utilizar el driver para comunicar el dispositivo con la PC
- Correr las pruebas utilizando fotografías y filtros programados con antelación 
