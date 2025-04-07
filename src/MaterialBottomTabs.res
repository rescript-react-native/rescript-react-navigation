// https://reactnavigation.org/docs/material-bottom-tab-navigator

open Core
open ReactNative

type tabBarIconOptions = {
  focused: bool,
  color: string,
}

module TabBarBadge = {
  type t

  external boolean: bool => t = "%identity"
  external int: int => t = "%identity"
  external string: string => t = "%identity"
}

type tabBarLabelArgs = {
  focused: bool,
  color: string,
  children: string,
}

@unboxed
type tabBarLabel = String(string) | Function(tabBarLabelArgs => React.element)

type options = {
  title?: string,
  tabBarIcon?: tabBarIconOptions => React.element,
  tabBarColor?: Color.t,
  tabBarLabel?: tabBarLabel,
  tabBarBadge?: TabBarBadge.t,
  tabBarAccessibilityLabel?: string,
  tabBarTestID?: string,
}

type navigatorProps = {
  id?: string,
  initialRouteName?: string,
  screenOptions?: screenOptionsParams => options,
  backBehavior?: backBehavior,
  shifting?: bool,
  labeled?: bool,
  activeColor?: Color.t,
  inactiveColor?: Color.t,
  barStyle?: Style.t,
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
  @module("@react-navigation/material-bottom-tabs")
  external createMaterialBottomTabNavigator: unit => {..} = "createMaterialBottomTabNavigator"

  let internal = createMaterialBottomTabNavigator()

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
  @send
  external setOptions: (navigation, options) => unit = "setOptions"

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
