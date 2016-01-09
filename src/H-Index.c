int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);
	int result = 0;
	for (int i = 0; i < citationsSize; ++i)
	{
		if (citations[i] > result)
		{
			result++;
		}
	}
	return result;
}