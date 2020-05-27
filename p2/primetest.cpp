/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

      int n=0; // input an interger
      int d;
      bool ans= true;
      // number will divide by
      cout << "enter a number: \n"; // asking for an number

    while (cin >> n) { // inputing number

      for (d=2; d<n ; d++) {
        if (n%d==0) {
          //cout << "for loop, in if\n";
          ans = false;
          break;
        }
        else{
          //cout << "for loop, in else\n";
          ans = true;
        }
       }
      if ( ans == true && n>1) {
          cout << "1\n";
      }
      else {
        cout << "0\n";
      }
    }
return 0;
}