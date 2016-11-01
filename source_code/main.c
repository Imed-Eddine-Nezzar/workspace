#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* my_fgets(char* string, int n, FILE* fp)
{
  int ch = 0;
  int count = 0;

  while (count < (n - 1)) {
    ch = fgetc(fp);

    if ( ch == EOF )
      break;
    else
      if ( ch == '\n' )
        break;
      else
        string[count] = ch;

    count++;
  }

  string[count] = '\0';

  if ( ch == EOF )
    return (NULL);
  else
    return (string);
}


void echange(int note[][12], char etudiant[][12], float moy_e[], char module[][12], int l, int min, int nb_module)
{
  int i, tmp;
  char temp[12];
  strcpy(temp, etudiant[l]);
  strcpy(etudiant[l], etudiant[min]);
  strcpy(etudiant[min], temp);

  for (i = 0; i < nb_module; i++) {
    tmp = note[l][i];
    note[l][i] = note[min][i];
    note[min][i] = tmp;
  }

  tmp = moy_e[l];
  moy_e[l] = moy_e[min];
  moy_e[min] = tmp;
}

void tri(int note[15][12], char etudiant[][12], float moy_e[], char module[][12], int nb_etudiant, int nb_module)
{
  int i, j;
  int max;

  for (i = 0; i < nb_etudiant; i++) {
    max = i;

    for (j = i + 1; j < nb_etudiant; j++) {
      if (moy_e[max] < moy_e[j])
        max = j;
    }

    echange(note, etudiant, moy_e, module, i, max, nb_module);
  }
}

void affichage_module(int note[][12], char nom[][12], float moy[], char module[][12], int nb_etudiant, int nb_module)

{
  int i;
  char mot [12];
  int index = -1;
  printf("\nEntrez le module que vous voulez affichez \n");
  scanf("%s", mot);

  for (i = 0; i < nb_module; i++) {
    if (strcmp(mot, module[i]) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1)
    printf("\nModule nexiste pas\n");
  else {
    printf("\n\t   ");
    printf("%-10s", module[i]);
    printf("\n");

    for (i = 0; i < nb_etudiant; i++) {
      printf("%-10s", nom[i]);
      printf("  %-10d\n", note[i][index]);
    }

    printf("\n%-10s  ", nom[nb_etudiant]);
    printf("%-10.1f", moy[index]);
    printf("\n\n");
  }
}



void affichage_etudiant(int note[][12], char module[][12], char etudiant[][12], float moy_e[], int nb_etudiant, int nb_module)
{
  int i;
  int j;
  char mot [12];
  int index = -1;
  printf("\nEntrez l'etudiant que vous voulez affichez \n");
  my_fgets(mot, sizeof(mot), stdin);

  for (i = 0; i < nb_etudiant; i++) {
    if (strcmp(mot, etudiant[i]) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1)
    printf("\nEtudiant n'existe pas\n");
  else {
    printf("\t   ");

    for (i = 0; i < nb_module; i++)
      printf("%-10s", module[i]);

    printf("%-10s", module[nb_module]);
    printf("\n");
    printf("\n%-10s ", etudiant[index]);

    for (j = 0; j < nb_module; j++)
      printf("%-10d ", note[index][j]);

    printf("%-10.2f ", moy_e[index]);
  }
}
void affichage(int note[][12], char nom[][12], float moy[], float moy_e[], char module[][12], int nb_etudiant, int nb_module)
{
  int i, j;
  printf("\n");
  printf("\t\t******AFFICHAGE FINAL******\n\n");
  printf("\t   ");

  for (i = 0; i < nb_module; i++)
    printf("%-10s", module[i]);

  printf("%-10s", module[nb_module]);
  printf("\n");

  for (i = 0; i < nb_etudiant; i++) {
    printf("%-10s ", nom[i]);

    for (j = 0; j < nb_module; j++)
      printf("%-10d", note[i][j]);

    printf("%-10.1f\n", moy_e[i]);
  }

  printf("\n%-10s ", nom[nb_etudiant]);

  for (i = 0; i < nb_module; i++)
    printf("%-10.1f", moy[i]);
}

void max(char etudiant[][12], char module[][12], int note[][12], int nb_etudiant, int nb_module)
{
  int m;
  char key[10];
  int i = 0;
  int index = 0;
  printf("\nEntrez le nom du module:\n");
  scanf("%s", key);

  for (i = 0; i < nb_module; i++) {
    if (strcmp(key, module[i]) == 0) {
      index = i;
      break;
    }
    else
      i++;
  }

  int index2 = 0;
  m = note[0][index];

  for (i = 0; i < nb_etudiant; i++) {
    if (m < note[i][index]) {
      m = note[i][index];
      index2 = i;
    }
  }

  printf("\nla note maximal dans le module %s est %d de %s \n", module[index], m, etudiant[index2]);
}

void moy_classe(int note[][12], int nb_etudiant, int nb_module, float moy[])
{
  int i, j;
  int somme = 0;

  for (i = 0; i < nb_module; i++) {
    somme = 0;

    for (j = 0; j < nb_etudiant; j++)
      somme = somme + note[j][i];

    moy[i] = somme / nb_etudiant;
  }
}
void moy_etudiant(int note[][12], int nb_etudiant, int nb_module, float moy_e[])
{
  int i, j;
  int somme = 0;

  for (i = 0; i < nb_etudiant; i++) {
    somme = 0;

    for (j = 0; j < nb_module; j++)
      somme = somme + note[i][j];

    moy_e[i] = somme / nb_module;
  }
}

void aff_note(char module[][12], char etudiant[][12], int note[15][12], int nb_etudiant, int nb_module) //affichage d'"mation
{
  int i, j;

  for (i = 0; i < nb_etudiant; i++) {
    printf("Les note de l'etudiant %s\n", etudiant[i]);

    for (j = 0; j < nb_module; j++)
      printf("%s : %d\n", module[j], note[i][j]);
  }
}
void aff_moy_class(float moy[], char module[][12], int nb_module)
{
  int i;

  for (i = 0; i < nb_module; i++)
    printf("\nla moy de la class du module %s est %0.2f\n", module[i], moy[i]);
}
void aff_moy_etud(float moy_e[], char etudiant[][12], int nb_etudiant)
{
  int i;
  printf("\nAffichage du moyennes generale\n");

  for (i = 0; i < nb_etudiant; i++)
    printf("%s : %0.2f\n", etudiant[i], moy_e[i]);
}
void information(char module[][12], char etudiant[][12], int note[15][12], int nb_etudiant, int nb_module)
{
  int i, j;
  strcpy(module[nb_module], "MOY GENERALE");
  strcpy(etudiant[nb_etudiant], "MOY CLASS");
  strcpy(etudiant[nb_etudiant + 1], "\0");
  strcpy(module[nb_module + 1], "\0");

  for (i = 0; i < nb_module; i++) {
    printf("Entrez le nom de module num %d\n", i + 1);
    my_fgets(module[i], sizeof(module[i]), stdin);
  }

  for (i = 0; i < nb_etudiant; i++) {
    printf("\nEntrez le %d nom\n", i + 1);
    my_fgets(etudiant[i], sizeof(etudiant[i]), stdin);
  }

  for (i = 0; i < nb_etudiant; i++) {
    for (j = 0; j < nb_module; j++) {
      printf("Entrez la note du module %s de %s:\n", module[j], etudiant[i]);

      do {
        scanf("%d", &note[i][j]);

        if ((note[i][j] > 20) || (note[i][j] < 0))
          printf("Erreur ! Rentrez la note\n");
      }
      while ((note[i][j] > 20) || (note[i][j] < 0));
    }
  }
}
void supprimer (char module[][12], char etudiant[][12], int note[15][12], float moy_e[], int* nb_etudiant, int nb_module, float moy[])
{
  int i;
  int count = 0;
  int nb = *nb_etudiant;
  char temp[10];
  strcpy(temp, etudiant[nb]);
  tri(note, etudiant, moy_e, module, nb, nb_module);

  for (i = 0; i < *nb_etudiant; i++) {
    if (moy_e[i] < 10)
      count++;
  }

  *nb_etudiant = *nb_etudiant - count;
  nb = *nb_etudiant;
  moy_classe(note, nb, nb_module, moy);
  strcpy(etudiant[nb], temp);
  affichage(note, etudiant, moy, moy_e, module, nb, nb_module);
}
void aff_moy_generale(char module[][12], char etudiant[][12], int note[15][12], float moy_e[], int nb_etudiant, int nb_module)
{
  int i;
  printf("\tMoyenne Generale\n");

  for (i = 0; i < nb_etudiant; i++) {
    printf("%-10s", etudiant[i]);
    printf("  %-10.2f", moy_e[i]);
    printf("\n");
  }
}
void menu(char module[][12], char etudiant[][12], int note[15][12], float moy[], float moy_e[], int nb_etudiant, int nb_module)
{
  int choix;
  int menu2;

  while (1) {
    printf("\n\nEntrez votre choix !\n");
    printf("\n           1- Sasie\n");
    printf("\n           2- L'affichage\n");
    printf("\n           3- La note maximale\n");
    printf("\n           4- Le tri d'information\n");
    printf("\n           5- La suppression \n");
    scanf("%d", &choix);
    getchar();

    switch (choix) {
    case 1:
      information(module, etudiant, note, nb_etudiant, nb_module);
      moy_classe(note, nb_etudiant, nb_module, moy);
      moy_etudiant(note, nb_etudiant, nb_module, moy_e);
      break;

    case 2:
      printf("\n             1-Affichage par module\n");
      printf("\n             2-Affichage Moyenne generale\n");
      printf("\n             3-Affichage par etudiant\n");
      printf("\n             4-Affichage final\n");
      scanf("%d", &menu2);
      getchar();

      switch (menu2) {
      case 1:
        affichage_module(note, etudiant, moy, module, nb_etudiant, nb_module);
        break;

      case 2:
        aff_moy_generale(module, etudiant, note, moy_e, nb_etudiant, nb_module);
        break;

      case 3:
        affichage_etudiant(note, module, etudiant, moy_e, nb_etudiant, nb_module);
        break;

      case 4:
        affichage(note, etudiant, moy, moy_e, module, nb_etudiant, nb_module);
        break;
      }

      break;

    case 3:
      max(etudiant, module, note, nb_etudiant, nb_module);
      break;

    case 4:
      tri(note, etudiant, moy_e, module, nb_etudiant, nb_module);
      affichage(note, etudiant, moy, moy_e, module, nb_etudiant, nb_module);
      break;

    case 5:
      supprimer(module, etudiant, note, moy_e, &nb_etudiant, nb_module, moy);
      break;
    }
  }
}
int main()
{
  int nb_module;
  int nb_etudiant;
  printf("Entrez le nombre des modules\n");
  scanf("%d", &nb_module);
  getchar();
  printf("Entrez le nombre d'etudiant\n");
  scanf("%d", &nb_etudiant);
  getchar();
  char module[nb_module + 1][12];
  char etudiant[nb_etudiant + 1][12];
  float moy[nb_module];
  float moy_e[nb_etudiant];
  int note[nb_etudiant][12];
  menu(module, etudiant, note, moy, moy_e, nb_etudiant, nb_module);
  printf("\n");
  return 0;
}










