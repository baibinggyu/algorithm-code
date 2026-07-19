type ListNode struct {
	Val  int
	Next *ListNode
}
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sortedListToBST(head *ListNode) *TreeNode {
	arr := []*ListNode{}
	cur := head
	if cur == nil {
		return nil
	}
	for cur != nil {
		arr = append(arr, cur)
		cur = cur.Next
	}
	n := len(arr)
	if n == 1 {
		return &TreeNode{Val: head.Val, Left: nil, Right: nil}
	}
	return build(arr)
}
func build(arr []*ListNode) *TreeNode {
	n := len(arr)
	if n == 0 {
		return nil
	}
	if n == 1 {
		return &TreeNode{Val: arr[0].Val, Left: nil, Right: nil}
	}
	// 左闭合右开
	mid := n >> 1
	cur := TreeNode{Val: arr[mid].Val, Left: nil, Right: nil}
	cur.Left = build(arr[0:mid])
	cur.Right = build(arr[mid+1:])
	return &cur
}
