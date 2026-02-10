func longestBalanced(nums []int) int {
	n := len(nums)
	maxLen := 0
	for i := 0; i < n-1; i++ {
		odd := make(map[int]bool)
		even := make(map[int]bool)
		for j := i; j < n; j++ {
			if nums[j]%2 == 0 {
				even[nums[j]] = true
			} else {
				odd[nums[j]] = true
			}
			if len(odd) == len(even) {
				currLen := j - i + 1
				if currLen > maxLen {
					maxLen = currLen
				}
			}
		}
	}
	return maxLen
}