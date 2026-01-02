package simple

import (
	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/layout"
)

func HorizonCenter(obj fyne.CanvasObject) *fyne.Container {
    horizontalCenter := container.NewHBox(
        layout.NewSpacer(), 
        obj,               
        layout.NewSpacer(),
    )
    
	return horizontalCenter
}

func HorizonRight(obj fyne.CanvasObject) *fyne.Container {
    horizontalCenter := container.NewHBox(
        layout.NewSpacer(),
        obj,               
    )
    
	return horizontalCenter
}

func HorizonLeft(obj fyne.CanvasObject) *fyne.Container {
    horizontalCenter := container.NewHBox(
        obj,               
        layout.NewSpacer(),
    )
    
	return horizontalCenter
}

func HorizonLeftHalf(obj fyne.CanvasObject) *fyne.Container {
	return container.New(
		layout.NewGridLayoutWithColumns(2),
		obj,
		layout.NewSpacer(), 
	)
}
