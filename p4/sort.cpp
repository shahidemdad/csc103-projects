/*
 * CSc103 Project 4: Sorting with lists
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Ash, Adil, Carlos, Mathew cplusplus.com, l4(collected the for loop and other stuff)
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 24 hours
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <string>
using std::string;
#include <vector>
using std::vector;
#include<algorithm>
using std::swap;


/* doubly linked list node: */
struct node {
    string data;
    node* prev;
    node* next;
    node(string s="", node* p=NULL, node* n=NULL) : data(s),prev(p),next(n) {}
};

// functions breakdown:

void sorting(node*& a);
void frontPrint(node* a);
void backPrint(node* a);
void input(node*& a, string b);

//this function is sort out the values:
void sorting(node*& a){ //a=begin
    for (node* i = a; i != NULL; i = i->next){
        for (node* k = a; k != NULL; k = k->next){
            if (k->data > i->data){
                swap(i->data, k->data);
            }
        }
    }
}
//this function setup the new node and update the new node as new inputs come
void input(node*& a, string b){
    a->next = new node;
    a->next->prev = a;
    a = a->next;
    a->data = b;//now the a data the b value
}
//standard printout, collected from l4
void frontPrint(node* a){ //Forward printer, a = start
    for (node* i = a; i != NULL; i = i->next){
        cout << ((*i).data) << endl;
    }
}
//reverse printout, collected from l4
void backPrint(node* a){ //Reverse printer, a = end
    for (node* i = a; i != NULL; i = i->prev){
        cout << ((*i).data) << endl;
    }
}

//main function
int main(int argc, char *argv[]) {
    /* define long options */
    static int unique=0, reverse=0;
    static struct option long_opts[] = {
        {"unique",   no_argument,       &unique,   'u'},
        {"reverse",  no_argument,       &reverse,  'r'},
        {0,0,0,0} // this denotes the end of our options.
    };
    /* process options */
    char c; /* holds an option */
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "ur", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'u':
                unique = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case '?': /* this will catch unknown options. */
                return 1;
        }
    }
    /* NOTE: at this point, variables 'reverse' and 'unique' have been set
	 * according to the command line.  */
	/* TODO: finish writing this.  Maybe use while(getline(cin,line)) or
	 * similar to read all the lines from stdin. */

    //first we create our 3 different nodes
    node* present = NULL; // one for present
    node* begin = NULL; //this my first node
    node* last = NULL; //this is my last node, to keep track for all my nodes
    string words; // for string inputs

    //creating first node and present will link to my first node
    if (getline(cin,words)){
        present = new node;
        present->data = words;
        begin = present;
    }
    //creating buffer vector to store all my unique data
    vector<string> buffer; // vector is there to remember my nodes
    buffer.push_back(begin->data); // my first node added to my vector
    while(getline(cin,words)){ // while loop to do the keep going
        if (unique){ // it is to check my unify
          bool unify = false; // false means the input will unique
          for(size_t i = 0; i < buffer.size(); i++){//for loop to keep checking my any lastest inputs
              if(buffer[i] == words) { // if the input is already in my words, it will give me true
                  unify = true; // true means it is not unique anymore
              }
          }
          if(!unify){ //if the return is 0 means not unique
              input(present,words);
              buffer.push_back(words); // we ignore the input and move one
          }
        }
        else{
            input(present, words);
        }
    }
    last = present; // this is make sure the reverse works and ensure my end nodes
        sorting(begin); //sorting will help to organize my nodes and update them accordingly

        //if statement is to ensure my words are printing in order
    if (reverse == 1){
        backPrint(last);//for reverse
    }
    else{
        frontPrint(begin);// standard print
    }
    return 0;
}
//end of the code.