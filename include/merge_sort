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
