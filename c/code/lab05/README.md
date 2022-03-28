# Programmazione di Sistema - DIEF/UNIMORE

## Esercizi C (File ed integrazione con la shell)

Si propone un gruppo di esercizi per imparare ad utilizzare l'accesso ai file e l'integrazione del C con la shell. In
particolare, viene proposta una serie di implementazioni semplificate di famosi comandi shell.

--- 

Esercizio 1. Implementare una versione semplificata del comando *echo*

```shell
$ echo [string ...]
```

dove:

* **[string ...]** rappresenta un gruppo di stringhe;
* il comando visualizza a monitor le stringhe passate come argomenti.

---

Esercizio 2. Implementare una versione semplificata del comando *touch*

```shell
$ touch filename
```

dove:

* **filename** rappresenta un nome di file da creare (vuoto).

---

Esercizio 3. Implementare una versione semplificata del comando *size*

```shell
$ size filename
```

dove:

* **filename** rappresenta un nome di file di cui mostrare la dimensione in byte.

---

Esercizio 4. Implementare una versione semplificata del comando *cmp*

```shell
$ cmp filename_a filename_b
```

dove:

* **filename_a, filename_b** rappresentano due nomi di file da confrontare;
* il comando informa l'utente se i 2 file sono uguali o diversi. Se sono diversi, indica byte e linea della primo
  carattere diverso.

---

Esercizio 5. Implementare una versione semplificata del comando *cat*

```shell
$ cat [file ...]
```

dove:

* **[file ...]** rappresenta un gruppo di percorsi a file. In caso nessun percorso venga indicato, cat legge da stdin;
* il comando visualizza il contenuto dei file passati come parametro.

---

Esercizio 6. Implementare una versione semplificata del comando *cp*

```shell
$ cp filename_1 filename_2
```

dove:

* **filename_1 filename_2** rappresentano sorgente e destinazione della copia;
* il comando copia il contenuto di filename_1 all'interno di filename_2.

---

Esercizio 7. Implementare una versione semplificata del comando *head*

```shell
$ head filename n
```

dove:

* **filename** rappresenta un nome di file di cui mostrare le prime **n** linee.

---

Esercizio 8. Implementare una versione semplificata del comando *tail*

```shell
$ tail filename n
```

dove:

* **filename** rappresenta un nome di file di cui mostrare le ultime **n** linee.
