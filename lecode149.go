package main

func maxPoints(points [][]int) int {
	var res int = 0
	if len(points) == 0 {
		return 0
	}
	if len(points) == 1 {
		return 1
	}
	if len(points) == 2 {
		return 2
	}
	n := len(points)
	for i := 0; i < n; i++ {
		dx, dy := points[i][0], points[i][1]
		hash := make(map[int]map[int]int)
		for j := i + 1; j < n; j++ {
			x, y := points[j][0]-dx, points[j][1]-dy
			if x == 0 {
				if hash[x] == nil {
					hash[x] = make(map[int]int)
				}
				hash[0][1]++
				res = max(hash[0][1], res)
			} else if y == 0 {
				if hash[1] == nil {
					hash[1] = make(map[int]int)
				}
				hash[1][0]++
				res = max(hash[1][0], res)
			} else {
				if x < 0 {
					x, y = -x, -y
				}
				d := gcd(x, y)
				x, y = x/d, y/d
				if hash[x] == nil {
					hash[x] = make(map[int]int)
				}
				hash[x][y]++
				res = max(hash[x][y], res)
			}
		}
	}
	return res + 1
}
func gcd(a, b int) int {
	if a < 0 {
		a = -a
	}
	if b < 0 {
		b = -b
	}
	if a == 0 {
		return b
	}
	if b == 0 {
		return a
	}
	if a > b {
		a, b = b, a
	}
	return gcd(a, b%a)
}
