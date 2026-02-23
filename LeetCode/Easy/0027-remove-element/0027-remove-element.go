func removeElement(nums []int, val int) int {
    i:= 0
    for k := range nums {
        if nums[k] == val{
            break
        }
        i++
    }
    if i>=len(nums){
        return len(nums)
    }

    j:= i+1
    for j<len(nums){
        if nums[j] != val {
            // swap
            nums[i], nums[j] = nums[j], nums[i]
            i++
        }
        j++
    }
    return i
}