#include <stdio.h>
#include "nodes.h"
#include "library.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node * make_node(char song[50], char artist[50]){
  struct node * new_node = malloc(sizeof(struct node));
  strncpy(new_node -> name, song, sizeof(new_node->name));
  strncpy(new_node -> artist, artist, sizeof(new_node->artist));
  new_node -> next =  NULL;
  return new_node;
}


struct node * insert(struct node *n, char song[50], char singer[50]){
  struct node * new_node = make_node(song, singer);
  if (!n) {
    return new_node;
  }
  struct node * original = n;
  struct node * prev = NULL;
  while(n){
    if (strcmp(singer, n->artist)< 0 ||(strcmp(singer, n->artist) == 0 && strcmp(song, n->name) <=0)){
      new_node -> next = n;
      if (prev){
        prev -> next = new_node;
        return original;
      } else {
        return new_node;
      }
    } else {
      prev = n;
      n = n -> next;
    }
  }
  return original;
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
  while(n){
    printf("{%s, %s} ", n->artist, n->name);
    if(n->next){
      printf(" | ");
    }
    n = n-> next;
  }
  printf("\n");
}

void free_list(struct node *n){
  struct node * og = n;
  while(n){
    struct node * temp = n;
    n = n->next;
    free(temp);
  }
}
