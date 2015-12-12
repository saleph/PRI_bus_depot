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
