# Programmazione di Sistema (DIEF, UNIMORE)

## Software
* [VirtualBox](https://www.virtualbox.org/wiki/Downloads)
* [Ubuntu Linux](https://ubuntu.com/download/desktop)
* [CLion](https://www.jetbrains.com/clion/)

## Tutorial, Esercizi Online
* https://www.hackerrank.com/domains/shell
* https://www.tutorialspoint.com/unix/
* https://seankross.com/the-unix-workbench/
* https://explainshell.com/
* https://www.hackerrank.com/domains/c
* http://en.wikipedia.org/wiki/C_(programming_language)
* http://en.wikipedia.org/wiki/C_syntax
* http://en.wikibooks.org/wiki/C_Programming
* http://cppreference.com 

## Libri Bash
* Marco Liverani - Unix introduzione elementare
* Marco Liverani - Programmazione della Shell Bash
* Jason Bacon, Lars Olson - Unix User's Guide
* Chet Ramey, Brian Fox - Bash Reference Manual


## Libri C
* **Facchinetti, Larizza, Rubini - Programmare in C**
* BlackLight - Il Linguaggio C
* Banahan, Brady, Doran - The C Book
* Burgess - The GNU C Programming Tutorial

## Video
* [YouTube CLion](https://www.youtube.com/playlist?list=PLQ176FUIyIUb_J7ZEi2IDe9132-dq_vQL)
* [YouTube Bash](https://www.youtube.com/watch?v=62-hJarauK4&list=PLhlcRDRHVUzR-5TKDC1VPMtyhEyyQ5uwy)
* [YouTube C]()

## Microsoft Teams
Durante il corso utilizzeremo Microsoft Teams per tenerci in contatto, discutere esercizi e problemi vari. Chi non lo avesse ancora fatto, è pregato di iscriversi al canale dedicato al corso.

## Materiale didattico

Una volta terminata l'installazione di Ubuntu, per completare l' installazione del materiale didattico aprire un terminale ed inserire i seguenti comandi. 

```bash
$ sudo apt install git 
$ git clone https://github.com/nbicocchi/operatingsystemsbsc.git
$ cd operatingsystemsbsc/post-install/
$ chmod 755 ./ubuntu-post-install.sh
$ ./ubuntu-post-install.sh
```

Il materiale puo' essere aggiornato e/o corretto durante lo svolgimento del corso. Per scaricare la versione piu' recente, entrare nella cartella del materiale e digitare il comando seguente:

```bash
$ git pull 
```
In caso di errori, utilizzare invece i comandi sotto (tutte le modifiche locali al repository andranno perdute)

```bash
$ git reset --hard HEAD
$ git clean -df
$ git pull
```

## Moduli Bash
[M1] Introduzione a Unix
* Installazione sistema operativo
* Kernelspace e Userspace
* Utenti (gruppi, permessi)
* Filesystem (struttura interna, file, directory, devices)
* Processi (sequenza di boot, processo init, stdin/stdout/stderr)
* Manuale di sistema (man)
* Editor di testo (vim, nano)
* Gestione pacchetti (apt-get)

[M2] Bash Shell
* Bash (builtins, auto-completamento, ricerca comandi)
* Flussi dati standard (input, output, error)
* Ridirezione flussi dati (>, <)
* Composizione comandi (|)
* Variabili locali
* Variabili d'ambiente
* Metacaratteri
* Espansione ed inibizione

[M3] Bash Scripting
* Shebang
* Variabili speciali ($#, $N, $\*, shift, $@, $?, $$)
* Strutture di controllo (if, test, for, case)
* Funzioni
* Arrays
* Gestione argomenti linea di comando (getopts)

[M4] Comandi Unix
* Filesystem (ls, pwd, basename, dirname, cp, mv, ln, stat, rm, mkdir, rmdir, which, locate, touch, chmod, chown, cmp, diff, find)
* Filtri (cat, grep, sort, head, tail, cut, wc, tr, uniq, sed)
* Processi (ps, top, kill, fg, bg, &)
* Utenti (adduser, rmuser, whoami, id, sudo)
* Compressione (tar, gzip, bzip2)
* Varie (dd, echo, read, true, false, expr, date, man, apropos)

## Moduli C
[M1] Introduzione al linguaggio C
* Identificatori
* Variabili
* Espressioni
* Parole chiave

[M2] Preprocessore
* *\#define*
* *\#include*
* *\#if*
* *\#ifdef*

[M3] Istruzioni e strutture di controllo
* Costrutto condizionale *if-else*
* Costrutto di selezione *switch-case*
* Costrutti iterativi *for*, *while*, *do-while*
* Istruzioni *break*, *continue*

[M4] Tipi di dati
* Organizzazione della memoria
* Tipi interi ed in virgola mobile
* Puntatori
* Array
* Stringhe 
* Conversione di tipo (casting implicito, esplicito)
* Funzioni (matematiche, numeri pseudo-casuali, stringhe, I/O console)
* Operatori

[M5] Funzioni
* Dichiarazione, definizione, chiamata a funzione
* Variabili locali, globali e static
* Passaggio di parametri (per valore, per riferimento)
* Ricorsione

[M6] Tipi di dati derivati
* Array multi-dimensionali
* Strutture dati
* Enumerazioni
* *typedef*

[M7] Puntatori 
* Puntatori a void
* Puntatori e array
* Aritmetica dei puntatori
* Allocazione dinamica della memoria

[M8] File
* File binari e file di testo
* Apertura, chiusura, posizione corrente
* Lettura e scrittura (con e senza formattazione)
* Flussi standard (stdin, stdout, stderr)

## Esame
L'esame consiste in 2 esercizi al calcolatore (1x Bash, 1x C) che gli studenti sono tenuti a svolgere sul loro calcolatore (utilizzando le pagine man, in caso) spiegando al docente lo svolgimento. Esempi di esercizi si trovano nelle cartelle bash/code e c/code suddivisi per livello di difficoltà.
