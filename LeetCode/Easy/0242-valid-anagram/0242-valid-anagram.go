func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	countS := make(map[rune]int)
	for _, c := range s {
		countS[c]++
	}

	countT := make(map[rune]int)
	for _, c := range t {
		countT[c]++
	}

	if len(countS) != len(countT) {
		return false
	}

	for k, v := range countS {
		if countT[k] != v {
			return false
		}
	}
	return true
}