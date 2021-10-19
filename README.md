# Project1
/* Music Library Overview

    You may work with a partner on this assignment. They must be in the same class period as you.
    Write a program in C that implements a music library organizer.
    This will consist of 2 data structures
        A linked list of songs.
            Your nodes/links should be able to hold a song’s title and artist. You might use structures like the following:

            struct song_node{
            char name[100];
            char artist[100];
            struct song_node *next;
            };

        An array of 27 linked lists (one for each letter from ‘a’ to ‘z’, and another for other symbols).
            Each slot will contain a linked list of all the artists that have names that start with the corresponding letter.
            When you add a song, it should go on to a linked list at the appropriate array slot in the correct position alphabetically. Assume no duplicate songs.

Linked List Part

    You should start by making your linked lists work with the following functionality:
        insert nodes at the front
        insert nodes in order
            alphabetical by Artist then by Song
            you should have a helper function to compare song nodes effectively.
        print the entire list
        find and return a pointer to a node based on artist and song name
        find and return a pointer to the first song of an artist based on artist name
        Return a pointer to random element in the list.
        remove a single specified node from the list
            specified by both artist and song name.
        free the entire list

Library Part

DO NOT WORK ON THIS PART UNTIL YOUR LINKED LIST IS COMPLETE

    Details on this part forthcoming

Putting it all together

    Files you should have:
        A .c file that contains the main function you use to test all your work
            You must test all the functions in your main function in order to receive full credit!!!
    Two sets of .h/.c files
        There are 2 separate structures being worked on, the linked list and the library.
    A makefile that will compile all the parts of your code and generate a single executable program, as well as a run target.
*/
