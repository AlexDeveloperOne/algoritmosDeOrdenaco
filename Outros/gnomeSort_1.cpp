# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>


Código em C++ versão 1

template<class T>
void gnome_sort( std::vector<T> &lista )
{
  std::vector<T>::size_type i = 1;

  while( i < lista.size() )
  {
    if( i == 0 || lista.at( i-1 ) <= lista.at( i ) )
    {
      i++;
    }
    else
    {
      std::swap( lista[ i - 1 ], lista [ i ] );
      --i;
    }
  }
}