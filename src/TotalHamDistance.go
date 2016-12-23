package main

import (
	"fmt"
)

func totalHammingDistance(nums []int) int {
	result := 0
	length := len(nums)
	for i := 0; i < 32; i++ {
		bitCount := 0
		for j := 0; j < length; j++ {
			var tmp = uint(nums[j])
			var step = uint(i)
			bitCount += int(tmp>>step) & 1
		}
		result += bitCount * (length - bitCount)
	}

	return result
}

func main() {
	arr := []int{4, 14, 2}
	fmt.Print(totalHammingDistance(arr))
}
