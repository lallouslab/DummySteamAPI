#ifndef ISTEAMHTMLSURFACE003_H
#define ISTEAMHTMLSURFACE003_H 1

#include "steam.h"

#include "ISteamHTMLSurface.h"

#define STEAMHTMLSURFACE_INTERFACE_VERSION_003 "STEAMHTMLSURFACE_INTERFACE_VERSION_003"

struct ISteamHTMLSurface003Vtbl
{
	void *DestructISteamHTMLSurface;
	void *Init;
	void *Shutdown;
	void *CreateBrowser;
	void *RemoveBrowser;
	void *LoadURL;
	void *SetSize;
	void *StopLoad;
	void *Reload;
	void *GoBack;
	void *GoForward;
	void *AddHeader;
	void *ExecuteJavascript;
	void *MouseUp;
	void *MouseDown;
	void *MouseDoubleClick;
	void *MouseMove;
	void *MouseWheel;
	void *KeyDown;
	void *KeyUp;
	void *KeyChar;
	void *SetHorizontalScroll;
	void *SetVerticalScroll;
	void *SetKeyFocus;
	void *ViewSource;
	void *CopyToClipboard;
	void *PasteFromClipboard;
	void *Find;
	void *StopFind;
	void *GetLinkAtPosition;
	void *SetCookie;
	void *SetPageScaleFactor;
	void *SetBackgroundMode;
	void *AllowStartRequest;
	void *JSDialogResponse;
	void *FileLoadDialogResponse;
};

struct ISteamHTMLSurface *SteamHTMLSurface003(void);

#endif /* ISTEAMHTMLSURFACE003_H */
