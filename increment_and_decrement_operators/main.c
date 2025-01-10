#include <stdio.h>



/* Exercise 2-4. 
 * Write an alternative version of squeeze(s1,s2)
 * that deletes each character in s1 that matches any
 * character in the string s2.
 * page.43-44
 * */
void squeeze(char s1[], char s2[]);

int main() {
    char name1[] = "simon";
    char name2[] = "isak";

    squeeze(name1, name2);

    printf("name1: %s\nname2:%s", name1, name2);

    return 0;
}
void squeeze(char s1[], char s2[]) {
    int i = 0, j = 0, k, match;

    while (s1[i] != '\0') { 
        match = 0; 
        k = 0;

        while (s2[k] != '\0') {             
            if (s1[i] == s2[k]) {
                match = 1; 
                break;
            }
            k++;
        }

        if (!match) {
            s1[j++] = s1[i]; 
        }
        i++;
    }

    s1[j] = '\0'; 
}

/*void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int match;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = 0; // assume no match
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = 1; // found a match
                break;
            }
        }
        if (!match) {
            s1[j++] = s1[i]; // copy if no match
        }
    }
    s1[j] = '\0'; // null-terminate the result
}
*/

