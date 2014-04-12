#pragma once

#include "BsEditorPrerequisites.h"
#include "BsGUIToggle.h"
#include "BsGUIToggleGroup.h"
#include "BsImageSprite.h"
#include "boost/signal.hpp"

namespace BansheeEditor
{
	class GUITabButton : public BS::GUIToggle
	{
	public:
		static const CM::String& getGUITypeName();

		static GUITabButton* create(const BS::GUIToggleGroupPtr& toggleGroup, CM::UINT32 index, const CM::HString& text, const BS::GUIElementStyle* style = nullptr);
		static GUITabButton* create(const BS::GUIToggleGroupPtr& toggleGroup, CM::UINT32 index, const CM::HString& text, const BS::GUIOptions& layoutOptions, const BS::GUIElementStyle* style = nullptr);
	
		static GUITabButton* create(const BS::GUIToggleGroupPtr& toggleGroup, CM::UINT32 index, const BS::GUIContent& content, const BS::GUIElementStyle* style = nullptr);
		static GUITabButton* create(const BS::GUIToggleGroupPtr& toggleGroup, CM::UINT32 index, const BS::GUIContent& content, const BS::GUIOptions& layoutOptions, const BS::GUIElementStyle* style = nullptr);

		CM::UINT32 getIndex() const { return mIndex; }
		void _setDraggedState(bool active);

		boost::signal<void(CM::UINT32, const CM::Vector2I&)> onDragged;
		boost::signal<void(CM::UINT32, const CM::Vector2I&)> onDragEnd;
	protected:
		virtual bool mouseEvent(const BS::GUIMouseEvent& ev);

	private:
		CM::UINT32 mIndex;
		CM::Vector2I mDragStartPosition;
		bool mDraggedState;
		BS::GUIButtonState mInactiveState;

		static const CM::UINT32 DRAG_MIN_DISTANCE;

		GUITabButton(const BS::GUIElementStyle* style, const BS::GUIToggleGroupPtr& toggleGroup, CM::UINT32 index, const BS::GUIContent& content, const BS::GUILayoutOptions& layoutOptions);
	};
}