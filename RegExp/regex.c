#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) 
{
    regex_t regex;
    int result;

    result = regcomp(&regex, argv[1], 0);
    if (result != 0)
    {
        fprintf(stderr, "Could not compile regex\n");
        return 1;
    }
    size_t n = 128;
    char* line = malloc(n);
    while (!feof(stdin))
    {
        getline(&line, &n, stdin);
        result = regexec(&regex, line, 0, NULL, 0);
        if (result == 0)
        {
            printf("%s", line);
        }
        else 
        {
            printf("It does not match the regular expression");
        }
        
    }
    free(line);
    regfree(&regex); 
    return 0;
}

// gcc -o regexc regex.c
// ./regexc 'f\(o*\)'              \( == (


