/* 
 * esh, the Unix shell with Lisp-like syntax. 
 * Copyright (C) 1999  Ivan Tkatchev
 * This source code is under the GPL.
 */

extern void rl_bind_key(char foo, int(*func)(int, int));
extern void rl_insert_text(char* foo);
extern char* readline(char* prompt);
