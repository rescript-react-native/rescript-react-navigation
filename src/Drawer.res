// https://reactnavigation.org/docs/drawer-navigator

open Core
open Elements
open ReactNative

type keyboardDismissMode = [#"on-drag" | #none]

type drawerLabelProps = {
  focused: bool,
  color: Color.t,
}

type drawerIconProps = {
  focused: bool,
  color: Color.t,
  size: float,
}

type drawerPosition = [#left | #right]

type drawerType = [#front | #back | #slide | #permanent]

type drawerStatusBarAnimation = [#slide | #fade | #none]

// TODO
type gestureHandlerProps

type rec options = {
  title?: string,
  \"lazy"?: bool,
  drawerLabel?: drawerLabelProps => React.element,
  drawerIcon?: drawerIconProps => React.element,
  drawerActiveTintColor?: Color.t,
  drawerActiveBackgroundColor?: Color.t,
  drawerInactiveTintColor?: Color.t,
  drawerInactiveBackgroundColor?: Color.t,
  drawerItemStyle?: Style.t,
  drawerLabelStyle?: Style.t,
  drawerContentContainerStyle?: Style.t,
  drawerContentStyle?: Style.t,
  drawerStyle?: Style.t,
  drawerPosition?: drawerPosition,
  drawerType?: drawerType,
  drawerHideStatusBarOnOpen?: bool,
  drawerStatusBarAnimation?: drawerStatusBarAnimation,
  overlayColor?: Color.t,
  sceneStyle?: Style.t,
  gestureEnabled?: bool,
  gestureHandlerProps?: gestureHandlerProps,
  swipeEnabled?: bool,
  swipeEdgeWidth?: float,
  swipeMinDistance?: float,
  keyboardDismissMode?: keyboardDismissMode,
  popToTopOnBlur?: bool,
  freezeOnBlur?: bool,
  headerShown?: bool,
  header?: headerProps => React.element,
  // Header props from https://reactnavigation.org/docs/elements#header
  headerTitle?: Header.headerTitle,
  headerTitleAlign?: Header.headerTitleAlign,
  headerTitleAllowFontScaling?: bool,
  headerTitleStyle?: Style.t,
  headerTitleContainerStyle?: Style.t,
  headerLeft?: Header.headerLeftProps => React.element,
  headerLeftLabelVisible?: bool,
  headerLeftContainerStyle?: Style.t,
  headerRight?: Header.headerRightProps => React.element,
  headerRightContainerStyle?: Style.t,
  headerPressColor?: Color.t,
  headerPressOpacity?: float,
  headerTintColor?: Color.t,
  headerBackground?: Header.headerBackgroundOptions => React.element,
  headerBackgroundContainerStyle?: Style.t,
  headerTransparent?: bool,
  headerStyle?: Style.t,
  headerShadowVisible?: bool,
  headerStatusBarHeight?: Style.size,
}
and headerProps = {
  navigation: navigation,
  route: route,
  options: options,
  layout: layout,
}

type contentComponentProps = {
  state: navigationState,
  navigation: navigation,
  descriptors: descriptors,
}

type drawerStatus = [#"open" | #closed]

module type NavigatorModule = {
  module Navigator: {
    @react.component
    let make: (
      ~id: string=?,
      ~initialRouteName: string=?,
      ~screenOptions: screenOptionsParams => options=?,
      ~backBehavior: backBehavior=?,
      ~defaultStatus: drawerStatus=?,
      ~detachInactiveScreens: bool=?,
      ~useLegacyImplementation: bool=?,
      ~drawerContent: React.component<contentComponentProps>=?,
      ~children: React.element=?,
    ) => React.element
  }

  module Screen: {
    @react.component
    let make: (
      ~name: string,
      ~navigationKey: string=?,
      ~options: screenOptionsParams => options=?,
      ~initialParams: 'params=?,
      ~getId: getIdOptions=?,
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
  @module("@react-navigation/drawer")
  external createDrawerNavigator: unit => navigatorModule = "createDrawerNavigator"

  @module("./Interop")
  external adaptNavigatorModule: navigatorModule => module(NavigatorModule) = "adaptNavigatorModule"
)

module Make = () => unpack(createDrawerNavigator()->adaptNavigatorModule)

module Navigation = {
  @send
  external setOptions: (navigation, options) => unit = "setOptions"

  @send external jumpTo: (navigation, ~name: string, ~params: 'params=?, unit) => unit = "jumpTo"
  @send external openDrawer: navigation => unit = "openDrawer"
  @send external closeDrawer: navigation => unit = "closeDrawer"
  @send external toggleDrawer: navigation => unit = "toggleDrawer"

  @send
  external addEventListener: (
    navigation,
    @string
    [
      | #drawerItemPress(navigationEvent<unit> => unit)
    ],
  ) => unsubscribe = "addListener"
}

@module("@react-navigation/drawer")
external useDrawerStatus: unit => drawerStatus = "useDrawerStatus"

@module("@react-navigation/drawer")
external getDrawerStatusFromState: navigationState => drawerStatus = "getDrawerStatusFromState"

module DrawerItemList = {
  @module("@react-navigation/drawer")
  external make: React.component<contentComponentProps> = "DrawerItemList"
}
