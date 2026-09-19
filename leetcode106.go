/**
* Definition for a binary tree node.
* type TreeNode struct {
	*     Val int
	*     Left *TreeNode
	*     Right *TreeNode
	* }
**/

func buildTree(inorder []int, postorder []int) *TreeNode {
    if len(inorder) == 0{return nil}
    if len(inorder) == 1{return &TreeNode{Val:inorder[0]}}
    backIndex := len(postorder) - 1
    hash := make(map[int]int,len(postorder))
    for i := 0;i < len(inorder);i++{hash[inorder[i]] = i}
    var build func(left int,right int) *TreeNode
    build = func(left int,right int) *TreeNode{
        if left > right{return nil}
        cur := &TreeNode{Val:postorder[backIndex]} 
        mid := hash[postorder[backIndex]]
        backIndex--
        cur.Right = build(mid + 1,right)    
        cur.Left = build(left,mid - 1)
        return cur 
    }
    return build(0,len(postorder) -1 )
}
