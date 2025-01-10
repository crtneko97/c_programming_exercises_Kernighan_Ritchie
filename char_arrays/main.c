#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);   
void copy(char to[], char from[]);       
void reverse(char str[]);


/* print the longest input line */
int main() 
{  
    int len;     /* current line length */
    int max;     /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }
        if (max > 0)
        {
            //reverse(longest);
        printf("%s", longest);
        }
    }

    return 0;  
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) 
{
    int i = 0;
    while ((to[i] = from[i]) != '\0')  
        ++i;
}

/* reverse: reverse the given string*/
void reverse(char str[])
{
    int start = 0; // points to the beginning of the string
    int end = 0; // points to the end of the string

    while(str[end] != '\0'){ // find the length of the string manually
        ++end; // move end pointer to the last char
    }
    --end; // Adjust to the last valid index (since it was pointing to '\0')

    char temp; // temp variable

    while(start < end){ // swap characters from both ends of the string
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}



