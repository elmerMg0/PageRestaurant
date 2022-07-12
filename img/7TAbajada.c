#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>
#define MAXLEN 1024

// Separar: separa datos del formulario

int callback(void *, int, char **, char **);

void separar(char *cadena, char *linea, char separador)
{
    int x, y;
    
    x = 0; y = 0;
    
    while ((linea[x]) && (linea[x] != separador))
    {
	cadena[x] = linea[x];
	x = x + 1;
    }
    cadena[x] = '\0';
    if (linea[x]) ++x;
    
    y = 0;
    
    while (linea[y] = linea[x])
    {
	linea[y] = linea[x];
	y++;
	x++;
    }

}
void consulta(char *datoI, char *datoF,char *fecha){

    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("/root/sqlite/logFTP.db", &db);



    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

       // return 1;
    }
    char query[200];
printf("<p> hola desde consulta");
    sprintf(query, "select count(archivo) from log where accion='DOWNLOAD:' and hora>='%s' and hora<='%s' and fecha='%s'",datoI,datoF,fecha);


    rc = sqlite3_exec(db, query, callback, NULL, NULL);

    if (rc != SQLITE_OK ) {

        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

       // return 1;
    }

    sqlite3_close(db);
    printf("<p> consulta cerrada");
  // return 0;



}

int callback(void *NotUsed, int argc, char **argv, char **azColName) {

	printf("<p> desde callback");
   (void) NotUsed;// = 0;

    //FILE *fichero;
    //fichero = fopen("archivo.txt", "w+b");

    for (int i = 0; i < argc; i++) {

      // printf("%s = %s   ", azColName[i], argv[i] ? argv[i] : "NULL");
      //printf("%s  %s ", argv[i] ? argv[i] :"NULL");

       printf("<p> requerimienti 7: %s",argv[i]);
       //fprintf(fichero,"%s",argv[i]);
      //fwrite(argv[i],5,i,achu);
      //fwrite(argv[i], 20,sizeof(argv), achu);
      //fputs(argv[i],achu);
      // fwrite(argv[i],53, sizeof(argv), fichero );

         }



       // fclose(fichero);
        printf("\n");

return 0;

}

int main(void)
{
    char *lenstr;
    char inputBuffer[MAXLEN];
    int contentLength;
    int i;
    char x;
    char mensaje[80];
    char usuario[80];

   /* int Uid, Gid ; //var. para almacenar el ID de usuario y grupo
        Uid = getuid();
        Gid = getgid();
        if((setuid(0))<0) printf("\n<br>setuid: operacion no permitida\n");
        if((setgid(0))<0) printf("\n<br>setgid: operacion no permitida\n");
    */

    printf ("Content-type:text/html\n\n");
    printf("<br>");
    printf("<TITLE>7requerimiento</TITLE>\n");
    lenstr = getenv("CONTENT_LENGTH");
    printf("<body>");
    printf("<p> hola");
    //lenstr = (char *)getenv("CONTENT_LENGTH");
    if (lenstr!= NULL)
    {
	contentLength = atoi(lenstr);   
    }
    else contentLength = 0;

    if (contentLength > sizeof(inputBuffer)-1)
	contentLength = sizeof(inputBuffer)-1;

    i = 0;

    while (i < contentLength){

	x = fgetc(stdin);
	if (x==EOF) break;
	inputBuffer[i] = x;
	i++;
    }

    inputBuffer[i] = '\0';
    contentLength = i;

    //printf("<br>Datos Formulario: %s\n", inputBuffer);
   // printf("<br>Tama&ntildeo: %d\n",contentLength);

    separar(mensaje, inputBuffer, '=');
    separar(mensaje, inputBuffer, '&');
    separar(usuario, inputBuffer, '=');
    separar(usuario, inputBuffer, '&');
    
   // printf("<p> Mensaje: %s",mensaje);
   // printf("<p> Usuario: %s",usuario);

     char *m="22:01:10";
     char *n="22:34:00";
     char *o="2022-11-25";
   
     consulta(m,n,o);
  
      printf("</body>");
   return 0;
}/*  
void consulta(char *datoI, char *datoF,char *fecha){

    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("/root/sqlite/logFTP.db", &db);



    if (rc != SQLITE_OK) {

        fprintf(stderr, "Cannot open database: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

       // return 1;
    }
    char query[200];

    sprintf(query, "select count(archivo) from log where accion='DOWNLOAD:' and hora>='%s' and hora<='%s' and fecha='%s'",datoI,datoF,fecha);
    

    rc = sqlite3_exec(db, query, callback, NULL, NULL);

    if (rc != SQLITE_OK ) {

        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);

        sqlite3_free(err_msg);
        sqlite3_close(db);

       // return 1;
    }

    sqlite3_close(db);
  // return 0;



}
int callback(void *NotUsed, int argc, char **argv, char **azColName) {

   (void) NotUsed;// = 0;
    
    //FILE *fichero;
    //fichero = fopen("archivo.txt", "w+b");
     
    for (int i = 0; i < argc; i++) {

      // printf("%s = %s   ", azColName[i], argv[i] ? argv[i] : "NULL");
      //printf("%s  %s ", argv[i] ? argv[i] :"NULL");
      
       printf("<p> requerimienti 7: %s",argv[i]);
       //fprintf(fichero,"%s",argv[i]);
      //fwrite(argv[i],5,i,achu);
      //fwrite(argv[i], 20,sizeof(argv), achu);
      //fputs(argv[i],achu);
      // fwrite(argv[i],53, sizeof(argv), fichero );

    	 }
    
        

       // fclose(fichero);
        printf("\n");
   
return 0;

}*/
