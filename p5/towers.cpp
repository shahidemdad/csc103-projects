/*
 * CSc103 Project 5: Towers of Hanoi
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: cplusplus, cs tutoring
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:14
 */

// TODO: write the program.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

//functions called out:
void moveCount(int n, short start, short end, short left);

//functions breakdown:
// start is my first line and end is the line where I want to have my all disks and left is my remainning line

void moveCount(int n, short start, short end, short left){ //my function parameter
		if(n == 1){ // if i have only one disks so it will just take to my end line
			cout <<  start << " " << end << endl;
        return;
    }
		if(n > 1) { //if I have more disks then following code
			moveCount(n - 1, start, left, end); // this is first to disk to my 2nd line
			cout <<  start << " " << end << endl;
			moveCount(n - 1, left, end, start); // finally all disks to my last line
		}
}

/* Here's a skeleton main function for processing the arguments. */
int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"start",        required_argument, 0, 's'},
		{"end",          required_argument, 0, 'e'},
		{"num-disks",    required_argument, 0, 'n'},
		{0,0,0,0} // this denotes the end of our options.
	};
	// now process the options:
	char c; // to hold the option
	int opt_index = 0;
	short n=0,start=0,end=0; /* to store inputs to the towers function. */
	while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 's': // process option s
				start = atoi(optarg);
				break;
			case 'e': // process option e
				end = atoi(optarg);
				break;
			case 'n': // process option n
				n = atoi(optarg);
				break;
			case '?': // this will catch unknown options.
				// here is where you would yell at the user.
				// although, getopt will already print an error message.
				return 1;
		}
	}
	/* TODO: now that you have the options and arguments,
	 * solve the puzzle. */
		short left = (6 - (start + end));// no matter what the sum of the 3 rods will be 6(1+2+3) so if I want to find which line is my remainning line, I use this formula to figure out.

    moveCount(n, start, end, left);// function called

	return 0;
}
//end of the code.