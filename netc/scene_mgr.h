#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include <memory>
#include "xml_config.h"
#include "../common/random.h"

#include "glbase.h"
#include "sungui.h"

namespace ygopro
{
    
    class Scene {
    public:
        virtual ~Scene() = default;
        virtual void Activate() = 0;
        virtual void Update() = 0;
        virtual void Draw() = 0;
        virtual void SetSceneSize(v2i sz) = 0;
        virtual recti GetScreenshotClip() = 0;
        virtual void MouseMove(sgui::MouseMoveEvent evt) = 0;
        virtual void MouseButtonDown(sgui::MouseButtonEvent evt) = 0;
        virtual void MouseButtonUp(sgui::MouseButtonEvent evt) = 0;
        virtual void KeyDown(sgui::KeyEvent evt) = 0;
        virtual void KeyUp(sgui::KeyEvent evt) = 0;
    };
    
    class SceneMgr {
    public:
        
        void Init();
        void Uninit();
        void InitDraw();
        void Update();
        void Draw();
        float GetGameTime();
        void SetFrameRate(float rate);
        void CheckFrameRate();
        void MouseMove(sgui::MouseMoveEvent evt);
        void MouseButtonDown(sgui::MouseButtonEvent evt);
        void MouseButtonUp(sgui::MouseButtonEvent evt);
        void KeyDown(sgui::KeyEvent evt);
        void KeyUp(sgui::KeyEvent evt);
        void SetSceneSize(v2i sz);
        void SetScene(std::shared_ptr<Scene> sc);
        void ScreenShot();
        std::shared_ptr<Scene> GetScene() { return current_scene; };
        void SetMousePosition(v2i pos) { mouse_pos = pos; }
        v2i GetMousePosition() { return mouse_pos; }
        
    protected:
        v2i scene_size;
        unsigned long long start_time = 0;
        std::shared_ptr<Scene> current_scene = nullptr;
        float frame_check = 0.0f;
        float frame_time = 0.0f;
        float frame_interval = 0.0f;
        v2i mouse_pos = {0, 0};
    };
    
    extern SceneMgr sceneMgr;
    extern Random globalRandom;
	extern CommonConfig commonCfg;
    extern CommonConfig stringCfg;
    
/*
    class wxGameCanvas;
    
    class GameFrame : public wxFrame {

        enum {
            ID_DECK_LOAD = wxID_HIGHEST + 1,
            ID_DECK_SAVE,
            ID_DECK_SAVEAS,
            ID_DECK_LOADSTR,
            ID_DECK_SAVESTR,
            ID_TOOL_CLEAR,
            ID_TOOL_SORT,
            ID_TOOL_SHUFFLE,
            ID_TOOL_SCREENSHOT,
            ID_TOOL_SCREENSHOT_SV,
            ID_TOOL_SEARCH,
            ID_TOOL_BROWSER,
            ID_TOOL_SHOWEXCLUSIVE,
            ID_REG_VIEW1,
            ID_REG_VIEW2,
            ID_REG_VIEW3,
            ID_REGULATION,
            ID_REGULATION_END = ID_REGULATION + 100,
            ID_MENUEND,
            ID_RTC_CARD,
        };

    public:
        GameFrame(int sx, int sy);
        ~GameFrame();

        void SetCardInfo(unsigned int code);
        void AddCard(unsigned int code, unsigned int pos);
        void StopViewRegulation() { view_regulation = 0; }
        
        void OnDeckLoad(wxCommandEvent& evt);
        void OnDeckSave(wxCommandEvent& evt);
        void OnDeckSaveAs(wxCommandEvent& evt);
        void OnDeckLoadString(wxCommandEvent& evt);
        void OnDeckSaveString(wxCommandEvent& evt);

        void OnToolClear(wxCommandEvent& evt);
        void OnToolSort(wxCommandEvent& evt);
        void OnToolShuffle(wxCommandEvent& evt);
        void OnToolScreenshot(wxCommandEvent& evt);
        void OnToolScreenshotSV(wxCommandEvent& evt);
        void OnToolSearch(wxCommandEvent& evt);
        void OnToolOpenBrowser(wxCommandEvent& evt);
        void OnToolSwitchExclusive(wxCommandEvent& evt);
        void OnToolViewRegulation(wxCommandEvent& evt);

        void OnRegulationChange(wxCommandEvent& evt);
        
        void OnUrlClicked(wxTextUrlEvent& evt);
        
    private:
        wxString current_file;
        wxGameCanvas* game_canvas;
        wxStaticBitmap* card_image;
        wxRichTextCtrl* card_info;
        wxImage star_img;
        int view_regulation = 0;
    };
*/
}

#endif //_GAME_SCENE_H_