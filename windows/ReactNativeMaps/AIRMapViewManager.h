#pragma once

#include "pch.h"
#include "NativeModules.h"
#include "winrt/Microsoft.ReactNative.h"

namespace winrt::ReactNativeMaps
{

  class AIRMapViewManager : public winrt::implements<AIRMapViewManager, React::IViewManager,
                                                     React::IViewManagerWithChildren,
                                                     React::IViewManagerWithReactContext,
                                                     React::IViewManagerWithNativeProperties>
  {
  public:
    // AIRMapViewManager();

    // IViewManager
    winrt::hstring Name() noexcept;
    xaml::FrameworkElement CreateView() noexcept;

    // IViewManagerWithChildren
    void AddView(xaml::FrameworkElement const &parent, xaml::UIElement const &child,
                 int64_t index) noexcept;
    void RemoveAllChildren(xaml::FrameworkElement const &parent) noexcept;
    void RemoveChildAt(xaml::FrameworkElement const &parent, int64_t index) noexcept;
    void ReplaceChild(xaml::FrameworkElement const &parent, xaml::UIElement const &oldChild,
                      xaml::UIElement const &newChild) noexcept;

    // IViewManagerWithReactContext
    winrt::Microsoft::ReactNative::IReactContext ReactContext() noexcept;
    void ReactContext(winrt::Microsoft::ReactNative::IReactContext reactContext) noexcept;

    // IViewManagerWithNativeProperties
    Collections::IMapView<winrt::hstring, React::ViewManagerPropertyType> NativeProps() noexcept;
    void UpdateProperties(xaml::FrameworkElement const &view, React::IJSValueReader const &propertyMapReader) noexcept;

  private:
    winrt::Microsoft::ReactNative::IReactContext m_reactContext{nullptr};
  };

} // namespace winrt::ReactNativeMaps
