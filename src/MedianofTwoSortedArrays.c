double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* nums3 = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
	int nums1Pos = 0, nums2Pos =  0, nums3Pos = 0;
	while (nums1Pos != nums1Size && nums2Pos != nums2Size)
	{
		if (nums1[nums1Pos] < nums2[nums2Pos])
		{
			nums3[nums3Pos++] = nums1[nums1Pos++];
		} else 
		{
			nums3[nums3Pos++] = nums2[nums2Pos++];
		}
	}
	while (nums1Pos != nums1Size)
	{
		nums3[nums3Pos++] = nums1[nums1Pos++];
	}

	while (nums2Pos != nums2Size)
	{
		nums3[nums3Pos++] = nums2[nums2Pos++];
	}
	double result = 0.0;
	if (nums3Pos % 2 == 0)
	{
		result = ((double)nums3[nums3Pos / 2] + (double)nums3[(nums3Pos - 1) / 2]) / 2.0;
	} else {
		result = (double) nums3[nums3Pos / 2];
	}
	free(nums3);

	return (double)result;
}