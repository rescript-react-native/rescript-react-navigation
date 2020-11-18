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
  type nonrec route = route(M.params);
  module Navigation =
    BottomTabNavigationProp({
      include M;
      type nonrec options = options;
    });

  type animatedNode = ReactNative.Animated.Value.t;

  type scene = {
    index: int,
    focused: bool,
    tintColor: string,
  };

  type labelPositionArgs = {deviceOrientation: string};

  class type virtual baseBottomTabBarOptions = {
    pub keyboardHidesTabBar: option(bool);
    pub activeBackgroundColor: option(string);
    pub inactiveBackgroundColor: option(string);
    pub allowFontScaling: option(bool);
    pub showLabel: option(bool);
    pub labelStyle: option(ReactNative.Style.t);
    pub tabStyle: option(ReactNative.Style.t);
    pub labelPosition: option(labelPositionArgs => string);
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
  type routeArgs = {route};
  type renderIconArgs = {
    route,
    focused: bool,
    tintColor: string,
    horizontal: bool,
  };
  class type virtual bottomTabBarProps = {
    as 'self;
    constraint 'self = #baseBottomTabBarOptions;
    pub state: navigationState(M.params);
    pub navigation: navigation;
    pub onTabPress: routeArgs => unit;
    pub onTabLongPress: routeArgs => unit;
    pub getAccessibilityLabel: routeArgs => Js.nullable(string);
    pub getAccessibilityRole: routeArgs => Js.nullable(accessibilityRole);
    pub getAccessibilityStates: routeArgs => Js.nullable(accessibilityStates);
    pub getButtonComponent: routeArgs => Js.nullable(React.element);
    //pub getLabelText: routeArgs => ...;
    pub getTestID: routeArgs => Js.nullable(string);
    pub renderIcon: renderIconArgs => React.element;
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
      ~labelPosition: labelPositionArgs => string=?,
      ~adaptive: bool=?,
      ~style: ReactNative.Style.t=?,
      unit
    ) =>
    bottomTabBarOptions;

  type tabBarLabelArgs = {
    focused: bool,
    color: string,
  };
  type tabBarIconArgs = {
    focused: bool,
    color: string,
    size: float,
  };
  [@bs.obj]
  external options:
    (
      ~title: string=?,
      //TODO: dynamic, missing static option: React.ReactNode
      ~tabBarLabel: tabBarLabelArgs => React.element=?,
      ~tabBarIcon: tabBarIconArgs => React.element=?,
      ~tabBarAccessibilityLabel: string=?,
      ~tabBarTestID: string=?,
      ~tabBarVisible: bool=?,
      ~tabBarButton: React.element=?,
      ~unmountOnBlur: bool=?,
      unit
    ) =>
    options;

  type optionsProps = {
    navigation,
    route,
  };

  type optionsCallback = optionsProps => options;

  type navigatorProps = {
    initialRouteName: option(string),
    screenOptions: option(optionsCallback),
    backBehavior: option(string),
    _lazy: option(bool),
    tabBar: option(Js.t(bottomTabBarProps) => React.element),
    tabBarOptions: option(bottomTabBarOptions),
  };

  type renderCallbackProp = {
    navigation,
    route,
  };

  type screenProps('params) = {
    name: string,
    options: option(optionsCallback),
    initialParams: option('params),
    component:
      option(
        React.component({
          .
          "navigation": navigation,
          "route": route,
        }),
      ),
    children: option(renderCallbackProp => React.element),
  };

  [@bs.module "@react-navigation/bottom-tabs"]
  external make:
    unit =>
    {
      .
      "Navigator": navigatorProps => React.element,
      "Screen": screenProps(M.params) => React.element,
    } =
    "createBottomTabNavigator";

  let bottomTabs = make();

  module Screen = {
    [@bs.obj]
    external makeProps:
      (
        ~name: string,
        ~options: optionsCallback=?,
        ~initialParams: M.params=?,
        ~component: React.component({
                      .
                      "navigation": navigation,
                      "route": route,
                    }),
        ~key: string=?,
        unit
      ) =>
      screenProps(M.params);
    let make = bottomTabs##"Screen";
  };

  module ScreenWithCallback = {
    [@bs.obj]
    external makeProps:
      (
        ~name: string,
        ~options: optionsCallback=?,
        ~initialParams: M.params=?,
        ~children: renderCallbackProp => React.element,
        ~key: string=?,
        unit
      ) =>
      screenProps(M.params);
    let make = bottomTabs##"Screen";
  };

  module Navigator = {
    [@bs.obj]
    external makeProps:
      (
        ~initialRouteName: string=?,
        ~screenOptions: optionsCallback=?,
        ~children: React.element,
        ~backBehavior: [ | `initialRoute | `order | `history | `none]=?,
        ~_lazy: bool=?,
        ~tabBar: Js.t(bottomTabBarProps) => React.element=?,
        ~tabBarOptions: bottomTabBarOptions=?,
        ~key: string=?,
        unit
      ) =>
      navigatorProps;

    let make = bottomTabs##"Navigator";
  };
};
