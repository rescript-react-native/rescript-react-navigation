// https://reactnavigation.org/docs/bottom-tab-navigator

open Core
open Elements
open ReactNative

type tabBarLabelPosition = [#"below-icon" | #"beside-icon"]

type tabBarPosition = [#bottom | #top | #left | #right]

type tabBarVariant = [#uikit | #material]

type animation = [
  | #fade
  | #shift
  | #none
]

type tabBarIconOptions = {
  focused: bool,
  color: string,
}

module TabBarBadge = {
  type t

  external int: int => t = "%identity"
  external string: string => t = "%identity"
}

type tabBarLabelArgs = {
  focused: bool,
  color: string,
  position: tabBarLabelPosition,
  children: string,
}

@unboxed
type tabBarLabel = String(string) | Function(tabBarLabelArgs => React.element)

type rec options = {
  title?: string,
  tabBarLabel?: tabBarLabel,
  tabBarShowLabel?: bool,
  tabBarLabelPosition?: tabBarLabelPosition,
  tabBarLabelStyle?: Style.t,
  tabBarIcon?: tabBarIconOptions => React.element,
  tabBarIconStyle?: Style.t,
  tabBarBadge?: string,
  tabBarBadgeStyle?: Style.t,
  tabBarAccessibilityLabel?: string,
  tabBarButtonTestID?: string,
  tabBarButton?: unit => React.element, // TODO: props
  tabBarActiveTintColor?: string,
  tabBarInactiveTintColor?: string,
  tabBarActiveBackgroundColor?: string,
  tabBarInactiveBackgroundColor?: string,
  tabBarHideOnKeyboard?: bool,
  tabBarItemStyle?: Style.t,
  tabBarStyle?: Style.t,
  tabBarBackground?: unit => React.element,
  tabBarPosition?: tabBarPosition,
  tabBarVariant?: tabBarVariant,
  sceneStyle?: Style.t,
  \"lazy"?: bool,
  popToTopOnBlur?: bool,
  freezeOnBlur?: bool,
  header?: headerParams => React.element,
  headerShown?: bool,
  animation?: animation,
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
and headerParams = {
  navigation: navigation,
  route: route,
  options: options,
  layout: layout,
}

type navigatorProps = {
  id?: string,
  initialRouteName?: string,
  screenOptions?: screenOptionsParams => options,
  backBehavior?: backBehavior,
  detachInactiveScreens?: bool,
  tabBar?: unit => React.element,
  layout?: layoutNavigatorParams => React.element,
  children: React.element,
}

type screenProps<'params> = {
  name: string,
  navigationKey?: string,
  options?: screenOptionsParams => options,
  initialParams?: 'params,
  getId?: getIdOptions => option<string>,
  component?: React.component<screenProps>,
  getComponent?: unit => React.component<screenProps>,
  children?: screenProps => React.element,
}

type groupProps = {
  navigationKey?: string,
  screenOptions?: screenOptionsParams => options,
}

module type NavigatorModule = {
  module Navigator: {
    let make: React.component<navigatorProps>
  }

  module Screen: {
    let make: React.component<screenProps<'params>>
  }

  module Group: {
    let make: React.component<groupProps>
  }
}

module Make = (): NavigatorModule => {
  @module("@react-navigation/bottom-tabs")
  external createBottomTabNavigator: unit => {..} = "createBottomTabNavigator"

  let internal = createBottomTabNavigator()

  module Navigator = {
    let make = internal["Navigator"]
  }

  module Screen = {
    let make = internal["Screen"]
  }

  module Group = {
    let make = internal["Group"]
  }
}

module Navigation = {
  @send external jumpTo: (navigation, string, ~params: 'params=?) => unit = "jumpTo"
  @deprecated("Use `jumpTo` with `~params` instead") @send
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
