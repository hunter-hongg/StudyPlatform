package util

type AddAble interface {
	AddNum(an int) error
}
type ReadAble interface {
	ReadStr() (string, error)
	ReadInt() (int, error)
}