package main

func evalRPN(tokens []string) int {
	atoi := func(str string) int {
		if len(str) == 0 {
			return 0
		}
		var res int = 0
		for _, ch := range str {
			x := int(ch - '0')
			res = res*10 + x
		}
		return res
	}
	if len(tokens) == 1 {
		return atoi(tokens[0])
	}
	push_back := func(stk *[]int, val int) int {
		if stk == nil {
			return 1
		}
		*stk = append(*stk, val)
		return 0
	}
	pop_back := func(stk *[]int) int {
		res := (*stk)[len(*stk)-1]
		*stk = (*stk)[0 : len(*stk)-1]
		return res
	}
	var stk []int
	for _, x := range tokens {
		if x == "+" {
			b, a := pop_back(&stk), pop_back(&stk)
			push_back(&stk, a+b)
		} else if x == "-" {
			b, a := pop_back(&stk), pop_back(&stk)
			push_back(&stk, a-b)

		} else if x == "*" {
			b, a := pop_back(&stk), pop_back(&stk)
			push_back(&stk, a*b)

		} else if x == "/" {
			b, a := pop_back(&stk), pop_back(&stk)
			push_back(&stk, a/b)

		} else {
			if x[0] == '-' {
				x = x[1:len(x)]
				push_back(&stk, -atoi(x))
				continue
			}
			push_back(&stk, atoi(x))
		}
	}
	return stk[0]
}
