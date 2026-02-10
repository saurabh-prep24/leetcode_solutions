/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func inorder(root *TreeNode, nodes *[]int) {
	if root == nil {
		return
	}

	inorder(root.Left, nodes)
	*nodes = append(*nodes, root.Val)
	inorder(root.Right, nodes)
}

func buildBalanced(nodes []int, start, end int) (root *TreeNode) {
	if start > end {
		return nil
	}

	mid := (start + end) / 2
    val := nodes[mid]
	newRoot := &TreeNode{Val: val}
	newRoot.Left = buildBalanced(nodes, start, mid-1)
	newRoot.Right = buildBalanced(nodes, mid+1, end)
	return newRoot
}

func balanceBST(root *TreeNode) *TreeNode {
	nodes := []int{}
	inorder(root, &nodes)

	return buildBalanced(nodes, 0, len(nodes)-1)
}