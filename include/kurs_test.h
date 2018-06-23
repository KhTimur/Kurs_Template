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

template <typename  RandomAccessIterator,typename FindMin>
void merge_sort(RandomAccessIterator begi, RandomAccessIterator en, FindMin min)
{
	int siz = std::distance(begi, en);
    size_t first_half = siz / 2;
	size_t second_half = siz - first_half;
	if (siz <= 1)
		return;
	RandomAccessIterator middle = begi;
	std::advance(middle, first_half);

	merge_sort(begi, middle, min);
	merge_sort(middle, en, min);

	RandomAccessIterator right = middle;

	while (begi != middle)
	{
		if (min(*right, *begi))
		{
			typename std::iterator_traits<RandomAccessIterator>::value_type replace =
				std::move(*begi);
			*begi = std::move(*right);
			RandomAccessIterator scan = right;
			RandomAccessIterator next = scan;
			++next;

			while (next != en && min(*next, replace))
			{
				*scan++ = std::move(*next++);
			}

			*scan = std::move(replace);
		}
		++begi;
	}
}

template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	merge_sort(first, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

template <typename RandomAccessIterator>
void downHeap(RandomAccessIterator t, RandomAccessIterator en) {
  int const siz = (en-t);
  RandomAccessIterator k= en-(siz/2)-1;
    while (k>=t)
    {
        int a= (k-t);
        if(*k> *(k+a))
            {
                std::swap(*k,*(k+a));
            }
        if(*k>*(k+a+1) && (k+a+1)!=en)
            {
                std::swap(*k,*(k+a+1));
            }
        k--;
    }
}



template <typename RandomAccessIterator>
void heapSort(RandomAccessIterator begi , RandomAccessIterator en)
{

    RandomAccessIterator t=begi;
    while(t<en)
    {
        downHeap(t, en);
        t++;
    }
}


template <typename RandomAccessIterator>
RandomAccessIterator Partition(  RandomAccessIterator left, RandomAccessIterator right)
  {
      int const siz = (right-left);
      RandomAccessIterator pivot = std::next(left, siz / 2);
      std::swap(*pivot, *(right-1));
      RandomAccessIterator j=left;
      for (RandomAccessIterator i=left; i<(right-1);i++)
      {
          if (*i<*(right-1))
          {
              std::swap(*i,*j);
              j++;
          }
      }
      std::swap(*j,*(right-1));
      return j;
  }

 template <typename RandomAccessIterator>
void quick_sort( RandomAccessIterator begi, RandomAccessIterator en )
{
     int const siz = std::distance(begi, en);
    if (siz>0)
     {
     RandomAccessIterator g=Partition( begi, en);
     quick_sort( begi, g );
     quick_sort( g+1, en );
     }

}
