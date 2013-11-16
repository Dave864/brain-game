//|||||||||||||||||||||||||||||||||||||||||||||||

#ifndef OGRE_FRAMEWORK_H
#define OGRE_FRAMEWORK_H

//|||||||||||||||||||||||||||||||||||||||||||||||

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreOverlay.h>
#include <OgreOverlayElement.h>
#include <OgreOverlayManager.h>
#include <OgrePass.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include "OgreOggSoundPlugin.h"

#ifdef OGRE_STATIC_LIB
#  define OGRE_STATIC_GL
#  if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#    define OGRE_STATIC_Direct3D9
// dx10 will only work on vista, so be careful about statically linking
#    if OGRE_USE_D3D10
#      define OGRE_STATIC_Direct3D10
#    endif
#  endif
#  define OGRE_STATIC_CgProgramManager
#  ifdef OGRE_USE_PCZ
#    define OGRE_STATIC_PCZSceneManager
#    define OGRE_STATIC_OctreeZone
#  endif
#  if OGRE_VERSION >= 0x10800
#    if OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
#      define OGRE_IS_IOS 1
#    endif
#  else
#    if OGRE_PLATFORM == OGRE_PLATFORM_IPHONE
#      define OGRE_IS_IOS 1
#    endif
#  endif
#  ifdef OGRE_IS_IOS
#    undef OGRE_STATIC_CgProgramManager
#    undef OGRE_STATIC_GL
#    define OGRE_STATIC_GLES 1
#    ifdef OGRE_USE_GLES2
#      define OGRE_STATIC_GLES2 1
#      define USE_RTSHADER_SYSTEM
#      undef OGRE_STATIC_GLES
#    endif
#    ifdef __OBJC__
#      import <UIKit/UIKit.h>
#    endif
#  endif
#  include "OgreStaticPluginLoader.h"
#endif

#ifdef OGRE_IS_IOS
#   include <OISMultiTouch.h>
#endif

#include <SdkTrays.h>

using namespace Ogre;
using namespace OgreOggSound;

//|||||||||||||||||||||||||||||||||||||||||||||||

#ifdef OGRE_IS_IOS
class OgreFramework : public Ogre::Singleton<OgreFramework>, OIS::KeyListener, OIS::MultiTouchListener, OgreBites::SdkTrayListener
#else
class OgreFramework : public Ogre::Singleton<OgreFramework>, OIS::KeyListener, OIS::MouseListener, OgreBites::SdkTrayListener
#endif
{
public:
	OgreFramework();
	~OgreFramework();
    
#ifdef OGRE_IS_IOS
    bool initOgre(Ogre::String wndTitle, OIS::KeyListener *pKeyListener = 0, OIS::MultiTouchListener *pMouseListener = 0, Ogre::RenderTargetListener *pRenderTargetListener = 0);
#else
	bool initOgre(Ogre::String wndTitle, OIS::KeyListener *pKeyListener = 0, OIS::MouseListener *pMouseListener = 0, Ogre::RenderTargetListener *pRenderTargetListener = 0);
#endif
	void updateOgre(double timeSinceLastFrame);
	void moveCamera();
	void getInput();
    
    Ogre::String getMacBundlePath() const;
	bool requestOgreShutdown(){m_bShutDownOgre = true;}
	bool isOgreToBeShutDown()const{return m_bShutDownOgre;}
    
	bool keyPressed(const OIS::KeyEvent &keyEventRef);
	bool keyReleased(const OIS::KeyEvent &keyEventRef);
    
#ifdef OGRE_IS_IOS
	bool touchMoved(const OIS::MultiTouchEvent &evt);
	bool touchPressed(const OIS::MultiTouchEvent &evt);
	bool touchReleased(const OIS::MultiTouchEvent &evt);
	bool touchCancelled(const OIS::MultiTouchEvent &evt);
#else
	bool mouseMoved(const OIS::MouseEvent &evt);
	bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID id);
#endif
    void buttonHit(OgreBites::Button* button);
	
	Ogre::Root*                 m_pRoot;
	Ogre::RenderWindow*			m_pRenderWnd;
	Ogre::SceneManager*			m_pSceneMgrMain;
	Ogre::SceneManager*			m_pSceneMgrSide;
	Ogre::Camera*				m_pCameraMain;
	Ogre::Viewport*				m_pViewportMain;
	Ogre::Camera*				m_pCameraSide;
	Ogre::Viewport*				m_pViewportSide;
	Ogre::Log*                  m_pLog;
	Ogre::Timer*				m_pTimer;
	
	OIS::InputManager*			m_pInputMgr;
	OIS::Keyboard*				m_pKeyboard;
#ifdef OGRE_IS_IOS
	OIS::MultiTouch*			m_pMouse;
#else
	OIS::Mouse*					m_pMouse;
#endif
    
    Ogre::ResourceGroupManager* m_pResourceGroupMgr;
	Ogre::OverlayManager*		m_pOverlayMgr;
	Ogre::FontManager*          m_pFontMgr;
    Ogre::MaterialManager*      m_pMaterialMgr;
    
    OgreOggSound::OgreOggSoundManager* m_pSoundMgr;
    
	OgreBites::SdkTrayManager*  m_pTrayMgr;
protected:
    // Added for Mac compatibility
    Ogre::String                 m_ResourcePath;
    
private:
	OgreFramework(const OgreFramework&);
	OgreFramework& operator= (const OgreFramework&);
    
    Ogre::FrameEvent            m_FrameEvent;
	int                         m_iNumScreenShots;
    
	bool                        m_bShutDownOgre;
	
	Ogre::Vector3				m_TranslateVector;
	Ogre::Real                  m_MoveSpeed;
	Ogre::Degree				m_RotateSpeed;
	float                       m_MoveScale;
	Ogre::Degree				m_RotScale;
    
    OgreBites::Button*          m_quitButton;
    
#ifdef OGRE_STATIC_LIB
    Ogre::StaticPluginLoader    m_StaticPluginLoader;
#endif
};

//|||||||||||||||||||||||||||||||||||||||||||||||

#endif

//|||||||||||||||||||||||||||||||||||||||||||||||
