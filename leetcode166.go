package main

import (
	"strconv"
)

func fractionToDecimal(numerator int, denominator int) string {
	// true is < 0
	var flag bool = false
	if numerator*denominator < 0 {
		flag = true
	}
	abs := func(x int) int {
		if x < 0 {
			return -x
		}
		return x
	}
	numerator, denominator = abs(numerator), abs(denominator)
	vis := make(map[int]bool)
	if temp := numerator % denominator; temp == 0 {
		if flag {

			return "-" + strconv.Itoa(numerator/denominator)
		}
		return strconv.Itoa(numerator / denominator)
	}
	preDot := strconv.Itoa(numerator / denominator)
	behindDot := ""
	cur := numerator % denominator
	cur = cur * 10
	for {
		if vis[cur] {
			break
		}
		vis[cur] = true
		behindDot = behindDot + strconv.Itoa(cur/denominator)
		if (cur % denominator) == 0 {
			if flag {
				return "-" + preDot + "." + behindDot
			}
			return preDot + "." + behindDot
		}
		cur = cur % denominator
		cur = cur * 10
	}
	vis = make(map[int]bool)
	loop := ""
	for {
		if vis[cur] {
			break
		}
		vis[cur] = true
		loop = loop + strconv.Itoa(cur/denominator)
		cur = cur % denominator
		cur = cur * 10
	}
	if flag {

		return "-" + preDot + "." + behindDot[0:len(behindDot)-len(loop)] + "(" + loop + ")"
	}
	return preDot + "." + behindDot[0:len(behindDot)-len(loop)] + "(" + loop + ")"
}
