// https://reactnavigation.org/docs/drawer-navigator

open Core;
open Elements;
open ReactNative;

type keyboardDismissMode = [ | `on_drag | `none];

type drawerLabelProps = {
  focused: bool,
  color: Color.t,
};

type drawerIconProps = {
  focused: bool,
  color: Color.t,
  size: float,
};

[@bs.deriving jsConverter]
type drawerPosition = [ | `left | `right];

[@bs.deriving jsConverter]
type drawerType = [ | `front | `back | `slide | `permanent];

[@bs.deriving jsConverter]
type drawerStatusBarAnimation = [ | `slide | `fade | `none];

// TODO
type gestureHandlerProps;

[@bs.deriving abstract]
type options = {
  title: string,
  [@bs.optional] [@bs.as "lazy"]
  lazy_: bool,
  [@bs.optional]
  drawerLabel: drawerLabelProps => React.element,
  [@bs.optional]
  drawerIcon: drawerIconProps => React.element,
  [@bs.optional]
  drawerActiveTintColor: Color.t,
  [@bs.optional]
  drawerActiveBackgroundColor: Color.t,
  [@bs.optional]
  drawerInactiveTintColor: Color.t,
  [@bs.optional]
  drawerInactiveBackgroundColor: Color.t,
  [@bs.optional]
  drawerItemStyle: Style.t,
  [@bs.optional]
  drawerLabelStyle: Style.t,
  [@bs.optional]
  drawerContentContainerStyle: Style.t,
  [@bs.optional]
  drawerContentStyle: Style.t,
  [@bs.optional]
  drawerStyle: Style.t,
  [@bs.optional]
  drawerPosition,
  [@bs.optional]
  drawerType,
  [@bs.optional]
  drawerHideStatusBarOnOpen: bool,
  [@bs.optional]
  drawerStatusBarAnimation,
  [@bs.optional]
  overlayColor: Color.t,
  [@bs.optional]
  sceneContainerStyle: Style.t,
  [@bs.optional]
  gestureEnabled: bool,
  [@bs.optional]
  gestureHandlerProps,
  [@bs.optional]
  swipeEnabled: bool,
  [@bs.optional]
  swipeEdgeWidth: float,
  [@bs.optional]
  swipeMinDistance: float,
  [@bs.optional]
  keyboardDismissMode,
  [@bs.optional]
  unmountOnBlur: bool,
  [@bs.optional]
  freezeOnBlur: bool,
  [@bs.optional]
  headerShown: bool,
  //header: headerProps => React.element,
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

type headerProps = {
  navigation,
  route,
  options,
  layout,
};

type contentComponentProps = {
  state: navigationState,
  navigation,
  descriptors,
};

[@bs.deriving jsConverter]
type drawerStatus = [ | [@bs.as "open"] `open_ | `closed];

module type NavigatorModule = {
  module Navigator: {
    [@react.component]
    let make:
      (
        ~id: string=?,
        ~initialRouteName: string=?,
        ~screenOptions: screenOptionsParams => options=?,
        ~backBehavior: backBehavior=?,
        ~defaultStatus: drawerStatus=?,
        ~detachInactiveScreens: bool=?,
        ~useLegacyImplementation: bool=?,
        ~drawerContent: React.component(contentComponentProps)=?,
        ~children: React.element=?
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

[@bs.module "@react-navigation/drawer"]
external createDrawerNavigator: unit => navigatorModule =
  "createDrawerNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (val createDrawerNavigator()->adaptNavigatorModule);

module Navigation = {
  [@bs.send] external setOptions: (navigation, options) => unit = "setOptions";

  [@bs.send]
  external jumpTo:
    (navigation, ~name: string, ~params: 'params=?, unit) => unit =
    "jumpTo";
  [@bs.send] external openDrawer: navigation => unit = "openDrawer";
  [@bs.send] external closeDrawer: navigation => unit = "closeDrawer";
  [@bs.send] external toggleDrawer: navigation => unit = "toggleDrawer";

  [@bs.send]
  external addEventListener:
    (
      navigation,
      [@bs.string] [ | `drawerItemPress(navigationEvent(unit) => unit)]
    ) =>
    unsubscribe =
    "addListener";
};

[@bs.module "@react-navigation/drawer"]
external useDrawerStatus: unit => drawerStatus = "useDrawerStatus";

[@bs.module "@react-navigation/drawer"]
external getDrawerStatusFromState: navigationState => drawerStatus =
  "getDrawerStatusFromState";
