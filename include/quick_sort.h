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
