/*
 * Tarea 1 - Creacion de un proceso con fork()
 * El proceso padre imprime del 1 al 10000.
 * El proceso hijo imprime del 10000 al 1.
 */
#include <stdio.h>      /* printf, perror, setvbuf */
#include <stdlib.h>     /* exit, EXIT_SUCCESS, EXIT_FAILURE */
#include <unistd.h>     /* fork, getpid, getppid */
#include <sys/types.h>  /* pid_t */
#include <sys/wait.h>   /* wait */

#define LIMITE 10000

int main(void)
{
    pid_t pid;
    int i;

    /* Salida con buffer por linea: cada printf que termina en \n se
       escribe de inmediato. Asi, aunque redirijas a salida.txt, se ve
       como se intercalan padre e hijo. */
    setvbuf(stdout, NULL, _IOLBF, 0);

    pid = fork();   /* A partir de aqui hay DOS procesos ejecutando */

    if (pid < 0) {
        /* fork fallo: no se creo ningun hijo */
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        /* Codigo del HIJO: fork le devolvio 0 */
        printf("[HIJO]  PID=%d, PID de mi padre=%d\n", getpid(), getppid());
        for (i = LIMITE; i >= 1; i--) {
            printf("Hijo: %d\n", i);
        }
        exit(EXIT_SUCCESS);
    }
    else {
        /* Codigo del PADRE: fork le devolvio el PID del hijo */
        printf("[PADRE] PID=%d, PID de mi hijo=%d\n", getpid(), pid);
        for (i = 1; i <= LIMITE; i++) {
            printf("Padre: %d\n", i);
        }
        wait(NULL);   /* Espera a que el hijo termine (evita un zombi) */
        printf("[PADRE] El hijo termino. Fin del programa.\n");
    }

    return 0;
}
