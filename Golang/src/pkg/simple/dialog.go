package simple

import (
	"fyne.io/fyne/v2/dialog"
	"fyne.io/fyne/v2"
)

func DialogInfo(show string, window fyne.Window) {
	dialog.ShowInformation("Info", show, window)
}
func DialogError(show error, window fyne.Window) {
	dialog.ShowError(show, window)
}

