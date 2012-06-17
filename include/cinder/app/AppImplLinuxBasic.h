/*
 Copyright (c) 2010, The Barbarian Group
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "cinder/app/AppImplLinux.h"
#include "cinder/app/AppImplLinuxRenderer.h"
#include "cinder/Display.h"

namespace cinder { namespace app {

class AppImplLinuxBasic : public AppImplLinux {
 public:
	AppImplLinuxBasic( class AppBasic *aApp  );
	void	run();

	class AppBasic*		getApp() { return mApp; }

	void	quit() { mShouldQuit = true; }

	void	setWindowWidth( int aWindowWidth );
	void	setWindowHeight( int aWindowHeight );
	void	setWindowSize( int aWindowWidth, int aWindowHeight );
	float	setFrameRate( float aFrameRate );
	void	toggleFullScreen();

	std::string getAppPath() const;

	Display*	getDisplay() { return mDisplay; }
	Window		getXWindow() { return mWin; }

 protected:
	bool		createWindow( int *width, int *height );
	void		killWindow( bool wasFullScreen );

	unsigned int	prepModifiers( unsigned int state );

	bool		mShouldQuit;
	bool		mIsDragging;
	bool		mHasBeenInitialized;
	class AppBasic	*mApp;

	// Linux window variables
	Window		mWin;
	Atom		mAtomDeleteWindow;
	Vec2i		mWindowedPos;

	double				mNextFrameTime;
	Display				*mDisplay;
};

} } // namespace cinder::app
