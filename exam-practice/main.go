package main

import "fmt"

func main() {

	array := []int{
		43, 12, 4, 3, 11, 234, 23, 54,
	}

	fmt.Println(gcd(21, 12))
	fmt.Println(fib(7))

	bubblesort(array)
	selectionsort(array)
	insertionsort(array)

	fmt.Println(linearsearch(array, 54))

}

func fib(n int) int {

	a := 0
	b := 1
	temp := 0

	for i := 1; i < n; i++ {
		temp = a + b
		a = b
		b = temp
	}

	return temp

}

func gcd(a, b int) int {
	if a == 0 || b == 0 {
		return 1
	}

	for b != 0 {
		temp := a % b
		a = b
		b = temp
	}
	return a
}

func bubblesort(array []int) {

	n := len(array)

	for i := range n - 1 {
		for j := range n - i - 1 {
			if array[j] > array[j+1] {
				array[j+1], array[j] = array[j], array[j+1]
			}
		}
	}
	fmt.Println(array)
}

func selectionsort(array []int) {
	n := len(array)

	for index, value := range array {
		smallest_index := index
		smallest_value := value

		for i := index; i < n; i++ {
			if array[i] < smallest_value {
				smallest_index = i
				smallest_value = array[i]
			}
		}

		if smallest_index != index {
			array[smallest_index], array[index] = array[index], array[smallest_index]
		}

	}
	fmt.Println(array)

}

func insertionsort(array []int) {
	n := len(array)

	for i := range n {
		temp := array[i]
		j := i - 1

		for j >= 0 && array[j] > temp {
			array[j+1] = array[j]
			j = j - 1
		}
		array[j+1] = temp
	}
	fmt.Println(array)
}

func linearsearch(items []int, item int) int {
	for i, v := range items {
		if v == item {
			return i
		}
	}
	return -1
}
