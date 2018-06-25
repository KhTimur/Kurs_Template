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
