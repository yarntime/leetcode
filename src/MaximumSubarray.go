package main

import (
	"fmt"
)

func maxSubArray(nums []int) int {
	sum := -1
	result := -(1 << 30)
	for i := 0; i < len(nums); i++ {
		if sum < 0 {
			sum = nums[i]
		} else {
			sum += nums[i]
		}
		if sum > result {
			result = sum
		}
	}
	return result
}

func main() {
	arr := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
	fmt.Print(maxSubArray(arr))
}
