// https://reactnavigation.org/docs/material-top-tab-navigator

open Core
open ReactNative

type tabBarLabelOptions = {
  focused: bool,
  color: string,
}

type tabBarIconOptions = {
  focused: bool,
  color: string,
}

type options = {
  title?: string,
  tabBarLabel?: tabBarLabelOptions => React.element,
  tabBarAccessibilityLabel?: string,
  tabBarAllowFontScaling?: bool,
  tabBarShowLabel?: bool,
  tabBarIcon?: tabBarIconOptions => React.element,
  tabBarShowIcon?: bool,
  tabBarBadge?: unit => React.element,
  tabBarIndicator?: unit => React.element,
  tabBarIndicatorStyle?: Style.t,
  tabBarIndicatorContainerStyle?: Style.t,
  tabBarButtonTestID?: string,
  tabBarActiveTintColor?: string,
  tabBarInactiveTintColor?: string,
  tabBarPressColor?: string,
  tabBarPressOpacity?: float,
  tabBarBounces?: bool,
  tabBarScrollEnabled?: bool,
  tabBarIconStyle?: Style.t,
  tabBarLabelStyle?: Style.t,
  tabBarItemStyle?: Style.t,
  tabBarContentContainerStyle?: Style.t,
  tabBarStyle?: Style.t,
  animationEnabled?: bool,
  swipeEnabled?: bool,
  \"lazy"?: bool,
  lazyPreloadDistance?: float,
  lazyPlaceholder?: unit => React.element,
  sceneStyle?: Style.t,
}

type tabBarPosition = [#top | #bottom]

type keyboardDismissMode = [#auto | #"on-drag" | #none]

// TODO: outdated
type tabBarProps = {
  scrollEnabled?: bool,
  pressColor?: string,
  pressOpacity?: float,
  //TODO: render: https://github.com/react-native-community/react-native-tab-view/blob/64e03bf14b0fac9c3bccd684bf31a04ecf19c50d/src/TabBar.tsx#L38-L51
  tabStyle?: Style.t,
  indicatorStyle?: Style.t,
  labelStyle?: Style.t,
  style?: Style.t,
  renderIndicator?: React.component<{"route": route}>,
  activeTintColor?: string,
  inactiveTintColor?: string,
  iconStyle?: Style.t,
  showLabel?: bool,
  showIcon?: bool,
  allowFontScaling?: bool,
  // ----
  state: navigationState,
  navigation: navigation,
  descriptors: descriptors,
  // SceneRendererProps from react-native-tab-view
  layout: layout,
  position: Animated.Value.t,
  jumpTo: string => unit,
}

module type NavigatorModule = {
  module Navigator: {
    @react.component
    let make: (
      ~id: string=?,
      ~initialRouteName: string=?,
      ~screenOptions: screenOptionsParams => options=?,
      ~backBehavior: backBehavior=?,
      ~tabBarPosition: tabBarPosition=?,
      ~keyboardDismissMode: keyboardDismissMode=?,
      ~initialLayout: layout=?,
      ~style: Style.t=?,
      ~tabBar: tabBarProps => React.element=?,
      ~layout: layoutNavigatorParams => React.element=?,
      ~children: React.element,
    ) => React.element
  }

  module Screen: {
    @react.component
    let make: (
      ~name: string,
      ~navigationKey: string=?,
      ~options: screenOptionsParams => options=?,
      ~initialParams: 'params=?,
      ~getId: getIdOptions => option<string>=?,
      ~component: React.component<screenProps>=?,
      ~getComponent: unit => React.component<screenProps>=?,
      ~children: screenProps => React.element=?,
    ) => React.element
  }

  module Group: {
    @react.component
    let make: (
      ~navigationKey: string=?,
      ~screenOptions: screenOptionsParams => options=?,
    ) => React.element
  }
}

type navigatorModule

%%private(
  @module("@react-navigation/material-top-tabs")
  external createMaterialTopTabNavigator: unit => navigatorModule = "createMaterialTopTabNavigator"

  @module("./Interop")
  external adaptNavigatorModule: navigatorModule => module(NavigatorModule) = "adaptNavigatorModule"
)

module Make = () => unpack(createMaterialTopTabNavigator()->adaptNavigatorModule)

module Navigation = {
  @send
  external setOptions: (navigation, options) => unit = "setOptions"

  @send external jumpTo: (navigation, string) => unit = "jumpTo"
  @send
  external jumpToWithParams: (navigation, string, 'params) => unit = "jumpTo"

  @send
  external addEventListener: (
    navigation,
    @string
    [
      | #tabPress(navigationEvent<unit> => unit)
    ],
  ) => unsubscribe = "addListener"
}
