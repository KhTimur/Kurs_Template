#include <iterator>

template <typename RandomAccessIterator>
void inser(RandomAccessIterator  begi, RandomAccessIterator en)
{
    for(RandomAccessIterator ptr  = begi; ptr != en; ptr++)
        for(RandomAccessIterator j=ptr; j != begi && *(j-1)>*j;j--)
			{
			   std::swap(*(j-1),*j);
            }
}
