/*
* IF ABSOLUTE MATCH IS NOT FOUND, CORE IS SEARCHED USING THIS
* FUNCTION
*
*
*
*
*
*
*
*
*/

#include "wordExifFunc.h"

//fortonei olo to arxeio se ena pinaka kai ton diabazei anapoda 
//roi kanones gia ta prothemata menontai na ulopoihthoun
int main(int argc, char** argv){

    if(argc != 2){
        printf("too few arguments\n");
        exit(0);
    }

    FILE* f1 = fopen ("wordDatabaseFinal/ wordSyllabusGr2.txt", "r");
    if(!f1){ printf("ERROR f1"); exit(1); }

    int     type;
    char    *len, *syllen;
    char    *word, *syllabes, *syllabesEditable;
    char    *wordWithoutEnding;
    char    *buffer = calloc(255*33636,sizeof(char*));
    char    **wholeFile;
    
    int jk = 0;
    wholeFile = calloc(255*33636,sizeof(char));

    while (fgets(buffer,255, f1)!= NULL)    { 
        if(wholeFile[jk] == NULL){
            wholeFile[jk] = calloc(255 * strlen(buffer)+1, sizeof(char));
            strcpy(wholeFile[jk], buffer);
        }else{
          printf("error\n");
          return 1;
        }
        jk++;

    };

    fclose(f1);

    jk--;
    int reader = jk;

    while (reader > 0)    {

      strcpy(buffer, wholeFile[reader]);

      len         = strtok(buffer,    "|");
      word        = strtok(NULL,      "|");
      syllen      = strtok(NULL,      "|");
      syllabes    = strtok(NULL,      "|");
      type        = toInt(strtok(NULL,      "|"));

      if( strcmp(word, argv[1]) == 0 ){
        printf("\n[");
        printf(UNDER "database" DEUNDER);
        printf("]: ");
        // goes to array finds type
        // calls the type defined
        // function and executes it
        functionPrinter[type](wholeFile[reader]);

        return 0;

      } 

      reader--;

    }

    reader = jk;

    while (reader > 0)    { 

        strcpy(buffer, wholeFile[reader]);

        len         = strtok(buffer,    "|");
        word        = strtok(NULL,      "|");
        syllen      = strtok(NULL,      "|");
        syllabes    = strtok(NULL,      "|");
        type        = toInt(strtok(NULL,      "|"));
        
        syllabesEditable = calloc(strlen(syllabes),sizeof(char));     strcpy(syllabesEditable, syllabes);  
        wordWithoutEnding = calloc(255 * strlen(word),sizeof(char));
        strcpy(wordWithoutEnding, strtok(syllabesEditable, "-")); 
  
        for(int i = 2; i < toInt(syllen); i++){ // kano int = 2 etsi oste h teleutaia sullabi na min antigrafei
            strcat(wordWithoutEnding,strtok(NULL, "-")); 
        }

        // printf("\n>len = %s\n", len);
        // printf("word = %s\n", word);
        // printf("syllen = %s\n", syllen);
        // printf("syllabes = %s\n", syllabes);
        // printf("type = %d\n", type);
        // printf("wordWithoutEnding = %s\n", wordWithoutEnding);
        // printf("syllabesEditable = %s\n", syllabesEditable);

        if( strncmp(wordWithoutEnding, argv[1], strlen(wordWithoutEnding)) == 0 ){
            printf("\nΗ λέξη ");
            printf(UNDER "%s" DEUNDER, argv[1]);
            printf(" δεν βρέθηκε στη βάση,\nαλλά ο πυρήνας της είναι ");
            printf(UNDER "%s" DEUNDER, wordWithoutEnding);
            printf(".\n");

            return 0;

        }   
            
        reader--;

    }

    printf("No core for word \"%s\" was found in Database.\n", argv[1]);
    return 0;

}