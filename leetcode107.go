import "slices"
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
import "fmt"
func levelOrderBottom(root *TreeNode) [][]int {
    if root == nil{return nil}
    if root.Left == nil && root.Right == nil{return [][]int{{root.Val}}}
    queue := []*TreeNode{}
    queue = append(queue,root) 
    res := [][]int{}
    for len(queue) > 0{
        arr := queue
        queue = []*TreeNode{}
        temp := []int{}
        for _ , node := range arr{
            temp = append(temp,node.Val)
            if node.Left != nil{ queue = append(queue,node.Left)}
            if node.Right != nil{queue = append(queue,node.Right)}
        }
        res = append(res,temp)
    }
    slices.Reverse(res)
    return res
}
