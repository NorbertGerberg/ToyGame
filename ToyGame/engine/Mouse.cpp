/*=========================================
	Copyright 2024-2025 Norbert Gerberg
=========================================*/
#include "Mouse.hpp"
#include "Console.hpp"

void eMouse::SetPositionCallback(NGE_MOUSE_POSCALLBACK callback)
{
	glfwSetCursorPosCallback(GetGLFWwindow(), callback);
}

void eMouse::GetPosition(real6& xpos, real6& ypos)
{
	glfwGetCursorPos(GetGLFWwindow(), &xpos, &ypos);
}

void eMouse::DisableCursor()
{
	glfwSetInputMode(GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void eMouse::HideCursor()
{
	glfwSetInputMode(GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

void eMouse::NormalCursor()
{
	glfwSetInputMode(GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void eMouse::CheckRawMouseMotionSupport()
{
	if (glfwRawMouseMotionSupported()) {
		eConsole::PrintLog("INFO::eMouse::CheckRawMouseMotionSupport", "Current machine does support raw mouse motion");
		glfwSetInputMode(GetGLFWwindow(), GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
		return;
	}
	eConsole::PrintLog("INFO::eMouse::CheckRawMouseMotionSupport", "Current machine does not support raw mouse motion");
	glfwSetInputMode(GetGLFWwindow(), GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
}

void eMouse::SetEnterCallback(NGE_MOUSE_ENTERCALLBACK& callback)
{
	glfwSetCursorEnterCallback(GetGLFWwindow(), callback);
}

const bool eMouse::IsHovering()
{
	return glfwGetWindowAttrib(GetGLFWwindow(), GLFW_HOVERED);
}

void eMouse::SetMouseButtonCallback(NGE_MOUSE_BUTTONCALLBACK& callback)
{
	glfwSetMouseButtonCallback(GetGLFWwindow(), callback);
}

const int eMouse::GetButtonState(const int button)
{
	return glfwGetMouseButton(GetGLFWwindow(), button);
}

void eMouse::SetStickyMode(const int vl)
{
	glfwSetInputMode(GetGLFWwindow(), GLFW_STICKY_MOUSE_BUTTONS, vl);
}

void eMouse::SetScrollCallback(NGE_MOUSE_SCROLLCALLBACK& callback)
{
	glfwSetScrollCallback(GetGLFWwindow(), callback);
}

const bool eMouse::GetButtonPressed(const int key)
{
	if (glfwGetMouseButton(GetGLFWwindow(), key) == GLFW_PRESS)
		return true;
	return false;
}

const bool eMouse::GetButtonReleased(const int key)
{
	if (glfwGetMouseButton(GetGLFWwindow(), key) == GLFW_RELEASE)
		return true;
	return false;
}