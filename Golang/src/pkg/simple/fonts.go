package simple

import (
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/theme"
)

type Font struct {
}

func (m Font) Font(style fyne.TextStyle) fyne.Resource {
    return theme.LightTheme().Font(style) 
}
func (m Font) Color(name fyne.ThemeColorName, variant fyne.ThemeVariant) color.Color {
    return theme.LightTheme().Color(name, variant)
}
func (m Font) Icon(name fyne.ThemeIconName) fyne.Resource {
    return theme.LightTheme().Icon(name)
}
func (m Font) Size(name fyne.ThemeSizeName) float32 {
    if name == theme.SizeNameText {
        return 20
    }
    return theme.LightTheme().Size(name)
}
