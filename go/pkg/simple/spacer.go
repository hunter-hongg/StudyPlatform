package simple

import (
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
)

func Spacer(height int) fyne.CanvasObject {
	// 创建固定高度的空白区域（例如50像素高）
	fixedSpace := container.New(
		layout.NewGridWrapLayout(fyne.NewSize(1, float32(height))), // 强制宽度为1，高度为50像素
		canvas.NewRectangle(color.Transparent),
	)

	return fixedSpace
}
