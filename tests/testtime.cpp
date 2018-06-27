#include "catch.h"
#include <algorithm>
#include <inser.h>
#include <merge_sort.h>
#include <quick_sort.h>
#include <heapSort.h>

SCENARIO("SORT"){
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        inser(begi, en);
   	}
    auto end_time = chrono::high_resolution_clock::now();
    }
    return 0;
}

SCENARIO("SORT"){
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        merge_sort(begi, en);
   	}
    auto end_time = chrono::high_resolution_clock::now();
    }
    return 0;
}


SCENARIO("SORT"){
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        heapSort(begi, en);
   	}
    auto end_time = chrono::high_resolution_clock::now();
    }
    return 0;
}


SCENARIO("SORT"){
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        quick_sort(begi, en);
   	}
    auto end_time = chrono::high_resolution_clock::now();
    }
    return 0;
}
