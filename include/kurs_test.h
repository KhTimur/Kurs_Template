#include <iterator>

template <typename random_access_iterator_tag>
void inser(random_access_iterator_tag begi, random_access_iterator_tag en)
{
    for(random_access_iterator_tag ptr  = begi; ptr != en; ptr++)
        for(random_access_iterator_tag j=ptr; j != begi && *(j-1)>*j;j--)
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

template <typename random_access_iterator_tag>
void downHeap(random_access_iterator_tag t, random_access_iterator_tag en) {
  int const siz = (en-t);
  random_access_iterator_tag k= en-(siz/2)-1;
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



template <typename random_access_iterator_tag>
void heapSort(random_access_iterator_tag begi , random_access_iterator_tag en)
{

    random_access_iterator_tag t=begi;
    while(t<en)
    {
        downHeap(t, en);
        t++;
    }
}


template <typename random_access_iterator_tag>
random_access_iterator_tag Partition(  random_access_iterator_tag left, random_access_iterator_tag right)
  {
      int const siz = (right-left);
      random_access_iterator_tag pivot = std::next(left, siz / 2);
      std::swap(*pivot, *(right-1));
      random_access_iterator_tag j=left;
      for (random_access_iterator_tag i=left; i<(right-1);i++)
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

 template <typename random_access_iterator_tag>
void quick_sort( random_access_iterator_tag begi, random_access_iterator_tag en )
{
     int const siz = std::distance(begi, en);
    if (siz>0)
     {
     random_access_iterator_tag g=Partition( begi, en);
     quick_sort( begi, g );
     quick_sort( g+1, en );
     }

}
