#include "../../../includes/containers.h"
#include <stdio.h>

int	cmp(void *value, void *target)
{
	t_hashcontent *t_value;
	t_hashcontent *t_target;

	t_value = (t_hashcontent *)value;
	t_target = (t_hashcontent *)target;
	if (!ft_strncmp(t_value->key, t_target->key, -1))
		return (1);
	return (0);
}

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
