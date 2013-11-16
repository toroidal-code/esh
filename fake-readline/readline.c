/* 
 * esh, the Unix shell with Lisp-like syntax. 
 * Copyright (C) 1999  Ivan Tkatchev
 * This source code is under the GPL.
 */

#include <stdio.h>
#include <unistd.h>

void add_history(char* line) {
  /* Nothing. */
}

void rl_bind_key(char foo, int(*func)(int, int)) {
  /* Nothing. */
}

void rl_insert_text(char* foo) {
  /* Nothing. */
}

char* readline(char* prompt) {
  static int interactive = -1;

  int len = 80;
  int i = 0;
  char* ret = (char*)malloc(sizeof(char) * len);
  char foo = 0;

  if (interactive < 0) {
    interactive = isatty(STDIN_FILENO);
  }

  if (interactive) {
    printf(prompt);
    fflush(stdout);
  }

  while (foo != '\n') {
    if (read(STDIN_FILENO, &foo, 1) <= 0) {
      free(ret);
      return NULL;
    }

    if (i >= len-2) {
      char* tmp = (char*)malloc(sizeof(char) * len * 2);

      len *= 2;

      strcpy(tmp, ret);
      free(ret);
      ret = tmp;
    }
    
    ret[i] = foo;
    i++;
  }

  ret[i] = '\0';

  return ret;
}
