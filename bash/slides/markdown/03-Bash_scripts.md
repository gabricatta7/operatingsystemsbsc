---
date: Marzo 2022
author: Dr. Nicola Bicocchi
institute: DIEF/UNIMORE
title: Bash Scripting
subtitle: Corso di Programmazione di Sistema
section-titles: true
theme: Madrid
colortheme: crane
fontsize: 8pt
aspectratio: 1610
lang: it
---


# Bash Script

* **La prima linea di ogni script (shebang) specifica l'interprete da utilizzare per i comandi successivi (#!/bin/bash).** Si tratta di un linguaggio interpretato (non compilato)!  
* Tutte le altre **linee che iniziano con # sono commenti nel codice**.  
$ vim script.sh


* **Rendere lo script eseguibile**  
$ chmod u+x script.sh # oppure  
$ chmod 755 script.sh

* **Eseguire lo script**  
$ ./script.sh

# Bash Script

**$ vim script.sh**  
\#!/bin/bash  
echo Total number of inputs: $#  
echo First input: "$1"  
echo Second input: "$2"  
exit 0

**$ chmod 755 script.sh**

**$ ./script.sh AAPL GOOGL MSFT**  
Total number of inputs: 3  
First input: AAPL  
Second input: GOOGL


# Bash Script

$**./**script.sh $ script.sh ?

* **Se non specifichiamo un percorso - ma solo un nome - Bash cercas un programma eseguibile nell'elenco di cartelle rappresentato dalla variabile PATH.**  
* Se PATH non contiene la cartella punto (.) che indica la cartella corrente, i programmi non vengono trovati anche se si trovano nella cartella corrente. Due opzioni:

- Invocazione tramite percorso esplicito relativo o assoluto (da preferire)  
- $ **./** script.sh

-Modifica alla variabile PATH (uso didattico)  
-$ export PATH=$PATH:.
  
-$ script.sh

# Variabili speciali

* **All'interno di uno script Bash è possibile accedere ad un gruppo di variabili speciali che rendono possibile lo sviluppo**

* **$0** Il nome dello script in esecuzione  
+ **$1, $2,...., $n** n-esimo parametro passato da linea di comando  
* **$*** tutti i parametri passati a linea di comando  
* **$@** come $* ma in forma di lista  
* **$#** numero di parametri da linea di comando  
* **$$** PID della shell  
* **$?** valore di ritorno dell'ultimo parametro  
* **shift** elimina il primo parametro dalla lista $1...$n, tutti gli altri scorrono indietro di una posizione

# exit

* **exit** termina l'esecuzione di una shell (e di conseguenza anche di uno script) e ritorna al chiamante un valore [0, 255]

$ bash &nbsp; &nbsp; &nbsp; &nbsp; # (avvio sotto-shell)  
$ exit 15 &nbsp; &nbsp; &nbsp; # (terminazione sotto-shell con valore 15)  
$ echo $?  
15  
$


# expr

* **expr** è utilizzato per eseguire operazioni matematiche. Spesso utile negli script in abbinamento a costrutti iterativi.  
&nbsp; &nbsp; &nbsp; - Op. aritmetiche: +,-,*,/,%  
&nbsp; &nbsp; &nbsp; - Op. di confronto: <,<=,==,!=,>=,>  
&nbsp; &nbsp; &nbsp; - OP. logiche: &, |


$ expr 2 \\*6  
12  
$ A=12  
$ A=$(expr $A-1)  
$ echo $A  
$ 11

# Costrutti condizionali

# test

* **test è un comando per eseguire verifiche** di varia natura sulle stringhe (interpretandole in base ai casi come stringhe, numeri o file).  
* **Un controllo avvenuto con successo ritorna 0, altrimenti 1.**

$ test 5 -gt 3; echo $? # 0  
$ test 5 -gt 3; echo $? # 1  
$ test "nicola" == "nicola"; echo $? # 0  
$ test "nicola" == "mario"; echo $? # 1  
$ test -f /etc/passwd; echo $? # 0  
$ test -d /etc/passwd; echo $? # 1

# test (strings)

* string1 = string2 &nbsp; &nbsp; &nbsp; True if strings are identical  
* string1 == string2 &nbsp; &nbsp; True if strings are identical  
* string1 != string2 &nbsp; &nbsp; True if strings are not identical  
* string &nbsp; &nbsp; &nbsp; &nbsp; Return 0 exit status (=true) if string is not null  
* -n string &nbsp; &nbsp; &nbsp; Return 0 exit status (=true) if string is not null  
* -z string &nbsp; &nbsp; &nbsp; Return 0 exit status (=true) if string is null


# test (numbers)

* int1 -eq int2 &nbsp; &nbsp; &nbsp; Test identity  
* int1 -ne int2 &nbsp; &nbsp; &nbsp; Test inequality  
* int1 -lt int2 &nbsp; &nbsp; &nbsp; Less than  
* int1 -gt int2 &nbsp; &nbsp; &nbsp; Greater than  
* int1 -le int2 &nbsp; &nbsp; &nbsp; Less than or equal  
* int1 -ge int2 &nbsp; &nbsp; &nbsp; Greater than or equal

# test (files)

* -d file &nbsp; &nbsp; &nbsp; Test if file is a directory  
* -f file &nbsp; &nbsp; &nbsp; Test if file is not a directory  
* -s file &nbsp; &nbsp; &nbsp; Test if the file has non zero length  
* -r file &nbsp; &nbsp; &nbsp; Test if the file is readable  
* -w file &nbsp; &nbsp; &nbsp; Test if the file is writable  
* -x file &nbsp; &nbsp; &nbsp; Test if the file is executable  
* -o file &nbsp; &nbsp; &nbsp; Test if the file is owned by the user  
* -e file &nbsp; &nbsp; &nbsp; Test if the file exists  
* -z file &nbsp; &nbsp; &nbsp; Test if the file has zero lenght

# test (logic)

* -o &nbsp; &nbsp; &nbsp; logical or  
* -a &nbsp; &nbsp; &nbsp; logical and  
* ! &nbsp; &nbsp; &nbsp; &nbsp; logical not

# test (logic)

 # /etc/passwd è un file E è scrivibile  
 $ **test -f** /etc/passwd **-a -w** /etc/passwd; echo $?
 
 # /etc/passwd è un file O è scrivibile  
 $ **test -f** /etc/passwd **-o -w** /etc/passwd; echo $?
 
 # /etc/passwd NON è un file O NON è scrivibile  
 $ **test ! -f** /etc/passwd **-o ! -w** /etc/passwd; echo $?
 
 
# [

* **Il comando test ha un alter ego che si comporta nello stesso modo ma ha nome diverso**  
* **Il comando è stato introdotto principalmente per aumentare la leggibilità degli script**  
* Gli spazi che vedete nell'esempio sotto, dopo [ e prima di ] sono obbligatori! La loro assenza produce errori!


$ which test  
/usr/bin/test  
$ which [  
/usr/bin/[  
$ [ -r /etc/passwd ]; echo $?  
$ 0


# if

**if &nbsp; test** &nbsp; condizione; &nbsp; **then** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # Esempio  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if &nbsp; [ &nbsp; -f &nbsp; /etc/passwd &nbsp; -a &nbsp; -r &nbsp; /etc/passwd &nbsp; ]; &nbsp; then  
**else** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "/etc/passwd file leggibile!"  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; fi  
**fi**  
  
  
  
**if** &nbsp; **\[** &nbsp; condizione &nbsp; **\]** ; &nbsp; **then** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # Esempio  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if &nbsp; [ &nbsp; $# &nbsp; -ne &nbsp; 3 &nbsp; ]; &nbsp; then  
**else** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "numero parametri errato"  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; else  
**fi** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "numero parametri corretto"  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; fi



# if

**if test** &nbsp; condizione; &nbsp; **then** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # Esempio  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; #!/bin/bash  
**elif test** &nbsp; condizione; &nbsp; **then**  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; **if** &nbsp; [ &nbsp; $# &nbsp; -lt &nbsp; 2 &nbsp; ]; &nbsp; **then**  
**else** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp;  "params &nbsp; &nbsp; < &nbsp; 2"  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;**elif** &nbsp; [ &nbsp; $# &nbsp; -lt &nbsp; 4 &nbsp; ]; &nbsp; **then**  
**fi** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "2 &nbsp; <= &nbsp; params &nbsp; < &nbsp; 4"  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; **else**  
**if** &nbsp; **\[** &nbsp; condizione &nbsp; **\]**; &nbsp; **then** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "params &nbsp; >= &nbsp; 4"  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; **fi**  
**elif** **\[** &nbsp; condizione &nbsp; **\]**; &nbsp; **then**  
&nbsp; &nbsp; &nbsp; &nbsp; comando &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; exit 0  
**else**  
&nbsp; &nbsp; &nbsp; &nbsp; comando  
**fi**


# if (forma sintetica)

* In caso un *blocco if* determini l'esecuzione di poche istruzioni è possibile utilizzare una forma sintetica (&&,||)

$ &nbsp; [ &nbsp; 1 &nbsp; -eq &nbsp; 0 &nbsp; ] &nbsp; &nbsp; && &nbsp; echo &nbsp; "pass"  
**$ &nbsp; [ &nbsp; 1 &nbsp; -eq &nbsp; 1 &nbsp; ] &nbsp; && &nbsp; echo &nbsp; "pass"**  
**$ &nbsp; [ &nbsp; 1 &nbsp; -eq &nbsp; 0 &nbsp; ] &nbsp; || &nbsp; echo &nbsp; "fail"**  
$ &nbsp; [ &nbsp; 1 &nbsp; -eq &nbsp; 1 &nbsp; ] &nbsp; &nbsp; || &nbsp; echo &nbsp; "fail"

$ &nbsp; [ &nbsp; 1 &nbsp; -eq &nbsp; 1 &nbsp; ] &nbsp; && &nbsp; (echo &nbsp; "pass"; &nbsp; pwd)
 
 
# if (forma sintetica)

* **Gli operatori && e || possono anche sostituire gli operatori -a e -o** per combinare logicamente condizioni di test trattandole come comandi separati

\# /etc/passwd è un file E è scrivibile  
$ **test -f** /etc/passwd **&& test -w** /etc/passwd; echo $?

\# /etc/passwd è un file O è scrivibile  
$ **test -f** /etc/passwd **|| test -w** /etc/passwd; echo $?

\# /etc/passwd è un file E è scrivibile  
$ **[ -f** /etc/passwd **\]** **&& [ -w** /etc/passwd **\]**; echo $?

\# /etc/passwd è un file O è scrivibile  
$ **[ -f** /etc/passwd **\]** **|| [ -w** /etc/passwd **\]**; echo $?


# Pattern matching

* **Il pattern matching consiste nel confrontare un valore con un determinatopattern**  
&nbsp; frequentemente specificato utilizzando wildcards.  
&nbsp; &nbsp; - ABCDEF &nbsp; &nbsp; &nbsp; &nbsp; A* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Match  
&nbsp; &nbsp; - ABCDEF &nbsp; &nbsp; &nbsp; &nbsp; AB??EF &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Match  
&nbsp; &nbsp; - ABCDEF &nbsp; &nbsp; &nbsp; &nbsp; ABCNN* &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; Match

* **Il costrutto test /[] non supporta pattern matching! Alternative:**  
&nbsp; &nbsp; - Il costrutto **[[]]** che si comporta come [] aggiungendo (fra altre) la funzione di pattern matching  
&nbsp; &nbsp; - Il costrutto **switch-case** che abbina il pattern matching alla possibilità di eseguire più confronti  
&nbsp; &nbsp; &nbsp; in modo sintetico (evitando else if)

# [[

 # &nbsp; [ &nbsp; ] &nbsp; fallisce &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # &nbsp; [[ &nbsp; ]] &nbsp; pattern matching
 
 if &nbsp; **[ &nbsp; "$1" &nbsp; == &nbsp; n?co* &nbsp; ];** &nbsp; then &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if &nbsp; **[[ &nbsp; "$1" &nbsp; == &nbsp; n?co* &nbsp; ]];** &nbsp; then  
 &nbsp; &nbsp; &nbsp; echo &nbsp; "success" &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "success"  
 fi &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; fi
 
 if &nbsp; **[ &nbsp; "$1" &nbsp; != &nbsp; [0-9]* &nbsp; ];** &nbsp; then &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if &nbsp; **[[ &nbsp; "$1" &nbsp; != &nbsp; [0-9]* &nbsp; ]];** &nbsp; then  
 &nbsp; &nbsp; &nbsp; echo &nbsp; "success" &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "success"  
 fi &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; fi
 

# case

**case** &nbsp; espressione &nbsp; **in** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; #!/bin/bash  
&nbsp; &nbsp; **PATTERN_1)** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; if &nbsp; [ &nbsp; $# &nbsp; -ne &nbsp; 1 &nbsp; ]; &nbsp; then  
&nbsp; &nbsp; &nbsp; &nbsp; comando/i &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "usage: &nbsp; $0 &nbsp; arg"  
&nbsp; &nbsp; &nbsp; &nbsp; ;; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; exit &nbsp; 1  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; fi  
&nbsp; &nbsp; **PATTERN_2)**  
&nbsp; &nbsp; &nbsp; &nbsp; comando/i &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; **case** &nbsp; "$1" &nbsp; **in**  
&nbsp; &nbsp; &nbsp; &nbsp; ;; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  &nbsp; echo &nbsp; "Percorso assoluto"  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; ;;  
&nbsp; &nbsp; **PATTERN_N)** &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; echo &nbsp; "Percorso relativo  
&nbsp; &nbsp; &nbsp; &nbsp; comando/i &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; ;;  
&nbsp; &nbsp; &nbsp; &nbsp; ;; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; *) &nbsp; echo &nbsp; "Nome semplice"  
&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; ;;  
&nbsp; &nbsp; *) &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; **esac**  
&nbsp; &nbsp; &nbsp; &nbsp; comando/i &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; exit 0  
&nbsp; &nbsp; &nbsp; &nbsp; ;;  
**esac**

# Costrutti iterativi


# for

**for** argomento **in** lista ; **do**  
   comando/i  
   ...  
**done**

 # Esempio: tabellina del 5  
``` shell
for i in 1 2 3 4 5; do  
  echo "5 * %i = $(expr 5 \* $i)"  
done
```

 # Esempio: mostra i nomi file in home directory 
``` shell 
for fname in "$HOME"/*; do  
   echo "$fname"  
done 
```

# seq

* Per iterare su indici, è possibile **generare una lista di indici validi da utilizzare con for utilizzando il comando seq.**

$ &nbsp; seq &nbsp; 1 &nbsp; 5  
1  
2  
3  
4  
5

 # Esempio: tabellina del 5  
``` shell
for i in $(seq 1 5); do
  echo "5 * $i = $(expr 5 \* $i)"
done
```

# while

**while** &nbsp; comando_esegue_con_successo; &nbsp; **do**  
&nbsp; &nbsp;comando/i  
&nbsp; &nbsp; ...  
**done**

 # Esempio: contatore  
``` shell
 i=10 
 while [ "$i" -gt 0 ]; do
  echo $i
  i=$(expr $i - 1)
 done
```

# Espansione variabili

* **Filesystem supportano nomi contenenti spazi. Di conseguenza, per evitare problemi, l'espansione di variabili all'interno di script (soprattutto se si tratta di nomi di file!) va effettuata con "".**  

``` shell
 $ vim script.sh  
 #!/bin/bash  
 for fname in "$HOME"/*; do
   if [ -f "$fname" ]; then
     echo F "$fname"
   elif [ -d "$fname" ]; then
     echo D "$fname"
   fi
 done
```
 
 $ touch **"**$HOME**"**/**"**Mario Rossi**"**  
 $ ./script.sh  
 ./script.sh: &nbsp; line &nbsp; 4: &nbsp; [: &nbsp; /home/nicola/**Mario**: &nbsp; binary operator expected
 
 
# Funzioni

# Funzioni

* Definite con sintassi  
**nomefunzione() &nbsp; {**  
 &nbsp; **...**  
 **}**  
* &nbsp; Accedono a parametri di invocazione con sintassi **$1 ... $n** (come gli script)  
* &nbsp; Ritornano al chiamante con istruzione **return** (script usano exit)  
* &nbsp; Valori di ritorno possono essere letti dal chiamante con sintassi **$?** (come gli script)

# Funzioni

``` shell
 #!/bin/bash  
 process() {  
   echo -n "$1"
   [ -d "$1" -a -x "$1" ] $$ return 0  
   return 1  
 }
 
 for f in $*: do  
   process "$f"  
   if [ $? -eq 0 ]; then  
     echo " [pass]"  
   else  
     echo " [fail]"  
   fi  
 done
 
 exit 0
```


# Script multi-file

 **$ vim lib.sh**  
``` shell
 #!/bin/bash 
 
 process() {  
   echo -n "$1"  
   [ -d "$1" -a -x "$1 ] && return 0
   return 1
 }
```


# Script multi-file

 **$ vim script.sh**  
``` shell 
 #!/bin/bash
 
 source lib.sh  
 # oppure  
 # . lib.sh
 
 for f in $*; do  
   process "$f"  
   if [ $? -eq 0 ]; then  
     echo " [pass]"  
   else  
     echo " [fail]"
   fi
 done
 
 exit 0
```

# Arrays

# Definizioni

$ arr=() &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;  # array definito vuoto  
$ arr=(1 2 3) &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # array definito con valori all'interno  
$ arr+=(4 5) &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # aggiunge valori ad array esistente  
$ arr[0]=3 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # sovrascrive valore di indice 0  
$ echo ${arr[@]} &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # mostra i valori nell'array  
$ echo ${!arr[@]} &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # mostra gli indici validi dell'array  
$ echo ${#arr[@]} &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; # mostra il numero di valori nell'array  
$ echo ${arr[@]:s:n} &nbsp; &nbsp; &nbsp; &nbsp; # mostra n elementi partendo da indice s


# Esempio

```shell
#!/bin/bash

files=(/var/log/kern.log /var/log/auth.log /var/log/syslog)  
keyw=(nicola marzia)

echo "* searching ${#files[@]} files with ${#keyw[@]} keywords"
echo "* press enter to continue..."
read

for f in ${files[@]}; do
  for k in ${keyw[@]}; do
    l=$(cat ${f} | grep ${k} | wc -l)
    echo "* ${f}: found ${l} occurrences of ${k}!"
  done
done
```

# getopts

# getopts

```shell
while getopts "m:dh" o; do  
  case "$o" in  
     m) MESSAGE="$OPTARG"  
       ;;  
     d) DEBUG=TRUE  
       ;;
     h) usage  
       ;;  
     *) usage  
       ;;  
  esac  
done
shift $(expr $OPTIND - 1)
```

# getopts

* Funzione standard (**builtin**) per gestire parametri a linea di comando. Esiste in Java, C, Python, etc.
* getopts va sempre utilizzata **abbinata ad un while e un case**
* **La stringa "m:dh" rappresenta i parametri da controllare.** Le lettere singole (e.g., d e h) rappresentano parametri senza argomenti. Le lettere seguite da **:** (e.g., m) rappresentano parametri con argomenti
* **getopts scansiona la linea di comando** e ad ogni ciclo aggiorna la variabile **o** affinchè sia analizzata dal blocco case
* Il blocco case, tipicamente, assegna a delle variabili il valore degli argomenti (**OPTARG**)


# getopts (esempio completo)


```shell
#!/bin/bash                                                      
# Default values                                                 # Additional checks
MESSAGE="Hello World!"                                           # Check if filename exists
DEBUG=FALSE                                                      [ -e "$1" ] || usage
                                           
# Usage function                                                 echo m = "$MESSAGE"
usage() {                                                        echo d = "$DEBUG"
    echo "Usage: $0 [-h] [-m <string>] [-d] filename" 1>&2       echo filename = "$1"
    exit 1
}                                                                exit 0

# In case of optional [] parameters
# default values are overriden
while getopts "m:dh" o; do
    case "$0" in
          m) MESSAGE="$OPTARG"
             ;;
          d) DEBUG=TRUE
             ;;
          h) usage
             ;;
          *) usage
             ;;
    esac
done
# Shift parameters away. $1 becomes filename
shift $(expr $OPTIND - 1) 
```

# Best Practices

# Struttura script

* **Nello sviluppo di script è buona norma (best practice) aderire ad un canovaccio noto e consolidato**
  

* **Definizione interprete**  
	#!/bin/bash
* **Definizione variabili globali**  
	USAGE="usage: $0 dirname"
* **Definizione funzioni**  

* **Controllo parametri**
```shell
	if [ $# -ne 1 ]; then
	  echo "$USAGE"
	  exit 1
	fi
	
	if [ ! -d "$1" -o ! -x "$1" ]; then
	  echo "$USAGE"
	  exit 1
	fi
```

# Struttura script

* **Corpo principale**
```shell      
	F=0; D=0
	for fname in "$1"/*; do
	  if [ -f "$fname" ]; then
	      F=$(expr $F + 1)
	  fi
	  if [ -d "$fname" ]; then
	      D=$(expr $D + 1)
	  fi
	done
	
	echo "#files=$F, #directories=$D"
```
* **Terminazione**  
	exit 0
	
# Struttura script (Best Practices)

* Trattandosi di un linguaggio antico, l'indentazione è ancora facoltativa (in Python, recente, è obbligatoria!). **Indentazione è comunque di fondamentale importanza!**  
* **Variabili globali sono MAIUSCOLE** (ad es. USAGE="$0 usage: ...")  
* **Il controllo dei parametri avviene in via negativa**. Si controllano le condizioni di fallimento e, se verificate, si termina lo script ritornando un codice errore (exit 1). Questa pratica evita indentazione eccessiva  
* **I valori di uscita (exit) utilizzano valori diversi per distinguere successo (exit 0) da fallimento (exit 1).** Per differenziare fra diversi tipi di fallimento si possono utilizzare numeri positivi > 1 (exit 2)  
* I filesystem moderni supportano la presenza di spazi. Per questo motivo, tutte le variabili fuori dal controllo del programmatore (ad es. nomi di file) vanno espanse fra doppie virgolette (echo "$filename") 


# Bash e Python

# Bash vs Python

**BASH**  

* Tradizionale, notissima, installata ovunque  
* Supporto nativo e integrazione profonda con Unix (piping, ridirezione)  
* Avvio quasi istantaneo  

Non usabile su Windows  
Non completamente compatibile con altre shell (csh, zsh, fish)  
Manca supporto per oggetti, strutture dati complesse, ulti-threading  
Mancano tool di debug


# Bash vs Python
 
**PYTHON**  

* Linguaggio ad oggetti general-purpose  
* Portabile. Funziona su tutti i principali OS  
* Sintassi chiara e leggibile, semplice da leggere e da scrivere  
* Ottima gestione degli errori (eccezioni)  
* Tool di debug  

Spesso richiede dipendenze da installare  
Codice generalmente più prolisso


# Esempio(Bash)

```shell
#!/bin/bash

if [ $# -lt 1 ]; then
  echo "usage: $0 f1 .. fn"
  exit 1
fi

l=0
for fname in $*; do
   l=$(wc -l "$fname" | cut -d ' ' -f 1)
   echo "$fname": "$l"
done

exit 0
```

# Esempio(Python)

```shell
#!/usr/bin/env python

import sys
import subprocess

if len(sys.argv) < 2:
   sys.stderr.write("usage: %s f1 .. fn\n" % (sys.argv[0]))
   sys.exit(1)
   
for fname in sys.argv[1:]:
  out  = subprocess.check_output(['wc', '-l', fname])
  print("%s: %s" % (fname, out.split(' ')[0]))
  
sys.exit(0)
```


# Xonsh

* Xonsh is a Python-powered, cross-platform, Unix-gazing shell language and command prompt. The language is a superset of Python 3.5+ with additional shell primitives that you are used to from Bash and Python. It works on all major systems including Linux, Mac OSX, and Windows. Xonsh is meant for the daily use of experts and novices alike.

* https://xon.sh/



