#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "library.h"
#include <time.h>
void testNodes(){
    printf("LINKED LIST TESTS");
    struct node * n = NULL;
    printf("\n============================================================\n\n");

    printf("TESTING INSERT_FRONT AND PRINT_LIST \n");
    printf("n = insert_front(n, Yesterday, Beatles)\n");
    n = insert(n, "Yesterday", "Beatles");
    print_list(n);
    printf("n = insert_front(n, Bohemian Rhapsody, Queen)\n");
    n = insert(n, "Bohemian Rhapsody", "Queen");
    print_list(n);
    printf("==============================================================\n\n");
    n = NULL;
    printf("TESTING INSERT_ALPHABETICALLY\n");
    printf("n = insert(n, \"Easy On Me\", \"Adele\")\n");
    n = insert(n, "Easy On Me", "Adele");
    printf("n = insert(n, \"Duel of the Fates\", \"John Williams\")\n");
    n = insert(n, "Duel of the Fates", "John Williams");
    printf("n = insert(n, \"Middle Child\", \"Jay Cole\")\n");
    n = insert(n, "Middle Child", "Jay Cole");
    printf("n = insert(n, \"Country Road\", \"John Denver\")\n");
    n = insert(n, "Country Road", "John Denver");
    printf("n = insert(n, \"Motion Sickness\", \"Phoebe Bridgers\")\n");
    n = insert(n, "Motion Sickness", "Phoebe Bridgers");
    printf("n = insert(n, \"Let It Be\", \"Beatles\")\n");
    n = insert(n, "Let It Be", "Beatles");
    print_list(n);
    printf("==============================================================\n\n");

    printf("TESTING FIND_SONG, FIND_ARTIST, AND FIND_RANDOM\n");
    printf("find_song(n, \"Motion Sickness\", \"Phoebe Bridgers\"): \n");
    print_node(find_song(n, "Motion Sickness", "Phoebe Bridgers"));
    printf("\n");
    printf("find_song(n, \"Hello\", \"Adele\"): ");
    print_node(find_song(n, "Hello", "Adele"));
    printf("\n");
    printf("find_artist(n, Adele): ");
    print_node(find_artist(n, "Adele"));
    printf("\n");
    printf("find_random(n): ");
    print_node(find_random(n));
    printf("\n");
    printf("==============================================================\n\n");

    printf("TESTING REMOVE_SONG AND FREE_LIST\n");
    printf("n: ");
    print_list(n);
    printf("n = remove_song(n, \"Motion Sickness\", \"Phoebe Bridgers\")\n");
    print_list(remove_song(n, "Motion Sickness", "Phoebe Bridgers"));
    printf("\n");
    printf("Free List(n)");
    free_list(n);
    printf("==============================================================\n\n");
}
void testLibrary(){
  printf("LIBRARY TESTS");
  printf("\n============================================================\n\n");
  printf("Testing make_library\n");
  printf("struct node ** library = make_library()\n");
  struct node ** library = make_library();
  printf("Let's add some songs! \n");
  add_node(library, "God's Plan", "Drake");
  add_node(library, "Duel of the Fates", "John Williams");
  add_node(library, "Let it Be", "The Beatles");
  add_node(library, "Yesterday", "The Beatles");
  add_node(library, "Middle Child", "Jay Cole");
  add_node(library, "Trophies", "Drake");
  add_node(library, "Country Road", "John Denver");
  print_library(library);
  printf("Find song: God's Plan: \n");
  printf("Find song, God's Plan: %p \n", song_search(library, "God's Plan", "Drake"));
  print_node(song_search(library, "God's Plan", "Drake"));
  printf("\n");
  printf("Find artist: John Denver: \n");
  printf("Find artist, John Denver: %p \n", artist_search(library, "John Denver"));
  print_node(artist_search(library, "John Denver"));
  printf("\n");
  printf("Print artist: Drake\n");
  print_artist(library, "Drake");
  printf("\n");
  printf("Print letter: J \n");
  print_letter(library, 'J');

  printf("\n");
  printf("\n============================================================\n\n");
  printf("Let's test shuffle!\n");
  printf("Shuffle for 2 songs: \n");

  shuffle(library, 2);
  printf("Shuffle three songs: \n");

  shuffle(library, 3);
  printf("Delete songs: \n");
  printf("remove_song1(library, \"God's Plan\", \"Drake\")\n");
  remove_song1(library, "God's Plan", "Drake");
  print_library(library);
  printf("\n FREE LIBRARY!\n");
  printf("clear_out\n");
  clear_out(library);
}
int main(){
  srand(time(NULL));
  testNodes();
  testLibrary();
  return 0;
}
