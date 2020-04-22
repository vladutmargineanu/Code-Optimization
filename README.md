# Code-Optimization
Homework for the Computing Systems Architecture course @ ACS, UPB 2020

Tema 2
Deadline soft: 22 aprilie 2020, ora 23:55. Primiți un bonus de 10% din punctajul obtinut pentru trimiterea temei înainte de 22 aprilie 2020, ora 23:55.
Deadline hard: 29 aprilie 2020, ora 23:55. Veți primi o depunctare de 10% din punctajul maxim al temei pentru fiecare zi de întârziere, până la maxim 7 zile, adică până pe 29 aprilie 2020, ora 23:55.
Enunț
Se dă următoarea operație cu matrice:

C=B×At+A2×B
unde:

A si B sunt matrice patratice de double de dimensiune N x N
A este o matrice superior triunghiulara
At este transpusa lui A
× este operația de înmulțire
+ este operatia de adunare
A2 este A ridicat la patrat
Se dorește implementarea operației de mai sus in C/C++ în 5 moduri:

blas - o variantă care folosește una sau mai multe functii din BLAS Atlas pentru realizarea operatiilor de inmultire de matrice. Adunarea matricelor poate fi facuta “de mana”. Aceasta implementare va tine cont de faptul ca A este o matrice superior triunghiulara.
neopt - o variantă “de mână” fără îmbunătățiri. Aceasta implementare va tine cont de faptul ca A este o matrice superior triunghiulara.
opt_m - o variantă îmbunătățită a versiunii neopt. Îmbunătățirea are în vedere exclusiv modificarea codului pentru a obține performanțe mai bune.
opt_f - o variantă îmbunătățită obținută prin compilarea codului de la varianta neopt cu flag-ul -O3
opt_f_extra - o variantă îmbunătățită obținută prin compilarea codului de la varianta neopt cu flag-ul -O3 si alte flag-uri de optimizare specifice. Se vor avea in vedere flag-uri care actioneaza asupra unei singure optimizari, nu flag-uri care actioneaza asupra unui grup de optimizari.
Rulare și testare
Pentru testarea temei vă este oferit un schelet de cod pe care trebuie să-l completați cu implementarile pentru cele 4 variante menționate mai sus. Scheletul de cod este structurat astfel:

main.c - conține funcția main, precum și alte funcții folosite pentru citirea fișierului cu descrierea testelor, scrierea matricei rezultat într-un fișier, generarea datelor de intrare și rularea unui test. Acest fișier va fi suprascris în timpul corectării și nu trebuie modificat.
utils.h - fișier header. Acest fișier va fi suprascris în timpul corectării și nu trebuie modificat.
solver_blas.c - în acest fișier trebuie să adaugați implementarea variantei blas.
solver_neopt.c - în acest fișier trebuie să adaugați implementarea variantei neopt.
solver_opt.c - în acest fișier trebuie să adaugați implementarea variantei opt_m.
Makefile - Makefile folosit la compilarea cu gcc.
input - fișierul de input care contine 3 teste pentru urmatoarele valori ale lui N: 400, 800, 1200
compare.c - utilitar ce poate fi folosit pentru a compara doua fisiere rezultat. Acest fișier va fi suprascris în timpul corectării și nu trebuie modificat.
Puteți aduce orice modificare scheletului de cod exceptând cele 3 fișiere menționate mai sus.
În urma rulării comenzii make cu oricare din cele 2 Makefile-uri vor rezulta 5 fișere binare, tema2_blas, tema2_neopt, tema2_opt_m, tema2_opt_f si tema2_opt_f_extra corespunzătoare celor 5 variante care trebuie implementate.

Rularea se va realiza astfel:
./tema2_<mod> input 
unde:

mod este unul din modurile blas, neopt, opt_m, opt_f sau opt_f_extra.
input este fișierul ce contine descrierea testelor.
Fișierul input este structurat astfel:

pe prima linie numărul de teste.
pe următoarele linii descrierea fiecarui test:
valoarea lui N.
seed-ul folosit la generarea datelor.
calea către fișierul de ieșire ce conține matricea rezultat.
Rularea se va face pe coada ibm-nehalem.q. Compilarea se va face folosind gcc-5.4.0 din modulul compilers/gnu-5.4.0. Pentru a incarca modulul pentru GCC trebuie sa dati pe una din masinile din coada ibm-nehalem.q urmatoarea comanda:

 module load compilers/gnu-5.4.0 
Pentru variantele blas, neopt si opt_m nu vor fi utilizate flag-uri de optimizare pentru compilare (va fi utilizat -O0). Pentru linkarea cu BLAS Atlas se va folosi versiunea single-threaded libsatlas.so.3.10 de pe masinile din coada ibm-nehalem.q disponibile in directorul

/usr/lib64/atlas
Fișierele output referință le găsiți aici:

 /export/asc/tema2/
Punctaj
Punctajul este impărțit astfel:

15p pentru implementarea variantei blas dintre care:
12p daca implementarea obtine rezultate corecte
3p pentru descrierea implementarii in README
15p pentru implementarea variantei neopt dintre care:
12p daca implementarea obtine rezultate corecte
3p pentru descrierea implementarii in README
20p pentru implementarea variantei opt_m dintre care:
15p daca implementarea obtine rezultate corecte si timpul de calcul este cu cel putin 30% mai mic decat cel al variantei neopt pentru testul cu N = 1200
5p pentru descrierea implementarii in README
20p pentru implementarea variantei opt_f_extra dintre care:
10p daca implementarea obtine rezultate corecte si timpul de calcul este cu cel putin 5% mai mic decat cel al variantei opt_f pentru testul cu N = 1200
10p pentru explicatii legate de alegerea flag-urilor si impactul flag-urilor asupra performantei
30p pentru o analiza comparativa a performantei pentru cele 5 variante:
15p pentru realizarea unor grafice relevante bazate pe rularea a cel putin 5 teste (5 valori diferite ale lui N: adica inca cel putin doua valori diferite de 400, 800 si 1200 pentru N)
15p pentru explicatii oferite in README
(Bonus)
20p daca timpul de calcul al variantei opt_m pentru testul cu N = 1200 este cel mult 4 secunde sau
10p daca timpul de calcul al variantei opt_m pentru testul cu N = 1200 este intre 4 si 8 secunde
Bonusurile se calculeaza doar pe coada ibm-nehalem.q
Pentru a fi luată în considerare la punctaj, implementarea trebuie să producă rezultate corecte pe cele 3 teste din fisierul input.
Precizări și recomandări
Timpul maxim pentru rularea celor 3 teste folosind oricare din cele 5 variante este de 2 minute. Această limită de timp se referă la rularea întregului program, nu doar la partea intensiv computațională.
Pentru a simplifica implementarea puteți presupune că N este multiplu de 40 și că este mai mic sau egal cu 1600.
În compararea rezultatelor se va permite o eroare absolută de maxim 10−3.
În cazul variantei opt_m complexitatea trebuie să fie aceeași cu cea din varianta neopt.
Formatul arhivei trebuie să fie zip.
Pentru a vedea ce optimizari sunt prezente in fiecare nivel de optimizare puteti folosi comanda:

 gcc -Q -Olevel --help=optimizers 
Pentru a evita aglomerarea cozii se recomanda rularea de teste pentru valori ale lui N mai mici sau egale cu 1600.
Se recomandă ștergerea fișierelor coredump în cazul rulărilor care se termină cu eroare pentru a evita problemele cu spațiul de stocare.
În cazul în care job-urile vă rămân “agățate”, va recomandam să utilizați de pe fep.grid.pub.ro, comanda
 qstat 
pentru a vedea câte job-uri aveți pornite, și apoi să utilizați comanda

qdel -f <id-sesiune> 
unde <id-sesiune> sunt primele cifre din stânga, rezultate după comanda qstat.

Sesiunile interactive deschise prin qlogin nu sunt permise pe coada ibm-nehalem.q. Va trebui sa utilizati qsub pentru a folosi aceasta coada.
