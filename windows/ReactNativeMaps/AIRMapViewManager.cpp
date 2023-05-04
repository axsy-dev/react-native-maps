#include "pch.h"
#include "AIRMapViewManager.h"

using namespace winrt::Windows::UI::Xaml::Controls;

namespace winrt::ReactNativeMaps
{

    // AIRMapViewManager::AIRMapViewManager() {}

    // IViewManager
    winrt::hstring AIRMapViewManager::Name() noexcept { return L"AIRMap"; }

    xaml::FrameworkElement AIRMapViewManager::CreateView() noexcept
    {
        return Maps::MapControl();
    }

    // IViewManagerWithChildren
    void AIRMapViewManager::AddView(xaml::FrameworkElement const &parent,
                                    xaml::UIElement const &child,
                                    int64_t index) noexcept
    {
        if (auto const &panel = parent.try_as<Maps::MapControl>())
        {
            panel.Children().InsertAt(static_cast<uint32_t>(index), child);
        }
    }

    void AIRMapViewManager::RemoveAllChildren(
        xaml::FrameworkElement const &parent) noexcept
    {
        if (auto const &panel = parent.try_as<Maps::MapControl>())
        {
            panel.Children().Clear();
        }
    }

    void AIRMapViewManager::RemoveChildAt(xaml::FrameworkElement const &parent,
                                          int64_t index) noexcept
    {
        if (auto const &panel = parent.try_as<Maps::MapControl>())
        {
            panel.Children().RemoveAt(static_cast<uint32_t>(index));
        }
    }

    void AIRMapViewManager::ReplaceChild(xaml::FrameworkElement const &parent,
                                         xaml::UIElement const &oldChild,
                                         xaml::UIElement const &newChild) noexcept
    {
        if (auto const &panel = parent.try_as<Maps::MapControl>())
        {
            uint32_t index;
            if (panel.Children().IndexOf(oldChild, index))
            {
                panel.Children().RemoveAt(index);
                panel.Children().InsertAt(index, newChild);
            }
        }
    }

    // IViewManagerWithReactContext
    React::IReactContext AIRMapViewManager::ReactContext() noexcept
    {
        return m_reactContext.Handle();
    }

    void AIRMapViewManager::ReactContext(React::IReactContext reactContext) noexcept
    {
        m_reactContext = reactContext;
    }

    // IViewManagerWithNativeProperties
    Collections::IMapView<winrt::hstring, React::ViewManagerPropertyType> AIRMapViewManager::NativeProps() noexcept
    {
        auto nativeProps = winrt::single_threaded_map<winrt::hstring, React::ViewManagerPropertyType>();
        nativeProps.Insert(L"customMapStyleString", React::ViewManagerPropertyType::String);
        return nativeProps.GetView();
    }

    void AIRMapViewManager::UpdateProperties(xaml::FrameworkElement const &view, React::IJSValueReader const &propertyMapReader) noexcept
    {
    }

} // namespace winrt::ReactNativeMaps