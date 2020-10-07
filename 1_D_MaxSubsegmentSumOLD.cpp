#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long MaxSubsegmentSum(long long* begin, long long* end);

int main()
{
    const int MIN_VALUE = 1;
    
    int N = 0;
    scanf  ("%d", &N);
    assert (N >= MIN_VALUE);
    
    long long* Array = (long long*) calloc (N, sizeof(long long));
    assert (Array != NULL);
    long long* PrefArray = (long long*) calloc (N + 1, sizeof(long long));
    assert (PrefArray != NULL);
    
    PrefArray[0] = 0;
    for (size_t i = 0; i < N; i++)
    {
        scanf ("%lld", Array + i);
        PrefArray[i + 1] = PrefArray[i] + Array[i];
    }
    
    //
    printf("PrefArray[0] = %lld\n", PrefArray[0]);
    for (int i = 0; i < N; i++)
    {
        printf("PrefArray[%d] = %lld\tArray[%d] = %lld\n", i+1, PrefArray[i+1], i, Array[i]);
    }
    //
    
    int Q = 0;
    scanf  ("%d", &Q);
    assert (Q >= MIN_VALUE);
    
    long long i = 0;
    long long j = 0;
    long long* begin = 0;
    long long* end   = 0;
    
    
    long long max_sub_sum = 0;
    for (int t = 0; t < Q; t++)
    {
        scanf ("%d %d", &i, &j);
        assert (i < j);
        
        begin = (PrefArray + i);
        end   = (PrefArray + j);
        
        //
        printf("begin elem = %lld\tend elem = %lld", *begin, *end);
        //
        
        max_sub_sum = MaxSubsegmentSum (begin, end);
        printf ("%lld\n", max_sub_sum);
    }
    
    free(Array);
    free(PrefArray);
    
    return 0;
}

/*struct Extremum
{
    long long value;
    long long index;
};*/

long long MaxSubsegmentSum(long long* begin, long long* end)
{
    long long cur_sum = 0;
    //struct Extremum max_psum = {-1000000001, 0};
    long long max_psum = -1000000001;
    
    //struct Extremum min_psum = {0, 0};
    long long min_psum = 0;
    
    //struct Extremum pot_min_psum = {0, 0};
    long long pot_min_psum = 0;
    
    for (long long* pointer = begin + 1; pointer <= end; pointer++)
    {
        cur_sum = *pointer - *begin;
        
        if (cur_sum > max_psum/*.value*/)
        {
            max_psum/*.value*/ = cur_sum;
            //max_psum.index = pointer - begin;
            
            if (/*pot_min_psum.index < max_psum.index && */pot_min_psum/*.value*/ < min_psum/*.value*/)
            {
                min_psum/*.value*/ = pot_min_psum/*.value*/;
                //min_psum.index = pot_min_psum.index;
            }
        }
        
        if (cur_sum < min_psum/*.value*/)
        {
            pot_min_psum/*.value*/ = cur_sum;
            //pot_min_psum.index = pointer - begin;
        }
    }
    
    //
    printf("\nmax_psum.value = %lld\tmin_psum.value = %lld", max_psum/*.value*/, min_psum/*.value*/);
    //
    
    return max_psum/*.value*/ - min_psum/*.value*/;
}
