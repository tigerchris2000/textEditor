#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main.h"
#include "file.h"


line_data* readFromFile(const char* location){
    FILE* file = fopen(location, "r");
    if(file == NULL)
    {
        perror("fopen"); 
        exit(EXIT_FAILURE);
    }

    line_data* data = malloc(sizeof(line_data));
    data -> lines = NULL;
    data -> length = 0;
    data -> current = 0;

    if(data == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char* buf = malloc(sizeof(char) * BUFF_SIZE);
    if(buf == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    while(buf = fgets(buf, sizeof(char) * BUFF_SIZE, file))
    {
        char* pos = strstr(buf, "\n");
        pos[0] = 0;
        int l = strlen(buf) + 1;
        char* tmpline = malloc(l*sizeof(char));
        if(tmpline == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        char** tmplines = malloc(sizeof(char) * (data -> length + 2));
        if(tmplines == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < data -> length; i++)
        {
            tmplines[i] = data -> lines[i];
        }
        tmplines[data -> length] = tmpline;
        tmplines[data -> length + 1] = NULL;
        data -> lines = tmplines;
        data -> length++;
    }
    if(ferror(file))
    {
            perror("fread");
            exit(EXIT_FAILURE);
    }

    if(fclose(file) != 0)
    {
        perror("fclose");
        exit(EXIT_FAILURE);
    }
    return data;
}
