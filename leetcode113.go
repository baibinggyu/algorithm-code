package algorithm_code

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, targetSum int) [][]int {
	if root == nil {
		return [][]int{}
	}
	if root.Left == nil && root.Right == nil {
		if root.Val == targetSum {
			return [][]int{[]int{root.Val}}
		}
		return [][]int{}
	}
	res := [][]int{}
	bfs(root, 0, targetSum, []int{}, &res)
	return res
}
func bfs(cur *TreeNode, curSum int, targetSum int, arr []int, res *[][]int) {
	if cur == nil {
		return
	}
	if cur.Left == nil && cur.Right == nil {
		if cur.Val+curSum == targetSum {
			path := make([]int, len(arr))
			copy(path, arr)
			path = append(path, cur.Val)
			*res = append(*res,path
		}
		return
	}
	arr = append(arr, cur.Val)
	bfs(cur.Left, curSum+cur.Val, targetSum, arr, res)
	bfs(cur.Right, curSum+cur.Val, targetSum, arr, res)
}
