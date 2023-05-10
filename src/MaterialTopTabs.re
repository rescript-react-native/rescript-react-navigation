// https://reactnavigation.org/docs/material-top-tab-navigator

open Core;
open ReactNative;

type tabBarLabelOptions = {
  focused: bool,
  color: string,
};

type tabBarIconOptions = {
  focused: bool,
  color: string,
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  tabBarLabel: tabBarLabelOptions => React.element,
  [@bs.optional]
  tabBarAccessibilityLabel: string,
  [@bs.optional]
  tabBarAllowFontScaling: bool,
  [@bs.optional]
  tabBarShowLabel: bool,
  [@bs.optional]
  tabBarIcon: tabBarIconOptions => React.element,
  [@bs.optional]
  tabBarShowIcon: bool,
  [@bs.optional]
  tabBarBadge: unit => React.element,
  [@bs.optional]
  tabBarIndicator: unit => React.element,
  [@bs.optional]
  tabBarIndicatorStyle: Style.t,
  [@bs.optional]
  tabBarIndicatorContainerStyle: Style.t,
  [@bs.optional]
  tabBarTestID: string,
  [@bs.optional]
  tabBarActiveTintColor: string,
  [@bs.optional]
  tabBarInactiveTintColor: string,
  [@bs.optional]
  tabBarPressColor: string,
  [@bs.optional]
  tabBarPressOpacity: float,
  [@bs.optional]
  tabBarBounces: bool,
  [@bs.optional]
  tabBarScrollEnabled: bool,
  [@bs.optional]
  tabBarIconStyle: Style.t,
  [@bs.optional]
  tabBarLabelStyle: Style.t,
  [@bs.optional]
  tabBarItemStyle: Style.t,
  [@bs.optional]
  tabBarContentContainerStyle: Style.t,
  [@bs.optional]
  tabBarStyle: Style.t,
  [@bs.optional]
  animationEnabled: bool,
  [@bs.optional]
  swipeEnabled: bool,
  [@bs.optional] [@bs.as "lazy"]
  lazy_: bool,
  [@bs.optional]
  lazyPreloadDistance: float,
  [@bs.optional]
  lazyPlaceholder: unit => React.element,
};

[@bs.deriving jsConverter]
type tabBarPosition = [ | `top | `bottom];

[@bs.deriving jsConverter]
type keyboardDismissMode = [ | `auto | [@bs.as "on-drag"] `on_drag | `none];

// TODO: outdated
[@bs.deriving abstract]
type tabBarProps = {
  [@bs.optional]
  scrollEnabled: bool,
  [@bs.optional]
  pressColor: string,
  [@bs.optional]
  pressOpacity: float,
  //TODO: render: https://github.com/react-native-community/react-native-tab-view/blob/64e03bf14b0fac9c3bccd684bf31a04ecf19c50d/src/TabBar.tsx#L38-L51
  [@bs.optional]
  tabStyle: Style.t,
  [@bs.optional]
  indicatorStyle: Style.t,
  [@bs.optional]
  labelStyle: Style.t,
  [@bs.optional]
  style: Style.t,
  /* TODO?
     [@bs.optional]
     renderIndicator: React.component({"route": route}),
     */
  [@bs.optional]
  activeTintColor: string,
  [@bs.optional]
  inactiveTintColor: string,
  [@bs.optional]
  iconStyle: Style.t,
  [@bs.optional]
  showLabel: bool,
  [@bs.optional]
  showIcon: bool,
  [@bs.optional]
  allowFontScaling: bool,
  // ----
  state: navigationState,
  navigation,
  descriptors,
  // SceneRendererProps from react-native-tab-view
  layout,
  position: Animated.Value.t,
  jumpTo: string => unit,
};

module type NavigatorModule = {
  module Navigator: {
    [@react.component]
    let make:
      (
        ~id: string=?,
        ~initialRouteName: string=?,
        ~screenOptions: screenOptionsParams => options=?,
        ~backBehavior: backBehavior=?,
        ~tabBarPosition: tabBarPosition=?,
        ~keyboardDismissMode: keyboardDismissMode=?,
        ~initialLayout: layout=?,
        ~sceneContainerStyle: Style.t=?,
        ~style: Style.t=?,
        ~tabBar: tabBarProps => React.element=?,
        ~children: React.element
      ) =>
      React.element;
  };

  module Screen: {
    [@react.component]
    let make:
      (
        ~name: string,
        ~navigationKey: string=?,
        ~options: screenOptionsParams => options=?,
        ~initialParams: 'params=?,
        ~getId: getIdOptions=?,
        ~component: React.component(screenProps)=?,
        ~getComponent: unit => React.component(screenProps)=?,
        ~children: screenProps => React.element=?
      ) =>
      React.element;
  };

  module Group: {
    [@react.component]
    let make:
      (
        ~navigationKey: string=?,
        ~screenOptions: screenOptionsParams => options=?
      ) =>
      React.element;
  };
};

type navigatorModule;

[@bs.module "@react-navigation/material-top-tabs"]
external createMaterialTopTabNavigator: unit => navigatorModule =
  "createMaterialTopTabNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (
  val createMaterialTopTabNavigator()->adaptNavigatorModule
);

module Navigation = {
  [@bs.send] external jumpTo: (navigation, string) => unit = "jumpTo";

  [@bs.send]
  external jumpToWithParams: (navigation, string, 'params) => unit = "jumpTo";

  [@bs.send]
  external addEventListener:
    (
      navigation,
      [@bs.string] [ | `tabPress(navigationEvent(unit) => unit)]
    ) =>
    unsubscribe =
    "addListener";
};
