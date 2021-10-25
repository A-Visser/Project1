#include <stdio.h>
#include "nodes.h"
#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>



struct node * insert_front(struct node *n, char song[50], char singer[50]){
  struct node *m = malloc(sizeof(struct node));
  strcpy(m -> name, song);
  strcpy(m -> artist, singer);
  m -> next = n;
  return m;
}
struct node * insert_alphabetically_helper(struct node *n, struct node *prev, struct node *og, char song[50], char singer[50]){
  if(!n){
    struct node *m = malloc(sizeof(struct node));
    strcpy(m -> name, song);
    strcpy(m -> artist, singer);
    if(prev) prev -> next = m;
  }
  else if(strcmp(singer, n->artist)< 0 ||(strcmp(singer, n->artist) == 0 && strcmp(song, n->name) <=0)){
    struct node *m = malloc(sizeof(struct node));
    strcpy(m -> name, song);
    strcpy(m -> artist, singer);
    m -> next = n;
    if(prev) prev -> next = m;
    else {
      return m;
    }
  }else{
    insert_alphabetically_helper(n->next, n, og, song, singer);
  }
  return og;
}
struct node * insert(struct node *n, char song[50], char singer[50]){
  if(!n)return insert_front(n, song, singer);
  return insert_alphabetically_helper(n, NULL, n, song, singer);
}
struct node * find_song(struct node *n, char song[50], char singer[50]){
  while(n){
    if(strcmp(n->name, song)== 0 && strcmp(n-> artist, singer) == 0){
      return n;
    }
    n = n->next;
  }
  return NULL;
}
struct node * find_artist(struct node *n, char singer[50]){
  if (strcmp(n-> artist, singer) != 0){
    if(!(n->next)){
      return NULL;
    }
    find_artist(n->next, singer);
  }
  return n;
}
struct node * find_random(struct node *n){
  struct node * i = n;
  int tracker = 0;
  int counter = find_random_helper(n);
  int r = rand()% counter;
  while(n){
    if(tracker == r){
      return n;
    }
    tracker ++;
    n = n->next;
  }
  return NULL;
}
int find_random_helper(struct node *n){
  int counter = 0;
  while(n){
    counter ++;
    n = n->next;
  }
  return counter;
}
struct node * remove_song(struct node *n, char song[50], char singer[50]){

  if(strcmp(n->name, song) == 0 && strcmp(n->artist, singer) == 0){
    struct node *temp = n->next;
    n->next = NULL;
    free(n);
    return temp;
  }
  struct node * og = n;
  while(n->next){
    if(strcmp((n->next)->name, song) == 0 && strcmp((n->next)->artist, singer) == 0){
      struct node * temp = n->next;
      n->next = n->next->next;
      temp -> next = NULL;
      free(temp);
      return og;
    }
    n = n->next;
  }
  return og;
}
void print_node(struct node *n){
  if (!n){
    printf("Artist Not Found");
  } else {
    printf("{%s, %s}", n->artist, n->name);
  }
}
void print_list(struct node *n){
  if(n){
    printf("{%s, %s}", n->artist, n->name);
    if(n->next){
      printf(" | ");
      print_list(n->next);
    }
    printf(" \n");
}
}

struct node * free_list(struct node *n){
  if(n->next != NULL){
    free_list(n->next);
  }
  free(n);
  return n;
}
