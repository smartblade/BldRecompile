#include "RasterDevice.h"
#include "raster_int.h"


/*
* Module:                 Raster.dll
* Entry point:            0x10003550
*/

void Cls(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003574
*/

void SwapBuffers()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003589
*/

long BmpHandle(const char *bmpName)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035A3
*/

const char *BmpName(long handle)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035BD
*/

int nTextures()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035D2
*/

int GetTextureInfo(int index, int &w, int &h, int &depth)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035F8
*/

void SetFlags(long flags)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003612
*/

void SetVideoSettings(float gamma, float contrast, float brightness)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003633
*/

void SetGammaCorrection(float gamma)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000364D
*/

float GetGammaCorrection()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003662
*/

void SetContrast(float contrast)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000367C
*/

float GetContrast()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003691
*/

void SetBrightness(float brightness)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036AB
*/

float GetBrightness()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036C0
*/

void SetTextMode(int text_mode)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036DD
*/

int GetTextMode()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036F5
*/

void SetTextScale(float scale_x, float scale_y)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003716
*/

void GetTextScale(float &scale_x, float &scale_y)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003737
*/

void Line(int x1, int y1, int x2, int y2)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003760
*/

void LineTo(int x, int y)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003781
*/

void Rectangle(int x1, int y1, int x2, int y2)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037AA
*/

void SolidRectangle(int x1, int y1, int x2, int y2)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037D3
*/

void SetPosition(float x, float y)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037F4
*/

void GetPosition(float &x, float &y)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003815
*/

void set_pen_color(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003839
*/

void set_fill_color(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000385D
*/

void set_alpha(float alpha)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000387A
*/

void set_text_blur_color(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000389E
*/

void set_text_blur_alpha(float alpha)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100038BB
*/

float get_text_blur_alpha()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100038D3
*/

void SetTextBlur(int blurLeft, int blurTop, int blurRight, int blurBottom)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100038FC
*/

void GetTextBlur(
        int &blurLeft, int &blurTop, int &blurRight, int &blurBottom
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003925
*/

void SetTextShadow(int x_shadow, int y_shadow)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003946
*/

void GetTextShadow(int &x_shadow, int &y_shadow)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003967
*/

float get_alpha()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000397F
*/

void set_text_color(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039A3
*/

void set_text_alpha(float alpha)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039C0
*/

float get_text_alpha()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039D8
*/

int WriteText(const char *text)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039F5
*/

void SysWrite(int x, int y, const char *text, byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003A25
*/

int GetImage(
        int x, int y, int w, int h, const char *color_style,
        const char *stretch_or_centered, int image_size, long image_data
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003A5E
*/

void DrawImage(
        int w, int h, const char *color_style, const char *is_normal,
        const void * image_data
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003A8B
*/

void SetBackgroundImage(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003ABB
*/

void RemoveBackgroundImage()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003ADC
*/

void DrawBitmap(long handle, int w, int h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B00
*/

void SetClipWindow(int x, int y, int w, int h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B29
*/

void GetClipWindow(int &x, int &y, int &w, int &h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B52
*/

int SetRasterParameter(const char *parameter, const char *value)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B73
*/

const char *GetRasterParameter(const char *parameter)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B90
*/

void SetClipActive(int clip_active)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003BAD
*/

int GetClipActive()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003BC5
*/

void GetSize(int &w, int &h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003BE6
*/

int SetWindowSize(int w, int h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003C07
*/

int GetWindowSize(int &w, int &h)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003C28
*/

int FullScreen()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003C40
*/

int nVideoModes()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003C58
*/

int GetVideoModeDscr(
        int mode_index, int &depth, int &w, int &h, int &flags,
        int &frequency
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003C88
*/

int SetVideoMode(int mode_index)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003CCE
*/

int GetCurrentMode(
        int &depth, int &w, int &h, int &flags,
        int &frequency
)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003CFB
*/

const char *ClassIdName()
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003D13
*/

void SetFont(long font_pointer)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003D30
*/

void SetDomeColor(byte r, byte g, byte b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003D54
*/

void GetDomeColor(byte &r, byte &g, byte &b)
{
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003DA6
*/

void UnifyRenderBuffers()
{
}
