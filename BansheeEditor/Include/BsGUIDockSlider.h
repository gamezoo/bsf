#pragma once

#include "BsEditorPrerequisites.h"
#include "BsGUIButtonBase.h"
#include "BsDockManager.h"
#include "boost/signal.hpp"

namespace BansheeEditor
{
	class GUIDockSlider : public BS::GUIButtonBase
	{
	public:
		static const CM::String& getGUITypeName();

		static GUIDockSlider* create(bool horizontal, const BS::GUIElementStyle* style = nullptr);
		static GUIDockSlider* create(bool horizontal, const BS::GUIOptions& layoutOptions, const BS::GUIElementStyle* style = nullptr);

		boost::signal<void(const CM::Vector2I&)> onDragged;
	protected:
		virtual bool mouseEvent(const BS::GUIMouseEvent& ev);

		bool _hasCustomCursor(const CM::Vector2I position, BS::CursorType& type) const;
	private:
		CM::Vector2I mLastDragPosition;
		bool mHorizontal;
		bool mIsCursorSet;
		bool mDragInProgress;

		GUIDockSlider(bool horizontal, const BS::GUIElementStyle* style, const BS::GUILayoutOptions& layoutOptions);
	};
}