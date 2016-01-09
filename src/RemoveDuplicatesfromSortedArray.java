int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
	{
		return 0;
	}
    int currentPos = 1;
	int currentNum = nums[0];
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] == currentNum)
		{
			continue;
		}
		nums[currentPos++] = nums[i];
		currentNum = nums[i];
	}
	return currentPos;
}