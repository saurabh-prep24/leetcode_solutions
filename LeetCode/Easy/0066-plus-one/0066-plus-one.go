func plusOne(digits []int) []int {
	c := 1
	n := len(digits)
	i := n - 1
	for i >= 0 {
		s := (digits[i] + c)
		digits[i] = (s) % 10
		c = (s) / 10
		if c == 0 {
			break
		}
		i--
	}
	ans := []int{}
	if c > 0 {
		ans = append(ans, c)
	}
	ans = append(ans, digits...)
	return ans
}
