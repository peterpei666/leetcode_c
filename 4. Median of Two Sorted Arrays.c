double find(int* nums1,int nums1Size,int* nums2,int nums2Size)
{
    int i=0,j=0,count,total;
    double mid1=0,mid2=0;
    total=nums1Size+nums2Size;
    for(count=0;count<=total/2;count++)
    {
        mid1=mid2;
        if(i<nums1Size&&(j>=nums2Size||*(nums1+i)<*(nums2+j)))
        {
            mid2=*(nums1+i);
            i++;
        }
        else
        {
            mid2=*(nums2+j);
            j++;
        }
    }
    if(total%2)
    {
        return mid2;
    }
    else
    {
        return mid1/2.0+mid2/2.0;
    }
}
