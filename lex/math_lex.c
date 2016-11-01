#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define get_size(arr) sizeof((arr)) / sizeof(*(arr))

/*
tab1={cos,sin,tan...}ga3 les fonctions li kaynin
tab2 fih les opérateur +,-,*<.>.
tab3 fih séparateur ( ) ; :=
min dakhlah fonction ya9raha chaine de charactère wtesti wcomparé fel tableau weyraja3 kol unité whadha
*/

const char* operators[] = {"+", "-", "*", "/", "^", "<", ">", "!=", "==", ">=", "<=", "!=", "|", "="};
const char* symbols[] = {"(", ")", "[", "]", "{", "}", ";", ":"};
const char* keywords[] = {"arccos", "arccosec", "arccot", "arccsc ", "arcexc", "arcexcosec ", "arcexcsc", "arcexs ", "arcexsec", "arcosech ", "arcosh", "arcoth ", "arcsch", "arcsec ", "arcsin", "arctan", "arctan2", "arg ", "arg", "arsech", "arsinh ", "artanh", "atan2", "Aut", "bd ", "Bi", "Bias ", "Card", "cdf ", "char ", "Chi", "Ci ", "cis", "Cl ", "cl", "cok", "conv ", "Cor", "corr ", "cos", "cosec ", "cosech", "cosh ", "cosiv", "cot ", "coth", "cov ", "cover", "covercos ", "covers", "crd ", "csc", "csch ", "ctg", "curl ", "cvc", "cvs ", "def", "deg ", "del", "det ", "dim", "div ", "dkl", "DNE ", "dom", "End ", "Ei", "epi ", "Eqn", "erf ", "erfc", "etr", "exc", "excosec ", "excsc", "exs ", "exsec", "exp ", "expi", "expm1 ", "exp1m", "Ext ", "ext", "extr ", "FIP", "FOL ", "fr", "Frob ", "Gal", "gcd ", "gd", "GF ", "GL", "grad", "hacover ", "hacovercos", "hacovers ", "hav", "havercos ", "hcc", "hcv ", "hcf", "HOL", "Hom ", "hom", "hot", "HOTPO", "hvc ", "hyp", "iff ", "iid", "Im ", "im", "inf ", "int", "ker ", "lb", "lcm ", "ld", "lerp ", "lg", "LHS ", "Li", "li ", "lim", "lim", "inf ", "lim", "ln ", "lnp1", "ln1p ", "log", "logh ", "LST", "lub ", "max", "min", "mod ", "mtanh", "mth ", "mx", "NAND ", "No", "NOR ", "NTS", "ob ", "ord", "pdf ", "pf", "PGL ", "pmf", "Pr ", "PSL", "QED ", "QEF", "ran ", "rank", "Re ", "resp", "RHS ", "rk", "RMS", "rng", "rot ", "RTP", "RV ", "sec", "sech ", "seg", "sem ", "SFIP", "sgn ", "Shi", "Si ", "sin", "sinc ", "sinh", "siv ", "SL", "Soln ", "sp", "Spec ", "st ", "STP", "sup ", "supp", "Sym ", "tan", "tanh ", "TFAE", "tg ", "tgn", "Thm ", "Tor", "Tr ", "undef", "var", "vcs ", "ver", "vercos ", "vers", "walog", "wff ", "whp", "wlog ", "WMA", "WO ", "wp1", "wrt ", "WTP", "WTS ", "XOR", "ZF ", "ZFC"};

typedef enum {
  ID = 0,
  KW,
  OP,
  SYMB,
  NUM,
  UNKONWN
} token_type;

const char* token_type_str[] = {
  "IDENTIFIER",
  "KEYWORD",
  "OPERATOR",
  "SYMBOL",
  "NUMBER",
  "UNKONWN"
};

bool contains(char* token, const char** group, size_t gsize) {
  for (int i = 0; i < gsize; ++i)
    if (strcmp(group[i], token) == 0)
      return true;
  return false;
}

bool isoper(char* token) {
  return contains(token, operators, get_size(operators));
}

bool issymb(char* token) {
  return contains(token, symbols, get_size(symbols));
}

bool iskw(char* token) {
  return contains(token, keywords, get_size(keywords));
}

bool isidnt(char* token) {
  return isalpha(token[0]);
}

token_type what_type(char* token) {
  return   isoper(token) ? OP
         : issymb(token) ? SYMB
         : iskw(token)   ? KW
         : isidnt(token) ? ID
         : UNKONWN;
}

const char* token_ttos(token_type type) {
  return token_type_str[type];
}

/***************************************
* token definition
***************************************/

typedef struct token {
  char token[32];
  token_type type;
  struct token* next;
} token_s, *token_ptr;

token_ptr make_token(char* str, token_type type, token_ptr next) {
  token_ptr token = (token_ptr) malloc(sizeof(token_s));
  strcpy(token->token, str);

  token->type = type;
  token->next = next;

  return token;
}

/***************************************
* symbole table linked list
***************************************/

typedef struct {
  token_ptr table;
  token_ptr tail;
} symbole_table_s, *symbole_table_ptr;

void symbole_table_init(symbole_table_ptr stable) {
  stable->table  = stable->tail
                 = NULL;
}


void symbole_table_append(symbole_table_ptr stable, token_ptr token) {
  if (stable->table == NULL) {
    stable->table = stable->tail = token;
    return;
  }

  stable->tail->next = token;
  stable->tail = token;
}


void symbole_table_clear(symbole_table_ptr stable) {
  token_ptr cur_token;
  while (stable->table != NULL) {
    cur_token = stable->table;
    stable->table = stable->table->next;
    free(cur_token);
  }
}

void symbole_table_display(const symbole_table_ptr stable) {
  puts("\n--------------TOKENS---------------");
  token_ptr cur_token;
  for (cur_token = stable->table; cur_token != NULL; cur_token = cur_token->next) {
    printf("%s : %s\n",
           cur_token->token,
           token_ttos(cur_token->type));
  }
}


/***************************************
* file reading utilities
***************************************/

int fpeek(FILE* stream) {
  const int c = fgetc(stream);
  ungetc(c, stream);
  return c;
}

char* read_while(char* dest, FILE* stream, int (*unary_predicate)(int)) {
  int c;
  while ((c = fgetc(stream)) != EOF && unary_predicate(c))
    *dest++ = c;
  *dest = '\0';
  return dest;
}

char* read_num(char* dest, FILE* stream) {
  return read_while(dest, stream, isdigit);
}

char* read_string(char* dest, FILE* stream) {
  return read_while(dest, stream, isalpha);
}

char* read_space(char* dest, FILE* stream) {
  return read_while(dest, stream, isspace);
}

char* read_punct(char* dest, FILE* stream) {
  return read_while(dest, stream, ispunct);
}

void tokenize(symbole_table_ptr stable, FILE* stream) {
  char token[32];
  for (int c = fpeek(stream); c != EOF; c = fpeek(stream)) {
    // read number
    if (isdigit(c)) {
      read_num(token, stream);
      symbole_table_append(stable, make_token(token, NUM, NULL));
      continue;
    }

    // read identifiers
    if (isalpha(c)) {
      read_string(token, stream);
      symbole_table_append(stable, make_token(token, what_type(token), NULL));
      continue;
    }

    // read white space
    if (isspace(c)) {
      read_space(token, stream);
      continue;
    }

    // read symbols
    if (ispunct(c)) {
      read_punct(token, stream);
      symbole_table_append(stable, make_token(token, what_type(token), NULL));
      continue;
    }
  }
}


int main(int argc, char const *argv[])
{
  symbole_table_s stable;
  symbole_table_init(&stable);
  tokenize(&stable, stdin);
  symbole_table_display(&stable);
  symbole_table_clear(&stable);
}
