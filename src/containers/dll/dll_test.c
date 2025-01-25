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
  // dll_remove(dll, dll->head->next->next);
  printf("===========================\n");
  dll_remove(dll, dll->tail, NULL);
  print_dll(dll);
  printf("===========================\n");
  dll_clear(dll);
  print_dll(dll);
  return (0);
}
