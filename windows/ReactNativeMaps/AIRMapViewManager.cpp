#include "pch.h"
#include "AIRMapViewManager.h"
#include "JSValueReader.h"
#include "JSValueXaml.h"
#include "NativeModules.h"

using namespace winrt;
using namespace Microsoft::ReactNative;
using namespace winrt::Windows::UI::Xaml::Controls;

namespace winrt::ReactNativeMaps::implementation
{
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
        if (auto const &mapView = parent.try_as<Maps::MapControl>())
        {
            mapView.Children().InsertAt(static_cast<uint32_t>(index), child);
        }
    }

    void AIRMapViewManager::RemoveAllChildren(
        xaml::FrameworkElement const &parent) noexcept
    {
        if (auto const &mapView = parent.try_as<Maps::MapControl>())
        {
            mapView.Children().Clear();
        }
    }

    void AIRMapViewManager::RemoveChildAt(xaml::FrameworkElement const &parent,
                                          int64_t index) noexcept
    {
        if (auto const &mapView = parent.try_as<Maps::MapControl>())
        {
            mapView.Children().RemoveAt(static_cast<uint32_t>(index));
        }
    }

    void AIRMapViewManager::ReplaceChild(xaml::FrameworkElement const &parent,
                                         xaml::UIElement const &oldChild,
                                         xaml::UIElement const &newChild) noexcept
    {
        if (auto const &mapView = parent.try_as<Maps::MapControl>())
        {
            uint32_t index;
            if (mapView.Children().IndexOf(oldChild, index))
            {
                mapView.Children().RemoveAt(index);
                mapView.Children().InsertAt(index, newChild);
            }
        }
    }

    // IViewManagerWithReactContext
    IReactContext AIRMapViewManager::ReactContext() noexcept
    {
        return m_reactContext;
    }

    void AIRMapViewManager::ReactContext(IReactContext reactContext) noexcept
    {
        m_reactContext = reactContext;
    }

    // IViewManagerWithNativeProperties
    Collections::IMapView<winrt::hstring, React::ViewManagerPropertyType> AIRMapViewManager::NativeProps() noexcept
    {
        auto nativeProps = winrt::single_threaded_map<winrt::hstring, React::ViewManagerPropertyType>();
        return nativeProps.GetView();
    }

    void AIRMapViewManager::UpdateProperties(xaml::FrameworkElement const &view, React::IJSValueReader const &propertyMapReader) noexcept
    {
    }

} // namespace winrt::ReactNativeMaps