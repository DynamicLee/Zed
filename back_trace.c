#include <execinfo.h>
void print_trace(void)
{
  void  *array[128] = {0};
  int   size        = 0;
  char  **strings   = NULL;
  int   i           = 0;
  
  size    = backtrace(array, 20);
  strings = backtrace_symbols(array, size);
  
  for(i=0; i<size; i++)
  {
    printf("\033[1;35m @@@%d:%s\033[0m\n", i, strings[i]);
  }
  
  if(strings)
  {
    free(strings);
      strings = NULL;
  }
}
