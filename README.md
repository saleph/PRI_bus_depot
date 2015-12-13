# Zadanie 3.07
Aplikacja obsługująca zajezdnie autobusowe - przechowuje informacje na temat autobusów, zajezdni oraz relacji pomiędzy nimi. Umożliwia także manipulację tymi danymi.

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

## Dokumentacja funkcji
### **list.h**
`int append_to(List* a_list, void* an_object, int (*cmp)(const void*, const void*))`: dodaje obiekt (np. autobus) do listy w odpowiednim miejscu (porównywanie następuje przy pomocy funkcji podanej jako 3 argument). Domyślny porządek jest rosnący, choć może zostać odwrócony przez manipulację na funkcji porównującej.

`int remove_from(List* a_list, void* an_element, void (*rm)(void*))`: usuwa obiekt (np. autobus) z listy. Wymaga także dekonstruktora danej struktury (np. funkcji usuwającej dowiązania do zajezdni oraz samą listę z zależnościami).

`ListNode *find_node_in(List* a_list, void* an_object)`: wyszukuje obiekt (np. zajeznię jako strukturę) w danej liście, a nastepnie zwraca wskaźnik węzła, w którym się on znajduje. Jeśli elementu nie znaleziono - zwraca NULL.

`void *find_object_with_item_in(List* the_list, void* item, void *(*get)(ListNode*), int (*cmp)(void*, void*))`: funkcja zwracająca wskaźnik na strukturę, która zawiera podany element (*item*) we wskazanej liście. Wymaga funkcji wyłuskującej (np. wyłuskanie *side_no* z *ListNode*) oraz funkcji porównującej (np. `side_no_cmp(const void*, const void*)`).

`void delete_list(List* the_list, void (*rm_content)(void*))`: usuwa wszystkie węzły listy wraz z elementami wewnątrz każdego węzła (poprzez funkcję przekazywaną przez wskaźnik).

`void del_node_only(void* the_node_ptr)`: funkcja 'pusta'; podana jako argument np. `remove_from()` nie spowoduje usunięcia obietków wewnątrz węzła (używana np. przy usuwaniu przypisań autobusów do zajezdni).

`List find_occurrences(List* the_list, void* item, void* (*get)(ListNode*), int (*cmp)(const void*, const void*))`: funkcja przeszukująca podaną listę względem zawierania (określanego przy pomocy funkcji `*cmp`) podanego kryterium (`void *item`). Jeśli jakiś element listy spełnia to kryterium, to zostaje dodany do statycznej listy, która potem zostanie zwrócona. Wymaga dodatkowo funkcji wyłuskującej z `ListNode` analogicznego elementu (np. przy filtrowaniu po numerze linii - wymagana jest funkcja `get_line_no(ListNode*)`.

`void for_each_in(List* the_list, void (*do_sth)(void*))`: prymitywna implementacja operatora `for_each`, która wykonuje jakąś operację na elemencie we wszystkich węzłach (używana np. do funkcji wyświetlających zawartość listy albo do usuwania nieistniejących już dowiązań).

### **comparing.h**
`int buses_side_no_cmp(const void *first, const void *second)`: porównuje numery boczne dwóch autobusów.

`int buses_line_no_cmp(const void *first, const void *second)`: porównuje numery linii dwóch autobusów.

`int buses_drivers_names_cmp(const void* first, const void* second)`: porównuje nazwiska kierowców dwóch autobusów.

`int buses_drivers_pesels_cmp(const void* first, const void* second)`: porównuje pesele kierowców dwóch autobusów.

`int depots_names_cmp(const void* first, const void* second)`: porównuje nazwy dwóch zajezdni.

### **extracting.h**
`void *get_side_no(ListNode* the_node)`: wyłuskuje numer boczny z węzła listy.

`void *get_line_no(ListNode* the_node)`: wyłuskuje numer linii z węzła listy.

`void *get_driver_name(ListNode* the_node)`: wyłuskuje nazwisko kierowcy z węzła listy.

`void *get_driver_pesel(ListNode* the_node)`: wyłuskuje pesel kierowcy z węzła listy.

`void *get_depot_name(ListNode* the_node)`: wyłuskuje nazwę zajezdni z węzła listy.

### **bus.h**
`Bus *new_bus(char* side_no, char* line_no, char* name, char* driver_pesel)`: konstruktor nowej instancji struktury. Przy ustawianiu konkretnych wartości następuje od razu ich sprawdzenie, zaś niespełnienie jakiegokolwiek kryterium skutkuje cofnięciem alokacji pamięci.

`int set_side_no(Bus* a_bus, char* side_no)`: ustawia numer boczny po uprzedniej walidacji.

`int set_line_no(Bus* a_bus, char* line_no)`: ustawia numer linii po uprzedniej walidacji.

`int set_driver_name(Bus* a_bus, char* name)`: ustawia nazwisko i imię kierowcy po uprzedniej walidacji.

`int set_driver_pesel(Bus* a_bus, char* driver_pesel)`: ustawia pesel kierowcy po uprzedniej walidacji.

`void print_bus_info(void* the_bus_ptr)`: wyświetla informacje o pojedyńczym autobusie w formie skróconej (bez przypisań).

`void print_bus_info_with_refs(void* the_bus_ptr)`: wyświetla informacje o pojedyńczym autobusie razem z przypisaniami do zajezdni.

`void print_bus_labels()`: wyświetla linię nagłówkową dla listy autobusów.

`void del_bus(void* the_bus_pointer)`: dekonstruktor pojedyńczego autobusu - usuwa listę dowiązań oraz sam autobus (wraz ze zwolnieniem pamięci).

### **depot.h**
`Depot *new_depot(char* a_string)`: alokuje pamięć dla nowej zajezdni, ustawia jej nazwę i zwraca do niej wskaźnik.

`void del_depot(void* the_depot_pointer)`: dekonstruuje zajezdnię - usuwa listę dowiązań i samą zajezdnię.

`int set_depot_name(Depot* a_depot, char* name)`: ustawia nazwę zajezdni uprzednio ją walidując.

`void print_depot_info(void* the_depot_pointer)`: wyświetla informacje o pojedyńczej zajezdni w skróconej formie (bez dowiązań).

`void print_depot_info_with_refs(void* the_depot_pointer)`: wyświetla informacje o pojedyńczej zajezdni razem z przypisanymi autobusami.

### **buses_management.h**
`int add_bus(char* side_no, char* line_no, char* name, char* pesel)`: dodaje autobus o podanych parametrach do listy.

`int remove_bus(Bus* the_bus)`: usuwa wszystkie dowiązania autobusu w zajezdniach, a następnie sam autobus.

`void reappend_bus_memberships(Bus* the_bus)`: usuwa i na nowo tworzy przypisania autobusu we wszystkich zajezdniach. Ma to na celu naprawienie kolejności rekordów po edycji wartości klucza (po edycji numeru bocznego).

### **depots_management.h**
`int add_depot(char* depot_name)`: dodaje zajezdnię o podanej nazwie do listy.

`int remove_depot(Depot* the_depot)`: usuwa zajezdnię wraz z miejscami, gdzie występowała.

`void reappend_depot_assignments(Depot* the_depot)`: usuwa i tworzy na nowo dowiązania zajezdni w przypisanych autobusach. Naprawia ich kolejność (po edycji nazwy zajezdni).

### **membership_management.h**
`void assign_to(char* depot_name, int side_no)`: przypisuje zajezdnię o podanej nazwie do autobusu o podanym numerze bocznym.

`void assign_structs_to(Depot* the_depot, Bus* the_bus)`: analogicznie jak przy powyższej, tylko że wymaga już wskaźników na struktury.

`void remove_assignment_from(char* depot_name, int side_no)`: usuwa przypisanie autobusu o podanym numerze bocznym z zajezdni o podanej nazwie.

`void remove_assignment_structs_from(Depot* the_depot, Bus* the_bus)`: analogicznie jak powyżej, ale wymaga wskaźników na struktury.

`void move_to(char *from_depot_name, int side_no, char *to_depot_name)`: przenosi przypisanie autobusu o podanej nazwie z jednej zajezdni do drugiej.

### **filtering.h**
`void print_filtered_by(enum FilterType filter_type, void* value)`: filtruje dane po konkretnym polu (podane przez enum) wykorzystując podane kryterium *value* i wypisuje je na wyjściu.

### **dumper.h**
`int dump_database_to(const char* filename)`: zapisuje zrzut bazy danych do pliku o nazwie podanej w parametrze oraz tworzy backup poprzednich danych (z poprzedniego zapisu).

### **data_loader.h**
`void load_database_from(const char* filename)`: wczytuje z pliku o podanej nazwie dane i tworzy z nich bazę danych, do której dostęp będzie miał program.

### **cleanup.h**
`void clean_up_mem()`: czyści całą bazę danych usuwając wszystkie zaalokowane wcześniej struktury. Nie pozostawia jakichkolwiek danych w pamięci.

### **tests.h**
`void do_tests()`: wykonuje prymitywne testy wszystkich funkcjonalności programu, wyświetlając stan bazy danych po każdej jej edycji. Aby uruchomić program w trybie debugowania wystarczy zmienić flagę `DEBUG_MODE` w pliku `main.c` na 1.

### **messages.h**
`void msg(enum Message message)`: switch operujący na enumie; zawiera wszystkie komunikaty błędów, które mogą wystąpić w programie.

### **ui_printer.h**
`void prt(enum PrintType prt_type)`: jeden wielki switch operujący na enumie. Zawiera wszystkie komunikaty używane w interfejsie użytkownika.

### **ui.h**
`void start_program()`: procedura odpowiedzialna za obsługę całego programu. Opiera się na jednej pętli zdarzeń, które mogą wywoływać kolejne (pozostałe podmenu, zapis danych etc.). Dba także, aby po jakiejkolwiek edycji danych zapytać użytkownika przed wyjściem, czy chciałby zapisać dane do pliku.
