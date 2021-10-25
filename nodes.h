struct node{
  char name[50];
  char artist[50];
  struct node *next;
};
struct node * insert(struct node *n, char song[50], char singer[50]);
struct node * find_song(struct node *n, char song[50], char singer[50]);
struct node * find_artist(struct node *n, char singer[50]);
struct node * find_random(struct node *n);
int find_random_helper(struct node *n);
struct node * remove_song(struct node *n, char song[50], char singer[50]);
void print_node(struct node *n);
void print_list(struct node *n);
void free_list(struct node *n);
