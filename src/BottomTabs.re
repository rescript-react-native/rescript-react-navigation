open Core;

type options;

module BottomTabNavigationProp = (M: {
                                    type params;
                                    type options;
                                  }) => {
  include NavigationScreenProp(M);

  type t = navigation;

  [@bs.send] external jumpTo: (t, string) => unit = "jumpTo";
  [@bs.send]
  external jumpToWithParams: (t, string, M.params) => unit = "jumpTo";
};

module Make = (M: {type params;}) => {
  module Navigation =
    BottomTabNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    .
    "index": int,
    "focused": bool,
    "tintColor": string,
  };

  class type virtual baseBottomTabBarOptions = {
    pub keyboardHidesTabBar: option(bool);
    pub activeBackgroundColor: option(string);
    pub inactiveBackgroundColor: option(string);
    pub allowFontScaling: option(bool);
    pub showLabel: option(bool);
    pub showIcon: option(bool);
    pub labelStyle: option(ReactNative.Style.t);
    pub tabStyle: option(ReactNative.Style.t);
    pub labelPosition: option({. "deviceOrientation": string} => string);
    pub adaptive: option(bool);
    pub style: option(ReactNative.Style.t);
  };

  class type virtual bottomTabBarOptions = {
    as 'self;
    constraint 'self = #baseBottomTabBarOptions;
    pub activeTintColor: option(string);
    pub inactiveTintColor: option(string);
  };

  type accessibilityRole = string;
  type accessibilityStates = array(string);
  class type virtual bottomTabBarProps = {
    as 'self;
    constraint 'self = #baseBottomTabBarOptions;
    pub state: navigationState(M.params);
    pub navigation: navigation;
    pub onTabPress: {. "route": route(M.params)} => unit;
    pub onTabLongPress: {. "route": route(M.params)} => unit;
    pub getAccessibilityLabel:
      {. "route": route(M.params)} => Js.nullable(string);
    pub getAccessibilityRole:
      {. "route": route(M.params)} => Js.nullable(accessibilityRole);
    pub getAccessibilityStates:
      {. "route": route(M.params)} => Js.nullable(accessibilityStates);
    pub getButtonComponent:
      {. "route": route(M.params)} => Js.nullable(React.element);
    //pub getLabelText: {. "route": route(M.params)} => ...;
    pub getTestID: {. "route": route(M.params)} => Js.nullable(string);
    pub renderIcon:
      {
        .
        "route": route(M.params),
        "focused": bool,
        "tintColor": string,
        "horizontal": bool,
      } =>
      React.element;
    pub activeTintColor: string;
    pub inactiveTintColor: string;
  };

  [@bs.obj]
  external bottomTabBarOptions:
    (
      ~keyboardHidesTabBar: bool=?,
      ~activeTintColor: string=?,
      ~inactiveTintColor: string=?,
      ~activeBackgroundColor: string=?,
      ~inactiveBackgroundColor: string=?,
      ~allowFontScaling: bool=?,
      ~showLabel: bool=?,
      ~showIcon: bool=?,
      ~labelStyle: ReactNative.Style.t=?,
      ~tabStyle: ReactNative.Style.t=?,
      ~labelPosition: {. "deviceOrientation": string} => string=?,
      ~adaptive: bool=?,
      ~style: ReactNative.Style.t=?,
      unit
    ) =>
    bottomTabBarOptions =
    "";

  [@bs.obj]
  external options:
    (
      ~title: string=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarLabel: {
                      .
                      "focused": bool,
                      "color": string,
                    } =>
                    React.element
                      =?,
      ~tabBarIcon: {
                     .
                     "focused": bool,
                     "color": string,
                     "size": float,
                   } =>
                   React.element
                     =?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarTestID: string=?,
      ~tabBarVisible: bool=?,
      ~tabBarButtonComponent: React.element=?,
      unit
    ) =>
    options =
    "";

  type optionsProps =
    {
      .
      "navigation": navigation,
      "route": route(M.params),
    } =>
    options;

  type navigatorProps;

  type screenProps;

  [@bs.module "@react-navigation/bottom-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps => React.element,
    } =
    "createBottomTabNavigator";

  let bottomTabs = make();

  module Screen = {
    [@bs.obj]
    external makeProps:
      (
        ~name: string,
        ~options: optionsProps=?,
        ~initialParams: M.params=?,
        ~component: React.component({. "navigation": navigation}),
        unit
      ) =>
      screenProps =
      "";
    let make = bottomTabs##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionsProps=?,
        ~children: React.element,
        ~_lazy: bool=?,
        ~tabBarComponent: React.component(Js.t(bottomTabBarProps))=?,
        ~tabBarOptions: bottomTabBarOptions=?,
        unit
      ) =>
      navigatorProps =
      "";

    let make = bottomTabs##"Navigator";
  };
};
