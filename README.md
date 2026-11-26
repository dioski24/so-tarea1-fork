# Tarea 1 - Creacion de un proceso con fork()

Programa en C que crea un proceso hijo con la llamada al sistema `fork()`.
El padre imprime del 1 al 10,000 y el hijo del 10,000 al 1, de forma concurrente.

- `fork.c`: codigo fuente
- `salida.txt`: salida de la ejecucion en Debian 13 (Trixie)

Compilar: `gcc -Wall -Wextra -o fork fork.c`

Ejecutar: `./fork > salida.txt`
