package contest187

const INF = 0x3f3f3f3f

func minCost(source string, target string, rules [][]string, costs []int) int {
	if len(source) != len(target) {
		return -1
	}
	for idx, x := range rules {
		str := x[0]
		cnt := 0
		for i := 0; i < len(str); i++ {
			if str[i] == '*' {
				cnt++
			}
		}
		costs[idx] += cnt
	}
	dp := make([]int, len(source)+1)
	for i := 0; i < len(dp); i++ {
		dp[i] = INF
	}
	dp[0] = 0
	for i := 1; i < len(dp); i++ {
		idx := i - 1
		if source[idx] == target[idx] {
			dp[i] = dp[i-1]
		}
		for moneyIdx, val := range rules {
			pattern, replacement := val[0], val[1]
			button := idx - len(pattern) + 1
			if button < 0 {
				continue
			}
			if !isMatch(source[button:i], pattern) {
				continue
			}
			flag := false
			if target[button:i] != replacement {
				flag = true
			}
			if flag {
				continue
			}
			dp[i] = min(dp[i], dp[i-len(pattern)]+costs[moneyIdx])
		}
	}
	if dp[len(dp)-1] != INF {
		return dp[len(dp)-1]
	}
	return -1
}
func isMatch(src string, dst string) bool {
	if len(src) != len(dst) {
		return false
	}
	for i := 0; i < len(src); i++ {
		if dst[i] == '*' {
			continue
		}
		if src[i] != dst[i] {
			return false
		}
	}
	return true
}
