/*
    nanogui/slider.h -- Fractional slider widget with mouse control

    NanoGUI was developed by Wenzel Jakob <wenzel@inf.ethz.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/

#pragma once

NAMESPACE_BEGIN (nanogui)

class  Slider : public Widget
{
   public:
      Slider (Widget * parent);

      float value() const
      {
         return mValue;
      }
      void setValue (float value)
      {
         mValue = value;
      }

      const Colour & highlightColor() const
      {
         return mHighlightColor;
      }
      void setHighlightColor (const Colour & highlightColor)
      {
         mHighlightColor = highlightColor;
      }

      std::pair<float, float> highlightedRange() const
      {
         return mHighlightedRange;
      }
      void setHighlightedRange (std::pair<float, float> highlightedRange)
      {
         mHighlightedRange = highlightedRange;
      }

      std::function<void (float)> callback() const
      {
         return mCallback;
      }
      void setCallback (const std::function<void (float)> & callback)
      {
         mCallback = callback;
      }

      std::function<void (float)> finalCallback() const
      {
         return mFinalCallback;
      }
      void setFinalCallback (const std::function<void (float)> & callback)
      {
         mFinalCallback = callback;
      }

      virtual ivec2 preferredSize (NVGcontext * ctx) const;
      virtual bool mouseDragEvent (const ivec2 & p, const ivec2 & rel, int button, int modifiers);
      virtual bool mouseButtonEvent (const ivec2 & p, int button, bool down, int modifiers);
      virtual void draw (NVGcontext * ctx);

   protected:
      float mValue;
      std::function<void (float)> mCallback;
      std::function<void (float)> mFinalCallback;
      std::pair<float, float> mHighlightedRange;
      Colour mHighlightColor;
};

NAMESPACE_END (nanogui)
