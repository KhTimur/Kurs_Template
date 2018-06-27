#include "catch.h"
#include <algorithm>
#include <quick_sort.h>


SCENARIO("SORT"){
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int numscheck[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    long int j=0;
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        quick_sort(begi, en);
        int k=1;
        for (int o = 0; o <= 10; ++o) {
		if(nums[o] != numscheck[o])
        {
         k=0;
        }
        j=j+k;
	}

    }
    REQUIRE(j==3628800);
    return 0;
}
