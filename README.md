# Zadanie 3.07
Aplikacja obsługująca zajezdnie autobusowe - przechowuje informacje na temat autobusów, zajezdni oraz relacji pomiędzy nimi.

## Warstwa algorytmiczna
### Wykorzystane struktury
#### Lista
Cały program bazuje na uniwersalnej, dwukierunkowej liście. Każdy jej węzeł przechowuje dowolny wskaźnik na miejsce w pamięci. Elementy w liście są unikalne i posortowane (względem podawanych przy dodawaniu elementów funkcji porównujących).

```c
typedef struct List {
    unsigned int length;
    ListNode *head;
    ListNode *tail;
} List;

typedef struct ListNode {
    void *object;
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;
```

Funkcje, które bezpośrednio na niej operują (w celu zachowania całkowitej uniwersalności), przyjmują jako argumenty wywołania wskaźniki na inne funkcje o określonych zadaniach (np. funkcja wyłuskująca z `ListNode` wskaźnik na zajezdnię czy funkca porównująca numery boczne autobusów)

#### Autobus
Dane o konkretnym autobusie znajdują się w pojedyńczej, statycznej strukturze. Pole numeru bocznego jest także wyróżnikiem każdego z autobusów (w jednej liście nie mogą pojawić się 2 takie same numery boczne). W polu `memberships` znajduje się lista zawierająca wskaźniki na zajezdnie, do których należy dany autobus.

```c
typedef struct Bus {
    int side_no;
    int line_no;
    char driver_name[64];
    char driver_pesel[12];
    List memberships;
} Bus;
```

#### Zajeznia
Kolejna statyczna struktura, która w pełni opisuje pojedyńczą zajeznię. Nazwa zajezni jest jej wyróżnikiem - musi być unikalna. Lista `members` zawiera wskaźniki na autobusy, które przynależą do danej zajezdni.

```c
typedef struct Depot {
    char name[64];
    List members;
} Depot;
```

### Sposób realizacji wymagań dot. operacji na danych
#### Dodawanie, modyfikacja i usuwanie
Wszystkie dane są przechowywane w najmniejszej możliwej ilości egzemplarzy. Dodawanie nowych rekordów opiera się na pojedyńczym zaalokowaniu miejsca dla dodawanej struktury, a następnie zaalokowaniu miejsca na sam węzeł listy. Dany rekord zostaje w pamięci, a wskaźnik do niego jest cały czas dostępny. Przy modyfikacji pól, które są kluczami (numer boczny, nazwa zajezdni) następuje automatyczne przesortowanie listy tak, aby zachować w niej porządek rosnący. Podczas usuwania rekordu zostają także usunięte wszelkie do niego dowiązania, a sama pamięć od razu zwalniana.

#### Zarządzanie przypisaniami
Każdy autobus i zajeznia zawiera w sobie listę ze wskaźnikami przypisań (np. każdy autobus posiada w liście wskaźniki na zajezdnie, do których zależy). Dodanie nowego dowiązania ogranicza się do dodania wskaźnika na konkretną strukturę do odpowiedniej listy zależności. Wszelkie mechanizmy list są dokładnie takie same, jak przy każdej innej strukturze. Różnicą są jedynie małe funkcje, które determinują inne zachowania tych niskopoziomowych działań (np. funkcja `del_node_only()` nie robi absolutnie nic. Ale dzięki temu przy usuwaniu referencji nie zostanie usunięty konkretny reprezentant struktury).

#### Filtrowanie
Filtrowanie bazuje na niskopoziomomwej funcji `find_occurrences(List*, void*, void *(ListNode*), int (const void*, const void*))`, która zwraca zmienną `List` (czyli de facto wskaźnik na koniec i początek listy oraz jej długość). Przeszukuje ona listę podaną jako pierwszy argument według kryterium z drugiego parametru. Oczekuje także funkcji wyłuskującej (np. `get_side_no(ListNode*)`) oraz funkcji porównującej (np. `side_no_cmp(void*, void*)`). Następnie, jeśli obiekt z danego węzła listy z argumentu spełnia podane kryteria, wskaźnik na niego zostaje dołączony do statycznej listy wewnątrz funkcji. Po iteracji na całej liście wejściowej, lista z elementami spełniającymi kryterium zostaje zwrócona.

#### Zapis danych do pliku
Dane mogą zostać zapisane i odczytane z/do pliku `Dane.txt`. Funkcja przeprowadzająca zrzut bazy danych (list z autobusami i zajezdniami) dołącza także kilka komentarzy do teogoż pliku (które zostaną później pominięte przy parsowaniu). Wszystkie dane zostają zapisane bez jakiejkolwiek redundancji. Po pierwsze - zostają zapisane same własności autobusów (numery boczne, imię kierowcy etc.). Następnie zapisane zostają zajezdnie wraz z przypisanymi do nich autobusami. Przy parsowaniu i konstrukcji bazy danych z pliku dowiązania te zostają automatycznie wykonane w obydwie strony (czyli każdy autobus będzie także zawierał informację o tym, że jest przypisany do konkretnej zajezdni).

### Testy
Kod projektu zawiera pliki `tests`, w których zawarte zostały bardzo prymitywne testy wszystkich funkcjonalności używanych w programie. Ich wykonanie nie wymaga ingerencji użytkownika, więc w naturalny sposób były bardzo pomocne przy testowaniu programu narzędziem do kontroli wycieków pamięci ([VALGRIND](http://valgrind.org/)). Program nie posiada jakichkolwiek miejsc, w których mogłoby dojść do wycieku pamięci albo nieautoryzowanego odwołania się do komórek spoza sterty.
