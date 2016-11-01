#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


char  mc[][20] = {"PROGRAM", "BEGIN", "END", "IF", "THEN", "WHILE", "DO", "VAR", "ARRAY", "INTEGER", "OF", "AND", "NOT", "OR", "FOR"};
char  cs[][20] = {"=", "<>", "<", ">", "<=", ">=", "+", "-", "/", "*", "..", ".", ":", "(", ")", ",", ";", "[", "]", "{", "}", "'"};
char  op[][20] = {"=", "<", ">", ">", "+", "-", "/", "*", ".", ":", "(", ")", ",", ";", "[", "]", "'"};


char  tab_cs[30];
//char  tab_mc[20][20];
//int   tab_ct[20];


/**********************************/

int is_cs(char x) //si c'est un CS
{
  int res = 0;
  int i, j;
  i = 0;

  for (i = 0; i < 20; i++) {
    if (x == op[i][0])
      res = 1;
  }

  return (res);
}
/*********************************/
/*affiche_mc()
{
int i=0;
char s[20];
for(i=0;i<=20;i++)
 {
   strcpy(s,tab_mc[i]);
   if(s[0]!='\0')
   {

    printf("%s  ",tab_mc[i]);

    }
 }
}

/*****************************/
void affiche_cs() //affiche le contenue du TAB_CS[]
{
  int i = 0;

  for (i = 0; i <= 30; i++) {
    if (tab_cs[i] != '\0')
      printf("%c   ", tab_cs[i]);
  }
}
/**********************************/

void cut_cs(char* jeton) //traiter le jeton et enlever les cs
{
  int i = 0;
  int j = 0;
  int taille = strlen(jeton);
  char token[20];
  char c = ' ';

  while (i <= taille) {
    for (j = 0; j <= 20; j++)
      token[j] = '\0';

    c = jeton[i];
    j = 0;

    while (is_cs(c) != 1) {
      token[j] = c;
      i++;
      c = jeton[i];
      j++;
    }

    c = jeton[i];
    i++;
    traitment(token);
    //printf("voila le jeton %s\n",token);
    //getchar();
  }
}
/**********************************/

/*insert_mc(char *tk)
{//1
 int i=0;
 int ext=0;
 int len=strlen(tk);
 for (i=0;i<=20;i++)  //verifier l'existance de x dans la TS
  {//2
    if (tab_mc[i]==tk) {//3
                       printf("%s existe deja\n",tab_mc[i]);
                        ext=1;
                        }//3
  }//2
 if(ext!=1)
 {

   i=0;
  while ((tab_mc[0][i]!='\0')&&(i<=20))
        {
         i++;
        }

  strcpy(tab_mc[i],tk);
  tab_mc[0][i]=tk[0];
  tab_mc[len][i]='\0';
  //printf("%s inserer dans %d\n",tab_mc[i],i);
}

}//1
/************************************/
void insert_cs(char x) //inserer les cs dans la table des symboles
{
  int i = 0;
  int ext = 0;

  for (i = 0; i <= 30; i++) { //verifier l'existance de x dans la TS
    if (tab_cs[i] == x)
      ext = 1;
  }

  if (ext == 0) {
    i = 0;

    while (tab_cs[i] != '\0')
      i++;

    tab_cs[i] = x;
  }
}

/*******************************/
/**********************************/

void cherche_cs(char* chemin) //chercher les cs du code
{
  FILE* f;
  char c;
  f = fopen(chemin, "r");

  if (f == NULL) {
  }
  else {
    while ((c = fgetc(f)) != EOF) {
      if (is_cs(c) == 1)
        insert_cs(c);
    }
  }

  fclose(f);
}

/******************************/
int is_sep(char x) //verifie si c'est un separateur;
{
  int res = 0;

  if ( (x == ' ') || (x == '\n') )
    res = 1 ;

  return (res);
}

/*********************************************************/
void comment (char* jeton) //pour ignorer les commentaires
{
  char token[20];
  int i = 0;
  int j = 0;

  for (j = 0; j < 20; j++) {
    token[j] = ' ';
    token[j] = '\0';
  }

  while ( (jeton[i] != '{') && (jeton[i] != '}') && (i < 20)) {
    token[i] = jeton[i];
    i++;
  }

  token[i] = '\0';
//printf("%s\n",token);
//traitment(token);
  cut_cs(token);
}
/***********************************/
void traitment(char* token)  //le traitment dujeton tout Simplement ;)
{
  int res = is_mc(token);

  if (res == 1) {
    //insert_mc(token);
    printf("%s\t\t   ---> MOT CLE\n", token);
  }
  else {
    res = is_ct(token);

    if (res == 1)
      printf("%s\t\t   ---> CONSTANTE\n", token);
    else {
      if (res == 2)
        printf("%s\t\t   ---> CONSTANTE INCORRECTE(Taille plus que 5)\n", token);
      else
        is_id(token);
    }
  }
}
//}}
/*********************************************************/
int is_mc(char* tk ) //si un mc//
{
  int res = 0; //le resultat
  int n = 0; //pour la taille exacte
  int i = 0; //un indice
  n = 0;

  while ((i < 10) && (tk[i] != ' ') && (tk[i] != '\0')) {
    n = i;
    i++;
  }

  char jet[n];

  //printf("le taille de jet = %d\n",n+1);
  for (i = 0; i <= n; i++)
    jet[i] = tk[i];

  jet[i] = '\0';
  //printf("jet contien : %s\n",jet);
  int j = 0;

  for (j = 0; j < 15; j++) {
    if (strcmp(jet, mc[j]) == 0)
      res = 1 ;
  }

  return (res);
}
/************************************************************/
int is_ct(char* tk) /* si c'est une constante*/
{
  int a = 1;
  int i = 0;
  int n = 0;

  while ((i < 10) && (tk[i] != ' ') && (tk[i] != '\0')) {
    n = i;
    i++;
  }

  for (i = 0; i <= n; i++) {
    if ( ! isdigit(tk[i]))
      a = 0;
  }

  if (a == 1) {
    if (n > 4)
      a = 2; //la taille de la constante est superieure a 5 digits
  }
  else {
    //rien du tout
  }

  return (a);
}
/***********************************************************/
void is_id(char* jeton)  //si c'est un ID
{
  int res = 1;
  int n = 0;
  int i = 0;

  while ((i < 10) && (jeton[i] != ' ') && (jeton[i] != '\0')) {
    n = i;
    i++;
  }

  if (n > 7)
    printf("%s\t   ---> ID INCORRECTE (Taille ID>8)\n", jeton);
  else {
    if (isdigit(jeton[0]))
      printf("%s\t\t   ---> ID INCORRECTE  (debut avec un chiffre)\n", jeton);
    else
      if (isalpha(jeton[0]))
        printf("%s\t\t   ---> IDENTIFICATEUR \n", jeton);
  }
}

/**********************************************************/

int main ()
{
  FILE* f, *p;
  char c;
  char jeton [20];
  int i = 0;
  c = '"';
  char chemin [32];
  printf("             ********************************************\n");
  printf("             *      A N A L Y S E   L E X I C A L E     *\n");
  printf("             ********************************************\n");
  printf("\nENTRER LE CHEMIN DU FICHIER A ANALYSER:");
  scanf("%s", chemin);
  f = fopen(chemin, "r");
  fopen(chemin, "r");

  if (f == NULL)
    printf("LE FICHIER EST INTROUVABLE !\n");
  else {
//printf("fichier trouvée\n");
    printf("\n\n");
    printf("UNITE LEXICALE          TYPE \n");
    printf("---------------         -----\n");
    p = fopen(chemin, "a");
    fputc('\n', p);
    fclose(p);

    while  ((c = fgetc(f)) != EOF) {
      // tq non fin du fichier
      for (i = 0; i < 20; i++) {
        jeton[i] = ' ';  //initialisation du jeton
        jeton[i] = '\0';
      }

      i = 0; //l'indice du jeton

      while (is_sep(c) != 1) {
        jeton[i] = toupper(c);
        c = fgetc(f);
        i++;
      }

      jeton[i] = '\0';
      i = 0;
      comment(jeton);
      //printf("%s\n",jeton);
    }//fin de tq non fin de fichier

    fclose(f);
  } //fin du else

  printf("\n");
  cherche_cs(chemin);//rechercher les cs
  printf("les caracteres speciaux dans ce fichier sont:\n");
  affiche_cs();
  printf("\n");
//printf("LA LISTE DES MC:\n");
//printf("================\n");
//affiche_mc();
  printf("\n");
}
