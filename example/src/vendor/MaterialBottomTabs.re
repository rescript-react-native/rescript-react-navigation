// https://reactnavigation.org/docs/material-bottom-tab-navigator

open Core;
open ReactNative;

type tabBarIconOptions = {
  focused: bool,
  color: string,
};

module TabBarBadge = {
  type t;

  external boolean: bool => t = "%identity";
  external int: int => t = "%identity";
  external string: string => t = "%identity";
};

[@bs.deriving abstract]
type options = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  tabBarIcon: tabBarIconOptions => React.element,
  [@bs.optional]
  tabBarColor: Color.t,
  [@bs.optional]
  tabBarLabel: string,
  [@bs.optional]
  tabBarBadge: TabBarBadge.t,
  [@bs.optional]
  tabBarAccessibilityLabel: string,
  [@bs.optional]
  tabBarTestID: string,
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
        ~shifting: bool=?,
        ~labeled: bool=?,
        ~activeColor: Color.t=?,
        ~inactiveColor: Color.t=?,
        ~barStyle: Style.t=?,
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

[@bs.module "@react-navigation/material-bottom-tabs"]
external createMaterialBottomTabNavigator: unit => navigatorModule =
  "createMaterialBottomTabNavigator";

[@bs.module "./Interop"]
external adaptNavigatorModule: navigatorModule => (module NavigatorModule) =
  "adaptNavigatorModule";

module Make = (()) => (
  val createMaterialBottomTabNavigator()->adaptNavigatorModule
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
