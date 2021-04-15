# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>

Código em C++ versão 2

template<class T>
void gnome_sort( std::vector<T> &lista )
{
  std::vector<T>::iterator elem = lista.begin()+1;

  while( elem != lista.end() )
  {
    if( elem == lista.begin() || *(elem-1) <= *elem )
    {
      ++elem;
    }
    else
    {
      std::iter_swap( elem-1, elem );
      --elem;
    }
  }
}