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

/*template <typename random_access_iterator_tag>
void inplmerg (int* begi, int* middle, int* en)
{
   int const siz = std::distance(begi, en);
   int num[siz];
   int k=0;
   int j=0;
   int i=0;
   while( ((begi+i)<middle) && ((middle+k)<en)  )
       if(*(begi+i) < *(middle+k))
          {
            num[j]=*(begi+i);
            i++;
            j++;
          }
       else
          {
            num[j]=*(middle+k);
            k++;
            j++;
          }
   while ((begi+i)<middle)
        {
            num[j]=*(begi+i);
            i++;
            j++;
        }
   while ((middle+k)<en)
        {
            num[j]=*(middle+k);
            k++;
            j++;
        }
   for (int i = 0; i<siz; i++)
      {
        *(begi+i)=num[i];
      }
}

template <typename random_access_iterator_tag>
void merge_sort(int * begi, int *en)
{
    int const siz = std::distance(begi, en);
    if (siz <= 1) return;
    int * const middle = begi+( siz / 2);
    merge_sort(begi, middle);
    merge_sort(middle, en);
    inplmerg(begi, middle, en);
}*/

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
