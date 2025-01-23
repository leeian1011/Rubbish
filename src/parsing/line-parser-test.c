#include "../../includes/parsing.h"
#include "../../includes/containers.h"

int main(void)
{
  t_dll *dll = dll_init();
  // char *y = "echo hi \"hello bro\"googoogaagaa";
  char *y = "< infile cat | ls -a | sleep 3 && (echo $? >1)";
  // char *y = ""
  if (parse_line(dll, y))
    print_dll(dll);
  else
    printf("parse_line return err!\n");
}
