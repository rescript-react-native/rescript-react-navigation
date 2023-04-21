// https://reactnavigation.org/docs/bottom-tab-navigator

open Core;
open Elements;
open ReactNative;

//type tabBarLabelPosition = [@bs.string] [ [@bs.as "below-icon"] `belowIcon | [@bs.as "beside-icon"] `besideIcon];
//type tabBarLabelPosition = [@bs.string] [ | [@bs.as "below-icon"] `belowIcon | [@bs.as "beside-icon"] `besideIcon ];
[@bs.deriving jsConverter]
type tabBarLabelPosition = [
  | [@bs.as "below-icon"] `below_icon
  | [@bs.as "beside-icon"] `beside_icon
];

type tabBarIconOptions = {
  focused: bool,
  color: string,
};

module TabBarBadge = {
  type t;

  external int: int => t = "%identity";

  external string: string => t = "%identity";
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  tabBarLabel: string,
  [@bs.optional]
  tabBarShowLabel: bool,
  [@bs.optional]
  tabBarLabelPosition,
  [@bs.optional]
  tabBarLabelStyle: Style.t,
  [@bs.optional]
  tabBarIcon: tabBarIconOptions => React.element,
  [@bs.optional]
  tabBarIconStyle: Style.t,
  [@bs.optional]
  tabBarBadge: string,
  [@bs.optional]
  tabBarBadgeStyle: Style.t,
  [@bs.optional]
  tabBarAccessibilityLabel: string,
  [@bs.optional]
  tabBarTestID: string,
  [@bs.optional]
  tabBarButton: unit => React.element, // TODO: props
  [@bs.optional]
  tabBarColor: Color.t,
  [@bs.optional]
  tabBarActiveTintColor: string,
  [@bs.optional]
  tabBarInactiveTintColor: string,
  [@bs.optional]
  tabBarActiveBackgroundColor: string,
  [@bs.optional]
  tabBarInactiveBackgroundColor: string,
  [@bs.optional]
  tabBarHideOnKeyboard: bool,
  [@bs.optional]
  tabBarItemStyle: Style.t,
  [@bs.optional]
  tabBarStyle: Style.t,
  [@bs.optional]
  tabBarBackground: unit => React.element,
  [@bs.optional]
  lazy_: bool,
  [@bs.optional]
  unmountOnBlur: bool,
  [@bs.optional]
  freezeOnBlur: bool,
  /*
   [@bs.optional]
   header: headerParams => React.element,
   */
  [@bs.optional]
  headerShown: bool,
  // Header props from https://reactnavigation.org/docs/elements#header
  [@bs.optional]
  headerTitle: Header.headerTitleProps => React.element,
  [@bs.optional]
  headerTitleAlign: Header.headerTitleAlign,
  [@bs.optional]
  headerTitleAllowFontScaling: bool,
  [@bs.optional]
  headerTitleStyle: Style.t,
  [@bs.optional]
  headerTitleContainerStyle: Style.t,
  [@bs.optional]
  headerLeft: Header.headerLeftProps => React.element,
  [@bs.optional]
  headerLeftLabelVisible: bool,
  [@bs.optional]
  headerLeftContainerStyle: Style.t,
  [@bs.optional]
  headerRight: Header.headerRightProps => React.element,
  [@bs.optional]
  headerRightContainerStyle: Style.t,
  [@bs.optional]
  headerPressColor: Color.t,
  [@bs.optional]
  headerPressOpacity: float,
  [@bs.optional]
  headerTintColor: Color.t,
  [@bs.optional]
  headerBackground: Header.headerBackgroundOptions => React.element,
  [@bs.optional]
  headerBackgroundContainerStyle: Style.t,
  [@bs.optional]
  headerTransparent: bool,
  [@bs.optional]
  headerStyle: Style.t,
  [@bs.optional]
  headerShadowVisible: bool,
  [@bs.optional]
  headerStatusBarHeight: Style.size,
};

// TODO: this was an `and` recursive type, but that doesn't work with deriving abstract
type headerParams = {
  navigation,
  route,
  //options: options,
  layout,
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
        ~detachInactiveScreens: bool=?,
        ~sceneContainerStyle: Style.t=?,
        ~tabBar: unit => React.element=?,
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

[@bs.module "@react-navigation/bottom-tabs"]
external createBottomTabNavigator: unit => navigatorModule =
  "createBottomTabNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (val createBottomTabNavigator()->adaptNavigatorModule);

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
