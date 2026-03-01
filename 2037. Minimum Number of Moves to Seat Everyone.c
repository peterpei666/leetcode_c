#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize)
{
    int n = seatsSize;
    qsort(seats, n, sizeof(int), cmp);
    qsort(students, n, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(seats[i] - students[i]);
    }
    return ans;
}
