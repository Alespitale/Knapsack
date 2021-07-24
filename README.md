# Knapsack

Backtracking y Programación Dinámica.

## Interfaz de línea de comandos

El programa lee listas de items desde archivos de texto con el siguiente formato:
# KNAPSACK:15 VALUE:14
A:13:15
B:6:7
C:8:4

La primera línea contiene la capacidad máxima de la mochila (15), y de manera opcional se
puede colocar el valor máximo esperado (14). Las siguientes líneas contienen los items (uno
por línea) en el formato nombre:valor:peso.
Si la primera línea contiene el valor esperado (14), y se le ingresa al programa la opción -t,
se verificará que el resultado de las funciones coincida con el mismo.

Las opciones del programa son las siguientes:
- b: habilitar el algoritmo de backtracking
- d: habilitar el algoritmo de programación dinámica
- s: mostrar los items seleccionados (sólo junto con -d)
- w <arg>: forzar la capacidad de la mochila a "arg" (ignorando campo KNAPSACK de la
primera lı́nea del archivo)
- t: habilitar las verificaciones (lee VALUE desde primera lı́nea)
-f <files>: lista de archivos para los cuáles se quiere correr los algoritmos habilitados. Si
no se incluye esta opción se pide la lista de items desde el teclado en el formato
nombre:valor:peso
  
Utilizar comando "make" para compilar.
  
### Algunos ejemplos:

 - Bactracking:
  ```
  $ ./knapsack -b -f input/example0.in
  ```
 - Dinámica:
  ```
  $ ./knapsack -d -f input/example0.in
  ```
  - Dinámica mostrando selección de items:
  ```
  $ ./knapsack -ds -f input/example0.in
  ```
  - Backtracking y Dinámica:
  ```
  $ ./knapsack -bd -f input/example0.in
  ```
  - Backtracking y Dinámica mostrando selección y verificando el valor obtenido:
  ```
  $ ./knapsack -bdst -f input/example*.in

  - test memory leaks y los errores de acceso a memoria:
  ```
  $ valgrind --show-reachable=yes --leak-check=full ./knapsack -b -f input/example0.in
  ```

Por ej. Para utilizar backtraking, dinamic_selection y verificar si hay memory leaks, ejecutar:

valgrind --show-reachable=yes --leak-check=full ./knapsack -dst -f input/random-5.in

Luego de realizar todas las pruebas, ejecutar "make clean" para limpiar los ejecutables creados durante la compilacion.

## Materia: Algoritmos y estructura de datos 2
