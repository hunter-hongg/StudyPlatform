package cgo

import "fmt"
/*
#cgo CFLAGS: -I../../cgo
#cgo LDFLAGS: -L../../lib -lRustRand
#include "RustRand.h"
*/
import "C"

type CGoRndEnum int
const (
	CGoRnd_IncludeRight CGoRndEnum = iota
	CGoRnd_ExcludeRight
)

func GetRnd(a, b int) int {
	return int(C.getrnd(C.int(a), C.int(b)))
}
func GetRndWithEnum(a, b int, flag CGoRndEnum) (res int, err error) {
	switch flag {
	case CGoRnd_IncludeRight:
		err = nil
		res = GetRnd(a, b)
		return 
	case CGoRnd_ExcludeRight:
		err = nil 
		res = GetRnd(a, b-1)
		return
	default:
		err = fmt.Errorf("Error flag")
		return
	}
}