/* check test.php for comparable notes - the logic should be exactly the same between the two */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TRUE 1
#define FALSE 0


char * check_request_var(char * var, int check_isset, int * isset)
{
    char * query_string = getenv("QUERY_STRING");
    char * query = NULL;
    char * save_pair = NULL;
    char * save_key = NULL;
    char * pair = NULL;
    char * key = NULL;
    char * value = NULL;

    if (query_string == NULL) {
        return NULL;
    }

    query = strdup(query_string);

    pair = strtok_r(query, "&", &save_pair);
    while (pair != NULL) {
        key = strtok_r(pair, "=", &save_key);

        if (key == NULL || !strcmp(key, "")) {
            break;
        }

        if (!strcmp(var, key)) {

            /* if we are just checking to see if var is set, then
               we can set the pointer to isset properly and return */
            if (check_isset == TRUE && isset != NULL) {
                *isset = TRUE;
                free(query);
                return NULL;
            }

            value = strtok_r(NULL, "=", &save_key);

            if (value == NULL || !strcmp(value, "")) {
                free(query);
                return NULL;
            }

            free(query);
            return strdup(value);
        }

        pair = strtok_r(NULL, "&", &save_pair);
    }

    free(query);
    return NULL;
}


char * get_request_var(char * var)
{
    return check_request_var(var, FALSE, NULL);
}


int request_var_isset(char * var)
{
    int isset = FALSE;
    char * check = check_request_var(var, TRUE, &isset);
    return isset;
}


int main(int argc, char const *argv[])
{
    unsigned int count = 1000000000;
    unsigned int i, j, k;
    int print_count = 0;

    char * get_count = get_request_var("count");
    if (get_count != NULL) {
        count = strtoul(get_count, NULL, 10);
        free(get_count);
    }

    /* we have to print our own http headers in cgi */
    printf("%s\r\n\r\n", "Content-type: text/html; charset=utf-8");

    printf("%s", "<!doctype html><html><head><title>test</title></head><body><pre>\n\n");
    printf("%u\n", count);

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            for (k = 0; k < count; k++) {

                print_count++;

                if (request_var_isset("print")) {
                    printf("%c", '.');

                    if (print_count >= 96) {
                        printf("%s", "\n");
                        print_count = 0;
                    }
                }
            }
        }
    }

    printf("%s", "\n\n</pre></html>\n");
    return 0;
}
