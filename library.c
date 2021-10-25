#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "nodes.h"
#include <time.h>

struct node ** make_library(){
  struct node ** library = (struct node **)calloc(27,sizeof(struct node *));
  return library;
}

void add_node(struct node ** library, char name[50], char artist[50]){
    library[artist[0]-'A'] = insert(library[artist[0]-'A'], name, artist);
}

struct node * song_search(struct node ** library, char name[50], char artist[50]){
  if(!(library[artist[0]-'A']))return NULL;
  return find_song(library[artist[0]-'A'], name, artist);
}

struct node * artist_search(struct node ** library, char artist[50]){
  if(!(library[artist[0]-'A']))return NULL;
  return find_artist(library[artist[0]-'A'], artist);
}

void print_letter(struct node ** library, char c){
  if(!library[c-'A'])printf("No artists with first letter %c found ", c);
  else{
    printf("%c: ", c);
    print_list(library[c-'A']);
 }
}

void print_library(struct node ** library){
  int i = 0;
  for(i = 0; i < 27; i++){
    if (library[i]){
      print_letter(library, i+'A');
    }
  }
  printf("\n");
}

void print_artist(struct node ** library, char singer[50]){
  if (!(find_artist(library[singer[0]-'A'], singer))) {
    printf("Artist not found");
  } else {
    struct node * n = find_artist(library[singer[0]-'A'], singer);
    printf("{%s, %s} ", n->artist, n->name);
    while(n -> next){
      if(strcmp((n->next)->artist, singer) == 0){
        printf("{%s, %s}", (n->next)->artist, (n->next)->name);
      }
      n = n->next;
    }
  }
}

int get_num_nodes(struct node ** library){
  int i, count;
  count = 0;
  for(i = 0; i < 27; i++){
    struct node * n = library[i];
    while(n){
      count ++;
      n= n->next;
    }
  }
  return count;
}

struct node * get_random_node(struct node **library, int num_nodes){
  int i, count;
  count = 0;
  int r = rand() % num_nodes;
  for(i = 0; i < 27; i++){
    struct node * n = library[i];
    while(n){
      if (count==r){
        return n;
      }
      count ++;
      n = n->next;
    }
  }
  return NULL;
}

int isIn(struct node ** a, struct node * c, int len){
  int i;
  for(int i = 0; i < len; i ++){
    if(a[i]==c){
      return 1;
    }
  }
  return 0;
}

void shuffle(struct node **library, int num){
  struct node * shuffled_songs[num];
  int num_nodes = get_num_nodes(library);
  while(num){
    struct node * n = get_random_node(library, num_nodes);
    int i = 0;
    if(!isIn(shuffled_songs, n, num)){
      shuffled_songs[i] = n;
      i ++;
      printf("{%s, %s}\n", n -> artist, n -> name);
      num --;
    }
  }
}

void remove_song1(struct node ** library, char song[50], char singer[50]){
  int i;
  for(i = 0; i < 27; i++){
    if(library[i]){
      library[i] = remove_song(library[i], song, singer);
    }
  }
}

void clear_out(struct node ** library){
  int i;
  for(i = 0; i < 27; i++){
    free_list(library[i]);
    library[i] = 0;
  }
}
