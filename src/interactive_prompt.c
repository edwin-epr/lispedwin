#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <editline/readline.h>
#include <editline/history.h>

int main(int argc, char const *argv[])
{
    /* Print Version and Exit Information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press '/exit' to Exit\n");

    int exit_command;
    int exit_requested;

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt and get input */
        char *input = readline("lispmath|> ");

        /* Add input to history */
        add_history(input);

        /* Exit condition */
        exit_command = strcmp(input, "/exit");
        exit_requested = exit_command == 0;
        if (exit_requested)
        {
            free(input);
            puts("See you soon!");
            return 0;
        }

        /* Echo input back to user */
        printf("  %s\n", input);

        /* Free retrieved input */
        free(input);
    }

    return 0;
}
