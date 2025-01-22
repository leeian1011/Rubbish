#include "../../../includes/containers.h"
#include <stdio.h>

int main()
{
  t_dll *dll;

  dll = dll_init();
  dll_append(dll, "hello");
  dll_prepend(dll, "goodbye");
  dll_append(dll, "fuck bro");
  dll_append(dll, "kanina");
  print_dll(dll);
  dll_remove(dll, dll->head->next->next);
  printf("===========================\n");
  print_dll(dll);
  return (0);
}
