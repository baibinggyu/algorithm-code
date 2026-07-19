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
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return &TreeNode{Val: head.Val, Left: nil, Right: nil}
	}
	slow, fast := head, head
	var pre *ListNode = nil
	for slow != nil && fast != nil && fast.Next != nil {
		pre = slow
		slow = slow.Next
		fast = fast.Next.Next
	}
	pre.Next = nil
	cur := TreeNode{Val: slow.Val, Left: nil, Right: nil}
	cur.Left, cur.Right = sortedListToBST(head), sortedListToBST(slow.Next)
	return &cur
}
