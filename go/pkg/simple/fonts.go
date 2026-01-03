package simple

import (
	"image/color"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/theme"
)

type MyTheme struct {
    variant fyne.ThemeVariant
}

func NewMyTheme(variant fyne.ThemeVariant) *MyTheme {
    return &MyTheme{variant: variant}
}

func (m MyTheme) Font(style fyne.TextStyle) fyne.Resource {
    return theme.DefaultTheme().Font(style)
}

func (m MyTheme) Color(name fyne.ThemeColorName, variant fyne.ThemeVariant) color.Color {
    // 使用主题的 Variant 方法
    return theme.DefaultTheme().Color(name, m.variant)
}

func (m MyTheme) Icon(name fyne.ThemeIconName) fyne.Resource {
    return theme.DefaultTheme().Icon(name)
}

func (m MyTheme) Size(name fyne.ThemeSizeName) float32 {
    if name == theme.SizeNameText {
        return 20 // 自定义字体大小
    }
    return theme.DefaultTheme().Size(name)
}

// ✅ 关键：实现 Variant() 方法
func (m MyTheme) Variant() fyne.ThemeVariant {
    return m.variant
}