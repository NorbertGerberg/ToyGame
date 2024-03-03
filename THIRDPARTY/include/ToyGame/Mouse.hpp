/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#ifndef MOUSE_HPP
#define MOUSE_HPP
#include "Types.hpp"
#include "Input.hpp"

#define NGE_MOUSE_POSCALLBACK	 GLFWcursorposfun
#define NGE_MOUSE_ENTERCALLBACK	 GLFWcursorenterfun
#define NGE_MOUSE_BUTTONCALLBACK GLFWmousebuttonfun
#define NGE_MOUSE_SCROLLCALLBACK GLFWscrollfun

constexpr auto NGE_INPUT_CURSOR = 0x00033001;
constexpr auto NGE_INPUT_STICKY_MOUSE_BUTTONS = 0x00033003;
constexpr auto NGE_INPUT_RAW_MOUSE_MOTION = 0x00033005;
constexpr auto NGE_INPUT_CURSOR_NORMAL = 0x00034001;
constexpr auto NGE_INPUT_CURSOR_HIDDEN = 0x00034002;
constexpr auto NGE_INPUT_CURSOR_DISABLED = 0x00034003;

constexpr auto NGE_INPUT_MOUSE_BUTTON_1 = 0;
constexpr auto NGE_INPUT_MOUSE_BUTTON_2 = 1;
constexpr auto NGE_INPUT_MOUSE_BUTTON_3 = 2;
constexpr auto NGE_INPUT_MOUSE_BUTTON_4 = 3;
constexpr auto NGE_INPUT_MOUSE_BUTTON_5 = 4;
constexpr auto NGE_INPUT_MOUSE_BUTTON_6 = 5;
constexpr auto NGE_INPUT_MOUSE_BUTTON_7 = 6;
constexpr auto NGE_INPUT_MOUSE_BUTTON_8 = 7;
constexpr auto NGE_INPUT_MOUSE_BUTTON_LAST = 7;
constexpr auto NGE_INPUT_MOUSE_BUTTON_LEFT = 0;
constexpr auto NGE_INPUT_MOUSE_BUTTON_RIGHT = 1;
constexpr auto NGE_INPUT_MOUSE_BUTTON_MIDDLE = 2;

class eMouse : public eInput
{
public:
	void SetPositionCallback(NGE_MOUSE_POSCALLBACK callback);
	void GetPosition(real6& xpos, real6& ypos);
	void DisableCursor();
	void HideCursor();
	void NormalCursor();
	void CheckRawMouseMotionSupport();
	void SetEnterCallback(NGE_MOUSE_ENTERCALLBACK& callback);
	const bool IsHovering();
	void SetMouseButtonCallback(NGE_MOUSE_BUTTONCALLBACK& callback);
	const int GetButtonState(const int button);
	void SetStickyMode(const int vl);
	void SetScrollCallback(NGE_MOUSE_SCROLLCALLBACK& callback);
	const bool GetButtonPressed(const int key);
	const bool GetButtonReleased(const int key);
};
#endif