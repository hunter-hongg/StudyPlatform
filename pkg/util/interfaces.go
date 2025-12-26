package util

type AddAble interface {
	AddNum(an int) error
}
type ReadAble interface {
	ReadStrSafe() int
	ReadIntSafe() string
}
type MinusAble interface {
	CanMinusSafe(an int) bool
}