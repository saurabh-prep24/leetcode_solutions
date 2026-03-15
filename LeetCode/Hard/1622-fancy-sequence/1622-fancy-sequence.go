type Fancy struct {
	elems []int
}

func Constructor() Fancy {
	elems := make([]int, 0)
	return Fancy{elems: elems}
}

func (this *Fancy) Append(val int) {
	this.elems = append(this.elems, val)
}

func (this *Fancy) AddAll(inc int) {
	for i, e := range this.elems {
		this.elems[i] = e + inc
	}
}

func (this *Fancy) MultAll(m int) {
	for i, e := range this.elems {
		this.elems[i] = (e * m)%(1e9+7)
	}
}

func (this *Fancy) GetIndex(idx int) int {
	if idx >= len(this.elems) {
		return -1
	}
    // fmt.Println(idx, len(this.elems))
	return this.elems[idx]%(1e9+7)
}

/**
 * Your Fancy object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Append(val);
 * obj.AddAll(inc);
 * obj.MultAll(m);
 * param_4 := obj.GetIndex(idx);
 */