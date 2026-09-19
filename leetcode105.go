package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	pos := make(map[int]int,len(inorder))  
	for i := 0;i < len(inorder);i++{ pos[inorder[i]] = i}
	preIndex := 0
	var build func(left int,right int) *TreeNode
	build = func(left int,right int) *TreeNode{
		if left > right {return nil}  
		mid_value := preorder[preIndex]
		mid := pos[mid_value]
		preIndex++
		cur := &TreeNode{Val:mid_value}
		cur.Left = build(left,mid - 1)
		cur.Right = build(mid + 1,right)
		return cur
	}
	return build(0,len(inorder) - 1)
}
