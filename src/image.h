#ifndef IMAGE_H
#define IMAGE_H

class Image
{
private:
    const DWORD XSzPic;
    const DWORD YSzPic;
    HDC picture;
public:
    inline Image();
    inline Image(const DWORD XSzImg, const DWORD YSzImg, const LPCSTR file_name);
    inline Image(const LPCSTR file_name);
    inline Image(const Image &image);
    inline ~Image();
    inline VOID draw   (const DWORD XCrdOnWn, const DWORD YCrdOnWn,
                const DWORD XSzeOnWn, const DWORD YSzeOnWn,
                const DWORD XCrdOnPc, const DWORD YCrdOnPc,
                const DWORD XSzeOnPc, const DWORD YSzeOnPc,
                COLORREF TrnsClr);

};

inline Image::Image() :
XSzPic(0), YSzPic(0), picture(nullptr)
{
}

inline Image::Image(const DWORD XSzImg, const DWORD YSzImg, const LPCSTR file_name) :
XSzPic(XSzImg), YSzPic(YSzImg), picture(txLoadImage(file_name))
{
    if(!picture)
    {
        txMessageBox("[image.h  23-33] Pic does not loaded!");
        exit(0);
    }
}

inline Image::Image(const LPCSTR file_name) :
XSzPic(0), YSzPic(0), picture(txLoadImage(file_name))
{
    if(!picture)
    {
        txMessageBox("[image.h  23-33] Pic does not loaded!");
        exit(0);
    }
}

inline Image::Image(const Image &image) :
    XSzPic(image.XSzPic), YSzPic(image.YSzPic), picture(nullptr)
{
    *picture = *(image.picture);
}

inline Image::~Image()
{
    txDeleteDC(picture);
}

inline VOID Image::draw(
                const DWORD XCrdOnWn,
                const DWORD YCrdOnWn,
                const DWORD XSzeOnWn,
                const DWORD YSzeOnWn,
                const DWORD XCrdOnPc,
                const DWORD YCrdOnPc,
                const DWORD XSzeOnPc,
                const DWORD YSzeOnPc,
                COLORREF TrnsClr
                )
{
    Win32::TransparentBlt(txDC(), XCrdOnWn, YCrdOnWn, XSzeOnWn, YSzeOnWn,
                        picture, XCrdOnPc, YCrdOnPc, XSzeOnPc, YSzeOnPc, TrnsClr);

}
#endif //IMAGE_H
