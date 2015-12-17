/*
    nanogui/window.h -- Top-level window widget

    NanoGUI was developed by Wenzel Jakob <wenzel@inf.ethz.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

NAMESPACE_BEGIN (nanogui)

class  Window : public Widget
{
      friend class Popup;
   public:
      Window (Widget * parent, const std::string & title = "Untitled");

      /// Return the window title
      const std::string & title() const
      {
         return mTitle;
      }
      /// Set the window title
      void setTitle (const std::string & title)
      {
         mTitle = title;
      }

      /// Is this a model dialog?
      bool modal() const
      {
         return mModal;
      }
      /// Set whether or not this is a modal dialog
      void setModal (bool modal)
      {
         mModal = modal;
      }

      /// Dispose the window
      void dispose();

      /// Center the window in the current \ref Screen
      void center();

      /// Draw the window
      virtual void draw (NVGcontext * ctx);

      /// Handle window drag events
      virtual bool mouseDragEvent (const ivec2 & p, const ivec2 & rel, int button, int modifiers);
      /// Handle mouse events recursively and bring the current window to the top
      virtual bool mouseButtonEvent (const ivec2 & p, int button, bool down, int modifiers);
      /// Accept scroll events and propagate them to the widget under the mouse cursor
      virtual bool scrollEvent (const ivec2 & p, const vec2 & rel);
      /// Compute the preferred size of the widget
      virtual ivec2 preferredSize (NVGcontext * ctx) const;
   protected:
      /// Internal helper function to maintain nested window position values; overridden in \ref Popup
      virtual void refreshRelativePlacement();
   protected:
      std::string mTitle;
      bool mModal;
      bool mDrag;
};

NAMESPACE_END (nanogui)